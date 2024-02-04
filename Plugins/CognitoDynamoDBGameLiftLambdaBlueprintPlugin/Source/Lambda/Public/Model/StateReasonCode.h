/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "StateReasonCode.generated.h"

UENUM(BlueprintType)
enum class EAWSStateReasonCode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Idle        UMETA(DisplayName = "idle"),
    Creating        UMETA(DisplayName = "creating"),
    Restoring        UMETA(DisplayName = "restoring"),
    EniLimitExceeded        UMETA(DisplayName = "enilimitexceeded"),
    InsufficientRolePermissions        UMETA(DisplayName = "insufficientrolepermissions"),
    InvalidConfiguration        UMETA(DisplayName = "invalidconfiguration"),
    InternalError        UMETA(DisplayName = "internalerror"),
    SubnetOutOfIPAddresses        UMETA(DisplayName = "subnetoutofipaddresses"),
    InvalidSubnet        UMETA(DisplayName = "invalidsubnet"),
    InvalidSecurityGroup        UMETA(DisplayName = "invalidsecuritygroup"),
    ImageDeleted        UMETA(DisplayName = "imagedeleted"),
    ImageAccessDenied        UMETA(DisplayName = "imageaccessdenied"),
    InvalidImage        UMETA(DisplayName = "invalidimage"),
};
