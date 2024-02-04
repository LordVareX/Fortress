/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "CognitoIdentityClientObject.h"
#include "CognitoIdentityGlobals.h"
#include "CognitoIdentityPrivatePCH.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_COGNITOIDENTITYCLIENTSDK

ECognitoIdentityError fromAWS(Aws::CognitoIdentity::CognitoIdentityErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::CognitoIdentity::CognitoIdentityErrors::INCOMPLETE_SIGNATURE:
            return ECognitoIdentityError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INTERNAL_FAILURE:
            return ECognitoIdentityError::INTERNAL_FAILURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_ACTION:
            return ECognitoIdentityError::INVALID_ACTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_CLIENT_TOKEN_ID:
            return ECognitoIdentityError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER_COMBINATION:
            return ECognitoIdentityError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_QUERY_PARAMETER:
            return ECognitoIdentityError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER_VALUE:
            return ECognitoIdentityError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_ACTION:
            return ECognitoIdentityError::MISSING_ACTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_AUTHENTICATION_TOKEN:
            return ECognitoIdentityError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_PARAMETER:
            return ECognitoIdentityError::MISSING_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::OPT_IN_REQUIRED:
            return ECognitoIdentityError::OPT_IN_REQUIRED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_EXPIRED:
            return ECognitoIdentityError::REQUEST_EXPIRED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SERVICE_UNAVAILABLE:
            return ECognitoIdentityError::SERVICE_UNAVAILABLE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::THROTTLING:
            return ECognitoIdentityError::THROTTLING;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::VALIDATION:
            return ECognitoIdentityError::VALIDATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::ACCESS_DENIED:
            return ECognitoIdentityError::ACCESS_DENIED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::RESOURCE_NOT_FOUND:
            return ECognitoIdentityError::RESOURCE_NOT_FOUND;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::UNRECOGNIZED_CLIENT:
            return ECognitoIdentityError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MALFORMED_QUERY_STRING:
            return ECognitoIdentityError::MALFORMED_QUERY_STRING;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SLOW_DOWN:
            return ECognitoIdentityError::SLOW_DOWN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_TIME_TOO_SKEWED:
            return ECognitoIdentityError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_SIGNATURE:
            return ECognitoIdentityError::INVALID_SIGNATURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SIGNATURE_DOES_NOT_MATCH:
            return ECognitoIdentityError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_ACCESS_KEY_ID:
            return ECognitoIdentityError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_TIMEOUT:
            return ECognitoIdentityError::REQUEST_TIMEOUT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::NETWORK_CONNECTION:
            return ECognitoIdentityError::NETWORK_CONNECTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::UNKNOWN:
            return ECognitoIdentityError::UNKNOWN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::CONCURRENT_MODIFICATION:
            return ECognitoIdentityError::CONCURRENT_MODIFICATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::DEVELOPER_USER_ALREADY_REGISTERED:
            return ECognitoIdentityError::DEVELOPER_USER_ALREADY_REGISTERED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::EXTERNAL_SERVICE:
            return ECognitoIdentityError::EXTERNAL_SERVICE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INTERNAL_ERROR:
            return ECognitoIdentityError::INTERNAL_ERROR;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_IDENTITY_POOL_CONFIGURATION:
            return ECognitoIdentityError::INVALID_IDENTITY_POOL_CONFIGURATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER:
            return ECognitoIdentityError::INVALID_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::LIMIT_EXCEEDED:
            return ECognitoIdentityError::LIMIT_EXCEEDED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::NOT_AUTHORIZED:
            return ECognitoIdentityError::NOT_AUTHORIZED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::RESOURCE_CONFLICT:
            return ECognitoIdentityError::RESOURCE_CONFLICT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::TOO_MANY_REQUESTS:
            return ECognitoIdentityError::TOO_MANY_REQUESTS;
            break;
        default:
            return ECognitoIdentityError::UNKNOWN;
            break;
    }
}

