/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if PLATFORM_ANDROID

#include <string>
#include <sstream>

namespace std {
    template<typename T>
    static string to_string(T val) {
        std::stringstream ss;
        ss << val;
        return ss.str();
    };
};

#endif