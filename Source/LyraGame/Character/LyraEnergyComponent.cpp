// Fill out your copyright notice in the Description page of Project Settings.


#include "LyraEnergyComponent.h"
#include "LyraLogChannels.h"
#include "System/LyraAssetManager.h"
#include "System/LyraGameData.h"
#include "LyraGameplayTags.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "GameplayPrediction.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/LyraEnergySet.h"
#include "Messages/LyraVerbMessage.h"
#include "Messages/LyraVerbMessageHelpers.h"
#include "NativeGameplayTags.h"
#include "Components/GameFrameworkComponentManager.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "GameFramework/PlayerState.h"

ULyraEnergyComponent::ULyraEnergyComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;

	SetIsReplicatedByDefault(true);

	AbilitySystemComponent = nullptr;
	EnergySet = nullptr;
}

//void ULyraEnergyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
//{
//	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
//	/*DOREPLIFETIME(ULyraEnergyComponent, DeathState);*/
//}

void ULyraEnergyComponent::OnUnregister()
{
	UninitializeFromAbilitySystem();

	Super::OnUnregister();
}

void ULyraEnergyComponent::InitializeWithAbilitySystem(ULyraAbilitySystemComponent* InASC)
{
	AActor* Owner = GetOwner();
	check(Owner);

	if (AbilitySystemComponent)
	{
		UE_LOG(LogLyra, Error, TEXT("LyraEnergyComponent: Energy component for owner [%s] has already been initialized with an ability system."), *GetNameSafe(Owner));
		return;
	}

	AbilitySystemComponent = InASC;
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogLyra, Error, TEXT("LyraEnergyComponent: Cannot initialize Energy component for owner [%s] with NULL ability system."), *GetNameSafe(Owner));
		return;
	}

	EnergySet = AbilitySystemComponent->GetSet<ULyraEnergySet>();
	if (!EnergySet)
	{
		UE_LOG(LogLyra, Error, TEXT("LyraEnergyComponent: Cannot initialize Energy component for owner [%s] with NULL Energy set on the ability system."), *GetNameSafe(Owner));
		return;
	}

	// Register to listen for attribute changes.
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(ULyraEnergySet::GetEnergyAttribute()).AddUObject(this, &ThisClass::HandleEnergyChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(ULyraEnergySet::GetMaxEnergyAttribute()).AddUObject(this, &ThisClass::HandleMaxEnergyChanged);
	EnergySet->OnOutOfEnergy.AddUObject(this, &ThisClass::HandleOutOfEnergy);

	// TEMP: Reset attributes to default values.  Eventually this will be driven by a spread sheet.
	AbilitySystemComponent->SetNumericAttributeBase(ULyraEnergySet::GetEnergyAttribute(), EnergySet->GetMaxEnergy());

	ClearGameplayTags();

	OnEnergyChanged.Broadcast(this, EnergySet->GetEnergy(), EnergySet->GetEnergy(), nullptr);
	OnMaxEnergyChanged.Broadcast(this, EnergySet->GetEnergy(), EnergySet->GetEnergy(), nullptr);
}

void ULyraEnergyComponent::UninitializeFromAbilitySystem()
{
	ClearGameplayTags();

	if (EnergySet)
	{
		EnergySet->OnOutOfEnergy.RemoveAll(this);
	}

	EnergySet = nullptr;
	AbilitySystemComponent = nullptr;
}

void ULyraEnergyComponent::ClearGameplayTags()
{
	if (AbilitySystemComponent)
	{
		const FLyraGameplayTags& GameplayTags = FLyraGameplayTags::Get();

		//AbilitySystemComponent->SetLooseGameplayTagCount(GameplayTags.Status_Death_Dying, 0);
		//AbilitySystemComponent->SetLooseGameplayTagCount(GameplayTags.Status_Death_Dead, 0);
	}
}

float ULyraEnergyComponent::GetEnergy() const
{
	return (EnergySet ? EnergySet->GetEnergy() : 0.0f);
}

