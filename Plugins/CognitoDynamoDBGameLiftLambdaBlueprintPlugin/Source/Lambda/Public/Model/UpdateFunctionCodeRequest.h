/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateFunctionCodeRequest.h"

#endif

#include "UpdateFunctionCodeRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFunctionCodeRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
     * Indicate the zip file path. Absolute File Path
    *  <p>The base64-encoded contents of the deployment package. AWS SDK and AWS CLI clients handle the encoding for you.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString zipFile;

    /**
    *  <p>An Amazon S3 bucket in the same AWS Region as your function. The bucket can be in a different AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Bucket;

    /**
    *  <p>The Amazon S3 key of the deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Key;

    /**
    *  <p>For versioned objects, the version of the deployment package object to use.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3ObjectVersion;

    /**
    *  <p>URI of a container image in the Amazon ECR registry.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString imageUri;

    /**
    *  <p>Set to true to publish a new version of the function after updating the code. This has the same effect as calling <a>PublishVersion</a> separately.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool publish;

    /**
    *  <p>Set to true to validate the request parameters and access permissions without modifying the function code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool dryRun;

    /**
    *  <p>Only update the function if the revision ID matches the ID that's specified. Use this option to avoid modifying a function that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateFunctionCodeRequest toAWS() const {
        Aws::Lambda::Model::UpdateFunctionCodeRequest awsUpdateFunctionCodeRequest;

		if (!(this->functionName.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile)) {
            IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

            IFileHandle* FileHandle = PlatformFile.OpenRead(*this->zipFile);
            if(FileHandle) {
                uint8* ByteBuffer = (uint8*)FMemory::Malloc(FPlatformFileManager::Get().GetPlatformFile().FileSize(*this->zipFile));

                FileHandle->Read(ByteBuffer, sizeof(ByteBuffer));

                awsUpdateFunctionCodeRequest.SetZipFile(Aws::Utils::CryptoBuffer(Aws::Utils::ByteBuffer(ByteBuffer, sizeof(ByteBuffer))));

                delete FileHandle;
                FMemory::Free(ByteBuffer);
            }
        }

		if (!(this->s3Bucket.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3Bucket(TCHAR_TO_UTF8(*this->s3Bucket));
        }

		if (!(this->s3Key.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3Key(TCHAR_TO_UTF8(*this->s3Key));
        }

		if (!(this->s3ObjectVersion.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3ObjectVersion(TCHAR_TO_UTF8(*this->s3ObjectVersion));
        }

		if (!(this->imageUri.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetImageUri(TCHAR_TO_UTF8(*this->imageUri));
        }

		awsUpdateFunctionCodeRequest.SetPublish(this->publish);

		awsUpdateFunctionCodeRequest.SetDryRun(this->dryRun);

		if (!(this->revisionId.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        return awsUpdateFunctionCodeRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && !FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile) && this->s3Bucket.IsEmpty() && this->s3Key.IsEmpty() && this->s3ObjectVersion.IsEmpty() && this->imageUri.IsEmpty() && false && false && this->revisionId.IsEmpty();
    }
#endif
};
