// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraCameraComponent.h"
#include "LyraCameraMode.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Canvas.h"
#include "Character/LyraCharacter.h"
#include "Math/Vector.h"
#include "Player/LyraPlayerState.h"
#include "GameFramework/GameplayMessageSubsystem.h"


ULyraCameraComponent::ULyraCameraComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CameraModeStack = nullptr;
	FieldOfViewOffset = 0.0f;
}

void ULyraCameraComponent::Visibility_GetNotRenderedActors(TArray<class ALyraCharacter*>& CurrentlyNotRenderedActors, float MinRecentTime)
{
	//Empty any previous entries
	CurrentlyNotRenderedActors.Empty();

	//Iterate Over Actors
	for (TObjectIterator<ALyraCharacter> Itr; Itr; ++Itr)
	{
		if (Itr->GetLastRenderTime() <= MinRecentTime)
		{
			CurrentlyNotRenderedActors.Add(*Itr);
			ALyraCharacter* Char = Cast<ALyraCharacter>(*Itr);
			if (Char != nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Player not in view %s"), *Char->GetFName().ToString()));
			}
		}
	}
}

void ULyraCameraComponent::OnRegister()
{
	Super::OnRegister();

	if (!CameraModeStack)
	{
		CameraModeStack = NewObject<ULyraCameraModeStack>(this);
		check(CameraModeStack);
	}
}

void ULyraCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
	check(CameraModeStack);

	UpdateCameraModes();

	FLyraCameraModeView CameraModeView;
	CameraModeStack->EvaluateStack(DeltaTime, CameraModeView);

	// Keep player controller in sync with the latest view.
	if (APawn* TargetPawn = Cast<APawn>(GetTargetActor()))
	{
		if (APlayerController* PC = TargetPawn->GetController<APlayerController>())
		{
			thisPS = Cast<ALyraPlayerState>(PC->PlayerState);
			if (thisPS != nullptr)
			{
				PC->SetControlRotation(CameraModeView.ControlRotation);

				if (!thisPS->IsABot())
				{
					for (TObjectIterator<ALyraCharacter> Itr; Itr; ++Itr)
					{
						ALyraCharacter* Char = Cast<ALyraCharacter>(*Itr);
						if (Char != nullptr && Char != TargetPawn)
						{
							ALyraPlayerState* PS = Cast<ALyraPlayerState>(Char->GetPlayerState());
							if (PS != nullptr && thisPS->GetTeamId() != PS->GetTeamId())
							{
								if (PC->LineOfSightTo(Char) && Char->GetLastRenderTime() > 0.1f)
								{
									FGameplayTag GetTag;
									FLyraVerbMessage SpawnIconMessage;

									SpawnIconMessage.Instigator = PS;
									SpawnIconMessage.Verb = GetTag.RequestGameplayTag("Show Enemy");

									//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Is in view")));
									if (GetNetMode() != NM_DedicatedServer)
									{
										UGameplayMessageSubsystem::Get(this).BroadcastMessage(SpawnIconMessage.Verb, SpawnIconMessage);
									}
								}
								else if (!PC->LineOfSightTo(Char) && Char->GetLastRenderTime() <= 0.1f)
								{
									FGameplayTag GetTag;
									FLyraVerbMessage SpawnIconMessage;

									SpawnIconMessage.Instigator = PS;
									SpawnIconMessage.Verb = GetTag.RequestGameplayTag("Hide Enemy");

									//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Is out of view")));
									if (GetNetMode() != NM_DedicatedServer)
									{
										UGameplayMessageSubsystem::Get(this).BroadcastMessage(SpawnIconMessage.Verb, SpawnIconMessage);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	// Apply any offset that was added to the field of view.
	CameraModeView.FieldOfView += FieldOfViewOffset;
	FieldOfViewOffset = 0.0f;

	// Keep camera component in sync with the latest view.
	SetWorldLocationAndRotation(CameraModeView.Location, CameraModeView.Rotation);
	FieldOfView = CameraModeView.FieldOfView;

	// Fill in desired view.
	DesiredView.Location = CameraModeView.Location;
	DesiredView.Rotation = CameraModeView.Rotation;
	DesiredView.FOV = CameraModeView.FieldOfView;
	DesiredView.OrthoWidth = OrthoWidth;
	DesiredView.OrthoNearClipPlane = OrthoNearClipPlane;
	DesiredView.OrthoFarClipPlane = OrthoFarClipPlane;
	DesiredView.AspectRatio = AspectRatio;
	DesiredView.bConstrainAspectRatio = bConstrainAspectRatio;
	DesiredView.bUseFieldOfViewForLOD = bUseFieldOfViewForLOD;
	DesiredView.ProjectionMode = ProjectionMode;

	// See if the CameraActor wants to override the PostProcess settings used.
	DesiredView.PostProcessBlendWeight = PostProcessBlendWeight;
	if (PostProcessBlendWeight > 0.0f)
	{
		DesiredView.PostProcessSettings = PostProcessSettings;
	}
}

void ULyraCameraComponent::UpdateCameraModes()
{
	check(CameraModeStack);

	if (CameraModeStack->IsStackActivate())
	{
		if (DetermineCameraModeDelegate.IsBound())
		{
			if (const TSubclassOf<ULyraCameraMode> CameraMode = DetermineCameraModeDelegate.Execute())
			{
				CameraModeStack->PushCameraMode(CameraMode);
			}
		}
	}
}

void ULyraCameraComponent::DrawDebug(UCanvas* Canvas) const
{
	check(Canvas);

	FDisplayDebugManager& DisplayDebugManager = Canvas->DisplayDebugManager;

	DisplayDebugManager.SetFont(GEngine->GetSmallFont());
	DisplayDebugManager.SetDrawColor(FColor::Yellow);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("LyraCameraComponent: %s"), *GetNameSafe(GetTargetActor())));

	DisplayDebugManager.SetDrawColor(FColor::White);
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   Location: %s"), *GetComponentLocation().ToCompactString()));
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   Rotation: %s"), *GetComponentRotation().ToCompactString()));
	DisplayDebugManager.DrawString(FString::Printf(TEXT("   FOV: %f"), FieldOfView));

	check(CameraModeStack);
	CameraModeStack->DrawDebug(Canvas);
}

void ULyraCameraComponent::GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const
{
	check(CameraModeStack);
	CameraModeStack->GetBlendInfo(/*out*/ OutWeightOfTopLayer, /*out*/ OutTagOfTopLayer);
}

