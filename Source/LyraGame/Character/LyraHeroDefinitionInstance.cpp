// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LyraHeroDefinitionInstance.h"
#include "Net/UnrealNetwork.h"
#include "Character/LyraHeroDataDefinition.h"

ULyraHeroDefinitionInstance::ULyraHeroDefinitionInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ULyraHeroDefinitionInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, StatTags);
	DOREPLIFETIME(ThisClass, HeroDef);
}

void ULyraHeroDefinitionInstance::AddStatTagStack(FGameplayTag Tag, int32 StackCount)
{
	StatTags.AddStack(Tag, StackCount);
}

void ULyraHeroDefinitionInstance::RemoveStatTagStack(FGameplayTag Tag, int32 StackCount)
{
	StatTags.RemoveStack(Tag, StackCount);
}

int32 ULyraHeroDefinitionInstance::GetStatTagStackCount(FGameplayTag Tag) const
{
	return StatTags.GetStackCount(Tag);
}

bool ULyraHeroDefinitionInstance::HasStatTag(FGameplayTag Tag) const
{
	return StatTags.ContainsTag(Tag);
}

void ULyraHeroDefinitionInstance::SetHeroDef(TSubclassOf<ULyraHeroDataDefinition> InDef)
{
	HeroDef = InDef;
}


const ULyraHeroFragment* ULyraHeroDefinitionInstance::FindFragmentByClass(TSubclassOf<ULyraHeroFragment> FragmentClass) const
{
	if ((HeroDef != nullptr) && (FragmentClass != nullptr))
	{
		return GetDefault<ULyraHeroDataDefinition>(HeroDef)->FindFragmentByClass(FragmentClass);
	}

	return nullptr;
}
