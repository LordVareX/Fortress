// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraGameInstance.h"
#include "Player/LyraPlayerController.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/World.h"

ULyraGameInstance::ULyraGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HttpModule = &FHttpModule::Get();
	AveragePlayerLatency = 60.0;
}

void ULyraGameInstance::Init()
{
	Super::Init();

	/*GetWorld()->GetTimerManager().SetTimer(SetAveragePlayerLatencyHandle, this, &ULyraGameInstance::SetAveragePlayerLatency, 1.0f, true, 1.0f);
	GetWorld()->GetTimerManager().SetTimer(GetResponseTimeHandle, this, &ULyraGameInstance::GetResponseTime, 1.0f, true, 1.0f);*/

	
}

void ULyraGameInstance::Shutdown()
{
	Super::Shutdown();

	/*GetWorld()->GetTimerManager().ClearTimer(GetResponseTimeHandle);
	GetWorld()->GetTimerManager().ClearTimer(SetAveragePlayerLatencyHandle);*/
}

ALyraPlayerController* ULyraGameInstance::GetPrimaryPlayerController() const
{
	return Cast<ALyraPlayerController>(Super::GetPrimaryPlayerController(false));
}

void ULyraGameInstance::GetResponseTime() {
	TSharedRef<IHttpRequest> GetResponseTimeRequest = HttpModule->CreateRequest();
	GetResponseTimeRequest->OnProcessRequestComplete().BindUObject(this, &ULyraGameInstance::OnGetResponseTimeResponseReceived);
	GetResponseTimeRequest->SetURL("https://gamelift.ap-southeast-1.amazonaws.com");
	GetResponseTimeRequest->SetVerb("GET");
	GetResponseTimeRequest->ProcessRequest();
}

void ULyraGameInstance::OnGetResponseTimeResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	
	if (PlayerLatencies.Num() >= 4) {
		PlayerLatencies.RemoveNode(PlayerLatencies.GetHead());
	}

	float ResponseTime = Request->GetElapsedTime() * 1000;
	//UE_LOG(LogTemp, Warning, TEXT("response time in milliseconds: %s"), *FString::SanitizeFloat(ResponseTime));

	PlayerLatencies.AddTail(ResponseTime);
	ActivateLatency = true;

	SetAveragePlayerLatency();
}

void ULyraGameInstance::SetAveragePlayerLatency() {
	if (ActivateLatency == true)
	{
		float TotalPlayerLatency = 0.0f;
		for (float PlayerLatency : PlayerLatencies) {
			TotalPlayerLatency += PlayerLatency;
		}

		if (TotalPlayerLatency > 0) {
			AveragePlayerLatency = TotalPlayerLatency / PlayerLatencies.Num();

			PingString = FString::FromInt(FMath::RoundToInt(AveragePlayerLatency));//"Ping: " + FString::FromInt(FMath::RoundToInt(AveragePlayerLatency)) + "ms";
			//PingTextBlock->SetText(FText::FromString(PingString));
		}
	}
}

