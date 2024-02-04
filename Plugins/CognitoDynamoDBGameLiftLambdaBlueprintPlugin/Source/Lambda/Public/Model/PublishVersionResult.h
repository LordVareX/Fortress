/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/PublishVersionResult.h"

#endif

#include "Model/Runtime.h"
#include "Model/VpcConfigResponse.h"
#include "Model/DeadLetterConfig.h"
#include "Model/EnvironmentResponse.h"
#include "Model/TracingConfigResponse.h"
#include "Model/AWSLayer.h"
#include "Model/State.h"
#include "Model/StateReasonCode.h"
#include "Model/LastUpdateStatus.h"
#include "Model/LastUpdateStatusReasonCode.h"
#include "Model/FileSystemConfig.h"
#include "Model/AWSLambdaPackageType.h"
#include "Model/AWSLambdaImageConfigResponse.h"

#include "PublishVersionResult.generated.h"

USTRUCT(BlueprintType)
struct FPublishVersionResult {
GENERATED_BODY()

    /**
    *  <p>The name of the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The function's Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

    /**
    *  <p>The runtime environment for the Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSRuntime runtime;

    /**
    *  <p>The function's execution role.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString role;

    /**
    *  <p>The function that Lambda calls to begin executing your function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString handler;

    /**
    *  <p>The size of the function's deployment package, in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int64 codeSize;

    /**
    *  <p>The function's description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString description;

    /**
    *  <p>The amount of time in seconds that Lambda allows a function to run before stopping it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int timeout;

    /**
    *  <p>The amount of memory available to the function at runtime. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int memorySize;

    /**
    *  <p>The date and time that the function was last updated, in <a href="https://www.w3.org/TR/NOTE-datetime">ISO-8601 format</a> (YYYY-MM-DDThh:mm:ss.sTZD).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastModified;

    /**
    *  <p>The SHA256 hash of the function's deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString codeSha256;

    /**
    *  <p>The version of the Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString version;

    /**
    *  <p>The function's networking configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FVpcConfigResponse vpcConfig;

    /**
    *  <p>The function's dead letter queue.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDeadLetterConfig deadLetterConfig;

    /**
    *  <p>The function's environment variables.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FEnvironmentResponse environment;

    /**
    *  <p>The KMS key that's used to encrypt the function's environment variables. This key is only returned if you've configured a customer managed CMK.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString kMSKeyArn;

    /**
    *  <p>The function's AWS X-Ray tracing configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FTracingConfigResponse tracingConfig;

    /**
    *  <p>For Lambda@Edge functions, the ARN of the master function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString masterArn;

    /**
    *  <p>The latest updated revision of the function or alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

    /**
    *  <p>The function's <a href="https://docs.aws.amazon.com/lambda/latest/dg/configuration-layers.html"> layers</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLayer> layers;

    /**
    *  <p>The current state of the function. When the state is <code>Inactive</code>, you can reactivate the function by invoking it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSState state;

    /**
    *  <p>The reason for the function's current state.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString stateReason;

    /**
    *  <p>The reason code for the function's current state. When the code is <code>Creating</code>, you can't invoke or modify the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSStateReasonCode stateReasonCode;

    /**
    *  <p>The status of the last update that was performed on the function. This is first set to <code>Successful</code> after function creation completes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLastUpdateStatus lastUpdateStatus;

    /**
    *  <p>The reason for the last update that was performed on the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastUpdateStatusReason;

    /**
    *  <p>The reason code for the last update that was performed on the function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLastUpdateStatusReasonCode lastUpdateStatusReasonCode;

    /**
    *  <p>Connection settings for an Amazon EFS file system.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FFileSystemConfig> fileSystemConfigs;

    /**
    *  <p>The type of deployment package. Set to <code>Image</code> for container image and set <code>Zip</code> for .zip file archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    EAWSLambdaPackageType packageType;

    /**
    *  <p>The function's image configuration values.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaImageConfigResponse imageConfigResponse;

    /**
    *  <p>The ARN of the signing profile version.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString signingProfileVersionArn;

    /**
    *  <p>The ARN of the signing job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString signingJobArn;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FPublishVersionResult &fromAWS(const Aws::Lambda::Model::PublishVersionResult &awsPublishVersionResult) {
        this->functionName = UTF8_TO_TCHAR(awsPublishVersionResult.GetFunctionName().c_str());

        this->functionArn = UTF8_TO_TCHAR(awsPublishVersionResult.GetFunctionArn().c_str());

        switch(awsPublishVersionResult.GetRuntime()) {
            case Aws::Lambda::Model::Runtime::NOT_SET:
                this->runtime = EAWSRuntime::NOT_SET;
                break;
            case Aws::Lambda::Model::Runtime::nodejs:
                this->runtime = EAWSRuntime::nodejs;
                break;
            case Aws::Lambda::Model::Runtime::nodejs4_3:
                this->runtime = EAWSRuntime::nodejs4_3;
                break;
            case Aws::Lambda::Model::Runtime::nodejs6_10:
                this->runtime = EAWSRuntime::nodejs6_10;
                break;
            case Aws::Lambda::Model::Runtime::nodejs8_10:
                this->runtime = EAWSRuntime::nodejs8_10;
                break;
            case Aws::Lambda::Model::Runtime::nodejs10_x:
                this->runtime = EAWSRuntime::nodejs10_x;
                break;
            case Aws::Lambda::Model::Runtime::nodejs12_x:
                this->runtime = EAWSRuntime::nodejs12_x;
                break;
            case Aws::Lambda::Model::Runtime::nodejs14_x:
                this->runtime = EAWSRuntime::nodejs14_x;
                break;
            case Aws::Lambda::Model::Runtime::java8:
                this->runtime = EAWSRuntime::java8;
                break;
            case Aws::Lambda::Model::Runtime::java8_al2:
                this->runtime = EAWSRuntime::java8_al2;
                break;
            case Aws::Lambda::Model::Runtime::java11:
                this->runtime = EAWSRuntime::java11;
                break;
            case Aws::Lambda::Model::Runtime::python2_7:
                this->runtime = EAWSRuntime::python2_7;
                break;
            case Aws::Lambda::Model::Runtime::python3_6:
                this->runtime = EAWSRuntime::python3_6;
                break;
            case Aws::Lambda::Model::Runtime::python3_7:
                this->runtime = EAWSRuntime::python3_7;
                break;
            case Aws::Lambda::Model::Runtime::python3_8:
                this->runtime = EAWSRuntime::python3_8;
                break;
            case Aws::Lambda::Model::Runtime::dotnetcore1_0:
                this->runtime = EAWSRuntime::dotnetcore1_0;
                break;
            case Aws::Lambda::Model::Runtime::dotnetcore2_0:
                this->runtime = EAWSRuntime::dotnetcore2_0;
                break;
            case Aws::Lambda::Model::Runtime::dotnetcore2_1:
                this->runtime = EAWSRuntime::dotnetcore2_1;
                break;
            case Aws::Lambda::Model::Runtime::dotnetcore3_1:
                this->runtime = EAWSRuntime::dotnetcore3_1;
                break;
            case Aws::Lambda::Model::Runtime::nodejs4_3_edge:
                this->runtime = EAWSRuntime::nodejs4_3_edge;
                break;
            case Aws::Lambda::Model::Runtime::go1_x:
                this->runtime = EAWSRuntime::go1_x;
                break;
            case Aws::Lambda::Model::Runtime::ruby2_5:
                this->runtime = EAWSRuntime::ruby2_5;
                break;
            case Aws::Lambda::Model::Runtime::ruby2_7:
                this->runtime = EAWSRuntime::ruby2_7;
                break;
            case Aws::Lambda::Model::Runtime::provided:
                this->runtime = EAWSRuntime::provided;
                break;
            case Aws::Lambda::Model::Runtime::provided_al2:
                this->runtime = EAWSRuntime::provided_al2;
                break;
            default:
                this->runtime = EAWSRuntime::NOT_SET;
                break;
        }

        this->role = UTF8_TO_TCHAR(awsPublishVersionResult.GetRole().c_str());

        this->handler = UTF8_TO_TCHAR(awsPublishVersionResult.GetHandler().c_str());

        this->codeSize = (int64)awsPublishVersionResult.GetCodeSize();

        this->description = UTF8_TO_TCHAR(awsPublishVersionResult.GetDescription().c_str());

		this->timeout = awsPublishVersionResult.GetTimeout();

		this->memorySize = awsPublishVersionResult.GetMemorySize();

        this->lastModified = UTF8_TO_TCHAR(awsPublishVersionResult.GetLastModified().c_str());

        this->codeSha256 = UTF8_TO_TCHAR(awsPublishVersionResult.GetCodeSha256().c_str());

        this->version = UTF8_TO_TCHAR(awsPublishVersionResult.GetVersion().c_str());

        this->vpcConfig.fromAWS(awsPublishVersionResult.GetVpcConfig());

        this->deadLetterConfig.fromAWS(awsPublishVersionResult.GetDeadLetterConfig());

        this->environment.fromAWS(awsPublishVersionResult.GetEnvironment());

        this->kMSKeyArn = UTF8_TO_TCHAR(awsPublishVersionResult.GetKMSKeyArn().c_str());

        this->tracingConfig.fromAWS(awsPublishVersionResult.GetTracingConfig());

        this->masterArn = UTF8_TO_TCHAR(awsPublishVersionResult.GetMasterArn().c_str());

        this->revisionId = UTF8_TO_TCHAR(awsPublishVersionResult.GetRevisionId().c_str());

        this->layers.Empty();
        for (const Aws::Lambda::Model::Layer& elem : awsPublishVersionResult.GetLayers()) {
            this->layers.Add(FAWSLayer().fromAWS(elem));
        }

        switch(awsPublishVersionResult.GetState()) {
            case Aws::Lambda::Model::State::NOT_SET:
                this->state = EAWSState::NOT_SET;
                break;
            case Aws::Lambda::Model::State::Pending:
                this->state = EAWSState::Pending;
                break;
            case Aws::Lambda::Model::State::Active:
                this->state = EAWSState::Active;
                break;
            case Aws::Lambda::Model::State::Inactive:
                this->state = EAWSState::Inactive;
                break;
            case Aws::Lambda::Model::State::Failed:
                this->state = EAWSState::Failed;
                break;
            default:
                this->state = EAWSState::NOT_SET;
                break;
        }

        this->stateReason = UTF8_TO_TCHAR(awsPublishVersionResult.GetStateReason().c_str());

        switch(awsPublishVersionResult.GetStateReasonCode()) {
            case Aws::Lambda::Model::StateReasonCode::NOT_SET:
                this->stateReasonCode = EAWSStateReasonCode::NOT_SET;
                break;
            case Aws::Lambda::Model::StateReasonCode::Idle:
                this->stateReasonCode = EAWSStateReasonCode::Idle;
                break;
            case Aws::Lambda::Model::StateReasonCode::Creating:
                this->stateReasonCode = EAWSStateReasonCode::Creating;
                break;
            case Aws::Lambda::Model::StateReasonCode::Restoring:
                this->stateReasonCode = EAWSStateReasonCode::Restoring;
                break;
            case Aws::Lambda::Model::StateReasonCode::EniLimitExceeded:
                this->stateReasonCode = EAWSStateReasonCode::EniLimitExceeded;
                break;
            case Aws::Lambda::Model::StateReasonCode::InsufficientRolePermissions:
                this->stateReasonCode = EAWSStateReasonCode::InsufficientRolePermissions;
                break;
            case Aws::Lambda::Model::StateReasonCode::InvalidConfiguration:
                this->stateReasonCode = EAWSStateReasonCode::InvalidConfiguration;
                break;
            case Aws::Lambda::Model::StateReasonCode::InternalError:
                this->stateReasonCode = EAWSStateReasonCode::InternalError;
                break;
            case Aws::Lambda::Model::StateReasonCode::SubnetOutOfIPAddresses:
                this->stateReasonCode = EAWSStateReasonCode::SubnetOutOfIPAddresses;
                break;
            case Aws::Lambda::Model::StateReasonCode::InvalidSubnet:
                this->stateReasonCode = EAWSStateReasonCode::InvalidSubnet;
                break;
            case Aws::Lambda::Model::StateReasonCode::InvalidSecurityGroup:
                this->stateReasonCode = EAWSStateReasonCode::InvalidSecurityGroup;
                break;
            case Aws::Lambda::Model::StateReasonCode::ImageDeleted:
                this->stateReasonCode = EAWSStateReasonCode::ImageDeleted;
                break;
            case Aws::Lambda::Model::StateReasonCode::ImageAccessDenied:
                this->stateReasonCode = EAWSStateReasonCode::ImageAccessDenied;
                break;
            case Aws::Lambda::Model::StateReasonCode::InvalidImage:
                this->stateReasonCode = EAWSStateReasonCode::InvalidImage;
                break;
            default:
                this->stateReasonCode = EAWSStateReasonCode::NOT_SET;
                break;
        }

        switch(awsPublishVersionResult.GetLastUpdateStatus()) {
            case Aws::Lambda::Model::LastUpdateStatus::NOT_SET:
                this->lastUpdateStatus = EAWSLastUpdateStatus::NOT_SET;
                break;
            case Aws::Lambda::Model::LastUpdateStatus::Successful:
                this->lastUpdateStatus = EAWSLastUpdateStatus::Successful;
                break;
            case Aws::Lambda::Model::LastUpdateStatus::Failed:
                this->lastUpdateStatus = EAWSLastUpdateStatus::Failed;
                break;
            case Aws::Lambda::Model::LastUpdateStatus::InProgress:
                this->lastUpdateStatus = EAWSLastUpdateStatus::InProgress;
                break;
            default:
                this->lastUpdateStatus = EAWSLastUpdateStatus::NOT_SET;
                break;
        }

        this->lastUpdateStatusReason = UTF8_TO_TCHAR(awsPublishVersionResult.GetLastUpdateStatusReason().c_str());

        switch(awsPublishVersionResult.GetLastUpdateStatusReasonCode()) {
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::NOT_SET:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::NOT_SET;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::EniLimitExceeded:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::EniLimitExceeded;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InsufficientRolePermissions:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InsufficientRolePermissions;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InvalidConfiguration:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InvalidConfiguration;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InternalError:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InternalError;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::SubnetOutOfIPAddresses:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::SubnetOutOfIPAddresses;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InvalidSubnet:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InvalidSubnet;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InvalidSecurityGroup:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InvalidSecurityGroup;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::ImageDeleted:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::ImageDeleted;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::ImageAccessDenied:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::ImageAccessDenied;
                break;
            case Aws::Lambda::Model::LastUpdateStatusReasonCode::InvalidImage:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::InvalidImage;
                break;
            default:
                this->lastUpdateStatusReasonCode = EAWSLastUpdateStatusReasonCode::NOT_SET;
                break;
        }

        this->fileSystemConfigs.Empty();
        for (const Aws::Lambda::Model::FileSystemConfig& elem : awsPublishVersionResult.GetFileSystemConfigs()) {
            this->fileSystemConfigs.Add(FFileSystemConfig().fromAWS(elem));
        }

        switch(awsPublishVersionResult.GetPackageType()) {
            case Aws::Lambda::Model::PackageType::NOT_SET:
                this->packageType = EAWSLambdaPackageType::NOT_SET;
                break;
            case Aws::Lambda::Model::PackageType::Zip:
                this->packageType = EAWSLambdaPackageType::Zip;
                break;
            case Aws::Lambda::Model::PackageType::Image:
                this->packageType = EAWSLambdaPackageType::Image;
                break;
            default:
                this->packageType = EAWSLambdaPackageType::NOT_SET;
                break;
        }

        this->imageConfigResponse = FAWSLambdaImageConfigResponse().fromAWS(awsPublishVersionResult.GetImageConfigResponse());

        this->signingProfileVersionArn = UTF8_TO_TCHAR(awsPublishVersionResult.GetSigningProfileVersionArn().c_str());

        this->signingJobArn = UTF8_TO_TCHAR(awsPublishVersionResult.GetSigningJobArn().c_str());

        return *this;
    }
#endif
};
