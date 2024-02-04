/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "CognitoIdentityProviderClientObject.h"
#include "CognitoIdpGlobals.h"
#include "CognitoIdpPrivatePCH.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK

ECognitoIdpError fromAWS(Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INCOMPLETE_SIGNATURE:
            return ECognitoIdpError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INTERNAL_FAILURE:
            return ECognitoIdpError::INTERNAL_FAILURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_ACTION:
            return ECognitoIdpError::INVALID_ACTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_CLIENT_TOKEN_ID:
            return ECognitoIdpError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER_COMBINATION:
            return ECognitoIdpError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_QUERY_PARAMETER:
            return ECognitoIdpError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER_VALUE:
            return ECognitoIdpError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_ACTION:
            return ECognitoIdpError::MISSING_ACTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_AUTHENTICATION_TOKEN:
            return ECognitoIdpError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_PARAMETER:
            return ECognitoIdpError::MISSING_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::OPT_IN_REQUIRED:
            return ECognitoIdpError::OPT_IN_REQUIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_EXPIRED:
            return ECognitoIdpError::REQUEST_EXPIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SERVICE_UNAVAILABLE:
            return ECognitoIdpError::SERVICE_UNAVAILABLE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::THROTTLING:
            return ECognitoIdpError::THROTTLING;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::VALIDATION:
            return ECognitoIdpError::VALIDATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ACCESS_DENIED:
            return ECognitoIdpError::ACCESS_DENIED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::RESOURCE_NOT_FOUND:
            return ECognitoIdpError::RESOURCE_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNRECOGNIZED_CLIENT:
            return ECognitoIdpError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MALFORMED_QUERY_STRING:
            return ECognitoIdpError::MALFORMED_QUERY_STRING;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SLOW_DOWN:
            return ECognitoIdpError::SLOW_DOWN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_TIME_TOO_SKEWED:
            return ECognitoIdpError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SIGNATURE:
            return ECognitoIdpError::INVALID_SIGNATURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SIGNATURE_DOES_NOT_MATCH:
            return ECognitoIdpError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_ACCESS_KEY_ID:
            return ECognitoIdpError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_TIMEOUT:
            return ECognitoIdpError::REQUEST_TIMEOUT;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::NETWORK_CONNECTION:
            return ECognitoIdpError::NETWORK_CONNECTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNKNOWN:
            return ECognitoIdpError::UNKNOWN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ALIAS_EXISTS:
            return ECognitoIdpError::ALIAS_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CODE_DELIVERY_FAILURE:
            return ECognitoIdpError::CODE_DELIVERY_FAILURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CODE_MISMATCH:
            return ECognitoIdpError::CODE_MISMATCH;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CONCURRENT_MODIFICATION:
            return ECognitoIdpError::CONCURRENT_MODIFICATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::DUPLICATE_PROVIDER:
            return ECognitoIdpError::DUPLICATE_PROVIDER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ENABLE_SOFTWARE_TOKEN_M_F_A:
            return ECognitoIdpError::ENABLE_SOFTWARE_TOKEN_MFA;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::EXPIRED_CODE:
            return ECognitoIdpError::EXPIRED_CODE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::GROUP_EXISTS:
            return ECognitoIdpError::GROUP_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INTERNAL_ERROR:
            return ECognitoIdpError::INTERNAL_ERROR;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_EMAIL_ROLE_ACCESS_POLICY:
            return ECognitoIdpError::INVALID_EMAIL_ROLE_ACCESS_POLICY;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_LAMBDA_RESPONSE:
            return ECognitoIdpError::INVALID_LAMBDA_RESPONSE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_O_AUTH_FLOW:
            return ECognitoIdpError::INVALID_OAUTH_FLOW;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER:
            return ECognitoIdpError::INVALID_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PASSWORD:
            return ECognitoIdpError::INVALID_PASSWORD;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SMS_ROLE_ACCESS_POLICY:
            return ECognitoIdpError::INVALID_SMS_ROLE_ACCESS_POLICY;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SMS_ROLE_TRUST_RELATIONSHIP:
            return ECognitoIdpError::INVALID_SMS_ROLE_TRUST_RELATIONSHIP;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_USER_POOL_CONFIGURATION:
            return ECognitoIdpError::INVALID_USER_POOL_CONFIGURATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::LIMIT_EXCEEDED:
            return ECognitoIdpError::LIMIT_EXCEEDED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::M_F_A_METHOD_NOT_FOUND:
            return ECognitoIdpError::MFA_METHOD_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::NOT_AUTHORIZED:
            return ECognitoIdpError::NOT_AUTHORIZED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::PASSWORD_RESET_REQUIRED:
            return ECognitoIdpError::PASSWORD_RESET_REQUIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::PRECONDITION_NOT_MET:
            return ECognitoIdpError::PRECONDITION_NOT_MET;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SCOPE_DOES_NOT_EXIST:
            return ECognitoIdpError::SCOPE_DOES_NOT_EXIST;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SOFTWARE_TOKEN_M_F_A_NOT_FOUND:
            return ECognitoIdpError::SOFTWARE_TOKEN_MFA_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::TOO_MANY_FAILED_ATTEMPTS:
            return ECognitoIdpError::TOO_MANY_FAILED_ATTEMPTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::TOO_MANY_REQUESTS:
            return ECognitoIdpError::TOO_MANY_REQUESTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNEXPECTED_LAMBDA:
            return ECognitoIdpError::UNEXPECTED_LAMBDA;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_IDENTITY_PROVIDER:
            return ECognitoIdpError::UNSUPPORTED_IDENTITY_PROVIDER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_USER_STATE:
            return ECognitoIdpError::UNSUPPORTED_USER_STATE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USERNAME_EXISTS:
            return ECognitoIdpError::USERNAME_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_IMPORT_IN_PROGRESS:
            return ECognitoIdpError::USER_IMPORT_IN_PROGRESS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_LAMBDA_VALIDATION:
            return ECognitoIdpError::USER_LAMBDA_VALIDATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_NOT_CONFIRMED:
            return ECognitoIdpError::USER_NOT_CONFIRMED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_NOT_FOUND:
            return ECognitoIdpError::USER_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_POOL_ADD_ON_NOT_ENABLED:
            return ECognitoIdpError::USER_POOL_ADDON_NOT_ENABLED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_POOL_TAGGING:
            return ECognitoIdpError::USER_POOL_TAGGING;
            break;
        default:
            return ECognitoIdpError::UNKNOWN;
            break;
    }
}

#endif

UCognitoIdpClientObject *UCognitoIdpClientObject::CreateCognitoIdpObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    UCognitoIdpClientObject *CognitoIdpClient = NewObject<UCognitoIdpClientObject>();
    CognitoIdpClient->awsCognitoIdentityProviderClient = new Aws::CognitoIdentityProvider::CognitoIdentityProviderClient(credentials.toAWS(),
    clientConfiguration.toAWS());
    return CognitoIdpClient;
