// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraCharacter.h"
#include "LyraCharacterMovementComponent.h"
#include "LyraLogChannels.h"
#include "LyraGameplayTags.h"
#include "Character/LyraPawnExtensionComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "Camera/LyraCameraComponent.h"
#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "Character/LyraHealthComponent.h"
#include "Character/LyraEnergyComponent.h"
#include "Player/LyraPlayerController.h"
#include "Player/LyraPlayerState.h"
#include "System/LyraSignificanceManager.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameplayEffect.h"
#include "Animation/LyraAnimInstance.h"
#include "Components/TimelineComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Engine/StaticMeshActor.h"
#include "Camera/LyraCameraMode.h"
#include "AbilitySystem/Abilities/LyraGameplayAbility.h"

static FName NAME_LyraCharacterCollisionProfile_Capsule(TEXT("LyraPawnCapsule"));
static FName NAME_LyraCharacterCollisionProfile_Mesh(TEXT("LyraPawnMesh"));

ALyraCharacter::ALyraCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<ULyraCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Avoid ticking characters if possible.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	NetCullDistanceSquared = 900000000.0f;

	SlideTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("SlidingTimeline"));

	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	check(CapsuleComp);
	CapsuleComp->InitCapsuleSize(40.0f, 90.0f);
	CapsuleComp->SetCollisionProfileName(NAME_LyraCharacterCollisionProfile_Capsule);

	USkeletalMeshComponent* MeshComp = GetMesh();
	check(MeshComp);
	MeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));  // Rotate mesh to be X forward since it is exported as Y forward.
	MeshComp->SetCollisionProfileName(NAME_LyraCharacterCollisionProfile_Mesh);

	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());
	LyraMoveComp->GravityScale = 1.0f;
	LyraMoveComp->MaxAcceleration = 2400.0f;
	LyraMoveComp->BrakingFrictionFactor = 1.0f;
	LyraMoveComp->BrakingFriction = 6.0f;
	LyraMoveComp->GroundFriction = 8.0f;
	LyraMoveComp->BrakingDecelerationWalking = 1400.0f;
	LyraMoveComp->bUseControllerDesiredRotation = false;
	LyraMoveComp->bOrientRotationToMovement = false;
	LyraMoveComp->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	LyraMoveComp->bAllowPhysicsRotationDuringAnimRootMotion = false;
	LyraMoveComp->GetNavAgentPropertiesRef().bCanCrouch = true;
	LyraMoveComp->bCanWalkOffLedgesWhenCrouching = true;
	LyraMoveComp->SetCrouchedHalfHeight(65.0f);

	PawnExtComponent = CreateDefaultSubobject<ULyraPawnExtensionComponent>(TEXT("PawnExtensionComponent"));
	PawnExtComponent->OnAbilitySystemInitialized_RegisterAndCall(FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ThisClass::OnAbilitySystemInitialized));
	PawnExtComponent->OnAbilitySystemUninitialized_Register(FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ThisClass::OnAbilitySystemUninitialized));

	HealthComponent = CreateDefaultSubobject<ULyraHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->OnDeathStarted.AddDynamic(this, &ThisClass::OnDeathStarted);
	HealthComponent->OnDeathFinished.AddDynamic(this, &ThisClass::OnDeathFinished);

	EnergyComponent = CreateDefaultSubobject<ULyraEnergyComponent>(TEXT("EnergyComponent"));
	/*EnergyComponent->OnEnergyChanged.AddDynamic(this, &ThisClass::OnEnergyChanged);
	EnergyComponent->OnMaxEnergyChanged.AddDynamic(this, &ThisClass::OnMaxEnergyChanged);*/

	CameraComponent = CreateDefaultSubobject<ULyraCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 75.0f));

	/*ShieldComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldComponent"));
	ShieldComponent->SetupAttachment(CapsuleComp);
	ShieldComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 75.0f));*/

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	BaseEyeHeight = 80.0f;
	CrouchedEyeHeight = 50.0f;
}

