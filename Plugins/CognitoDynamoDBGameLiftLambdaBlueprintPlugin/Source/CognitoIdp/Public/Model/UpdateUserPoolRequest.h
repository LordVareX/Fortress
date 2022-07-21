/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolRequest.h"

#endif

#include "Model/UserPoolPolicyType.h"
#include "Model/LambdaConfigType.h"
#include "Model/VerifiedAttributeType.h"
#include "Model/VerificationMessageTemplateType.h"
#include "Model/UserPoolMfaType.h"
#include "Model/DeviceConfigurationType.h"
#include "Model/EmailConfigurationType.h"
#include "Model/SmsConfigurationType.h"
#include "Model/AdminCreateUserConfigType.h"
#include "Model/UserPoolAddOnsType.h"
#include "Model/AccountRecoverySettingType.h"

#include "UpdateUserPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool you want to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>A container with the policies you wish to update in a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolPolicyType policies;

    /**
    *  <p>The AWS Lambda configuration information from the request to update the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FLambdaConfigType lambdaConfig;

    /**
    *  <p>The attributes that are automatically verified when the Amazon Cognito service makes a request to update user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EVerifiedAttributeType> autoVerifiedAttributes;

    /**
    *  <p>A container with information about the SMS verification message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsVerificationMessage;

    /**
    *  <p>The contents of the email verification message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationMessage;

    /**
    *  <p>The subject of the email verification message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationSubject;

    /**
    *  <p>The template for verification messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FVerificationMessageTemplateType verificationMessageTemplate;

    /**
    *  <p>The contents of the SMS authentication message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsAuthenticationMessage;

    /**
    *  <p>Can be one of the following values:</p> <ul> <li> <p> <code>OFF</code> - MFA tokens are not required and cannot be specified during user registration.</p> </li> <li> <p> <code>ON</code> - MFA tokens are required for all user registrations. You can only specify required when you are initially creating a user pool.</p> </li> <li> <p> <code>OPTIONAL</code> - Users have the option when registering to create an MFA token.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration;

    /**
    *  <p>Device configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceConfigurationType deviceConfiguration;

    /**
    *  <p>Email configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEmailConfigurationType emailConfiguration;

    /**
    *  <p>SMS configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsConfigurationType smsConfiguration;

    /**
    *  <p>The tag keys and values to assign to the user pool. A tag is a label that you can use to categorize and manage user pools in different ways, such as by purpose, owner, environment, or other criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> userPoolTags;

    /**
    *  <p>The configuration for <code>AdminCreateUser</code> requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAdminCreateUserConfigType adminCreateUserConfig;

    /**
    *  <p>Used to enable advanced security risk detection. Set the key <code>AdvancedSecurityMode</code> to the value "AUDIT".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolAddOnsType userPoolAddOns;

    /**
    *  <p>Use this setting to define which verified available method a user can use to recover their password when they call <code>ForgotPassword</code>. It allows you to define a preferred method when a user has more than one method available. With this setting, SMS does not qualify for a valid password recovery mechanism if the user also has SMS MFA enabled. In the absence of this setting, Cognito uses the legacy behavior to determine the recovery method where SMS is preferred over email.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountRecoverySettingType accountRecoverySetting;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateUserPoolRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateUserPoolRequest awsUpdateUserPoolRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateUserPoolRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->policies.IsEmpty())) {
            awsUpdateUserPoolRequest.SetPolicies(this->policies.toAWS());
        }

        if (!(this->lambdaConfig.IsEmpty())) {
            awsUpdateUserPoolRequest.SetLambdaConfig(this->lambdaConfig.toAWS());
        }

        for (const EVerifiedAttributeType& elem : this->autoVerifiedAttributes) {
            switch(elem) {
                case EVerifiedAttributeType::phone_number:
                    awsUpdateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number);
                    break;
                case EVerifiedAttributeType::email:
                    awsUpdateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email);
                    break;
                default:
                    break;
            };
        }

        if (!(this->smsVerificationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsVerificationMessage(TCHAR_TO_UTF8(*this->smsVerificationMessage));
        }

        if (!(this->emailVerificationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailVerificationMessage(TCHAR_TO_UTF8(*this->emailVerificationMessage));
        }

        if (!(this->emailVerificationSubject.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailVerificationSubject(TCHAR_TO_UTF8(*this->emailVerificationSubject));
        }

        if (!(this->verificationMessageTemplate.IsEmpty())) {
            awsUpdateUserPoolRequest.SetVerificationMessageTemplate(this->verificationMessageTemplate.toAWS());
        }

        if (!(this->smsAuthenticationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsAuthenticationMessage(TCHAR_TO_UTF8(*this->smsAuthenticationMessage));
        }

        switch(this->mfaConfiguration) {
            case EUserPoolMfaType::OFF:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF);
                break;
            case EUserPoolMfaType::ON:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON);
                break;
            case EUserPoolMfaType::OPT:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPT);
                break;
            default:
                break;
        }

        if (!(this->deviceConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetDeviceConfiguration(this->deviceConfiguration.toAWS());
        }

        if (!(this->emailConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailConfiguration(this->emailConfiguration.toAWS());
        }

        if (!(this->smsConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsConfiguration(this->smsConfiguration.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->userPoolTags) {
            awsUpdateUserPoolRequest.AddUserPoolTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->adminCreateUserConfig.IsEmpty())) {
            awsUpdateUserPoolRequest.SetAdminCreateUserConfig(this->adminCreateUserConfig.toAWS());
        }

        if (!(this->userPoolAddOns.IsEmpty())) {
            awsUpdateUserPoolRequest.SetUserPoolAddOns(this->userPoolAddOns.toAWS());
        }

        if (!(this->accountRecoverySetting.IsEmpty())) {
            awsUpdateUserPoolRequest.SetAccountRecoverySetting(this->accountRecoverySetting.toAWS());
        }

        return awsUpdateUserPoolRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->policies.IsEmpty() && this->lambdaConfig.IsEmpty() && this->autoVerifiedAttributes.Num() == 0 && this->smsVerificationMessage.IsEmpty() && this->emailVerificationMessage.IsEmpty() && this->emailVerificationSubject.IsEmpty() && this->verificationMessageTemplate.IsEmpty() && this->smsAuthenticationMessage.IsEmpty() && this->mfaConfiguration == EUserPoolMfaType::NOT_SET && this->deviceConfiguration.IsEmpty() && this->emailConfiguration.IsEmpty() && this->smsConfiguration.IsEmpty() && this->userPoolTags.Num() == 0 && this->adminCreateUserConfig.IsEmpty() && this->userPoolAddOns.IsEmpty() && this->accountRecoverySetting.IsEmpty();
    }
#endif
};
