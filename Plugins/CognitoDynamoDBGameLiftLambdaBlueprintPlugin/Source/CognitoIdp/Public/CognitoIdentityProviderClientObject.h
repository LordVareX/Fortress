/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "CognitoIdpError.h"

#include "Model/AddCustomAttributesRequest.h"
#include "Model/AdminAddUserToGroupRequest.h"
#include "Model/AdminConfirmSignUpRequest.h"
#include "Model/AdminCreateUserRequest.h"
#include "Model/AdminDeleteUserRequest.h"
#include "Model/AdminDeleteUserAttributesRequest.h"
#include "Model/AdminDisableProviderForUserRequest.h"
#include "Model/AdminDisableUserRequest.h"
#include "Model/AdminEnableUserRequest.h"
#include "Model/AdminForgetDeviceRequest.h"
#include "Model/AdminGetDeviceRequest.h"
#include "Model/AdminGetUserRequest.h"
#include "Model/AdminInitiateAuthRequest.h"
#include "Model/AdminLinkProviderForUserRequest.h"
#include "Model/AdminListDevicesRequest.h"
#include "Model/AdminListGroupsForUserRequest.h"
#include "Model/AdminListUserAuthEventsRequest.h"
#include "Model/AdminRemoveUserFromGroupRequest.h"
#include "Model/AdminResetUserPasswordRequest.h"
#include "Model/AdminRespondToAuthChallengeRequest.h"
#include "Model/AdminSetUserMFAPreferenceRequest.h"
#include "Model/AdminSetUserPasswordRequest.h"
#include "Model/AdminSetUserSettingsRequest.h"
#include "Model/AdminUpdateAuthEventFeedbackRequest.h"
#include "Model/AdminUpdateDeviceStatusRequest.h"
#include "Model/AdminUpdateUserAttributesRequest.h"
#include "Model/AdminUserGlobalSignOutRequest.h"
#include "Model/AssociateSoftwareTokenRequest.h"
#include "Model/ChangePasswordRequest.h"
#include "Model/ConfirmDeviceRequest.h"
#include "Model/ConfirmForgotPasswordRequest.h"
#include "Model/ConfirmSignUpRequest.h"
#include "Model/CreateGroupRequest.h"
#include "Model/CreateIdentityProviderRequest.h"
#include "Model/CreateResourceServerRequest.h"
#include "Model/CreateUserImportJobRequest.h"
#include "Model/CreateUserPoolRequest.h"
#include "Model/CreateUserPoolClientRequest.h"
#include "Model/CreateUserPoolDomainRequest.h"
#include "Model/DeleteGroupRequest.h"
#include "Model/DeleteIdentityProviderRequest.h"
#include "Model/DeleteResourceServerRequest.h"
#include "Model/DeleteUserRequest.h"
#include "Model/DeleteUserAttributesRequest.h"
#include "Model/DeleteUserPoolRequest.h"
#include "Model/DeleteUserPoolClientRequest.h"
#include "Model/DeleteUserPoolDomainRequest.h"
#include "Model/DescribeIdentityProviderRequest.h"
#include "Model/DescribeResourceServerRequest.h"
#include "Model/DescribeRiskConfigurationRequest.h"
#include "Model/DescribeUserImportJobRequest.h"
#include "Model/DescribeUserPoolRequest.h"
#include "Model/DescribeUserPoolClientRequest.h"
#include "Model/DescribeUserPoolDomainRequest.h"
#include "Model/ForgetDeviceRequest.h"
#include "Model/ForgotPasswordRequest.h"
#include "Model/GetCSVHeaderRequest.h"
#include "Model/GetDeviceRequest.h"
#include "Model/GetGroupRequest.h"
#include "Model/GetIdentityProviderByIdentifierRequest.h"
#include "Model/GetSigningCertificateRequest.h"
#include "Model/GetUICustomizationRequest.h"
#include "Model/GetUserRequest.h"
#include "Model/GetUserAttributeVerificationCodeRequest.h"
#include "Model/GetUserPoolMfaConfigRequest.h"
#include "Model/GlobalSignOutRequest.h"
#include "Model/InitiateAuthRequest.h"
#include "Model/ListDevicesRequest.h"
#include "Model/ListGroupsRequest.h"
#include "Model/ListIdentityProvidersRequest.h"
#include "Model/ListResourceServersRequest.h"
#include "Model/CognitoIdpListTagsForResourceRequest.h"
#include "Model/ListUserImportJobsRequest.h"
#include "Model/ListUserPoolClientsRequest.h"
#include "Model/ListUserPoolsRequest.h"
#include "Model/ListUsersRequest.h"
#include "Model/ListUsersInGroupRequest.h"
#include "Model/ResendConfirmationCodeRequest.h"
#include "Model/RespondToAuthChallengeRequest.h"
#include "Model/SetRiskConfigurationRequest.h"
#include "Model/SetUICustomizationRequest.h"
#include "Model/SetUserMFAPreferenceRequest.h"
#include "Model/SetUserPoolMfaConfigRequest.h"
#include "Model/SetUserSettingsRequest.h"
#include "Model/SignUpRequest.h"
#include "Model/StartUserImportJobRequest.h"
#include "Model/StopUserImportJobRequest.h"
#include "Model/CognitoIdpTagResourceRequest.h"
#include "Model/CognitoIdpUntagResourceRequest.h"
#include "Model/UpdateAuthEventFeedbackRequest.h"
#include "Model/UpdateDeviceStatusRequest.h"
#include "Model/UpdateGroupRequest.h"
#include "Model/UpdateIdentityProviderRequest.h"
#include "Model/UpdateResourceServerRequest.h"
#include "Model/UpdateUserAttributesRequest.h"
#include "Model/UpdateUserPoolRequest.h"
#include "Model/UpdateUserPoolClientRequest.h"
#include "Model/UpdateUserPoolDomainRequest.h"
#include "Model/VerifySoftwareTokenRequest.h"
#include "Model/VerifyUserAttributeRequest.h"