void ALyraCharacter::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void ALyraCharacter::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	const bool bRegisterWithSignificanceManager = !IsNetMode(NM_DedicatedServer);
	if (bRegisterWithSignificanceManager)
	{
		if (ULyraSignificanceManager* SignificanceManager = USignificanceManager::Get<ULyraSignificanceManager>(World))
		{
			//@TODO: SignificanceManager->RegisterObject(this, (EFortSignificanceType)SignificanceType);
		}
	}

	DeclareSlidingTimeline();
}

void ALyraCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UWorld* World = GetWorld();

	const bool bRegisterWithSignificanceManager = !IsNetMode(NM_DedicatedServer);
	if (bRegisterWithSignificanceManager)
	{
		if (ULyraSignificanceManager* SignificanceManager = USignificanceManager::Get<ULyraSignificanceManager>(World))
		{
			SignificanceManager->UnregisterObject(this);
		}
	}
}

void ALyraCharacter::Reset()
{
	if (ShieldActor != nullptr)
	{
		ShieldActor->Destroy();
	}
	DisableMovementAndCollision();

	K2_OnReset();

	UninitAndDestroy();
}

void ALyraCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ThisClass, ReplicatedAcceleration, COND_SimulatedOnly);
	DOREPLIFETIME(ThisClass, MyTeamID);
	DOREPLIFETIME(ThisClass, Sliding);
	DOREPLIFETIME(ThisClass, HitActor);
	DOREPLIFETIME(ThisClass, Blocking);
	DOREPLIFETIME(ThisClass, StartDash);
	DOREPLIFETIME(ThisClass, ShieldActor);
}

void ALyraCharacter::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);

	if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
	{
		// Compress Acceleration: XY components as direction + magnitude, Z component as direct value
		const double MaxAccel = MovementComponent->MaxAcceleration;
		const FVector CurrentAccel = MovementComponent->GetCurrentAcceleration();
		double AccelXYRadians, AccelXYMagnitude;
		FMath::CartesianToPolar(CurrentAccel.X, CurrentAccel.Y, AccelXYMagnitude, AccelXYRadians);

		ReplicatedAcceleration.AccelXYRadians = FMath::FloorToInt((AccelXYRadians / TWO_PI) * 255.0);     // [0, 2PI] -> [0, 255]
		ReplicatedAcceleration.AccelXYMagnitude = FMath::FloorToInt((AccelXYMagnitude / MaxAccel) * 255.0);	// [0, MaxAccel] -> [0, 255]
		ReplicatedAcceleration.AccelZ = FMath::FloorToInt((CurrentAccel.Z / MaxAccel) * 127.0);   // [-MaxAccel, MaxAccel] -> [-127, 127]
	}
}

void ALyraCharacter::NotifyControllerChanged()
{
	const FGenericTeamId OldTeamId = GetGenericTeamId();

	Super::NotifyControllerChanged();

	// Update our team ID based on the controller
	if (HasAuthority() && (Controller != nullptr))
	{
		if (ILyraTeamAgentInterface* ControllerWithTeam = Cast<ILyraTeamAgentInterface>(Controller))
		{
			MyTeamID = ControllerWithTeam->GetGenericTeamId();
			ConditionalBroadcastTeamChanged(this, OldTeamId, MyTeamID);
		}
	}
}

ALyraPlayerController* ALyraCharacter::GetLyraPlayerController() const
{
	return CastChecked<ALyraPlayerController>(Controller, ECastCheckedType::NullAllowed);
}

ALyraPlayerState* ALyraCharacter::GetLyraPlayerState() const
{
	return CastChecked<ALyraPlayerState>(GetPlayerState(), ECastCheckedType::NullAllowed);
}

ULyraAbilitySystemComponent* ALyraCharacter::GetLyraAbilitySystemComponent() const
{
	return Cast<ULyraAbilitySystemComponent>(GetAbilitySystemComponent());
}

UAbilitySystemComponent* ALyraCharacter::GetAbilitySystemComponent() const
{
	return PawnExtComponent->GetLyraAbilitySystemComponent();
}

