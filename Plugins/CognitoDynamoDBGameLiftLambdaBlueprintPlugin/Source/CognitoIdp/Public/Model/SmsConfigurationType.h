/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SmsConfigurationType.h"

#endif

#include "SmsConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FSmsConfigurationType {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon Simple Notification Service (SNS) caller.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString snsCallerArn;

    /**
    *  <p>The external ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString externalId;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SmsConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SmsConfigurationType awsSmsConfigurationType;

        if (!(this->snsCallerArn.IsEmpty())) {
            awsSmsConfigurationType.SetSnsCallerArn(TCHAR_TO_UTF8(*this->snsCallerArn));
        }

        if (!(this->externalId.IsEmpty())) {
            awsSmsConfigurationType.SetExternalId(TCHAR_TO_UTF8(*this->externalId));
        }

        return awsSmsConfigurationType;
    }

    bool IsEmpty() const {
        return this->snsCallerArn.IsEmpty() && this->externalId.IsEmpty();
    }

    FSmsConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::SmsConfigurationType &awsSmsConfigurationType) {
        this->snsCallerArn = UTF8_TO_TCHAR(awsSmsConfigurationType.GetSnsCallerArn().c_str());

        this->externalId = UTF8_TO_TCHAR(awsSmsConfigurationType.GetExternalId().c_str());

        return *this;
    }
#endif
};
