/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchExecuteStatementRequest.h"

#endif

#include "Model/AWSDynamoDBBatchStatementRequest.h"

#include "AWSDynamoDBBatchExecuteStatementRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchExecuteStatementRequest {
GENERATED_BODY()

    /**
    *  <p> The list of PartiQL statements representing the batch to run. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBBatchStatementRequest> statements;
    
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::BatchExecuteStatementRequest toAWS() const {
        Aws::DynamoDB::Model::BatchExecuteStatementRequest awsBatchExecuteStatementRequest;

        for (const FAWSDynamoDBBatchStatementRequest& elem : this->statements) {
            awsBatchExecuteStatementRequest.AddStatements(elem.toAWS());
        }

        return awsBatchExecuteStatementRequest;
    }

    bool IsEmpty() const {
        return this->statements.Num() == 0;
    }
#endif
};