void ALyraCharacter::OnAbilitySystemInitialized()
{
	if (EnergyComponent != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Energy comp : %s"), *EnergyComponent->GetFName().ToString()));
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Energy comp owner : %s"), *EnergyComponent->GetOwner()->GetFName().ToString()));
	}

	ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent();
	check(LyraASC);

	HealthComponent->InitializeWithAbilitySystem(LyraASC);

	/*ULyraAbilitySystemComponent* LyraEn = GetLyraAbilitySystemComponent();
	check(LyraEn);

	EnergyComponent->InitializeWithAbilitySystem(LyraEn);*/

	InitializeGameplayTags();
}

void ALyraCharacter::OnAbilitySystemUninitialized()
{
	HealthComponent->UninitializeFromAbilitySystem();
	//EnergyComponent->UninitializeFromAbilitySystem();
}

void ALyraCharacter::PossessedBy(AController* NewController)
{
	const FGenericTeamId OldTeamID = MyTeamID;

	Super::PossessedBy(NewController);

	PawnExtComponent->HandleControllerChanged();

	// Grab the current team ID and listen for future changes
	if (ILyraTeamAgentInterface* ControllerAsTeamProvider = Cast<ILyraTeamAgentInterface>(NewController))
	{
		MyTeamID = ControllerAsTeamProvider->GetGenericTeamId();
		ControllerAsTeamProvider->GetTeamChangedDelegateChecked().AddDynamic(this, &ThisClass::OnControllerChangedTeam);
	}
	ConditionalBroadcastTeamChanged(this, OldTeamID, MyTeamID);
}

void ALyraCharacter::UnPossessed()
{
	AController* const OldController = Controller;

	// Stop listening for changes from the old controller
	const FGenericTeamId OldTeamID = MyTeamID;
	if (ILyraTeamAgentInterface* ControllerAsTeamProvider = Cast<ILyraTeamAgentInterface>(OldController))
	{
		ControllerAsTeamProvider->GetTeamChangedDelegateChecked().RemoveAll(this);
	}

	Super::UnPossessed();

	PawnExtComponent->HandleControllerChanged();

	// Determine what the new team ID should be afterwards
	MyTeamID = DetermineNewTeamAfterPossessionEnds(OldTeamID);
	ConditionalBroadcastTeamChanged(this, OldTeamID, MyTeamID);
}

void ALyraCharacter::OnRep_Controller()
{
	Super::OnRep_Controller();

	PawnExtComponent->HandleControllerChanged();
}

void ALyraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	PawnExtComponent->HandlePlayerStateReplicated();
}

void ALyraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PawnExtComponent->SetupPlayerInputComponent();
}

void ALyraCharacter::InitializeGameplayTags()
{
	// Clear tags that may be lingering on the ability system from the previous pawn.
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		const FLyraGameplayTags& GameplayTags = FLyraGameplayTags::Get();

		for (const TPair<uint8, FGameplayTag>& TagMapping : GameplayTags.MovementModeTagMap)
		{
			if (TagMapping.Value.IsValid())
			{
				LyraASC->SetLooseGameplayTagCount(TagMapping.Value, 0);
			}
		}

		for (const TPair<uint8, FGameplayTag>& TagMapping : GameplayTags.CustomMovementModeTagMap)
		{
			if (TagMapping.Value.IsValid())
			{
				LyraASC->SetLooseGameplayTagCount(TagMapping.Value, 0);
			}
		}

		ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());
		SetMovementModeTag(LyraMoveComp->MovementMode, LyraMoveComp->CustomMovementMode, true);
	}
}

void ALyraCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		LyraASC->GetOwnedGameplayTags(TagContainer);
	}
}

bool ALyraCharacter::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasMatchingGameplayTag(TagToCheck);
	}

	return false;
}

bool ALyraCharacter::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasAllMatchingGameplayTags(TagContainer);
	}

	return false;
}

bool ALyraCharacter::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasAnyMatchingGameplayTags(TagContainer);
	}

	return false;
}

void ALyraCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
	HealthComponent->DamageSelfDestruct(/*bFellOutOfWorld=*/ true);
}

void ALyraCharacter::OnDeathStarted(AActor*)
{
	if (ShieldActor != nullptr)
	{
		ShieldActor->Destroy();
	}
	DisableMovementAndCollision();
}

void ALyraCharacter::OnEnergyChanged(AActor*)
{
	/*if (ShieldActor != nullptr)
	{
		ShieldActor->Destroy();
	}
	DisableMovementAndCollision();*/
}

