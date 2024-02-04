/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserContextDataType.h"

#endif

#include "UserContextDataType.generated.h"

USTRUCT(BlueprintType)
struct FUserContextDataType {
GENERATED_BODY()

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString encodedData;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UserContextDataType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UserContextDataType awsUserContextDataType;

        if (!(this->encodedData.IsEmpty())) {
            awsUserContextDataType.SetEncodedData(TCHAR_TO_UTF8(*this->encodedData));
        }

        return awsUserContextDataType;
    }

    bool IsEmpty() const {
        return this->encodedData.IsEmpty();
    }
#endif
};
