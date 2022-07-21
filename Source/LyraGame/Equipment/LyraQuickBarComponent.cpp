// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraQuickBarComponent.h"

#include "NativeGameplayTags.h"
#include "GameFramework/GameplayMessageSubsystem.h"

#include "Net/UnrealNetwork.h"
#include "Inventory/LyraInventoryItemInstance.h"
#include "Inventory/LyraInventoryItemDefinition.h"
#include "Inventory/InventoryFragment_EquippableItem.h"
#include "Equipment/LyraEquipmentInstance.h"
#include "Equipment/LyraEquipmentDefinition.h"
#include "Equipment/LyraEquipmentManagerComponent.h"
#include "Character/LyraCharacter.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_QuickBar_Message_SlotsChanged, "Lyra.QuickBar.Message.SlotsChanged");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_QuickBar_Message_ActiveIndexChanged, "Lyra.QuickBar.Message.ActiveIndexChanged");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_QuickBar_Message_ThrowableSlotsChanged, "Lyra.QuickBar.Message.ThrowableSlotsChanged");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Lyra_QuickBar_Message_ThrowableActiveIndexChanged, "Lyra.QuickBar.Message.ThrowableActiveIndexChanged");

ULyraQuickBarComponent::ULyraQuickBarComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicatedByDefault(true);
}

void ULyraQuickBarComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, Slots);
	DOREPLIFETIME(ThisClass, ThrowableSlots);
	DOREPLIFETIME(ThisClass, ActiveSlotIndex);
	DOREPLIFETIME(ThisClass, ActiveThrowableSlotIndex);
}

void ULyraQuickBarComponent::BeginPlay()
{
	if (Slots.Num() < NumSlots)
	{
		Slots.AddDefaulted(NumSlots - Slots.Num());
	}

	if (ThrowableSlots.Num() < ThrowableNumSlots)
	{
		ThrowableSlots.AddDefaulted(ThrowableNumSlots - ThrowableSlots.Num());
	}

	Super::BeginPlay();
}

void ULyraQuickBarComponent::CycleActiveSlotForward()
{
	if (Slots.Num() < 2)
	{
		
		return;
	}

	const int32 OldIndex = (ActiveSlotIndex < 0 ? 3-1 : ActiveSlotIndex);
	int32 NewIndex = ActiveSlotIndex;
	do
	{
		NewIndex = (NewIndex + 1) % 3;
		if (Slots[NewIndex] != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Current slots : %i"), Slots.Num()));
			SetActiveSlotIndex(NewIndex);
			return;
		}
	} while (NewIndex != OldIndex);
}