void ALyraCharacter::OnDeathFinished(AActor*)
{
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::DestroyDueToDeath);
}

void ALyraCharacter::OnMaxEnergyChanged(AActor*)
{
	//GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::DestroyDueToDeath);
}

void ALyraCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	if (WantsToSliding == true)
	{
		ServerSlide(MaxSlideSpeed, 0.f, true, SlideGA, SlideCM);
		PlayTimeline();
	}
	else
	{
		GetCharacterMovement()->JumpZVelocity = DefaultJumpSpeed;
	}
}


void ALyraCharacter::DisableMovementAndCollision()
{
	if (Controller)
	{
		Controller->SetIgnoreMoveInput(true);
	}

	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	check(CapsuleComp);
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());
	LyraMoveComp->StopMovementImmediately();
	LyraMoveComp->DisableMovement();
}

void ALyraCharacter::DestroyDueToDeath()
{
	K2_OnDeathFinished();

	UninitAndDestroy();
}


void ALyraCharacter::UninitAndDestroy()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		DetachFromControllerPendingDestroy();
		SetLifeSpan(0.1f);
	}

	// Uninitialize the ASC if we're still the avatar actor (otherwise another pawn already did it when they became the avatar actor)
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		if (LyraASC->GetAvatarActor() == this)
		{
			PawnExtComponent->UninitializeAbilitySystem();
		}
	}

	SetActorHiddenInGame(true);
}

bool ALyraCharacter::CanSlide()
{
	return (this->GetLastMovementInputVector().Size() > 0.0f/* && GetCharacterMovement()->IsFalling() != true*/);
}

bool ALyraCharacter::IsMovingBackwards()
{
	return (FVector::DotProduct(this->GetLastMovementInputVector(), GetActorForwardVector()) < 0.f);
}

void ALyraCharacter::ResetCharacter()
{
	Reset();
}

void ALyraCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);

	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	SetMovementModeTag(PrevMovementMode, PreviousCustomMode, false);
	SetMovementModeTag(LyraMoveComp->MovementMode, LyraMoveComp->CustomMovementMode, true);
}

void ALyraCharacter::SetMovementModeTag(EMovementMode MovementMode, uint8 CustomMovementMode, bool bTagEnabled)
{
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		const FLyraGameplayTags& GameplayTags = FLyraGameplayTags::Get();
		const FGameplayTag* MovementModeTag = nullptr;

		if (MovementMode == MOVE_Custom)
		{
			MovementModeTag = GameplayTags.CustomMovementModeTagMap.Find(CustomMovementMode);
		}
		else
		{
			MovementModeTag = GameplayTags.MovementModeTagMap.Find(MovementMode);
		}

		if (MovementModeTag && MovementModeTag->IsValid())
		{
			LyraASC->SetLooseGameplayTagCount(*MovementModeTag, (bTagEnabled ? 1 : 0));
		}
	}
}

void ALyraCharacter::ToggleCrouch()
{
	const ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	if (bIsCrouched || LyraMoveComp->bWantsToCrouch)
	{
		UnCrouch();
	}
	else if (LyraMoveComp->IsMovingOnGround())
	{
		Crouch();
	}
}

bool ALyraCharacter::ServerSlide_Validate(float SlideSpeed, float Friction, bool IsSliding, ULyraGameplayAbility* GA, TSubclassOf<ULyraCameraMode> CameraMode)
{
	return true;
}

void ALyraCharacter::ServerSlide_Implementation(float SlideSpeed, float Friction, bool IsSliding, ULyraGameplayAbility* GA, TSubclassOf<ULyraCameraMode> CameraMode)
{
	RotateOnPlaneAngle();

	Sliding = IsSliding;

	USkeletalMeshComponent* MeshComp = GetMesh();
	ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(MeshComp->GetAnimInstance());
	if (AnimInst != nullptr)
	{
		AnimInst->OnSliding = IsSliding;
		//SetActorRotation(NewRot);
		MulticastSlide(SlideSpeed, Friction, IsSliding, GA, CameraMode);
	}

	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	if (LyraMoveComp != nullptr)
	{
		LyraMoveComp->MaxWalkSpeed = SlideSpeed;
		LyraMoveComp->GroundFriction = Friction;

		if (Sliding == true)
		{
			if (GA != nullptr)
			{
				GA->SetCameraMode(CameraMode);
			}
			/*if (bIsCrouched == true)
			{
				UnCrouch();
			}*/
		}
		else
		{
			if (GA != nullptr)
			{
				GA->ClearCameraMode();
				//GA->OnAbilityEnd();
			}
		}
	}
}

