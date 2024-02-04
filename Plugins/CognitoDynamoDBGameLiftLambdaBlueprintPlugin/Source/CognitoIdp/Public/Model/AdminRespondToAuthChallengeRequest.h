/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminRespondToAuthChallengeRequest.h"

#endif

#include "Model/ChallengeNameType.h"
#include "Model/AnalyticsMetadataType.h"
#include "Model/ContextDataType.h"

#include "AdminRespondToAuthChallengeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminRespondToAuthChallengeRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the Amazon Cognito user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The challenge name. For more information, see .</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EChallengeNameType challengeName;

    /**
    *  <p>The challenge responses. These are inputs corresponding to the value of <code>ChallengeName</code>, for example:</p> <ul> <li> <p> <code>SMS_MFA</code>: <code>SMS_MFA_CODE</code>, <code>USERNAME</code>, <code>SECRET_HASH</code> (if app client is configured with client secret).</p> </li> <li> <p> <code>PASSWORD_VERIFIER</code>: <code>PASSWORD_CLAIM_SIGNATURE</code>, <code>PASSWORD_CLAIM_SECRET_BLOCK</code>, <code>TIMESTAMP</code>, <code>USERNAME</code>, <code>SECRET_HASH</code> (if app client is configured with client secret).</p> </li> <li> <p> <code>ADMIN_NO_SRP_AUTH</code>: <code>PASSWORD</code>, <code>USERNAME</code>, <code>SECRET_HASH</code> (if app client is configured with client secret). </p> </li> <li> <p> <code>NEW_PASSWORD_REQUIRED</code>: <code>NEW_PASSWORD</code>, any other required attributes, <code>USERNAME</code>, <code>SECRET_HASH</code> (if app client is configured with client secret). </p> </li> </ul> <p>The value of the <code>USERNAME</code> attribute must be the user's actual username, not an alias (such as email address or phone number). To make this easier, the <code>AdminInitiateAuth</code> response includes the actual username value in the <code>USERNAMEUSER_ID_FOR_SRP</code> attribute, even if you specified an alias in your call to <code>AdminInitiateAuth</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> challengeResponses;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service. If <code>InitiateAuth</code> or <code>RespondToAuthChallenge</code> API call determines that the caller needs to go through another challenge, they return a session with other challenge parameters. This session should be passed as it is to the next <code>RespondToAuthChallenge</code> API call.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

    /**
    *  <p>The analytics metadata for collecting Amazon Pinpoint metrics for <code>AdminRespondToAuthChallenge</code> calls.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsMetadataType analyticsMetadata;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FContextDataType contextData;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the AdminRespondToAuthChallenge API action, Amazon Cognito invokes any functions that are assigned to the following triggers: <i>pre sign-up</i>, <i>custom message</i>, <i>post authentication</i>, <i>user migration</i>, <i>pre token generation</i>, <i>define auth challenge</i>, <i>create auth challenge</i>, and <i>verify auth challenge response</i>. When Amazon Cognito invokes any of these functions, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your AdminRespondToAuthChallenge request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminRespondToAuthChallengeRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminRespondToAuthChallengeRequest awsAdminRespondToAuthChallengeRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminRespondToAuthChallengeRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsAdminRespondToAuthChallengeRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        switch(this->challengeName) {
            case EChallengeNameType::SMS_MFA:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::SMS_MFA);
                break;
            case EChallengeNameType::SOFTWARE_TOKEN_MFA:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::SOFTWARE_TOKEN_MFA);
                break;
            case EChallengeNameType::SELECT_MFA_TYPE:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::SELECT_MFA_TYPE);
                break;
            case EChallengeNameType::MFA_SETUP:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::MFA_SETUP);
                break;
            case EChallengeNameType::PASSWORD_VERIFIER:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::PASSWORD_VERIFIER);
                break;
            case EChallengeNameType::CUSTOM_CHALLENGE:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::CUSTOM_CHALLENGE);
                break;
            case EChallengeNameType::DEVICE_SRP_AUTH:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::DEVICE_SRP_AUTH);
                break;
            case EChallengeNameType::DEVICE_PASSWORD_VERIFIER:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::DEVICE_PASSWORD_VERIFIER);
                break;
            case EChallengeNameType::ADMIN_NO_SRP_AUTH:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::ADMIN_NO_SRP_AUTH);
                break;
            case EChallengeNameType::NEW_PASSWORD_REQUIRED:
                awsAdminRespondToAuthChallengeRequest.SetChallengeName(Aws::CognitoIdentityProvider::Model::ChallengeNameType::NEW_PASSWORD_REQUIRED);
                break;
            default:
                break;
        }

        for (const TPair<FString, FString>& elem : this->challengeResponses) {
            awsAdminRespondToAuthChallengeRequest.AddChallengeResponses(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->session.IsEmpty())) {
            awsAdminRespondToAuthChallengeRequest.SetSession(TCHAR_TO_UTF8(*this->session));
        }

        if (!(this->analyticsMetadata.IsEmpty())) {
            awsAdminRespondToAuthChallengeRequest.SetAnalyticsMetadata(this->analyticsMetadata.toAWS());
        }

        if (!(this->contextData.IsEmpty())) {
            awsAdminRespondToAuthChallengeRequest.SetContextData(this->contextData.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsAdminRespondToAuthChallengeRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsAdminRespondToAuthChallengeRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty() && this->challengeName == EChallengeNameType::NOT_SET && this->challengeResponses.Num() == 0 && this->session.IsEmpty() && this->analyticsMetadata.IsEmpty() && this->contextData.IsEmpty() && this->clientMetadata.Num() == 0;
    }
#endif
};