#include "Model/AddCustomAttributesResult.h"
#include "Model/AdminConfirmSignUpResult.h"
#include "Model/AdminCreateUserResult.h"
#include "Model/AdminDeleteUserAttributesResult.h"
#include "Model/AdminDisableProviderForUserResult.h"
#include "Model/AdminDisableUserResult.h"
#include "Model/AdminEnableUserResult.h"
#include "Model/AdminGetDeviceResult.h"
#include "Model/AdminGetUserResult.h"
#include "Model/AdminInitiateAuthResult.h"
#include "Model/AdminLinkProviderForUserResult.h"
#include "Model/AdminListDevicesResult.h"
#include "Model/AdminListGroupsForUserResult.h"
#include "Model/AdminListUserAuthEventsResult.h"
#include "Model/AdminResetUserPasswordResult.h"
#include "Model/AdminRespondToAuthChallengeResult.h"
#include "Model/AdminSetUserMFAPreferenceResult.h"
#include "Model/AdminSetUserPasswordResult.h"
#include "Model/AdminSetUserSettingsResult.h"
#include "Model/AdminUpdateAuthEventFeedbackResult.h"
#include "Model/AdminUpdateDeviceStatusResult.h"
#include "Model/AdminUpdateUserAttributesResult.h"
#include "Model/AdminUserGlobalSignOutResult.h"
#include "Model/AssociateSoftwareTokenResult.h"
#include "Model/ChangePasswordResult.h"
#include "Model/ConfirmDeviceResult.h"
#include "Model/ConfirmForgotPasswordResult.h"
#include "Model/ConfirmSignUpResult.h"
#include "Model/CreateGroupResult.h"
#include "Model/CreateIdentityProviderResult.h"
#include "Model/CreateResourceServerResult.h"
#include "Model/CreateUserImportJobResult.h"
#include "Model/CreateUserPoolResult.h"
#include "Model/CreateUserPoolClientResult.h"
#include "Model/CreateUserPoolDomainResult.h"
#include "Model/DeleteUserAttributesResult.h"
#include "Model/DeleteUserPoolDomainResult.h"
#include "Model/DescribeIdentityProviderResult.h"
#include "Model/DescribeResourceServerResult.h"
#include "Model/DescribeRiskConfigurationResult.h"
#include "Model/DescribeUserImportJobResult.h"
#include "Model/DescribeUserPoolResult.h"
#include "Model/DescribeUserPoolClientResult.h"
#include "Model/DescribeUserPoolDomainResult.h"
#include "Model/ForgotPasswordResult.h"
#include "Model/GetCSVHeaderResult.h"
#include "Model/GetDeviceResult.h"
#include "Model/GetGroupResult.h"
#include "Model/GetIdentityProviderByIdentifierResult.h"
#include "Model/GetSigningCertificateResult.h"
#include "Model/GetUICustomizationResult.h"
#include "Model/GetUserResult.h"
#include "Model/GetUserAttributeVerificationCodeResult.h"
#include "Model/GetUserPoolMfaConfigResult.h"
#include "Model/GlobalSignOutResult.h"
#include "Model/InitiateAuthResult.h"
#include "Model/ListDevicesResult.h"
#include "Model/ListGroupsResult.h"
#include "Model/ListIdentityProvidersResult.h"
#include "Model/ListResourceServersResult.h"
#include "Model/CognitoIdpListTagsForResourceResult.h"
#include "Model/ListUserImportJobsResult.h"
#include "Model/ListUserPoolClientsResult.h"
#include "Model/ListUserPoolsResult.h"
#include "Model/ListUsersResult.h"
#include "Model/ListUsersInGroupResult.h"
#include "Model/ResendConfirmationCodeResult.h"
#include "Model/RespondToAuthChallengeResult.h"
#include "Model/SetRiskConfigurationResult.h"
#include "Model/SetUICustomizationResult.h"
#include "Model/SetUserMFAPreferenceResult.h"
#include "Model/SetUserPoolMfaConfigResult.h"
#include "Model/SetUserSettingsResult.h"
#include "Model/SignUpResult.h"
#include "Model/StartUserImportJobResult.h"
#include "Model/StopUserImportJobResult.h"
#include "Model/CognitoIdpTagResourceResult.h"
#include "Model/CognitoIdpUntagResourceResult.h"
#include "Model/UpdateAuthEventFeedbackResult.h"
#include "Model/UpdateDeviceStatusResult.h"
#include "Model/UpdateGroupResult.h"
#include "Model/UpdateIdentityProviderResult.h"
#include "Model/UpdateResourceServerResult.h"
#include "Model/UpdateUserAttributesResult.h"
#include "Model/UpdateUserPoolResult.h"
#include "Model/UpdateUserPoolClientResult.h"
#include "Model/UpdateUserPoolDomainResult.h"
#include "Model/VerifySoftwareTokenResult.h"
#include "Model/VerifyUserAttributeResult.h"