bool ALyraCharacter::MulticastSlide_Validate(float SlideSpeed, float Friction, bool IsSliding, ULyraGameplayAbility* GA, TSubclassOf<ULyraCameraMode> CameraMode)
{
	return true;
}

void ALyraCharacter::MulticastSlide_Implementation(float SlideSpeed, float Friction, bool IsSliding, ULyraGameplayAbility* GA, TSubclassOf<ULyraCameraMode> CameraMode)
{
	RotateOnPlaneAngle();

	Sliding = IsSliding;
	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	if (LyraMoveComp != nullptr)
	{
		LyraMoveComp->MaxWalkSpeed = SlideSpeed;
		LyraMoveComp->GroundFriction = Friction;

		if (Sliding == true)
		{
			/*if (bIsCrouched == true)
			{
				UnCrouch();
			}*/
			if (GA != nullptr)
			{
				GA->SetCameraMode(CameraMode);
			}
			USkeletalMeshComponent* MeshComp = GetMesh();

			ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(MeshComp->GetAnimInstance());
			if (AnimInst != nullptr)
			{
				AnimInst->OnSliding = IsSliding;
				//SetActorRotation(NewRot);
			}
		}
		else
		{
			if (GA != nullptr)
			{
				GA->ClearCameraMode();
				//GA->OnAbilityEnd();
			}
		}
	}
}

bool ALyraCharacter::ServerShield_Validate(TSubclassOf<AActor> ShieldToSpawn, FGameplayTagContainer Tag, TSubclassOf<UGameplayEffect> GameplayEffectClass, bool IsShield, float WalkSpeed)
{
	return true;
}

void ALyraCharacter::ServerShield_Implementation(TSubclassOf<AActor> ShieldToSpawn, FGameplayTagContainer Tag, TSubclassOf<UGameplayEffect> GameplayEffectClass, bool IsShield, float WalkSpeed)
{
	Blocking = IsShield;
	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	if (LyraMoveComp != nullptr)
	{
		LyraMoveComp->MaxWalkSpeed = WalkSpeed;

		if (Blocking == true)
		{
			//FGameplayEffectContextHandle EffectContext;

			//UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this)->BP_ApplyGameplayEffectToSelf(GameplayEffectClass, 0.f, EffectContext);
			
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			if (bIsCrouched == true)
			{
				UnCrouch();
			}

			AActor* Shield = GetWorld()->SpawnActor<AActor>(ShieldToSpawn, GetCapsuleComponent()->GetComponentTransform(), SpawnInfo);
			Shield->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);
			Shield->SetActorRelativeLocation(FVector(100.f, 0.f, 0.f));
			Shield->SetActorRelativeRotation(FRotator(0.f, 0.f, 0.f));
			ShieldActor = Shield;
		}
		else
		{
			//UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this)->RemoveActiveGameplayEffectBySourceEffect(GameplayEffectClass, UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this));
			if (ShieldActor != nullptr)
			{
				ShieldActor->Destroy();
			}
		}

		USkeletalMeshComponent* MeshComp = GetMesh();
		ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(MeshComp->GetAnimInstance());
		if (AnimInst != nullptr)
		{
			AnimInst->OnShield = IsShield;
			MulticastShield(Blocking, WalkSpeed, ShieldActor);
		}
	}
}

bool ALyraCharacter::MulticastShield_Validate(bool IsShield, float WalkSpeed, AActor* Shield)
{
	return true;
}

