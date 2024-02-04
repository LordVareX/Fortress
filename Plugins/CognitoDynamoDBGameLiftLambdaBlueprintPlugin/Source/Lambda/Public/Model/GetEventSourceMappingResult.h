/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetEventSourceMappingResult.h"

#endif

#include "Model/EventSourcePosition.h"
#include "Model/DestinationConfig.h"
#include "Model/AWSLambdaSourceAccessConfiguration.h"
#include "Model/AWSLambdaSelfManagedEventSource.h"
#include "Model/AWSLambdaFunctionResponseType.h"

#include "GetEventSourceMappingResult.generated.h"

USTRUCT(BlueprintType)
struct FGetEventSourceMappingResult {
GENERATED_BODY()

    /**
    *  <p>The identifier of the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString UUID;

    /**
    *  <p>The position in a stream from which to start reading. Required for Amazon Kinesis, Amazon DynamoDB, and Amazon MSK Streams sources. <code>AT_TIMESTAMP</code> is only supported for Amazon Kinesis streams.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    ES3EventSourcePosition startingPosition;

    /**
    *  <p>With <code>StartingPosition</code> set to <code>AT_TIMESTAMP</code>, the time from which to start reading.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime startingPositionTimestamp;

    /**
    *  <p>The maximum number of items to retrieve in a single batch.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int batchSize;

    /**
    *  <p>(Streams and SQS standard queues) The maximum amount of time to gather records before invoking the function, in seconds. The default value is zero.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumBatchingWindowInSeconds;

    /**
    *  <p>(Streams) The number of batches to process from each shard concurrently. The default value is 1.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int parallelizationFactor;

    /**
    *  <p>The Amazon Resource Name (ARN) of the event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString eventSourceArn;

    /**
    *  <p>The ARN of the Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionArn;

    /**
    *  <p>The date that the event source mapping was last updated, or its state changed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDateTime lastModified;

    /**
    *  <p>The result of the last AWS Lambda invocation of your Lambda function.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString lastProcessingResult;

    /**
    *  <p>The state of the event source mapping. It can be one of the following: <code>Creating</code>, <code>Enabling</code>, <code>Enabled</code>, <code>Disabling</code>, <code>Disabled</code>, <code>Updating</code>, or <code>Deleting</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString state;

    /**
    *  <p>Indicates whether the last change to the event source mapping was made by a user, or by the Lambda service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString stateTransitionReason;

    /**
    *  <p>(Streams) An Amazon SQS queue or Amazon SNS topic destination for discarded records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDestinationConfig destinationConfig;

    /**
    *  <p>The name of the Kafka topic.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> topics;

    /**
    *  <p> (MQ) The name of the Amazon MQ broker destination queue to consume. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> queues;

    /**
    *  <p>An array of the authentication protocol, or the VPC components to secure your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaSourceAccessConfiguration> sourceAccessConfigurations;

    /**
    *  <p>The Self-Managed Apache Kafka cluster for your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FAWSLambdaSelfManagedEventSource selfManagedEventSource;

    /**
    *  <p>(Streams) Discard records older than the specified age. The default value is infinite (-1). When set to infinite (-1), failed records are retried until the record expires.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRecordAgeInSeconds;

    /**
    *  <p>(Streams) If the function returns an error, split the batch in two and retry. The default value is false.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool bisectBatchOnFunctionError;

    /**
    *  <p>(Streams) The maximum number of times to retry when the function returns an error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRetryAttempts;

    /**
    *  <p>(Streams) The duration in seconds of a processing window. The range is between 1 second up to 900 seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int tumblingWindowInSeconds;

    /**
    *  <p>(Streams) A list of current response type enums applied to the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<EAWSLambdaFunctionResponseType> functionResponseTypes;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FGetEventSourceMappingResult &fromAWS(const Aws::Lambda::Model::GetEventSourceMappingResult &awsGetEventSourceMappingResult) {
        this->UUID = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetUUID().c_str());

        switch(awsGetEventSourceMappingResult.GetStartingPosition()) {
            case Aws::Lambda::Model::EventSourcePosition::NOT_SET:
                this->startingPosition = ES3EventSourcePosition::NOT_SET;
                break;
            case Aws::Lambda::Model::EventSourcePosition::TRIM_HORIZON:
                this->startingPosition = ES3EventSourcePosition::TRIM_HORIZON;
                break;
            case Aws::Lambda::Model::EventSourcePosition::LATEST:
                this->startingPosition = ES3EventSourcePosition::LATEST;
                break;
            case Aws::Lambda::Model::EventSourcePosition::AT_TIMESTAMP:
                this->startingPosition = ES3EventSourcePosition::AT_TIMESTAMP;
                break;
            default:
                this->startingPosition = ES3EventSourcePosition::NOT_SET;
                break;
            }

        this->startingPositionTimestamp = FDateTime(1970, 1, 1) + FTimespan(awsGetEventSourceMappingResult.GetStartingPositionTimestamp().Millis() * ETimespan::TicksPerMillisecond);

		this->batchSize = awsGetEventSourceMappingResult.GetBatchSize();

		this->maximumBatchingWindowInSeconds = awsGetEventSourceMappingResult.GetMaximumBatchingWindowInSeconds();

		this->parallelizationFactor = awsGetEventSourceMappingResult.GetParallelizationFactor();

        this->eventSourceArn = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetEventSourceArn().c_str());

        this->functionArn = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetFunctionArn().c_str());

        this->lastModified = FDateTime(1970, 1, 1) + FTimespan(awsGetEventSourceMappingResult.GetLastModified().Millis() * ETimespan::TicksPerMillisecond);

        this->lastProcessingResult = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetLastProcessingResult().c_str());

        this->state = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetState().c_str());

        this->stateTransitionReason = UTF8_TO_TCHAR(awsGetEventSourceMappingResult.GetStateTransitionReason().c_str());

        this->destinationConfig.fromAWS(awsGetEventSourceMappingResult.GetDestinationConfig());

        this->topics.Empty();
        for (const Aws::String& elem : awsGetEventSourceMappingResult.GetTopics()) {
            this->topics.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->queues.Empty();
        for (const Aws::String& elem : awsGetEventSourceMappingResult.GetQueues()) {
            this->queues.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->sourceAccessConfigurations.Empty();
        for (const Aws::Lambda::Model::SourceAccessConfiguration& elem : awsGetEventSourceMappingResult.GetSourceAccessConfigurations()) {
            this->sourceAccessConfigurations.Add(FAWSLambdaSourceAccessConfiguration().fromAWS(elem));
        }

        this->selfManagedEventSource = FAWSLambdaSelfManagedEventSource().fromAWS(awsGetEventSourceMappingResult.GetSelfManagedEventSource());

		this->maximumRecordAgeInSeconds = awsGetEventSourceMappingResult.GetMaximumRecordAgeInSeconds();

        this->bisectBatchOnFunctionError = awsGetEventSourceMappingResult.GetBisectBatchOnFunctionError();

		this->maximumRetryAttempts = awsGetEventSourceMappingResult.GetMaximumRetryAttempts();

		this->tumblingWindowInSeconds = awsGetEventSourceMappingResult.GetTumblingWindowInSeconds();

        this->functionResponseTypes.Empty();
        for (const Aws::Lambda::Model::FunctionResponseType& elem : awsGetEventSourceMappingResult.GetFunctionResponseTypes()) {
            switch(elem) {
                case Aws::Lambda::Model::FunctionResponseType::NOT_SET:
                    this->functionResponseTypes.Add(EAWSLambdaFunctionResponseType::NOT_SET);
                    break;
                case Aws::Lambda::Model::FunctionResponseType::ReportBatchItemFailures:
                    this->functionResponseTypes.Add(EAWSLambdaFunctionResponseType::ReportBatchItemFailures);
                    break;
                default:
                    break;
		    };
        }

        return *this;
    }
#endif
};
