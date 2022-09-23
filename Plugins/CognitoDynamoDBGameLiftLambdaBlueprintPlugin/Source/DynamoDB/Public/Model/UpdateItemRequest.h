/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateItemRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/AttributeValueUpdate.h"
#include "Model/ExpectedAttributeValue.h"
#include "Model/ConditionalOperator.h"
#include "Model/ReturnValue.h"
#include "Model/ReturnConsumedCapacity.h"
#include "Model/ReturnItemCollectionMetrics.h"

#include "UpdateItemRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateItemRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table containing the item to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;


    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValue returnValues;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity;

    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnItemCollectionMetrics returnItemCollectionMetrics;

    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString updateExpression;

    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString conditionExpression;

    /**
    *  
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

    /**
    *     
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> expressionAttributeValues;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateItemRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateItemRequest awsUpdateItemRequest;

		if (!(this->tableName.IsEmpty())) {
            awsUpdateItemRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsUpdateItemRequest.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        /*for (const TPair<FString, FAttributeValueUpdate>& elem : this->attributeUpdates) {
            awsUpdateItemRequest.AddAttributeUpdates(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }*/

        /*for (const TPair<FString, FExpectedAttributeValue>& elem : this->expected) {
            awsUpdateItemRequest.AddExpected(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }*/

        /*switch(this->conditionalOperator) {
            case EAWSConditionalOperator::AND:
                awsUpdateItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::AND);
                break;
            case EAWSConditionalOperator::OR:
                awsUpdateItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::OR);
                break;
            default:
                break;
        }*/

        switch(this->returnValues) {
            case EAWSReturnValue::NONE:
                awsUpdateItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::NONE);
                break;
            case EAWSReturnValue::ALL_OLD:
                awsUpdateItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_OLD);
                break;
            case EAWSReturnValue::UPDATED_OLD:
                awsUpdateItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_OLD);
                break;
            case EAWSReturnValue::ALL_NEW:
                awsUpdateItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_NEW);
                break;
            case EAWSReturnValue::UPDATED_NEW:
                awsUpdateItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_NEW);
                break;
            default:
                break;
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsUpdateItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsUpdateItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsUpdateItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
        }

        switch(this->returnItemCollectionMetrics) {
            case EAWSReturnItemCollectionMetrics::SIZE:
                awsUpdateItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::SIZE);
                break;
            case EAWSReturnItemCollectionMetrics::NONE:
                awsUpdateItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::NONE);
                break;
            default:
                break;
        }

		if (!(this->updateExpression.IsEmpty())) {
            awsUpdateItemRequest.SetUpdateExpression(TCHAR_TO_UTF8(*this->updateExpression));
        }

		if (!(this->conditionExpression.IsEmpty())) {
            awsUpdateItemRequest.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsUpdateItemRequest.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsUpdateItemRequest.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsUpdateItemRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->key.Num() == 0 && /*this->attributeUpdates.Num() == 0 && *//*this->expected.Num() == 0 && *//*this->conditionalOperator == EAWSConditionalOperator::NOT_SET && */this->returnValues == EAWSReturnValue::NOT_SET && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->returnItemCollectionMetrics == EAWSReturnItemCollectionMetrics::NOT_SET && this->updateExpression.IsEmpty() && this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0;
    }
#endif
};
