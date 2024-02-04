// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Executions/LyraEnergyExecution.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/Attributes/LyraEnergySet.h"
#include "AbilitySystem/Attributes/LyraCombatSet.h"

struct FEnergyStatics
{
	FGameplayEffectAttributeCaptureDefinition BaseEnergyDef;

	FEnergyStatics()
	{
		BaseEnergyDef = FGameplayEffectAttributeCaptureDefinition(ULyraCombatSet::GetBaseEnergyAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
	}
};

static FEnergyStatics& EnergyStatics()
{
	static FEnergyStatics Statics;
	return Statics;
}

ULyraEnergyExecution::ULyraEnergyExecution()
{
	RelevantAttributesToCapture.Add(EnergyStatics().BaseEnergyDef);
}

void ULyraEnergyExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
#if WITH_SERVER_CODE
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float BaseRegen = 0.0f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(EnergyStatics().BaseEnergyDef, EvaluateParameters, BaseRegen);

	const float RegenDone = FMath::Max(0.0f, BaseRegen);

	if (RegenDone > 0.0f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(ULyraEnergySet::GetEnergyAttribute(), EGameplayModOp::Additive, RegenDone));
	}
#endif // #if WITH_SERVER_CODE
}