#endif
    return nullptr;
}

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAddCustomAttributesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAddCustomAttributesRequest addCustomAttributesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAddCustomAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAddCustomAttributesRequest addCustomAttributesRequest,
        FAddCustomAttributesResult &addCustomAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), addCustomAttributesRequest(addCustomAttributesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AddCustomAttributesAsync(
            addCustomAttributesRequest.toAWS(),
            [&success, &addCustomAttributesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AddCustomAttributesRequest &awsAddCustomAttributesRequest,
                const Aws::CognitoIdentityProvider::Model::AddCustomAttributesOutcome &awsAddCustomAttributesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAddCustomAttributesOutcome.IsSuccess();
                if (success) {
                    addCustomAttributesResult.fromAWS(awsAddCustomAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAddCustomAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AddCustomAttributes error: " + awsAddCustomAttributesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddCustomAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AddCustomAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAddCustomAttributesRequest addCustomAttributesRequest,
        FAddCustomAttributesResult &addCustomAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddCustomAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddCustomAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                addCustomAttributesRequest,
                addCustomAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminAddUserToGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminAddUserToGroupRequest adminAddUserToGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminAddUserToGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminAddUserToGroupRequest adminAddUserToGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminAddUserToGroupRequest(adminAddUserToGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminAddUserToGroupAsync(
            adminAddUserToGroupRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminAddUserToGroupRequest &awsAdminAddUserToGroupRequest,
                const Aws::CognitoIdentityProvider::Model::AdminAddUserToGroupOutcome &awsAdminAddUserToGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminAddUserToGroupOutcome.IsSuccess();

                errorType = fromAWS(awsAdminAddUserToGroupOutcome.GetError().GetErrorType());
                errorMessage = ("AdminAddUserToGroup error: " + awsAdminAddUserToGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminAddUserToGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminAddUserToGroup(
        UObject *WorldContextObject,
        bool &success,
        FAdminAddUserToGroupRequest adminAddUserToGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminAddUserToGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminAddUserToGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                adminAddUserToGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminConfirmSignUpAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminConfirmSignUpRequest adminConfirmSignUpRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminConfirmSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminConfirmSignUpRequest adminConfirmSignUpRequest,
        FAdminConfirmSignUpResult &adminConfirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminConfirmSignUpRequest(adminConfirmSignUpRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminConfirmSignUpAsync(
            adminConfirmSignUpRequest.toAWS(),
            [&success, &adminConfirmSignUpResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminConfirmSignUpRequest &awsAdminConfirmSignUpRequest,
                const Aws::CognitoIdentityProvider::Model::AdminConfirmSignUpOutcome &awsAdminConfirmSignUpOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminConfirmSignUpOutcome.IsSuccess();
                if (success) {
                    adminConfirmSignUpResult.fromAWS(awsAdminConfirmSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminConfirmSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("AdminConfirmSignUp error: " + awsAdminConfirmSignUpOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminConfirmSignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminConfirmSignUp(
        UObject *WorldContextObject,
        bool &success,
        FAdminConfirmSignUpRequest adminConfirmSignUpRequest,
        FAdminConfirmSignUpResult &adminConfirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminConfirmSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminConfirmSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                adminConfirmSignUpRequest,
                adminConfirmSignUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminCreateUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminCreateUserRequest adminCreateUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminCreateUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminCreateUserRequest adminCreateUserRequest,
        FAdminCreateUserResult &adminCreateUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminCreateUserRequest(adminCreateUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminCreateUserAsync(
            adminCreateUserRequest.toAWS(),
            [&success, &adminCreateUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminCreateUserRequest &awsAdminCreateUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminCreateUserOutcome &awsAdminCreateUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminCreateUserOutcome.IsSuccess();
                if (success) {
                    adminCreateUserResult.fromAWS(awsAdminCreateUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminCreateUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminCreateUser error: " + awsAdminCreateUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminCreateUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminCreateUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminCreateUserRequest adminCreateUserRequest,
        FAdminCreateUserResult &adminCreateUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminCreateUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminCreateUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminCreateUserRequest,
                adminCreateUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminDeleteUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminDeleteUserRequest adminDeleteUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminDeleteUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDeleteUserRequest adminDeleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminDeleteUserRequest(adminDeleteUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminDeleteUserAsync(
            adminDeleteUserRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminDeleteUserRequest &awsAdminDeleteUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminDeleteUserOutcome &awsAdminDeleteUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminDeleteUserOutcome.IsSuccess();

                errorType = fromAWS(awsAdminDeleteUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDeleteUser error: " + awsAdminDeleteUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDeleteUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDeleteUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserRequest adminDeleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDeleteUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDeleteUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDeleteUserRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminDeleteUserAttributesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminDeleteUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest,
        FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminDeleteUserAttributesRequest(adminDeleteUserAttributesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminDeleteUserAttributesAsync(
            adminDeleteUserAttributesRequest.toAWS(),
            [&success, &adminDeleteUserAttributesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesRequest &awsAdminDeleteUserAttributesRequest,
                const Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesOutcome &awsAdminDeleteUserAttributesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminDeleteUserAttributesOutcome.IsSuccess();
                if (success) {
                    adminDeleteUserAttributesResult.fromAWS(awsAdminDeleteUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDeleteUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDeleteUserAttributes error: " + awsAdminDeleteUserAttributesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDeleteUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDeleteUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest,
        FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDeleteUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDeleteUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDeleteUserAttributesRequest,
                adminDeleteUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminDisableProviderForUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminDisableProviderForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest,
        FAdminDisableProviderForUserResult &adminDisableProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminDisableProviderForUserRequest(adminDisableProviderForUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminDisableProviderForUserAsync(
            adminDisableProviderForUserRequest.toAWS(),
            [&success, &adminDisableProviderForUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserRequest &awsAdminDisableProviderForUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserOutcome &awsAdminDisableProviderForUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminDisableProviderForUserOutcome.IsSuccess();
                if (success) {
                    adminDisableProviderForUserResult.fromAWS(awsAdminDisableProviderForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDisableProviderForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDisableProviderForUser error: " + awsAdminDisableProviderForUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDisableProviderForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDisableProviderForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest,
        FAdminDisableProviderForUserResult &adminDisableProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDisableProviderForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDisableProviderForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDisableProviderForUserRequest,
                adminDisableProviderForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminDisableUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminDisableUserRequest adminDisableUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminDisableUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDisableUserRequest adminDisableUserRequest,
        FAdminDisableUserResult &adminDisableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminDisableUserRequest(adminDisableUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminDisableUserAsync(
            adminDisableUserRequest.toAWS(),
            [&success, &adminDisableUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminDisableUserRequest &awsAdminDisableUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminDisableUserOutcome &awsAdminDisableUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminDisableUserOutcome.IsSuccess();
                if (success) {
                    adminDisableUserResult.fromAWS(awsAdminDisableUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDisableUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDisableUser error: " + awsAdminDisableUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDisableUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDisableUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableUserRequest adminDisableUserRequest,
        FAdminDisableUserResult &adminDisableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDisableUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDisableUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDisableUserRequest,
                adminDisableUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminEnableUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminEnableUserRequest adminEnableUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminEnableUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminEnableUserRequest adminEnableUserRequest,
        FAdminEnableUserResult &adminEnableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminEnableUserRequest(adminEnableUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminEnableUserAsync(
            adminEnableUserRequest.toAWS(),
            [&success, &adminEnableUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminEnableUserRequest &awsAdminEnableUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminEnableUserOutcome &awsAdminEnableUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminEnableUserOutcome.IsSuccess();
                if (success) {
                    adminEnableUserResult.fromAWS(awsAdminEnableUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminEnableUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminEnableUser error: " + awsAdminEnableUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminEnableUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminEnableUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminEnableUserRequest adminEnableUserRequest,
        FAdminEnableUserResult &adminEnableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminEnableUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminEnableUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminEnableUserRequest,
                adminEnableUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminForgetDeviceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminForgetDeviceRequest adminForgetDeviceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminForgetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminForgetDeviceRequest adminForgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminForgetDeviceRequest(adminForgetDeviceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminForgetDeviceAsync(
            adminForgetDeviceRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminForgetDeviceRequest &awsAdminForgetDeviceRequest,
                const Aws::CognitoIdentityProvider::Model::AdminForgetDeviceOutcome &awsAdminForgetDeviceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminForgetDeviceOutcome.IsSuccess();

                errorType = fromAWS(awsAdminForgetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminForgetDevice error: " + awsAdminForgetDeviceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminForgetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminForgetDevice(
        UObject *WorldContextObject,
        bool &success,
        FAdminForgetDeviceRequest adminForgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminForgetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminForgetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminForgetDeviceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminGetDeviceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminGetDeviceRequest adminGetDeviceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminGetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminGetDeviceRequest adminGetDeviceRequest,
        FAdminGetDeviceResult &adminGetDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminGetDeviceRequest(adminGetDeviceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminGetDeviceAsync(
            adminGetDeviceRequest.toAWS(),
            [&success, &adminGetDeviceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminGetDeviceRequest &awsAdminGetDeviceRequest,
                const Aws::CognitoIdentityProvider::Model::AdminGetDeviceOutcome &awsAdminGetDeviceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminGetDeviceOutcome.IsSuccess();
                if (success) {
                    adminGetDeviceResult.fromAWS(awsAdminGetDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminGetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminGetDevice error: " + awsAdminGetDeviceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminGetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminGetDevice(
        UObject *WorldContextObject,
        bool &success,
        FAdminGetDeviceRequest adminGetDeviceRequest,
        FAdminGetDeviceResult &adminGetDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminGetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminGetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminGetDeviceRequest,
                adminGetDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminGetUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminGetUserRequest adminGetUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminGetUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminGetUserRequest adminGetUserRequest,
        FAdminGetUserResult &adminGetUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminGetUserRequest(adminGetUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminGetUserAsync(
            adminGetUserRequest.toAWS(),
            [&success, &adminGetUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminGetUserRequest &awsAdminGetUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminGetUserOutcome &awsAdminGetUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminGetUserOutcome.IsSuccess();
                if (success) {
                    adminGetUserResult.fromAWS(awsAdminGetUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminGetUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminGetUser error: " + awsAdminGetUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminGetUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminGetUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminGetUserRequest adminGetUserRequest,
        FAdminGetUserResult &adminGetUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminGetUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminGetUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminGetUserRequest,
                adminGetUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminInitiateAuthAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminInitiateAuthRequest adminInitiateAuthRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminInitiateAuthAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminInitiateAuthRequest adminInitiateAuthRequest,
        FAdminInitiateAuthResult &adminInitiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminInitiateAuthRequest(adminInitiateAuthRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminInitiateAuthAsync(
            adminInitiateAuthRequest.toAWS(),
            [&success, &adminInitiateAuthResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminInitiateAuthRequest &awsAdminInitiateAuthRequest,
                const Aws::CognitoIdentityProvider::Model::AdminInitiateAuthOutcome &awsAdminInitiateAuthOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminInitiateAuthOutcome.IsSuccess();
                if (success) {
                    adminInitiateAuthResult.fromAWS(awsAdminInitiateAuthOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminInitiateAuthOutcome.GetError().GetErrorType());
                errorMessage = ("AdminInitiateAuth error: " + awsAdminInitiateAuthOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminInitiateAuth Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminInitiateAuth(
        UObject *WorldContextObject,
        bool &success,
        FAdminInitiateAuthRequest adminInitiateAuthRequest,
        FAdminInitiateAuthResult &adminInitiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminInitiateAuthAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminInitiateAuthAction(this->awsCognitoIdentityProviderClient,
                success,
                adminInitiateAuthRequest,
                adminInitiateAuthResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminLinkProviderForUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminLinkProviderForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest,
        FAdminLinkProviderForUserResult &adminLinkProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminLinkProviderForUserRequest(adminLinkProviderForUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminLinkProviderForUserAsync(
            adminLinkProviderForUserRequest.toAWS(),
            [&success, &adminLinkProviderForUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserRequest &awsAdminLinkProviderForUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserOutcome &awsAdminLinkProviderForUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminLinkProviderForUserOutcome.IsSuccess();
                if (success) {
                    adminLinkProviderForUserResult.fromAWS(awsAdminLinkProviderForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminLinkProviderForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminLinkProviderForUser error: " + awsAdminLinkProviderForUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminLinkProviderForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminLinkProviderForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest,
        FAdminLinkProviderForUserResult &adminLinkProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminLinkProviderForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminLinkProviderForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminLinkProviderForUserRequest,
                adminLinkProviderForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminListDevicesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminListDevicesRequest adminListDevicesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminListDevicesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListDevicesRequest adminListDevicesRequest,
        FAdminListDevicesResult &adminListDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminListDevicesRequest(adminListDevicesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminListDevicesAsync(
            adminListDevicesRequest.toAWS(),
            [&success, &adminListDevicesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminListDevicesRequest &awsAdminListDevicesRequest,
                const Aws::CognitoIdentityProvider::Model::AdminListDevicesOutcome &awsAdminListDevicesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminListDevicesOutcome.IsSuccess();
                if (success) {
                    adminListDevicesResult.fromAWS(awsAdminListDevicesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListDevicesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListDevices error: " + awsAdminListDevicesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListDevices Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListDevices(
        UObject *WorldContextObject,
        bool &success,
        FAdminListDevicesRequest adminListDevicesRequest,
        FAdminListDevicesResult &adminListDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListDevicesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListDevicesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListDevicesRequest,
                adminListDevicesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminListGroupsForUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminListGroupsForUserRequest adminListGroupsForUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminListGroupsForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListGroupsForUserRequest adminListGroupsForUserRequest,
        FAdminListGroupsForUserResult &adminListGroupsForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminListGroupsForUserRequest(adminListGroupsForUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminListGroupsForUserAsync(
            adminListGroupsForUserRequest.toAWS(),
            [&success, &adminListGroupsForUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserRequest &awsAdminListGroupsForUserRequest,
                const Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserOutcome &awsAdminListGroupsForUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminListGroupsForUserOutcome.IsSuccess();
                if (success) {
                    adminListGroupsForUserResult.fromAWS(awsAdminListGroupsForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListGroupsForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListGroupsForUser error: " + awsAdminListGroupsForUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListGroupsForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListGroupsForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminListGroupsForUserRequest adminListGroupsForUserRequest,
        FAdminListGroupsForUserResult &adminListGroupsForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListGroupsForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListGroupsForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListGroupsForUserRequest,
                adminListGroupsForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminListUserAuthEventsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminListUserAuthEventsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest,
        FAdminListUserAuthEventsResult &adminListUserAuthEventsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminListUserAuthEventsRequest(adminListUserAuthEventsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminListUserAuthEventsAsync(
            adminListUserAuthEventsRequest.toAWS(),
            [&success, &adminListUserAuthEventsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsRequest &awsAdminListUserAuthEventsRequest,
                const Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsOutcome &awsAdminListUserAuthEventsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminListUserAuthEventsOutcome.IsSuccess();
                if (success) {
                    adminListUserAuthEventsResult.fromAWS(awsAdminListUserAuthEventsOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListUserAuthEventsOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListUserAuthEvents error: " + awsAdminListUserAuthEventsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListUserAuthEvents Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListUserAuthEvents(
        UObject *WorldContextObject,
        bool &success,
        FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest,
        FAdminListUserAuthEventsResult &adminListUserAuthEventsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListUserAuthEventsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListUserAuthEventsAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListUserAuthEventsRequest,
                adminListUserAuthEventsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminRemoveUserFromGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminRemoveUserFromGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminRemoveUserFromGroupRequest(adminRemoveUserFromGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminRemoveUserFromGroupAsync(
            adminRemoveUserFromGroupRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminRemoveUserFromGroupRequest &awsAdminRemoveUserFromGroupRequest,
                const Aws::CognitoIdentityProvider::Model::AdminRemoveUserFromGroupOutcome &awsAdminRemoveUserFromGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminRemoveUserFromGroupOutcome.IsSuccess();

                errorType = fromAWS(awsAdminRemoveUserFromGroupOutcome.GetError().GetErrorType());
                errorMessage = ("AdminRemoveUserFromGroup error: " + awsAdminRemoveUserFromGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminRemoveUserFromGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminRemoveUserFromGroup(
        UObject *WorldContextObject,
        bool &success,
        FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminRemoveUserFromGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminRemoveUserFromGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                adminRemoveUserFromGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminResetUserPasswordAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminResetUserPasswordRequest adminResetUserPasswordRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminResetUserPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminResetUserPasswordRequest adminResetUserPasswordRequest,
        FAdminResetUserPasswordResult &adminResetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminResetUserPasswordRequest(adminResetUserPasswordRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminResetUserPasswordAsync(
            adminResetUserPasswordRequest.toAWS(),
            [&success, &adminResetUserPasswordResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordRequest &awsAdminResetUserPasswordRequest,
                const Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordOutcome &awsAdminResetUserPasswordOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminResetUserPasswordOutcome.IsSuccess();
                if (success) {
                    adminResetUserPasswordResult.fromAWS(awsAdminResetUserPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminResetUserPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("AdminResetUserPassword error: " + awsAdminResetUserPasswordOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminResetUserPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminResetUserPassword(
        UObject *WorldContextObject,
        bool &success,
        FAdminResetUserPasswordRequest adminResetUserPasswordRequest,
        FAdminResetUserPasswordResult &adminResetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminResetUserPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminResetUserPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                adminResetUserPasswordRequest,
                adminResetUserPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminRespondToAuthChallengeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminRespondToAuthChallengeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest,
        FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminRespondToAuthChallengeRequest(adminRespondToAuthChallengeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminRespondToAuthChallengeAsync(
            adminRespondToAuthChallengeRequest.toAWS(),
            [&success, &adminRespondToAuthChallengeResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminRespondToAuthChallengeRequest &awsAdminRespondToAuthChallengeRequest,
                const Aws::CognitoIdentityProvider::Model::AdminRespondToAuthChallengeOutcome &awsAdminRespondToAuthChallengeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminRespondToAuthChallengeOutcome.IsSuccess();
                if (success) {
                    adminRespondToAuthChallengeResult.fromAWS(awsAdminRespondToAuthChallengeOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminRespondToAuthChallengeOutcome.GetError().GetErrorType());
                errorMessage = ("AdminRespondToAuthChallenge error: " + awsAdminRespondToAuthChallengeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminRespondToAuthChallenge Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminRespondToAuthChallenge(
        UObject *WorldContextObject,
        bool &success,
        FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest,
        FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminRespondToAuthChallengeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminRespondToAuthChallengeAction(this->awsCognitoIdentityProviderClient,
                success,
                adminRespondToAuthChallengeRequest,
                adminRespondToAuthChallengeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminSetUserMFAPreferenceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminSetUserMFAPreferenceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest,
        FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminSetUserMFAPreferenceRequest(adminSetUserMFAPreferenceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminSetUserMFAPreferenceAsync(
            adminSetUserMFAPreferenceRequest.toAWS(),
            [&success, &adminSetUserMFAPreferenceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceRequest &awsAdminSetUserMFAPreferenceRequest,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceOutcome &awsAdminSetUserMFAPreferenceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminSetUserMFAPreferenceOutcome.IsSuccess();
                if (success) {
                    adminSetUserMFAPreferenceResult.fromAWS(awsAdminSetUserMFAPreferenceOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserMFAPreferenceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserMFAPreference error: " + awsAdminSetUserMFAPreferenceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserMFAPreference Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserMFAPreference(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest,
        FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserMFAPreferenceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserMFAPreferenceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserMFAPreferenceRequest,
                adminSetUserMFAPreferenceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminSetUserPasswordAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminSetUserPasswordRequest adminSetUserPasswordRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminSetUserPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserPasswordRequest adminSetUserPasswordRequest,
        FAdminSetUserPasswordResult &adminSetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminSetUserPasswordRequest(adminSetUserPasswordRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminSetUserPasswordAsync(
            adminSetUserPasswordRequest.toAWS(),
            [&success, &adminSetUserPasswordResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordRequest &awsAdminSetUserPasswordRequest,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordOutcome &awsAdminSetUserPasswordOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminSetUserPasswordOutcome.IsSuccess();
                if (success) {
                    adminSetUserPasswordResult.fromAWS(awsAdminSetUserPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserPassword error: " + awsAdminSetUserPasswordOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserPassword(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserPasswordRequest adminSetUserPasswordRequest,
        FAdminSetUserPasswordResult &adminSetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserPasswordRequest,
                adminSetUserPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminSetUserSettingsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminSetUserSettingsRequest adminSetUserSettingsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminSetUserSettingsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserSettingsRequest adminSetUserSettingsRequest,
        FAdminSetUserSettingsResult &adminSetUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminSetUserSettingsRequest(adminSetUserSettingsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminSetUserSettingsAsync(
            adminSetUserSettingsRequest.toAWS(),
            [&success, &adminSetUserSettingsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsRequest &awsAdminSetUserSettingsRequest,
                const Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsOutcome &awsAdminSetUserSettingsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminSetUserSettingsOutcome.IsSuccess();
                if (success) {
                    adminSetUserSettingsResult.fromAWS(awsAdminSetUserSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserSettings error: " + awsAdminSetUserSettingsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserSettings Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserSettings(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserSettingsRequest adminSetUserSettingsRequest,
        FAdminSetUserSettingsResult &adminSetUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserSettingsAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserSettingsRequest,
                adminSetUserSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminUpdateAuthEventFeedbackAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminUpdateAuthEventFeedbackAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest,
        FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminUpdateAuthEventFeedbackRequest(adminUpdateAuthEventFeedbackRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminUpdateAuthEventFeedbackAsync(
            adminUpdateAuthEventFeedbackRequest.toAWS(),
            [&success, &adminUpdateAuthEventFeedbackResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackRequest &awsAdminUpdateAuthEventFeedbackRequest,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackOutcome &awsAdminUpdateAuthEventFeedbackOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminUpdateAuthEventFeedbackOutcome.IsSuccess();
                if (success) {
                    adminUpdateAuthEventFeedbackResult.fromAWS(awsAdminUpdateAuthEventFeedbackOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateAuthEventFeedbackOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateAuthEventFeedback error: " + awsAdminUpdateAuthEventFeedbackOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateAuthEventFeedback Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateAuthEventFeedback(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest,
        FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateAuthEventFeedbackAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateAuthEventFeedbackAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateAuthEventFeedbackRequest,
                adminUpdateAuthEventFeedbackResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminUpdateDeviceStatusAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminUpdateDeviceStatusAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest,
        FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminUpdateDeviceStatusRequest(adminUpdateDeviceStatusRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminUpdateDeviceStatusAsync(
            adminUpdateDeviceStatusRequest.toAWS(),
            [&success, &adminUpdateDeviceStatusResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusRequest &awsAdminUpdateDeviceStatusRequest,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusOutcome &awsAdminUpdateDeviceStatusOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminUpdateDeviceStatusOutcome.IsSuccess();
                if (success) {
                    adminUpdateDeviceStatusResult.fromAWS(awsAdminUpdateDeviceStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateDeviceStatusOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateDeviceStatus error: " + awsAdminUpdateDeviceStatusOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateDeviceStatus Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateDeviceStatus(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest,
        FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateDeviceStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateDeviceStatusAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateDeviceStatusRequest,
                adminUpdateDeviceStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminUpdateUserAttributesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminUpdateUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest,
        FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminUpdateUserAttributesRequest(adminUpdateUserAttributesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminUpdateUserAttributesAsync(
            adminUpdateUserAttributesRequest.toAWS(),
            [&success, &adminUpdateUserAttributesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesRequest &awsAdminUpdateUserAttributesRequest,
                const Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesOutcome &awsAdminUpdateUserAttributesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminUpdateUserAttributesOutcome.IsSuccess();
                if (success) {
                    adminUpdateUserAttributesResult.fromAWS(awsAdminUpdateUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateUserAttributes error: " + awsAdminUpdateUserAttributesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest,
        FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateUserAttributesRequest,
                adminUpdateUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAdminUserGlobalSignOutAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAdminUserGlobalSignOutAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest,
        FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), adminUserGlobalSignOutRequest(adminUserGlobalSignOutRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AdminUserGlobalSignOutAsync(
            adminUserGlobalSignOutRequest.toAWS(),
            [&success, &adminUserGlobalSignOutResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutRequest &awsAdminUserGlobalSignOutRequest,
                const Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutOutcome &awsAdminUserGlobalSignOutOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAdminUserGlobalSignOutOutcome.IsSuccess();
                if (success) {
                    adminUserGlobalSignOutResult.fromAWS(awsAdminUserGlobalSignOutOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUserGlobalSignOutOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUserGlobalSignOut error: " + awsAdminUserGlobalSignOutOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUserGlobalSignOut Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUserGlobalSignOut(
        UObject *WorldContextObject,
        bool &success,
        FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest,
        FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUserGlobalSignOutAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUserGlobalSignOutAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUserGlobalSignOutRequest,
                adminUserGlobalSignOutResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FAssociateSoftwareTokenAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FAssociateSoftwareTokenRequest associateSoftwareTokenRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FAssociateSoftwareTokenAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAssociateSoftwareTokenRequest associateSoftwareTokenRequest,
        FAssociateSoftwareTokenResult &associateSoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), associateSoftwareTokenRequest(associateSoftwareTokenRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->AssociateSoftwareTokenAsync(
            associateSoftwareTokenRequest.toAWS(),
            [&success, &associateSoftwareTokenResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenRequest &awsAssociateSoftwareTokenRequest,
                const Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenOutcome &awsAssociateSoftwareTokenOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsAssociateSoftwareTokenOutcome.IsSuccess();
                if (success) {
                    associateSoftwareTokenResult.fromAWS(awsAssociateSoftwareTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsAssociateSoftwareTokenOutcome.GetError().GetErrorType());
                errorMessage = ("AssociateSoftwareToken error: " + awsAssociateSoftwareTokenOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AssociateSoftwareToken Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AssociateSoftwareToken(
        UObject *WorldContextObject,
        bool &success,
        FAssociateSoftwareTokenRequest associateSoftwareTokenRequest,
        FAssociateSoftwareTokenResult &associateSoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAssociateSoftwareTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAssociateSoftwareTokenAction(this->awsCognitoIdentityProviderClient,
                success,
                associateSoftwareTokenRequest,
                associateSoftwareTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FChangePasswordAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FChangePasswordRequest changePasswordRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FChangePasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FChangePasswordRequest changePasswordRequest,
        FChangePasswordResult &changePasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), changePasswordRequest(changePasswordRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ChangePasswordAsync(
            changePasswordRequest.toAWS(),
            [&success, &changePasswordResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ChangePasswordRequest &awsChangePasswordRequest,
                const Aws::CognitoIdentityProvider::Model::ChangePasswordOutcome &awsChangePasswordOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsChangePasswordOutcome.IsSuccess();
                if (success) {
                    changePasswordResult.fromAWS(awsChangePasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsChangePasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ChangePassword error: " + awsChangePasswordOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ChangePassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ChangePassword(
        UObject *WorldContextObject,
        bool &success,
        FChangePasswordRequest changePasswordRequest,
        FChangePasswordResult &changePasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FChangePasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FChangePasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                changePasswordRequest,
                changePasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FConfirmDeviceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FConfirmDeviceRequest confirmDeviceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FConfirmDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmDeviceRequest confirmDeviceRequest,
        FConfirmDeviceResult &confirmDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), confirmDeviceRequest(confirmDeviceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ConfirmDeviceAsync(
            confirmDeviceRequest.toAWS(),
            [&success, &confirmDeviceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ConfirmDeviceRequest &awsConfirmDeviceRequest,
                const Aws::CognitoIdentityProvider::Model::ConfirmDeviceOutcome &awsConfirmDeviceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsConfirmDeviceOutcome.IsSuccess();
                if (success) {
                    confirmDeviceResult.fromAWS(awsConfirmDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmDevice error: " + awsConfirmDeviceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmDevice(
        UObject *WorldContextObject,
        bool &success,
        FConfirmDeviceRequest confirmDeviceRequest,
        FConfirmDeviceResult &confirmDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmDeviceRequest,
                confirmDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FConfirmForgotPasswordAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FConfirmForgotPasswordRequest confirmForgotPasswordRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FConfirmForgotPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmForgotPasswordRequest confirmForgotPasswordRequest,
        FConfirmForgotPasswordResult &confirmForgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), confirmForgotPasswordRequest(confirmForgotPasswordRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ConfirmForgotPasswordAsync(
            confirmForgotPasswordRequest.toAWS(),
            [&success, &confirmForgotPasswordResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ConfirmForgotPasswordRequest &awsConfirmForgotPasswordRequest,
                const Aws::CognitoIdentityProvider::Model::ConfirmForgotPasswordOutcome &awsConfirmForgotPasswordOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsConfirmForgotPasswordOutcome.IsSuccess();
                if (success) {
                    confirmForgotPasswordResult.fromAWS(awsConfirmForgotPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmForgotPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmForgotPassword error: " + awsConfirmForgotPasswordOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmForgotPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmForgotPassword(
        UObject *WorldContextObject,
        bool &success,
        FConfirmForgotPasswordRequest confirmForgotPasswordRequest,
        FConfirmForgotPasswordResult &confirmForgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmForgotPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmForgotPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmForgotPasswordRequest,
                confirmForgotPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FConfirmSignUpAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FConfirmSignUpRequest confirmSignUpRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FConfirmSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmSignUpRequest confirmSignUpRequest,
        FConfirmSignUpResult &confirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), confirmSignUpRequest(confirmSignUpRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ConfirmSignUpAsync(
            confirmSignUpRequest.toAWS(),
            [&success, &confirmSignUpResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ConfirmSignUpRequest &awsConfirmSignUpRequest,
                const Aws::CognitoIdentityProvider::Model::ConfirmSignUpOutcome &awsConfirmSignUpOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsConfirmSignUpOutcome.IsSuccess();
                if (success) {
                    confirmSignUpResult.fromAWS(awsConfirmSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmSignUp error: " + awsConfirmSignUpOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmSignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmSignUp(
        UObject *WorldContextObject,
        bool &success,
        FConfirmSignUpRequest confirmSignUpRequest,
        FConfirmSignUpResult &confirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmSignUpRequest,
                confirmSignUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateGroupRequest createGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateGroupRequest createGroupRequest,
        FCreateGroupResult &createGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createGroupRequest(createGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateGroupAsync(
            createGroupRequest.toAWS(),
            [&success, &createGroupResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateGroupRequest &awsCreateGroupRequest,
                const Aws::CognitoIdentityProvider::Model::CreateGroupOutcome &awsCreateGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateGroupOutcome.IsSuccess();
                if (success) {
                    createGroupResult.fromAWS(awsCreateGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGroupOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGroup error: " + awsCreateGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateGroup(
        UObject *WorldContextObject,
        bool &success,
        FCreateGroupRequest createGroupRequest,
        FCreateGroupResult &createGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                createGroupRequest,
                createGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateIdentityProviderAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateIdentityProviderRequest createIdentityProviderRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateIdentityProviderRequest createIdentityProviderRequest,
        FCreateIdentityProviderResult &createIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createIdentityProviderRequest(createIdentityProviderRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateIdentityProviderAsync(
            createIdentityProviderRequest.toAWS(),
            [&success, &createIdentityProviderResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateIdentityProviderRequest &awsCreateIdentityProviderRequest,
                const Aws::CognitoIdentityProvider::Model::CreateIdentityProviderOutcome &awsCreateIdentityProviderOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateIdentityProviderOutcome.IsSuccess();
                if (success) {
                    createIdentityProviderResult.fromAWS(awsCreateIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("CreateIdentityProvider error: " + awsCreateIdentityProviderOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FCreateIdentityProviderRequest createIdentityProviderRequest,
        FCreateIdentityProviderResult &createIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                createIdentityProviderRequest,
                createIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateResourceServerAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateResourceServerRequest createResourceServerRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateResourceServerRequest createResourceServerRequest,
        FCreateResourceServerResult &createResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createResourceServerRequest(createResourceServerRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateResourceServerAsync(
            createResourceServerRequest.toAWS(),
            [&success, &createResourceServerResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateResourceServerRequest &awsCreateResourceServerRequest,
                const Aws::CognitoIdentityProvider::Model::CreateResourceServerOutcome &awsCreateResourceServerOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateResourceServerOutcome.IsSuccess();
                if (success) {
                    createResourceServerResult.fromAWS(awsCreateResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("CreateResourceServer error: " + awsCreateResourceServerOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FCreateResourceServerRequest createResourceServerRequest,
        FCreateResourceServerResult &createResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                createResourceServerRequest,
                createResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateUserImportJobAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateUserImportJobRequest createUserImportJobRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserImportJobRequest createUserImportJobRequest,
        FCreateUserImportJobResult &createUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createUserImportJobRequest(createUserImportJobRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateUserImportJobAsync(
            createUserImportJobRequest.toAWS(),
            [&success, &createUserImportJobResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateUserImportJobRequest &awsCreateUserImportJobRequest,
                const Aws::CognitoIdentityProvider::Model::CreateUserImportJobOutcome &awsCreateUserImportJobOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateUserImportJobOutcome.IsSuccess();
                if (success) {
                    createUserImportJobResult.fromAWS(awsCreateUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserImportJob error: " + awsCreateUserImportJobOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserImportJobRequest createUserImportJobRequest,
        FCreateUserImportJobResult &createUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserImportJobRequest,
                createUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateUserPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateUserPoolRequest createUserPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolRequest createUserPoolRequest,
        FCreateUserPoolResult &createUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createUserPoolRequest(createUserPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateUserPoolAsync(
            createUserPoolRequest.toAWS(),
            [&success, &createUserPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolRequest &awsCreateUserPoolRequest,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolOutcome &awsCreateUserPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateUserPoolOutcome.IsSuccess();
                if (success) {
                    createUserPoolResult.fromAWS(awsCreateUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPool error: " + awsCreateUserPoolOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPool(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolRequest createUserPoolRequest,
        FCreateUserPoolResult &createUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolRequest,
                createUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateUserPoolClientAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateUserPoolClientRequest createUserPoolClientRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolClientRequest createUserPoolClientRequest,
        FCreateUserPoolClientResult &createUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createUserPoolClientRequest(createUserPoolClientRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateUserPoolClientAsync(
            createUserPoolClientRequest.toAWS(),
            [&success, &createUserPoolClientResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolClientRequest &awsCreateUserPoolClientRequest,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolClientOutcome &awsCreateUserPoolClientOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateUserPoolClientOutcome.IsSuccess();
                if (success) {
                    createUserPoolClientResult.fromAWS(awsCreateUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPoolClient error: " + awsCreateUserPoolClientOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolClientRequest createUserPoolClientRequest,
        FCreateUserPoolClientResult &createUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolClientRequest,
                createUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FCreateUserPoolDomainAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCreateUserPoolDomainRequest createUserPoolDomainRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FCreateUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolDomainRequest createUserPoolDomainRequest,
        FCreateUserPoolDomainResult &createUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), createUserPoolDomainRequest(createUserPoolDomainRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->CreateUserPoolDomainAsync(
            createUserPoolDomainRequest.toAWS(),
            [&success, &createUserPoolDomainResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainRequest &awsCreateUserPoolDomainRequest,
                const Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainOutcome &awsCreateUserPoolDomainOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsCreateUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    createUserPoolDomainResult.fromAWS(awsCreateUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPoolDomain error: " + awsCreateUserPoolDomainOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolDomainRequest createUserPoolDomainRequest,
        FCreateUserPoolDomainResult &createUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolDomainRequest,
                createUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteGroupRequest deleteGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteGroupRequest deleteGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteGroupRequest(deleteGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteGroupAsync(
            deleteGroupRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteGroupRequest &awsDeleteGroupRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteGroupOutcome &awsDeleteGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteGroupOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteGroupOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteGroup error: " + awsDeleteGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteGroup(
        UObject *WorldContextObject,
        bool &success,
        FDeleteGroupRequest deleteGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteIdentityProviderAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteIdentityProviderRequest deleteIdentityProviderRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteIdentityProviderRequest deleteIdentityProviderRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteIdentityProviderRequest(deleteIdentityProviderRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteIdentityProviderAsync(
            deleteIdentityProviderRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteIdentityProviderRequest &awsDeleteIdentityProviderRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteIdentityProviderOutcome &awsDeleteIdentityProviderOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteIdentityProviderOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentityProvider error: " + awsDeleteIdentityProviderOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentityProviderRequest deleteIdentityProviderRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteIdentityProviderRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteResourceServerAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteResourceServerRequest deleteResourceServerRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteResourceServerRequest deleteResourceServerRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteResourceServerRequest(deleteResourceServerRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteResourceServerAsync(
            deleteResourceServerRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteResourceServerRequest &awsDeleteResourceServerRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteResourceServerOutcome &awsDeleteResourceServerOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteResourceServerOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteResourceServer error: " + awsDeleteResourceServerOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FDeleteResourceServerRequest deleteResourceServerRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteResourceServerRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteUserRequest deleteUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserRequest deleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteUserRequest(deleteUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteUserAsync(
            deleteUserRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteUserRequest &awsDeleteUserRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteUserOutcome &awsDeleteUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteUserOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUser error: " + awsDeleteUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUser(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserRequest deleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteUserAttributesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteUserAttributesRequest deleteUserAttributesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserAttributesRequest deleteUserAttributesRequest,
        FDeleteUserAttributesResult &deleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteUserAttributesRequest(deleteUserAttributesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteUserAttributesAsync(
            deleteUserAttributesRequest.toAWS(),
            [&success, &deleteUserAttributesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteUserAttributesRequest &awsDeleteUserAttributesRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteUserAttributesOutcome &awsDeleteUserAttributesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteUserAttributesOutcome.IsSuccess();
                if (success) {
                    deleteUserAttributesResult.fromAWS(awsDeleteUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserAttributes error: " + awsDeleteUserAttributesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserAttributesRequest deleteUserAttributesRequest,
        FDeleteUserAttributesResult &deleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserAttributesRequest,
                deleteUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteUserPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteUserPoolRequest deleteUserPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolRequest deleteUserPoolRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteUserPoolRequest(deleteUserPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteUserPoolAsync(
            deleteUserPoolRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolRequest &awsDeleteUserPoolRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolOutcome &awsDeleteUserPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteUserPoolOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPool error: " + awsDeleteUserPoolOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPool(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolRequest deleteUserPoolRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteUserPoolClientAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteUserPoolClientRequest deleteUserPoolClientRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolClientRequest deleteUserPoolClientRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteUserPoolClientRequest(deleteUserPoolClientRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteUserPoolClientAsync(
            deleteUserPoolClientRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolClientRequest &awsDeleteUserPoolClientRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolClientOutcome &awsDeleteUserPoolClientOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteUserPoolClientOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPoolClient error: " + awsDeleteUserPoolClientOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolClientRequest deleteUserPoolClientRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolClientRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDeleteUserPoolDomainAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDeleteUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest,
        FDeleteUserPoolDomainResult &deleteUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), deleteUserPoolDomainRequest(deleteUserPoolDomainRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DeleteUserPoolDomainAsync(
            deleteUserPoolDomainRequest.toAWS(),
            [&success, &deleteUserPoolDomainResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainRequest &awsDeleteUserPoolDomainRequest,
                const Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainOutcome &awsDeleteUserPoolDomainOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDeleteUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    deleteUserPoolDomainResult.fromAWS(awsDeleteUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPoolDomain error: " + awsDeleteUserPoolDomainOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest,
        FDeleteUserPoolDomainResult &deleteUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolDomainRequest,
                deleteUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeIdentityProviderAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeIdentityProviderRequest describeIdentityProviderRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeIdentityProviderRequest describeIdentityProviderRequest,
        FDescribeIdentityProviderResult &describeIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeIdentityProviderRequest(describeIdentityProviderRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeIdentityProviderAsync(
            describeIdentityProviderRequest.toAWS(),
            [&success, &describeIdentityProviderResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderRequest &awsDescribeIdentityProviderRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderOutcome &awsDescribeIdentityProviderOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeIdentityProviderOutcome.IsSuccess();
                if (success) {
                    describeIdentityProviderResult.fromAWS(awsDescribeIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentityProvider error: " + awsDescribeIdentityProviderOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityProviderRequest describeIdentityProviderRequest,
        FDescribeIdentityProviderResult &describeIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                describeIdentityProviderRequest,
                describeIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeResourceServerAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeResourceServerRequest describeResourceServerRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeResourceServerRequest describeResourceServerRequest,
        FDescribeResourceServerResult &describeResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeResourceServerRequest(describeResourceServerRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeResourceServerAsync(
            describeResourceServerRequest.toAWS(),
            [&success, &describeResourceServerResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeResourceServerRequest &awsDescribeResourceServerRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeResourceServerOutcome &awsDescribeResourceServerOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeResourceServerOutcome.IsSuccess();
                if (success) {
                    describeResourceServerResult.fromAWS(awsDescribeResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeResourceServer error: " + awsDescribeResourceServerOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FDescribeResourceServerRequest describeResourceServerRequest,
        FDescribeResourceServerResult &describeResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                describeResourceServerRequest,
                describeResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeRiskConfigurationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeRiskConfigurationRequest describeRiskConfigurationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeRiskConfigurationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeRiskConfigurationRequest describeRiskConfigurationRequest,
        FDescribeRiskConfigurationResult &describeRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeRiskConfigurationRequest(describeRiskConfigurationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeRiskConfigurationAsync(
            describeRiskConfigurationRequest.toAWS(),
            [&success, &describeRiskConfigurationResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationRequest &awsDescribeRiskConfigurationRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationOutcome &awsDescribeRiskConfigurationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeRiskConfigurationOutcome.IsSuccess();
                if (success) {
                    describeRiskConfigurationResult.fromAWS(awsDescribeRiskConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeRiskConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeRiskConfiguration error: " + awsDescribeRiskConfigurationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeRiskConfiguration Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeRiskConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDescribeRiskConfigurationRequest describeRiskConfigurationRequest,
        FDescribeRiskConfigurationResult &describeRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeRiskConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeRiskConfigurationAction(this->awsCognitoIdentityProviderClient,
                success,
                describeRiskConfigurationRequest,
                describeRiskConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeUserImportJobAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeUserImportJobRequest describeUserImportJobRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserImportJobRequest describeUserImportJobRequest,
        FDescribeUserImportJobResult &describeUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeUserImportJobRequest(describeUserImportJobRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeUserImportJobAsync(
            describeUserImportJobRequest.toAWS(),
            [&success, &describeUserImportJobResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeUserImportJobRequest &awsDescribeUserImportJobRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeUserImportJobOutcome &awsDescribeUserImportJobOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeUserImportJobOutcome.IsSuccess();
                if (success) {
                    describeUserImportJobResult.fromAWS(awsDescribeUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserImportJob error: " + awsDescribeUserImportJobOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserImportJobRequest describeUserImportJobRequest,
        FDescribeUserImportJobResult &describeUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserImportJobRequest,
                describeUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeUserPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeUserPoolRequest describeUserPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolRequest describeUserPoolRequest,
        FDescribeUserPoolResult &describeUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeUserPoolRequest(describeUserPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeUserPoolAsync(
            describeUserPoolRequest.toAWS(),
            [&success, &describeUserPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolRequest &awsDescribeUserPoolRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolOutcome &awsDescribeUserPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeUserPoolOutcome.IsSuccess();
                if (success) {
                    describeUserPoolResult.fromAWS(awsDescribeUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPool error: " + awsDescribeUserPoolOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPool(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolRequest describeUserPoolRequest,
        FDescribeUserPoolResult &describeUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolRequest,
                describeUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeUserPoolClientAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeUserPoolClientRequest describeUserPoolClientRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolClientRequest describeUserPoolClientRequest,
        FDescribeUserPoolClientResult &describeUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeUserPoolClientRequest(describeUserPoolClientRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeUserPoolClientAsync(
            describeUserPoolClientRequest.toAWS(),
            [&success, &describeUserPoolClientResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientRequest &awsDescribeUserPoolClientRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientOutcome &awsDescribeUserPoolClientOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeUserPoolClientOutcome.IsSuccess();
                if (success) {
                    describeUserPoolClientResult.fromAWS(awsDescribeUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPoolClient error: " + awsDescribeUserPoolClientOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolClientRequest describeUserPoolClientRequest,
        FDescribeUserPoolClientResult &describeUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolClientRequest,
                describeUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FDescribeUserPoolDomainAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FDescribeUserPoolDomainRequest describeUserPoolDomainRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FDescribeUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolDomainRequest describeUserPoolDomainRequest,
        FDescribeUserPoolDomainResult &describeUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), describeUserPoolDomainRequest(describeUserPoolDomainRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->DescribeUserPoolDomainAsync(
            describeUserPoolDomainRequest.toAWS(),
            [&success, &describeUserPoolDomainResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainRequest &awsDescribeUserPoolDomainRequest,
                const Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainOutcome &awsDescribeUserPoolDomainOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsDescribeUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    describeUserPoolDomainResult.fromAWS(awsDescribeUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPoolDomain error: " + awsDescribeUserPoolDomainOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolDomainRequest describeUserPoolDomainRequest,
        FDescribeUserPoolDomainResult &describeUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolDomainRequest,
                describeUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FForgetDeviceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FForgetDeviceRequest forgetDeviceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FForgetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FForgetDeviceRequest forgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), forgetDeviceRequest(forgetDeviceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ForgetDeviceAsync(
            forgetDeviceRequest.toAWS(),
            [&success, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ForgetDeviceRequest &awsForgetDeviceRequest,
                const Aws::CognitoIdentityProvider::Model::ForgetDeviceOutcome &awsForgetDeviceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsForgetDeviceOutcome.IsSuccess();

                errorType = fromAWS(awsForgetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("ForgetDevice error: " + awsForgetDeviceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ForgetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ForgetDevice(
        UObject *WorldContextObject,
        bool &success,
        FForgetDeviceRequest forgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FForgetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FForgetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                forgetDeviceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FForgotPasswordAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FForgotPasswordRequest forgotPasswordRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FForgotPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FForgotPasswordRequest forgotPasswordRequest,
        FForgotPasswordResult &forgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), forgotPasswordRequest(forgotPasswordRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ForgotPasswordAsync(
            forgotPasswordRequest.toAWS(),
            [&success, &forgotPasswordResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ForgotPasswordRequest &awsForgotPasswordRequest,
                const Aws::CognitoIdentityProvider::Model::ForgotPasswordOutcome &awsForgotPasswordOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsForgotPasswordOutcome.IsSuccess();
                if (success) {
                    forgotPasswordResult.fromAWS(awsForgotPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsForgotPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ForgotPassword error: " + awsForgotPasswordOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ForgotPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ForgotPassword(
        UObject *WorldContextObject,
        bool &success,
        FForgotPasswordRequest forgotPasswordRequest,
        FForgotPasswordResult &forgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FForgotPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FForgotPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                forgotPasswordRequest,
                forgotPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetCSVHeaderAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetCSVHeaderRequest getCSVHeaderRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetCSVHeaderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetCSVHeaderRequest getCSVHeaderRequest,
        FGetCSVHeaderResult &getCSVHeaderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getCSVHeaderRequest(getCSVHeaderRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetCSVHeaderAsync(
            getCSVHeaderRequest.toAWS(),
            [&success, &getCSVHeaderResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetCSVHeaderRequest &awsGetCSVHeaderRequest,
                const Aws::CognitoIdentityProvider::Model::GetCSVHeaderOutcome &awsGetCSVHeaderOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetCSVHeaderOutcome.IsSuccess();
                if (success) {
                    getCSVHeaderResult.fromAWS(awsGetCSVHeaderOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCSVHeaderOutcome.GetError().GetErrorType());
                errorMessage = ("GetCSVHeader error: " + awsGetCSVHeaderOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetCSVHeader Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetCSVHeader(
        UObject *WorldContextObject,
        bool &success,
        FGetCSVHeaderRequest getCSVHeaderRequest,
        FGetCSVHeaderResult &getCSVHeaderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCSVHeaderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCSVHeaderAction(this->awsCognitoIdentityProviderClient,
                success,
                getCSVHeaderRequest,
                getCSVHeaderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetDeviceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetDeviceRequest getDeviceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetDeviceRequest getDeviceRequest,
        FGetDeviceResult &getDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getDeviceRequest(getDeviceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetDeviceAsync(
            getDeviceRequest.toAWS(),
            [&success, &getDeviceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetDeviceRequest &awsGetDeviceRequest,
                const Aws::CognitoIdentityProvider::Model::GetDeviceOutcome &awsGetDeviceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetDeviceOutcome.IsSuccess();
                if (success) {
                    getDeviceResult.fromAWS(awsGetDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsGetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("GetDevice error: " + awsGetDeviceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetDevice(
        UObject *WorldContextObject,
        bool &success,
        FGetDeviceRequest getDeviceRequest,
        FGetDeviceResult &getDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                getDeviceRequest,
                getDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetGroupRequest getGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetGroupRequest getGroupRequest,
        FGetGroupResult &getGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getGroupRequest(getGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetGroupAsync(
            getGroupRequest.toAWS(),
            [&success, &getGroupResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetGroupRequest &awsGetGroupRequest,
                const Aws::CognitoIdentityProvider::Model::GetGroupOutcome &awsGetGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetGroupOutcome.IsSuccess();
                if (success) {
                    getGroupResult.fromAWS(awsGetGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsGetGroupOutcome.GetError().GetErrorType());
                errorMessage = ("GetGroup error: " + awsGetGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetGroup(
        UObject *WorldContextObject,
        bool &success,
        FGetGroupRequest getGroupRequest,
        FGetGroupResult &getGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                getGroupRequest,
                getGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetIdentityProviderByIdentifierAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetIdentityProviderByIdentifierAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest,
        FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getIdentityProviderByIdentifierRequest(getIdentityProviderByIdentifierRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetIdentityProviderByIdentifierAsync(
            getIdentityProviderByIdentifierRequest.toAWS(),
            [&success, &getIdentityProviderByIdentifierResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierRequest &awsGetIdentityProviderByIdentifierRequest,
                const Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierOutcome &awsGetIdentityProviderByIdentifierOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetIdentityProviderByIdentifierOutcome.IsSuccess();
                if (success) {
                    getIdentityProviderByIdentifierResult.fromAWS(awsGetIdentityProviderByIdentifierOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdentityProviderByIdentifierOutcome.GetError().GetErrorType());
                errorMessage = ("GetIdentityProviderByIdentifier error: " + awsGetIdentityProviderByIdentifierOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetIdentityProviderByIdentifier Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetIdentityProviderByIdentifier(
        UObject *WorldContextObject,
        bool &success,
        FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest,
        FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdentityProviderByIdentifierAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdentityProviderByIdentifierAction(this->awsCognitoIdentityProviderClient,
                success,
                getIdentityProviderByIdentifierRequest,
                getIdentityProviderByIdentifierResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetSigningCertificateAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetSigningCertificateRequest getSigningCertificateRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetSigningCertificateAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetSigningCertificateRequest getSigningCertificateRequest,
        FGetSigningCertificateResult &getSigningCertificateResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getSigningCertificateRequest(getSigningCertificateRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetSigningCertificateAsync(
            getSigningCertificateRequest.toAWS(),
            [&success, &getSigningCertificateResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetSigningCertificateRequest &awsGetSigningCertificateRequest,
                const Aws::CognitoIdentityProvider::Model::GetSigningCertificateOutcome &awsGetSigningCertificateOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetSigningCertificateOutcome.IsSuccess();
                if (success) {
                    getSigningCertificateResult.fromAWS(awsGetSigningCertificateOutcome.GetResult());
                }

                errorType = fromAWS(awsGetSigningCertificateOutcome.GetError().GetErrorType());
                errorMessage = ("GetSigningCertificate error: " + awsGetSigningCertificateOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetSigningCertificate Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetSigningCertificate(
        UObject *WorldContextObject,
        bool &success,
        FGetSigningCertificateRequest getSigningCertificateRequest,
        FGetSigningCertificateResult &getSigningCertificateResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetSigningCertificateAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetSigningCertificateAction(this->awsCognitoIdentityProviderClient,
                success,
                getSigningCertificateRequest,
                getSigningCertificateResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetUICustomizationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetUICustomizationRequest getUICustomizationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetUICustomizationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUICustomizationRequest getUICustomizationRequest,
        FGetUICustomizationResult &getUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getUICustomizationRequest(getUICustomizationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetUICustomizationAsync(
            getUICustomizationRequest.toAWS(),
            [&success, &getUICustomizationResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetUICustomizationRequest &awsGetUICustomizationRequest,
                const Aws::CognitoIdentityProvider::Model::GetUICustomizationOutcome &awsGetUICustomizationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetUICustomizationOutcome.IsSuccess();
                if (success) {
                    getUICustomizationResult.fromAWS(awsGetUICustomizationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUICustomizationOutcome.GetError().GetErrorType());
                errorMessage = ("GetUICustomization error: " + awsGetUICustomizationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUICustomization Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUICustomization(
        UObject *WorldContextObject,
        bool &success,
        FGetUICustomizationRequest getUICustomizationRequest,
        FGetUICustomizationResult &getUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUICustomizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUICustomizationAction(this->awsCognitoIdentityProviderClient,
                success,
                getUICustomizationRequest,
                getUICustomizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetUserAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetUserRequest getUserRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserRequest getUserRequest,
        FGetUserResult &getUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getUserRequest(getUserRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetUserAsync(
            getUserRequest.toAWS(),
            [&success, &getUserResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetUserRequest &awsGetUserRequest,
                const Aws::CognitoIdentityProvider::Model::GetUserOutcome &awsGetUserOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetUserOutcome.IsSuccess();
                if (success) {
                    getUserResult.fromAWS(awsGetUserOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserOutcome.GetError().GetErrorType());
                errorMessage = ("GetUser error: " + awsGetUserOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUser(
        UObject *WorldContextObject,
        bool &success,
        FGetUserRequest getUserRequest,
        FGetUserResult &getUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserRequest,
                getUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetUserAttributeVerificationCodeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetUserAttributeVerificationCodeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest,
        FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getUserAttributeVerificationCodeRequest(getUserAttributeVerificationCodeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetUserAttributeVerificationCodeAsync(
            getUserAttributeVerificationCodeRequest.toAWS(),
            [&success, &getUserAttributeVerificationCodeResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetUserAttributeVerificationCodeRequest &awsGetUserAttributeVerificationCodeRequest,
                const Aws::CognitoIdentityProvider::Model::GetUserAttributeVerificationCodeOutcome &awsGetUserAttributeVerificationCodeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetUserAttributeVerificationCodeOutcome.IsSuccess();
                if (success) {
                    getUserAttributeVerificationCodeResult.fromAWS(awsGetUserAttributeVerificationCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserAttributeVerificationCodeOutcome.GetError().GetErrorType());
                errorMessage = ("GetUserAttributeVerificationCode error: " + awsGetUserAttributeVerificationCodeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUserAttributeVerificationCode Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUserAttributeVerificationCode(
        UObject *WorldContextObject,
        bool &success,
        FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest,
        FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserAttributeVerificationCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserAttributeVerificationCodeAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserAttributeVerificationCodeRequest,
                getUserAttributeVerificationCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGetUserPoolMfaConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGetUserPoolMfaConfigAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest,
        FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), getUserPoolMfaConfigRequest(getUserPoolMfaConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GetUserPoolMfaConfigAsync(
            getUserPoolMfaConfigRequest.toAWS(),
            [&success, &getUserPoolMfaConfigResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigRequest &awsGetUserPoolMfaConfigRequest,
                const Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigOutcome &awsGetUserPoolMfaConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGetUserPoolMfaConfigOutcome.IsSuccess();
                if (success) {
                    getUserPoolMfaConfigResult.fromAWS(awsGetUserPoolMfaConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserPoolMfaConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetUserPoolMfaConfig error: " + awsGetUserPoolMfaConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUserPoolMfaConfig Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUserPoolMfaConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest,
        FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserPoolMfaConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserPoolMfaConfigAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserPoolMfaConfigRequest,
                getUserPoolMfaConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FGlobalSignOutAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FGlobalSignOutRequest globalSignOutRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FGlobalSignOutAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGlobalSignOutRequest globalSignOutRequest,
        FGlobalSignOutResult &globalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), globalSignOutRequest(globalSignOutRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->GlobalSignOutAsync(
            globalSignOutRequest.toAWS(),
            [&success, &globalSignOutResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::GlobalSignOutRequest &awsGlobalSignOutRequest,
                const Aws::CognitoIdentityProvider::Model::GlobalSignOutOutcome &awsGlobalSignOutOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsGlobalSignOutOutcome.IsSuccess();
                if (success) {
                    globalSignOutResult.fromAWS(awsGlobalSignOutOutcome.GetResult());
                }

                errorType = fromAWS(awsGlobalSignOutOutcome.GetError().GetErrorType());
                errorMessage = ("GlobalSignOut error: " + awsGlobalSignOutOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GlobalSignOut Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GlobalSignOut(
        UObject *WorldContextObject,
        bool &success,
        FGlobalSignOutRequest globalSignOutRequest,
        FGlobalSignOutResult &globalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGlobalSignOutAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGlobalSignOutAction(this->awsCognitoIdentityProviderClient,
                success,
                globalSignOutRequest,
                globalSignOutResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FInitiateAuthAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FInitiateAuthRequest initiateAuthRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FInitiateAuthAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FInitiateAuthRequest initiateAuthRequest,
        FInitiateAuthResult &initiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), initiateAuthRequest(initiateAuthRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->InitiateAuthAsync(
            initiateAuthRequest.toAWS(),
            [&success, &initiateAuthResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::InitiateAuthRequest &awsInitiateAuthRequest,
                const Aws::CognitoIdentityProvider::Model::InitiateAuthOutcome &awsInitiateAuthOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsInitiateAuthOutcome.IsSuccess();
                if (success) {
                    initiateAuthResult.fromAWS(awsInitiateAuthOutcome.GetResult());
                }

                errorType = fromAWS(awsInitiateAuthOutcome.GetError().GetErrorType());
                errorMessage = ("InitiateAuth error: " + awsInitiateAuthOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("InitiateAuth Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::InitiateAuth(
        UObject *WorldContextObject,
        bool &success,
        FInitiateAuthRequest initiateAuthRequest,
        FInitiateAuthResult &initiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FInitiateAuthAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FInitiateAuthAction(this->awsCognitoIdentityProviderClient,
                success,
                initiateAuthRequest,
                initiateAuthResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListDevicesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListDevicesRequest listDevicesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListDevicesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListDevicesRequest listDevicesRequest,
        FListDevicesResult &listDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listDevicesRequest(listDevicesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListDevicesAsync(
            listDevicesRequest.toAWS(),
            [&success, &listDevicesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListDevicesRequest &awsListDevicesRequest,
                const Aws::CognitoIdentityProvider::Model::ListDevicesOutcome &awsListDevicesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListDevicesOutcome.IsSuccess();
                if (success) {
                    listDevicesResult.fromAWS(awsListDevicesOutcome.GetResult());
                }

                errorType = fromAWS(awsListDevicesOutcome.GetError().GetErrorType());
                errorMessage = ("ListDevices error: " + awsListDevicesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListDevices Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListDevices(
        UObject *WorldContextObject,
        bool &success,
        FListDevicesRequest listDevicesRequest,
        FListDevicesResult &listDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListDevicesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListDevicesAction(this->awsCognitoIdentityProviderClient,
                success,
                listDevicesRequest,
                listDevicesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListGroupsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListGroupsRequest listGroupsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListGroupsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListGroupsRequest listGroupsRequest,
        FListGroupsResult &listGroupsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listGroupsRequest(listGroupsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListGroupsAsync(
            listGroupsRequest.toAWS(),
            [&success, &listGroupsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListGroupsRequest &awsListGroupsRequest,
                const Aws::CognitoIdentityProvider::Model::ListGroupsOutcome &awsListGroupsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListGroupsOutcome.IsSuccess();
                if (success) {
                    listGroupsResult.fromAWS(awsListGroupsOutcome.GetResult());
                }

                errorType = fromAWS(awsListGroupsOutcome.GetError().GetErrorType());
                errorMessage = ("ListGroups error: " + awsListGroupsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListGroups Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListGroups(
        UObject *WorldContextObject,
        bool &success,
        FListGroupsRequest listGroupsRequest,
        FListGroupsResult &listGroupsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListGroupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListGroupsAction(this->awsCognitoIdentityProviderClient,
                success,
                listGroupsRequest,
                listGroupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListIdentityProvidersAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListIdentityProvidersRequest listIdentityProvidersRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListIdentityProvidersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListIdentityProvidersRequest listIdentityProvidersRequest,
        FListIdentityProvidersResult &listIdentityProvidersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listIdentityProvidersRequest(listIdentityProvidersRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListIdentityProvidersAsync(
            listIdentityProvidersRequest.toAWS(),
            [&success, &listIdentityProvidersResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListIdentityProvidersRequest &awsListIdentityProvidersRequest,
                const Aws::CognitoIdentityProvider::Model::ListIdentityProvidersOutcome &awsListIdentityProvidersOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListIdentityProvidersOutcome.IsSuccess();
                if (success) {
                    listIdentityProvidersResult.fromAWS(awsListIdentityProvidersOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentityProvidersOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentityProviders error: " + awsListIdentityProvidersOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListIdentityProviders Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListIdentityProviders(
        UObject *WorldContextObject,
        bool &success,
        FListIdentityProvidersRequest listIdentityProvidersRequest,
        FListIdentityProvidersResult &listIdentityProvidersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentityProvidersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentityProvidersAction(this->awsCognitoIdentityProviderClient,
                success,
                listIdentityProvidersRequest,
                listIdentityProvidersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListResourceServersAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListResourceServersRequest listResourceServersRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListResourceServersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListResourceServersRequest listResourceServersRequest,
        FListResourceServersResult &listResourceServersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listResourceServersRequest(listResourceServersRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListResourceServersAsync(
            listResourceServersRequest.toAWS(),
            [&success, &listResourceServersResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListResourceServersRequest &awsListResourceServersRequest,
                const Aws::CognitoIdentityProvider::Model::ListResourceServersOutcome &awsListResourceServersOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListResourceServersOutcome.IsSuccess();
                if (success) {
                    listResourceServersResult.fromAWS(awsListResourceServersOutcome.GetResult());
                }

                errorType = fromAWS(awsListResourceServersOutcome.GetError().GetErrorType());
                errorMessage = ("ListResourceServers error: " + awsListResourceServersOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListResourceServers Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListResourceServers(
        UObject *WorldContextObject,
        bool &success,
        FListResourceServersRequest listResourceServersRequest,
        FListResourceServersResult &listResourceServersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListResourceServersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListResourceServersAction(this->awsCognitoIdentityProviderClient,
                success,
                listResourceServersRequest,
                listResourceServersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListTagsForResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListTagsForResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdpListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listTagsForResourceRequest(listTagsForResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListTagsForResourceAsync(
            listTagsForResourceRequest.toAWS(),
            [&success, &listTagsForResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListTagsForResourceRequest &awsListTagsForResourceRequest,
                const Aws::CognitoIdentityProvider::Model::ListTagsForResourceOutcome &awsListTagsForResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListTagsForResourceOutcome.IsSuccess();
                if (success) {
                    listTagsForResourceResult.fromAWS(awsListTagsForResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsForResourceOutcome.GetError().GetErrorType());
                errorMessage = ("ListTagsForResource error: " + awsListTagsForResourceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTagsForResource Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListTagsForResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdpListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsForResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsForResourceAction(this->awsCognitoIdentityProviderClient,
                success,
                listTagsForResourceRequest,
                listTagsForResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListUserImportJobsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListUserImportJobsRequest listUserImportJobsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListUserImportJobsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserImportJobsRequest listUserImportJobsRequest,
        FListUserImportJobsResult &listUserImportJobsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listUserImportJobsRequest(listUserImportJobsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListUserImportJobsAsync(
            listUserImportJobsRequest.toAWS(),
            [&success, &listUserImportJobsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListUserImportJobsRequest &awsListUserImportJobsRequest,
                const Aws::CognitoIdentityProvider::Model::ListUserImportJobsOutcome &awsListUserImportJobsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListUserImportJobsOutcome.IsSuccess();
                if (success) {
                    listUserImportJobsResult.fromAWS(awsListUserImportJobsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserImportJobsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserImportJobs error: " + awsListUserImportJobsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserImportJobs Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserImportJobs(
        UObject *WorldContextObject,
        bool &success,
        FListUserImportJobsRequest listUserImportJobsRequest,
        FListUserImportJobsResult &listUserImportJobsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserImportJobsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserImportJobsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserImportJobsRequest,
                listUserImportJobsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListUserPoolClientsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListUserPoolClientsRequest listUserPoolClientsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListUserPoolClientsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserPoolClientsRequest listUserPoolClientsRequest,
        FListUserPoolClientsResult &listUserPoolClientsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listUserPoolClientsRequest(listUserPoolClientsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListUserPoolClientsAsync(
            listUserPoolClientsRequest.toAWS(),
            [&success, &listUserPoolClientsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListUserPoolClientsRequest &awsListUserPoolClientsRequest,
                const Aws::CognitoIdentityProvider::Model::ListUserPoolClientsOutcome &awsListUserPoolClientsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListUserPoolClientsOutcome.IsSuccess();
                if (success) {
                    listUserPoolClientsResult.fromAWS(awsListUserPoolClientsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserPoolClientsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserPoolClients error: " + awsListUserPoolClientsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserPoolClients Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserPoolClients(
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolClientsRequest listUserPoolClientsRequest,
        FListUserPoolClientsResult &listUserPoolClientsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserPoolClientsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserPoolClientsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserPoolClientsRequest,
                listUserPoolClientsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListUserPoolsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListUserPoolsRequest listUserPoolsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListUserPoolsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserPoolsRequest listUserPoolsRequest,
        FListUserPoolsResult &listUserPoolsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listUserPoolsRequest(listUserPoolsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListUserPoolsAsync(
            listUserPoolsRequest.toAWS(),
            [&success, &listUserPoolsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListUserPoolsRequest &awsListUserPoolsRequest,
                const Aws::CognitoIdentityProvider::Model::ListUserPoolsOutcome &awsListUserPoolsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListUserPoolsOutcome.IsSuccess();
                if (success) {
                    listUserPoolsResult.fromAWS(awsListUserPoolsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserPoolsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserPools error: " + awsListUserPoolsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserPools Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserPools(
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolsRequest listUserPoolsRequest,
        FListUserPoolsResult &listUserPoolsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserPoolsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserPoolsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserPoolsRequest,
                listUserPoolsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListUsersAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListUsersRequest listUsersRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListUsersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUsersRequest listUsersRequest,
        FListUsersResult &listUsersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listUsersRequest(listUsersRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListUsersAsync(
            listUsersRequest.toAWS(),
            [&success, &listUsersResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListUsersRequest &awsListUsersRequest,
                const Aws::CognitoIdentityProvider::Model::ListUsersOutcome &awsListUsersOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListUsersOutcome.IsSuccess();
                if (success) {
                    listUsersResult.fromAWS(awsListUsersOutcome.GetResult());
                }

                errorType = fromAWS(awsListUsersOutcome.GetError().GetErrorType());
                errorMessage = ("ListUsers error: " + awsListUsersOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUsers Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUsers(
        UObject *WorldContextObject,
        bool &success,
        FListUsersRequest listUsersRequest,
        FListUsersResult &listUsersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUsersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUsersAction(this->awsCognitoIdentityProviderClient,
                success,
                listUsersRequest,
                listUsersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FListUsersInGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FListUsersInGroupRequest listUsersInGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FListUsersInGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUsersInGroupRequest listUsersInGroupRequest,
        FListUsersInGroupResult &listUsersInGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), listUsersInGroupRequest(listUsersInGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ListUsersInGroupAsync(
            listUsersInGroupRequest.toAWS(),
            [&success, &listUsersInGroupResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ListUsersInGroupRequest &awsListUsersInGroupRequest,
                const Aws::CognitoIdentityProvider::Model::ListUsersInGroupOutcome &awsListUsersInGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsListUsersInGroupOutcome.IsSuccess();
                if (success) {
                    listUsersInGroupResult.fromAWS(awsListUsersInGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsListUsersInGroupOutcome.GetError().GetErrorType());
                errorMessage = ("ListUsersInGroup error: " + awsListUsersInGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUsersInGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUsersInGroup(
        UObject *WorldContextObject,
        bool &success,
        FListUsersInGroupRequest listUsersInGroupRequest,
        FListUsersInGroupResult &listUsersInGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUsersInGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUsersInGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                listUsersInGroupRequest,
                listUsersInGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FResendConfirmationCodeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FResendConfirmationCodeRequest resendConfirmationCodeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FResendConfirmationCodeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FResendConfirmationCodeRequest resendConfirmationCodeRequest,
        FResendConfirmationCodeResult &resendConfirmationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), resendConfirmationCodeRequest(resendConfirmationCodeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->ResendConfirmationCodeAsync(
            resendConfirmationCodeRequest.toAWS(),
            [&success, &resendConfirmationCodeResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::ResendConfirmationCodeRequest &awsResendConfirmationCodeRequest,
                const Aws::CognitoIdentityProvider::Model::ResendConfirmationCodeOutcome &awsResendConfirmationCodeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsResendConfirmationCodeOutcome.IsSuccess();
                if (success) {
                    resendConfirmationCodeResult.fromAWS(awsResendConfirmationCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsResendConfirmationCodeOutcome.GetError().GetErrorType());
                errorMessage = ("ResendConfirmationCode error: " + awsResendConfirmationCodeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ResendConfirmationCode Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ResendConfirmationCode(
        UObject *WorldContextObject,
        bool &success,
        FResendConfirmationCodeRequest resendConfirmationCodeRequest,
        FResendConfirmationCodeResult &resendConfirmationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FResendConfirmationCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FResendConfirmationCodeAction(this->awsCognitoIdentityProviderClient,
                success,
                resendConfirmationCodeRequest,
                resendConfirmationCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FRespondToAuthChallengeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FRespondToAuthChallengeRequest respondToAuthChallengeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FRespondToAuthChallengeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FRespondToAuthChallengeRequest respondToAuthChallengeRequest,
        FRespondToAuthChallengeResult &respondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), respondToAuthChallengeRequest(respondToAuthChallengeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->RespondToAuthChallengeAsync(
            respondToAuthChallengeRequest.toAWS(),
            [&success, &respondToAuthChallengeResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeRequest &awsRespondToAuthChallengeRequest,
                const Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeOutcome &awsRespondToAuthChallengeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsRespondToAuthChallengeOutcome.IsSuccess();
                if (success) {
                    respondToAuthChallengeResult.fromAWS(awsRespondToAuthChallengeOutcome.GetResult());
                }

                errorType = fromAWS(awsRespondToAuthChallengeOutcome.GetError().GetErrorType());
                errorMessage = ("RespondToAuthChallenge error: " + awsRespondToAuthChallengeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RespondToAuthChallenge Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::RespondToAuthChallenge(
        UObject *WorldContextObject,
        bool &success,
        FRespondToAuthChallengeRequest respondToAuthChallengeRequest,
        FRespondToAuthChallengeResult &respondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRespondToAuthChallengeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRespondToAuthChallengeAction(this->awsCognitoIdentityProviderClient,
                success,
                respondToAuthChallengeRequest,
                respondToAuthChallengeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSetRiskConfigurationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSetRiskConfigurationRequest setRiskConfigurationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetRiskConfigurationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetRiskConfigurationRequest setRiskConfigurationRequest,
        FSetRiskConfigurationResult &setRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), setRiskConfigurationRequest(setRiskConfigurationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SetRiskConfigurationAsync(
            setRiskConfigurationRequest.toAWS(),
            [&success, &setRiskConfigurationResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SetRiskConfigurationRequest &awsSetRiskConfigurationRequest,
                const Aws::CognitoIdentityProvider::Model::SetRiskConfigurationOutcome &awsSetRiskConfigurationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetRiskConfigurationOutcome.IsSuccess();
                if (success) {
                    setRiskConfigurationResult.fromAWS(awsSetRiskConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsSetRiskConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("SetRiskConfiguration error: " + awsSetRiskConfigurationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetRiskConfiguration Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetRiskConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FSetRiskConfigurationRequest setRiskConfigurationRequest,
        FSetRiskConfigurationResult &setRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetRiskConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetRiskConfigurationAction(this->awsCognitoIdentityProviderClient,
                success,
                setRiskConfigurationRequest,
                setRiskConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSetUICustomizationAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSetUICustomizationRequest setUICustomizationRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetUICustomizationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUICustomizationRequest setUICustomizationRequest,
        FSetUICustomizationResult &setUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), setUICustomizationRequest(setUICustomizationRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SetUICustomizationAsync(
            setUICustomizationRequest.toAWS(),
            [&success, &setUICustomizationResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SetUICustomizationRequest &awsSetUICustomizationRequest,
                const Aws::CognitoIdentityProvider::Model::SetUICustomizationOutcome &awsSetUICustomizationOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetUICustomizationOutcome.IsSuccess();
                if (success) {
                    setUICustomizationResult.fromAWS(awsSetUICustomizationOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUICustomizationOutcome.GetError().GetErrorType());
                errorMessage = ("SetUICustomization error: " + awsSetUICustomizationOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUICustomization Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUICustomization(
        UObject *WorldContextObject,
        bool &success,
        FSetUICustomizationRequest setUICustomizationRequest,
        FSetUICustomizationResult &setUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUICustomizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUICustomizationAction(this->awsCognitoIdentityProviderClient,
                success,
                setUICustomizationRequest,
                setUICustomizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSetUserMFAPreferenceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetUserMFAPreferenceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest,
        FSetUserMFAPreferenceResult &setUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), setUserMFAPreferenceRequest(setUserMFAPreferenceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SetUserMFAPreferenceAsync(
            setUserMFAPreferenceRequest.toAWS(),
            [&success, &setUserMFAPreferenceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceRequest &awsSetUserMFAPreferenceRequest,
                const Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceOutcome &awsSetUserMFAPreferenceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetUserMFAPreferenceOutcome.IsSuccess();
                if (success) {
                    setUserMFAPreferenceResult.fromAWS(awsSetUserMFAPreferenceOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserMFAPreferenceOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserMFAPreference error: " + awsSetUserMFAPreferenceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserMFAPreference Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserMFAPreference(
        UObject *WorldContextObject,
        bool &success,
        FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest,
        FSetUserMFAPreferenceResult &setUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserMFAPreferenceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserMFAPreferenceAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserMFAPreferenceRequest,
                setUserMFAPreferenceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSetUserPoolMfaConfigAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetUserPoolMfaConfigAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest,
        FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), setUserPoolMfaConfigRequest(setUserPoolMfaConfigRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SetUserPoolMfaConfigAsync(
            setUserPoolMfaConfigRequest.toAWS(),
            [&success, &setUserPoolMfaConfigResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigRequest &awsSetUserPoolMfaConfigRequest,
                const Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigOutcome &awsSetUserPoolMfaConfigOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetUserPoolMfaConfigOutcome.IsSuccess();
                if (success) {
                    setUserPoolMfaConfigResult.fromAWS(awsSetUserPoolMfaConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserPoolMfaConfigOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserPoolMfaConfig error: " + awsSetUserPoolMfaConfigOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserPoolMfaConfig Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserPoolMfaConfig(
        UObject *WorldContextObject,
        bool &success,
        FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest,
        FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserPoolMfaConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserPoolMfaConfigAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserPoolMfaConfigRequest,
                setUserPoolMfaConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSetUserSettingsAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSetUserSettingsRequest setUserSettingsRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSetUserSettingsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserSettingsRequest setUserSettingsRequest,
        FSetUserSettingsResult &setUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), setUserSettingsRequest(setUserSettingsRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SetUserSettingsAsync(
            setUserSettingsRequest.toAWS(),
            [&success, &setUserSettingsResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SetUserSettingsRequest &awsSetUserSettingsRequest,
                const Aws::CognitoIdentityProvider::Model::SetUserSettingsOutcome &awsSetUserSettingsOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSetUserSettingsOutcome.IsSuccess();
                if (success) {
                    setUserSettingsResult.fromAWS(awsSetUserSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserSettings error: " + awsSetUserSettingsOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserSettings Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserSettings(
        UObject *WorldContextObject,
        bool &success,
        FSetUserSettingsRequest setUserSettingsRequest,
        FSetUserSettingsResult &setUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserSettingsAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserSettingsRequest,
                setUserSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FSignUpAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FSignUpRequest signUpRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSignUpRequest signUpRequest,
        FSignUpResult &signUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), signUpRequest(signUpRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->SignUpAsync(
            signUpRequest.toAWS(),
            [&success, &signUpResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::SignUpRequest &awsSignUpRequest,
                const Aws::CognitoIdentityProvider::Model::SignUpOutcome &awsSignUpOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsSignUpOutcome.IsSuccess();
                if (success) {
                    signUpResult.fromAWS(awsSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("SignUp error: " + awsSignUpOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SignUp(
        UObject *WorldContextObject,
        bool &success,
        FSignUpRequest signUpRequest,
        FSignUpResult &signUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                signUpRequest,
                signUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FStartUserImportJobAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FStartUserImportJobRequest startUserImportJobRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FStartUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FStartUserImportJobRequest startUserImportJobRequest,
        FStartUserImportJobResult &startUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), startUserImportJobRequest(startUserImportJobRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->StartUserImportJobAsync(
            startUserImportJobRequest.toAWS(),
            [&success, &startUserImportJobResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::StartUserImportJobRequest &awsStartUserImportJobRequest,
                const Aws::CognitoIdentityProvider::Model::StartUserImportJobOutcome &awsStartUserImportJobOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsStartUserImportJobOutcome.IsSuccess();
                if (success) {
                    startUserImportJobResult.fromAWS(awsStartUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsStartUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("StartUserImportJob error: " + awsStartUserImportJobOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::StartUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FStartUserImportJobRequest startUserImportJobRequest,
        FStartUserImportJobResult &startUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                startUserImportJobRequest,
                startUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FStopUserImportJobAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FStopUserImportJobRequest stopUserImportJobRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FStopUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FStopUserImportJobRequest stopUserImportJobRequest,
        FStopUserImportJobResult &stopUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), stopUserImportJobRequest(stopUserImportJobRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->StopUserImportJobAsync(
            stopUserImportJobRequest.toAWS(),
            [&success, &stopUserImportJobResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::StopUserImportJobRequest &awsStopUserImportJobRequest,
                const Aws::CognitoIdentityProvider::Model::StopUserImportJobOutcome &awsStopUserImportJobOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsStopUserImportJobOutcome.IsSuccess();
                if (success) {
                    stopUserImportJobResult.fromAWS(awsStopUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsStopUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("StopUserImportJob error: " + awsStopUserImportJobOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StopUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::StopUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FStopUserImportJobRequest stopUserImportJobRequest,
        FStopUserImportJobResult &stopUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStopUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStopUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                stopUserImportJobRequest,
                stopUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCognitoIdpTagResourceRequest tagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FTagResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpTagResourceRequest tagResourceRequest,
        FCognitoIdpTagResourceResult &tagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), tagResourceRequest(tagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->TagResourceAsync(
            tagResourceRequest.toAWS(),
            [&success, &tagResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::TagResourceRequest &awsTagResourceRequest,
                const Aws::CognitoIdentityProvider::Model::TagResourceOutcome &awsTagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsTagResourceOutcome.IsSuccess();
                if (success) {
                    tagResourceResult.fromAWS(awsTagResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsTagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("TagResource error: " + awsTagResourceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("TagResource Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpTagResourceRequest tagResourceRequest,
        FCognitoIdpTagResourceResult &tagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsCognitoIdentityProviderClient,
                success,
                tagResourceRequest,
                tagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FCognitoIdpUntagResourceRequest untagResourceRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUntagResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpUntagResourceRequest untagResourceRequest,
        FCognitoIdpUntagResourceResult &untagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), untagResourceRequest(untagResourceRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UntagResourceAsync(
            untagResourceRequest.toAWS(),
            [&success, &untagResourceResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UntagResourceRequest &awsUntagResourceRequest,
                const Aws::CognitoIdentityProvider::Model::UntagResourceOutcome &awsUntagResourceOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUntagResourceOutcome.IsSuccess();
                if (success) {
                    untagResourceResult.fromAWS(awsUntagResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsUntagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("UntagResource error: " + awsUntagResourceOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UntagResource Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpUntagResourceRequest untagResourceRequest,
        FCognitoIdpUntagResourceResult &untagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsCognitoIdentityProviderClient,
                success,
                untagResourceRequest,
                untagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateAuthEventFeedbackAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateAuthEventFeedbackAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest,
        FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateAuthEventFeedbackRequest(updateAuthEventFeedbackRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateAuthEventFeedbackAsync(
            updateAuthEventFeedbackRequest.toAWS(),
            [&success, &updateAuthEventFeedbackResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackRequest &awsUpdateAuthEventFeedbackRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackOutcome &awsUpdateAuthEventFeedbackOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateAuthEventFeedbackOutcome.IsSuccess();
                if (success) {
                    updateAuthEventFeedbackResult.fromAWS(awsUpdateAuthEventFeedbackOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateAuthEventFeedbackOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateAuthEventFeedback error: " + awsUpdateAuthEventFeedbackOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateAuthEventFeedback Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateAuthEventFeedback(
        UObject *WorldContextObject,
        bool &success,
        FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest,
        FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateAuthEventFeedbackAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateAuthEventFeedbackAction(this->awsCognitoIdentityProviderClient,
                success,
                updateAuthEventFeedbackRequest,
                updateAuthEventFeedbackResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateDeviceStatusAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateDeviceStatusRequest updateDeviceStatusRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateDeviceStatusAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateDeviceStatusRequest updateDeviceStatusRequest,
        FUpdateDeviceStatusResult &updateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateDeviceStatusRequest(updateDeviceStatusRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateDeviceStatusAsync(
            updateDeviceStatusRequest.toAWS(),
            [&success, &updateDeviceStatusResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusRequest &awsUpdateDeviceStatusRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusOutcome &awsUpdateDeviceStatusOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateDeviceStatusOutcome.IsSuccess();
                if (success) {
                    updateDeviceStatusResult.fromAWS(awsUpdateDeviceStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateDeviceStatusOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateDeviceStatus error: " + awsUpdateDeviceStatusOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateDeviceStatus Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateDeviceStatus(
        UObject *WorldContextObject,
        bool &success,
        FUpdateDeviceStatusRequest updateDeviceStatusRequest,
        FUpdateDeviceStatusResult &updateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateDeviceStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateDeviceStatusAction(this->awsCognitoIdentityProviderClient,
                success,
                updateDeviceStatusRequest,
                updateDeviceStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateGroupAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateGroupRequest updateGroupRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateGroupRequest updateGroupRequest,
        FUpdateGroupResult &updateGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateGroupRequest(updateGroupRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateGroupAsync(
            updateGroupRequest.toAWS(),
            [&success, &updateGroupResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateGroupRequest &awsUpdateGroupRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateGroupOutcome &awsUpdateGroupOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateGroupOutcome.IsSuccess();
                if (success) {
                    updateGroupResult.fromAWS(awsUpdateGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGroupOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGroup error: " + awsUpdateGroupOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateGroup(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGroupRequest updateGroupRequest,
        FUpdateGroupResult &updateGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                updateGroupRequest,
                updateGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateIdentityProviderAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateIdentityProviderRequest updateIdentityProviderRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateIdentityProviderRequest updateIdentityProviderRequest,
        FUpdateIdentityProviderResult &updateIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateIdentityProviderRequest(updateIdentityProviderRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateIdentityProviderAsync(
            updateIdentityProviderRequest.toAWS(),
            [&success, &updateIdentityProviderResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderRequest &awsUpdateIdentityProviderRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderOutcome &awsUpdateIdentityProviderOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateIdentityProviderOutcome.IsSuccess();
                if (success) {
                    updateIdentityProviderResult.fromAWS(awsUpdateIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateIdentityProvider error: " + awsUpdateIdentityProviderOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FUpdateIdentityProviderRequest updateIdentityProviderRequest,
        FUpdateIdentityProviderResult &updateIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                updateIdentityProviderRequest,
                updateIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateResourceServerAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateResourceServerRequest updateResourceServerRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateResourceServerRequest updateResourceServerRequest,
        FUpdateResourceServerResult &updateResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateResourceServerRequest(updateResourceServerRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateResourceServerAsync(
            updateResourceServerRequest.toAWS(),
            [&success, &updateResourceServerResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateResourceServerRequest &awsUpdateResourceServerRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateResourceServerOutcome &awsUpdateResourceServerOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateResourceServerOutcome.IsSuccess();
                if (success) {
                    updateResourceServerResult.fromAWS(awsUpdateResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateResourceServer error: " + awsUpdateResourceServerOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FUpdateResourceServerRequest updateResourceServerRequest,
        FUpdateResourceServerResult &updateResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                updateResourceServerRequest,
                updateResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateUserAttributesAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateUserAttributesRequest updateUserAttributesRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserAttributesRequest updateUserAttributesRequest,
        FUpdateUserAttributesResult &updateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateUserAttributesRequest(updateUserAttributesRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateUserAttributesAsync(
            updateUserAttributesRequest.toAWS(),
            [&success, &updateUserAttributesResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateUserAttributesRequest &awsUpdateUserAttributesRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateUserAttributesOutcome &awsUpdateUserAttributesOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateUserAttributesOutcome.IsSuccess();
                if (success) {
                    updateUserAttributesResult.fromAWS(awsUpdateUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserAttributes error: " + awsUpdateUserAttributesOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserAttributesRequest updateUserAttributesRequest,
        FUpdateUserAttributesResult &updateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserAttributesRequest,
                updateUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateUserPoolAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateUserPoolRequest updateUserPoolRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolRequest updateUserPoolRequest,
        FUpdateUserPoolResult &updateUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateUserPoolRequest(updateUserPoolRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateUserPoolAsync(
            updateUserPoolRequest.toAWS(),
            [&success, &updateUserPoolResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolRequest &awsUpdateUserPoolRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolOutcome &awsUpdateUserPoolOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateUserPoolOutcome.IsSuccess();
                if (success) {
                    updateUserPoolResult.fromAWS(awsUpdateUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPool error: " + awsUpdateUserPoolOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPool(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolRequest updateUserPoolRequest,
        FUpdateUserPoolResult &updateUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolRequest,
                updateUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateUserPoolClientAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateUserPoolClientRequest updateUserPoolClientRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolClientRequest updateUserPoolClientRequest,
        FUpdateUserPoolClientResult &updateUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateUserPoolClientRequest(updateUserPoolClientRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateUserPoolClientAsync(
            updateUserPoolClientRequest.toAWS(),
            [&success, &updateUserPoolClientResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientRequest &awsUpdateUserPoolClientRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientOutcome &awsUpdateUserPoolClientOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateUserPoolClientOutcome.IsSuccess();
                if (success) {
                    updateUserPoolClientResult.fromAWS(awsUpdateUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPoolClient error: " + awsUpdateUserPoolClientOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolClientRequest updateUserPoolClientRequest,
        FUpdateUserPoolClientResult &updateUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolClientRequest,
                updateUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FUpdateUserPoolDomainAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FUpdateUserPoolDomainRequest updateUserPoolDomainRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FUpdateUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolDomainRequest updateUserPoolDomainRequest,
        FUpdateUserPoolDomainResult &updateUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), updateUserPoolDomainRequest(updateUserPoolDomainRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->UpdateUserPoolDomainAsync(
            updateUserPoolDomainRequest.toAWS(),
            [&success, &updateUserPoolDomainResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainRequest &awsUpdateUserPoolDomainRequest,
                const Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainOutcome &awsUpdateUserPoolDomainOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsUpdateUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    updateUserPoolDomainResult.fromAWS(awsUpdateUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPoolDomain error: " + awsUpdateUserPoolDomainOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolDomainRequest updateUserPoolDomainRequest,
        FUpdateUserPoolDomainResult &updateUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolDomainRequest,
                updateUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FVerifySoftwareTokenAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FVerifySoftwareTokenRequest verifySoftwareTokenRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FVerifySoftwareTokenAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FVerifySoftwareTokenRequest verifySoftwareTokenRequest,
        FVerifySoftwareTokenResult &verifySoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), verifySoftwareTokenRequest(verifySoftwareTokenRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->VerifySoftwareTokenAsync(
            verifySoftwareTokenRequest.toAWS(),
            [&success, &verifySoftwareTokenResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenRequest &awsVerifySoftwareTokenRequest,
                const Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenOutcome &awsVerifySoftwareTokenOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsVerifySoftwareTokenOutcome.IsSuccess();
                if (success) {
                    verifySoftwareTokenResult.fromAWS(awsVerifySoftwareTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsVerifySoftwareTokenOutcome.GetError().GetErrorType());
                errorMessage = ("VerifySoftwareToken error: " + awsVerifySoftwareTokenOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("VerifySoftwareToken Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::VerifySoftwareToken(
        UObject *WorldContextObject,
        bool &success,
        FVerifySoftwareTokenRequest verifySoftwareTokenRequest,
        FVerifySoftwareTokenResult &verifySoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FVerifySoftwareTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FVerifySoftwareTokenAction(this->awsCognitoIdentityProviderClient,
                success,
                verifySoftwareTokenRequest,
                verifySoftwareTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

class FVerifyUserAttributeAction : public FPendingLatentAction {
private:
    // trigger for finish
    bool completed = false;
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient;
    FVerifyUserAttributeRequest verifyUserAttributeRequest;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

public:
    FVerifyUserAttributeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FVerifyUserAttributeRequest verifyUserAttributeRequest,
        FVerifyUserAttributeResult &verifyUserAttributeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : CognitoIdpClient(CognitoIdpClient), verifyUserAttributeRequest(verifyUserAttributeRequest),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        CognitoIdpClient->VerifyUserAttributeAsync(
            verifyUserAttributeRequest.toAWS(),
            [&success, &verifyUserAttributeResult, &errorType, &errorMessage, this](
                const Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient,
                const Aws::CognitoIdentityProvider::Model::VerifyUserAttributeRequest &awsVerifyUserAttributeRequest,
                const Aws::CognitoIdentityProvider::Model::VerifyUserAttributeOutcome &awsVerifyUserAttributeOutcome,
                const std::shared_ptr<const Aws::Client::AsyncCallerContext> &awsAsyncCallerContext
            ) mutable -> void {
                success = awsVerifyUserAttributeOutcome.IsSuccess();
                if (success) {
                    verifyUserAttributeResult.fromAWS(awsVerifyUserAttributeOutcome.GetResult());
                }

                errorType = fromAWS(awsVerifyUserAttributeOutcome.GetError().GetErrorType());
                errorMessage = ("VerifyUserAttribute error: " + awsVerifyUserAttributeOutcome.GetError().GetMessage()).c_str();
                completed = true;
            },
            std::make_shared<Aws::Client::AsyncCallerContext>(std::to_string(LatentInfo.UUID).c_str())
        );
    }

    void UpdateOperation(FLatentResponse &Response) override {
        Response.FinishAndTriggerIf(completed, ExecutionFunction, OutputLink, CallbackTarget);
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("VerifyUserAttribute Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::VerifyUserAttribute(
        UObject *WorldContextObject,
        bool &success,
        FVerifyUserAttributeRequest verifyUserAttributeRequest,
        FVerifyUserAttributeResult &verifyUserAttributeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FVerifyUserAttributeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FVerifyUserAttributeAction(this->awsCognitoIdentityProviderClient,
                success,
                verifyUserAttributeRequest,
                verifyUserAttributeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}