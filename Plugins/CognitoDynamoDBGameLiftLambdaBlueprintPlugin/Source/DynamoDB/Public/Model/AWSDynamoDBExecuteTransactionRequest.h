/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteTransactionRequest.h"

#endif

#include "Model/AWSDynamoDBParameterizedStatement.h"

#include "AWSDynamoDBExecuteTransactionRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteTransactionRequest {
GENERATED_BODY()

    /**
    *  <p> The list of PartiQL statements representing the transaction to run. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBParameterizedStatement> transactStatements;
    /**
    *  <p> Set this value to get remaining results, if <code>NextToken</code> was returned in the statement response. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientRequestToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ExecuteTransactionRequest toAWS() const {
        Aws::DynamoDB::Model::ExecuteTransactionRequest awsExecuteTransactionRequest;

        for (const FAWSDynamoDBParameterizedStatement& elem : this->transactStatements) {
            awsExecuteTransactionRequest.AddTransactStatements(elem.toAWS());
        }

        if (!(this->clientRequestToken.IsEmpty())) {
            awsExecuteTransactionRequest.SetClientRequestToken(TCHAR_TO_UTF8(*this->clientRequestToken));
        }
        return awsExecuteTransactionRequest;
    }

    bool IsEmpty() const {
        return this->transactStatements.Num() == 0 && this->clientRequestToken.IsEmpty();
    }
#endif
};