void ULyraQuickBarComponent::ThrowableCycleActiveSlotForward()
{
	if (Slots.Num() < 5)
	{
		return;
	}

	const int32 OldIndex = (ActiveSlotIndex != 0 || ActiveSlotIndex != 1 || ActiveSlotIndex != 2);
	int32 NewIndex = ActiveSlotIndex;
	
	if (NewIndex < 3)
	{
		if (Slots[3] != nullptr)
		{
			NewIndex = 3;

			SetActiveSlotIndex(NewIndex);
			return;
		}
		else
		{
			if (Slots[4] != nullptr)
			{
				NewIndex = 4;

				SetActiveSlotIndex(NewIndex);
				return;
			}
			else
			{
				if (Slots[5] != nullptr)
				{
					NewIndex = 5;

					SetActiveSlotIndex(NewIndex);
					return;
				}
				else
				{
					NewIndex = 1;

					SetActiveSlotIndex(NewIndex);
					return;
				}
			}
		}
	}
	else if (NewIndex > 2)
	{	
			if (Slots[5] != nullptr)
			{	
				int CurrentSlot = Slots.Num() - 1;
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Current slots : %i"), NewIndex));
				
				if (NewIndex != 5)
				{
					NewIndex = (NewIndex + 1) % Slots.Num();
					
					if (Slots[4] != nullptr)
					{
						SetActiveSlotIndex(NewIndex);
						return;
					}
					else
					{
						//NewIndex = (NewIndex + 1) % Slots.Num();
						if (Slots[5] != nullptr)
						{
							

							SetActiveSlotIndex(NewIndex);
							return;
						}
						else
						{
							//NewIndex = (NewIndex + 1) % Slots.Num();
							if (Slots[3] != nullptr)
							{

								SetActiveSlotIndex(NewIndex);
								return;
							}
							
						}
					}
				}
				if (NewIndex == 5)
				{
					if (Slots[3] != nullptr)
					{
						NewIndex = 3;
						SetActiveSlotIndex(NewIndex);
						return;
					}
					else
					{
						if (Slots[4] != nullptr)
						{
							NewIndex = 4;
							SetActiveSlotIndex(NewIndex);
							return;
						}
						else
						{
							if (Slots[5] != nullptr)
							{
								NewIndex = 5;
								SetActiveSlotIndex(NewIndex);
								return;
							}
							else
							{
								NewIndex = 1;

								SetActiveSlotIndex(NewIndex);
								return;
							}
						}
					}
				}
			}
			else if (Slots[4] != nullptr)
			{
				int CurrentSlot = Slots.Num() - 1;
				//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Current slots : %i"), CurrentSlot));

				if (NewIndex != 4)
				{
					NewIndex = (NewIndex + 1) % Slots.Num();

					if (Slots[4] != nullptr)
					{
						SetActiveSlotIndex(NewIndex);
						return;
					}
					else
					{
						//NewIndex = (NewIndex + 1) % Slots.Num();
						if (Slots[5] != nullptr)
						{


							SetActiveSlotIndex(NewIndex);
							return;
						}
						else
						{
							//NewIndex = (NewIndex + 1) % Slots.Num();
							if (Slots[3] != nullptr)
							{

								SetActiveSlotIndex(NewIndex);
								return;
							}

						}
					}
				}
				if (NewIndex == 4)
				{
					if (Slots[3] != nullptr)
					{
						NewIndex = 3;
						SetActiveSlotIndex(NewIndex);
						return;
					}
					else
					{
						if (Slots[4] != nullptr)
						{
							NewIndex = 4;
							SetActiveSlotIndex(NewIndex);
							return;
						}
						else
						{
							if (Slots[5] != nullptr)
							{
								NewIndex = 5;
								SetActiveSlotIndex(NewIndex);
								return;
							}
							else
							{
								NewIndex = 1;

								SetActiveSlotIndex(NewIndex);
								return;
							}
						}
					}
				}
			}
	}
}

void ULyraQuickBarComponent::CycleActiveSlotBackward()
{
	if (Slots.Num() < 2)
	{
		return;
	}

	const int32 OldIndex = (ActiveSlotIndex < 0 ? 3-1 : ActiveSlotIndex);
	int32 NewIndex = ActiveSlotIndex;
	do
	{
		NewIndex = (NewIndex - 1 + 3) % 3;
		if (Slots[NewIndex] != nullptr)
		{
			SetActiveSlotIndex(NewIndex);
			return;
		}
	} while (NewIndex != OldIndex);
}

void ULyraQuickBarComponent::ThrowableCycleActiveSlotBackward()
{
	if (Slots.Num() < 2)
	{
		return;
	}

	const int32 OldIndex = (ActiveSlotIndex < 0 ? 3 - 1 : ActiveSlotIndex);
	int32 NewIndex = ActiveSlotIndex;
	do
	{
		NewIndex = (NewIndex - 1 + 3) % 3;
		if (Slots[NewIndex] != nullptr)
		{
			SetActiveSlotIndex(NewIndex);
			return;
		}
	} while (NewIndex != OldIndex);
}

void ULyraQuickBarComponent::EquipItemInSlot()
{
	check(Slots.IsValidIndex(ActiveSlotIndex));
	check(EquippedItem == nullptr);

	if (ULyraInventoryItemInstance* SlotItem = Slots[ActiveSlotIndex])
	{
		if (const UInventoryFragment_EquippableItem* EquipInfo = SlotItem->FindFragmentByClass<UInventoryFragment_EquippableItem>())
		{
			TSubclassOf<ULyraEquipmentDefinition> EquipDef = EquipInfo->EquipmentDefinition;
			if (EquipDef != nullptr)
			{
				if (ULyraEquipmentManagerComponent* EquipmentManager = FindEquipmentManager())
				{
					EquippedItem = EquipmentManager->EquipItem(EquipDef);
					if (EquippedItem != nullptr)
					{
						EquippedItem->SetInstigator(SlotItem);
					}
				}
			}
		}
	}
}

