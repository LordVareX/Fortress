/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteItemRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ExpectedAttributeValue.h"
#include "Model/ConditionalOperator.h"
#include "Model/ReturnValue.h"
#include "Model/ReturnConsumedCapacity.h"
#include "Model/ReturnItemCollectionMetrics.h"

#include "DeleteItemRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteItemRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table from which to delete the item.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>A map of attribute names to <code>AttributeValue</code> objects, representing the primary key of the item to delete.</p> <p>For the primary key, you must provide all of the attributes. For example, with a simple primary key, you only need to provide a value for the partition key. For a composite primary key, you must provide values for both the partition key and the sort key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;

    /**
    *  <p>This is a legacy parameter. Use <code>ConditionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.Expected.html">Expected</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FExpectedAttributeValue> expected;*/

    /**
    *  <p>This is a legacy parameter. Use <code>ConditionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.ConditionalOperator.html">ConditionalOperator</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSConditionalOperator conditionalOperator;*/

    /**
    *  <p>Use <code>ReturnValues</code> if you want to get the item attributes as they appeared before they were deleted. For <code>DeleteItem</code>, the valid values are:</p> <ul> <li> <p> <code>NONE</code> - If <code>ReturnValues</code> is not specified, or if its value is <code>NONE</code>, then nothing is returned. (This setting is the default for <code>ReturnValues</code>.)</p> </li> <li> <p> <code>ALL_OLD</code> - The content of the old item is returned.</p> </li> </ul> <note> <p>The <code>ReturnValues</code> parameter is used by several DynamoDB operations; however, <code>DeleteItem</code> does not recognize any values other than <code>NONE</code> or <code>ALL_OLD</code>.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValue returnValues;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity;

    /**
    *  <p>Determines whether item collection metrics are returned. If set to <code>SIZE</code>, the response includes statistics about item collections, if any, that were modified during the operation are returned in the response. If set to <code>NONE</code> (the default), no statistics are returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnItemCollectionMetrics returnItemCollectionMetrics;

    /**
    *  <p>A condition that must be satisfied in order for a conditional <code>DeleteItem</code> to succeed.</p> <p>An expression can contain any of the following:</p> <ul> <li> <p>Functions: <code>attribute_exists | attribute_not_exists | attribute_type | contains | begins_with | size</code> </p> <p>These function names are case-sensitive.</p> </li> <li> <p>Comparison operators: <code>= | &lt;&gt; | &lt; | &gt; | &lt;= | &gt;= | BETWEEN | IN </code> </p> </li> <li> <p> Logical operators: <code>AND | OR | NOT</code> </p> </li> </ul> <p>For more information about condition expressions, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.SpecifyingConditions.html">Condition Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString conditionExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in an expression. The following are some use cases for using <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p>To access an attribute whose name conflicts with a DynamoDB reserved word.</p> </li> <li> <p>To create a placeholder for repeating occurrences of an attribute name in an expression.</p> </li> <li> <p>To prevent special characters in an attribute name from being misinterpreted in an expression.</p> </li> </ul> <p>Use the <b>#</b> character in an expression to dereference an attribute name. For example, consider the following attribute name:</p> <ul> <li> <p> <code>Percentile</code> </p> </li> </ul> <p>The name of this attribute conflicts with a reserved word, so it cannot be used directly in an expression. (For the complete list of reserved words, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ReservedWords.html">Reserved Words</a> in the <i>Amazon DynamoDB Developer Guide</i>). To work around this, you could specify the following for <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p> <code>{"#P":"Percentile"}</code> </p> </li> </ul> <p>You could then use this substitution in an expression, as in this example:</p> <ul> <li> <p> <code>#P = :val</code> </p> </li> </ul> <note> <p>Tokens that begin with the <b>:</b> character are <i>expression attribute values</i>, which are placeholders for the actual value at runtime.</p> </note> <p>For more information on expression attribute names, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Specifying Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

    /**
    *  <p>One or more values that can be substituted in an expression.</p> <p>Use the <b>:</b> (colon) character in an expression to dereference an attribute value. For example, suppose that you wanted to check whether the value of the <i>ProductStatus</i> attribute was one of the following: </p> <p> <code>Available | Backordered | Discontinued</code> </p> <p>You would first need to specify <code>ExpressionAttributeValues</code> as follows:</p> <p> <code>{ ":avail":{"S":"Available"}, ":back":{"S":"Backordered"}, ":disc":{"S":"Discontinued"} }</code> </p> <p>You could then use these values in an expression, such as this:</p> <p> <code>ProductStatus IN (:avail, :back, :disc)</code> </p> <p>For more information on expression attribute values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.SpecifyingConditions.html">Condition Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> expressionAttributeValues;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteItemRequest toAWS() const {
        Aws::DynamoDB::Model::DeleteItemRequest awsDeleteItemRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDeleteItemRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsDeleteItemRequest.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        /*for (const TPair<FString, FExpectedAttributeValue>& elem : this->expected) {
            awsDeleteItemRequest.AddExpected(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }*/

        /*switch(this->conditionalOperator) {
            case EAWSConditionalOperator::AND:
                awsDeleteItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::AND);
                break;
            case EAWSConditionalOperator::OR:
                awsDeleteItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::OR);
                break;
            default:
                break;
        }*/

        switch(this->returnValues) {
            case EAWSReturnValue::NONE:
                awsDeleteItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::NONE);
                break;
            case EAWSReturnValue::ALL_OLD:
                awsDeleteItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_OLD);
                break;
            case EAWSReturnValue::UPDATED_OLD:
                awsDeleteItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_OLD);
                break;
            case EAWSReturnValue::ALL_NEW:
                awsDeleteItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_NEW);
                break;
            case EAWSReturnValue::UPDATED_NEW:
                awsDeleteItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_NEW);
                break;
            default:
                break;
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsDeleteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsDeleteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsDeleteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
        }

        switch(this->returnItemCollectionMetrics) {
            case EAWSReturnItemCollectionMetrics::SIZE:
                awsDeleteItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::SIZE);
                break;
            case EAWSReturnItemCollectionMetrics::NONE:
                awsDeleteItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::NONE);
                break;
            default:
                break;
        }

		if (!(this->conditionExpression.IsEmpty())) {
            awsDeleteItemRequest.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsDeleteItemRequest.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsDeleteItemRequest.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsDeleteItemRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->key.Num() == 0 && /*this->expected.Num() == 0 && *//*this->conditionalOperator == EAWSConditionalOperator::NOT_SET && */this->returnValues == EAWSReturnValue::NOT_SET && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->returnItemCollectionMetrics == EAWSReturnItemCollectionMetrics::NOT_SET && this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0;
    }
#endif
};
