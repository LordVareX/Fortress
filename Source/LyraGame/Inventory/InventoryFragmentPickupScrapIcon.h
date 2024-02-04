// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/LyraInventoryItemDefinition.h"
#include "InventoryFragmentPickupScrapIcon.generated.h"

class UStaticMesh;

UCLASS()
class LYRAGAME_API UInventoryFragmentPickupScrapIcon : public ULyraInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	UInventoryFragmentPickupScrapIcon();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
		TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
		FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
		FLinearColor PadColor;
};
