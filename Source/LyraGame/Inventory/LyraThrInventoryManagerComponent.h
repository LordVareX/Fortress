// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Components/PawnComponent.h"
#include "LyraThrInventoryManagerComponent.generated.h"

class ULyraInventoryItemDefinition;
class ULyraInventoryItemInstance;
class ULyraInventoryManagerComponent;
struct FLyraThrInventoryList;

USTRUCT(BlueprintType)
struct FLyraThrInventoryChangeMessage
{
	GENERATED_BODY()

		//@TODO: Tag based names+owning actors for inventories instead of directly exposing the component?
		UPROPERTY(BlueprintReadOnly, Category = Inventory)
		UActorComponent* InventoryOwner = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		ULyraInventoryItemInstance* Instance = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		int32 NewCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = Inventory)
		int32 Delta = 0;
};

/** A single entry in an inventory */
USTRUCT(BlueprintType)
struct FLyraThrInventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

		FLyraThrInventoryEntry()
	{}

	FString GetDebugString() const;

private:
	friend FLyraThrInventoryList;
	friend ULyraThrInventoryManagerComponent;

	UPROPERTY()
		ULyraInventoryItemInstance* Instance = nullptr;

	UPROPERTY()
		int32 StackCount = 0;

	UPROPERTY(NotReplicated)
		int32 LastObservedCount = INDEX_NONE;
};

/** List of inventory items */
USTRUCT(BlueprintType)
struct FLyraThrInventoryList : public FFastArraySerializer
{
	GENERATED_BODY()

		FLyraThrInventoryList()
		: OwnerComponent(nullptr)
	{
	}

	FLyraThrInventoryList(UActorComponent* InOwnerComponent)
		: OwnerComponent(InOwnerComponent)
	{
	}

	TArray<ULyraInventoryItemInstance*> GetAllItems() const;

public:
	//~FFastArraySerializer contract
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize);
	//~End of FFastArraySerializer contract

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FLyraThrInventoryEntry, FLyraThrInventoryList>(Entries, DeltaParms, *this);
	}

	ULyraInventoryItemInstance* AddEntry(TSubclassOf<ULyraInventoryItemDefinition> ItemClass, int32 StackCount);
	void AddEntry(ULyraInventoryItemInstance* Instance);

	void RemoveEntry(ULyraInventoryItemInstance* Instance);

private:
	void BroadcastChangeMessage(FLyraThrInventoryEntry& Entry, int32 OldCount, int32 NewCount);

private:
	friend ULyraThrInventoryManagerComponent;

private:
	// Replicated list of items
	UPROPERTY()
		TArray<FLyraThrInventoryEntry> Entries;

	UPROPERTY()
		UActorComponent* OwnerComponent;
};

template<>
struct TStructOpsTypeTraits<FLyraThrInventoryList> : public TStructOpsTypeTraitsBase2<FLyraThrInventoryList>
{
	enum { WithNetDeltaSerializer = true };
};



UCLASS(BlueprintType)
class LYRAGAME_API ULyraThrInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULyraThrInventoryManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = Inventory)
		bool CanAddItemDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef, int32 StackCount = 1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = Inventory)
		ULyraInventoryItemInstance* AddItemDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef, int32 StackCount = 1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = Inventory)
		void AddItemInstance(ULyraInventoryItemInstance* ItemInstance);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = Inventory)
		void RemoveItemInstance(ULyraInventoryItemInstance* ItemInstance);

	UFUNCTION(BlueprintCallable, Category = Inventory, BlueprintPure = false)
		TArray<ULyraInventoryItemInstance*> GetAllItems() const;

	UFUNCTION(BlueprintCallable, Category = Inventory, BlueprintPure)
		ULyraInventoryItemInstance* FindFirstItemStackByDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef) const;

	int32 GetTotalItemCountByDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef) const;
	bool ConsumeItemsByDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef, int32 NumToConsume);

	//~UObject interface
	virtual bool ReplicateSubobjects(class UActorChannel* Channel, class FOutBunch* Bunch, FReplicationFlags* RepFlags) override;
	//~End of UObject interface

private:
	UPROPERTY(Replicated)
	FLyraThrInventoryList InventoryList;

		
};
