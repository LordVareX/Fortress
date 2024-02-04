/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteStatementRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "AWSDynamoDBExecuteStatementRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteStatementRequest {
GENERATED_BODY()
    /**
    *  <p> The PartiQL statement representing the operation to run. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString statement;
    /**
    *  <p> The parameters for the PartiQL statement, if any. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBAttributeValue> parameters;
    /**
    *  <p> The consistency of a read operation. If set to <code>true</code>, then a strongly consistent read is used; otherwise, an eventually consistent read is used. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool consistentRead;
    /**
    *  <p> Set this value to get remaining results, if <code>NextToken</code> was returned in the statement response. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ExecuteStatementRequest toAWS() const {
        Aws::DynamoDB::Model::ExecuteStatementRequest awsExecuteStatementRequest;

        if (!(this->statement.IsEmpty())) {
            awsExecuteStatementRequest.SetStatement(TCHAR_TO_UTF8(*this->statement));
        }

        for (const FDynamoDBAttributeValue& elem : this->parameters) {
            awsExecuteStatementRequest.AddParameters(elem.toAWS());
        }

        if (!(false)) {
            awsExecuteStatementRequest.SetConsistentRead(this->consistentRead);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsExecuteStatementRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsExecuteStatementRequest;
    }

    bool IsEmpty() const {
        return this->statement.IsEmpty() && this->parameters.Num() == 0 && false && this->nextToken.IsEmpty();
    }
#endif
};