#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/CognitoIdentityProviderClient.h"

#endif

#include "CognitoIdentityProviderClientObject.generated.h"

/**
*  <p>Using the Amazon Cognito User Pools API, you can create a user pool to manage directories and users. You can authenticate a user to obtain tokens related to user identity and access policies.</p> <p>This API reference provides information about user pools in Amazon Cognito User Pools.</p> <p>For more information, see the Amazon Cognito Documentation.</p>
**/
UCLASS(BlueprintType)
class COGNITOIDP_API UCognitoIdpClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_COGNITOIDENTITYPROVIDERCLIENTSDK && WITH_CORE
    Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *awsCognitoIdentityProviderClient;
#endif

    /**
    * public static UCognitoIdpClientObject::CreateCognitoIdentityProviderObject
    * Creates a CognitoIdpClientObject. This function must be called first before accessing any Cognito Idp client functions.
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [UCognitoIdentityProviderClient*] Returns UCognitoIdentityProviderClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "CognitoIdentityProvider Client")
    static UCognitoIdpClientObject *
    CreateCognitoIdpObject(const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    *  <p>Adds additional user attributes to the user pool schema.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AddCustomAttributes">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param addCustomAttributesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AddCustomAttributes (
        UObject *WorldContextObject,
        bool &success,
        FAddCustomAttributesRequest addCustomAttributesRequest,
        FAddCustomAttributesResult &addCustomAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Adds the specified user to the specified group.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminAddUserToGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminAddUserToGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminAddUserToGroup (
        UObject *WorldContextObject,
        bool &success,
        FAdminAddUserToGroupRequest adminAddUserToGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Confirms user registration as an admin without using a confirmation code. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminConfirmSignUp">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminConfirmSignUpRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminConfirmSignUp (
        UObject *WorldContextObject,
        bool &success,
        FAdminConfirmSignUpRequest adminConfirmSignUpRequest,
        FAdminConfirmSignUpResult &adminConfirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates a new user in the specified user pool.</p> <p>If <code>MessageAction</code> is not set, the default is to send a welcome message via email or phone (SMS).</p> <note> <p>This message is based on a template that you configured in your call to or . This template includes your custom sign-up instructions and placeholders for user name and temporary password.</p> </note> <p>Alternatively, you can call AdminCreateUser with “SUPPRESS” for the <code>MessageAction</code> parameter, and Amazon Cognito will not send any email. </p> <p>In either case, the user will be in the <code>FORCE_CHANGE_PASSWORD</code> state until they sign in and change their password.</p> <p>AdminCreateUser requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminCreateUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminCreateUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminCreateUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminCreateUserRequest adminCreateUserRequest,
        FAdminCreateUserResult &adminCreateUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes a user as an administrator. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminDeleteUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminDeleteUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminDeleteUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserRequest adminDeleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes the user attributes in a user pool as an administrator. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminDeleteUserAttributes">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminDeleteUserAttributesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminDeleteUserAttributes (
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest,
        FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Disables the user from signing in with the specified external (SAML or social) identity provider. If the user to disable is a Cognito User Pools native username + password user, they are not permitted to use their password to sign-in. If the user to disable is a linked external IdP user, any link between that user and an existing user is removed. The next time the external user (no longer attached to the previously linked <code>DestinationUser</code>) signs in, they must create a new user account. See .</p> <p>This action is enabled only for admin access and requires developer credentials.</p> <p>The <code>ProviderName</code> must match the value specified when creating an IdP for the pool. </p> <p>To disable a native username + password user, the <code>ProviderName</code> value must be <code>Cognito</code> and the <code>ProviderAttributeName</code> must be <code>Cognito_Subject</code>, with the <code>ProviderAttributeValue</code> being the name that is used in the user pool for the user.</p> <p>The <code>ProviderAttributeName</code> must always be <code>Cognito_Subject</code> for social identity providers. The <code>ProviderAttributeValue</code> must always be the exact subject that was used when the user was originally linked as a source user.</p> <p>For de-linking a SAML identity, there are two scenarios. If the linked identity has not yet been used to sign-in, the <code>ProviderAttributeName</code> and <code>ProviderAttributeValue</code> must be the same values that were used for the <code>SourceUser</code> when the identities were originally linked in the call. (If the linking was done with <code>ProviderAttributeName</code> set to <code>Cognito_Subject</code>, the same applies here). However, if the user has already signed in, the <code>ProviderAttributeName</code> must be <code>Cognito_Subject</code> and <code>ProviderAttributeValue</code> must be the subject of the SAML assertion.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminDisableProviderForUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminDisableProviderForUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminDisableProviderForUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest,
        FAdminDisableProviderForUserResult &adminDisableProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Disables the specified user as an administrator. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminDisableUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminDisableUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminDisableUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableUserRequest adminDisableUserRequest,
        FAdminDisableUserResult &adminDisableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Enables the specified user as an administrator. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminEnableUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminEnableUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminEnableUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminEnableUserRequest adminEnableUserRequest,
        FAdminEnableUserResult &adminEnableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Forgets the device, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminForgetDevice">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminForgetDeviceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminForgetDevice (
        UObject *WorldContextObject,
        bool &success,
        FAdminForgetDeviceRequest adminForgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the device, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminGetDevice">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminGetDeviceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminGetDevice (
        UObject *WorldContextObject,
        bool &success,
        FAdminGetDeviceRequest adminGetDeviceRequest,
        FAdminGetDeviceResult &adminGetDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the specified user by user name in a user pool as an administrator. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminGetUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminGetUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminGetUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminGetUserRequest adminGetUserRequest,
        FAdminGetUserResult &adminGetUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Initiates the authentication flow, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminInitiateAuth">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminInitiateAuthRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminInitiateAuth (
        UObject *WorldContextObject,
        bool &success,
        FAdminInitiateAuthRequest adminInitiateAuthRequest,
        FAdminInitiateAuthResult &adminInitiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Links an existing user account in a user pool (<code>DestinationUser</code>) to an identity from an external identity provider (<code>SourceUser</code>) based on a specified attribute name and value from the external identity provider. This allows you to create a link from the existing user account to an external federated user identity that has not yet been used to sign in, so that the federated user identity can be used to sign in as the existing user account. </p> <p> For example, if there is an existing user with a username and password, this API links that user to a federated user identity, so that when the federated user identity is used, the user signs in as the existing user account. </p> <important> <p>Because this API allows a user with an external federated identity to sign in as an existing user in the user pool, it is critical that it only be used with external identity providers and provider attributes that have been trusted by the application owner.</p> </important> <p>See also .</p> <p>This action is enabled only for admin access and requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminLinkProviderForUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminLinkProviderForUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminLinkProviderForUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest,
        FAdminLinkProviderForUserResult &adminLinkProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists devices, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminListDevices">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminListDevicesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminListDevices (
        UObject *WorldContextObject,
        bool &success,
        FAdminListDevicesRequest adminListDevicesRequest,
        FAdminListDevicesResult &adminListDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the groups that the user belongs to.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminListGroupsForUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminListGroupsForUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminListGroupsForUser (
        UObject *WorldContextObject,
        bool &success,
        FAdminListGroupsForUserRequest adminListGroupsForUserRequest,
        FAdminListGroupsForUserResult &adminListGroupsForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists a history of user activity and any risks detected as part of Amazon Cognito advanced security.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminListUserAuthEvents">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminListUserAuthEventsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminListUserAuthEvents (
        UObject *WorldContextObject,
        bool &success,
        FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest,
        FAdminListUserAuthEventsResult &adminListUserAuthEventsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Removes the specified user from the specified group.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminRemoveUserFromGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminRemoveUserFromGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminRemoveUserFromGroup (
        UObject *WorldContextObject,
        bool &success,
        FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Resets the specified user's password in a user pool as an administrator. Works on any user.</p> <p>When a developer calls this API, the current password is invalidated, so it must be changed. If a user tries to sign in after the API is called, the app will get a PasswordResetRequiredException exception back and should direct the user down the flow to reset the password, which is the same as the forgot password flow. In addition, if the user pool has phone verification selected and a verified phone number exists for the user, or if email verification is selected and a verified email exists for the user, calling this API will also result in sending a message to the end user with the code to change their password.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminResetUserPassword">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminResetUserPasswordRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminResetUserPassword (
        UObject *WorldContextObject,
        bool &success,
        FAdminResetUserPasswordRequest adminResetUserPasswordRequest,
        FAdminResetUserPasswordResult &adminResetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Responds to an authentication challenge, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminRespondToAuthChallenge">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminRespondToAuthChallengeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminRespondToAuthChallenge (
        UObject *WorldContextObject,
        bool &success,
        FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest,
        FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Sets the user's multi-factor authentication (MFA) preference.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminSetUserMFAPreference">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminSetUserMFAPreferenceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminSetUserMFAPreference (
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest,
        FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminSetUserPasswordRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminSetUserPassword (
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserPasswordRequest adminSetUserPasswordRequest,
        FAdminSetUserPasswordResult &adminSetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Sets all the user settings for a specified user name. Works on any user.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminSetUserSettings">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminSetUserSettingsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminSetUserSettings (
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserSettingsRequest adminSetUserSettingsRequest,
        FAdminSetUserSettingsResult &adminSetUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Provides feedback for an authentication event as to whether it was from a valid user. This feedback is used for improving the risk evaluation decision for the user pool as part of Amazon Cognito advanced security.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminUpdateAuthEventFeedback">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminUpdateAuthEventFeedbackRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminUpdateAuthEventFeedback (
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest,
        FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the device status as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminUpdateDeviceStatus">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminUpdateDeviceStatusRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminUpdateDeviceStatus (
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest,
        FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the specified user's attributes, including developer attributes, as an administrator. Works on any user.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p> <p>In addition to updating user attributes, this API can also be used to mark phone and email as verified.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminUpdateUserAttributes">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminUpdateUserAttributesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminUpdateUserAttributes (
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest,
        FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Signs out users from all devices, as an administrator.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AdminUserGlobalSignOut">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param adminUserGlobalSignOutRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AdminUserGlobalSignOut (
        UObject *WorldContextObject,
        bool &success,
        FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest,
        FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Returns a unique generated shared secret key code for the user account. The request takes an access token or a session string, but not both.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/AssociateSoftwareToken">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param associateSoftwareTokenRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void AssociateSoftwareToken (
        UObject *WorldContextObject,
        bool &success,
        FAssociateSoftwareTokenRequest associateSoftwareTokenRequest,
        FAssociateSoftwareTokenResult &associateSoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Changes the password for a specified user in a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ChangePassword">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param changePasswordRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ChangePassword (
        UObject *WorldContextObject,
        bool &success,
        FChangePasswordRequest changePasswordRequest,
        FChangePasswordResult &changePasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Confirms tracking of the device. This API call is the call that begins device tracking.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ConfirmDevice">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param confirmDeviceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ConfirmDevice (
        UObject *WorldContextObject,
        bool &success,
        FConfirmDeviceRequest confirmDeviceRequest,
        FConfirmDeviceResult &confirmDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Allows a user to enter a confirmation code to reset a forgotten password.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ConfirmForgotPassword">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param confirmForgotPasswordRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ConfirmForgotPassword (
        UObject *WorldContextObject,
        bool &success,
        FConfirmForgotPasswordRequest confirmForgotPasswordRequest,
        FConfirmForgotPasswordResult &confirmForgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Confirms registration of a user and handles the existing alias from a previous user.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ConfirmSignUp">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param confirmSignUpRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ConfirmSignUp (
        UObject *WorldContextObject,
        bool &success,
        FConfirmSignUpRequest confirmSignUpRequest,
        FConfirmSignUpResult &confirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates a new group in the specified user pool.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateGroup (
        UObject *WorldContextObject,
        bool &success,
        FCreateGroupRequest createGroupRequest,
        FCreateGroupResult &createGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates an identity provider for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateIdentityProvider">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createIdentityProviderRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateIdentityProvider (
        UObject *WorldContextObject,
        bool &success,
        FCreateIdentityProviderRequest createIdentityProviderRequest,
        FCreateIdentityProviderResult &createIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates a new OAuth2.0 resource server and defines custom scopes in it.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateResourceServer">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createResourceServerRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateResourceServer (
        UObject *WorldContextObject,
        bool &success,
        FCreateResourceServerRequest createResourceServerRequest,
        FCreateResourceServerResult &createResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates the user import job.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateUserImportJob">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createUserImportJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateUserImportJob (
        UObject *WorldContextObject,
        bool &success,
        FCreateUserImportJobRequest createUserImportJobRequest,
        FCreateUserImportJobResult &createUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates a new Amazon Cognito user pool and sets the password policy for the pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateUserPool">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createUserPoolRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateUserPool (
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolRequest createUserPoolRequest,
        FCreateUserPoolResult &createUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates the user pool client.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateUserPoolClient">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createUserPoolClientRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateUserPoolClient (
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolClientRequest createUserPoolClientRequest,
        FCreateUserPoolClientResult &createUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Creates a new domain for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/CreateUserPoolDomain">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param createUserPoolDomainRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void CreateUserPoolDomain (
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolDomainRequest createUserPoolDomainRequest,
        FCreateUserPoolDomainResult &createUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes a group. Currently only groups with no members can be deleted.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteGroup (
        UObject *WorldContextObject,
        bool &success,
        FDeleteGroupRequest deleteGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes an identity provider for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteIdentityProvider">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteIdentityProviderRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteIdentityProvider (
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentityProviderRequest deleteIdentityProviderRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes a resource server.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteResourceServer">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteResourceServerRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteResourceServer (
        UObject *WorldContextObject,
        bool &success,
        FDeleteResourceServerRequest deleteResourceServerRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Allows a user to delete himself or herself.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteUser (
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserRequest deleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes the attributes for a user.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteUserAttributes">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteUserAttributesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteUserAttributes (
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserAttributesRequest deleteUserAttributesRequest,
        FDeleteUserAttributesResult &deleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes the specified Amazon Cognito user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteUserPool">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteUserPoolRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteUserPool (
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolRequest deleteUserPoolRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Allows the developer to delete the user pool client.</p><p><h3>See Also:</h3> <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteUserPoolClient">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteUserPoolClientRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteUserPoolClient (
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolClientRequest deleteUserPoolClientRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Deletes a domain for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DeleteUserPoolDomain">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param deleteUserPoolDomainRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DeleteUserPoolDomain (
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest,
        FDeleteUserPoolDomainResult &deleteUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets information about a specific identity provider.</p><p><h3>See Also:</h3> <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeIdentityProvider">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeIdentityProviderRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeIdentityProvider (
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityProviderRequest describeIdentityProviderRequest,
        FDescribeIdentityProviderResult &describeIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Describes a resource server.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeResourceServer">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeResourceServerRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeResourceServer (
        UObject *WorldContextObject,
        bool &success,
        FDescribeResourceServerRequest describeResourceServerRequest,
        FDescribeResourceServerResult &describeResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Describes the risk configuration.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeRiskConfiguration">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeRiskConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeRiskConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FDescribeRiskConfigurationRequest describeRiskConfigurationRequest,
        FDescribeRiskConfigurationResult &describeRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Describes the user import job.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeUserImportJob">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeUserImportJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeUserImportJob (
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserImportJobRequest describeUserImportJobRequest,
        FDescribeUserImportJobResult &describeUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Returns the configuration information and metadata of the specified user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeUserPool">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeUserPoolRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeUserPool (
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolRequest describeUserPoolRequest,
        FDescribeUserPoolResult &describeUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Client method for returning the configuration information and metadata of the specified user pool app client.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeUserPoolClient">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeUserPoolClientRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeUserPoolClient (
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolClientRequest describeUserPoolClientRequest,
        FDescribeUserPoolClientResult &describeUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets information about a domain.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/DescribeUserPoolDomain">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param describeUserPoolDomainRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void DescribeUserPoolDomain (
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolDomainRequest describeUserPoolDomainRequest,
        FDescribeUserPoolDomainResult &describeUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Forgets the specified device.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ForgetDevice">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param forgetDeviceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ForgetDevice (
        UObject *WorldContextObject,
        bool &success,
        FForgetDeviceRequest forgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Calling this API causes a message to be sent to the end user with a confirmation code that is required to change the user's password. For the <code>Username</code> parameter, you can use the username or user alias. If a verified phone number exists for the user, the confirmation code is sent to the phone number. Otherwise, if a verified email exists, the confirmation code is sent to the email. If neither a verified phone number nor a verified email exists, <code>InvalidParameterException</code> is thrown. To use the confirmation code for resetting the password, call .</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ForgotPassword">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param forgotPasswordRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ForgotPassword (
        UObject *WorldContextObject,
        bool &success,
        FForgotPasswordRequest forgotPasswordRequest,
        FForgotPasswordResult &forgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the header information for the .csv file to be used as input for the user import job.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetCSVHeader">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getCSVHeaderRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetCSVHeader (
        UObject *WorldContextObject,
        bool &success,
        FGetCSVHeaderRequest getCSVHeaderRequest,
        FGetCSVHeaderResult &getCSVHeaderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the device.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetDevice">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getDeviceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetDevice (
        UObject *WorldContextObject,
        bool &success,
        FGetDeviceRequest getDeviceRequest,
        FGetDeviceResult &getDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets a group.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3> <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetGroup (
        UObject *WorldContextObject,
        bool &success,
        FGetGroupRequest getGroupRequest,
        FGetGroupResult &getGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the specified identity provider.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetIdentityProviderByIdentifier">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getIdentityProviderByIdentifierRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetIdentityProviderByIdentifier (
        UObject *WorldContextObject,
        bool &success,
        FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest,
        FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>This method takes a user pool ID, and returns the signing certificate.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetSigningCertificate">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getSigningCertificateRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetSigningCertificate (
        UObject *WorldContextObject,
        bool &success,
        FGetSigningCertificateRequest getSigningCertificateRequest,
        FGetSigningCertificateResult &getSigningCertificateResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the UI Customization information for a particular app client's app UI, if there is something set. If nothing is set for the particular client, but there is an existing pool level customization (app <code>clientId</code> will be <code>ALL</code>), then that is returned. If nothing is present, then an empty shape is returned.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetUICustomization">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getUICustomizationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetUICustomization (
        UObject *WorldContextObject,
        bool &success,
        FGetUICustomizationRequest getUICustomizationRequest,
        FGetUICustomizationResult &getUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the user attributes and metadata for a user.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetUser">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getUserRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetUser (
        UObject *WorldContextObject,
        bool &success,
        FGetUserRequest getUserRequest,
        FGetUserResult &getUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the user attribute verification code for the specified attribute name.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetUserAttributeVerificationCode">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getUserAttributeVerificationCodeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetUserAttributeVerificationCode (
        UObject *WorldContextObject,
        bool &success,
        FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest,
        FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Gets the user pool multi-factor authentication (MFA) configuration.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GetUserPoolMfaConfig">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param getUserPoolMfaConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GetUserPoolMfaConfig (
        UObject *WorldContextObject,
        bool &success,
        FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest,
        FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Signs out users from all devices.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/GlobalSignOut">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param globalSignOutRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void GlobalSignOut (
        UObject *WorldContextObject,
        bool &success,
        FGlobalSignOutRequest globalSignOutRequest,
        FGlobalSignOutResult &globalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Initiates the authentication flow.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/InitiateAuth">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param initiateAuthRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void InitiateAuth (
        UObject *WorldContextObject,
        bool &success,
        FInitiateAuthRequest initiateAuthRequest,
        FInitiateAuthResult &initiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the devices.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListDevices">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listDevicesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListDevices (
        UObject *WorldContextObject,
        bool &success,
        FListDevicesRequest listDevicesRequest,
        FListDevicesResult &listDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the groups associated with a user pool.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListGroups">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listGroupsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListGroups (
        UObject *WorldContextObject,
        bool &success,
        FListGroupsRequest listGroupsRequest,
        FListGroupsResult &listGroupsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists information about all identity providers for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListIdentityProviders">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listIdentityProvidersRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListIdentityProviders (
        UObject *WorldContextObject,
        bool &success,
        FListIdentityProvidersRequest listIdentityProvidersRequest,
        FListIdentityProvidersResult &listIdentityProvidersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the resource servers for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListResourceServers">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listResourceServersRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListResourceServers (
        UObject *WorldContextObject,
        bool &success,
        FListResourceServersRequest listResourceServersRequest,
        FListResourceServersResult &listResourceServersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the tags that are assigned to an Amazon Cognito user pool.</p> <p>A tag is a label that you can apply to user pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p> <p>You can use this action up to 10 times per second, per account.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListTagsForResource">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listTagsForResourceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListTagsForResource (
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdpListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the user import jobs.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListUserImportJobs">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listUserImportJobsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListUserImportJobs (
        UObject *WorldContextObject,
        bool &success,
        FListUserImportJobsRequest listUserImportJobsRequest,
        FListUserImportJobsResult &listUserImportJobsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the clients that have been created for the specified user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListUserPoolClients">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listUserPoolClientsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListUserPoolClients (
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolClientsRequest listUserPoolClientsRequest,
        FListUserPoolClientsResult &listUserPoolClientsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the user pools associated with an AWS account.</p><p><h3>See Also:</h3> <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListUserPools">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listUserPoolsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListUserPools (
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolsRequest listUserPoolsRequest,
        FListUserPoolsResult &listUserPoolsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the users in the Amazon Cognito user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListUsers">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listUsersRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListUsers (
        UObject *WorldContextObject,
        bool &success,
        FListUsersRequest listUsersRequest,
        FListUsersResult &listUsersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Lists the users in the specified group.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ListUsersInGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param listUsersInGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ListUsersInGroup (
        UObject *WorldContextObject,
        bool &success,
        FListUsersInGroupRequest listUsersInGroupRequest,
        FListUsersInGroupResult &listUsersInGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Resends the confirmation (for confirmation of registration) to a specific user in the user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/ResendConfirmationCode">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param resendConfirmationCodeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void ResendConfirmationCode (
        UObject *WorldContextObject,
        bool &success,
        FResendConfirmationCodeRequest resendConfirmationCodeRequest,
        FResendConfirmationCodeResult &resendConfirmationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Responds to the authentication challenge.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/RespondToAuthChallenge">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param respondToAuthChallengeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void RespondToAuthChallenge (
        UObject *WorldContextObject,
        bool &success,
        FRespondToAuthChallengeRequest respondToAuthChallengeRequest,
        FRespondToAuthChallengeResult &respondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Configures actions on detected risks. To delete the risk configuration for <code>UserPoolId</code> or <code>ClientId</code>, pass null values for all four configuration types.</p> <p>To enable Amazon Cognito advanced security features, update the user pool to include the <code>UserPoolAddOns</code> key<code>AdvancedSecurityMode</code>.</p> <p>See .</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SetRiskConfiguration">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param setRiskConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SetRiskConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FSetRiskConfigurationRequest setRiskConfigurationRequest,
        FSetRiskConfigurationResult &setRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Sets the UI customization information for a user pool's built-in app UI.</p> <p>You can specify app UI customization settings for a single client (with a specific <code>clientId</code>) or for all clients (by setting the <code>clientId</code> to <code>ALL</code>). If you specify <code>ALL</code>, the default configuration will be used for every client that has no UI customization set previously. If you specify UI customization settings for a particular client, it will no longer fall back to the <code>ALL</code> configuration. </p> <note> <p>To use this API, your user pool must have a domain associated with it. Otherwise, there is no place to host the app's pages, and the service will throw an error.</p> </note><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SetUICustomization">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param setUICustomizationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SetUICustomization (
        UObject *WorldContextObject,
        bool &success,
        FSetUICustomizationRequest setUICustomizationRequest,
        FSetUICustomizationResult &setUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Set the user's multi-factor authentication (MFA) method preference.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SetUserMFAPreference">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param setUserMFAPreferenceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SetUserMFAPreference (
        UObject *WorldContextObject,
        bool &success,
        FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest,
        FSetUserMFAPreferenceResult &setUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Set the user pool MFA configuration.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SetUserPoolMfaConfig">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param setUserPoolMfaConfigRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SetUserPoolMfaConfig (
        UObject *WorldContextObject,
        bool &success,
        FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest,
        FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Sets the user settings like multi-factor authentication (MFA). If MFA is to be removed for a particular attribute pass the attribute with code delivery as null. If null list is passed, all MFA options are removed.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SetUserSettings">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param setUserSettingsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SetUserSettings (
        UObject *WorldContextObject,
        bool &success,
        FSetUserSettingsRequest setUserSettingsRequest,
        FSetUserSettingsResult &setUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Registers the user in the specified user pool and creates a user name, password, and user attributes.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/SignUp">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param signUpRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void SignUp (
        UObject *WorldContextObject,
        bool &success,
        FSignUpRequest signUpRequest,
        FSignUpResult &signUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Starts the user import.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/StartUserImportJob">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param startUserImportJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void StartUserImportJob (
        UObject *WorldContextObject,
        bool &success,
        FStartUserImportJobRequest startUserImportJobRequest,
        FStartUserImportJobResult &startUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Stops the user import job.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/StopUserImportJob">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param stopUserImportJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void StopUserImportJob (
        UObject *WorldContextObject,
        bool &success,
        FStopUserImportJobRequest stopUserImportJobRequest,
        FStopUserImportJobResult &stopUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Assigns a set of tags to an Amazon Cognito user pool. A tag is a label that you can use to categorize and manage user pools in different ways, such as by purpose, owner, environment, or other criteria.</p> <p>Each tag consists of a key and value, both of which you define. A key is a general category for more specific values. For example, if you have two versions of a user pool, one for testing and another for production, you might assign an <code>Environment</code> tag key to both user pools. The value of this key might be <code>Test</code> for one user pool and <code>Production</code> for the other.</p> <p>Tags are useful for cost tracking and access control. You can activate your tags so that they appear on the Billing and Cost Management console, where you can track the costs associated with your user pools. In an IAM policy, you can constrain permissions for user pools based on specific tags or tag values.</p> <p>You can use this action up to 5 times per second, per account. A user pool can have as many as 50 tags.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/TagResource">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param tagResourceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void TagResource (
            UObject *WorldContextObject,
            bool &success,
            FCognitoIdpTagResourceRequest tagResourceRequest,
            FCognitoIdpTagResourceResult &tagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
            struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Removes the specified tags from an Amazon Cognito user pool. You can use this action up to 5 times per second, per account</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UntagResource">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param untagResourceRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UntagResource (
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpUntagResourceRequest untagResourceRequest,
        FCognitoIdpUntagResourceResult &untagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Provides the feedback for an authentication event whether it was from a valid user or not. This feedback is used for improving the risk evaluation decision for the user pool as part of Amazon Cognito advanced security.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateAuthEventFeedback">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateAuthEventFeedbackRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateAuthEventFeedback (
        UObject *WorldContextObject,
        bool &success,
        FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest,
        FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the device status.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateDeviceStatus">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateDeviceStatusRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateDeviceStatus (
        UObject *WorldContextObject,
        bool &success,
        FUpdateDeviceStatusRequest updateDeviceStatusRequest,
        FUpdateDeviceStatusResult &updateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the specified group with the specified attributes.</p> <p>Requires developer credentials.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateGroup">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateGroupRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateGroup (
        UObject *WorldContextObject,
        bool &success,
        FUpdateGroupRequest updateGroupRequest,
        FUpdateGroupResult &updateGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates identity provider information for a user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateIdentityProvider">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateIdentityProviderRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateIdentityProvider (
        UObject *WorldContextObject,
        bool &success,
        FUpdateIdentityProviderRequest updateIdentityProviderRequest,
        FUpdateIdentityProviderResult &updateIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the name and scopes of resource server. All other fields are read-only.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateResourceServer">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateResourceServerRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateResourceServer (
        UObject *WorldContextObject,
        bool &success,
        FUpdateResourceServerRequest updateResourceServerRequest,
        FUpdateResourceServerResult &updateResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Allows a user to update a specific attribute (one at a time).</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateUserAttributes">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateUserAttributesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateUserAttributes (
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserAttributesRequest updateUserAttributesRequest,
        FUpdateUserAttributesResult &updateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the specified user pool with the specified attributes. If you don't provide a value for an attribute, it will be set to the default value. You can get a list of the current user pool settings with .</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateUserPool">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateUserPoolRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateUserPool (
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolRequest updateUserPoolRequest,
        FUpdateUserPoolResult &updateUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the specified user pool app client with the specified attributes. If you don't provide a value for an attribute, it will be set to the default value. You can get a list of the current user pool app client settings with .</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateUserPoolClient">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateUserPoolClientRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateUserPoolClient (
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolClientRequest updateUserPoolClientRequest,
        FUpdateUserPoolClientResult &updateUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Updates the Secure Sockets Layer (SSL) certificate for the custom domain for your user pool.</p> <p>You can use this operation to provide the Amazon Resource Name (ARN) of a new certificate to Amazon Cognito. You cannot use it to change the domain for a user pool.</p> <p>A custom domain is used to host the Amazon Cognito hosted UI, which provides sign-up and sign-in pages for your application. When you set up a custom domain, you provide a certificate that you manage with AWS Certificate Manager (ACM). When necessary, you can use this operation to change the certificate that you applied to your custom domain.</p> <p>Usually, this is unnecessary following routine certificate renewal with ACM. When you renew your existing certificate in ACM, the ARN for your certificate remains the same, and your custom domain uses the new certificate automatically.</p> <p>However, if you replace your existing certificate with a new one, ACM gives the new certificate a new ARN. To apply the new certificate to your custom domain, you must provide this ARN to Amazon Cognito.</p> <p>When you add your new certificate in ACM, you must choose US East (N. Virginia) as the AWS Region.</p> <p>After you submit your request, Amazon Cognito requires up to 1 hour to distribute your new certificate to your custom domain.</p> <p>For more information about adding a custom domain to your user pool, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pools-add-custom-domain.html">Using Your Own Domain for the Hosted UI</a>.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/UpdateUserPoolDomain">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param updateUserPoolDomainRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void UpdateUserPoolDomain (
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolDomainRequest updateUserPoolDomainRequest,
        FUpdateUserPoolDomainResult &updateUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Use this API to register a user's entered TOTP code and mark the user's software token MFA status as "verified" if successful. The request takes an access token or a session string, but not both.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/VerifySoftwareToken">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param verifySoftwareTokenRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void VerifySoftwareToken (
        UObject *WorldContextObject,
        bool &success,
        FVerifySoftwareTokenRequest verifySoftwareTokenRequest,
        FVerifySoftwareTokenResult &verifySoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    *  <p>Verifies the specified user attributes in the user pool.</p><p><h3>See Also:</h3>   <a href="http://docs.aws.amazon.com/goto/WebAPI/cognito-idp-2016-04-18/VerifyUserAttribute">AWS API Reference</a></p>
    *  Queues the request into a thread executor and triggers associated callback when operation has finished.
    * @param
    * @param verifyUserAttributeRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "CognitoIdentityProvider Client")
    void VerifyUserAttribute (
        UObject *WorldContextObject,
        bool &success,
        FVerifyUserAttributeRequest verifyUserAttributeRequest,
        FVerifyUserAttributeResult &verifyUserAttributeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
};