void ALyraCharacter::MulticastShield_Implementation(bool IsShield, float WalkSpeed, AActor* Shield)
{
	Blocking = IsShield;
	ULyraCharacterMovementComponent* LyraMoveComp = CastChecked<ULyraCharacterMovementComponent>(GetCharacterMovement());

	if (LyraMoveComp != nullptr)
	{
		LyraMoveComp->MaxWalkSpeed = WalkSpeed;

		if (Blocking == true)
		{
			if (bIsCrouched == true)
			{
				UnCrouch();
			}
			/*if (ShieldActor != nullptr)
			{
				ShieldActor->SetActorHiddenInGame(false);
			}*/
		}
		else
		{
			//UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this)->RemoveActiveGameplayEffectBySourceEffect(GameplayEffectClass, UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(this));
			if (ShieldActor != nullptr)
			{
				ShieldActor->Destroy();
			}
		}

		/*if (ShieldActor != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Shield : %s"), ShieldActor));
			ShieldActor->SetActorHiddenInGame(true);
		}*/

		USkeletalMeshComponent* MeshComp = GetMesh();
		ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(MeshComp->GetAnimInstance());
		if (AnimInst != nullptr)
		{
			AnimInst->OnShield = IsShield;
		}
	}
}

bool ALyraCharacter::ServerApplyGameplayEffect_Validate(UAbilitySystemComponent* AbilitySystem, TSubclassOf<UGameplayEffect> GameEffect)
{
	return true;
}

void ALyraCharacter::ServerApplyGameplayEffect_Implementation(UAbilitySystemComponent* AbilitySystem, TSubclassOf<UGameplayEffect> GameEffect)
{
	MulticastApplyGameplayEffect(AbilitySystem, GameEffect);

	FTimerHandle handle;
	FTimerDelegate TimerDelegate;

	//set the row boolean to false after finish cooldown timer
	TimerDelegate.BindLambda([AbilitySystem, GameEffect, this]()
	{
		AbilitySystem->RemoveActiveGameplayEffectBySourceEffect(GameEffect, AbilitySystem);

		HitActor = nullptr;
	});
	//delay
	this->GetWorldTimerManager().SetTimer(handle, TimerDelegate, .2f, false);
}

bool ALyraCharacter::MulticastApplyGameplayEffect_Validate(UAbilitySystemComponent* AbilitySystem, TSubclassOf<UGameplayEffect> GameEffect)
{
	return true;
}

void ALyraCharacter::MulticastApplyGameplayEffect_Implementation(UAbilitySystemComponent* AbilitySystem, TSubclassOf<UGameplayEffect> GameEffect)
{
	if (AbilitySystem != nullptr)
	{
		FGameplayEffectContextHandle NewHandle = FGameplayEffectContextHandle();
		AbilitySystem->BP_ApplyGameplayEffectToSelf(GameEffect, 0.f, NewHandle);
	}
}

void ALyraCharacter::OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		LyraASC->SetLooseGameplayTagCount(FLyraGameplayTags::Get().Status_Crouching, 1);
	}


	Super::OnStartCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

void ALyraCharacter::OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust)
{
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		LyraASC->SetLooseGameplayTagCount(FLyraGameplayTags::Get().Status_Crouching, 0);
	}

	Super::OnEndCrouch(HalfHeightAdjust, ScaledHalfHeightAdjust);
}

bool ALyraCharacter::CanJumpInternal_Implementation() const
{
	// same as ACharacter's implementation but without the crouch check
	return JumpIsAllowedInternal();
}

void ALyraCharacter::OnRep_ReplicatedAcceleration()
{
	if (ULyraCharacterMovementComponent* LyraMovementComponent = Cast<ULyraCharacterMovementComponent>(GetCharacterMovement()))
	{
		// Decompress Acceleration
		const double MaxAccel = LyraMovementComponent->MaxAcceleration;
		const double AccelXYMagnitude = double(ReplicatedAcceleration.AccelXYMagnitude) * MaxAccel / 255.0; // [0, 255] -> [0, MaxAccel]
		const double AccelXYRadians = double(ReplicatedAcceleration.AccelXYRadians) * TWO_PI / 255.0;     // [0, 255] -> [0, 2PI]

		FVector UnpackedAcceleration(FVector::ZeroVector);
		FMath::PolarToCartesian(AccelXYMagnitude, AccelXYRadians, UnpackedAcceleration.X, UnpackedAcceleration.Y);
		UnpackedAcceleration.Z = double(ReplicatedAcceleration.AccelZ) * MaxAccel / 127.0; // [-127, 127] -> [-MaxAccel, MaxAccel]

		LyraMovementComponent->SetReplicatedAcceleration(UnpackedAcceleration);
	}
}

void ALyraCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (GetController() == nullptr)
	{
		if (HasAuthority())
		{
			const FGenericTeamId OldTeamID = MyTeamID;
			MyTeamID = NewTeamID;
			ConditionalBroadcastTeamChanged(this, OldTeamID, MyTeamID);
		}
		else
		{
			UE_LOG(LogLyraTeams, Error, TEXT("You can't set the team ID on a character (%s) except on the authority"), *GetPathNameSafe(this));
		}
	}
	else
	{
		UE_LOG(LogLyraTeams, Error, TEXT("You can't set the team ID on a possessed character (%s); it's driven by the associated controller"), *GetPathNameSafe(this));
	}
}

FGenericTeamId ALyraCharacter::GetGenericTeamId() const
{
	return MyTeamID;
}

FOnLyraTeamIndexChangedDelegate* ALyraCharacter::GetOnTeamIndexChangedDelegate()
{
	return &OnTeamChangedDelegate;
}

void ALyraCharacter::OnControllerChangedTeam(UObject* TeamAgent, int32 OldTeam, int32 NewTeam)
{
	const FGenericTeamId MyOldTeamID = MyTeamID;
	MyTeamID = IntegerToGenericTeamId(NewTeam);
	ConditionalBroadcastTeamChanged(this, MyOldTeamID, MyTeamID);
}

void ALyraCharacter::OnRep_MyTeamID(FGenericTeamId OldTeamID)
{
	ConditionalBroadcastTeamChanged(this, OldTeamID, MyTeamID);
}

float ALyraCharacter::GetAngleSpeed()
{
	FRotator Rot = UKismetMathLibrary::FindLookAtRotation(PrevLocation, GetActorLocation());

	PrevLocation = GetActorLocation();

	return SpeedCurve->GetFloatValue(Rot.Pitch);
}

void ALyraCharacter::UpdateMovementSpeed(float DesiredSpeed)
{
	GetCharacterMovement()->MaxWalkSpeed = FMath::FInterpTo(GetCharacterMovement()->MaxWalkSpeed, DesiredSpeed, GetWorld()->GetDeltaSeconds(), 4.f);
	GetCharacterMovement()->JumpZVelocity = GetCharacterMovement()->MaxWalkSpeed;
}

void ALyraCharacter::TimelineCallback(float val)
{
	AActor* FloorActor = GetCharacterMovement()->CurrentFloor.HitResult.GetActor();

	if (FloorActor != nullptr && FloorActor->ActorHasTag("stairs") == true || IsMovingBackwards() == true)
	{
		TimelineFinishedCallback();
	}
	else
	{
		RotateOnPlaneAngle();
		// This function is called for every tick in the timeline.
		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Current value : %f"), val));

		UpdateMovementSpeed(GetAngleSpeed());

		FVector NormalizeVect;
		GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal(0.000f, NormalizeVect);

		FInputActionInstance ActionInstance(InputAction);
		FInputActionValue ActionValue = ActionInstance.GetValue();
		FVector2D Val = ActionValue.Get<FVector2D>();

		FVector WorldDir = FVector(NormalizeVect.X, NormalizeVect.Y, 0.0f);
		AddMovementInput(WorldDir, UKismetMathLibrary::Abs(Val.X) * val, true);
	}
}

