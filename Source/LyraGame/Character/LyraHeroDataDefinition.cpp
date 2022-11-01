// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraHeroDataDefinition.h"

ULyraHeroDataDefinition::ULyraHeroDataDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const ULyraHeroFragment* ULyraHeroDataDefinition::FindFragmentByClass(TSubclassOf<ULyraHeroFragment> FragmentClass) const
{
	if (FragmentClass != nullptr)
	{
		for (ULyraHeroFragment* Fragment : Fragments)
		{
			if (Fragment && Fragment->IsA(FragmentClass))
			{
				return Fragment;
			}
		}
	}

	return nullptr;
}

//////////////////////////////////////////////////////////////////////
// ULyraInventoryItemDefinition

const ULyraHeroFragment* ULyraHeroFunctionLibrary::FindItemDefinitionFragment(TSubclassOf<ULyraHeroDataDefinition> HeroDef, TSubclassOf<ULyraHeroFragment> FragmentClass)
{
	if ((HeroDef != nullptr) && (FragmentClass != nullptr))
	{
		return GetDefault<ULyraHeroDataDefinition>(HeroDef)->FindFragmentByClass(FragmentClass);
	}
	return nullptr;
}