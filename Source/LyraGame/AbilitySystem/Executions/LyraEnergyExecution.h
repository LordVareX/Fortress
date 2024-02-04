// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "LyraEnergyExecution.generated.h"

/**
 * 
 */
UCLASS()
class LYRAGAME_API ULyraEnergyExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:

	ULyraEnergyExecution();

protected:

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	
};
