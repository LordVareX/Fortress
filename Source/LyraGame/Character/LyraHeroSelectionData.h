// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LyraHeroSelectionData.generated.h"

class ULyraHeroDataDefinition;
class UStaticMesh;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Const, Meta = (DisplayName = "Lyra Hero Selection Data", ShortTooltip = "Data asset used to configure a hero selection."))
class LYRAGAME_API ULyraHeroSelectionData : public UDataAsset
{
	GENERATED_BODY()

public:

	//Defines the pickup's actors to spawn, abilities to grant, and tags to add
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Selection|Hero")
		TSubclassOf<ULyraHeroDataDefinition> HeroDataDefinition;

	//Visual representation of the pickup
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Selection|Actor Mesh")
		UStaticMesh* DisplayMesh;

	
};
