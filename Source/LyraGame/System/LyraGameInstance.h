// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CommonGameInstance.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "LyraGameInstance.generated.h"

class ULyraSocialManager;
class ULyraSocialParty;
class USocialManager;
class ALyraPlayerController;
class ULyraInventoryItemDefinition;

UCLASS(Config = Game)
class LYRAGAME_API ULyraGameInstance : public UCommonGameInstance
{
	GENERATED_BODY()

public:

	ULyraGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	ALyraPlayerController* GetPrimaryPlayerController() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool ThrowMode = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool ThrowGrenadeMode = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray< TSubclassOf<ULyraInventoryItemDefinition>> ItemDefArray;

	UPROPERTY()
	FTimerHandle SetAveragePlayerLatencyHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Server)
	FString PingString;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	void SetAveragePlayerLatency();

	TDoubleLinkedList<float> PlayerLatencies;

	UPROPERTY()
	FTimerHandle GetResponseTimeHandle;

	UPROPERTY()
	bool ActivateLatency = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString GameSessionId;// = "132143124124521421421";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> ArrayGameSessionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerSessionId = "psess-3c191f4c-4571-4455-8f9e-73bc00935148";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PlayerId;// = "b55fb4bb-62ff-449f-a9c9-0aed93722d90";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Username; //= "VareX";


protected:

	virtual void Init() override;
	virtual void Shutdown() override;

private:

	UPROPERTY()
	float AveragePlayerLatency;

	FHttpModule* HttpModule;

	UPROPERTY()
	FString ApiUrl;

	UPROPERTY()
	FString RegionCode;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	void GetResponseTime();

	void OnGetResponseTimeResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};
