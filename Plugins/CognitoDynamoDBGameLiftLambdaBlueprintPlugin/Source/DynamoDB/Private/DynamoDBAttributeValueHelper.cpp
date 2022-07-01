/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, Oct 2021
 */

#include "DynamoDBAttributeValueHelper.h"

#include "DynamoDBGlobals.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/core/external/cjson/cJSON.h"

#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>

#endif

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

static unsigned char* strdup(const unsigned char* string)
{
    size_t length = 0;
    unsigned char *copy = NULL;

    if (string == NULL)
    {
        return NULL;
    }

    length = std::strlen((const char*)string) + sizeof("");
    copy = (unsigned char *)cJSON_malloc(length);
    if (copy == NULL)
    {
        return NULL;
    }
    std::memcpy(copy, string, length);

    return copy;
}

cJSON *JsonToDynamoDBAttributeValueNode(cJSON *json);

std::vector<cJSON *> JsonToDynamoDBAttributeValueContainer(cJSON *json) {
    cJSON *current_element = json->child;

    std::vector<cJSON *> container;
    while (current_element != nullptr) {
        container.push_back(JsonToDynamoDBAttributeValueNode(current_element));

        current_element = current_element->next;
    }

    return container;
}

cJSON *JsonToDynamoDBAttributeValueNode(cJSON *json) {
    cJSON *attributeValueNode = cJSON_CreateObject();

    if (json->string) {
        attributeValueNode->string = (char *)strdup((const unsigned char*)(json->string));
    }

    if (json != nullptr) {
        switch (json->type & 0xFF) {
            case cJSON_Invalid:
            case cJSON_NULL: {
                cJSON_AddTrueToObject(attributeValueNode, "NULL");
                break;
            }
            case cJSON_False: {
                cJSON_AddFalseToObject(attributeValueNode, "BOOL");
                break;
            }
            case cJSON_True: {
                cJSON_AddTrueToObject(attributeValueNode, "BOOL");
                break;
            }
            case cJSON_Number: {
                cJSON_AddStringToObject(attributeValueNode, "N", std::to_string(json->valuedouble).c_str());
                break;
            }
            case cJSON_String:
            case cJSON_Raw: {
                cJSON_AddStringToObject(attributeValueNode, "S", json->valuestring);
                break;
            }
            case cJSON_Array: {
                cJSON *array = cJSON_AddArrayToObject(attributeValueNode, "L");
                std::vector<cJSON *> container = JsonToDynamoDBAttributeValueContainer(json);

                for (cJSON *container_node : container) {
                    cJSON_AddItemToArray(array, container_node);
                }

                break;
            }
            case cJSON_Object: {
                cJSON *map = cJSON_AddObjectToObject(attributeValueNode, "M");
                std::vector<cJSON *> container = JsonToDynamoDBAttributeValueContainer(json);

                for (cJSON *container_node : container) {
                    cJSON_AddItemToObject(map, container_node->string, container_node);
                }

                break;
            }
        }
    }

    return attributeValueNode;
}

#endif

FString UDynamoDBAttributeValueHelper::JsonToDynamoDBAttributeValue(FString json) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    cJSON *cjson = cJSON_Parse(TCHAR_TO_UTF8(*json));

    if (cjson == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            LOG_DYNAMODB_WARNING(FString::Printf(TEXT("Error before: %s"), UTF8_TO_TCHAR(error_ptr)));
        }
        cJSON_Delete(cjson);
        return FString();
    }

    cJSON *cjsonAttributeValue = JsonToDynamoDBAttributeValueNode(cjson);

    char *string = cJSON_Print(cjsonAttributeValue);
    if (string == nullptr)
    {
        LOG_DYNAMODB_WARNING("Failed to print");
    }

    cJSON_Delete(cjson);
    cJSON_Delete(cjsonAttributeValue);

    return UTF8_TO_TCHAR(string);
#else
    return FString();
#endif
}

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

std::vector<cJSON *> DynamoDBAttributeValueToJsonContainer(cJSON *attributeValue);

