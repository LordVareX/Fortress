/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateEventSourceMappingRequest.h"

#endif

#include "Model/DestinationConfig.h"
#include "Model/AWSLambdaSourceAccessConfiguration.h"
#include "Model/AWSLambdaFunctionResponseType.h"

#include "UpdateEventSourceMappingRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateEventSourceMappingRequest {
GENERATED_BODY()

    /**
    *  <p>The identifier of the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString UUID;

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>MyFunction</code>.</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction</code>.</p> </li> <li> <p> <b>Version or Alias ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:MyFunction:PROD</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:MyFunction</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it's limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>If true, the event source mapping is active. Set to false to pause polling and invocation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool enabled;

    /**
    *  <p>The maximum number of items to retrieve in a single batch.</p> <ul> <li> <p> <b>Amazon Kinesis</b> - Default 100. Max 10,000.</p> </li> <li> <p> <b>Amazon DynamoDB Streams</b> - Default 100. Max 1,000.</p> </li> <li> <p> <b>Amazon Simple Queue Service</b> - Default 10. For standard queues the max is 10,000. For FIFO queues the max is 10.</p> </li> <li> <p> <b>Amazon Managed Streaming for Apache Kafka</b> - Default 100. Max 10,000.</p> </li> <li> <p> <b>Self-Managed Apache Kafka</b> - Default 100. Max 10,000.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int batchSize;

    /**
    *  <p>(Streams and SQS standard queues) The maximum amount of time to gather records before invoking the function, in seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumBatchingWindowInSeconds;

    /**
    *  <p>(Streams) An Amazon SQS queue or Amazon SNS topic destination for discarded records.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FDestinationConfig destinationConfig;

    /**
    *  <p>(Streams) Discard records older than the specified age. The default value is infinite (-1).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRecordAgeInSeconds;

    /**
    *  <p>(Streams) If the function returns an error, split the batch in two and retry.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool bisectBatchOnFunctionError;

    /**
    *  <p>(Streams) Discard records after the specified number of retries. The default value is infinite (-1). When set to infinite (-1), failed records will be retried until the record expires.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int maximumRetryAttempts;

    /**
    *  <p>(Streams) The number of batches to process from each shard concurrently.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int parallelizationFactor;

    /**
    *  <p>An array of the authentication protocol, or the VPC components to secure your event source.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAWSLambdaSourceAccessConfiguration> sourceAccessConfigurations;

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
    Aws::Lambda::Model::UpdateEventSourceMappingRequest toAWS() const {
        Aws::Lambda::Model::UpdateEventSourceMappingRequest awsUpdateEventSourceMappingRequest;

		if (!(this->UUID.IsEmpty())) {
            awsUpdateEventSourceMappingRequest.SetUUID(TCHAR_TO_UTF8(*this->UUID));
        }

		if (!(this->functionName.IsEmpty())) {
            awsUpdateEventSourceMappingRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		awsUpdateEventSourceMappingRequest.SetEnabled(this->enabled);

        if (this->batchSize != 0) {
            awsUpdateEventSourceMappingRequest.SetBatchSize(this->batchSize);
        }

        if (this->maximumBatchingWindowInSeconds != 0) {
            awsUpdateEventSourceMappingRequest.SetMaximumBatchingWindowInSeconds(this->maximumBatchingWindowInSeconds);
        }

        if (!(this->destinationConfig.IsEmpty())) {
            awsUpdateEventSourceMappingRequest.SetDestinationConfig(this->destinationConfig.toAWS());
        }

        if (!(this->maximumRecordAgeInSeconds == 0)) {
            awsUpdateEventSourceMappingRequest.SetMaximumRecordAgeInSeconds(this->maximumRecordAgeInSeconds);
        }

        if (!(false)) {
            awsUpdateEventSourceMappingRequest.SetBisectBatchOnFunctionError(this->bisectBatchOnFunctionError);
        }

        if (!(this->maximumRetryAttempts == 0)) {
            awsUpdateEventSourceMappingRequest.SetMaximumRetryAttempts(this->maximumRetryAttempts);
        }

        if (!(this->parallelizationFactor == 0)) {
            awsUpdateEventSourceMappingRequest.SetParallelizationFactor(this->parallelizationFactor);
        }

        for (const FAWSLambdaSourceAccessConfiguration& elem : this->sourceAccessConfigurations) {
            awsUpdateEventSourceMappingRequest.AddSourceAccessConfigurations(elem.toAWS());
        }

        if (!(this->tumblingWindowInSeconds == 0)) {
            awsUpdateEventSourceMappingRequest.SetTumblingWindowInSeconds(this->tumblingWindowInSeconds);
        }

        for (const EAWSLambdaFunctionResponseType& elem : this->functionResponseTypes) {
		    switch(elem) {
                case EAWSLambdaFunctionResponseType::ReportBatchItemFailures:
                    awsUpdateEventSourceMappingRequest.AddFunctionResponseTypes(Aws::Lambda::Model::FunctionResponseType::ReportBatchItemFailures);
                    break;
            default:
                break;
            };
        }

        return awsUpdateEventSourceMappingRequest;
    }

    bool IsEmpty() const {
        return this->UUID.IsEmpty() && this->functionName.IsEmpty() && false && this->batchSize == 0 && this->maximumBatchingWindowInSeconds == 0 && this->destinationConfig.IsEmpty() && this->maximumRecordAgeInSeconds == 0 && false && this->maximumRetryAttempts == 0 && this->parallelizationFactor == 0 && this->sourceAccessConfigurations.Num() == 0 && this->tumblingWindowInSeconds == 0 && this->functionResponseTypes.Num() == 0;
    }
#endif
};
