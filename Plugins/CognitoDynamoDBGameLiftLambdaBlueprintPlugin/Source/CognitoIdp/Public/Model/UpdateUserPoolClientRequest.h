/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolClientRequest.h"

#endif

#include "Model/TokenValidityUnitsType.h"
#include "Model/ExplicitAuthFlowsType.h"
#include "Model/OAuthFlowType.h"
#include "Model/AnalyticsConfigurationType.h"
#include "Model/PreventUserExistenceErrorTypes.h"

#include "UpdateUserPoolClientRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolClientRequest {
    GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to update the user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The ID of the client associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The client name from the update user pool client request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientName;

    /**
    *  <p>The time limit, in days, after which the refresh token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int refreshTokenValidity;

    /**
    *  <p>The time limit, after which the access token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int accessTokenValidity;

    /**
    *  <p>The time limit, after which the ID token is no longer valid and cannot be used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int idTokenValidity;

    /**
    *  <p>The units in which the validity times are represented in. Default for RefreshToken is days, and default for ID and access tokens are hours.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FTokenValidityUnitsType tokenValidityUnits;

    /**
    *  <p>The read-only attributes of the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> readAttributes;

    /**
    *  <p>The writeable attributes of the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> writeAttributes;

    /**
    *  <p>The authentication flows that are supported by the user pool clients. Flow names without the <code>ALLOW_</code> prefix are deprecated in favor of new names with the <code>ALLOW_</code> prefix. Note that values with <code>ALLOW_</code> prefix cannot be used along with values without <code>ALLOW_</code> prefix.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ALLOW_ADMIN_USER_PASSWORD_AUTH</code>: Enable admin based user password authentication flow <code>ADMIN_USER_PASSWORD_AUTH</code>. This setting replaces the <code>ADMIN_NO_SRP_AUTH</code> setting. With this authentication flow, Cognito receives the password in the request instead of using the SRP (Secure Remote Password protocol) protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_CUSTOM_AUTH</code>: Enable Lambda trigger based authentication.</p> </li> <li> <p> <code>ALLOW_USER_PASSWORD_AUTH</code>: Enable user password-based authentication. In this flow, Cognito receives the password in the request instead of using the SRP protocol to verify passwords.</p> </li> <li> <p> <code>ALLOW_USER_SRP_AUTH</code>: Enable SRP based authentication.</p> </li> <li> <p> <code>ALLOW_REFRESH_TOKEN_AUTH</code>: Enable authflow to refresh tokens.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EExplicitAuthFlowsType> explicitAuthFlows;

    /**
    *  <p>A list of provider names for the identity providers that are supported on this client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> supportedIdentityProviders;

    /**
    *  <p>A list of allowed redirect (callback) URLs for the identity providers.</p> <p>A redirect URI must:</p> <ul> <li> <p>Be an absolute URI.</p> </li> <li> <p>Be registered with the authorization server.</p> </li> <li> <p>Not include a fragment component.</p> </li> </ul> <p>See <a href="https://tools.ietf.org/html/rfc6749#section-3.1.2">OAuth 2.0 - Redirection Endpoint</a>.</p> <p>Amazon Cognito requires HTTPS over HTTP except for http://localhost for testing purposes only.</p> <p>App callback URLs such as myapp://example are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> callbackURLs;

    /**
    *  <p>A list of allowed logout URLs for the identity providers.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> logoutURLs;

    /**
    *  <p>The default redirect URI. Must be in the <code>CallbackURLs</code> list.</p> <p>A redirect URI must:</p> <ul> <li> <p>Be an absolute URI.</p> </li> <li> <p>Be registered with the authorization server.</p> </li> <li> <p>Not include a fragment component.</p> </li> </ul> <p>See <a href="https://tools.ietf.org/html/rfc6749#section-3.1.2">OAuth 2.0 - Redirection Endpoint</a>.</p> <p>Amazon Cognito requires HTTPS over HTTP except for http://localhost for testing purposes only.</p> <p>App callback URLs such as myapp://example are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString defaultRedirectURI;

    /**
    *  <p>The allowed OAuth flows.</p> <p>Set to <code>code</code> to initiate a code grant flow, which provides an authorization code as the response. This code can be exchanged for access tokens with the token endpoint.</p> <p>Set to <code>implicit</code> to specify that the client should get the access token (and, optionally, ID token, based on scopes) directly.</p> <p>Set to <code>client_credentials</code> to specify that the client should get the access token (and, optionally, ID token, based on scopes) from the token endpoint using a combination of client and client_secret.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EOAuthFlowType> allowedOAuthFlows;

    /**
    *  <p>The allowed OAuth scopes. Possible values provided by OAuth are: <code>phone</code>, <code>email</code>, <code>openid</code>, and <code>profile</code>. Possible values provided by AWS are: <code>aws.cognito.signin.user.admin</code>. Custom scopes created in Resource Servers are also supported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> allowedOAuthScopes;

    /**
    *  <p>Set to true if the client is allowed to follow the OAuth protocol when interacting with Cognito user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool allowedOAuthFlowsUserPoolClient;

    /**
    *  <p>The Amazon Pinpoint analytics configuration for collecting metrics for this user pool.</p>  <p>In regions where Pinpoint is not available, Cognito User Pools only supports sending events to Amazon Pinpoint projects in us-east-1. In regions where Pinpoint is available, Cognito User Pools will support sending events to Amazon Pinpoint projects within that same region. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsConfigurationType analyticsConfiguration;

    /**
    *  <p>Use this setting to choose which errors and responses are returned by Cognito APIs during authentication, account confirmation, and password recovery when the user does not exist in the user pool. When set to <code>ENABLED</code> and the user does not exist, authentication returns an error indicating either the username or password was incorrect, and account confirmation and password recovery return a response indicating a code was sent to a simulated destination. When set to <code>LEGACY</code>, those APIs will return a <code>UserNotFoundException</code> exception if the user does not exist in the user pool.</p> <p>Valid values include:</p> <ul> <li> <p> <code>ENABLED</code> - This prevents user existence-related errors.</p> </li> <li> <p> <code>LEGACY</code> - This represents the old behavior of Cognito where user existence related errors are not prevented.</p> </li> </ul>  <p>After February 15th 2020, the value of <code>PreventUserExistenceErrors</code> will default to <code>ENABLED</code> for newly created user pool clients if no value is provided.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSPreventUserExistenceErrorTypes preventUserExistenceErrors;

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    public:
    Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientRequest awsUpdateUserPoolClientRequest;

		if (!(this->userPoolId.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

		if (!(this->clientId.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

		if (!(this->clientName.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetClientName(TCHAR_TO_UTF8(*this->clientName));
        }

        if (!(this->refreshTokenValidity == 0)) {
            awsUpdateUserPoolClientRequest.SetRefreshTokenValidity(this->refreshTokenValidity);
        }

        if (!(this->accessTokenValidity == 0)) {
            awsUpdateUserPoolClientRequest.SetAccessTokenValidity(this->accessTokenValidity);
        }

        if (!(this->idTokenValidity == 0)) {
            awsUpdateUserPoolClientRequest.SetIdTokenValidity(this->idTokenValidity);
        }

        if (!(this->tokenValidityUnits.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetTokenValidityUnits(this->tokenValidityUnits.toAWS());
        }

        for (const FString& elem : this->readAttributes) {
            awsUpdateUserPoolClientRequest.AddReadAttributes(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->writeAttributes) {
            awsUpdateUserPoolClientRequest.AddWriteAttributes(TCHAR_TO_UTF8(*elem));
        }

        for (const EExplicitAuthFlowsType& elem : this->explicitAuthFlows) {
		    switch(elem) {
                case EExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ADMIN_NO_SRP_AUTH);
                        break;
                case EExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::CUSTOM_AUTH_FLOW_ONLY);
                        break;
                case EExplicitAuthFlowsType::USER_PASSWORD_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_ADMIN_USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_CUSTOM_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_PASSWORD_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_USER_SRP_AUTH);
                        break;
                case EExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH:
                        awsUpdateUserPoolClientRequest.AddExplicitAuthFlows(Aws::CognitoIdentityProvider::Model::ExplicitAuthFlowsType::ALLOW_REFRESH_TOKEN_AUTH);
                        break;
                default:
                    break;
            };
        }

        for (const FString& elem : this->supportedIdentityProviders) {
            awsUpdateUserPoolClientRequest.AddSupportedIdentityProviders(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->callbackURLs) {
            awsUpdateUserPoolClientRequest.AddCallbackURLs(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->logoutURLs) {
            awsUpdateUserPoolClientRequest.AddLogoutURLs(TCHAR_TO_UTF8(*elem));
        }

		if (!(this->defaultRedirectURI.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetDefaultRedirectURI(TCHAR_TO_UTF8(*this->defaultRedirectURI));
        }

        for (const EOAuthFlowType& elem : this->allowedOAuthFlows) {
		    switch(elem) {
                case EOAuthFlowType::code:
                        awsUpdateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::code);
                        break;
                case EOAuthFlowType::implicit:
                        awsUpdateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::implicit);
                        break;
                case EOAuthFlowType::client_credentials:
                        awsUpdateUserPoolClientRequest.AddAllowedOAuthFlows(Aws::CognitoIdentityProvider::Model::OAuthFlowType::client_credentials);
                        break;
                default:
                    break;
            };
        }

        for (const FString& elem : this->allowedOAuthScopes) {
            awsUpdateUserPoolClientRequest.AddAllowedOAuthScopes(TCHAR_TO_UTF8(*elem));
        }

        if (!(false)) {
            awsUpdateUserPoolClientRequest.SetAllowedOAuthFlowsUserPoolClient(this->allowedOAuthFlowsUserPoolClient);
        }

        if (!(this->analyticsConfiguration.IsEmpty())) {
            awsUpdateUserPoolClientRequest.SetAnalyticsConfiguration(this->analyticsConfiguration.toAWS());
        }

        switch(this->preventUserExistenceErrors) {
            case EAWSPreventUserExistenceErrorTypes::LEGACY:
                awsUpdateUserPoolClientRequest.SetPreventUserExistenceErrors(Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::LEGACY);
                break;
            case EAWSPreventUserExistenceErrorTypes::ENABLED:
                awsUpdateUserPoolClientRequest.SetPreventUserExistenceErrors(Aws::CognitoIdentityProvider::Model::PreventUserExistenceErrorTypes::ENABLED);
                break;
            default:
                break;
            }

        return awsUpdateUserPoolClientRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty() && this->clientName.IsEmpty() && this->refreshTokenValidity == 0 && this->accessTokenValidity == 0 && this->idTokenValidity == 0 && this->tokenValidityUnits.IsEmpty() && this->readAttributes.Num() == 0 && this->writeAttributes.Num() == 0 && this->explicitAuthFlows.Num() == 0 && this->supportedIdentityProviders.Num() == 0 && this->callbackURLs.Num() == 0 && this->logoutURLs.Num() == 0 && this->defaultRedirectURI.IsEmpty() && this->allowedOAuthFlows.Num() == 0 && this->allowedOAuthScopes.Num() == 0 && false && this->analyticsConfiguration.IsEmpty() && preventUserExistenceErrors == EAWSPreventUserExistenceErrorTypes::NOT_SET;
    }
#endif
};
