// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Character/LyraPawnComponent.h"
#include "LyraEnergyComponent.generated.h"

class ULyraAbilitySystemComponent;
class ULyraEnergySet;
struct FGameplayEffectSpec;
struct FOnAttributeChangeData;

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLyraEnergy_AttributeChanged, AActor*, OwningActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FLyraEnergy_AttributeChanged, ULyraEnergyComponent*, EnergyComponent, float, OldValue, float, NewValue, AActor*, Instigator);

/**
 * ULyraEnergyComponent
 *
 *	An actor component used to handle anything related to Energy.
 */
UCLASS(Blueprintable, Meta = (BlueprintSpawnableComponent))
class LYRAGAME_API ULyraEnergyComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:

	ULyraEnergyComponent(const FObjectInitializer& ObjectInitializer);

	// Returns the energy component if one exists on the specified actor.
	UFUNCTION(BlueprintPure, Category = "Lyra|Energy")
		static ULyraEnergyComponent* FindEnergyComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<ULyraEnergyComponent>() : nullptr); }

	// Initialize the component using an ability system component.
	UFUNCTION(BlueprintCallable, Category = "Lyra|Energy")
		void InitializeWithAbilitySystem(ULyraAbilitySystemComponent* InASC);

	// Uninitialize the component, clearing any references to the ability system.
	UFUNCTION(BlueprintCallable, Category = "Lyra|Energy")
		void UninitializeFromAbilitySystem();

	// Returns the current Energy value.
	UFUNCTION(BlueprintCallable, Category = "Lyra|Energy")
		float GetEnergy() const;

	// Returns the current maximum Energy value.
	UFUNCTION(BlueprintCallable, Category = "Lyra|Energy")
		float GetMaxEnergy() const;

	// Returns the current Energy in the range [0.0, 1.0].
	UFUNCTION(BlueprintCallable, Category = "Lyra|Energy")
		float GetEnergyNormalized() const;

public:

	// Delegate fired when the Energy value has changed.
	UPROPERTY(BlueprintAssignable)
		FLyraEnergy_AttributeChanged OnEnergyChanged;

	// Delegate fired when the max Energy value has changed.
	UPROPERTY(BlueprintAssignable)
		FLyraEnergy_AttributeChanged OnMaxEnergyChanged;

protected:

	virtual void OnUnregister() override;

	void ClearGameplayTags();

	virtual void HandleEnergyChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleMaxEnergyChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleOutOfEnergy(AActor* EnergyInstigator, AActor* EnergyCauser, const FGameplayEffectSpec& EnergyEffectSpec, float EnergyMagnitude);

protected:

	// Ability system used by this component.
	UPROPERTY()
		ULyraAbilitySystemComponent* AbilitySystemComponent;

	// Energy set used by this component.
	UPROPERTY()
		const ULyraEnergySet* EnergySet;
	
};
