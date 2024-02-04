/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeMatchmakingRuleSetsRequest.h"

#endif

#include "DescribeMatchmakingRuleSetsRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeMatchmakingRuleSetsRequest {
GENERATED_BODY()

    /**
    *  <p>List of one or more matchmaking rule set names to retrieve details for. (Note: The rule set name is different from the optional "name" field in the rule set body.) </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FString> names;

    /**
    *  <p>Maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit;

    /**
    *  <p>Token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this action. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeMatchmakingRuleSetsRequest toAWS() const {
        Aws::GameLift::Model::DescribeMatchmakingRuleSetsRequest awsDescribeMatchmakingRuleSetsRequest;

        for (const FString& elem : this->names) {
            awsDescribeMatchmakingRuleSetsRequest.AddNames(TCHAR_TO_UTF8(*elem));
        }

        if (this->limit != 0) {
            awsDescribeMatchmakingRuleSetsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsDescribeMatchmakingRuleSetsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsDescribeMatchmakingRuleSetsRequest;
    }

    bool IsEmpty() const {
        return this->names.Num() == 0 && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
