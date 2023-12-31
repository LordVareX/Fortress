/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ScanRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/Select.h"
#include "Model/DynamoDBCondition.h"
#include "Model/ConditionalOperator.h"
#include "Model/ReturnConsumedCapacity.h"

#include "ScanRequest.generated.h"

USTRUCT(BlueprintType)
struct FScanRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table containing the requested items; or, if you provide <code>IndexName</code>, the name of the table to which that index belongs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The name of a secondary index to scan. This index can be any local secondary index or global secondary index. Note that if you use the <code>IndexName</code> parameter, you must also provide <code>TableName</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>This is a legacy parameter. Use <code>ProjectionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.AttributesToGet.html">AttributesToGet</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> attributesToGet;*/

    /**
    *  <p>The maximum number of items to evaluate (not necessarily the number of matching items). If DynamoDB processes the number of items up to the limit while processing the results, it stops the operation and returns the matching values up to that point, and a key in <code>LastEvaluatedKey</code> to apply in a subsequent operation, so that you can pick up where you left off. Also, if the processed dataset size exceeds 1 MB before DynamoDB reaches this limit, it stops the operation and returns the matching values up to the limit, and a key in <code>LastEvaluatedKey</code> to apply in a subsequent operation to continue the operation. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/QueryAndScan.html">Working with Queries</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int limit;

    /**
    *  <p>The attributes to be returned in the result. You can retrieve all item attributes, specific item attributes, the count of matching items, or in the case of an index, some or all of the attributes projected into the index.</p> <ul> <li> <p> <code>ALL_ATTRIBUTES</code> - Returns all of the item attributes from the specified table or index. If you query a local secondary index, then for each matching item in the index, DynamoDB fetches the entire item from the parent table. If the index is configured to project all item attributes, then all of the data can be obtained from the local secondary index, and no fetching is required.</p> </li> <li> <p> <code>ALL_PROJECTED_ATTRIBUTES</code> - Allowed only when querying an index. Retrieves all attributes that have been projected into the index. If the index is configured to project all attributes, this return value is equivalent to specifying <code>ALL_ATTRIBUTES</code>.</p> </li> <li> <p> <code>COUNT</code> - Returns the number of matching items, rather than the matching items themselves.</p> </li> <li> <p> <code>SPECIFIC_ATTRIBUTES</code> - Returns only the attributes listed in <code>AttributesToGet</code>. This return value is equivalent to specifying <code>AttributesToGet</code> without specifying any value for <code>Select</code>.</p> <p>If you query or scan a local secondary index and request only attributes that are projected into that index, the operation reads only the index and not the table. If any of the requested attributes are not projected into the local secondary index, DynamoDB fetches each of these attributes from the parent table. This extra fetching incurs additional throughput cost and latency.</p> <p>If you query or scan a global secondary index, you can only request attributes that are projected into the index. Global secondary index queries cannot fetch attributes from the parent table.</p> </li> </ul> <p>If neither <code>Select</code> nor <code>AttributesToGet</code> are specified, DynamoDB defaults to <code>ALL_ATTRIBUTES</code> when accessing a table, and <code>ALL_PROJECTED_ATTRIBUTES</code> when accessing an index. You cannot use both <code>Select</code> and <code>AttributesToGet</code> together in a single request, unless the value for <code>Select</code> is <code>SPECIFIC_ATTRIBUTES</code>. (This usage is equivalent to specifying <code>AttributesToGet</code> without any value for <code>Select</code>.)</p> <note> <p>If you use the <code>ProjectionExpression</code> parameter, then the value for <code>Select</code> can only be <code>SPECIFIC_ATTRIBUTES</code>. Any other value for <code>Select</code> will return an error.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSSelect select;

    /**
    *  <p>This is a legacy parameter. Use <code>FilterExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.ScanFilter.html">ScanFilter</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FCondition> scanFilter;*/

    /**
    *  <p>This is a legacy parameter. Use <code>FilterExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.ConditionalOperator.html">ConditionalOperator</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSConditionalOperator conditionalOperator;*/

    /**
    *  <p>The primary key of the first item that this operation will evaluate. Use the value that was returned for <code>LastEvaluatedKey</code> in the previous operation.</p> <p>The data type for <code>ExclusiveStartKey</code> must be String, Number or Binary. No set data types are allowed.</p> <p>In a parallel scan, a <code>Scan</code> request that includes <code>ExclusiveStartKey</code> must specify the same segment whose previous <code>Scan</code> returned the corresponding value of <code>LastEvaluatedKey</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> exclusiveStartKey;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity;

    /**
    *  <p>For a parallel <code>Scan</code> request, <code>TotalSegments</code> represents the total number of segments into which the <code>Scan</code> operation will be divided. The value of <code>TotalSegments</code> corresponds to the number of application workers that will perform the parallel scan. For example, if you want to use four application threads to scan a table or an index, specify a <code>TotalSegments</code> value of 4.</p> <p>The value for <code>TotalSegments</code> must be greater than or equal to 1, and less than or equal to 1000000. If you specify a <code>TotalSegments</code> value of 1, the <code>Scan</code> operation will be sequential rather than parallel.</p> <p>If you specify <code>TotalSegments</code>, you must also specify <code>Segment</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int totalSegments;

    /**
    *  <p>For a parallel <code>Scan</code> request, <code>Segment</code> identifies an individual segment to be scanned by an application worker.</p> <p>Segment IDs are zero-based, so the first segment is always 0. For example, if you want to use four application threads to scan a table or an index, then the first thread specifies a <code>Segment</code> value of 0, the second thread specifies 1, and so on.</p> <p>The value of <code>LastEvaluatedKey</code> returned from a parallel <code>Scan</code> request must be used as <code>ExclusiveStartKey</code> with the same segment ID in a subsequent <code>Scan</code> operation.</p> <p>The value for <code>Segment</code> must be greater than or equal to 0, and less than the value provided for <code>TotalSegments</code>.</p> <p>If you provide <code>Segment</code>, you must also provide <code>TotalSegments</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int segment;

    /**
    *  <p>A string that identifies one or more attributes to retrieve from the specified table or index. These attributes can include scalars, sets, or elements of a JSON document. The attributes in the expression must be separated by commas.</p> <p>If no attribute names are specified, then all attributes will be returned. If any of the requested attributes are not found, they will not appear in the result.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Specifying Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString projectionExpression;

    /**
    *  <p>A string that contains conditions that DynamoDB applies after the <code>Scan</code> operation, but before the data is returned to you. Items that do not satisfy the <code>FilterExpression</code> criteria are not returned.</p> <note> <p>A <code>FilterExpression</code> is applied after the items have already been read; the process of filtering does not consume any additional read capacity units.</p> </note> <p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/QueryAndScan.html#FilteringResults">Filter Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString filterExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in an expression. The following are some use cases for using <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p>To access an attribute whose name conflicts with a DynamoDB reserved word.</p> </li> <li> <p>To create a placeholder for repeating occurrences of an attribute name in an expression.</p> </li> <li> <p>To prevent special characters in an attribute name from being misinterpreted in an expression.</p> </li> </ul> <p>Use the <b>#</b> character in an expression to dereference an attribute name. For example, consider the following attribute name:</p> <ul> <li> <p> <code>Percentile</code> </p> </li> </ul> <p>The name of this attribute conflicts with a reserved word, so it cannot be used directly in an expression. (For the complete list of reserved words, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ReservedWords.html">Reserved Words</a> in the <i>Amazon DynamoDB Developer Guide</i>). To work around this, you could specify the following for <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p> <code>{"#P":"Percentile"}</code> </p> </li> </ul> <p>You could then use this substitution in an expression, as in this example:</p> <ul> <li> <p> <code>#P = :val</code> </p> </li> </ul> <note> <p>Tokens that begin with the <b>:</b> character are <i>expression attribute values</i>, which are placeholders for the actual value at runtime.</p> </note> <p>For more information on expression attribute names, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Specifying Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

    /**
    *  <p>One or more values that can be substituted in an expression.</p> <p>Use the <b>:</b> (colon) character in an expression to dereference an attribute value. For example, suppose that you wanted to check whether the value of the <code>ProductStatus</code> attribute was one of the following: </p> <p> <code>Available | Backordered | Discontinued</code> </p> <p>You would first need to specify <code>ExpressionAttributeValues</code> as follows:</p> <p> <code>{ ":avail":{"S":"Available"}, ":back":{"S":"Backordered"}, ":disc":{"S":"Discontinued"} }</code> </p> <p>You could then use these values in an expression, such as this:</p> <p> <code>ProductStatus IN (:avail, :back, :disc)</code> </p> <p>For more information on expression attribute values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.SpecifyingConditions.html">Condition Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> expressionAttributeValues;

    /**
    *  <p>A Boolean value that determines the read consistency model during the scan:</p> <ul> <li> <p>If <code>ConsistentRead</code> is <code>false</code>, then the data returned from <code>Scan</code> might not contain the results from other recently completed write operations (<code>PutItem</code>, <code>UpdateItem</code>, or <code>DeleteItem</code>).</p> </li> <li> <p>If <code>ConsistentRead</code> is <code>true</code>, then all of the write operations that completed before the <code>Scan</code> began are guaranteed to be contained in the <code>Scan</code> response.</p> </li> </ul> <p>The default setting for <code>ConsistentRead</code> is <code>false</code>.</p> <p>The <code>ConsistentRead</code> parameter is not supported on global secondary indexes. If you scan a global secondary index with <code>ConsistentRead</code> set to true, you will receive a <code>ValidationException</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool consistentRead;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ScanRequest toAWS() const {
        Aws::DynamoDB::Model::ScanRequest awsScanRequest;

		if (!(this->tableName.IsEmpty())) {
            awsScanRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->indexName.IsEmpty())) {
            awsScanRequest.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        /*for (const FString& elem : this->attributesToGet) {
            awsScanRequest.AddAttributesToGet(TCHAR_TO_UTF8(*elem));
        }*/

        if (this->limit != 0) {
            awsScanRequest.SetLimit(this->limit);
        }

        switch(this->select) {
            case EAWSSelect::ALL_ATTRIBUTES:
                awsScanRequest.SetSelect(Aws::DynamoDB::Model::Select::ALL_ATTRIBUTES);
                break;
            case EAWSSelect::ALL_PROJECTED_ATTRIBUTES:
                awsScanRequest.SetSelect(Aws::DynamoDB::Model::Select::ALL_PROJECTED_ATTRIBUTES);
                break;
            case EAWSSelect::SPECIFIC_ATTRIBUTES:
                awsScanRequest.SetSelect(Aws::DynamoDB::Model::Select::SPECIFIC_ATTRIBUTES);
                break;
            case EAWSSelect::COUNT:
                awsScanRequest.SetSelect(Aws::DynamoDB::Model::Select::COUNT);
                break;
            default:
                break;
        }

        /*for (const TPair<FString, FCondition>& elem : this->scanFilter) {
            awsScanRequest.AddScanFilter(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }*/

        /*switch(this->conditionalOperator) {
            case EAWSConditionalOperator::AND:
                awsScanRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::AND);
                break;
            case EAWSConditionalOperator::OR:
                awsScanRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::OR);
                break;
            default:
                break;
        }*/

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->exclusiveStartKey) {
            awsScanRequest.AddExclusiveStartKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsScanRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsScanRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsScanRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
            }

        if (this->totalSegments != 0) {
            awsScanRequest.SetTotalSegments(this->totalSegments);
        }

        if (this->segment != 0) {
            awsScanRequest.SetSegment(this->segment);
        }

		if (!(this->projectionExpression.IsEmpty())) {
            awsScanRequest.SetProjectionExpression(TCHAR_TO_UTF8(*this->projectionExpression));
        }

		if (!(this->filterExpression.IsEmpty())) {
            awsScanRequest.SetFilterExpression(TCHAR_TO_UTF8(*this->filterExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsScanRequest.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsScanRequest.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        awsScanRequest.SetConsistentRead(this->consistentRead);

        return awsScanRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->indexName.IsEmpty() && /*this->attributesToGet.Num() == 0 && */this->limit == 0 && this->select == EAWSSelect::NOT_SET && /*this->scanFilter.Num() == 0 && *//*this->conditionalOperator == EAWSConditionalOperator::NOT_SET && */this->exclusiveStartKey.Num() == 0 && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->totalSegments == 0 && this->segment == 0 && this->projectionExpression.IsEmpty() && this->filterExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0 && false;
    }
#endif
};
