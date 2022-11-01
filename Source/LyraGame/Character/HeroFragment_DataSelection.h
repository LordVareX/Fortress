// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/LyraHeroDataDefinition.h"
#include "Character/LyraHeroSkillsetDefinition.h"
#include "HeroFragment_DataSelection.generated.h"

/**
 * 
 */
UCLASS()
class LYRAGAME_API UHeroFragment_DataSelection : public ULyraHeroFragment
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = Lyra)
	TSubclassOf<ULyraHeroSkillsetDefinition> HeroDataSkillset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Appearance)
	TObjectPtr<USkeletalMesh> SkeletalMesh;
};