cJSON *DynamoDBAttributeValueToJsonNode(cJSON *attributeValue) {
    if (attributeValue == nullptr) {
        return nullptr;
    }

    if ((attributeValue->type & 0xFF) != cJSON_Object) {
        return nullptr;
    }

    cJSON *current_element = attributeValue->child;

    cJSON *node = nullptr;
    while (current_element != nullptr) {
        if (strcmp(current_element->string, "S") == 0) {
            if ((current_element->type & 0xFF) != cJSON_String) {
                return nullptr;
            }
            node = cJSON_CreateString(current_element->valuestring);
        } else if (strcmp(current_element->string, "N") == 0) {
            if ((current_element->type & 0xFF) != cJSON_String) {
                return nullptr;
            }
            node = cJSON_CreateNumber(std::atof(current_element->valuestring));
        } else if (strcmp(current_element->string, "B") == 0) {
            if ((current_element->type & 0xFF) != cJSON_String) {
                return nullptr;
            }
            node = cJSON_CreateString(current_element->valuestring);
        } else if (strcmp(current_element->string, "SS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_Array) {
                return nullptr;
            }
            node = cJSON_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_String) {
                    cJSON_AddItemToArray(node, cJSON_CreateString(current_element_child->valuestring));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "NS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_Array) {
                return nullptr;
            }
            node = cJSON_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_String) {
                    cJSON_AddItemToArray(node, cJSON_CreateNumber(std::atof(current_element_child->valuestring)));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "BS") == 0) {
            if ((current_element->type & 0xFF) != cJSON_Array) {
                return nullptr;
            }
            node = cJSON_CreateArray();

            cJSON *current_element_child = current_element->child;
            while (current_element_child != nullptr) {
                if ((current_element_child->type & 0xFF) == cJSON_String) {
                    cJSON_AddItemToArray(node, cJSON_CreateString(current_element_child->valuestring));
                }

                current_element_child = current_element_child->next;
            }
        } else if (strcmp(current_element->string, "M") == 0) {
            if ((current_element->type & 0xFF) != cJSON_Object) {
                return nullptr;
            }

            std::vector<cJSON *> container = DynamoDBAttributeValueToJsonContainer(current_element);
            node = cJSON_CreateObject();

            for (cJSON *container_node : container) {
                cJSON_AddItemToObject(node, container_node->string, container_node);
            }
        } else if (strcmp(current_element->string, "L") == 0) {
            if ((current_element->type & 0xFF) != cJSON_Array) {
                return nullptr;
            }

            std::vector<cJSON *> container = DynamoDBAttributeValueToJsonContainer(current_element);
            node = cJSON_CreateArray();

            for (cJSON *container_node : container) {
                cJSON_AddItemToArray(node, container_node);
            }
        } else if (strcmp(current_element->string, "BOOL") == 0) {
            if ((current_element->type & 0xFF) != cJSON_True && (current_element->type & 0xFF) != cJSON_False) {
                return nullptr;
            }
            node = cJSON_CreateBool((current_element->type & 0xFF) == cJSON_True);
        } else if (strcmp(current_element->string, "NULL") == 0) {
            if ((current_element->type & 0xFF) != cJSON_True && (current_element->type & 0xFF) != cJSON_False) {
                return nullptr;
            }
            if ((current_element->type & 0xFF) == cJSON_True) {
                node = cJSON_CreateNull();
            }
        }
        
        current_element = current_element->next;
    }

    return node;
}

cJSON *DynamoDBItemToJson(cJSON *attributeValue) {
    cJSON *current_element = attributeValue->child;

    cJSON * item = cJSON_CreateObject();
    while (current_element != nullptr) {
        cJSON *node = DynamoDBAttributeValueToJsonNode(current_element);

        if (node && current_element->string) {
            cJSON_AddItemToObject(item, current_element->string, node);
        }

        current_element = current_element->next;
    }

    return item;
}

std::vector<cJSON *> DynamoDBAttributeValueToJsonContainer(cJSON *attributeValue) {
    cJSON *current_element = attributeValue->child;

    std::vector<cJSON *> container;
    while (current_element != nullptr) {
        cJSON *node = DynamoDBAttributeValueToJsonNode(current_element);

        if (node) {
            if (current_element->string) {
                node->string = (char *)strdup((const unsigned char *)current_element->string);
            }

            container.push_back(node);
        }

        current_element = current_element->next;
    }

    return container;
}

#endif

FString UDynamoDBAttributeValueHelper::DynamoDBAttributeValueToJson(FString attributeValue) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    cJSON *cjsonAttributeValue = cJSON_Parse(TCHAR_TO_UTF8(*attributeValue));

    if (cjsonAttributeValue == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            LOG_DYNAMODB_WARNING(FString::Printf(TEXT("Error before: %s"), UTF8_TO_TCHAR(error_ptr)));
        }
        cJSON_Delete(cjsonAttributeValue);
        return FString();
    }

    cJSON *cjson = DynamoDBAttributeValueToJsonNode(cjsonAttributeValue);
    if (cjson == nullptr) {
        cjson = DynamoDBItemToJson(cjsonAttributeValue);

        if (cjson == nullptr) {
            LOG_DYNAMODB_WARNING("failed to convert");

            cJSON_Delete(cjsonAttributeValue);

            return FString();
        }
    }

    char *string = cJSON_Print(cjson);
    if (string == nullptr)
    {
        LOG_DYNAMODB_WARNING("Failed to print");
    }

    cJSON_Delete(cjson);
    cJSON_Delete(cjsonAttributeValue);

    return UTF8_TO_TCHAR(string);
#else
    return FString();
#endif
}
