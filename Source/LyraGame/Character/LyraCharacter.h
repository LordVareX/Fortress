// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "Teams/LyraTeamAgentInterface.h"
#include "AbilitySystemInterface.h"
#include "GameplayCueInterface.h"
#include "GameplayTagAssetInterface.h"
#include "Components/TimelineComponent.h"
#include "InputAction.h"
#include "LyraCharacter.generated.h"


class ALyraPlayerController;
class ALyraPlayerState;
class ULyraAbilitySystemComponent;
class UAbilitySystemComponent;
class ULyraPawnExtensionComponent;
class ULyraHealthComponent;
class ULyraEnergyComponent;
class ULyraCameraComponent;
class UInputAction;
class ULyraGameplayAbility;
class ULyraCameraMode;


/**
 * FLyraReplicatedAcceleration: Compressed representation of acceleration
 */
USTRUCT()
struct FLyraReplicatedAcceleration
{
	GENERATED_BODY()

		UPROPERTY()
		uint8 AccelXYRadians = 0;	// Direction of XY accel component, quantized to represent [0, 2*pi]

	UPROPERTY()
		uint8 AccelXYMagnitude = 0;	//Accel rate of XY component, quantized to represent [0, MaxAcceleration]

	UPROPERTY()
		int8 AccelZ = 0;	// Raw Z accel rate component, quantized to represent [-MaxAcceleration, MaxAcceleration]
};


/**
 * ALyraCharacter
 *
 *	The base character pawn class used by this project.
 *	Responsible for sending events to pawn components.
 *	New behavior should be added via pawn components when possible.
 */
UCLASS(Config = Game, Meta = (ShortTooltip = "The base character pawn class used by this project."))
class ALyraCharacter : public AModularCharacter, public IAbilitySystemInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface, public ILyraTeamAgentInterface
{
	GENERATED_BODY()

		UPROPERTY()
		class UTimelineComponent* SlideTimeline;

public:

	ALyraCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
		ALyraPlayerController* GetLyraPlayerController() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
		ALyraPlayerState* GetLyraPlayerState() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
		ULyraAbilitySystemComponent* GetLyraAbilitySystemComponent() const;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;

	void ToggleCrouch();

	//~For Damage implementation Mechanic
	UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation, Category = "Transformation")
		void ServerApplyGameplayEffect(UAbilitySystemComponent* AbilitySystem, TSubclassOf<class UGameplayEffect> GameEffect);

	UFUNCTION(Unreliable, NetMulticast, WithValidation, Category = "Transformation")
		void MulticastApplyGameplayEffect(UAbilitySystemComponent* AbilitySystem, TSubclassOf<class UGameplayEffect> GameEffect);

	//~For Sliding mechanic
	UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation, Category = "Transformation")
	void ServerSlide(float SlideSpeed, float Friction, bool IsSliding, class ULyraGameplayAbility* GA, TSubclassOf<class ULyraCameraMode> CameraMode);

	UFUNCTION(Unreliable, NetMulticast, WithValidation, Category = "Transformation")
	void MulticastSlide(float SlideSpeed, float Friction, bool IsSliding, class ULyraGameplayAbility* GA, TSubclassOf<class ULyraCameraMode> CameraMode);

	//~For Shield mechanic
	UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation, Category = "Shield")
	void ServerShield(TSubclassOf<AActor> ShieldToSpawn, FGameplayTagContainer Tag, TSubclassOf<UGameplayEffect> GameplayEffectClass, bool IsShield, float WalkSpeed);

	UFUNCTION(Unreliable, NetMulticast, WithValidation, Category = "Shield")
	void MulticastShield(bool IsShield, float WalkSpeed, AActor* Shield);


	//~AActor interface
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Reset() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker) override;
	//~End of AActor interface

	//~APawn interface
	virtual void NotifyControllerChanged() override;
	//~End of APawn interface

	//~ILyraTeamAgentInterface interface
	virtual void SetGenericTeamId(const FGenericTeamId& NewTeamID) override;
	virtual FGenericTeamId GetGenericTeamId() const override;
	virtual FOnLyraTeamIndexChangedDelegate* GetOnTeamIndexChangedDelegate() override;
	//~End of ILyraTeamAgentInterface interface

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
		bool Sliding = false;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	bool Blocking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WantsToJump = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WantsToShield = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool WantsToSliding = false;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	bool StartDash = false;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
		int SlotIndex = 0;

	UPROPERTY(EditDefaultsOnly)
		UInputAction* InputAction;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OnResetStart"))
		void ResetCharacter();

	UPROPERTY(Replicated)
	AActor* ShieldActor = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class ULyraGameplayAbility* SlideGA;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<class ULyraCameraMode> SlideCM;

