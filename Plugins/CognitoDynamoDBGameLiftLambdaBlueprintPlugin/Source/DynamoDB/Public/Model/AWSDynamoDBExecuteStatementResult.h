/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ExecuteStatementResult.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "AWSDynamoDBExecuteStatementResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBExecuteStatementResult {
GENERATED_BODY()

    /**
    *  <p> If a read operation was used, this property will contain the result of the reade operation; a map of attribute names and their values. For the write operations this value will be empty. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> items;
    /**
    *  <p> If the response of a read request exceeds the response payload limit DynamoDB will set this value in the response. If set, you can use that this value in the subsequent request to get the remaining results. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBExecuteStatementResult &fromAWS(const Aws::DynamoDB::Model::ExecuteStatementResult &awsExecuteStatementResult) {
        {
            Aws::Utils::Array<Aws::Utils::Json::JsonValue> jsonArray1(awsExecuteStatementResult.GetItems().size());
            int i = 0;
            for (const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& elem1 : awsExecuteStatementResult.GetItems()) {
                Aws::Utils::Json::JsonValue jsonValue2;
                for (const auto& elem2 : elem1) {
                    Aws::Utils::Json::JsonValue jsonValue3 = elem2.second.Jsonize();
                    jsonValue2.WithObject(elem2.first, jsonValue3);
                }
                jsonArray1[i++] = jsonValue2;
            }
            this->items.Empty();
            for (int j = 0; j < jsonArray1.GetLength(); j++) {
                this->items.Add(UTF8_TO_TCHAR(jsonArray1[j].View().WriteReadable().c_str()));
            }
        }

        this->nextToken = UTF8_TO_TCHAR(awsExecuteStatementResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