void ULyraQuickBarComponent::ThrowableEquipItemInSlot()
{
	check(ThrowableSlots.IsValidIndex(ActiveSlotIndex));
	check(EquippedItem == nullptr);

	if (ULyraInventoryItemInstance* SlotItem = ThrowableSlots[ActiveSlotIndex])
	{
		if (const UInventoryFragment_EquippableItem* EquipInfo = SlotItem->FindFragmentByClass<UInventoryFragment_EquippableItem>())
		{
			TSubclassOf<ULyraEquipmentDefinition> EquipDef = EquipInfo->EquipmentDefinition;
			if (EquipDef != nullptr)
			{
				if (ULyraEquipmentManagerComponent* EquipmentManager = FindEquipmentManager())
				{
					EquippedItem = EquipmentManager->EquipItem(EquipDef);
					if (EquippedItem != nullptr)
					{
						EquippedItem->SetInstigator(SlotItem);
					}
				}
			}
		}
	}
}

void ULyraQuickBarComponent::UnequipItemInSlot()
{
	if (ULyraEquipmentManagerComponent* EquipmentManager = FindEquipmentManager())
	{
		if (EquippedItem != nullptr)
		{
			EquipmentManager->UnequipItem(EquippedItem);
			EquippedItem = nullptr;
		}
	}
}

void ULyraQuickBarComponent::ThrowableUnequipItemInSlot()
{
	if (ULyraEquipmentManagerComponent* EquipmentManager = FindEquipmentManager())
	{
		if (EquippedItem != nullptr)
		{
			EquipmentManager->UnequipItem(EquippedItem);
			EquippedItem = nullptr;
		}
	}
}

ULyraEquipmentManagerComponent* ULyraQuickBarComponent::FindEquipmentManager() const
{
	if (AController* OwnerController = Cast<AController>(GetOwner()))
	{
		if (APawn* Pawn = OwnerController->GetPawn())
		{
			return Pawn->FindComponentByClass<ULyraEquipmentManagerComponent>();
		}
	}
	return nullptr;
}

void ULyraQuickBarComponent::SetActiveSlotIndex_Implementation(int32 NewIndex)
{
	if (Slots.IsValidIndex(NewIndex) && (ActiveSlotIndex != NewIndex))
	{
		UnequipItemInSlot();

		ActiveSlotIndex = NewIndex;

		EquipItemInSlot();

		OnRep_ActiveSlotIndex();
	}
}

void ULyraQuickBarComponent::SetActiveThrowableSlotIndex_Implementation(int32 NewIndex)
{
	if (ThrowableSlots.IsValidIndex(NewIndex) && (ActiveSlotIndex != NewIndex))
	{
		ThrowableUnequipItemInSlot();

		ActiveSlotIndex = NewIndex;

		ThrowableEquipItemInSlot();

		OnRep_ActiveSlotIndex();
	}
}

ULyraInventoryItemInstance* ULyraQuickBarComponent::GetActiveSlotItem() const
{
	return Slots.IsValidIndex(ActiveSlotIndex) ? Slots[ActiveSlotIndex] : nullptr;
}

ULyraInventoryItemInstance* ULyraQuickBarComponent::GetActiveThrowableSlotItem() const
{
	return ThrowableSlots.IsValidIndex(ActiveSlotIndex) ? ThrowableSlots[ActiveSlotIndex] : nullptr;
}

int32 ULyraQuickBarComponent::GetNextFreeItemSlot() const
{
	int32 SlotIndex = 0;
	for (TObjectPtr<ULyraInventoryItemInstance> ItemPtr : Slots)
	{
		if (ItemPtr == nullptr)
		{
			return SlotIndex;
		}
		++SlotIndex;
	}

	return INDEX_NONE;
}

int32 ULyraQuickBarComponent::GetNextFreeThrowableItemSlot() const
{
	int32 SlotIndex = 0;
	for (TObjectPtr<ULyraInventoryItemInstance> ItemPtr : ThrowableSlots)
	{
		if (ItemPtr == nullptr)
		{
			return SlotIndex;
		}
		++SlotIndex;
	}

	return INDEX_NONE;
}

