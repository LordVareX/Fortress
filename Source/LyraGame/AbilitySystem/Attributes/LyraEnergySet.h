// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LyraAttributeSet.h"
#include "NativeGameplayTags.h"
#include "LyraEnergySet.generated.h"

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_Energy);
//UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_DamageImmunity);
//UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_DamageSelfDestruct);
//UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Gameplay_FellOutOfWorld);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Lyra_Energy_Message);

struct FGameplayEffectModCallbackData;

/**
 * 
 */
UCLASS()
class ULyraEnergySet : public ULyraAttributeSet
{
	GENERATED_BODY()

public:
	
	ULyraEnergySet();

	ATTRIBUTE_ACCESSORS(ULyraEnergySet, Energy);
	ATTRIBUTE_ACCESSORS(ULyraEnergySet, MaxEnergy);
	ATTRIBUTE_ACCESSORS(ULyraEnergySet, Regen);

	// Delegate to broadcast when the energy attribute reaches zero.
	mutable FLyraAttributeEvent OnOutOfEnergy;

protected:

	UFUNCTION()
	void OnRep_Energy(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxEnergy(const FGameplayAttributeData& OldValue);

	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

private:

	// The current health attribute.  The health will be capped by the max health attribute.  Health is hidden from modifiers so only executions can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Energy, Category = "Lyra|Health", Meta = (HideFromModifiers, AllowPrivateAccess = true))
		FGameplayAttributeData Energy;

	// The current max health attribute.  Max health is an attribute since gameplay effects can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxEnergy, Category = "Lyra|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MaxEnergy;

	// Used to track when the health reaches 0.
	bool bOutOfEnergy;

	// -------------------------------------------------------------------
	//	Meta Attribute (please keep attributes that aren't 'stateful' below 
	// -------------------------------------------------------------------

private:
	// Incoming healing. This is mapped directly to +Energy
	UPROPERTY(BlueprintReadOnly, Category = "Lyra|Energy", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Regen;

	// Incoming damage. This is mapped directly to -Energy
	UPROPERTY(BlueprintReadOnly, Category = "Lyra|Energy", Meta = (HideFromModifiers, AllowPrivateAccess = true))
		FGameplayAttributeData Use;
};
