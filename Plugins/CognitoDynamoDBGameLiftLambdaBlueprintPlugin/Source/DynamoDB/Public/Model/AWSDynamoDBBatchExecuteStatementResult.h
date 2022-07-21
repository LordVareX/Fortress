/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchExecuteStatementResult.h"

#endif

#include "Model/AWSDynamoDBBatchStatementResponse.h"

#include "AWSDynamoDBBatchExecuteStatementResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchExecuteStatementResult {
GENERATED_BODY()
    /**
    *  <p> The response to each PartiQL statement in the batch. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBBatchStatementResponse> responses;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBBatchExecuteStatementResult &fromAWS(const Aws::DynamoDB::Model::BatchExecuteStatementResult &awsBatchExecuteStatementResult) {
        this->responses.Empty();
        for (const Aws::DynamoDB::Model::BatchStatementResponse& elem : awsBatchExecuteStatementResult.GetResponses()) {
            this->responses.Add(FAWSDynamoDBBatchStatementResponse().fromAWS(elem));
        }

        return *this;
    }
#endif
};
