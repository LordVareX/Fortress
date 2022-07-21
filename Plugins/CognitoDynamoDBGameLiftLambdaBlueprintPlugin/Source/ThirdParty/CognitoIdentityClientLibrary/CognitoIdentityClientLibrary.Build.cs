/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

using System.IO;
using UnrealBuildTool;

public class CognitoIdentityClientLibrary : ModuleRules
{
    public CognitoIdentityClientLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        PublicIncludePaths.Add(ModuleDirectory);

        string ThirdPartyPath = System.IO.Path.Combine(ModuleDirectory, Target.Platform.ToString());

        if (Target.Type != TargetRules.TargetType.Server)
        {
            if (Target.Platform == UnrealTargetPlatform.Linux || Target.Platform == UnrealTargetPlatform.LinuxArm64)
            {
                if (Target.Platform == UnrealTargetPlatform.LinuxArm64) {
                    ThirdPartyPath = System.IO.Path.Combine(ThirdPartyPath, "aarch64-unknown-linux-gnu");
        		} else if (Target.Platform == UnrealTargetPlatform.Linux) {
                    ThirdPartyPath = System.IO.Path.Combine(ThirdPartyPath, "x86_64-unknown-linux-gnu");
        		}

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-cognito-identity.so"));
                RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-cognito-identity.so"));
            }
            else if (Target.Platform == UnrealTargetPlatform.Android)
            {
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(ModuleDirectory, "CognitoIdentityClientSDK_UPL.xml"));

                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "armeabi-v7a", "libaws-cpp-sdk-cognito-identity.so"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "armeabi-v7a", "libaws-cpp-sdk-cognito-identity.so"));
                }

                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-cpp-sdk-cognito-identity.so"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-cpp-sdk-cognito-identity.so"));
                }

                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-cpp-sdk-cognito-identity.so"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-cpp-sdk-cognito-identity.so"));
                }

            }
            else if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "aws-cpp-sdk-cognito-identity.lib"));
                PublicDelayLoadDLLs.Add("aws-cpp-sdk-cognito-identity.dll");
                RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "aws-cpp-sdk-cognito-identity.dll"));
            }
            else if (Target.Platform == UnrealTargetPlatform.Mac)
            {
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-cognito-identity.dylib"));
                RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-cognito-identity.dylib"));
            }
            else if (Target.Platform == UnrealTargetPlatform.IOS)
            {
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-cognito-identity.a"));
            }
        }
    }
}