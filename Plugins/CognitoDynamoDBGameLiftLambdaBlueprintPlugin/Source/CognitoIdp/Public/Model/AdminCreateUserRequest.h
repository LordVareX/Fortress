/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminCreateUserRequest.h"

#endif

#include "Model/AttributeType.h"
#include "Model/AttributeType.h"
#include "Model/MessageActionType.h"
#include "Model/DeliveryMediumType.h"

#include "AdminCreateUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminCreateUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where the user will be created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The username for the user. Must be unique within the user pool. Must be a UTF-8 string between 1 and 128 characters. After the user is created, the username cannot be changed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>An array of name-value pairs that contain user attributes and attribute values to be set for the user to be created. You can create a user without specifying any attributes other than <code>Username</code>. However, any attributes that you specify as required (in or in the <b>Attributes</b> tab of the console) must be supplied either by you (in your call to <code>AdminCreateUser</code>) or by the user (when he or she signs up in response to your welcome message).</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p> <p>To send a message inviting the user to sign up, you must specify the user's email address or phone number. This can be done in your call to AdminCreateUser or in the <b>Users</b> tab of the Amazon Cognito console for managing your user pools.</p> <p>In your call to <code>AdminCreateUser</code>, you can set the <code>email_verified</code> attribute to <code>True</code>, and you can set the <code>phone_number_verified</code> attribute to <code>True</code>. (You can also do this by calling .)</p> <ul> <li> <p> <b>email</b>: The email address of the user to whom the message that contains the code and username will be sent. Required if the <code>email_verified</code> attribute is set to <code>True</code>, or if <code>"EMAIL"</code> is specified in the <code>DesiredDeliveryMediums</code> parameter.</p> </li> <li> <p> <b>phone_number</b>: The phone number of the user to whom the message that contains the code and username will be sent. Required if the <code>phone_number_verified</code> attribute is set to <code>True</code>, or if <code>"SMS"</code> is specified in the <code>DesiredDeliveryMediums</code> parameter.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> userAttributes;

    /**
    *  <p>The user's validation data. This is an array of name-value pairs that contain user attributes and attribute values that you can use for custom validation, such as restricting the types of user accounts that can be registered. For example, you might choose to allow or disallow user sign-up based on the user's domain.</p> <p>To configure custom validation, you must create a Pre Sign-up Lambda trigger for the user pool as described in the Amazon Cognito Developer Guide. The Lambda trigger receives the validation data and uses it in the validation process.</p> <p>The user's validation data is not persisted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> validationData;

    /**
    *  <p>The user's temporary password. This password must conform to the password policy that you specified when you created the user pool.</p> <p>The temporary password is valid only once. To complete the Admin Create User flow, the user must enter the temporary password in the sign-in page along with a new password to be used in all future sign-ins.</p> <p>This parameter is not required. If you do not specify a value, Amazon Cognito generates one for you.</p> <p>The temporary password can only be used until the user account expiration limit that you specified when you created the user pool. To reset the account after that time limit, you must call <code>AdminCreateUser</code> again, specifying <code>"RESEND"</code> for the <code>MessageAction</code> parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString temporaryPassword;

    /**
    *  <p>This parameter is only used if the <code>phone_number_verified</code> or <code>email_verified</code> attribute is set to <code>True</code>. Otherwise, it is ignored.</p> <p>If this parameter is set to <code>True</code> and the phone number or email address specified in the UserAttributes parameter already exists as an alias with a different user, the API call will migrate the alias from the previous user to the newly created user. The previous user will no longer be able to log in using that alias.</p> <p>If this parameter is set to <code>False</code>, the API throws an <code>AliasExistsException</code> error if the alias already exists. The default value is <code>False</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool forceAliasCreation;

    /**
    *  <p>Set to <code>"RESEND"</code> to resend the invitation message to a user that already exists and reset the expiration limit on the user's account. Set to <code>"SUPPRESS"</code> to suppress sending the message. Only one value can be specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EMessageActionType messageAction;

    /**
    *  <p>Specify <code>"EMAIL"</code> if email will be used to send the welcome message. Specify <code>"SMS"</code> if the phone number will be used. The default value is <code>"SMS"</code>. More than one value can be specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EDeliveryMediumType> desiredDeliveryMediums;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the AdminCreateUser API action, Amazon Cognito invokes the function that is assigned to the <i>pre sign-up</i> trigger. When Amazon Cognito invokes this function, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your AdminCreateUser request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminCreateUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminCreateUserRequest awsAdminCreateUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminCreateUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminCreateUserRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        for (const FAttributeType& elem : this->userAttributes) {
            awsAdminCreateUserRequest.AddUserAttributes(elem.toAWS());
        }

        for (const FAttributeType& elem : this->validationData) {
            awsAdminCreateUserRequest.AddValidationData(elem.toAWS());
        }

        if (!(this->temporaryPassword.IsEmpty())) {
            awsAdminCreateUserRequest.SetTemporaryPassword(TCHAR_TO_UTF8(*this->temporaryPassword));
        }

        if (!(false)) {
            awsAdminCreateUserRequest.SetForceAliasCreation(this->forceAliasCreation);
        }

        switch(this->messageAction) {
            case EMessageActionType::RESEND:
                awsAdminCreateUserRequest.SetMessageAction(Aws::CognitoIdentityProvider::Model::MessageActionType::RESEND);
                break;
            case EMessageActionType::SUPPRESS:
                awsAdminCreateUserRequest.SetMessageAction(Aws::CognitoIdentityProvider::Model::MessageActionType::SUPPRESS);
                break;
            default:
                break;
        }

        for (const EDeliveryMediumType& elem : this->desiredDeliveryMediums) {
            switch(elem) {
                case EDeliveryMediumType::SMS:
                    awsAdminCreateUserRequest.AddDesiredDeliveryMediums(Aws::CognitoIdentityProvider::Model::DeliveryMediumType::SMS);
                    break;
                case EDeliveryMediumType::EMAIL:
                    awsAdminCreateUserRequest.AddDesiredDeliveryMediums(Aws::CognitoIdentityProvider::Model::DeliveryMediumType::EMAIL);
                    break;
                default:
                    break;
            };
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsAdminCreateUserRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsAdminCreateUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->userAttributes.Num() == 0 && this->validationData.Num() == 0 && this->temporaryPassword.IsEmpty() && false && this->messageAction == EMessageActionType::NOT_SET && this->desiredDeliveryMediums.Num() == 0 && this->clientMetadata.Num() == 0;
    }
#endif
};
