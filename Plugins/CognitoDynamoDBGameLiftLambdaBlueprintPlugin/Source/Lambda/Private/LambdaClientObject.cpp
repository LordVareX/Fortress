/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "LambdaClientObject.h"
#include "LambdaGlobals.h"
#include "LambdaPrivatePCH.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_LAMBDACLIENTSDK

ELambdaError fromAWS(Aws::Lambda::LambdaErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::Lambda::LambdaErrors::INCOMPLETE_SIGNATURE:
            return ELambdaError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::INTERNAL_FAILURE:
            return ELambdaError::INTERNAL_FAILURE;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ACTION:
            return ELambdaError::INVALID_ACTION;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_CLIENT_TOKEN_ID:
            return ELambdaError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_PARAMETER_COMBINATION:
            return ELambdaError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_QUERY_PARAMETER:
            return ELambdaError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_PARAMETER_VALUE:
            return ELambdaError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_ACTION:
            return ELambdaError::MISSING_ACTION;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_AUTHENTICATION_TOKEN:
            return ELambdaError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_PARAMETER:
            return ELambdaError::MISSING_PARAMETER;
            break;
        case Aws::Lambda::LambdaErrors::OPT_IN_REQUIRED:
            return ELambdaError::OPT_IN_REQUIRED;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_EXPIRED:
            return ELambdaError::REQUEST_EXPIRED;
            break;
        case Aws::Lambda::LambdaErrors::SERVICE_UNAVAILABLE:
            return ELambdaError::SERVICE_UNAVAILABLE;
            break;
        case Aws::Lambda::LambdaErrors::THROTTLING:
            return ELambdaError::THROTTLING;
            break;
        case Aws::Lambda::LambdaErrors::VALIDATION:
            return ELambdaError::VALIDATION;
            break;
        case Aws::Lambda::LambdaErrors::ACCESS_DENIED:
            return ELambdaError::ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_NOT_FOUND:
            return ELambdaError::RESOURCE_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::UNRECOGNIZED_CLIENT:
            return ELambdaError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::Lambda::LambdaErrors::MALFORMED_QUERY_STRING:
            return ELambdaError::MALFORMED_QUERY_STRING;
            break;
        case Aws::Lambda::LambdaErrors::SLOW_DOWN:
            return ELambdaError::SLOW_DOWN;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TIME_TOO_SKEWED:
            return ELambdaError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SIGNATURE:
            return ELambdaError::INVALID_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::SIGNATURE_DOES_NOT_MATCH:
            return ELambdaError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ACCESS_KEY_ID:
            return ELambdaError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TIMEOUT:
            return ELambdaError::REQUEST_TIMEOUT;
            break;
        case Aws::Lambda::LambdaErrors::NETWORK_CONNECTION:
            return ELambdaError::NETWORK_CONNECTION;
            break;
        case Aws::Lambda::LambdaErrors::UNKNOWN:
            return ELambdaError::UNKNOWN;
            break;
        case Aws::Lambda::LambdaErrors::CODE_SIGNING_CONFIG_NOT_FOUND:
            return ELambdaError::CODE_SIGNING_CONFIG_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::CODE_STORAGE_EXCEEDED:
            return ELambdaError::CODE_STORAGE_EXCEEDED;
            break;
        case Aws::Lambda::LambdaErrors::CODE_VERIFICATION_FAILED:
            return ELambdaError::CODE_VERIFICATION_FAILED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_ACCESS_DENIED:
            return ELambdaError::EC2_ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_THROTTLED:
            return ELambdaError::EC2_THROTTLED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_UNEXPECTED:
            return ELambdaError::EC2_UNEXPECTED;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_I_O:
            return ELambdaError::EFS_IO;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_CONNECTIVITY:
            return ELambdaError::EFS_MOUNT_CONNECTIVITY;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_FAILURE:
            return ELambdaError::EFS_MOUNT_FAILURE;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_TIMEOUT:
            return ELambdaError::EFS_MOUNT_TIMEOUT;
            break;
        case Aws::Lambda::LambdaErrors::E_N_I_LIMIT_REACHED:
            return ELambdaError::ENI_LIMIT_REACHED;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_CODE_SIGNATURE:
            return ELambdaError::INVALID_CODE_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_REQUEST_CONTENT:
            return ELambdaError::INVALID_REQUEST_CONTENT;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_RUNTIME:
            return ELambdaError::INVALID_RUNTIME;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SECURITY_GROUP_I_D:
            return ELambdaError::INVALID_SECURITY_GROUP_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SUBNET_I_D:
            return ELambdaError::INVALID_SUBNET_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ZIP_FILE:
            return ELambdaError::INVALID_ZIP_FILE;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_ACCESS_DENIED:
            return ELambdaError::KMS_ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_DISABLED:
            return ELambdaError::KMS_DISABLED;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_INVALID_STATE:
            return ELambdaError::KMS_INVALID_STATE;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_NOT_FOUND:
            return ELambdaError::KMS_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::POLICY_LENGTH_EXCEEDED:
            return ELambdaError::POLICY_LENGTH_EXCEEDED;
            break;
        case Aws::Lambda::LambdaErrors::PRECONDITION_FAILED:
            return ELambdaError::PRECONDITION_FAILED;
            break;
        case Aws::Lambda::LambdaErrors::PROVISIONED_CONCURRENCY_CONFIG_NOT_FOUND:
            return ELambdaError::PROVISIONED_CONCURRENCY_CONFIG_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TOO_LARGE:
            return ELambdaError::REQUEST_TOO_LARGE;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_CONFLICT:
            return ELambdaError::RESOURCE_CONFLICT;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_IN_USE:
            return ELambdaError::RESOURCE_IN_USE;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_NOT_READY:
            return ELambdaError::RESOURCE_NOT_READY;
            break;
        case Aws::Lambda::LambdaErrors::SERVICE:
            return ELambdaError::SERVICE;
            break;
        case Aws::Lambda::LambdaErrors::SUBNET_I_P_ADDRESS_LIMIT_REACHED:
            return ELambdaError::SUBNET_IP_ADDRESS_LIMIT_REACHED;
            break;
        case Aws::Lambda::LambdaErrors::TOO_MANY_REQUESTS:
            return ELambdaError::TOO_MANY_REQUESTS;
            break;
        case Aws::Lambda::LambdaErrors::UNSUPPORTED_MEDIA_TYPE:
            return ELambdaError::UNSUPPORTED_MEDIA_TYPE;
            break;
        default:
            return ELambdaError::UNKNOWN;
            break;
    }
}

#endif

ULambdaClientObject *ULambdaClientObject::CreateLambdaObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    ULambdaClientObject *LambdaClient = NewObject<ULambdaClientObject>();
    LambdaClient->awsLambdaClient = new Aws::Lambda::LambdaClient(credentials.toAWS(),
    clientConfiguration.toAWS());
    return LambdaClient;
#endif
    return nullptr;
}