protected:

	virtual void OnAbilitySystemInitialized();
	virtual void OnAbilitySystemUninitialized();

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	virtual void OnRep_Controller() override;
	virtual void OnRep_PlayerState() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void InitializeGameplayTags();

	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;

	UFUNCTION()
	virtual void Landed(const FHitResult& Hit);

	// Begins the death sequence for the character (disables collision, disables movement, etc...)
	UFUNCTION()
		virtual void OnDeathStarted(AActor* OwningActor);

	// Ends the death sequence for the character (detaches controller, destroys pawn, etc...)
	UFUNCTION()
		virtual void OnDeathFinished(AActor* OwningActor);

	// Begins the energy sequence for the character (disables collision, disables movement, etc...)
	UFUNCTION()
		virtual void OnEnergyChanged(AActor* OwningActor);

	// Ends the max energy sequence for the character (detaches controller, destroys pawn, etc...)
	UFUNCTION()
		virtual void OnMaxEnergyChanged(AActor* OwningActor);

	void DisableMovementAndCollision();
	void DestroyDueToDeath();
	void UninitAndDestroy();

	UFUNCTION(BlueprintPure)
		bool CanSlide();

	UFUNCTION(BlueprintPure, Category = "Movement")
		bool IsMovingBackwards();

	// Called when the death sequence for the character has completed
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnDeathFinished"))
		void K2_OnDeathFinished();

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;
	void SetMovementModeTag(EMovementMode MovementMode, uint8 CustomMovementMode, bool bTagEnabled);

	virtual void OnStartCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;
	virtual void OnEndCrouch(float HalfHeightAdjust, float ScaledHalfHeightAdjust) override;

	virtual bool CanJumpInternal_Implementation() const;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
		ULyraPawnExtensionComponent* PawnExtComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
		ULyraHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
		ULyraEnergyComponent* EnergyComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
		ULyraCameraComponent* CameraComponent;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Character", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ShieldComponent;*/

	UPROPERTY(Transient, ReplicatedUsing = OnRep_ReplicatedAcceleration)
		FLyraReplicatedAcceleration ReplicatedAcceleration;

	UPROPERTY(ReplicatedUsing = OnRep_MyTeamID)
		FGenericTeamId MyTeamID;

	UPROPERTY()
		FOnLyraTeamIndexChangedDelegate OnTeamChangedDelegate;

	UPROPERTY()
	FRotator BaseRot;

protected:
	// Called to determine what happens to the team ID when possession ends
	virtual FGenericTeamId DetermineNewTeamAfterPossessionEnds(FGenericTeamId OldTeamID) const
	{
		// This could be changed to return, e.g., OldTeamID if you want to keep it assigned afterwards, or return an ID for some neutral faction, or etc...
		return FGenericTeamId::NoTeam;
	}

private:
	UFUNCTION()
		void OnControllerChangedTeam(UObject* TeamAgent, int32 OldTeam, int32 NewTeam);

	UFUNCTION()
		void OnRep_ReplicatedAcceleration();

	UFUNCTION()
		void OnRep_MyTeamID(FGenericTeamId OldTeamID);

	UFUNCTION(BlueprintCallable)
		float GetAngleSpeed();

	UFUNCTION(BlueprintCallable)
	void UpdateMovementSpeed(float DesiredSpeed);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WantsToCrouch = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector PrevLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCurveFloat* SpeedCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxSlideSpeed = 1950.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DefaultWalkSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DefaultJumpSpeed = 500.f;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite)
		AActor* HitActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector DashLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector NewLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Timeline")
		class UCurveFloat* FloatCurve;

	UFUNCTION()
		void TimelineCallback(float val);

	UFUNCTION()
		void TimelineFinishedCallback();

	UFUNCTION(BlueprintCallable)
		void PlayTimeline();

	UFUNCTION()
		void DeclareSlidingTimeline();

	UFUNCTION(BlueprintCallable)
		void RotateOnPlaneAngle();
};
