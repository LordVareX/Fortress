/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "DynamoDBModule.h"
#include "DynamoDBGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FDynamoDBModule"

void* FDynamoDBModule::DynamoDBLibraryHandle = nullptr;

void FDynamoDBModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if WITH_DYNAMODBCLIENTSDK
#if PLATFORM_WINDOWS && PLATFORM_64BITS

	LOG_DYNAMODB_NORMAL("Starting DynamoDBClient Module...");
	// Get the base directory of this plugin
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	// Add on the relative location of the third party dll and load it
	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBClientLibrary"), TEXT("Win64"));
	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString DynamoDBDLLName = "aws-cpp-sdk-dynamodb";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBDLLName, DynamoDBLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(DynamoDBLibraryHandle);
	}
#elif PLATFORM_MAC
	LOG_DYNAMODB_NORMAL("Starting DynamoDBClient Module...");
    // Get the base directory of this plugin
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    // Add on the relative location of the third party dll and load it
    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBClientLibrary"), TEXT("Mac"));
    LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString DynamoDBDLLName = "libaws-cpp-sdk-dynamodb";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBDLLName, DynamoDBLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(DynamoDBLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
	LOG_DYNAMODB_NORMAL("Starting DynamoDBClient Module...");
#endif
}

void FDynamoDBModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FreeDependency(DynamoDBLibraryHandle);
	LOG_DYNAMODB_NORMAL("Shutting down DynamoDB Module...");
}

bool FDynamoDBModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_DYNAMODB_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FDynamoDBModule::FreeDependency(void*& Handle)
{
#if !PLATFORM_LINUX && !PLATFORM_ANDROID && !PLATFORM_IOS
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDynamoDBModule, DynamoDB)
