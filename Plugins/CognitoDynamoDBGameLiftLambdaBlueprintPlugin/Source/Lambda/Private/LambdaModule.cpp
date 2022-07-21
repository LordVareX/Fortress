/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "LambdaModule.h"
#include "LambdaGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FLambdaModule"

void* FLambdaModule::LambdaLibraryHandle = nullptr;

void FLambdaModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if WITH_LAMBDACLIENTSDK
#if PLATFORM_WINDOWS && PLATFORM_64BITS

	LOG_LAMBDA_NORMAL("Starting LambdaClient Module...");
	// Get the base directory of this plugin
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	// Add on the relative location of the third party dll and load it
	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("LambdaClientLibrary"), TEXT("Win64"));
	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString LambdaDLLName = "aws-cpp-sdk-lambda";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, LambdaDLLName, LambdaLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(LambdaDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(LambdaLibraryHandle);
	}
#elif PLATFORM_MAC
    LOG_LAMBDA_NORMAL("Starting LambdaClient Module...");
    // Get the base directory of this plugin
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    // Add on the relative location of the third party dll and load it
    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("LambdaClientLibrary"), TEXT("Mac"));
    LOG_LAMBDA_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString LambdaDLLName = "libaws-cpp-sdk-lambda";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, LambdaDLLName, LambdaLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(LambdaDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(LambdaLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
    LOG_LAMBDA_NORMAL("Starting LambdaClient Module...");
#endif
}

void FLambdaModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FreeDependency(LambdaLibraryHandle);
	LOG_LAMBDA_NORMAL("Shutting down Lambda Module...");
}

bool FLambdaModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_LAMBDA_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FLambdaModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FLambdaModule, Lambda)