void ALyraCharacter::TimelineFinishedCallback()
{
	// This function is called when the timeline finishes playing.
	FVector Start = GetCharacterMovement()->GetLastUpdateLocation();
	FVector End = Start + FVector(0.0f, 0.0f, -200.f);

	FHitResult Hit;
	FCollisionQueryParams AttackTraceParams;
	AttackTraceParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, AttackTraceParams);
	FVector DotRaw = FVector(GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal(0.0001f).X, GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal(0.0001f).Y, 0.0f);

	AActor* FloorActor = GetCharacterMovement()->CurrentFloor.HitResult.GetActor();

	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Dot product value: %f"), FVector::DotProduct(Hit.Normal, DotRaw)));
	if (FVector::DotProduct(Hit.Normal, DotRaw) > 0.1f && FloorActor != nullptr && FloorActor->ActorHasTag("stairs") == false && IsMovingBackwards() == false)
	{
		PlayTimeline();
		//RotateOnPlaneAngle();
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Continue")));
	}
	else
	{
		if (IsLocallyControlled())
		{
			ServerSlide(DefaultWalkSpeed, 8.0f, false, SlideGA, SlideCM);

			Sliding = false;

			//SetActorRotation(FRotator(0.0f, GetActorRotation().Yaw, 0.0f));
			GetCharacterMovement()->MaxWalkSpeed = DefaultWalkSpeed;
			GetCharacterMovement()->GroundFriction = 8.0f;

			USkeletalMeshComponent* MeshComp = GetMesh();
			ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(MeshComp->GetAnimInstance());
			if (AnimInst != nullptr)
			{
				AnimInst->OnSliding = false;
				AnimInst->CheckFloorAngle = FVector::DotProduct(Hit.Normal, DotRaw);
			}
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("END")));
			//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Dot product value: %f"), FVector::DotProduct(Hit.Normal, DotRaw)));
			WantsToSliding = false;
		}
		/*if (SlideGA != nullptr)
		{
			SlideGA->ClearCameraMode();
			SlideGA->OnAbilityEnd();
			return;
		}*/
	}
}

void ALyraCharacter::PlayTimeline()
{
	SlideTimeline->PlayFromStart();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("start timeline")));
}

void ALyraCharacter::DeclareSlidingTimeline()
{
	FOnTimelineFloat TimelineProgress;
	FOnTimelineEvent TimelineFinishedEvent;

	TimelineProgress.BindUFunction(this, FName("TimelineCallback"));
	TimelineFinishedEvent.BindUFunction(this, FName("TimelineFinishedCallback"));

	if (FloatCurve)
	{
		SlideTimeline->SetLooping(false);
		SlideTimeline->SetTimelineLength(5.83f);

		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Slide declared")));

		//Add the float curve to the timeline and connect it to your timelines's interpolation function
		SlideTimeline->AddInterpFloat(FloatCurve, TimelineProgress);
		SlideTimeline->SetTimelineFinishedFunc(TimelineFinishedEvent);
	}
}

void ALyraCharacter::RotateOnPlaneAngle()
{
	FVector Start = GetCharacterMovement()->GetLastUpdateLocation();
	FVector End = Start + FVector(0.0f, 0.0f, -200.f);

	FHitResult Hit;
	FCollisionQueryParams AttackTraceParams;
	AttackTraceParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, AttackTraceParams);
	FVector DotRaw = FVector(GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal(0.0001f).X, GetCharacterMovement()->GetLastUpdateVelocity().GetSafeNormal(0.0001f).Y, 0.0f);

	ULyraAnimInstance* AnimInst = Cast<ULyraAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInst != nullptr)
	{
		AnimInst->CheckFloorAngle = FVector::DotProduct(Hit.Normal, DotRaw);
		if (AnimInst->CheckFloorAngle > 0.f || AnimInst->CheckFloorAngle < 0.f)
		{
			AnimInst->CheckSlope = 1.f;
		}
		else
			AnimInst->CheckSlope = 0.0f;

		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, FString::Printf(TEXT("Dot product val: %f"), AnimInst->CheckSlope));
	}
	
	//if (bHit)
	//{
	//	if (AnimInst != nullptr && AnimInst->OnSliding == true)
	//	{
	//		AnimInst->OnSlidingSlope = true;
	//	}
	//	/*FVector VectorPlane = FVector::VectorPlaneProject(GetActorForwardVector(), Hit.ImpactNormal);
	//	FRotator NewRotation = FRotationMatrix::MakeFromXZ(VectorPlane, Hit.ImpactNormal).Rotator();

	//	FRotator FinalRot = FRotator(NewRotation.Pitch, NewRotation.Yaw, 0.0f);

	//	SetActorRotation(FinalRot);*/
	//}
	/*else
	{
		if (AnimInst != nullptr && AnimInst->OnSliding == true)
		{
			AnimInst->OnSlidingSlope = false;
		}
	}*/
}
