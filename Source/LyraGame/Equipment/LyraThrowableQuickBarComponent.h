// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "GameFramework/GameplayMessageSubsystem.h"
#include "LyraThrowableQuickBarComponent.generated.h"

class ULyraInventoryItemInstance;
class ULyraEquipmentInstance;
class ULyraEquipmentManagerComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class LYRAGAME_API ULyraThrowableQuickBarComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	ULyraThrowableQuickBarComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "Lyra")
		void CycleActiveSlotForward();

	UFUNCTION(BlueprintCallable, Category = "Lyra")
		void CycleActiveSlotBackward();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Lyra")
		void SetActiveSlotIndex(int32 NewIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
		TArray<ULyraInventoryItemInstance*> GetSlots() const
	{
		return Slots;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
		int32 GetActiveSlotIndex() const { return ActiveSlotIndex; }

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
		ULyraInventoryItemInstance* GetActiveSlotItem() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
		int32 GetNextFreeItemSlot() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
		void AddItemToSlot(int32 SlotIndex, ULyraInventoryItemInstance* Item);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
		ULyraInventoryItemInstance* RemoveItemFromSlot(int32 SlotIndex);

	virtual void BeginPlay() override;

private:
	void UnequipItemInSlot();
	void EquipItemInSlot();

	ULyraEquipmentManagerComponent* FindEquipmentManager() const;

protected:
	UPROPERTY()
		int32 NumSlots = 3;

	UFUNCTION()
		void OnRep_Slots();

	UFUNCTION()
		void OnRep_ActiveSlotIndex();

private:
	UPROPERTY(ReplicatedUsing = OnRep_Slots)
		TArray<TObjectPtr<ULyraInventoryItemInstance>> Slots;

	UPROPERTY(ReplicatedUsing = OnRep_ActiveSlotIndex)
		int32 ActiveSlotIndex = -1;

	UPROPERTY()
		TObjectPtr<ULyraEquipmentInstance> EquippedItem;
};


USTRUCT(BlueprintType)
struct FLyraThrowableQuickBarSlotsChangedMessage
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, Category = Inventory)
		AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		TArray<TObjectPtr<ULyraInventoryItemInstance>> Slots;
};


USTRUCT(BlueprintType)
struct FLyraThrowableQuickBarActiveIndexChangedMessage
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, Category = Inventory)
		AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		int32 ActiveIndex = 0;
	
};