#endif

UCognitoIdentityClientObject *UCognitoIdentityClientObject::CreateCognitoIdentityObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    UCognitoIdentityClientObject *CognitoIdentityClient = NewObject<UCognitoIdentityClientObject>();
    CognitoIdentityClient->awsCognitoIdentityClient = new Aws::CognitoIdentity::CognitoIdentityClient(credentials.toAWS(),
    clientConfiguration.toAWS());
    return CognitoIdentityClient;
#endif
    return nullptr;
}

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FCreateIdentityPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FCreateIdentityPoolRequest createIdentityPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCreateIdentityPoolRequest createIdentityPoolRequest,
        FCreateIdentityPoolResult &createIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), createIdentityPoolRequest(createIdentityPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->CreateIdentityPoolAsync(
            createIdentityPoolRequest.toAWS(),
            [&success, &createIdentityPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::CreateIdentityPoolRequest &awsCreateIdentityPoolRequest,
                const Aws::CognitoIdentity::Model::CreateIdentityPoolOutcome &awsCreateIdentityPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateIdentityPoolOutcome.IsSuccess();
                if (success) {
                    createIdentityPoolResult.fromAWS(awsCreateIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("CreateIdentityPool error: " + awsCreateIdentityPoolOutcome.GetError().GetMessage()).c_str();
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
        return FString("CreateIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::CreateIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FCreateIdentityPoolRequest createIdentityPoolRequest,
        FCreateIdentityPoolResult &createIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                createIdentityPoolRequest,
                createIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDeleteIdentitiesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FDeleteIdentitiesRequest deleteIdentitiesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDeleteIdentitiesRequest deleteIdentitiesRequest,
        FDeleteIdentitiesResult &deleteIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), deleteIdentitiesRequest(deleteIdentitiesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->DeleteIdentitiesAsync(
            deleteIdentitiesRequest.toAWS(),
            [&success, &deleteIdentitiesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::DeleteIdentitiesRequest &awsDeleteIdentitiesRequest,
                const Aws::CognitoIdentity::Model::DeleteIdentitiesOutcome &awsDeleteIdentitiesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteIdentitiesOutcome.IsSuccess();
                if (success) {
                    deleteIdentitiesResult.fromAWS(awsDeleteIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentities error: " + awsDeleteIdentitiesOutcome.GetError().GetMessage()).c_str();
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
        return FString("DeleteIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DeleteIdentities(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentitiesRequest deleteIdentitiesRequest,
        FDeleteIdentitiesResult &deleteIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                deleteIdentitiesRequest,
                deleteIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDeleteIdentityPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FDeleteIdentityPoolRequest deleteIdentityPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDeleteIdentityPoolRequest deleteIdentityPoolRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), deleteIdentityPoolRequest(deleteIdentityPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->DeleteIdentityPoolAsync(
            deleteIdentityPoolRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::DeleteIdentityPoolRequest &awsDeleteIdentityPoolRequest,
                const Aws::CognitoIdentity::Model::DeleteIdentityPoolOutcome &awsDeleteIdentityPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteIdentityPoolOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentityPool error: " + awsDeleteIdentityPoolOutcome.GetError().GetMessage()).c_str();
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
        return FString("DeleteIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DeleteIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentityPoolRequest deleteIdentityPoolRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                deleteIdentityPoolRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDescribeIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FDescribeIdentityRequest describeIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDescribeIdentityRequest describeIdentityRequest,
        FDescribeIdentityResult &describeIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), describeIdentityRequest(describeIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->DescribeIdentityAsync(
            describeIdentityRequest.toAWS(),
            [&success, &describeIdentityResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::DescribeIdentityRequest &awsDescribeIdentityRequest,
                const Aws::CognitoIdentity::Model::DescribeIdentityOutcome &awsDescribeIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeIdentityOutcome.IsSuccess();
                if (success) {
                    describeIdentityResult.fromAWS(awsDescribeIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentity error: " + awsDescribeIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("DescribeIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DescribeIdentity(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityRequest describeIdentityRequest,
        FDescribeIdentityResult &describeIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityAction(this->awsCognitoIdentityClient,
                success,
                describeIdentityRequest,
                describeIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDescribeIdentityPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FDescribeIdentityPoolRequest describeIdentityPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDescribeIdentityPoolRequest describeIdentityPoolRequest,
        FDescribeIdentityPoolResult &describeIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), describeIdentityPoolRequest(describeIdentityPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->DescribeIdentityPoolAsync(
            describeIdentityPoolRequest.toAWS(),
            [&success, &describeIdentityPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::DescribeIdentityPoolRequest &awsDescribeIdentityPoolRequest,
                const Aws::CognitoIdentity::Model::DescribeIdentityPoolOutcome &awsDescribeIdentityPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeIdentityPoolOutcome.IsSuccess();
                if (success) {
                    describeIdentityPoolResult.fromAWS(awsDescribeIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentityPool error: " + awsDescribeIdentityPoolOutcome.GetError().GetMessage()).c_str();
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
        return FString("DescribeIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DescribeIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityPoolRequest describeIdentityPoolRequest,
        FDescribeIdentityPoolResult &describeIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                describeIdentityPoolRequest,
                describeIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetCredentialsForIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FGetCredentialsForIdentityRequest getCredentialsForIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetCredentialsForIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetCredentialsForIdentityRequest getCredentialsForIdentityRequest,
        FGetCredentialsForIdentityResult &getCredentialsForIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getCredentialsForIdentityRequest(getCredentialsForIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetCredentialsForIdentityAsync(
            getCredentialsForIdentityRequest.toAWS(),
            [&success, &getCredentialsForIdentityResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetCredentialsForIdentityRequest &awsGetCredentialsForIdentityRequest,
                const Aws::CognitoIdentity::Model::GetCredentialsForIdentityOutcome &awsGetCredentialsForIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetCredentialsForIdentityOutcome.IsSuccess();
                if (success) {
                    getCredentialsForIdentityResult.fromAWS(awsGetCredentialsForIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCredentialsForIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("GetCredentialsForIdentity error: " + awsGetCredentialsForIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetCredentialsForIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetCredentialsForIdentity(
        UObject *WorldContextObject,
        bool &success,
        FGetCredentialsForIdentityRequest getCredentialsForIdentityRequest,
        FGetCredentialsForIdentityResult &getCredentialsForIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCredentialsForIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCredentialsForIdentityAction(this->awsCognitoIdentityClient,
                success,
                getCredentialsForIdentityRequest,
                getCredentialsForIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetIdAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FGetIdRequest getIdRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetIdAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetIdRequest getIdRequest,
        FGetIdResult &getIdResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getIdRequest(getIdRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetIdAsync(
            getIdRequest.toAWS(),
            [&success, &getIdResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetIdRequest &awsGetIdRequest,
                const Aws::CognitoIdentity::Model::GetIdOutcome &awsGetIdOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetIdOutcome.IsSuccess();
                if (success) {
                    getIdResult.fromAWS(awsGetIdOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdOutcome.GetError().GetErrorType());
                errorMessage = ("GetId error: " + awsGetIdOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetId Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetId(
        UObject *WorldContextObject,
        bool &success,
        FGetIdRequest getIdRequest,
        FGetIdResult &getIdResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdAction(this->awsCognitoIdentityClient,
                success,
                getIdRequest,
                getIdResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetIdentityPoolRolesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FGetIdentityPoolRolesRequest getIdentityPoolRolesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetIdentityPoolRolesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetIdentityPoolRolesRequest getIdentityPoolRolesRequest,
        FGetIdentityPoolRolesResult &getIdentityPoolRolesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getIdentityPoolRolesRequest(getIdentityPoolRolesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetIdentityPoolRolesAsync(
            getIdentityPoolRolesRequest.toAWS(),
            [&success, &getIdentityPoolRolesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetIdentityPoolRolesRequest &awsGetIdentityPoolRolesRequest,
                const Aws::CognitoIdentity::Model::GetIdentityPoolRolesOutcome &awsGetIdentityPoolRolesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetIdentityPoolRolesOutcome.IsSuccess();
                if (success) {
                    getIdentityPoolRolesResult.fromAWS(awsGetIdentityPoolRolesOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdentityPoolRolesOutcome.GetError().GetErrorType());
                errorMessage = ("GetIdentityPoolRoles error: " + awsGetIdentityPoolRolesOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetIdentityPoolRoles Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetIdentityPoolRoles(
        UObject *WorldContextObject,
        bool &success,
        FGetIdentityPoolRolesRequest getIdentityPoolRolesRequest,
        FGetIdentityPoolRolesResult &getIdentityPoolRolesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdentityPoolRolesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdentityPoolRolesAction(this->awsCognitoIdentityClient,
                success,
                getIdentityPoolRolesRequest,
                getIdentityPoolRolesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetOpenIdTokenAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FGetOpenIdTokenRequest getOpenIdTokenRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetOpenIdTokenAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetOpenIdTokenRequest getOpenIdTokenRequest,
        FGetOpenIdTokenResult &getOpenIdTokenResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getOpenIdTokenRequest(getOpenIdTokenRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetOpenIdTokenAsync(
            getOpenIdTokenRequest.toAWS(),
            [&success, &getOpenIdTokenResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetOpenIdTokenRequest &awsGetOpenIdTokenRequest,
                const Aws::CognitoIdentity::Model::GetOpenIdTokenOutcome &awsGetOpenIdTokenOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetOpenIdTokenOutcome.IsSuccess();
                if (success) {
                    getOpenIdTokenResult.fromAWS(awsGetOpenIdTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsGetOpenIdTokenOutcome.GetError().GetErrorType());
                errorMessage = ("GetOpenIdToken error: " + awsGetOpenIdTokenOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetOpenIdToken Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetOpenIdToken(
        UObject *WorldContextObject,
        bool &success,
        FGetOpenIdTokenRequest getOpenIdTokenRequest,
        FGetOpenIdTokenResult &getOpenIdTokenResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetOpenIdTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetOpenIdTokenAction(this->awsCognitoIdentityClient,
                success,
                getOpenIdTokenRequest,
                getOpenIdTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetOpenIdTokenForDeveloperIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FGetOpenIdTokenForDeveloperIdentityRequest getOpenIdTokenForDeveloperIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetOpenIdTokenForDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetOpenIdTokenForDeveloperIdentityRequest getOpenIdTokenForDeveloperIdentityRequest,
        FGetOpenIdTokenForDeveloperIdentityResult &getOpenIdTokenForDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getOpenIdTokenForDeveloperIdentityRequest(getOpenIdTokenForDeveloperIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetOpenIdTokenForDeveloperIdentityAsync(
            getOpenIdTokenForDeveloperIdentityRequest.toAWS(),
            [&success, &getOpenIdTokenForDeveloperIdentityResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityRequest &awsGetOpenIdTokenForDeveloperIdentityRequest,
                const Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityOutcome &awsGetOpenIdTokenForDeveloperIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetOpenIdTokenForDeveloperIdentityOutcome.IsSuccess();
                if (success) {
                    getOpenIdTokenForDeveloperIdentityResult.fromAWS(awsGetOpenIdTokenForDeveloperIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsGetOpenIdTokenForDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("GetOpenIdTokenForDeveloperIdentity error: " + awsGetOpenIdTokenForDeveloperIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetOpenIdTokenForDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetOpenIdTokenForDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FGetOpenIdTokenForDeveloperIdentityRequest getOpenIdTokenForDeveloperIdentityRequest,
        FGetOpenIdTokenForDeveloperIdentityResult &getOpenIdTokenForDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetOpenIdTokenForDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetOpenIdTokenForDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                getOpenIdTokenForDeveloperIdentityRequest,
                getOpenIdTokenForDeveloperIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetPrincipalTagAttributeMapAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest getPrincipalTagAttributeMapRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetPrincipalTagAttributeMapAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest getPrincipalTagAttributeMapRequest,
        FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &getPrincipalTagAttributeMapResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), getPrincipalTagAttributeMapRequest(getPrincipalTagAttributeMapRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->GetPrincipalTagAttributeMapAsync(
            getPrincipalTagAttributeMapRequest.toAWS(),
            [&success, &getPrincipalTagAttributeMapResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapRequest &awsGetPrincipalTagAttributeMapRequest,
                const Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapOutcome &awsGetPrincipalTagAttributeMapOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetPrincipalTagAttributeMapOutcome.IsSuccess();
                if (success) {
                    getPrincipalTagAttributeMapResult.fromAWS(awsGetPrincipalTagAttributeMapOutcome.GetResult());
                }

                errorType = fromAWS(awsGetPrincipalTagAttributeMapOutcome.GetError().GetErrorType());
                errorMessage = ("GetPrincipalTagAttributeMap error: " + awsGetPrincipalTagAttributeMapOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetPrincipalTagAttributeMap Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetPrincipalTagAttributeMap(
    UObject *WorldContextObject,
    bool &success,
    FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest getPrincipalTagAttributeMapRequest,
    FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &getPrincipalTagAttributeMapResult,
    ECognitoIdentityError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPrincipalTagAttributeMapAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPrincipalTagAttributeMapAction(this->awsCognitoIdentityClient,
                success,
                getPrincipalTagAttributeMapRequest,
                getPrincipalTagAttributeMapResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListIdentitiesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FListIdentitiesRequest listIdentitiesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FListIdentitiesRequest listIdentitiesRequest,
        FListIdentitiesResult &listIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), listIdentitiesRequest(listIdentitiesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->ListIdentitiesAsync(
            listIdentitiesRequest.toAWS(),
            [&success, &listIdentitiesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::ListIdentitiesRequest &awsListIdentitiesRequest,
                const Aws::CognitoIdentity::Model::ListIdentitiesOutcome &awsListIdentitiesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListIdentitiesOutcome.IsSuccess();
                if (success) {
                    listIdentitiesResult.fromAWS(awsListIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentities error: " + awsListIdentitiesOutcome.GetError().GetMessage()).c_str();
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
        return FString("ListIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::ListIdentities(
        UObject *WorldContextObject,
        bool &success,
        FListIdentitiesRequest listIdentitiesRequest,
        FListIdentitiesResult &listIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                listIdentitiesRequest,
                listIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListIdentityPoolsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FListIdentityPoolsRequest listIdentityPoolsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListIdentityPoolsAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FListIdentityPoolsRequest listIdentityPoolsRequest,
        FListIdentityPoolsResult &listIdentityPoolsResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), listIdentityPoolsRequest(listIdentityPoolsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->ListIdentityPoolsAsync(
            listIdentityPoolsRequest.toAWS(),
            [&success, &listIdentityPoolsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::ListIdentityPoolsRequest &awsListIdentityPoolsRequest,
                const Aws::CognitoIdentity::Model::ListIdentityPoolsOutcome &awsListIdentityPoolsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListIdentityPoolsOutcome.IsSuccess();
                if (success) {
                    listIdentityPoolsResult.fromAWS(awsListIdentityPoolsOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentityPoolsOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentityPools error: " + awsListIdentityPoolsOutcome.GetError().GetMessage()).c_str();
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
        return FString("ListIdentityPools Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::ListIdentityPools(
        UObject *WorldContextObject,
        bool &success,
        FListIdentityPoolsRequest listIdentityPoolsRequest,
        FListIdentityPoolsResult &listIdentityPoolsResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentityPoolsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentityPoolsAction(this->awsCognitoIdentityClient,
                success,
                listIdentityPoolsRequest,
                listIdentityPoolsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListTagsForResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FCognitoIdentityListTagsForResourceRequest listTagsForResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListTagsForResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdentityListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), listTagsForResourceRequest(listTagsForResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->ListTagsForResourceAsync(
            listTagsForResourceRequest.toAWS(),
            [&success, &listTagsForResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::ListTagsForResourceRequest &awsListTagsForResourceRequest,
                const Aws::CognitoIdentity::Model::ListTagsForResourceOutcome &awsListTagsForResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListTagsForResourceOutcome.IsSuccess();
                if (success) {
                    listTagsForResourceResult.fromAWS(awsListTagsForResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsForResourceOutcome.GetError().GetErrorType());
                errorMessage = ("ListTagsForResource error: " + awsListTagsForResourceOutcome.GetError().GetMessage()).c_str();
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
        return FString("ListTagsForResource Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::ListTagsForResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdentityListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsForResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsForResourceAction(this->awsCognitoIdentityClient,
                success,
                listTagsForResourceRequest,
                listTagsForResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FLookupDeveloperIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FLookupDeveloperIdentityRequest lookupDeveloperIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FLookupDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FLookupDeveloperIdentityRequest lookupDeveloperIdentityRequest,
        FLookupDeveloperIdentityResult &lookupDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), lookupDeveloperIdentityRequest(lookupDeveloperIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->LookupDeveloperIdentityAsync(
            lookupDeveloperIdentityRequest.toAWS(),
            [&success, &lookupDeveloperIdentityResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::LookupDeveloperIdentityRequest &awsLookupDeveloperIdentityRequest,
                const Aws::CognitoIdentity::Model::LookupDeveloperIdentityOutcome &awsLookupDeveloperIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsLookupDeveloperIdentityOutcome.IsSuccess();
                if (success) {
                    lookupDeveloperIdentityResult.fromAWS(awsLookupDeveloperIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsLookupDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("LookupDeveloperIdentity error: " + awsLookupDeveloperIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("LookupDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::LookupDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FLookupDeveloperIdentityRequest lookupDeveloperIdentityRequest,
        FLookupDeveloperIdentityResult &lookupDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FLookupDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FLookupDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                lookupDeveloperIdentityRequest,
                lookupDeveloperIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FMergeDeveloperIdentitiesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FMergeDeveloperIdentitiesRequest mergeDeveloperIdentitiesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FMergeDeveloperIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FMergeDeveloperIdentitiesRequest mergeDeveloperIdentitiesRequest,
        FMergeDeveloperIdentitiesResult &mergeDeveloperIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), mergeDeveloperIdentitiesRequest(mergeDeveloperIdentitiesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->MergeDeveloperIdentitiesAsync(
            mergeDeveloperIdentitiesRequest.toAWS(),
            [&success, &mergeDeveloperIdentitiesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesRequest &awsMergeDeveloperIdentitiesRequest,
                const Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesOutcome &awsMergeDeveloperIdentitiesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsMergeDeveloperIdentitiesOutcome.IsSuccess();
                if (success) {
                    mergeDeveloperIdentitiesResult.fromAWS(awsMergeDeveloperIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsMergeDeveloperIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("MergeDeveloperIdentities error: " + awsMergeDeveloperIdentitiesOutcome.GetError().GetMessage()).c_str();
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
        return FString("MergeDeveloperIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::MergeDeveloperIdentities(
        UObject *WorldContextObject,
        bool &success,
        FMergeDeveloperIdentitiesRequest mergeDeveloperIdentitiesRequest,
        FMergeDeveloperIdentitiesResult &mergeDeveloperIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FMergeDeveloperIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FMergeDeveloperIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                mergeDeveloperIdentitiesRequest,
                mergeDeveloperIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FSetIdentityPoolRolesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FSetIdentityPoolRolesRequest setIdentityPoolRolesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetIdentityPoolRolesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FSetIdentityPoolRolesRequest setIdentityPoolRolesRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), setIdentityPoolRolesRequest(setIdentityPoolRolesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->SetIdentityPoolRolesAsync(
            setIdentityPoolRolesRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::SetIdentityPoolRolesRequest &awsSetIdentityPoolRolesRequest,
                const Aws::CognitoIdentity::Model::SetIdentityPoolRolesOutcome &awsSetIdentityPoolRolesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetIdentityPoolRolesOutcome.IsSuccess();

                errorType = fromAWS(awsSetIdentityPoolRolesOutcome.GetError().GetErrorType());
                errorMessage = ("SetIdentityPoolRoles error: " + awsSetIdentityPoolRolesOutcome.GetError().GetMessage()).c_str();
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
        return FString("SetIdentityPoolRoles Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::SetIdentityPoolRoles(
        UObject *WorldContextObject,
        bool &success,
        FSetIdentityPoolRolesRequest setIdentityPoolRolesRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetIdentityPoolRolesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetIdentityPoolRolesAction(this->awsCognitoIdentityClient,
                success,
                setIdentityPoolRolesRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FSetPrincipalTagAttributeMapAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest setPrincipalTagAttributeMapRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetPrincipalTagAttributeMapAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest setPrincipalTagAttributeMapRequest,
        FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &setPrincipalTagAttributeMapResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), setPrincipalTagAttributeMapRequest(setPrincipalTagAttributeMapRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->SetPrincipalTagAttributeMapAsync(
            setPrincipalTagAttributeMapRequest.toAWS(),
            [&success, &setPrincipalTagAttributeMapResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapRequest &awsSetPrincipalTagAttributeMapRequest,
                const Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapOutcome &awsSetPrincipalTagAttributeMapOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetPrincipalTagAttributeMapOutcome.IsSuccess();
                if (success) {
                    setPrincipalTagAttributeMapResult.fromAWS(awsSetPrincipalTagAttributeMapOutcome.GetResult());
                }

                errorType = fromAWS(awsSetPrincipalTagAttributeMapOutcome.GetError().GetErrorType());
                errorMessage = ("SetPrincipalTagAttributeMap error: " + awsSetPrincipalTagAttributeMapOutcome.GetError().GetMessage()).c_str();
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
        return FString("SetPrincipalTagAttributeMap Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::SetPrincipalTagAttributeMap(
    UObject *WorldContextObject,
    bool &success,
    FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest setPrincipalTagAttributeMapRequest,
    FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &setPrincipalTagAttributeMapResult,
    ECognitoIdentityError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetPrincipalTagAttributeMapAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetPrincipalTagAttributeMapAction(this->awsCognitoIdentityClient,
                success,
                setPrincipalTagAttributeMapRequest,
                setPrincipalTagAttributeMapResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FCognitoIdentityTagResourceRequest tagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FTagResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityTagResourceRequest tagResourceRequest,
        FCognitoIdentityTagResourceResult &tagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), tagResourceRequest(tagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->TagResourceAsync(
            tagResourceRequest.toAWS(),
            [&success, &tagResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::TagResourceRequest &awsTagResourceRequest,
                const Aws::CognitoIdentity::Model::TagResourceOutcome &awsTagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsTagResourceOutcome.IsSuccess();
                if (success) {
                    tagResourceResult.fromAWS(awsTagResourceOutcome.GetResult());
                }

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
UCognitoIdentityClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityTagResourceRequest tagResourceRequest,
        FCognitoIdentityTagResourceResult &tagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsCognitoIdentityClient,
                success,
                tagResourceRequest,
                tagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUnlinkDeveloperIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FUnlinkDeveloperIdentityRequest unlinkDeveloperIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUnlinkDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUnlinkDeveloperIdentityRequest unlinkDeveloperIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), unlinkDeveloperIdentityRequest(unlinkDeveloperIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->UnlinkDeveloperIdentityAsync(
            unlinkDeveloperIdentityRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::UnlinkDeveloperIdentityRequest &awsUnlinkDeveloperIdentityRequest,
                const Aws::CognitoIdentity::Model::UnlinkDeveloperIdentityOutcome &awsUnlinkDeveloperIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUnlinkDeveloperIdentityOutcome.IsSuccess();

                errorType = fromAWS(awsUnlinkDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("UnlinkDeveloperIdentity error: " + awsUnlinkDeveloperIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("UnlinkDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UnlinkDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FUnlinkDeveloperIdentityRequest unlinkDeveloperIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUnlinkDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUnlinkDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                unlinkDeveloperIdentityRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUnlinkIdentityAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FUnlinkIdentityRequest unlinkIdentityRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUnlinkIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUnlinkIdentityRequest unlinkIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), unlinkIdentityRequest(unlinkIdentityRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->UnlinkIdentityAsync(
            unlinkIdentityRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::UnlinkIdentityRequest &awsUnlinkIdentityRequest,
                const Aws::CognitoIdentity::Model::UnlinkIdentityOutcome &awsUnlinkIdentityOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUnlinkIdentityOutcome.IsSuccess();

                errorType = fromAWS(awsUnlinkIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("UnlinkIdentity error: " + awsUnlinkIdentityOutcome.GetError().GetMessage()).c_str();
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
        return FString("UnlinkIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UnlinkIdentity(
        UObject *WorldContextObject,
        bool &success,
        FUnlinkIdentityRequest unlinkIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUnlinkIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUnlinkIdentityAction(this->awsCognitoIdentityClient,
                success,
                unlinkIdentityRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FCognitoIdentityUntagResourceRequest untagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUntagResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityUntagResourceRequest untagResourceRequest,
        FCognitoIdentityUntagResourceResult &untagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), untagResourceRequest(untagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->UntagResourceAsync(
            untagResourceRequest.toAWS(),
            [&success, &untagResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::UntagResourceRequest &awsUntagResourceRequest,
                const Aws::CognitoIdentity::Model::UntagResourceOutcome &awsUntagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUntagResourceOutcome.IsSuccess();
                if (success) {
                    untagResourceResult.fromAWS(awsUntagResourceOutcome.GetResult());
                }

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
UCognitoIdentityClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityUntagResourceRequest untagResourceRequest,
        FCognitoIdentityUntagResourceResult &untagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsCognitoIdentityClient,
                success,
                untagResourceRequest,
                untagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUpdateIdentityPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient;
    FUpdateIdentityPoolRequest updateIdentityPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUpdateIdentityPoolRequest updateIdentityPoolRequest,
        FUpdateIdentityPoolResult &updateIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdentityClient(CognitoIdentityClient), updateIdentityPoolRequest(updateIdentityPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdentityClient->UpdateIdentityPoolAsync(
            updateIdentityPoolRequest.toAWS(),
            [&success, &updateIdentityPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentity::CognitoIdentityClient *awsCognitoIdentityClient,
                const Aws::CognitoIdentity::Model::UpdateIdentityPoolRequest &awsUpdateIdentityPoolRequest,
                const Aws::CognitoIdentity::Model::UpdateIdentityPoolOutcome &awsUpdateIdentityPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateIdentityPoolOutcome.IsSuccess();
                if (success) {
                    updateIdentityPoolResult.fromAWS(awsUpdateIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateIdentityPool error: " + awsUpdateIdentityPoolOutcome.GetError().GetMessage()).c_str();
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
        return FString("UpdateIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UpdateIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FUpdateIdentityPoolRequest updateIdentityPoolRequest,
        FUpdateIdentityPoolResult &updateIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                updateIdentityPoolRequest,
                updateIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}