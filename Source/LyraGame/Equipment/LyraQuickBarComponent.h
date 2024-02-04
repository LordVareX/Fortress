// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "GameFramework/GameplayMessageSubsystem.h"

#include "LyraQuickBarComponent.generated.h"

class ULyraInventoryItemInstance;
class ULyraEquipmentInstance;
class ULyraEquipmentManagerComponent;
class ULyraInventoryItemDefinition;

UCLASS(Blueprintable, meta=(BlueprintSpawnableComponent))
class ULyraQuickBarComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	ULyraQuickBarComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category="Lyra")
	void CycleActiveSlotForward();

	UFUNCTION(BlueprintCallable, Category="Lyra")
	void CycleActiveSlotBackward();

	UFUNCTION(BlueprintCallable, Category = "Lyra")
	void ThrowableCycleActiveSlotForward();

	UFUNCTION(BlueprintCallable, Category = "Lyra")
	void ThrowableCycleActiveSlotBackward();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category="Lyra")
	void SetActiveSlotIndex(int32 NewIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Lyra")
	void SetActiveThrowableSlotIndex(int32 NewIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<ULyraInventoryItemInstance*> GetSlots() const
	{
		return Slots;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<ULyraInventoryItemInstance*> GetThrowableSlots() const
	{
		return ThrowableSlots;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	int32 GetActiveSlotIndex() const { return ActiveSlotIndex; }

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	int32 GetActiveThrowableSlotIndex() const { return ActiveThrowableSlotIndex; }

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	ULyraInventoryItemInstance* GetActiveSlotItem() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	ULyraInventoryItemInstance* GetActiveThrowableSlotItem() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	int32 GetNextFreeItemSlot() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	int32 GetNextFreeThrowableItemSlot() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddItemToSlot(int32 SlotIndex, ULyraInventoryItemInstance* Item);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddThrowableItemToSlot(int32 SlotIndex, ULyraInventoryItemInstance* Item);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	ULyraInventoryItemInstance* RemoveItemFromSlot(int32 SlotIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	ULyraInventoryItemInstance* RemoveThrowableItemFromSlot(int32 SlotIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int NewSlotIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> ItemArrayDefinition;

	virtual void BeginPlay() override;

private:
	void UnequipItemInSlot();
	void EquipItemInSlot();
	void ThrowableUnequipItemInSlot();
	void ThrowableEquipItemInSlot();

	ULyraEquipmentManagerComponent* FindEquipmentManager() const;

protected:
	UPROPERTY()
	int32 NumSlots = 6;

	UPROPERTY()
	int32 ThrowableNumSlots = 6;

	UFUNCTION()
	void OnRep_Slots();

	UFUNCTION()
	void OnRep_ThrowableSlots();

	UFUNCTION()
	void OnRep_ActiveSlotIndex();

	UFUNCTION()
	void OnRep_ThrowableActiveSlotIndex();

private:
	UPROPERTY(ReplicatedUsing=OnRep_Slots)
	TArray<TObjectPtr<ULyraInventoryItemInstance>> Slots;

	UPROPERTY(ReplicatedUsing = OnRep_Slots)
	TArray<TObjectPtr<ULyraInventoryItemInstance>> ThrowableSlots;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveSlotIndex)
	int32 ActiveSlotIndex = -1;

	UPROPERTY(ReplicatedUsing = OnRep_ThrowableActiveSlotIndex)
	int32 ActiveThrowableSlotIndex = -1;

	UPROPERTY()
	TObjectPtr<ULyraEquipmentInstance> EquippedItem;

	UPROPERTY()
	TObjectPtr<ULyraEquipmentInstance> ThrowableEquippedItem;
};


USTRUCT(BlueprintType)
struct FLyraQuickBarSlotsChangedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category=Inventory)
	AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
	TArray<TObjectPtr<ULyraInventoryItemInstance>> Slots;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
	TArray<TObjectPtr<ULyraInventoryItemInstance>> ThrowableSlots;

};


USTRUCT(BlueprintType)
struct FLyraQuickBarActiveIndexChangedMessage
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category=Inventory)
	AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category=Inventory)
	int32 ActiveIndex = 0;

};

USTRUCT(BlueprintType)
struct FLyraQuickBarThrowableSlotsChangedMessage
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, Category = Inventory)
		AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		TArray<TObjectPtr<ULyraInventoryItemInstance>> ThrowableSlots;
};


USTRUCT(BlueprintType)
struct FLyraQuickBarThrowableActiveIndexChangedMessage
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, Category = Inventory)
		AActor* Owner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		int32 ThrowableActiveIndex = 0;
};
