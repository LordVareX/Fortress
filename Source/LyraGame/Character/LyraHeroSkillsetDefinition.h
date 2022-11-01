// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "LyraHeroSkillsetDefinition.generated.h"

class ULyraAbilitySet;
/**
 * 
 */
UCLASS(Blueprintable, Const, Abstract, BlueprintType)
class LYRAGAME_API ULyraHeroSkillsetDefinition : public UObject
{
	GENERATED_BODY()
	
public:
	ULyraHeroSkillsetDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// Gameplay ability sets to grant when this is equipped
	UPROPERTY(EditAnywhere, Category = Skillset)
	TArray<TObjectPtr<const ULyraAbilitySet>> AbilitySetsToGrant;
};
