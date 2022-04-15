// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/PickupLoot.h"
#include "Net/UnrealNetwork.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Equipment/LyraEquipmentDefinition.h"
#include "Equipment/LyraEquipmentManagerComponent.h"
#include "Equipment/LyraPickupDefinition.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Inventory/LyraInventoryItemDefinition.h"
#include "Inventory/InventoryFragment_SetStats.h"
#include "TimerManager.h"
#include "LyraLogChannels.h"

// Sets default values
APickupLoot::APickupLoot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CollisionVolume = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionVolume"));
	CollisionVolume->InitCapsuleSize(80.f, 80.f);
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &APickupLoot::OnOverlapBegin);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponMeshRotationSpeed = 40.0f;
	bIsWeaponAvailable = true;
	bReplicates = true;

}

// Called when the game starts or when spawned
void APickupLoot::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APickupLoot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* World = GetWorld();

	WeaponMesh->AddRelativeRotation(FRotator(0.0f, World->GetDeltaSeconds() * WeaponMeshRotationSpeed, 0.0f));

}

void APickupLoot::OnConstruction(const FTransform& Transform)
{
	if (WeaponDefinition != nullptr && WeaponDefinition->DisplayMesh != nullptr)
	{
		WeaponMesh->SetStaticMesh(WeaponDefinition->DisplayMesh);
		WeaponMesh->SetRelativeLocation(WeaponDefinition->WeaponMeshOffset);
		WeaponMesh->SetRelativeScale3D(WeaponDefinition->WeaponMeshScale);
	}
}

void APickupLoot::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	APawn* OverlappingPawn = Cast<APawn>(OtherActor);
	if (GetLocalRole() == ROLE_Authority && bIsWeaponAvailable && OverlappingPawn != nullptr)
	{
		AttemptPickUpWeapon(OverlappingPawn);
	}
}

void APickupLoot::CheckForExistingOverlaps()
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors, APawn::StaticClass());

	for (AActor* OverlappingActor : OverlappingActors)
	{
		AttemptPickUpWeapon(Cast<APawn>(OverlappingActor));
	}
}

void APickupLoot::AttemptPickUpWeapon_Implementation(APawn* Pawn)
{
	if (GetLocalRole() == ROLE_Authority && bIsWeaponAvailable && UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Pawn))
	{
		TSubclassOf<ULyraInventoryItemDefinition> WeaponItemDefinition = WeaponDefinition ? WeaponDefinition->InventoryItemDefinition : nullptr;
		if (WeaponItemDefinition != nullptr)
		{
			//Attempt to grant the weapon
			if (GiveWeapon(WeaponItemDefinition, Pawn))
			{
				//Weapon picked up by pawn
				bIsWeaponAvailable = false;
				SetWeaponPickupVisibility(false);
				PlayPickupEffects();
				Destroy();
				//StartCoolDown();
			}
		}
	}
}

void APickupLoot::SetWeaponPickupVisibility(bool bShouldBeVisible)
{
	WeaponMesh->SetVisibility(bShouldBeVisible, true);
}

void APickupLoot::PlayPickupEffects_Implementation()
{
	if (WeaponDefinition != nullptr)
	{
		USoundBase* PickupSound = WeaponDefinition->PickedUpSound;
		if (PickupSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
		}

		UNiagaraSystem* PickupEffect = WeaponDefinition->PickedUpEffect;
		if (PickupEffect != nullptr)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, PickupEffect, WeaponMesh->GetComponentLocation());
		}
	}
}

void APickupLoot::OnRep_WeaponAvailability()
{
	if (bIsWeaponAvailable)
	{
		SetWeaponPickupVisibility(false);
		//StartCoolDown();
		PlayPickupEffects();
	}
}

void APickupLoot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickupLoot, bIsWeaponAvailable);
}

int32 APickupLoot::GetDefaultStatFromItemDef(const TSubclassOf<ULyraInventoryItemDefinition> WeaponItemClass, FGameplayTag StatTag)
{
	if (WeaponItemClass != nullptr)
	{
		if (ULyraInventoryItemDefinition* WeaponItemCDO = WeaponItemClass->GetDefaultObject<ULyraInventoryItemDefinition>())
		{
			if (const UInventoryFragment_SetStats* ItemStatsFragment = Cast<UInventoryFragment_SetStats>(WeaponItemCDO->FindFragmentByClass(UInventoryFragment_SetStats::StaticClass())))
			{
				return ItemStatsFragment->GetItemStatByTag(StatTag);
			}
		}
	}

	return 0;
}