#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FAddLayerVersionPermissionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAddLayerVersionPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest,
        FAddLayerVersionPermissionResult &addLayerVersionPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), addLayerVersionPermissionRequest(addLayerVersionPermissionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->AddLayerVersionPermissionAsync(
            addLayerVersionPermissionRequest.toAWS(),
            [&success, &addLayerVersionPermissionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::AddLayerVersionPermissionRequest &awsAddLayerVersionPermissionRequest,
                const Aws::Lambda::Model::AddLayerVersionPermissionOutcome &awsAddLayerVersionPermissionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAddLayerVersionPermissionOutcome.IsSuccess();
                if (success) {
                    addLayerVersionPermissionResult.fromAWS(awsAddLayerVersionPermissionOutcome.GetResult());
                }

                errorType = fromAWS(awsAddLayerVersionPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("AddLayerVersionPermission error: " + awsAddLayerVersionPermissionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddLayerVersionPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::AddLayerVersionPermission(
        UObject *WorldContextObject,
        bool &success,
        FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest,
        FAddLayerVersionPermissionResult &addLayerVersionPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddLayerVersionPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddLayerVersionPermissionAction(this->awsLambdaClient,
                success,
                addLayerVersionPermissionRequest,
                addLayerVersionPermissionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FAddPermissionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAddPermissionRequest addPermissionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAddPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAddPermissionRequest addPermissionRequest,
        FAddPermissionResult &addPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), addPermissionRequest(addPermissionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->AddPermissionAsync(
            addPermissionRequest.toAWS(),
            [&success, &addPermissionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::AddPermissionRequest &awsAddPermissionRequest,
                const Aws::Lambda::Model::AddPermissionOutcome &awsAddPermissionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAddPermissionOutcome.IsSuccess();
                if (success) {
                    addPermissionResult.fromAWS(awsAddPermissionOutcome.GetResult());
                }

                errorType = fromAWS(awsAddPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("AddPermission error: " + awsAddPermissionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::AddPermission(
        UObject *WorldContextObject,
        bool &success,
        FAddPermissionRequest addPermissionRequest,
        FAddPermissionResult &addPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddPermissionAction(this->awsLambdaClient,
                success,
                addPermissionRequest,
                addPermissionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateAliasAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaCreateAliasRequest createAliasRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaCreateAliasRequest createAliasRequest,
        FLambdaCreateAliasResult &createAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), createAliasRequest(createAliasRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->CreateAliasAsync(
            createAliasRequest.toAWS(),
            [&success, &createAliasResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::CreateAliasRequest &awsCreateAliasRequest,
                const Aws::Lambda::Model::CreateAliasOutcome &awsCreateAliasOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateAliasOutcome.IsSuccess();
                if (success) {
                    createAliasResult.fromAWS(awsCreateAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateAliasOutcome.GetError().GetErrorType());
                errorMessage = ("CreateAlias error: " + awsCreateAliasOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateAlias Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaCreateAliasRequest createAliasRequest,
        FLambdaCreateAliasResult &createAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateAliasAction(this->awsLambdaClient,
                success,
                createAliasRequest,
                createAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest,
        FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), createCodeSigningConfigRequest(createCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->CreateCodeSigningConfigAsync(
            createCodeSigningConfigRequest.toAWS(),
            [&success, &createCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::CreateCodeSigningConfigRequest &awsCreateCodeSigningConfigRequest,
                const Aws::Lambda::Model::CreateCodeSigningConfigOutcome &awsCreateCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    createCodeSigningConfigResult.fromAWS(awsCreateCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("CreateCodeSigningConfig error: " + awsCreateCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest,
    FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateCodeSigningConfigAction(this->awsLambdaClient,
                success,
                createCodeSigningConfigRequest,
                createCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateEventSourceMappingAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FCreateEventSourceMappingRequest createEventSourceMappingRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FCreateEventSourceMappingRequest createEventSourceMappingRequest,
        FCreateEventSourceMappingResult &createEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), createEventSourceMappingRequest(createEventSourceMappingRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->CreateEventSourceMappingAsync(
            createEventSourceMappingRequest.toAWS(),
            [&success, &createEventSourceMappingResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::CreateEventSourceMappingRequest &awsCreateEventSourceMappingRequest,
                const Aws::Lambda::Model::CreateEventSourceMappingOutcome &awsCreateEventSourceMappingOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    createEventSourceMappingResult.fromAWS(awsCreateEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("CreateEventSourceMapping error: " + awsCreateEventSourceMappingOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FCreateEventSourceMappingRequest createEventSourceMappingRequest,
        FCreateEventSourceMappingResult &createEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateEventSourceMappingAction(this->awsLambdaClient,
                success,
                createEventSourceMappingRequest,
                createEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateFunctionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FCreateFunctionRequest createFunctionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FCreateFunctionRequest createFunctionRequest,
        FCreateFunctionResult &createFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), createFunctionRequest(createFunctionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->CreateFunctionAsync(
            createFunctionRequest.toAWS(),
            [&success, &createFunctionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::CreateFunctionRequest &awsCreateFunctionRequest,
                const Aws::Lambda::Model::CreateFunctionOutcome &awsCreateFunctionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateFunctionOutcome.IsSuccess();
                if (success) {
                    createFunctionResult.fromAWS(awsCreateFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("CreateFunction error: " + awsCreateFunctionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateFunction(
        UObject *WorldContextObject,
        bool &success,
        FCreateFunctionRequest createFunctionRequest,
        FCreateFunctionResult &createFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateFunctionAction(this->awsLambdaClient,
                success,
                createFunctionRequest,
                createFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteAliasAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaDeleteAliasRequest deleteAliasRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaDeleteAliasRequest deleteAliasRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteAliasRequest(deleteAliasRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteAliasAsync(
            deleteAliasRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteAliasRequest &awsDeleteAliasRequest,
                const Aws::Lambda::Model::DeleteAliasOutcome &awsDeleteAliasOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteAliasOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAliasOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAlias error: " + awsDeleteAliasOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAlias Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaDeleteAliasRequest deleteAliasRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAliasAction(this->awsLambdaClient,
                success,
                deleteAliasRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest,
        FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteCodeSigningConfigRequest(deleteCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteCodeSigningConfigAsync(
            deleteCodeSigningConfigRequest.toAWS(),
            [&success, &deleteCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteCodeSigningConfigRequest &awsDeleteCodeSigningConfigRequest,
                const Aws::Lambda::Model::DeleteCodeSigningConfigOutcome &awsDeleteCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    deleteCodeSigningConfigResult.fromAWS(awsDeleteCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteCodeSigningConfig error: " + awsDeleteCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest,
    FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteCodeSigningConfigAction(this->awsLambdaClient,
                success,
                deleteCodeSigningConfigRequest,
                deleteCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteEventSourceMappingAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest,
        FDeleteEventSourceMappingResult &deleteEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteEventSourceMappingRequest(deleteEventSourceMappingRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteEventSourceMappingAsync(
            deleteEventSourceMappingRequest.toAWS(),
            [&success, &deleteEventSourceMappingResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteEventSourceMappingRequest &awsDeleteEventSourceMappingRequest,
                const Aws::Lambda::Model::DeleteEventSourceMappingOutcome &awsDeleteEventSourceMappingOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    deleteEventSourceMappingResult.fromAWS(awsDeleteEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteEventSourceMapping error: " + awsDeleteEventSourceMappingOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest,
        FDeleteEventSourceMappingResult &deleteEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteEventSourceMappingAction(this->awsLambdaClient,
                success,
                deleteEventSourceMappingRequest,
                deleteEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteFunctionRequest deleteFunctionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionRequest deleteFunctionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteFunctionRequest(deleteFunctionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteFunctionAsync(
            deleteFunctionRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteFunctionRequest &awsDeleteFunctionRequest,
                const Aws::Lambda::Model::DeleteFunctionOutcome &awsDeleteFunctionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteFunctionOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunction error: " + awsDeleteFunctionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunction(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionRequest deleteFunctionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionAction(this->awsLambdaClient,
                success,
                deleteFunctionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteFunctionCodeSigningConfigRequest(deleteFunctionCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteFunctionCodeSigningConfigAsync(
            deleteFunctionCodeSigningConfigRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteFunctionCodeSigningConfigRequest &awsDeleteFunctionCodeSigningConfigRequest,
                const Aws::Lambda::Model::DeleteFunctionCodeSigningConfigOutcome &awsDeleteFunctionCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteFunctionCodeSigningConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionCodeSigningConfig error: " + awsDeleteFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                deleteFunctionCodeSigningConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionConcurrencyAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteFunctionConcurrencyRequest(deleteFunctionConcurrencyRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteFunctionConcurrencyAsync(
            deleteFunctionConcurrencyRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteFunctionConcurrencyRequest &awsDeleteFunctionConcurrencyRequest,
                const Aws::Lambda::Model::DeleteFunctionConcurrencyOutcome &awsDeleteFunctionConcurrencyOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteFunctionConcurrencyOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionConcurrency error: " + awsDeleteFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                deleteFunctionConcurrencyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteFunctionEventInvokeConfigRequest(deleteFunctionEventInvokeConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteFunctionEventInvokeConfigAsync(
            deleteFunctionEventInvokeConfigRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteFunctionEventInvokeConfigRequest &awsDeleteFunctionEventInvokeConfigRequest,
                const Aws::Lambda::Model::DeleteFunctionEventInvokeConfigOutcome &awsDeleteFunctionEventInvokeConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteFunctionEventInvokeConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionEventInvokeConfig error: " + awsDeleteFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                deleteFunctionEventInvokeConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteLayerVersionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteLayerVersionRequest deleteLayerVersionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteLayerVersionRequest deleteLayerVersionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteLayerVersionRequest(deleteLayerVersionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteLayerVersionAsync(
            deleteLayerVersionRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteLayerVersionRequest &awsDeleteLayerVersionRequest,
                const Aws::Lambda::Model::DeleteLayerVersionOutcome &awsDeleteLayerVersionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteLayerVersionOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteLayerVersion error: " + awsDeleteLayerVersionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FDeleteLayerVersionRequest deleteLayerVersionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteLayerVersionAction(this->awsLambdaClient,
                success,
                deleteLayerVersionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), deleteProvisionedConcurrencyConfigRequest(deleteProvisionedConcurrencyConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->DeleteProvisionedConcurrencyConfigAsync(
            deleteProvisionedConcurrencyConfigRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::DeleteProvisionedConcurrencyConfigRequest &awsDeleteProvisionedConcurrencyConfigRequest,
                const Aws::Lambda::Model::DeleteProvisionedConcurrencyConfigOutcome &awsDeleteProvisionedConcurrencyConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteProvisionedConcurrencyConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteProvisionedConcurrencyConfig error: " + awsDeleteProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                deleteProvisionedConcurrencyConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetAccountSettingsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetAccountSettingsRequest getAccountSettingsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetAccountSettingsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetAccountSettingsRequest getAccountSettingsRequest,
        FGetAccountSettingsResult &getAccountSettingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getAccountSettingsRequest(getAccountSettingsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetAccountSettingsAsync(
            getAccountSettingsRequest.toAWS(),
            [&success, &getAccountSettingsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetAccountSettingsRequest &awsGetAccountSettingsRequest,
                const Aws::Lambda::Model::GetAccountSettingsOutcome &awsGetAccountSettingsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetAccountSettingsOutcome.IsSuccess();
                if (success) {
                    getAccountSettingsResult.fromAWS(awsGetAccountSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccountSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccountSettings error: " + awsGetAccountSettingsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccountSettings Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetAccountSettings(
        UObject *WorldContextObject,
        bool &success,
        FGetAccountSettingsRequest getAccountSettingsRequest,
        FGetAccountSettingsResult &getAccountSettingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccountSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccountSettingsAction(this->awsLambdaClient,
                success,
                getAccountSettingsRequest,
                getAccountSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetAliasAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetAliasRequest getAliasRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetAliasRequest getAliasRequest,
        FGetAliasResult &getAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getAliasRequest(getAliasRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetAliasAsync(
            getAliasRequest.toAWS(),
            [&success, &getAliasResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetAliasRequest &awsGetAliasRequest,
                const Aws::Lambda::Model::GetAliasOutcome &awsGetAliasOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetAliasOutcome.IsSuccess();
                if (success) {
                    getAliasResult.fromAWS(awsGetAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAliasOutcome.GetError().GetErrorType());
                errorMessage = ("GetAlias error: " + awsGetAliasOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAlias Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetAlias(
        UObject *WorldContextObject,
        bool &success,
        FGetAliasRequest getAliasRequest,
        FGetAliasResult &getAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAliasAction(this->awsLambdaClient,
                success,
                getAliasRequest,
                getAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest,
        FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getCodeSigningConfigRequest(getCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetCodeSigningConfigAsync(
            getCodeSigningConfigRequest.toAWS(),
            [&success, &getCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetCodeSigningConfigRequest &awsGetCodeSigningConfigRequest,
                const Aws::Lambda::Model::GetCodeSigningConfigOutcome &awsGetCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    getCodeSigningConfigResult.fromAWS(awsGetCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetCodeSigningConfig error: " + awsGetCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest,
    FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCodeSigningConfigAction(this->awsLambdaClient,
                success,
                getCodeSigningConfigRequest,
                getCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetEventSourceMappingAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetEventSourceMappingRequest getEventSourceMappingRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetEventSourceMappingRequest getEventSourceMappingRequest,
        FGetEventSourceMappingResult &getEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getEventSourceMappingRequest(getEventSourceMappingRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetEventSourceMappingAsync(
            getEventSourceMappingRequest.toAWS(),
            [&success, &getEventSourceMappingResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetEventSourceMappingRequest &awsGetEventSourceMappingRequest,
                const Aws::Lambda::Model::GetEventSourceMappingOutcome &awsGetEventSourceMappingOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    getEventSourceMappingResult.fromAWS(awsGetEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("GetEventSourceMapping error: " + awsGetEventSourceMappingOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FGetEventSourceMappingRequest getEventSourceMappingRequest,
        FGetEventSourceMappingResult &getEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetEventSourceMappingAction(this->awsLambdaClient,
                success,
                getEventSourceMappingRequest,
                getEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetFunctionRequest getFunctionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionRequest getFunctionRequest,
        FGetFunctionResult &getFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getFunctionRequest(getFunctionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetFunctionAsync(
            getFunctionRequest.toAWS(),
            [&success, &getFunctionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetFunctionRequest &awsGetFunctionRequest,
                const Aws::Lambda::Model::GetFunctionOutcome &awsGetFunctionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetFunctionOutcome.IsSuccess();
                if (success) {
                    getFunctionResult.fromAWS(awsGetFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunction error: " + awsGetFunctionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunction(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionRequest getFunctionRequest,
        FGetFunctionResult &getFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionAction(this->awsLambdaClient,
                success,
                getFunctionRequest,
                getFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest,
        FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getFunctionCodeSigningConfigRequest(getFunctionCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetFunctionCodeSigningConfigAsync(
            getFunctionCodeSigningConfigRequest.toAWS(),
            [&success, &getFunctionCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetFunctionCodeSigningConfigRequest &awsGetFunctionCodeSigningConfigRequest,
                const Aws::Lambda::Model::GetFunctionCodeSigningConfigOutcome &awsGetFunctionCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetFunctionCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    getFunctionCodeSigningConfigResult.fromAWS(awsGetFunctionCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionCodeSigningConfig error: " + awsGetFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest,
    FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                getFunctionCodeSigningConfigRequest,
                getFunctionCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionConcurrencyAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest,
        FGetFunctionConcurrencyResult &getFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getFunctionConcurrencyRequest(getFunctionConcurrencyRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetFunctionConcurrencyAsync(
            getFunctionConcurrencyRequest.toAWS(),
            [&success, &getFunctionConcurrencyResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetFunctionConcurrencyRequest &awsGetFunctionConcurrencyRequest,
                const Aws::Lambda::Model::GetFunctionConcurrencyOutcome &awsGetFunctionConcurrencyOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetFunctionConcurrencyOutcome.IsSuccess();
                if (success) {
                    getFunctionConcurrencyResult.fromAWS(awsGetFunctionConcurrencyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionConcurrency error: " + awsGetFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest,
        FGetFunctionConcurrencyResult &getFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                getFunctionConcurrencyRequest,
                getFunctionConcurrencyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionConfigurationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetFunctionConfigurationRequest getFunctionConfigurationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetFunctionConfigurationAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionConfigurationRequest getFunctionConfigurationRequest,
        FGetFunctionConfigurationResult &getFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getFunctionConfigurationRequest(getFunctionConfigurationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetFunctionConfigurationAsync(
            getFunctionConfigurationRequest.toAWS(),
            [&success, &getFunctionConfigurationResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetFunctionConfigurationRequest &awsGetFunctionConfigurationRequest,
                const Aws::Lambda::Model::GetFunctionConfigurationOutcome &awsGetFunctionConfigurationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetFunctionConfigurationOutcome.IsSuccess();
                if (success) {
                    getFunctionConfigurationResult.fromAWS(awsGetFunctionConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionConfiguration error: " + awsGetFunctionConfigurationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionConfiguration Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConfigurationRequest getFunctionConfigurationRequest,
        FGetFunctionConfigurationResult &getFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionConfigurationAction(this->awsLambdaClient,
                success,
                getFunctionConfigurationRequest,
                getFunctionConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest,
        FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getFunctionEventInvokeConfigRequest(getFunctionEventInvokeConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetFunctionEventInvokeConfigAsync(
            getFunctionEventInvokeConfigRequest.toAWS(),
            [&success, &getFunctionEventInvokeConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetFunctionEventInvokeConfigRequest &awsGetFunctionEventInvokeConfigRequest,
                const Aws::Lambda::Model::GetFunctionEventInvokeConfigOutcome &awsGetFunctionEventInvokeConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    getFunctionEventInvokeConfigResult.fromAWS(awsGetFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionEventInvokeConfig error: " + awsGetFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest,
        FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                getFunctionEventInvokeConfigRequest,
                getFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetLayerVersionRequest getLayerVersionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionRequest getLayerVersionRequest,
        FGetLayerVersionResult &getLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getLayerVersionRequest(getLayerVersionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetLayerVersionAsync(
            getLayerVersionRequest.toAWS(),
            [&success, &getLayerVersionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetLayerVersionRequest &awsGetLayerVersionRequest,
                const Aws::Lambda::Model::GetLayerVersionOutcome &awsGetLayerVersionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetLayerVersionOutcome.IsSuccess();
                if (success) {
                    getLayerVersionResult.fromAWS(awsGetLayerVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersion error: " + awsGetLayerVersionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionRequest getLayerVersionRequest,
        FGetLayerVersionResult &getLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionAction(this->awsLambdaClient,
                success,
                getLayerVersionRequest,
                getLayerVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionByArnAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetLayerVersionByArnRequest getLayerVersionByArnRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetLayerVersionByArnAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionByArnRequest getLayerVersionByArnRequest,
        FGetLayerVersionByArnResult &getLayerVersionByArnResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getLayerVersionByArnRequest(getLayerVersionByArnRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetLayerVersionByArnAsync(
            getLayerVersionByArnRequest.toAWS(),
            [&success, &getLayerVersionByArnResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetLayerVersionByArnRequest &awsGetLayerVersionByArnRequest,
                const Aws::Lambda::Model::GetLayerVersionByArnOutcome &awsGetLayerVersionByArnOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetLayerVersionByArnOutcome.IsSuccess();
                if (success) {
                    getLayerVersionByArnResult.fromAWS(awsGetLayerVersionByArnOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionByArnOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersionByArn error: " + awsGetLayerVersionByArnOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersionByArn Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersionByArn(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionByArnRequest getLayerVersionByArnRequest,
        FGetLayerVersionByArnResult &getLayerVersionByArnResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionByArnAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionByArnAction(this->awsLambdaClient,
                success,
                getLayerVersionByArnRequest,
                getLayerVersionByArnResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionPolicyAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetLayerVersionPolicyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest,
        FGetLayerVersionPolicyResult &getLayerVersionPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getLayerVersionPolicyRequest(getLayerVersionPolicyRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetLayerVersionPolicyAsync(
            getLayerVersionPolicyRequest.toAWS(),
            [&success, &getLayerVersionPolicyResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetLayerVersionPolicyRequest &awsGetLayerVersionPolicyRequest,
                const Aws::Lambda::Model::GetLayerVersionPolicyOutcome &awsGetLayerVersionPolicyOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetLayerVersionPolicyOutcome.IsSuccess();
                if (success) {
                    getLayerVersionPolicyResult.fromAWS(awsGetLayerVersionPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersionPolicy error: " + awsGetLayerVersionPolicyOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersionPolicy Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersionPolicy(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest,
        FGetLayerVersionPolicyResult &getLayerVersionPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionPolicyAction(this->awsLambdaClient,
                success,
                getLayerVersionPolicyRequest,
                getLayerVersionPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetPolicyAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetPolicyRequest getPolicyRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetPolicyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetPolicyRequest getPolicyRequest,
        FGetPolicyResult &getPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getPolicyRequest(getPolicyRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetPolicyAsync(
            getPolicyRequest.toAWS(),
            [&success, &getPolicyResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetPolicyRequest &awsGetPolicyRequest,
                const Aws::Lambda::Model::GetPolicyOutcome &awsGetPolicyOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetPolicyOutcome.IsSuccess();
                if (success) {
                    getPolicyResult.fromAWS(awsGetPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetPolicy error: " + awsGetPolicyOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetPolicy Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetPolicy(
        UObject *WorldContextObject,
        bool &success,
        FGetPolicyRequest getPolicyRequest,
        FGetPolicyResult &getPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPolicyAction(this->awsLambdaClient,
                success,
                getPolicyRequest,
                getPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest,
        FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), getProvisionedConcurrencyConfigRequest(getProvisionedConcurrencyConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->GetProvisionedConcurrencyConfigAsync(
            getProvisionedConcurrencyConfigRequest.toAWS(),
            [&success, &getProvisionedConcurrencyConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::GetProvisionedConcurrencyConfigRequest &awsGetProvisionedConcurrencyConfigRequest,
                const Aws::Lambda::Model::GetProvisionedConcurrencyConfigOutcome &awsGetProvisionedConcurrencyConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetProvisionedConcurrencyConfigOutcome.IsSuccess();
                if (success) {
                    getProvisionedConcurrencyConfigResult.fromAWS(awsGetProvisionedConcurrencyConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetProvisionedConcurrencyConfig error: " + awsGetProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest,
        FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                getProvisionedConcurrencyConfigRequest,
                getProvisionedConcurrencyConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FInvokeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FInvokeRequest invokeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FInvokeAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FInvokeRequest invokeRequest,
        FInvokeResult &invokeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), invokeRequest(invokeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->InvokeAsync(
            invokeRequest.toAWS(),
            [&success, &invokeResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::InvokeRequest &awsInvokeRequest,
                const Aws::Lambda::Model::InvokeOutcome &awsInvokeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsInvokeOutcome.IsSuccess();
                if (success) {
                    invokeResult.fromAWS(awsInvokeOutcome.GetResult());
                }

                errorType = fromAWS(awsInvokeOutcome.GetError().GetErrorType());
                errorMessage = ("Invoke error: " + awsInvokeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Invoke Request");
    }

#endif
};

#endif

void
ULambdaClientObject::Invoke(
        UObject *WorldContextObject,
        bool &success,
        FInvokeRequest invokeRequest,
        FInvokeResult &invokeResult,
        ELambdaError &errorType,
        FString &errorMessage,
struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
// Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FInvokeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FInvokeAction(this->awsLambdaClient,
                success,
                invokeRequest,
                invokeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListAliasesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaListAliasesRequest listAliasesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListAliasesAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaListAliasesRequest listAliasesRequest,
        FLambdaListAliasesResult &listAliasesResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listAliasesRequest(listAliasesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListAliasesAsync(
            listAliasesRequest.toAWS(),
            [&success, &listAliasesResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListAliasesRequest &awsListAliasesRequest,
                const Aws::Lambda::Model::ListAliasesOutcome &awsListAliasesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListAliasesOutcome.IsSuccess();
                if (success) {
                    listAliasesResult.fromAWS(awsListAliasesOutcome.GetResult());
                }

                errorType = fromAWS(awsListAliasesOutcome.GetError().GetErrorType());
                errorMessage = ("ListAliases error: " + awsListAliasesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListAliases Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListAliases(
        UObject *WorldContextObject,
        bool &success,
        FLambdaListAliasesRequest listAliasesRequest,
        FLambdaListAliasesResult &listAliasesResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListAliasesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListAliasesAction(this->awsLambdaClient,
                success,
                listAliasesRequest,
                listAliasesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListCodeSigningConfigsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListCodeSigningConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest,
        FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listCodeSigningConfigsRequest(listCodeSigningConfigsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListCodeSigningConfigsAsync(
            listCodeSigningConfigsRequest.toAWS(),
            [&success, &listCodeSigningConfigsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListCodeSigningConfigsRequest &awsListCodeSigningConfigsRequest,
                const Aws::Lambda::Model::ListCodeSigningConfigsOutcome &awsListCodeSigningConfigsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListCodeSigningConfigsOutcome.IsSuccess();
                if (success) {
                    listCodeSigningConfigsResult.fromAWS(awsListCodeSigningConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListCodeSigningConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListCodeSigningConfigs error: " + awsListCodeSigningConfigsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListCodeSigningConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListCodeSigningConfigs(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest,
    FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListCodeSigningConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListCodeSigningConfigsAction(this->awsLambdaClient,
                success,
                listCodeSigningConfigsRequest,
                listCodeSigningConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListEventSourceMappingsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListEventSourceMappingsRequest listEventSourceMappingsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListEventSourceMappingsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListEventSourceMappingsRequest listEventSourceMappingsRequest,
        FListEventSourceMappingsResult &listEventSourceMappingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listEventSourceMappingsRequest(listEventSourceMappingsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListEventSourceMappingsAsync(
            listEventSourceMappingsRequest.toAWS(),
            [&success, &listEventSourceMappingsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListEventSourceMappingsRequest &awsListEventSourceMappingsRequest,
                const Aws::Lambda::Model::ListEventSourceMappingsOutcome &awsListEventSourceMappingsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListEventSourceMappingsOutcome.IsSuccess();
                if (success) {
                    listEventSourceMappingsResult.fromAWS(awsListEventSourceMappingsOutcome.GetResult());
                }

                errorType = fromAWS(awsListEventSourceMappingsOutcome.GetError().GetErrorType());
                errorMessage = ("ListEventSourceMappings error: " + awsListEventSourceMappingsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListEventSourceMappings Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListEventSourceMappings(
        UObject *WorldContextObject,
        bool &success,
        FListEventSourceMappingsRequest listEventSourceMappingsRequest,
        FListEventSourceMappingsResult &listEventSourceMappingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListEventSourceMappingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListEventSourceMappingsAction(this->awsLambdaClient,
                success,
                listEventSourceMappingsRequest,
                listEventSourceMappingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionEventInvokeConfigsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListFunctionEventInvokeConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest,
        FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listFunctionEventInvokeConfigsRequest(listFunctionEventInvokeConfigsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListFunctionEventInvokeConfigsAsync(
            listFunctionEventInvokeConfigsRequest.toAWS(),
            [&success, &listFunctionEventInvokeConfigsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListFunctionEventInvokeConfigsRequest &awsListFunctionEventInvokeConfigsRequest,
                const Aws::Lambda::Model::ListFunctionEventInvokeConfigsOutcome &awsListFunctionEventInvokeConfigsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListFunctionEventInvokeConfigsOutcome.IsSuccess();
                if (success) {
                    listFunctionEventInvokeConfigsResult.fromAWS(awsListFunctionEventInvokeConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionEventInvokeConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctionEventInvokeConfigs error: " + awsListFunctionEventInvokeConfigsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctionEventInvokeConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctionEventInvokeConfigs(
        UObject *WorldContextObject,
        bool &success,
        FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest,
        FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionEventInvokeConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionEventInvokeConfigsAction(this->awsLambdaClient,
                success,
                listFunctionEventInvokeConfigsRequest,
                listFunctionEventInvokeConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListFunctionsRequest listFunctionsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListFunctionsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListFunctionsRequest listFunctionsRequest,
        FListFunctionsResult &listFunctionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listFunctionsRequest(listFunctionsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListFunctionsAsync(
            listFunctionsRequest.toAWS(),
            [&success, &listFunctionsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListFunctionsRequest &awsListFunctionsRequest,
                const Aws::Lambda::Model::ListFunctionsOutcome &awsListFunctionsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListFunctionsOutcome.IsSuccess();
                if (success) {
                    listFunctionsResult.fromAWS(awsListFunctionsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctions error: " + awsListFunctionsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctions Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctions(
        UObject *WorldContextObject,
        bool &success,
        FListFunctionsRequest listFunctionsRequest,
        FListFunctionsResult &listFunctionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionsAction(this->awsLambdaClient,
                success,
                listFunctionsRequest,
                listFunctionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionsByCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListFunctionsByCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest,
        FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listFunctionsByCodeSigningConfigRequest(listFunctionsByCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListFunctionsByCodeSigningConfigAsync(
            listFunctionsByCodeSigningConfigRequest.toAWS(),
            [&success, &listFunctionsByCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListFunctionsByCodeSigningConfigRequest &awsListFunctionsByCodeSigningConfigRequest,
                const Aws::Lambda::Model::ListFunctionsByCodeSigningConfigOutcome &awsListFunctionsByCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListFunctionsByCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    listFunctionsByCodeSigningConfigResult.fromAWS(awsListFunctionsByCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionsByCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctionsByCodeSigningConfig error: " + awsListFunctionsByCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctionsByCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctionsByCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest,
    FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionsByCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionsByCodeSigningConfigAction(this->awsLambdaClient,
                success,
                listFunctionsByCodeSigningConfigRequest,
                listFunctionsByCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListLayerVersionsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListLayerVersionsRequest listLayerVersionsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListLayerVersionsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListLayerVersionsRequest listLayerVersionsRequest,
        FListLayerVersionsResult &listLayerVersionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listLayerVersionsRequest(listLayerVersionsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListLayerVersionsAsync(
            listLayerVersionsRequest.toAWS(),
            [&success, &listLayerVersionsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListLayerVersionsRequest &awsListLayerVersionsRequest,
                const Aws::Lambda::Model::ListLayerVersionsOutcome &awsListLayerVersionsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListLayerVersionsOutcome.IsSuccess();
                if (success) {
                    listLayerVersionsResult.fromAWS(awsListLayerVersionsOutcome.GetResult());
                }

                errorType = fromAWS(awsListLayerVersionsOutcome.GetError().GetErrorType());
                errorMessage = ("ListLayerVersions error: " + awsListLayerVersionsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListLayerVersions Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListLayerVersions(
        UObject *WorldContextObject,
        bool &success,
        FListLayerVersionsRequest listLayerVersionsRequest,
        FListLayerVersionsResult &listLayerVersionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListLayerVersionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListLayerVersionsAction(this->awsLambdaClient,
                success,
                listLayerVersionsRequest,
                listLayerVersionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListLayersAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListLayersRequest listLayersRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListLayersAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListLayersRequest listLayersRequest,
        FListLayersResult &listLayersResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listLayersRequest(listLayersRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListLayersAsync(
            listLayersRequest.toAWS(),
            [&success, &listLayersResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListLayersRequest &awsListLayersRequest,
                const Aws::Lambda::Model::ListLayersOutcome &awsListLayersOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListLayersOutcome.IsSuccess();
                if (success) {
                    listLayersResult.fromAWS(awsListLayersOutcome.GetResult());
                }

                errorType = fromAWS(awsListLayersOutcome.GetError().GetErrorType());
                errorMessage = ("ListLayers error: " + awsListLayersOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListLayers Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListLayers(
        UObject *WorldContextObject,
        bool &success,
        FListLayersRequest listLayersRequest,
        FListLayersResult &listLayersResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListLayersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListLayersAction(this->awsLambdaClient,
                success,
                listLayersRequest,
                listLayersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListProvisionedConcurrencyConfigsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListProvisionedConcurrencyConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest,
        FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listProvisionedConcurrencyConfigsRequest(listProvisionedConcurrencyConfigsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListProvisionedConcurrencyConfigsAsync(
            listProvisionedConcurrencyConfigsRequest.toAWS(),
            [&success, &listProvisionedConcurrencyConfigsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListProvisionedConcurrencyConfigsRequest &awsListProvisionedConcurrencyConfigsRequest,
                const Aws::Lambda::Model::ListProvisionedConcurrencyConfigsOutcome &awsListProvisionedConcurrencyConfigsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListProvisionedConcurrencyConfigsOutcome.IsSuccess();
                if (success) {
                    listProvisionedConcurrencyConfigsResult.fromAWS(awsListProvisionedConcurrencyConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListProvisionedConcurrencyConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListProvisionedConcurrencyConfigs error: " + awsListProvisionedConcurrencyConfigsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListProvisionedConcurrencyConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListProvisionedConcurrencyConfigs(
        UObject *WorldContextObject,
        bool &success,
        FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest,
        FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListProvisionedConcurrencyConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListProvisionedConcurrencyConfigsAction(this->awsLambdaClient,
                success,
                listProvisionedConcurrencyConfigsRequest,
                listProvisionedConcurrencyConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListTagsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListTagsRequest listTagsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListTagsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListTagsRequest listTagsRequest,
        FListTagsResult &listTagsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listTagsRequest(listTagsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListTagsAsync(
            listTagsRequest.toAWS(),
            [&success, &listTagsResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListTagsRequest &awsListTagsRequest,
                const Aws::Lambda::Model::ListTagsOutcome &awsListTagsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListTagsOutcome.IsSuccess();
                if (success) {
                    listTagsResult.fromAWS(awsListTagsOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsOutcome.GetError().GetErrorType());
                errorMessage = ("ListTags error: " + awsListTagsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTags Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListTags(
        UObject *WorldContextObject,
        bool &success,
        FListTagsRequest listTagsRequest,
        FListTagsResult &listTagsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsAction(this->awsLambdaClient,
                success,
                listTagsRequest,
                listTagsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListVersionsByFunctionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FListVersionsByFunctionRequest listVersionsByFunctionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListVersionsByFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListVersionsByFunctionRequest listVersionsByFunctionRequest,
        FListVersionsByFunctionResult &listVersionsByFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), listVersionsByFunctionRequest(listVersionsByFunctionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->ListVersionsByFunctionAsync(
            listVersionsByFunctionRequest.toAWS(),
            [&success, &listVersionsByFunctionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::ListVersionsByFunctionRequest &awsListVersionsByFunctionRequest,
                const Aws::Lambda::Model::ListVersionsByFunctionOutcome &awsListVersionsByFunctionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListVersionsByFunctionOutcome.IsSuccess();
                if (success) {
                    listVersionsByFunctionResult.fromAWS(awsListVersionsByFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsListVersionsByFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("ListVersionsByFunction error: " + awsListVersionsByFunctionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListVersionsByFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListVersionsByFunction(
        UObject *WorldContextObject,
        bool &success,
        FListVersionsByFunctionRequest listVersionsByFunctionRequest,
        FListVersionsByFunctionResult &listVersionsByFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListVersionsByFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListVersionsByFunctionAction(this->awsLambdaClient,
                success,
                listVersionsByFunctionRequest,
                listVersionsByFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPublishLayerVersionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FPublishLayerVersionRequest publishLayerVersionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPublishLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPublishLayerVersionRequest publishLayerVersionRequest,
        FPublishLayerVersionResult &publishLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), publishLayerVersionRequest(publishLayerVersionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PublishLayerVersionAsync(
            publishLayerVersionRequest.toAWS(),
            [&success, &publishLayerVersionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PublishLayerVersionRequest &awsPublishLayerVersionRequest,
                const Aws::Lambda::Model::PublishLayerVersionOutcome &awsPublishLayerVersionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPublishLayerVersionOutcome.IsSuccess();
                if (success) {
                    publishLayerVersionResult.fromAWS(awsPublishLayerVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsPublishLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("PublishLayerVersion error: " + awsPublishLayerVersionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PublishLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PublishLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FPublishLayerVersionRequest publishLayerVersionRequest,
        FPublishLayerVersionResult &publishLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPublishLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPublishLayerVersionAction(this->awsLambdaClient,
                success,
                publishLayerVersionRequest,
                publishLayerVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPublishVersionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FPublishVersionRequest publishVersionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPublishVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPublishVersionRequest publishVersionRequest,
        FPublishVersionResult &publishVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), publishVersionRequest(publishVersionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PublishVersionAsync(
            publishVersionRequest.toAWS(),
            [&success, &publishVersionResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PublishVersionRequest &awsPublishVersionRequest,
                const Aws::Lambda::Model::PublishVersionOutcome &awsPublishVersionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPublishVersionOutcome.IsSuccess();
                if (success) {
                    publishVersionResult.fromAWS(awsPublishVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsPublishVersionOutcome.GetError().GetErrorType());
                errorMessage = ("PublishVersion error: " + awsPublishVersionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PublishVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PublishVersion(
        UObject *WorldContextObject,
        bool &success,
        FPublishVersionRequest publishVersionRequest,
        FPublishVersionResult &publishVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPublishVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPublishVersionAction(this->awsLambdaClient,
                success,
                publishVersionRequest,
                publishVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPutFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest,
        FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), putFunctionCodeSigningConfigRequest(putFunctionCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PutFunctionCodeSigningConfigAsync(
            putFunctionCodeSigningConfigRequest.toAWS(),
            [&success, &putFunctionCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PutFunctionCodeSigningConfigRequest &awsPutFunctionCodeSigningConfigRequest,
                const Aws::Lambda::Model::PutFunctionCodeSigningConfigOutcome &awsPutFunctionCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPutFunctionCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    putFunctionCodeSigningConfigResult.fromAWS(awsPutFunctionCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionCodeSigningConfig error: " + awsPutFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest,
    FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                putFunctionCodeSigningConfigRequest,
                putFunctionCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionConcurrencyAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPutFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest,
        FPutFunctionConcurrencyResult &putFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), putFunctionConcurrencyRequest(putFunctionConcurrencyRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PutFunctionConcurrencyAsync(
            putFunctionConcurrencyRequest.toAWS(),
            [&success, &putFunctionConcurrencyResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PutFunctionConcurrencyRequest &awsPutFunctionConcurrencyRequest,
                const Aws::Lambda::Model::PutFunctionConcurrencyOutcome &awsPutFunctionConcurrencyOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPutFunctionConcurrencyOutcome.IsSuccess();
                if (success) {
                    putFunctionConcurrencyResult.fromAWS(awsPutFunctionConcurrencyOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionConcurrency error: " + awsPutFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest,
        FPutFunctionConcurrencyResult &putFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                putFunctionConcurrencyRequest,
                putFunctionConcurrencyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPutFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest,
        FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), putFunctionEventInvokeConfigRequest(putFunctionEventInvokeConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PutFunctionEventInvokeConfigAsync(
            putFunctionEventInvokeConfigRequest.toAWS(),
            [&success, &putFunctionEventInvokeConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PutFunctionEventInvokeConfigRequest &awsPutFunctionEventInvokeConfigRequest,
                const Aws::Lambda::Model::PutFunctionEventInvokeConfigOutcome &awsPutFunctionEventInvokeConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPutFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    putFunctionEventInvokeConfigResult.fromAWS(awsPutFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionEventInvokeConfig error: " + awsPutFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest,
        FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                putFunctionEventInvokeConfigRequest,
                putFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FPutProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest,
        FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), putProvisionedConcurrencyConfigRequest(putProvisionedConcurrencyConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->PutProvisionedConcurrencyConfigAsync(
            putProvisionedConcurrencyConfigRequest.toAWS(),
            [&success, &putProvisionedConcurrencyConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::PutProvisionedConcurrencyConfigRequest &awsPutProvisionedConcurrencyConfigRequest,
                const Aws::Lambda::Model::PutProvisionedConcurrencyConfigOutcome &awsPutProvisionedConcurrencyConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsPutProvisionedConcurrencyConfigOutcome.IsSuccess();
                if (success) {
                    putProvisionedConcurrencyConfigResult.fromAWS(awsPutProvisionedConcurrencyConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutProvisionedConcurrencyConfig error: " + awsPutProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest,
        FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                putProvisionedConcurrencyConfigRequest,
                putProvisionedConcurrencyConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FRemoveLayerVersionPermissionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FRemoveLayerVersionPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), removeLayerVersionPermissionRequest(removeLayerVersionPermissionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->RemoveLayerVersionPermissionAsync(
            removeLayerVersionPermissionRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::RemoveLayerVersionPermissionRequest &awsRemoveLayerVersionPermissionRequest,
                const Aws::Lambda::Model::RemoveLayerVersionPermissionOutcome &awsRemoveLayerVersionPermissionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsRemoveLayerVersionPermissionOutcome.IsSuccess();

                errorType = fromAWS(awsRemoveLayerVersionPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("RemoveLayerVersionPermission error: " + awsRemoveLayerVersionPermissionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RemoveLayerVersionPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::RemoveLayerVersionPermission(
        UObject *WorldContextObject,
        bool &success,
        FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRemoveLayerVersionPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRemoveLayerVersionPermissionAction(this->awsLambdaClient,
                success,
                removeLayerVersionPermissionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FRemovePermissionAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FRemovePermissionRequest removePermissionRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FRemovePermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FRemovePermissionRequest removePermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), removePermissionRequest(removePermissionRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->RemovePermissionAsync(
            removePermissionRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::RemovePermissionRequest &awsRemovePermissionRequest,
                const Aws::Lambda::Model::RemovePermissionOutcome &awsRemovePermissionOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsRemovePermissionOutcome.IsSuccess();

                errorType = fromAWS(awsRemovePermissionOutcome.GetError().GetErrorType());
                errorMessage = ("RemovePermission error: " + awsRemovePermissionOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RemovePermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::RemovePermission(
        UObject *WorldContextObject,
        bool &success,
        FRemovePermissionRequest removePermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRemovePermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRemovePermissionAction(this->awsLambdaClient,
                success,
                removePermissionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaTagResourceRequest tagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FTagResourceAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaTagResourceRequest tagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), tagResourceRequest(tagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->TagResourceAsync(
            tagResourceRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::TagResourceRequest &awsTagResourceRequest,
                const Aws::Lambda::Model::TagResourceOutcome &awsTagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsTagResourceOutcome.IsSuccess();

                errorType = fromAWS(awsTagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("TagResource error: " + awsTagResourceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("TagResource Request");
    }

#endif
};

#endif

void
ULambdaClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FLambdaTagResourceRequest tagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsLambdaClient,
                success,
                tagResourceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaUntagResourceRequest untagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUntagResourceAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaUntagResourceRequest untagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), untagResourceRequest(untagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UntagResourceAsync(
            untagResourceRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UntagResourceRequest &awsUntagResourceRequest,
                const Aws::Lambda::Model::UntagResourceOutcome &awsUntagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUntagResourceOutcome.IsSuccess();

                errorType = fromAWS(awsUntagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("UntagResource error: " + awsUntagResourceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UntagResource Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FLambdaUntagResourceRequest untagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsLambdaClient,
                success,
                untagResourceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateAliasAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FLambdaUpdateAliasRequest updateAliasRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaUpdateAliasRequest updateAliasRequest,
        FLambdaUpdateAliasResult &updateAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateAliasRequest(updateAliasRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateAliasAsync(
            updateAliasRequest.toAWS(),
            [&success, &updateAliasResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateAliasRequest &awsUpdateAliasRequest,
                const Aws::Lambda::Model::UpdateAliasOutcome &awsUpdateAliasOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateAliasOutcome.IsSuccess();
                if (success) {
                    updateAliasResult.fromAWS(awsUpdateAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateAliasOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateAlias error: " + awsUpdateAliasOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateAlias Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaUpdateAliasRequest updateAliasRequest,
        FLambdaUpdateAliasResult &updateAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateAliasAction(this->awsLambdaClient,
                success,
                updateAliasRequest,
                updateAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateCodeSigningConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest,
        FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateCodeSigningConfigRequest(updateCodeSigningConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateCodeSigningConfigAsync(
            updateCodeSigningConfigRequest.toAWS(),
            [&success, &updateCodeSigningConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateCodeSigningConfigRequest &awsUpdateCodeSigningConfigRequest,
                const Aws::Lambda::Model::UpdateCodeSigningConfigOutcome &awsUpdateCodeSigningConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    updateCodeSigningConfigResult.fromAWS(awsUpdateCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateCodeSigningConfig error: " + awsUpdateCodeSigningConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest,
    FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateCodeSigningConfigAction(this->awsLambdaClient,
                success,
                updateCodeSigningConfigRequest,
                updateCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateEventSourceMappingAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FUpdateEventSourceMappingRequest updateEventSourceMappingRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateEventSourceMappingRequest updateEventSourceMappingRequest,
        FUpdateEventSourceMappingResult &updateEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateEventSourceMappingRequest(updateEventSourceMappingRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateEventSourceMappingAsync(
            updateEventSourceMappingRequest.toAWS(),
            [&success, &updateEventSourceMappingResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateEventSourceMappingRequest &awsUpdateEventSourceMappingRequest,
                const Aws::Lambda::Model::UpdateEventSourceMappingOutcome &awsUpdateEventSourceMappingOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    updateEventSourceMappingResult.fromAWS(awsUpdateEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateEventSourceMapping error: " + awsUpdateEventSourceMappingOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FUpdateEventSourceMappingRequest updateEventSourceMappingRequest,
        FUpdateEventSourceMappingResult &updateEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateEventSourceMappingAction(this->awsLambdaClient,
                success,
                updateEventSourceMappingRequest,
                updateEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionCodeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FUpdateFunctionCodeRequest updateFunctionCodeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateFunctionCodeAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionCodeRequest updateFunctionCodeRequest,
        FUpdateFunctionCodeResult &updateFunctionCodeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateFunctionCodeRequest(updateFunctionCodeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateFunctionCodeAsync(
            updateFunctionCodeRequest.toAWS(),
            [&success, &updateFunctionCodeResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateFunctionCodeRequest &awsUpdateFunctionCodeRequest,
                const Aws::Lambda::Model::UpdateFunctionCodeOutcome &awsUpdateFunctionCodeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateFunctionCodeOutcome.IsSuccess();
                if (success) {
                    updateFunctionCodeResult.fromAWS(awsUpdateFunctionCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionCodeOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionCode error: " + awsUpdateFunctionCodeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionCode Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionCode(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionCodeRequest updateFunctionCodeRequest,
        FUpdateFunctionCodeResult &updateFunctionCodeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionCodeAction(this->awsLambdaClient,
                success,
                updateFunctionCodeRequest,
                updateFunctionCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionConfigurationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateFunctionConfigurationAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest,
        FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateFunctionConfigurationRequest(updateFunctionConfigurationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateFunctionConfigurationAsync(
            updateFunctionConfigurationRequest.toAWS(),
            [&success, &updateFunctionConfigurationResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateFunctionConfigurationRequest &awsUpdateFunctionConfigurationRequest,
                const Aws::Lambda::Model::UpdateFunctionConfigurationOutcome &awsUpdateFunctionConfigurationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateFunctionConfigurationOutcome.IsSuccess();
                if (success) {
                    updateFunctionConfigurationResult.fromAWS(awsUpdateFunctionConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionConfiguration error: " + awsUpdateFunctionConfigurationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionConfiguration Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest,
        FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionConfigurationAction(this->awsLambdaClient,
                success,
                updateFunctionConfigurationRequest,
                updateFunctionConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::Lambda::LambdaClient *LambdaClient;
    FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest,
        FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : LambdaClient(LambdaClient), updateFunctionEventInvokeConfigRequest(updateFunctionEventInvokeConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        LambdaClient->UpdateFunctionEventInvokeConfigAsync(
            updateFunctionEventInvokeConfigRequest.toAWS(),
            [&success, &updateFunctionEventInvokeConfigResult, &errorType, &errorMessage, this](
                const Aws::Lambda::LambdaClient *awsLambdaClient,
                const Aws::Lambda::Model::UpdateFunctionEventInvokeConfigRequest &awsUpdateFunctionEventInvokeConfigRequest,
                const Aws::Lambda::Model::UpdateFunctionEventInvokeConfigOutcome &awsUpdateFunctionEventInvokeConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    updateFunctionEventInvokeConfigResult.fromAWS(awsUpdateFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionEventInvokeConfig error: " + awsUpdateFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest,
        FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                updateFunctionEventInvokeConfigRequest,
                updateFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}