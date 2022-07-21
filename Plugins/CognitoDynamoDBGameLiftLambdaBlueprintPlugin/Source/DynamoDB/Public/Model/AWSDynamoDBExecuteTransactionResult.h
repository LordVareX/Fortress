/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteTransactionResult.h"

#endif

#include "Model/ItemResponse.h"

#include "AWSDynamoDBExecuteTransactionResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteTransactionResult {
GENERATED_BODY()

    /**
    *  <p> The response to a PartiQL transaction. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FItemResponse> responses;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExecuteTransactionResult &fromAWS(const Aws::DynamoDB::Model::ExecuteTransactionResult &awsExecuteTransactionResult) {
        this->responses.Empty();
        for (const Aws::DynamoDB::Model::ItemResponse& elem : awsExecuteTransactionResult.GetResponses()) {
            this->responses.Add(FItemResponse().fromAWS(elem));
        }

        return *this;
    }
#endif
};
