/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/Event.h"

#endif

#include "Model/EventCode.h"

#include "AWSEvent.generated.h"

USTRUCT(BlueprintType)
struct FAWSEvent {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet event.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString eventId;

    /**
    *  <p>Unique identifier for an event resource, such as a fleet ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString resourceId;

    /**
    *  <p>Type of event being logged. The following events are currently in use:</p> <p> <b>Fleet creation events:</b> </p> <ul> <li> <p>FLEET_CREATED -- A fleet record was successfully created with a status of <code>NEW</code>. Event messaging includes the fleet ID.</p> </li> <li> <p>FLEET_STATE_DOWNLOADING -- Fleet status changed from <code>NEW</code> to <code>DOWNLOADING</code>. The compressed build has started downloading to a fleet instance for installation.</p> </li> <li> <p> FLEET_BINARY_DOWNLOAD_FAILED -- The build failed to download to the fleet instance.</p> </li> <li> <p>FLEET_CREATION_EXTRACTING_BUILD – The game server build was successfully downloaded to an instance, and the build files are now being extracted from the uploaded build and saved to an instance. Failure at this stage prevents a fleet from moving to <code>ACTIVE</code> status. Logs for this stage display a list of the files that are extracted and saved on the instance. Access the logs by using the URL in <i>PreSignedLogUrl</i>.</p> </li> <li> <p>FLEET_CREATION_RUNNING_INSTALLER – The game server build files were successfully extracted, and the Amazon GameLift is now running the build's install script (if one is included). Failure in this stage prevents a fleet from moving to <code>ACTIVE</code> status. Logs for this stage list the installation steps and whether or not the install completed successfully. Access the logs by using the URL in <i>PreSignedLogUrl</i>. </p> </li> <li> <p>FLEET_CREATION_VALIDATING_RUNTIME_CONFIG -- The build process was successful, and the Amazon GameLift is now verifying that the game server launch paths, which are specified in the fleet's run-time configuration, exist. If any listed launch path exists, Amazon GameLift tries to launch a game server process and waits for the process to report ready. Failures in this stage prevent a fleet from moving to <code>ACTIVE</code> status. Logs for this stage list the launch paths in the run-time configuration and indicate whether each is found. Access the logs by using the URL in <i>PreSignedLogUrl</i>. </p> </li> <li> <p>FLEET_STATE_VALIDATING -- Fleet status changed from <code>DOWNLOADING</code> to <code>VALIDATING</code>.</p> </li> <li> <p> FLEET_VALIDATION_LAUNCH_PATH_NOT_FOUND -- Validation of the run-time configuration failed because the executable specified in a launch path does not exist on the instance.</p> </li> <li> <p>FLEET_STATE_BUILDING -- Fleet status changed from <code>VALIDATING</code> to <code>BUILDING</code>.</p> </li> <li> <p>FLEET_VALIDATION_EXECUTABLE_RUNTIME_FAILURE -- Validation of the run-time configuration failed because the executable specified in a launch path failed to run on the fleet instance.</p> </li> <li> <p>FLEET_STATE_ACTIVATING -- Fleet status changed from <code>BUILDING</code> to <code>ACTIVATING</code>. </p> </li> <li> <p> FLEET_ACTIVATION_FAILED - The fleet failed to successfully complete one of the steps in the fleet activation process. This event code indicates that the game build was successfully downloaded to a fleet instance, built, and validated, but was not able to start a server process. A possible reason for failure is that the game server is not reporting "process ready" to the Amazon GameLift service.</p> </li> <li> <p>FLEET_STATE_ACTIVE -- The fleet's status changed from <code>ACTIVATING</code> to <code>ACTIVE</code>. The fleet is now ready to host game sessions.</p> </li> </ul> <p> <b>VPC peering events:</b> </p> <ul> <li> <p>FLEET_VPC_PEERING_SUCCEEDED -- A VPC peering connection has been established between the VPC for an Amazon GameLift fleet and a VPC in your AWS account.</p> </li> <li> <p>FLEET_VPC_PEERING_FAILED -- A requested VPC peering connection has failed. Event details and status information (see <a>DescribeVpcPeeringConnections</a>) provide additional detail. A common reason for peering failure is that the two VPCs have overlapping CIDR blocks of IPv4 addresses. To resolve this, change the CIDR block for the VPC in your AWS account. For more information on VPC peering failures, see <a href="https://docs.aws.amazon.com/AmazonVPC/latest/PeeringGuide/invalid-peering-configurations.html">https://docs.aws.amazon.com/AmazonVPC/latest/PeeringGuide/invalid-peering-configurations.html</a> </p> </li> <li> <p>FLEET_VPC_PEERING_DELETED -- A VPC peering connection has been successfully deleted.</p> </li> </ul> <p> <b>Spot instance events:</b> </p> <ul> <li> <p> INSTANCE_INTERRUPTED -- A spot instance was interrupted by EC2 with a two-minute notification.</p> </li> </ul> <p> <b>Other fleet events:</b> </p> <ul> <li> <p>FLEET_SCALING_EVENT -- A change was made to the fleet's capacity settings (desired instances, minimum/maximum scaling limits). Event messaging includes the new capacity settings.</p> </li> <li> <p>FLEET_NEW_GAME_SESSION_PROTECTION_POLICY_UPDATED -- A change was made to the fleet's game session protection policy setting. Event messaging includes both the old and new policy setting. </p> </li> <li> <p>FLEET_DELETED -- A request to delete a fleet was initiated.</p> </li> <li> <p> GENERIC_EVENT -- An unspecified event has occurred.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    EEventCode eventCode;

    /**
    *  <p>Additional information related to the event.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString message;

    /**
    *  <p>Time stamp indicating when this event occurred. Format is a number expressed in Unix time as milliseconds (for example "1469498468.057").</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime eventTime;

    /**
    *  <p>Location of stored logs with additional detail that is related to the event. This is useful for debugging issues. The URL is valid for 15 minutes. You can also access fleet creation logs through the Amazon GameLift console.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString preSignedLogUrl;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSEvent &fromAWS(const Aws::GameLift::Model::Event &awsEvent) {
        this->eventId = UTF8_TO_TCHAR(awsEvent.GetEventId().c_str());

        this->resourceId = UTF8_TO_TCHAR(awsEvent.GetResourceId().c_str());

        switch(awsEvent.GetEventCode()) {
            case Aws::GameLift::Model::EventCode::NOT_SET:
                this->eventCode = EEventCode::NOT_SET;
                break;
            case Aws::GameLift::Model::EventCode::GENERIC_EVENT:
                this->eventCode = EEventCode::GENERIC_EVENT;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_CREATED:
                this->eventCode = EEventCode::FLEET_CREATED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_DELETED:
                this->eventCode = EEventCode::FLEET_DELETED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_SCALING_EVENT:
                this->eventCode = EEventCode::FLEET_SCALING_EVENT;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_DOWNLOADING:
                this->eventCode = EEventCode::FLEET_STATE_DOWNLOADING;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_VALIDATING:
                this->eventCode = EEventCode::FLEET_STATE_VALIDATING;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_BUILDING:
                this->eventCode = EEventCode::FLEET_STATE_BUILDING;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_ACTIVATING:
                this->eventCode = EEventCode::FLEET_STATE_ACTIVATING;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_ACTIVE:
                this->eventCode = EEventCode::FLEET_STATE_ACTIVE;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_STATE_ERROR:
                this->eventCode = EEventCode::FLEET_STATE_ERROR;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_INITIALIZATION_FAILED:
                this->eventCode = EEventCode::FLEET_INITIALIZATION_FAILED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_BINARY_DOWNLOAD_FAILED:
                this->eventCode = EEventCode::FLEET_BINARY_DOWNLOAD_FAILED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VALIDATION_LAUNCH_PATH_NOT_FOUND:
                this->eventCode = EEventCode::FLEET_VALIDATION_LAUNCH_PATH_NOT_FOUND;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VALIDATION_EXECUTABLE_RUNTIME_FAILURE:
                this->eventCode = EEventCode::FLEET_VALIDATION_EXECUTABLE_RUNTIME_FAILURE;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VALIDATION_TIMED_OUT:
                this->eventCode = EEventCode::FLEET_VALIDATION_TIMED_OUT;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_ACTIVATION_FAILED:
                this->eventCode = EEventCode::FLEET_ACTIVATION_FAILED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_ACTIVATION_FAILED_NO_INSTANCES:
                this->eventCode = EEventCode::FLEET_ACTIVATION_FAILED_NO_INSTANCES;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_NEW_GAME_SESSION_PROTECTION_POLICY_UPDATED:
                this->eventCode = EEventCode::FLEET_NEW_GAME_SESSION_PROTECTION_POLICY_UPDATED;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_INVALID_PATH:
                this->eventCode = EEventCode::SERVER_PROCESS_INVALID_PATH;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_SDK_INITIALIZATION_TIMEOUT:
                this->eventCode = EEventCode::SERVER_PROCESS_SDK_INITIALIZATION_TIMEOUT;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_PROCESS_READY_TIMEOUT:
                this->eventCode = EEventCode::SERVER_PROCESS_PROCESS_READY_TIMEOUT;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_CRASHED:
                this->eventCode = EEventCode::SERVER_PROCESS_CRASHED;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_TERMINATED_UNHEALTHY:
                this->eventCode = EEventCode::SERVER_PROCESS_TERMINATED_UNHEALTHY;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_FORCE_TERMINATED:
                this->eventCode = EEventCode::SERVER_PROCESS_FORCE_TERMINATED;
                break;
            case Aws::GameLift::Model::EventCode::SERVER_PROCESS_PROCESS_EXIT_TIMEOUT:
                this->eventCode = EEventCode::SERVER_PROCESS_PROCESS_EXIT_TIMEOUT;
                break;
            case Aws::GameLift::Model::EventCode::GAME_SESSION_ACTIVATION_TIMEOUT:
                this->eventCode = EEventCode::GAME_SESSION_ACTIVATION_TIMEOUT;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_CREATION_EXTRACTING_BUILD:
                this->eventCode = EEventCode::FLEET_CREATION_EXTRACTING_BUILD;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_CREATION_RUNNING_INSTALLER:
                this->eventCode = EEventCode::FLEET_CREATION_RUNNING_INSTALLER;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_CREATION_VALIDATING_RUNTIME_CONFIG:
                this->eventCode = EEventCode::FLEET_CREATION_VALIDATING_RUNTIME_CONFIG;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VPC_PEERING_SUCCEEDED:
                this->eventCode = EEventCode::FLEET_VPC_PEERING_SUCCEEDED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VPC_PEERING_FAILED:
                this->eventCode = EEventCode::FLEET_VPC_PEERING_FAILED;
                break;
            case Aws::GameLift::Model::EventCode::FLEET_VPC_PEERING_DELETED:
                this->eventCode = EEventCode::FLEET_VPC_PEERING_DELETED;
                break;
            case Aws::GameLift::Model::EventCode::INSTANCE_INTERRUPTED:
                this->eventCode = EEventCode::INSTANCE_INTERRUPTED;
                break;
            default:
                this->eventCode = EEventCode::NOT_SET;
                break;
        }

        this->message = UTF8_TO_TCHAR(awsEvent.GetMessage().c_str());

        this->eventTime = FDateTime(1970, 1, 1) + FTimespan(awsEvent.GetEventTime().Millis() * ETimespan::TicksPerMillisecond);

        this->preSignedLogUrl = UTF8_TO_TCHAR(awsEvent.GetPreSignedLogUrl().c_str());

        return *this;
    }
#endif
};
