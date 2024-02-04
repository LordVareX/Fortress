/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EventResponseType.generated.h"

UENUM(BlueprintType)
enum class EEventResponseType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Success        UMETA(DisplayName = "success"),
    Failure        UMETA(DisplayName = "failure")
};