void ULyraQuickBarComponent::AddItemToSlot(int32 SlotIndex, ULyraInventoryItemInstance* Item)
{
	if (Slots.IsValidIndex(SlotIndex) || ThrowableSlots.IsValidIndex(SlotIndex) && (Item != nullptr))
	{
		if (Slots[SlotIndex] == nullptr)
		{
			Slots[SlotIndex] = Item;
			OnRep_Slots();
		}
		else if (ThrowableSlots[SlotIndex] == nullptr)
		{
			ThrowableSlots[SlotIndex] = Item;
			OnRep_Slots();
		}

	}
}

void ULyraQuickBarComponent::AddThrowableItemToSlot(int32 SlotIndex, ULyraInventoryItemInstance* Item)
{
	if (ThrowableSlots.IsValidIndex(SlotIndex) && (Item != nullptr))
	{
		if (ThrowableSlots[SlotIndex] == nullptr)
		{
			ThrowableSlots[SlotIndex] = Item;
			OnRep_Slots();
		}
	}
}

ULyraInventoryItemInstance* ULyraQuickBarComponent::RemoveItemFromSlot(int32 SlotIndex)
{
	ULyraInventoryItemInstance* Result = nullptr;

	if (ActiveSlotIndex == SlotIndex)
	{
		UnequipItemInSlot();
		ActiveSlotIndex = -1;
	}

	if (Slots.IsValidIndex(SlotIndex))
	{
		Result = Slots[SlotIndex];

		if (Result != nullptr)
		{
			Slots[SlotIndex] = nullptr;
			OnRep_Slots();
		}
	}

	return Result;
}

ULyraInventoryItemInstance* ULyraQuickBarComponent::RemoveThrowableItemFromSlot(int32 SlotIndex)
{
	ULyraInventoryItemInstance* Result = nullptr;

	if (ActiveSlotIndex == SlotIndex)
	{
		ThrowableUnequipItemInSlot();
		ActiveSlotIndex = -1;
	}

	if (ThrowableSlots.IsValidIndex(SlotIndex))
	{
		Result = ThrowableSlots[SlotIndex];

		if (Result != nullptr)
		{
			ThrowableSlots[SlotIndex] = nullptr;
			OnRep_Slots();
		}
	}

	return Result;
}

void ULyraQuickBarComponent::OnRep_Slots()
{
	FLyraQuickBarSlotsChangedMessage Message;
	Message.Owner = GetOwner();
	Message.Slots = Slots;
	Message.ThrowableSlots = ThrowableSlots;

	UGameplayMessageSubsystem& MessageSystem = UGameplayMessageSubsystem::Get(this);
	MessageSystem.BroadcastMessage(TAG_Lyra_QuickBar_Message_SlotsChanged, Message);
}

void ULyraQuickBarComponent::OnRep_ThrowableSlots()
{
	FLyraQuickBarThrowableSlotsChangedMessage Message;
	Message.Owner = GetOwner();
	Message.ThrowableSlots = ThrowableSlots;

	UGameplayMessageSubsystem& MessageSystem = UGameplayMessageSubsystem::Get(this);
	MessageSystem.BroadcastMessage(TAG_Lyra_QuickBar_Message_ThrowableSlotsChanged, Message);
}

void ULyraQuickBarComponent::OnRep_ActiveSlotIndex()
{
	FLyraQuickBarActiveIndexChangedMessage Message;
	Message.Owner = GetOwner();
	Message.ActiveIndex = ActiveSlotIndex;

	UGameplayMessageSubsystem& MessageSystem = UGameplayMessageSubsystem::Get(this);
	MessageSystem.BroadcastMessage(TAG_Lyra_QuickBar_Message_ActiveIndexChanged, Message);
}

void ULyraQuickBarComponent::OnRep_ThrowableActiveSlotIndex()
{
	FLyraQuickBarThrowableActiveIndexChangedMessage Message;
	Message.Owner = GetOwner();
	Message.ThrowableActiveIndex = ActiveThrowableSlotIndex;

	UGameplayMessageSubsystem& MessageSystem = UGameplayMessageSubsystem::Get(this);
	MessageSystem.BroadcastMessage(TAG_Lyra_QuickBar_Message_ThrowableActiveIndexChanged, Message);
}
