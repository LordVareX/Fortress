/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "DynamoDBStreamsClientObject.h"
#include "DynamoDBStreamsGlobals.h"
#include "DynamoDBStreamsPrivatePCH.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_DYNAMODBSTREAMSCLIENTSDK

EDynamoDBStreamsError fromAWS(Aws::DynamoDBStreams::DynamoDBStreamsErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INCOMPLETE_SIGNATURE:
            return EDynamoDBStreamsError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INTERNAL_FAILURE:
            return EDynamoDBStreamsError::INTERNAL_FAILURE;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_ACTION:
            return EDynamoDBStreamsError::INVALID_ACTION;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_CLIENT_TOKEN_ID:
            return EDynamoDBStreamsError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_PARAMETER_COMBINATION:
            return EDynamoDBStreamsError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_QUERY_PARAMETER:
            return EDynamoDBStreamsError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_PARAMETER_VALUE:
            return EDynamoDBStreamsError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::MISSING_ACTION:
            return EDynamoDBStreamsError::MISSING_ACTION;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::MISSING_AUTHENTICATION_TOKEN:
            return EDynamoDBStreamsError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::MISSING_PARAMETER:
            return EDynamoDBStreamsError::MISSING_PARAMETER;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::OPT_IN_REQUIRED:
            return EDynamoDBStreamsError::OPT_IN_REQUIRED;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::REQUEST_EXPIRED:
            return EDynamoDBStreamsError::REQUEST_EXPIRED;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::SERVICE_UNAVAILABLE:
            return EDynamoDBStreamsError::SERVICE_UNAVAILABLE;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::THROTTLING:
            return EDynamoDBStreamsError::THROTTLING;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::VALIDATION:
            return EDynamoDBStreamsError::VALIDATION;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::ACCESS_DENIED:
            return EDynamoDBStreamsError::ACCESS_DENIED;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::RESOURCE_NOT_FOUND:
            return EDynamoDBStreamsError::RESOURCE_NOT_FOUND;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::UNRECOGNIZED_CLIENT:
            return EDynamoDBStreamsError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::MALFORMED_QUERY_STRING:
            return EDynamoDBStreamsError::MALFORMED_QUERY_STRING;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::SLOW_DOWN:
            return EDynamoDBStreamsError::SLOW_DOWN;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::REQUEST_TIME_TOO_SKEWED:
            return EDynamoDBStreamsError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_SIGNATURE:
            return EDynamoDBStreamsError::INVALID_SIGNATURE;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::SIGNATURE_DOES_NOT_MATCH:
            return EDynamoDBStreamsError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::INVALID_ACCESS_KEY_ID:
            return EDynamoDBStreamsError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::REQUEST_TIMEOUT:
            return EDynamoDBStreamsError::REQUEST_TIMEOUT;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::NETWORK_CONNECTION:
            return EDynamoDBStreamsError::NETWORK_CONNECTION;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::UNKNOWN:
            return EDynamoDBStreamsError::UNKNOWN;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::EXPIRED_ITERATOR:
            return EDynamoDBStreamsError::EXPIRED_ITERATOR;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::LIMIT_EXCEEDED:
            return EDynamoDBStreamsError::LIMIT_EXCEEDED;
            break;
        case Aws::DynamoDBStreams::DynamoDBStreamsErrors::TRIMMED_DATA_ACCESS:
            return EDynamoDBStreamsError::TRIMMED_DATA_ACCESS;
            break;
        default:
            return EDynamoDBStreamsError::UNKNOWN;
            break;
    }
}

#endif

UDynamoDBStreamsClientObject *UDynamoDBStreamsClientObject::CreateDynamoDBStreamsObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    UDynamoDBStreamsClientObject *DynamoDBStreamsClient = NewObject<UDynamoDBStreamsClientObject>();
    DynamoDBStreamsClient->awsDynamoDBStreamsClient = new Aws::DynamoDBStreams::DynamoDBStreamsClient(credentials.toAWS(),
    clientConfiguration.toAWS());
    return DynamoDBStreamsClient;
#endif
    return nullptr;
}

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

class FDescribeStreamAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient;
    FDescribeStreamRequest describeStreamRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeStreamAction(
        Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient,
        bool &success,
        FDescribeStreamRequest describeStreamRequest,
        FDescribeStreamResult &describeStreamResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : DynamoDBStreamsClient(DynamoDBStreamsClient), describeStreamRequest(describeStreamRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        DynamoDBStreamsClient->DescribeStreamAsync(
            describeStreamRequest.toAWS(),
            [&success, &describeStreamResult, &errorType, &errorMessage, this](
                const Aws::DynamoDBStreams::DynamoDBStreamsClient *awsDynamoDBStreamsClient,
                const Aws::DynamoDBStreams::Model::DescribeStreamRequest &awsDescribeStreamRequest,
                const Aws::DynamoDBStreams::Model::DescribeStreamOutcome &awsDescribeStreamOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeStreamOutcome.IsSuccess();
                if (success) {
                    describeStreamResult.fromAWS(awsDescribeStreamOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeStreamOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeStream error: " + awsDescribeStreamOutcome.GetError().GetMessage()).c_str();
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
        return FString("DescribeStream Request");
    }

#endif
};

#endif

void
UDynamoDBStreamsClientObject::DescribeStream(
        UObject *WorldContextObject,
        bool &success,
        FDescribeStreamRequest describeStreamRequest,
        FDescribeStreamResult &describeStreamResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeStreamAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeStreamAction(this->awsDynamoDBStreamsClient,
                success,
                describeStreamRequest,
                describeStreamResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

class FGetRecordsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient;
    FGetRecordsRequest getRecordsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetRecordsAction(
        Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient,
        bool &success,
        FGetRecordsRequest getRecordsRequest,
        FGetRecordsResult &getRecordsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : DynamoDBStreamsClient(DynamoDBStreamsClient), getRecordsRequest(getRecordsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        DynamoDBStreamsClient->GetRecordsAsync(
            getRecordsRequest.toAWS(),
            [&success, &getRecordsResult, &errorType, &errorMessage, this](
                const Aws::DynamoDBStreams::DynamoDBStreamsClient *awsDynamoDBStreamsClient,
                const Aws::DynamoDBStreams::Model::GetRecordsRequest &awsGetRecordsRequest,
                const Aws::DynamoDBStreams::Model::GetRecordsOutcome &awsGetRecordsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetRecordsOutcome.IsSuccess();
                if (success) {
                    getRecordsResult.fromAWS(awsGetRecordsOutcome.GetResult());
                }

                errorType = fromAWS(awsGetRecordsOutcome.GetError().GetErrorType());
                errorMessage = ("GetRecords error: " + awsGetRecordsOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetRecords Request");
    }

#endif
};

#endif

void
UDynamoDBStreamsClientObject::GetRecords(
        UObject *WorldContextObject,
        bool &success,
        FGetRecordsRequest getRecordsRequest,
        FGetRecordsResult &getRecordsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetRecordsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetRecordsAction(this->awsDynamoDBStreamsClient,
                success,
                getRecordsRequest,
                getRecordsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

class FGetShardIteratorAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient;
    FGetShardIteratorRequest getShardIteratorRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetShardIteratorAction(
        Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient,
        bool &success,
        FGetShardIteratorRequest getShardIteratorRequest,
        FGetShardIteratorResult &getShardIteratorResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : DynamoDBStreamsClient(DynamoDBStreamsClient), getShardIteratorRequest(getShardIteratorRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        DynamoDBStreamsClient->GetShardIteratorAsync(
            getShardIteratorRequest.toAWS(),
            [&success, &getShardIteratorResult, &errorType, &errorMessage, this](
                const Aws::DynamoDBStreams::DynamoDBStreamsClient *awsDynamoDBStreamsClient,
                const Aws::DynamoDBStreams::Model::GetShardIteratorRequest &awsGetShardIteratorRequest,
                const Aws::DynamoDBStreams::Model::GetShardIteratorOutcome &awsGetShardIteratorOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetShardIteratorOutcome.IsSuccess();
                if (success) {
                    getShardIteratorResult.fromAWS(awsGetShardIteratorOutcome.GetResult());
                }

                errorType = fromAWS(awsGetShardIteratorOutcome.GetError().GetErrorType());
                errorMessage = ("GetShardIterator error: " + awsGetShardIteratorOutcome.GetError().GetMessage()).c_str();
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
        return FString("GetShardIterator Request");
    }

#endif
};

#endif

void
UDynamoDBStreamsClientObject::GetShardIterator(
        UObject *WorldContextObject,
        bool &success,
        FGetShardIteratorRequest getShardIteratorRequest,
        FGetShardIteratorResult &getShardIteratorResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetShardIteratorAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetShardIteratorAction(this->awsDynamoDBStreamsClient,
                success,
                getShardIteratorRequest,
                getShardIteratorResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

class FListStreamsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient;
    FListStreamsRequest listStreamsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListStreamsAction(
        Aws::DynamoDBStreams::DynamoDBStreamsClient *DynamoDBStreamsClient,
        bool &success,
        FListStreamsRequest listStreamsRequest,
        FListStreamsResult &listStreamsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : DynamoDBStreamsClient(DynamoDBStreamsClient), listStreamsRequest(listStreamsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        DynamoDBStreamsClient->ListStreamsAsync(
            listStreamsRequest.toAWS(),
            [&success, &listStreamsResult, &errorType, &errorMessage, this](
                const Aws::DynamoDBStreams::DynamoDBStreamsClient *awsDynamoDBStreamsClient,
                const Aws::DynamoDBStreams::Model::ListStreamsRequest &awsListStreamsRequest,
                const Aws::DynamoDBStreams::Model::ListStreamsOutcome &awsListStreamsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListStreamsOutcome.IsSuccess();
                if (success) {
                    listStreamsResult.fromAWS(awsListStreamsOutcome.GetResult());
                }

                errorType = fromAWS(awsListStreamsOutcome.GetError().GetErrorType());
                errorMessage = ("ListStreams error: " + awsListStreamsOutcome.GetError().GetMessage()).c_str();
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
        return FString("ListStreams Request");
    }

#endif
};

#endif

void
UDynamoDBStreamsClientObject::ListStreams(
        UObject *WorldContextObject,
        bool &success,
        FListStreamsRequest listStreamsRequest,
        FListStreamsResult &listStreamsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListStreamsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListStreamsAction(this->awsDynamoDBStreamsClient,
                success,
                listStreamsRequest,
                listStreamsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}