float ULyraEnergyComponent::GetMaxEnergy() const
{
	return (EnergySet ? EnergySet->GetMaxEnergy() : 0.0f);
}

float ULyraEnergyComponent::GetEnergyNormalized() const
{
	if (EnergySet)
	{
		const float Energy = EnergySet->GetEnergy();
		const float MaxEnergy = EnergySet->GetMaxEnergy();

		return ((MaxEnergy > 0.0f) ? (Energy / MaxEnergy) : 0.0f);
	}

	return 0.0f;
}

static AActor* GetInstigatorFromEnergyAttrChangeData(const FOnAttributeChangeData& ChangeData)
{
	if (ChangeData.GEModData != nullptr)
	{
		const FGameplayEffectContextHandle& EffectContext = ChangeData.GEModData->EffectSpec.GetEffectContext();
		return EffectContext.GetOriginalInstigator();
	}

	return nullptr;
}

void ULyraEnergyComponent::HandleEnergyChanged(const FOnAttributeChangeData& ChangeData)
{
	OnEnergyChanged.Broadcast(this, ChangeData.OldValue, ChangeData.NewValue, GetInstigatorFromEnergyAttrChangeData(ChangeData));
}

void ULyraEnergyComponent::HandleMaxEnergyChanged(const FOnAttributeChangeData& ChangeData)
{
	OnMaxEnergyChanged.Broadcast(this, ChangeData.OldValue, ChangeData.NewValue, GetInstigatorFromEnergyAttrChangeData(ChangeData));
}

void ULyraEnergyComponent::HandleOutOfEnergy(AActor* EnergyInstigator, AActor* EnergyCauser, const FGameplayEffectSpec& EnergyEffectSpec, float EnergyMagnitude)
{
#if WITH_SERVER_CODE
	if (AbilitySystemComponent)
	{
		// Send the "GameplayEvent.Death" gameplay event through the owner's ability system.  This can be used to trigger a death gameplay ability.
		/*{
			FGameplayEventData Payload;
			Payload.EventTag = FLyraGameplayTags::Get().GameplayEvent_Death;
			Payload.Instigator = EnergyInstigator;
			Payload.Target = AbilitySystemComponent->GetAvatarActor();
			Payload.OptionalObject = EnergyEffectSpec.Def;
			Payload.ContextHandle = EnergyEffectSpec.GetEffectContext();
			Payload.InstigatorTags = *EnergyEffectSpec.CapturedSourceTags.GetAggregatedTags();
			Payload.TargetTags = *EnergyEffectSpec.CapturedTargetTags.GetAggregatedTags();
			Payload.EventMagnitude = EnergyMagnitude;

			FScopedPredictionWindow NewScopedWindow(AbilitySystemComponent, true);
			AbilitySystemComponent->HandleGameplayEvent(Payload.EventTag, &Payload);
		}*/

		// Send a standardized verb message that other systems can observe
		//{
		//	FLyraVerbMessage Message;
		//	Message.Verb = TAG_Lyra_Elimination_Message;
		//	Message.Instigator = EnergyInstigator;
		//	Message.InstigatorTags = *EnergyEffectSpec.CapturedSourceTags.GetAggregatedTags();
		//	Message.Target = ULyraVerbMessageHelpers::GetPlayerStateFromObject(AbilitySystemComponent->GetAvatarActor());
		//	Message.TargetTags = *EnergyEffectSpec.CapturedTargetTags.GetAggregatedTags();
		//	//@TODO: Fill out context tags, and any non-ability-system source/instigator tags
		//	//@TODO: Determine if it's an opposing team kill, self-own, team kill, etc...

		//	UGameplayMessageSubsystem& MessageSystem = UGameplayMessageSubsystem::Get(GetWorld());
		//	MessageSystem.BroadcastMessage(Message.Verb, Message);
		//}

		//@TODO: assist messages (could compute from damage dealt elsewhere)?
	}

#endif // #if WITH_SERVER_CODE
}