// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreUObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LyraHeroDataDefinition.generated.h"

class ULyraHeroDefinitionInstance;

UCLASS(DefaultToInstanced, EditInlineNew, Abstract)
class ULyraHeroFragment : public UObject
{
	GENERATED_BODY()

public:
	virtual void OnInstanceCreated(ULyraHeroDefinitionInstance* Instance) const {}
};
/**
 * 
 */
UCLASS(Blueprintable, Const, Abstract)
class LYRAGAME_API ULyraHeroDataDefinition : public UObject
{
	GENERATED_BODY()
	
public:
	ULyraHeroDataDefinition(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Display)
		FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Display, Instanced)
		TArray<TObjectPtr<ULyraHeroFragment>> Fragments;

public:
	const ULyraHeroFragment* FindFragmentByClass(TSubclassOf<ULyraHeroFragment> FragmentClass) const;
};

//@TODO: Make into a subsystem instead?
UCLASS()
class ULyraHeroFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType = FragmentClass))
		static const ULyraHeroFragment* FindItemDefinitionFragment(TSubclassOf<ULyraHeroDataDefinition> HeroDef, TSubclassOf<ULyraHeroFragment> FragmentClass);

};
