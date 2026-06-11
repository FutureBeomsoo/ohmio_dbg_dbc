#ifndef main_DBC_TOOL_GENERATED_H
#define main_DBC_TOOL_GENERATED_H

#include <stdint.h>
#include "additionalDbcCan.h"
#include "dbc_MsgID_main.h"
#include <math.h>
#include <assert.h>
#include "ConversionHelper.h"


// message ID 0x38 Timepulse_front
// message ID 0x39 Timepulse_rear
typedef struct{ 
	union
	{ 
		uint8_t buf[5];
		struct
		{
			uint64_t localTime :32;
			uint64_t sync :2;
		} signals;
	} raw;
} GpsPpsMsg_t;

// message ID 0x225 frontGpsUbxPart1
// message ID 0x235 rearGpsUbxPart1
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Latitude :36;    //degrees
			int64_t Height :23;    //metres
			uint64_t reserved :1;
			uint64_t Valid_Checksum :1;
			uint64_t Data_Available :1;
			uint64_t Sync :2;
		} signals;
	} raw;
    double Latitude;
    double Height;
} UBXPart1Msg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void UBXPart1Msg_ToCan(UBXPart1Msg_t * msg) 
{ 
    assert(msg->Latitude >= -90 && msg->Latitude <= 90);
    assert(msg->Height >= -1694 && msg->Height <= 6694);
    assert(msg->raw.signals.Data_Available <= 1);
    assert(msg->raw.signals.Sync <= 3);
    msg->raw.signals.Latitude = RoundLimitSigned(msg->Latitude, 0.00000001, 36);
    msg->raw.signals.Height = RoundLimitSigned(msg->Height + 2500, 0.001, 23);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void UBXPart1Msg_FromCan(UBXPart1Msg_t * msg) 
{ 
    msg->Latitude = msg->raw.signals.Latitude * 0.00000001;
    msg->Height = msg->raw.signals.Height * 0.001 - 2500;
}
// message ID 0x226 frontGpsUbxPart2
// message ID 0x236 rearGpsUbxPart2
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Longitude :36;    //degrees
			uint64_t HorizontalAccuracy :10;    //metres
			uint64_t VerticalAccuracy :10;    //metres
			uint64_t CarrierSolution :2;
			uint64_t pvtValidChecksum :1;
			uint64_t reserved :3;
			uint64_t Sync :2;
		} signals;
	} raw;
    double Longitude;
    double HorizontalAccuracy;
    double VerticalAccuracy;
} UBXPart2Msg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void UBXPart2Msg_ToCan(UBXPart2Msg_t * msg) 
{ 
    assert(msg->Longitude >= -180 && msg->Longitude <= 180);
    assert(msg->HorizontalAccuracy <= 1.024);
    assert(msg->VerticalAccuracy <= 1.024);
    assert(msg->raw.signals.CarrierSolution <= 2);
    assert(msg->raw.signals.pvtValidChecksum <= 1);
    assert(msg->raw.signals.Sync <= 3);
    msg->raw.signals.Longitude = RoundLimitSigned(msg->Longitude, 0.00000001, 36);
    assert(msg->HorizontalAccuracy >= 0);
    msg->raw.signals.HorizontalAccuracy = RoundLimitUnsigned(msg->HorizontalAccuracy, 0.001, 10);
    assert(msg->VerticalAccuracy >= 0);
    msg->raw.signals.VerticalAccuracy = RoundLimitUnsigned(msg->VerticalAccuracy, 0.001, 10);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void UBXPart2Msg_FromCan(UBXPart2Msg_t * msg) 
{ 
    msg->Longitude = msg->raw.signals.Longitude * 0.00000001;
    msg->HorizontalAccuracy = msg->raw.signals.HorizontalAccuracy * 0.001;
    msg->VerticalAccuracy = msg->raw.signals.VerticalAccuracy * 0.001;
}
// message ID 0x227 frontGpsUbxPart3
// message ID 0x237 rearGpsUbxPart3
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t iTow :32;    //ms
			uint64_t localTime :32;    //ms
		} signals;
	} raw;
} UBXPart3Msg_t;

// message ID 0x10 ErrorLocalisation
enum LocalisationErrorCode
{
	Loc_CAN_Comms = 0,
	Loc_Compass_Comms,
	Loc_GPS1_Comms,
	Loc_GPS2_Comms,
	Loc_UWB1_Comms,
	Loc_UWB2_Comms,
	Loc_GPS1_Serial,
	Loc_GPS2_Serial,
	Loc_Joystick_Disconnect,
	Loc_Joystick_Comms,
	Loc_Joystick_Centre,
	Loc_Safety_Relay_Open,
	Loc_Dri_Info_Comms,
	Loc_Reserved,
	Loc_Reserved2,
	Loc_Reserved3,
	Loc_Reserved4,
	Loc_Reserved5,
	Loc_Reserved6,
	Loc_Reserved7,
	Loc_Reserved8,
	Loc_Reserved9,
	Loc_Reserved10,
	Loc_Reserved11,
	Loc_Reserved12,
	Loc_Reserved13,
	Loc_Reserved14,
	Loc_Reserved15,
	Loc_motor_Comms,
	Loc_motor_Temp,
	//always add error codes above this
	Loc_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t LocCANCommsError :1;
			uint64_t LocCompassCommsError :1;
			uint64_t LocGPS1CommsError :1;
			uint64_t LocGPS2CommsError :1;
			uint64_t LocUWB1CommsError :1;
			uint64_t LocUWB2CommsError :1;
			uint64_t LocGPS1SerialError :1;
			uint64_t LocGPS2SerialError :1;
			uint64_t LocJoystickDisconnect :1;
			uint64_t LocJoystickCommsError :1;
			uint64_t LocJoystickCentreError :1;
			uint64_t LocSafetyRelayOpen :1;
			uint64_t LocDriInfoCommsError :1;
			uint64_t reserved :15;
			uint64_t motorCommsError :1;
			uint64_t motorTempError :1;
		} signals;
	} raw;
} ErrorLocalisation_t;

// message ID 0x200 TimestampMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t time :64;    //ms
		} signals;
	} raw;
} TimestampMsg_t;

// message ID 0x3A frontWheelSpeed
// message ID 0x3B rearWheelSpeed
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t left :16;    //rad/s
			uint64_t right :16;    //rad/s
			uint64_t clock :32;    //decinanos
		} signals;
	} raw;
    double left;
    double right;
} WheelSpeedMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void WheelSpeedMsg_ToCan(WheelSpeedMsg_t * msg) 
{ 
    assert(msg->left <= 65.535);
    assert(msg->right <= 65.535);
    assert(msg->left >= 0);
    msg->raw.signals.left = RoundLimitUnsigned(msg->left, 0.001, 16);
    assert(msg->right >= 0);
    msg->raw.signals.right = RoundLimitUnsigned(msg->right, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void WheelSpeedMsg_FromCan(WheelSpeedMsg_t * msg) 
{ 
    msg->left = msg->raw.signals.left * 0.001;
    msg->right = msg->raw.signals.right * 0.001;
}
// message ID 0x3C frontWheelCnt
// message ID 0x3D rearWheelCnt
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t right_count :16;
			uint64_t left_count :16;
			uint64_t clock :32;    //decinanos
		} signals;
	} raw;
} WheelCountMsg_t;

// message ID 0x740 WheelSpeedEvents
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t first_edge_offset :20;    //s
			uint64_t first_edge_direction :1;
			uint64_t second_edge_offset :20;    //s
			uint64_t second_edge_direction :1;
			uint64_t third_edge_offset :20;    //s
			uint64_t third_edge_direction :1;
			uint64_t overflow :1;
		} signals;
	} raw;
    double first_edge_offset;
    double second_edge_offset;
    double third_edge_offset;
} WheelSpeedEvents_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void WheelSpeedEvents_ToCan(WheelSpeedEvents_t * msg) 
{ 
    assert(msg->first_edge_offset <= 0.01);
    assert(msg->raw.signals.first_edge_direction <= 1);
    assert(msg->second_edge_offset <= 0.01);
    assert(msg->raw.signals.second_edge_direction <= 1);
    assert(msg->third_edge_offset <= 0.01);
    assert(msg->raw.signals.third_edge_direction <= 1);
    assert(msg->raw.signals.overflow <= 1);
    assert(msg->first_edge_offset >= 0);
    msg->raw.signals.first_edge_offset = RoundLimitUnsigned(msg->first_edge_offset, 0.00000001, 20);
    assert(msg->second_edge_offset >= 0);
    msg->raw.signals.second_edge_offset = RoundLimitUnsigned(msg->second_edge_offset, 0.00000001, 20);
    assert(msg->third_edge_offset >= 0);
    msg->raw.signals.third_edge_offset = RoundLimitUnsigned(msg->third_edge_offset, 0.00000001, 20);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void WheelSpeedEvents_FromCan(WheelSpeedEvents_t * msg) 
{ 
    msg->first_edge_offset = msg->raw.signals.first_edge_offset * 0.00000001;
    msg->second_edge_offset = msg->raw.signals.second_edge_offset * 0.00000001;
    msg->third_edge_offset = msg->raw.signals.third_edge_offset * 0.00000001;
}
// message ID 0x2B5 EPB1Status
// message ID 0x2B6 EPB2Status
typedef struct{ 
	union
	{ 
		uint8_t buf[7];
		struct
		{
			uint64_t status :8;
			uint64_t mode :8;
			uint64_t error :8;
			uint64_t current :16;    //A
			uint64_t vin1 :8;    //V
			uint64_t vin2 :8;    //V
		} signals;
	} raw;
    double current;
    double vin1;
    double vin2;
} EPBStatusMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EPBStatusMsg_ToCan(EPBStatusMsg_t * msg) 
{ 
    assert(msg->raw.signals.status <= 2);
    assert(msg->raw.signals.mode <= 3);
    assert(msg->raw.signals.error <= 1);
    assert(msg->current <= 30);
    assert(msg->vin1 <= 14.5);
    assert(msg->vin2 <= 14.5);
    assert(msg->current >= 0);
    msg->raw.signals.current = RoundLimitUnsigned(msg->current, 0.01, 16);
    assert(msg->vin1 >= 0);
    msg->raw.signals.vin1 = RoundLimitUnsigned(msg->vin1, 0.1, 8);
    assert(msg->vin2 >= 0);
    msg->raw.signals.vin2 = RoundLimitUnsigned(msg->vin2, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EPBStatusMsg_FromCan(EPBStatusMsg_t * msg) 
{ 
    msg->current = msg->raw.signals.current * 0.01;
    msg->vin1 = msg->raw.signals.vin1 * 0.1;
    msg->vin2 = msg->raw.signals.vin2 * 0.1;
}
// message ID 0x40 ResetReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reset :16;
			uint64_t shutdown :16;
			uint64_t parameter :16;
		} signals;
	} raw;
} ResetReqMsg_t;

// message ID 0x510 frontReqIndicatorBrake
// message ID 0x511 rearReqIndicatorBrake
// message ID 0x520 frontStatusIndicatorBrake
// message ID 0x521 rearStatusIndicatorBrake
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t left :8;
			uint64_t right :8;
			uint64_t brake :8;
		} signals;
	} raw;
} IndicatorBrakeStatusAndReqMsg_t;

// message ID 0x311 ConfigResp
// message ID 0x318 ConfigSignResp
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t value :32;
		} signals;
	} raw;
    double value;
} ConfigRespMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ConfigRespMsg_ToCan(ConfigRespMsg_t * msg) 
{ 
    assert(msg->value >= 0);
    msg->raw.signals.value = RoundLimitUnsigned(msg->value, 0.001, 32);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ConfigRespMsg_FromCan(ConfigRespMsg_t * msg) 
{ 
    msg->value = msg->raw.signals.value * 0.001;
}
// message ID 0x310 ParameterConfMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :15;
			uint64_t read :1;
			uint64_t value :32;
			uint64_t writeAll :1;
			uint64_t writeLast :1;
		} signals;
	} raw;
    double value;
} ParameterConfMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ParameterConfMsg_ToCan(ParameterConfMsg_t * msg) 
{ 
    assert(msg->raw.signals.read <= 1);
    assert(msg->raw.signals.writeAll <= 1);
    assert(msg->value >= 0);
    msg->raw.signals.value = RoundLimitUnsigned(msg->value, 0.001, 32);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ParameterConfMsg_FromCan(ParameterConfMsg_t * msg) 
{ 
    msg->value = msg->raw.signals.value * 0.001;
}
// message ID 0x312 VersionReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
		} signals;
	} raw;
} VersionReqMsg_t;

// message ID 0x317 ParameterConfSignMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :15;
			uint64_t read :1;
			int64_t value :32;
			uint64_t writeToMRAM :1;
		} signals;
	} raw;
    double value;
} ParameterConfSignMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ParameterConfSignMsg_ToCan(ParameterConfSignMsg_t * msg) 
{ 
    assert(msg->raw.signals.read <= 1);
    assert(msg->raw.signals.writeToMRAM <= 1);
    msg->raw.signals.value = RoundLimitSigned(msg->value, 0.001, 32);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ParameterConfSignMsg_FromCan(ParameterConfSignMsg_t * msg) 
{ 
    msg->value = msg->raw.signals.value * 0.001;
}
// message ID 0x320 SystemReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t path :8;
			uint64_t maxSpeed :16;    //m/s
			uint64_t brakePressure :8;    //bar
			uint64_t reserved :20;
			uint64_t driveDisalowed :1;
			uint64_t errorCheck :1;
			uint64_t useLidar :1;
			uint64_t useUltrasound :1;
		} signals;
	} raw;
} SystemReqMsg_t;

// message ID 0x340 EPBReleaseMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AA :8;
			uint64_t A02 :8;
		} signals;
	} raw;
} EPBReleaseMsg_t;

// message ID 0x650 TrackCtrlManageMsg
// message ID 0x660 TrackCtrlDriveMsg
// message ID 0x670 TrackCtrlObsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t destination :16;
			uint64_t type :16;
			uint64_t reserved :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
} TrackCtrlMsg_t;

// message ID 0x651 TrackAckManageMsg
// message ID 0x661 TrackAckDriveMsg
// message ID 0x671 TrackAckObsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t response :8;
			uint64_t waypoint :16;
		} signals;
	} raw;
} TrackAckMsg_t;

// message ID 0x652 TrackDataManageMsg
// message ID 0x662 TrackDataDriveMsg
// message ID 0x672 TrackDataObsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :4;
			uint64_t reserved :4;
			uint64_t data :56;
		} signals;
	} raw;
} TrackDataMsg_t;

// message ID 0x680 SteerCalibrationMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t id :16;
			uint64_t posFactor :16;
			uint64_t negFactor :16;
		} signals;
	} raw;
    double posFactor;
    double negFactor;
} SteerCalibrationMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteerCalibrationMsg_ToCan(SteerCalibrationMsg_t * msg) 
{ 
    assert(msg->posFactor <= 2.999);
    assert(msg->negFactor <= 2.999);
    assert(msg->posFactor >= 0);
    msg->raw.signals.posFactor = RoundLimitUnsigned(msg->posFactor, 0.001, 16);
    assert(msg->negFactor >= 0);
    msg->raw.signals.negFactor = RoundLimitUnsigned(msg->negFactor, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteerCalibrationMsg_FromCan(SteerCalibrationMsg_t * msg) 
{ 
    msg->posFactor = msg->raw.signals.posFactor * 0.001;
    msg->negFactor = msg->raw.signals.negFactor * 0.001;
}
// message ID 0x681 SteerConfigMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
		} signals;
	} raw;
} SteerConfigMsg_t;

// message ID 0x682 SteerConfigReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AA :8;
			uint64_t id :16;
		} signals;
	} raw;
} SteerConfigReqMsg_t;

// message ID 0x690 SteerMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t frontAngle :16;    //degree
			int64_t rearAngle :16;
		} signals;
	} raw;
    double frontAngle;
    double rearAngle;
} SteerMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteerMsg_ToCan(SteerMsg_t * msg) 
{ 
    assert(msg->frontAngle >= -45 && msg->frontAngle <= 45);
    assert(msg->rearAngle >= -45 && msg->rearAngle <= 45);
    msg->raw.signals.frontAngle = RoundLimitSigned(msg->frontAngle, 0.01, 16);
    msg->raw.signals.rearAngle = RoundLimitSigned(msg->rearAngle, 0.01, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteerMsg_FromCan(SteerMsg_t * msg) 
{ 
    msg->frontAngle = msg->raw.signals.frontAngle * 0.01;
    msg->rearAngle = msg->raw.signals.rearAngle * 0.01;
}
// message ID 0x410 LiveUpdateReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
		} signals;
	} raw;
} LiveUpdateReqMsg_t;

// message ID 0x2B ManagementError
enum ManagementErrorCode
{
	monitor = 0,
	mgt_Status,
	mgt_Drv_Info_Comms,
	mgt_shared_Drv,
	//always add error codes above this
	mgt_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t monitorError :1;
			uint64_t mgtStatusError :1;
			uint64_t mgtDrvInfoCommsError :1;
			uint64_t sharedDriveError :1;
			uint64_t reserved :4;
			uint64_t GPSOff :2;
			uint64_t reserved1 :6;
			uint64_t drvGPSOff :2;
			uint64_t ignoreDZ :2;
			uint64_t mcuVersionsOk :2;
			uint64_t recording :2;
			uint64_t limpMode :2;
		} signals;
	} raw;
} ManagementError_t;

// message ID 0x130 TrafficLightMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t status :8;
			uint64_t timeToChange :16;    //0.1sec
			uint64_t lightID :16;
			uint64_t stopNow :1;    //bool
		} signals;
	} raw;
    double timeToChange;
} TrafficLightMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void TrafficLightMsg_ToCan(TrafficLightMsg_t * msg) 
{ 
    assert(msg->raw.signals.status <= 255);
    assert(msg->raw.signals.stopNow <= 1);
    assert(msg->timeToChange >= 0);
    msg->raw.signals.timeToChange = RoundLimitUnsigned(msg->timeToChange, 0.1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void TrafficLightMsg_FromCan(TrafficLightMsg_t * msg) 
{ 
    msg->timeToChange = msg->raw.signals.timeToChange * 0.1;
}
// message ID 0x422 AtmelUpdateReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t action :8;
			uint64_t address :16;
			uint64_t data :32;
			uint64_t checksum :8;
		} signals;
	} raw;
} AtmelUpdateReqMsg_t;

// message ID 0x630 ConnectWp
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t startWp :19;    //wp
			uint64_t endWp :19;    //wp
			uint64_t startTrack :2;    //track_ID
			uint64_t endTrack :2;    //track_ID
			uint64_t type :3;    //CONNECT_TRACK_TYPE
			uint64_t distanceWpForCurved :3;    //num_wp_befor_start_for_curve_calcualtion
			uint64_t restore :1;    //revert_to_original_track
		} signals;
	} raw;
} ConnectWp_t;

// message ID 0x50 ResetLocalisation
// message ID 0x51 ResetDrive
// message ID 0x52 ResetSteering1
// message ID 0x53 ResetSteering2
// message ID 0x54 ResetManual
// message ID 0x55 ResetFusion
// message ID 0x56 ResetBlackBox
// message ID 0x57 ResetObsPC
// message ID 0x58 ResetLMotor
// message ID 0x59 ResetRMotor
// message ID 0x5A ResetEHB
// message ID 0x5C ResetEPB1
// message ID 0x5D ResetEPB2
// message ID 0x5E ResetSignal1
// message ID 0x5F ResetSignal2
// message ID 0x60 ResetJoystick
// message ID 0x63 ResetStartup
// message ID 0x68 ResetFoot1
// message ID 0x69 ResetFoot2
// message ID 0x6D ResetNetworkComm
// message ID 0x6E ResetAccessory1
// message ID 0x6F ResetAccessory2
// message ID 0x70 ResetWheelSpeed1
// message ID 0x71 ResetWheelSpeed2
// message ID 0x76 ResetTranslator
// message ID 0x77 ResetTranslator2
// message ID 0x78 ResetTeleOp
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t cause :16;
		} signals;
	} raw;
} ResetCauseMsg_t;

// message ID 0x6A ResetSecurity
typedef struct{ 
	union
	{ 
		uint8_t buf[5];
		struct
		{
			uint64_t cause :16;
		} signals;
	} raw;
} ResetSecurity_t;

// message ID 0x62 AtmelResetSafety
// message ID 0x64 AtmelResetLocalisation
// message ID 0x65 AtmelResetDrive
// message ID 0x66 AtmelResetManual
// message ID 0x67 AtmelResetFusion
// message ID 0x6C AtmelResetSecurity
// message ID 0x79 AtmelResetTeleop
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t cause :8;
		} signals;
	} raw;
} AtmelResetMsg_t;

// message ID 0x530 FrontRightIndicatorLightReqMsg
// message ID 0x531 FrontRightIndicatorLightStatusMsg
// message ID 0x540 FrontLeftIndicatorLightReqMsg
// message ID 0x541 FrontLeftIndicatorLightStatusMsg
// message ID 0x550 RearBrakeLightReqMsg
// message ID 0x551 RearBrakeLightStatusMsg
// message ID 0x560 RearRightIndicatorLightReqMsg
// message ID 0x561 RearRightIndicatorLightStatusMsg
// message ID 0x570 RearLeftIndicatorLightReqMsg
// message ID 0x571 RearLeftIndicatorLightStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t on :8;
		} signals;
	} raw;
} IndicatorBrakeLightMsg_t;

// message ID 0x322 StartupStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[5];
		struct
		{
			uint64_t bms :1;
			uint64_t emergencyLevel :3;
			uint64_t safetyLineErr :1;
			uint64_t reserved :2;
			uint64_t motorRly :1;
			uint64_t status :8;
			uint64_t key1 :8;
			uint64_t key2 :8;
		} signals;
	} raw;
} StartupStatusMsg_t;

// message ID 0x600 ErrorReportMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[6];
		struct
		{
			uint64_t id :8;
			uint64_t type :8;
			uint64_t error :32;
		} signals;
	} raw;
} ErrorReportMsg_t;

// message ID 0x584 BMSStatusStdMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxDischargeCurrent :16;    //A
			uint64_t maxChargeCurrent :16;    //A
			uint64_t soc :8;    //%
			uint64_t maxBattVolt :8;    //V
			uint64_t count :8;
			uint64_t reserved :6;
			uint64_t errorLevel :2;
		} signals;
	} raw;
    double maxDischargeCurrent;
    double maxChargeCurrent;
    double soc;
} BMSStatusStdMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void BMSStatusStdMsg_ToCan(BMSStatusStdMsg_t * msg) 
{ 
    assert(msg->soc <= 100);
    assert(msg->raw.signals.maxBattVolt <= 250);
    assert(msg->raw.signals.count <= 255);
    assert(msg->raw.signals.errorLevel <= 3);
    assert(msg->maxDischargeCurrent + 600 >= 0);
    msg->raw.signals.maxDischargeCurrent = RoundLimitUnsigned(msg->maxDischargeCurrent + 600, 0.02, 16);
    assert(msg->maxChargeCurrent + 600 >= 0);
    msg->raw.signals.maxChargeCurrent = RoundLimitUnsigned(msg->maxChargeCurrent + 600, 0.02, 16);
    assert(msg->soc >= 0);
    msg->raw.signals.soc = RoundLimitUnsigned(msg->soc, 0.4, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void BMSStatusStdMsg_FromCan(BMSStatusStdMsg_t * msg) 
{ 
    msg->maxDischargeCurrent = msg->raw.signals.maxDischargeCurrent * 0.02 - 600;
    msg->maxChargeCurrent = msg->raw.signals.maxChargeCurrent * 0.02 - 600;
    msg->soc = msg->raw.signals.soc * 0.4;
}
// message ID 0x280 frontSteeringStatus
// message ID 0x281 rearSteeringStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t angle :16;    //degree
			uint64_t status :3;
			uint64_t calibrationSet :2;
			uint64_t sensorFailed :1;
			uint64_t factorSet :2;
			uint64_t heartbeat :8;
			int64_t temperature :8;    //degree
			uint64_t time :24;
		} signals;
	} raw;
    double angle;
    double temperature;
} SteeringStatusMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringStatusMsg_ToCan(SteeringStatusMsg_t * msg) 
{ 
    assert(msg->angle >= -45 && msg->angle <= 45);
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.calibrationSet <= 3);
    assert(msg->raw.signals.sensorFailed <= 1);
    assert(msg->raw.signals.factorSet <= 3);
    assert(msg->raw.signals.heartbeat <= 255);
    assert(msg->temperature >= -127 && msg->temperature <= 127);
    msg->raw.signals.angle = RoundLimitSigned(msg->angle, 0.01, 16);
    msg->raw.signals.temperature = RoundLimitSigned(msg->temperature, 1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringStatusMsg_FromCan(SteeringStatusMsg_t * msg) 
{ 
    msg->angle = msg->raw.signals.angle * 0.01;
    msg->temperature = msg->raw.signals.temperature * 1.0;
}
// message ID 0x683 SteeringRespMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t manufactureNo :8;
			uint64_t posFactor :16;
			uint64_t negFactor :16;
		} signals;
	} raw;
    double posFactor;
    double negFactor;
} SteeringRespMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringRespMsg_ToCan(SteeringRespMsg_t * msg) 
{ 
    assert(msg->posFactor <= 2.999);
    assert(msg->negFactor <= 2.999);
    assert(msg->posFactor >= 0);
    msg->raw.signals.posFactor = RoundLimitUnsigned(msg->posFactor, 0.001, 16);
    assert(msg->negFactor >= 0);
    msg->raw.signals.negFactor = RoundLimitUnsigned(msg->negFactor, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringRespMsg_FromCan(SteeringRespMsg_t * msg) 
{ 
    msg->posFactor = msg->raw.signals.posFactor * 0.001;
    msg->negFactor = msg->raw.signals.negFactor * 0.001;
}
// message ID 0x330 EHBStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t active :1;
			uint64_t parkReq :1;
			uint64_t reserved :6;
			uint64_t pressure :8;    //bar
			uint64_t reserved1 :6;
			uint64_t condition :2;
			uint64_t pedalTravel :8;    //%
			uint64_t faultLevel :4;
			uint64_t reserved2 :4;
			uint64_t aimPressure :8;    //bar
			uint64_t counter :4;
			uint64_t reserved3 :4;
			uint64_t checksum :8;
		} signals;
	} raw;
} EHBStatusMsg_t;

// message ID 0x331 EHBPowerMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t current :8;    //A
			uint64_t reserved :4;
			uint64_t currentEx :4;    //A
			uint64_t voltage :8;    //V
			uint64_t s16_ADC :2;
			uint64_t reserved1 :6;
			uint64_t s16_ADCEx :8;
			uint64_t reserved2 :8;
			uint64_t counter :4;
			uint64_t reserved3 :4;
			uint64_t checksum :8;
		} signals;
	} raw;
    double current;
    double voltage;
    double s16_ADC;
} EHBPowerMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBPowerMsg_ToCan(EHBPowerMsg_t * msg) 
{ 
    assert(msg->current <= 100);
    assert(msg->voltage <= 63.75);
    assert(msg->s16_ADC <= 1023);
    assert(msg->raw.signals.counter <= 15);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->voltage >= 0);
    msg->raw.signals.voltage = RoundLimitUnsigned(msg->voltage, 0.25, 8);
    assert(msg->current + 100 >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->current + 100, 0.25, 12);
    msg->raw.signals.current =  temp >> 4;
    msg->raw.signals.currentEx =  temp & 0x0F;
    assert(msg->s16_ADC >= 0);
    temp = RoundLimitUnsigned(msg->s16_ADC, 1, 10);
    msg->raw.signals.s16_ADC =  temp >> 8;
    msg->raw.signals.s16_ADCEx =  temp & 0xFF;
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBPowerMsg_FromCan(EHBPowerMsg_t * msg) 
{ 
    msg->voltage = msg->raw.signals.voltage * 0.25;
    msg->current = ((msg->raw.signals.current << 4) + msg->raw.signals.currentEx) * 0.25 - 100;
    msg->s16_ADC = ((msg->raw.signals.s16_ADC << 8) + msg->raw.signals.s16_ADCEx) * 1.0;
}
// message ID 0x332 EHBT060PowerMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reserved :8;
			uint64_t voltage :8;    //V
			uint64_t s16_ADC :6;
			uint64_t reserved1 :6;
			uint64_t s16_ADCEx :4;
			uint64_t cylinderPosition :4;    //mm
			uint64_t reserved2 :4;
			uint64_t cylinderPositionEx :8;    //mm
			uint64_t counter :4;
			uint64_t reserved3 :4;
			uint64_t checksum :8;
		} signals;
	} raw;
    double voltage;
    double cylinderPosition;
    double s16_ADC;
} EHBT060PowerMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBT060PowerMsg_ToCan(EHBT060PowerMsg_t * msg) 
{ 
    assert(msg->voltage <= 63.75);
    assert(msg->s16_ADC <= 1023);
    assert(msg->cylinderPosition >= -5 && msg->cylinderPosition <= 45);
    assert(msg->raw.signals.counter <= 15);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->voltage >= 0);
    msg->raw.signals.voltage = RoundLimitUnsigned(msg->voltage, 0.25, 8);
    assert(msg->s16_ADC >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->s16_ADC, 1, 10);
    msg->raw.signals.s16_ADC =  temp >> 4;
    msg->raw.signals.s16_ADCEx =  temp & 0x0F;
    assert(msg->cylinderPosition + 5 >= 0);
    temp = RoundLimitUnsigned(msg->cylinderPosition + 5, 0.02, 12);
    msg->raw.signals.cylinderPosition =  temp >> 8;
    msg->raw.signals.cylinderPositionEx =  temp & 0xFF;
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBT060PowerMsg_FromCan(EHBT060PowerMsg_t * msg) 
{ 
    msg->voltage = msg->raw.signals.voltage * 0.25;
    msg->s16_ADC = ((msg->raw.signals.s16_ADC << 4) + msg->raw.signals.s16_ADCEx) * 1.0;
    msg->cylinderPosition = ((msg->raw.signals.cylinderPosition << 8) + msg->raw.signals.cylinderPositionEx) * 0.02 - 5;
}
// message ID 0x180 ManualDriveMsg
// message ID 0x185 LocManualMsg
// message ID 0x187 TransDriveMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t frontSteerAngle :16;    //degree
			uint64_t slide :8;
			uint64_t pressure :8;    //bar
			uint64_t start :1;
			uint64_t reverse :1;
			uint64_t reserved :2;
			uint64_t brake :1;
			uint64_t EPB :1;
			uint64_t reserved1 :2;
			int64_t rearSteerAngle :16;    //degree
			uint64_t id :8;
		} signals;
	} raw;
    double frontSteerAngle;
    double rearSteerAngle;
} ManualDriveMsg_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ManualDriveMsg_ToCan(ManualDriveMsg_t * msg) 
{ 
    assert(msg->frontSteerAngle >= -45 && msg->frontSteerAngle <= 45);
    assert(msg->raw.signals.slide <= 255);
    assert(msg->raw.signals.pressure <= 50);
    assert(msg->raw.signals.start <= 1);
    assert(msg->raw.signals.reverse <= 1);
    assert(msg->raw.signals.brake <= 1);
    assert(msg->raw.signals.EPB <= 1);
    assert(msg->rearSteerAngle >= -45 && msg->rearSteerAngle <= 45);
    msg->raw.signals.frontSteerAngle = RoundLimitSigned(msg->frontSteerAngle, 0.01, 16);
    msg->raw.signals.rearSteerAngle = RoundLimitSigned(msg->rearSteerAngle, 0.01, 16);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ManualDriveMsg_FromCan(ManualDriveMsg_t * msg) 
{ 
    msg->frontSteerAngle = msg->raw.signals.frontSteerAngle * 0.01;
    msg->rearSteerAngle = msg->raw.signals.rearSteerAngle * 0.01;
}
// message ID 0x181 JoystickMsg
// message ID 0x183 TeleOpMsg
// message ID 0x186 LocJoystickMsg
// message ID 0x188 TransJoystickMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t x :10;
			uint64_t y :10;
			uint64_t hatswitch :4;
			uint64_t rotation :8;
			uint64_t throttle :8;
			uint64_t b1 :1;
			uint64_t b2 :1;
			uint64_t b3 :1;
			uint64_t b4 :1;
			uint64_t b5 :1;
			uint64_t b6 :1;
			uint64_t b7 :1;
			uint64_t b8 :1;
			uint64_t b9 :1;
			uint64_t b10 :1;
			uint64_t b11 :1;
			uint64_t b12 :1;
			uint64_t reserved :4;
			uint64_t id :8;
		} signals;
	} raw;
} JoystickMsg_t;

// message ID 0x323 LoadingReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxAngle :2;
			uint64_t reverse :1;
			uint64_t dualAxis :1;
			uint64_t horn :1;
			uint64_t EHB :1;
			uint64_t EPB :1;
		} signals;
	} raw;
} LoadingReqMsg_t;

// message ID 0x150 EHBReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t enable :4;
			uint64_t parkActive :4;
			uint64_t slope :8;    //degree
			uint64_t speed :8;    //km/h
			uint64_t reserved :1;
			uint64_t speedQ :2;
			uint64_t speedEx :5;    //km/h
			uint64_t pressure :8;    //bar
			uint64_t reserved1 :8;
			uint64_t counter :4;
			uint64_t reserved2 :4;
			uint64_t checksum :8;
		} signals;
	} raw;
    double slope;
    double speed;
} EHBReqMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBReqMsg_ToCan(EHBReqMsg_t * msg) 
{ 
    assert(msg->raw.signals.enable <= 2);
    assert(msg->raw.signals.parkActive <= 2);
    assert(msg->slope <= 45);
    assert(msg->speed <= 460.69);
    assert(msg->raw.signals.speedQ <= 2);
    assert(msg->raw.signals.pressure <= 100);
    assert(msg->raw.signals.counter <= 15);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->slope >= 0);
    msg->raw.signals.slope = RoundLimitUnsigned(msg->slope, 0.1758125, 8);
    assert(msg->speed >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->speed, 0.05625, 13);
    msg->raw.signals.speed =  temp >> 5;
    msg->raw.signals.speedEx =  temp & 0x1F;
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void EHBReqMsg_FromCan(EHBReqMsg_t * msg) 
{ 
    msg->slope = msg->raw.signals.slope * 0.1758125;
    msg->speed = ((msg->raw.signals.speed << 5) + msg->raw.signals.speedEx) * 0.05625;
}
// message ID 0x663 TrackMD5ReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t path :8;
		} signals;
	} raw;
} TrackMD5ReqMsg_t;

// message ID 0x11 ErrorDriveController
enum DrvErrorCode
{
	Drv_Fusion_Comms = 0,
	Drv_Fusion_Quality2,
	Drv_Fusion_Quality1,
	Drv_Heading,
	Drv_Distance,
	Drv_Steer_Comms,
	Drv_Steer2_Comms,
	Drv_Motor_Comms,
	Drv_Track_Validation,
	Drv_Obs_Validation,
	Drv_Obs_Comms,
	Drv_Obs_Stop_Comms,
	Drv_Ult_Sd_Comms,
	Drv_Ult_Sd_Missing_Unit,
	Drv_Steer1_Stopped,
	Drv_Steer2_Stopped,
	Drv_Mgt_Comms,
	Drv_V2x,
	Drv_Obs_Danger_Zone_Comms,
	Drv_Deviation,
	Drv_Joystick,
	Drv_EHB_Comms,
	Drv_Obs_Buffering,
	Drv_Graceful_Stopped,
	Drv_Safety_Comms,
	Drv_Rolling_Too_Far,
	Drv_Speed2_Torque_Comms,
	Drv_Location_Jump,
	Drv_Delta_Steer_Req,
	Drv_Off_Track,
	Drv_WP_Distance,
	Drv_Telport_Denied,
	//always add error codes above this
	Drv_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t DrvFusCommsError :1;
			uint64_t DrvFusionQuality2 :1;
			uint64_t DrvFusionQuality1 :1;
			uint64_t HeadingError :1;
			uint64_t DistanceError :1;
			uint64_t DrvSteeringCommsError :1;
			uint64_t DrvSteering2CommsError :1;
			uint64_t DrvMotorCommsError :1;
			uint64_t TrackValidationFailed :1;
			uint64_t ObsValidationFailed :1;
			uint64_t DrvObsCommsError :1;
			uint64_t DrvObsStopCommsError :1;
			uint64_t DrvUltraSoundCommsError :1;
			uint64_t DrvUltraSoundMissingUnit :1;
			uint64_t Steering1Stopped :1;
			uint64_t Steering2Stopped :1;
			uint64_t DrvMgtCommsError :1;
			uint64_t V2xError :1;
			uint64_t DrvObsDangerZoneCommsError :1;
			uint64_t DeviationError :1;
			uint64_t LostJoystick :1;
			uint64_t DrvEHBCommsError :1;
			uint64_t DrvObsBufferingError :1;
			uint64_t DrvGracefulStopped :1;
			uint64_t DrvSafetyCommsError :1;
			uint64_t DrvRollingTooFar :1;
			uint64_t DrvSpeed2TorqueCommsError :1;
			uint64_t DrvLocationJump :1;
			uint64_t DrvDeltaSteerReqError :1;
			uint64_t DrvOffTrack :1;
			uint64_t WPDistanceError :1;
			uint64_t TelportDenied :1;
		} signals;
	} raw;
} ErrorDriveController_t;

// message ID 0x31 DriveWarningMsg
enum DrvWarningMsgErrorCode
{
	Drv_Traffic_Comms = 0,
	Drv_V2x_Warn,
	Drv_Mgt_Comms_Warn,
	Drv_Motor_Off,
	Drv_Net_Comms,
	Drv_No_Steer1_Type,
	Drv_No_Steer2_Type,
	Drv_Mcu_Ver_Incompatible,
	//always add warning codes above this
	Drv_NumWarningCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t DrvTrafficCommsError :1;
			uint64_t DrvV2xWarn :1;
			uint64_t DrvMgtCommsWarn :1;
			uint64_t DrvMotorOff :1;
			uint64_t DrvNetCommsError :1;
			uint64_t DrvNoSteer1Type :1;
			uint64_t DrvNoSteer2Type :1;
			uint64_t DrvMcuVerIncompatible :1;
		} signals;
	} raw;
} DriveWarningMsg_t;

// message ID 0x712 PlatDebugMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t abortReason :8;
		} signals;
	} raw;
} PlatDebugMsg_t;

// message ID 0x713 StopDebugMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t ClosestStop :4;
			uint64_t reserved :4;
			uint64_t trafficEventState :4;
			uint64_t junctionManualEventState :4;
			uint64_t closestDistance2Stop :16;    //mm
			uint64_t trafficDistance2Stop :16;    //mm
			uint64_t junctionManualDistance2Stop :16;    //mm
		} signals;
	} raw;
} StopDebugMsg_t;

// message ID 0x162 MotorReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t leftSpeed :16;    //rad/s
			int64_t rightSpeed :16;    //rad/s
			uint64_t mode :6;
			uint64_t brake :1;
			uint64_t reverse :1;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double leftSpeed;
    double rightSpeed;
} MotorReqMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void MotorReqMsg_ToCan(MotorReqMsg_t * msg) 
{ 
    assert(msg->leftSpeed >= -327.68 && msg->leftSpeed <= 327.67);
    assert(msg->rightSpeed >= -327.68 && msg->rightSpeed <= 327.67);
    assert(msg->raw.signals.mode <= 63);
    assert(msg->raw.signals.brake <= 1);
    assert(msg->raw.signals.reverse <= 1);
    msg->raw.signals.leftSpeed = RoundLimitSigned(msg->leftSpeed, 0.01, 16);
    msg->raw.signals.rightSpeed = RoundLimitSigned(msg->rightSpeed, 0.01, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void MotorReqMsg_FromCan(MotorReqMsg_t * msg) 
{ 
    msg->leftSpeed = msg->raw.signals.leftSpeed * 0.01;
    msg->rightSpeed = msg->raw.signals.rightSpeed * 0.01;
}
// message ID 0x163 frontSteeringReq
// message ID 0x164 rearSteeringReq
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t angle :16;    //degree
			uint64_t speed :8;
			uint64_t counter :8;
			uint64_t mode :1;
			uint64_t reserved :7;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double angle;
} SteeringReqMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringReqMsg_ToCan(SteeringReqMsg_t * msg) 
{ 
    assert(msg->angle >= -45 && msg->angle <= 45);
    assert(msg->raw.signals.speed <= 255);
    assert(msg->raw.signals.counter <= 255);
    assert(msg->raw.signals.mode <= 1);
    msg->raw.signals.angle = RoundLimitSigned(msg->angle, 0.01, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void SteeringReqMsg_FromCan(SteeringReqMsg_t * msg) 
{ 
    msg->angle = msg->raw.signals.angle * 0.01;
}
// message ID 0x165 Speed2TorqueReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t currentSpeed :16;    //mm/s
			int64_t reqSpeed :16;    //mm/s
			int64_t currentTorque :16;    //Nm
			uint64_t startupFlag :8;
			uint64_t motorStopped :1;
			uint64_t motorStarting :1;
		} signals;
	} raw;
    double currentSpeed;
    double reqSpeed;
    double currentTorque;
} Speed2TorqueReqMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Speed2TorqueReqMsg_ToCan(Speed2TorqueReqMsg_t * msg) 
{ 
    msg->raw.signals.currentSpeed = RoundLimitSigned(msg->currentSpeed, 1, 16);
    msg->raw.signals.reqSpeed = RoundLimitSigned(msg->reqSpeed, 1, 16);
    msg->raw.signals.currentTorque = RoundLimitSigned(msg->currentTorque, 1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Speed2TorqueReqMsg_FromCan(Speed2TorqueReqMsg_t * msg) 
{ 
    msg->currentSpeed = msg->raw.signals.currentSpeed * 1.0;
    msg->reqSpeed = msg->raw.signals.reqSpeed * 1.0;
    msg->currentTorque = msg->raw.signals.currentTorque * 1.0;
}
// message ID 0x2B0 EPBReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t request :8;
		} signals;
	} raw;
} EPBReqMsg_t;

// message ID 0x325 DriveInfoLongWpMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t waypoint :16;
			uint64_t maxSpeed :16;    //m/s
			int64_t errorDistance :16;    //m
			uint64_t mode :6;
			uint64_t brake :1;
			uint64_t reverse :1;
			uint64_t path :4;
			uint64_t leftDrive :1;
			uint64_t errorCheck :1;
			uint64_t useLidar :1;
			uint64_t useUltrasound :1;
		} signals;
	} raw;
    double errorDistance;
} DriveInfoLongWpMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void DriveInfoLongWpMsg_ToCan(DriveInfoLongWpMsg_t * msg) 
{ 
    assert(msg->raw.signals.waypoint <= 65535);
    assert(msg->raw.signals.maxSpeed >= 500 && msg->raw.signals.maxSpeed <= 12000);
    assert(msg->raw.signals.mode <= 63);
    assert(msg->raw.signals.brake <= 1);
    assert(msg->raw.signals.reverse <= 1);
    assert(msg->raw.signals.path <= 3);
    assert(msg->raw.signals.leftDrive <= 1);
    assert(msg->raw.signals.errorCheck <= 1);
    assert(msg->raw.signals.useLidar <= 1);
    assert(msg->raw.signals.useUltrasound <= 1);
    msg->raw.signals.errorDistance = RoundLimitSigned(msg->errorDistance, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void DriveInfoLongWpMsg_FromCan(DriveInfoLongWpMsg_t * msg) 
{ 
    msg->errorDistance = msg->raw.signals.errorDistance * 0.001;
}
// message ID 0x328 DriveInfo500kWpMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t waypoint :19;
			uint64_t reserved :5;
			uint64_t maxSpeed :8;    //mm/s
			int64_t errorDistance :16;    //m
			uint64_t mode :6;
			uint64_t brake :1;
			uint64_t reverse :1;
			uint64_t path :4;
			uint64_t leftDrive :1;
			uint64_t errorCheck :1;
			uint64_t useLidar :1;
		} signals;
	} raw;
    double maxSpeed;
    double errorDistance;
} DriveInfo500kWpMsg_t;


void DriveInfo500kWpMsg_ToCan(DriveInfo500kWpMsg_t * msg) ;

void DriveInfo500kWpMsg_FromCan(DriveInfo500kWpMsg_t * msg) ;

// message ID 0x720 DebugMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t ultrasoundDistance :16;    //mm
			uint64_t lidarDistance :16;    //mm
		} signals;
	} raw;
} DebugMsg_t;

// message ID 0x24 ErrorDriveExt
enum DrvExtErrorCode
{
	Drvext_Obs_Validation_Comms = 0,
	Drvext_Motor_No_Resp,
	Drvext_Safety_Relay_Open,
	Drvext_Parameter_Out_Of_Range,
	Drvext_Motor_Over_Temp,
	Drvext_Speed_Deviation,
	Drvext_EPB1_Comms,
	Drvext_EPB2_Comms,
	//always add error codes above this
	Drvext_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t DrvextObsValidationCommsError :1;
			uint64_t DrvextMotorNoResp :1;
			uint64_t DrvextSafetyRelayOpen :1;
			uint64_t DrvextParameterOutOfRange :1;
			uint64_t DrvextMotorOverTemp :1;
			uint64_t DrvextSpeedDeviationError :1;
			uint64_t DrvextEPB1CommsError :1;
			uint64_t DrvextEPB2CommsError :1;
		} signals;
	} raw;
} ErrorDriveExt_t;

// message ID 0x201 DriveRequestsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t driveGPSOff :1;
			uint64_t mgtGPSOff :1;
			uint64_t lidarLocOff :1;
			uint64_t fusionReset :1;
		} signals;
	} raw;
} DriveRequestsMsg_t;

// message ID 0x700 OdometerMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t value :32;    //km
		} signals;
	} raw;
    double value;
} OdometerMsg_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void OdometerMsg_ToCan(OdometerMsg_t * msg) 
{ 
    assert(msg->value >= 0);
    msg->raw.signals.value = RoundLimitUnsigned(msg->value, 0.001, 32);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void OdometerMsg_FromCan(OdometerMsg_t * msg) 
{ 
    msg->value = msg->raw.signals.value * 0.001;
}
// message ID 0x166 Speed2TorqueRespMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t reqTorque :16;    //Nm
		} signals;
	} raw;
    double reqTorque;
} Speed2TorqueRespMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Speed2TorqueRespMsg_ToCan(Speed2TorqueRespMsg_t * msg) 
{ 
    msg->raw.signals.reqTorque = RoundLimitSigned(msg->reqTorque, 1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Speed2TorqueRespMsg_FromCan(Speed2TorqueRespMsg_t * msg) 
{ 
    msg->reqTorque = msg->raw.signals.reqTorque * 1.0;
}
// message ID 0x327 ObsTiedMarginMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t shrinkTime :8;    //sec
			uint64_t left :1;
			uint64_t right :1;
		} signals;
	} raw;
} ObsTiedMarginMsg_t;

// message ID 0x7F4 EmulatorHeadingMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t heading :16;    //degree
		} signals;
	} raw;
    double heading;
} EmulatorHeadingMsg_t;


void EmulatorHeadingMsg_ToCan(EmulatorHeadingMsg_t * msg) ;

void EmulatorHeadingMsg_FromCan(EmulatorHeadingMsg_t * msg) ;

// message ID 0x5A0 ExtObsLocMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			int64_t x :22;    //m
			int64_t y :22;    //m
			uint64_t cleared :1;
		} signals;
	} raw;
    double x;
    double y;
} ExtObsLocMsg_t;


void ExtObsLocMsg_ToCan(ExtObsLocMsg_t * msg) ;

void ExtObsLocMsg_FromCan(ExtObsLocMsg_t * msg) ;

// message ID 0x5A1 ExtObsSpeedMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t speed :8;    //m/s
			uint64_t heading :9;    //degrees
		} signals;
	} raw;
    double speed;
    double heading;
} ExtObsSpeedMsg_t;


void ExtObsSpeedMsg_ToCan(ExtObsSpeedMsg_t * msg) ;

void ExtObsSpeedMsg_FromCan(ExtObsSpeedMsg_t * msg) ;

/* Origin_36_merge obsolete placeholder kept disabled after BK definitions were activated.
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reserved :64;
		} signals;
	} raw;
} ObsoleteMsg_t;
*/

// message ID 0x120 Obsolte_ObsLidarMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t obstacleDistanceLiDAR :16;    //mm
			uint64_t obstacleDistanceLiDARvalid :8;
			uint64_t obstacleDistanceLiDARRegionA :8;    //mm
			uint64_t obstacleDistanceLiDARRegionB :8;    //mm
			uint64_t obstacleDistanceLiDARtimestamp :24;    //ms
		} signals;
	} raw;
    double obstacleDistanceLiDAR;
    double obstacleDistanceLiDARRegionA;
    double obstacleDistanceLiDARRegionB;
} ObstacleDetectionLiDARMsg_t;

static void ObstacleDetectionLiDARMsg_ToCan(ObstacleDetectionLiDARMsg_t * msg) 
{ 
    assert(msg->obstacleDistanceLiDAR >= 0);
    msg->raw.signals.obstacleDistanceLiDAR = RoundLimitUnsigned(msg->obstacleDistanceLiDAR, 40, 16);
    assert(msg->obstacleDistanceLiDARRegionA >= 0);
    msg->raw.signals.obstacleDistanceLiDARRegionA = RoundLimitUnsigned(msg->obstacleDistanceLiDARRegionA, 200, 8);
    assert(msg->obstacleDistanceLiDARRegionB >= 0);
    msg->raw.signals.obstacleDistanceLiDARRegionB = RoundLimitUnsigned(msg->obstacleDistanceLiDARRegionB, 200, 8);
}

static void ObstacleDetectionLiDARMsg_FromCan(ObstacleDetectionLiDARMsg_t * msg) 
{ 
    msg->obstacleDistanceLiDAR = msg->raw.signals.obstacleDistanceLiDAR * 40 * 1.0;
    msg->obstacleDistanceLiDARRegionA = msg->raw.signals.obstacleDistanceLiDARRegionA * 200 * 1.0;
    msg->obstacleDistanceLiDARRegionB = msg->raw.signals.obstacleDistanceLiDARRegionB * 200 * 1.0;
}

// message ID 0x121 Obsolete_UltraSoundMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t frontDoor :8;    //mm
			uint64_t frontCentre :8;    //mm
			uint64_t frontWindow :8;    //mm
			uint64_t rearDoor :8;    //mm
			uint64_t rearCentre :8;    //mm
			uint64_t rearWindow :8;    //mm
		} signals;
	} raw;
    double frontDoor;
    double frontCentre;
    double frontWindow;
    double rearDoor;
    double rearCentre;
    double rearWindow;
} UltraSoundMsg_t;

static void UltraSoundMsg_ToCan(UltraSoundMsg_t * msg) 
{ 
    assert(msg->frontDoor <= 5100);
    assert(msg->frontCentre <= 5100);
    assert(msg->frontWindow <= 5100);
    assert(msg->rearDoor <= 5100);
    assert(msg->rearCentre <= 5100);
    assert(msg->rearWindow <= 5100);
    assert(msg->frontDoor >= 0);
    msg->raw.signals.frontDoor = RoundLimitUnsigned(msg->frontDoor, 20, 8);
    assert(msg->frontCentre >= 0);
    msg->raw.signals.frontCentre = RoundLimitUnsigned(msg->frontCentre, 20, 8);
    assert(msg->frontWindow >= 0);
    msg->raw.signals.frontWindow = RoundLimitUnsigned(msg->frontWindow, 20, 8);
    assert(msg->rearDoor >= 0);
    msg->raw.signals.rearDoor = RoundLimitUnsigned(msg->rearDoor, 20, 8);
    assert(msg->rearCentre >= 0);
    msg->raw.signals.rearCentre = RoundLimitUnsigned(msg->rearCentre, 20, 8);
    assert(msg->rearWindow >= 0);
    msg->raw.signals.rearWindow = RoundLimitUnsigned(msg->rearWindow, 20, 8);
}

static void UltraSoundMsg_FromCan(UltraSoundMsg_t * msg) 
{ 
    msg->frontDoor = msg->raw.signals.frontDoor * 20 * 1.0;
    msg->frontCentre = msg->raw.signals.frontCentre * 20 * 1.0;
    msg->frontWindow = msg->raw.signals.frontWindow * 20 * 1.0;
    msg->rearDoor = msg->raw.signals.rearDoor * 20 * 1.0;
    msg->rearCentre = msg->raw.signals.rearCentre * 20 * 1.0;
    msg->rearWindow = msg->raw.signals.rearWindow * 20 * 1.0;
}

// message ID 0x160 Obsolete_BrakeReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t obsoleted :64;
		} signals;
	} raw;
} BrakeReqMsg_t;

// message ID 0x220 Obsolete_latitudeFrontMsg
// message ID 0x230 Obsolete_latitudeBackMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t latitude :35;
			uint64_t sign :1;    //one's compl. sign
			uint64_t quality :4;    //enum
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double latitude;
} GPSLatitudeMsg_t;

static void GPSLatitudeMsg_ToCan(GPSLatitudeMsg_t * msg) 
{ 
    assert(msg->latitude >= -90 && msg->latitude <= 90);
    assert(msg->raw.signals.quality <= 7);
    msg->raw.signals.latitude = RoundLimitUnsigned(fabs(msg->latitude), 0.00000001, 35);
    msg->raw.signals.sign = (msg->latitude < 0);
}

static void GPSLatitudeMsg_FromCan(GPSLatitudeMsg_t * msg) 
{ 
    if (msg->raw.signals.sign)
       msg->latitude = -(msg->raw.signals.latitude * 0.00000001);
    else
       msg->latitude = msg->raw.signals.latitude * 0.00000001;
}

// message ID 0x222 Obsolete_heightFrontMsg
// message ID 0x232 Obsolete_heightBackMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t altitude :16;    //m
			uint64_t differenceBetweenWGS84andSealevel :16;    //m
			uint64_t noOfSatellites :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double altitude;
    double differenceBetweenWGS84andSealevel;
} HeightMsg_t;

static void HeightMsg_ToCan(HeightMsg_t * msg) 
{ 
    assert(msg->altitude <= 655);
    assert(msg->differenceBetweenWGS84andSealevel <= 655);
    assert(msg->altitude >= 0);
    msg->raw.signals.altitude = RoundLimitUnsigned(msg->altitude, 0.01, 16);
    assert(msg->differenceBetweenWGS84andSealevel >= 0);
    msg->raw.signals.differenceBetweenWGS84andSealevel = RoundLimitUnsigned(msg->differenceBetweenWGS84andSealevel, 0.01, 16);
}

static void HeightMsg_FromCan(HeightMsg_t * msg) 
{ 
    msg->altitude = msg->raw.signals.altitude * 0.01;
    msg->differenceBetweenWGS84andSealevel = msg->raw.signals.differenceBetweenWGS84andSealevel * 0.01;
}

// message ID 0x223 Obsolete_combineHeightFrontMsg
// message ID 0x234 Obsolete_combineHeightBackMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t altitude :32;    //m
			uint64_t noOfSatellites :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double altitude;
} CombinedHeightMsg_t;

static void CombinedHeightMsg_ToCan(CombinedHeightMsg_t * msg) 
{ 
    assert(msg->altitude >= -500 && msg->altitude <= 5000);
    msg->raw.signals.altitude = RoundLimitSigned(msg->altitude, 0.01, 32);
}

static void CombinedHeightMsg_FromCan(CombinedHeightMsg_t * msg) 
{ 
    msg->altitude = msg->raw.signals.altitude * 0.01;
}

// message ID 0x233 Obsolete_HeadingMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t heading :16;    //degree
		} signals;
	} raw;
    double heading;
} HeadingMsg_t;

static void HeadingMsg_ToCan(HeadingMsg_t * msg) 
{ 
    assert(msg->heading <= 360);
    assert(msg->heading >= 0);
    msg->raw.signals.heading = RoundLimitUnsigned(msg->heading, 0.1, 16);
}

static void HeadingMsg_FromCan(HeadingMsg_t * msg) 
{ 
    msg->heading = msg->raw.signals.heading * 0.1;
}

// message ID 0x260 Obsolete_CompassMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t heading :16;    //degree
			uint64_t reserved :24;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double heading;
} CompassMsg_t;

static void CompassMsg_ToCan(CompassMsg_t * msg) 
{ 
    assert(msg->heading <= 360);
    assert(msg->heading >= 0);
    msg->raw.signals.heading = RoundLimitUnsigned(msg->heading, 0.1, 16);
}

static void CompassMsg_FromCan(CompassMsg_t * msg) 
{ 
    msg->heading = msg->raw.signals.heading * 0.1;
}

// message ID 0x250 Obsolete_UWBDistanceMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :7;
			uint64_t rearUnit :1;
			uint64_t reserved :12;
			uint64_t distance :20;    //mm
			uint64_t time :24;    //ms
		} signals;
	} raw;
} UWBDistanceMsg_t;

// message ID 0x251 Obsolete_UWBLatitudeMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :20;
			int64_t latitude :36;    //DD
		} signals;
	} raw;
    double latitude;
} UWBLatitudeMsg_t;

static void UWBLatitudeMsg_ToCan(UWBLatitudeMsg_t * msg) 
{ 
    assert(msg->raw.signals.id <= 1048575);
    assert(msg->latitude >= -90 && msg->latitude <= 90);
    msg->raw.signals.latitude = RoundLimitSigned(msg->latitude, 0.00000001, 36);
}

static void UWBLatitudeMsg_FromCan(UWBLatitudeMsg_t * msg) 
{ 
    msg->latitude = msg->raw.signals.latitude * 0.00000001;
}

// message ID 0x252 Obsolete_UWBLongitudeMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :20;
			int64_t longitude :36;    //DD
		} signals;
	} raw;
    double longitude;
} UWBLongitudeMsg_t;

static void UWBLongitudeMsg_ToCan(UWBLongitudeMsg_t * msg) 
{ 
    assert(msg->raw.signals.id <= 1048575);
    assert(msg->longitude >= -180 && msg->longitude <= 180);
    msg->raw.signals.longitude = RoundLimitSigned(msg->longitude, 0.00000001, 36);
}

static void UWBLongitudeMsg_FromCan(UWBLongitudeMsg_t * msg) 
{ 
    msg->longitude = msg->raw.signals.longitude * 0.00000001;
}

// message ID 0x321 Obsolete_DriveInfoMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t waypoint :12;
			uint64_t path :4;
			uint64_t maxSpeed :16;    //m/s
			uint64_t errorDistance :16;    //m
			uint64_t mode :6;
			uint64_t brake :1;
			uint64_t reverse :1;
			uint64_t reserved :4;
			uint64_t cord :1;
			uint64_t errorCheck :1;
			uint64_t useLidar :1;
			uint64_t useUltrasound :1;
		} signals;
	} raw;
    double errorDistance;
} DriveInfoMsg_t;

static void DriveInfoMsg_ToCan(DriveInfoMsg_t * msg) 
{ 
    assert(msg->raw.signals.waypoint <= 4095);
    assert(msg->raw.signals.path <= 3);
    assert(msg->raw.signals.maxSpeed >= 500 && msg->raw.signals.maxSpeed <= 12000);
    assert(msg->errorDistance <= 65.535);
    assert(msg->raw.signals.mode <= 63);
    assert(msg->raw.signals.brake <= 1);
    assert(msg->raw.signals.reverse <= 1);
    assert(msg->raw.signals.cord <= 1);
    assert(msg->raw.signals.errorCheck <= 1);
    assert(msg->raw.signals.useLidar <= 1);
    assert(msg->raw.signals.useUltrasound <= 1);
    assert(msg->errorDistance >= 0);
    msg->raw.signals.errorDistance = RoundLimitUnsigned(msg->errorDistance, 0.001, 16);
}

static void DriveInfoMsg_FromCan(DriveInfoMsg_t * msg) 
{ 
    msg->errorDistance = msg->raw.signals.errorDistance * 0.001;
}

// message ID 0x710 Obsolete_LogIndMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t logObsoleted :1;
		} signals;
	} raw;
} LogIndMsg_t;

// message ID 0x20 ObstacleEmergency
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t stop :8;
			uint64_t minDistance :8;    //m
			uint64_t maxDistance :8;    //m
			uint64_t overtake :1;
			uint64_t movingAway :1;    //bool
			uint64_t obsErrorStop :1;    //bool
			uint64_t reserved :5;
			uint64_t envelopDistance :8;    //m
		} signals;
	} raw;
    double envelopDistance;
} ObstacleEmergency_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleEmergency_ToCan(ObstacleEmergency_t * msg) 
{ 
    assert(msg->raw.signals.movingAway <= 1);
    assert(msg->envelopDistance <= 32);
    assert(msg->envelopDistance >= 0);
    msg->raw.signals.envelopDistance = RoundLimitUnsigned(msg->envelopDistance, 0.125, 8);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleEmergency_FromCan(ObstacleEmergency_t * msg) 
{ 
    msg->envelopDistance = msg->raw.signals.envelopDistance * 0.125;
}
// message ID 0x122 ObstacleDangerZoneMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t distance :13;    //mm
			uint64_t timeToCollision :8;    //sec
			uint64_t notMoving :1;    //bool
			uint64_t movingSideways :1;    //bool
			uint64_t reserved :17;
			uint64_t timeStamp :24;
		} signals;
	} raw;
    double distance;
    double timeToCollision;
} ObstacleDangerZoneMsg_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleDangerZoneMsg_ToCan(ObstacleDangerZoneMsg_t * msg) 
{ 
    assert(msg->distance >= 0);
    msg->raw.signals.distance = RoundLimitUnsigned(msg->distance, 100, 13);
    assert(msg->timeToCollision >= 0);
    msg->raw.signals.timeToCollision = RoundLimitUnsigned(msg->timeToCollision, 0.1, 8);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleDangerZoneMsg_FromCan(ObstacleDangerZoneMsg_t * msg) 
{ 
    msg->distance = msg->raw.signals.distance * 100 * 1.0;
    msg->timeToCollision = msg->raw.signals.timeToCollision * 0.1;
}
// message ID 0x123 ObstacleTrackDistanceMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t trackDistance :13;    //mm
			uint64_t sideDistanceA :13;    //mm
			uint64_t sideDistanceB :13;    //mm
			uint64_t moveAwayFlag :1;
			uint64_t incSpeedFlag :1;
			uint64_t ignoredObstacle :1;    //bool
			uint64_t ClearOnRight :1;    //bool
			uint64_t ClearOnLeft :1;    //bool
			uint64_t reserved :15;
			uint64_t BackDistance :5;    //mm
		} signals;
	} raw;
    double trackDistance;
    double sideDistanceA;
    double sideDistanceB;
    double BackDistance;
} ObstacleTrackDistanceMsg_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleTrackDistanceMsg_ToCan(ObstacleTrackDistanceMsg_t * msg) 
{ 
    assert(msg->trackDistance >= 0);
    msg->raw.signals.trackDistance = RoundLimitUnsigned(msg->trackDistance, 100, 13);
    assert(msg->sideDistanceA >= 0);
    msg->raw.signals.sideDistanceA = RoundLimitUnsigned(msg->sideDistanceA, 100, 13);
    assert(msg->sideDistanceB >= 0);
    msg->raw.signals.sideDistanceB = RoundLimitUnsigned(msg->sideDistanceB, 100, 13);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void ObstacleTrackDistanceMsg_FromCan(ObstacleTrackDistanceMsg_t * msg) 
{ 
    msg->trackDistance = msg->raw.signals.trackDistance * 100 * 1.0;
    msg->sideDistanceA = msg->raw.signals.sideDistanceA * 100 * 1.0;
    msg->sideDistanceB = msg->raw.signals.sideDistanceB * 100 * 1.0;
}
// message ID 0x124 ObstacleDangerZoneStopMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t distance :13;    //mm
			uint64_t timeToCollision :8;    //sec
			uint64_t notMoving :1;    //bool
			uint64_t movingSideways :1;    //bool
			uint64_t occluded :1;    //bool
			uint64_t tolerance :8;    //mm
		} signals;
	} raw;
    double distance;
    double timeToCollision;
    double tolerance;
} ObstacleDangerZoneStopMsg_t;


void ObstacleDangerZoneStopMsg_ToCan(ObstacleDangerZoneStopMsg_t * msg) ;

void ObstacleDangerZoneStopMsg_FromCan(ObstacleDangerZoneStopMsg_t * msg) ;

// message ID 0x17 ErrorObstaclePC
enum ObstaclePCErrorCode
{
	Obstacle_front_left_lidar_fault = 0,
	Obstacle_front_top_lidar_fault,
	Obstacle_front_right_lidar_fault,
	Obstacle_rear_left_lidar_fault,
	Obstacle_rear_top_lidar_fault,
	Obstacle_rear_right_lidar_fault,
	Obstacle_CAN_localisation_msg,
	Obstacle_transform_broadcaster,
	Obstacle_CAN_wheel_speed_msg,
	Obstacle_CAN_front_steering_msg,
	Obstacle_CAN_back_steering_msg,
	Obstacle_ground_segmentation_msg,
	Obstacle_map_msg,
	Obstacle_path_planning_msg,
	Obstacle_collision_distance_msg,
	Obstacle_emergency_envelope_msg,
	Obstacle_lidar_calibration_msg,
	Obstacle_multiple_lidar_fault,
	Obstacle_map_source_missing,
	Obstacle_map_multiple_missing,
	Obstacle_dangerous_parameter,
	Obstacle_Heartbeat_detection,
	Obstacle_wp_mismatch,
	Obstacle_track_mismatch,
	Obstacle_drv_info_comms,
	//always add error codes above this
	Obstacle_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t Obstacle_front_left_lidar_fault :1;
			uint64_t Obstacle_front_top_lidar_fault :1;
			uint64_t Obstacle_front_right_lidar_fault :1;
			uint64_t Obstacle_rear_left_lidar_fault :1;
			uint64_t Obstacle_rear_top_lidar_fault :1;
			uint64_t Obstacle_rear_right_lidar_fault :1;
			uint64_t Obstacle_CAN_localisation_msg_error :1;
			uint64_t Obstacle_transform_broadcaster_error :1;
			uint64_t Obstacle_CAN_wheel_speed_msg_error :1;
			uint64_t Obstacle_CAN_front_steering_msg_error :1;
			uint64_t Obstacle_CAN_back_steering_msg_error :1;
			uint64_t Obstacle_ground_segmentation_msg_error :1;
			uint64_t Obstacle_map_msg_error :1;
			uint64_t Obstacle_path_planning_msg_error :1;
			uint64_t Obstacle_collision_distance_msg_error :1;
			uint64_t Obstacle_emergency_envelope_msg_error :1;
			uint64_t Obstacle_lidar_calibration_msg_error :1;
			uint64_t Obstacle_multiple_lidar_fault :1;
			uint64_t Obstacle_map_source_missing :1;
			uint64_t Obstacle_map_multiple_missing :1;
			uint64_t Obstacle_dangerous_parameter :1;
			uint64_t Obstacle_Heartbeat_detection_error :1;
			uint64_t Obstacle_wp_mismatch :1;
			uint64_t Obstacle_track_mismatch :1;
			uint64_t Obstacle_drv_info_comms_error :1;
		} signals;
	} raw;
} ErrorObstaclePC_t;

// message ID 0x240 LidarSpeed
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t SpeedForward :8;    //metres/s
			int64_t SpeedLeft :8;    //metres/s
			int64_t AngularSpeedLeft :8;    //degrees/s
			uint64_t SpeedForwardStdDev :8;    //m/s
			uint64_t SpeedLeftStdDev :8;    //m/s
			uint64_t AngularSpeedLeftStdDev :8;    //degrees/s
			uint64_t MeanSquaredError :8;    //metres
			uint64_t SpeedsInvalid :1;
			uint64_t delay :5;    //mSec
		} signals;
	} raw;
    double SpeedForward;
    double SpeedLeft;
    double AngularSpeedLeft;
    double SpeedForwardStdDev;
    double SpeedLeftStdDev;
    double AngularSpeedLeftStdDev;
    double MeanSquaredError;
    double delay;
} LidarSpeed_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void LidarSpeed_ToCan(LidarSpeed_t * msg) 
{ 
    assert(msg->SpeedForward >= -7.7 && msg->SpeedForward <= 17.8);
    assert(msg->SpeedLeft >= -12.7 && msg->SpeedLeft <= 12.8);
    assert(msg->AngularSpeedLeft >= -127 && msg->AngularSpeedLeft <= 128);
    assert(msg->SpeedForwardStdDev <= 2.55);
    assert(msg->SpeedLeftStdDev <= 2.55);
    assert(msg->AngularSpeedLeftStdDev <= 10.2);
    assert(msg->MeanSquaredError <= 25.5);
    msg->raw.signals.SpeedForward = RoundLimitSigned(msg->SpeedForward - 5, 0.1, 8);
    msg->raw.signals.SpeedLeft = RoundLimitSigned(msg->SpeedLeft, 0.1, 8);
    msg->raw.signals.AngularSpeedLeft = RoundLimitSigned(msg->AngularSpeedLeft, 1, 8);
    assert(msg->SpeedForwardStdDev >= 0);
    msg->raw.signals.SpeedForwardStdDev = RoundLimitUnsigned(msg->SpeedForwardStdDev, 0.01, 8);
    assert(msg->SpeedLeftStdDev >= 0);
    msg->raw.signals.SpeedLeftStdDev = RoundLimitUnsigned(msg->SpeedLeftStdDev, 0.01, 8);
    assert(msg->AngularSpeedLeftStdDev >= 0);
    msg->raw.signals.AngularSpeedLeftStdDev = RoundLimitUnsigned(msg->AngularSpeedLeftStdDev, 0.04, 8);
    assert(msg->MeanSquaredError >= 0);
    msg->raw.signals.MeanSquaredError = RoundLimitUnsigned(msg->MeanSquaredError, 0.1, 8);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void LidarSpeed_FromCan(LidarSpeed_t * msg) 
{ 
    msg->SpeedForward = msg->raw.signals.SpeedForward * 0.1 + 5;
    msg->SpeedLeft = msg->raw.signals.SpeedLeft * 0.1;
    msg->AngularSpeedLeft = msg->raw.signals.AngularSpeedLeft * 1.0;
    msg->SpeedForwardStdDev = msg->raw.signals.SpeedForwardStdDev * 0.01;
    msg->SpeedLeftStdDev = msg->raw.signals.SpeedLeftStdDev * 0.01;
    msg->AngularSpeedLeftStdDev = msg->raw.signals.AngularSpeedLeftStdDev * 0.04;
    msg->MeanSquaredError = msg->raw.signals.MeanSquaredError * 0.1;
}
// message ID 0x241 LidarLatitude
// message ID 0x245 CameraLatitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Latitude :36;    //degrees
			uint64_t ForwardStdDev :8;    //meters
			uint64_t LatUnavailable :1;
			uint64_t ForwardInfStdDev :1;
			uint64_t Delay :8;    //mSec
			uint64_t Reserved :8;
			uint64_t sync :2;
		} signals;
	} raw;
    double Latitude;
    double ForwardStdDev;
    double Delay;
} ObsLatitudeMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsLatitudeMsg_ToCan(ObsLatitudeMsg_t * msg) 
{ 
    assert(msg->Latitude >= -90 && msg->Latitude <= 90);
    assert(msg->ForwardStdDev <= 1);
    assert(msg->raw.signals.ForwardInfStdDev <= 1);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.Latitude = RoundLimitSigned(msg->Latitude, 0.00000001, 36);
    assert(msg->ForwardStdDev >= 0);
    msg->raw.signals.ForwardStdDev = RoundLimitUnsigned(msg->ForwardStdDev, 0.004, 8);
    assert(msg->Delay >= 0);
    msg->raw.signals.Delay = RoundLimitUnsigned(msg->Delay, 10, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsLatitudeMsg_FromCan(ObsLatitudeMsg_t * msg) 
{ 
    msg->Latitude = msg->raw.signals.Latitude * 0.00000001;
    msg->ForwardStdDev = msg->raw.signals.ForwardStdDev * 0.004;
    msg->Delay = msg->raw.signals.Delay * 10 * 1.0;
}
// message ID 0x242 LidarLongitude
// message ID 0x246 CameraLongitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Longitude :36;    //degrees
			uint64_t LateralStdDev :8;    //meters
			uint64_t LongUnavailable :1;
			uint64_t LateralInfStdDev :1;
			uint64_t Reserved :16;
			uint64_t sync :2;
		} signals;
	} raw;
    double Longitude;
    double LateralStdDev;
} ObsLongitudeMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsLongitudeMsg_ToCan(ObsLongitudeMsg_t * msg) 
{ 
    assert(msg->Longitude >= -180 && msg->Longitude <= 180);
    assert(msg->LateralStdDev <= 1);
    assert(msg->raw.signals.LateralInfStdDev <= 1);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.Longitude = RoundLimitSigned(msg->Longitude, 0.00000001, 36);
    assert(msg->LateralStdDev >= 0);
    msg->raw.signals.LateralStdDev = RoundLimitUnsigned(msg->LateralStdDev, 0.004, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsLongitudeMsg_FromCan(ObsLongitudeMsg_t * msg) 
{ 
    msg->Longitude = msg->raw.signals.Longitude * 0.00000001;
    msg->LateralStdDev = msg->raw.signals.LateralStdDev * 0.004;
}
// message ID 0x243 LidarHeading
// message ID 0x247 CameraHeading
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t CompassHeading :16;    //degrees
			uint64_t HeadingStdDev :8;    //degrees
			uint64_t MeanSquaredError :8;    //metres
			uint64_t HeadingUnavailable :1;
			uint64_t HeadingInfStdDev :1;
			uint64_t reserved :6;
			uint64_t timeStamp :16;    //ms
			uint64_t reserved1 :3;
			uint64_t msgVersion :3;
			uint64_t sync :2;
		} signals;
	} raw;
    double CompassHeading;
    double HeadingStdDev;
    double MeanSquaredError;
} ObsHeadingMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsHeadingMsg_ToCan(ObsHeadingMsg_t * msg) 
{ 
    assert(msg->CompassHeading <= 360);
    assert(msg->HeadingStdDev <= 10);
    assert(msg->MeanSquaredError <= 25.5);
    assert(msg->raw.signals.HeadingInfStdDev <= 1);
    assert(msg->raw.signals.sync <= 3);
    assert(msg->CompassHeading >= 0);
    msg->raw.signals.CompassHeading = RoundLimitUnsigned(msg->CompassHeading, 0.1, 16);
    assert(msg->HeadingStdDev >= 0);
    msg->raw.signals.HeadingStdDev = RoundLimitUnsigned(msg->HeadingStdDev, 0.04, 8);
    assert(msg->MeanSquaredError >= 0);
    msg->raw.signals.MeanSquaredError = RoundLimitUnsigned(msg->MeanSquaredError, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsHeadingMsg_FromCan(ObsHeadingMsg_t * msg) 
{ 
    msg->CompassHeading = msg->raw.signals.CompassHeading * 0.1;
    msg->HeadingStdDev = msg->raw.signals.HeadingStdDev * 0.04;
    msg->MeanSquaredError = msg->raw.signals.MeanSquaredError * 0.1;
}
// message ID 0x270 LidarOffset
// message ID 0x271 CameraOffset
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t literalDiff :14;    //m
			uint64_t reserved :1;
			uint64_t literalValid :1;
			int64_t headingDiff :14;    //degrees
			uint64_t headingValid :1;
		} signals;
	} raw;
    double literalDiff;
    double headingDiff;
} ObsTrackOffsetMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsTrackOffsetMsg_ToCan(ObsTrackOffsetMsg_t * msg) 
{ 
    assert(msg->literalDiff >= -4 && msg->literalDiff <= 4);
    assert(msg->raw.signals.literalValid <= 1);
    assert(msg->headingDiff >= -20 && msg->headingDiff <= 20);
    assert(msg->raw.signals.headingValid <= 1);
    msg->raw.signals.literalDiff = RoundLimitSigned(msg->literalDiff, 0.001, 14);
    msg->raw.signals.headingDiff = RoundLimitSigned(msg->headingDiff, 0.1, 14);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ObsTrackOffsetMsg_FromCan(ObsTrackOffsetMsg_t * msg) 
{ 
    msg->literalDiff = msg->raw.signals.literalDiff * 0.001;
    msg->headingDiff = msg->raw.signals.headingDiff * 0.1;
}
// message ID 0x210 FusionLatitudeFrontMsg
// message ID 0x213 FusionLatitudeRearMsg
// message ID 0x7F2 EmulatorLatitudeMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t latitude :35;
			uint64_t sign :1;    //one's compl. sign
			uint64_t outlier :1;
			uint64_t reserved :3;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double latitude;
} LatitudeMsg_t;

/* 2-4 rerun: FusionLatitudeMsg functions are applied to the existing
 * LatitudeMsg_t mapping because the signal layout matches.
 */
static void LatitudeMsg_ToCan(LatitudeMsg_t * msg) 
{ 
    assert(msg->latitude >= -90 && msg->latitude <= 90);
    assert(msg->raw.signals.outlier <= 1);
    msg->raw.signals.latitude = RoundLimitUnsigned(fabs(msg->latitude), 0.00000001, 35);
    msg->raw.signals.sign = (msg->latitude < 0);
}

static void LatitudeMsg_FromCan(LatitudeMsg_t * msg) 
{ 
    if (msg->raw.signals.sign)
       msg->latitude = -(msg->raw.signals.latitude * 0.00000001);
    else
       msg->latitude = msg->raw.signals.latitude * 0.00000001;
}

// message ID 0x211 FusionLongitudeFront
// message ID 0x214 FusionLongitudeRear
// message ID 0x221 Obsolete_longitudeFrontMsg
// message ID 0x231 Obsolete_longitudeBackMsg
// message ID 0x7F3 EmulatorLongitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t longitude :35;
			uint64_t sign :1;    //one's compl. sign
			uint64_t quality :4;    //enum
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double longitude;
} LongitudeMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LongitudeMsg_ToCan(LongitudeMsg_t * msg) 
{ 
    assert(msg->longitude >= -180 && msg->longitude <= 180);
    assert(msg->raw.signals.quality <= 7);
    msg->raw.signals.longitude = RoundLimitUnsigned(fabs(msg->longitude), 0.00000001, 35);
    msg->raw.signals.sign = (msg->longitude < 0);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LongitudeMsg_FromCan(LongitudeMsg_t * msg) 
{ 
    if (msg->raw.signals.sign)
       msg->longitude = -(msg->raw.signals.longitude * 0.00000001);
    else
       msg->longitude = msg->raw.signals.longitude * 0.00000001;
}
// message ID 0x212 FusionInfoMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t heading :16;    //degree
			uint64_t forwardConfidence :16;    //m
			uint64_t lateralConfidence :16;    //m
			uint64_t headConfidence :16;    //m
		} signals;
	} raw;
    double heading;
    double forwardConfidence;
    double lateralConfidence;
    double headConfidence;
} FusionInfoMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionInfoMsg_ToCan(FusionInfoMsg_t * msg) 
{ 
    assert(msg->heading <= 360);
    msg->raw.signals.heading = RoundLimitSigned(msg->heading, 0.1, 16);
    assert(msg->forwardConfidence >= 0);
    msg->raw.signals.forwardConfidence = RoundLimitUnsigned(msg->forwardConfidence, 0.001, 16);
    assert(msg->lateralConfidence >= 0);
    msg->raw.signals.lateralConfidence = RoundLimitUnsigned(msg->lateralConfidence, 0.001, 16);
    assert(msg->headConfidence >= 0);
    msg->raw.signals.headConfidence = RoundLimitUnsigned(msg->headConfidence, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionInfoMsg_FromCan(FusionInfoMsg_t * msg) 
{ 
    msg->heading = msg->raw.signals.heading * 0.1;
    msg->forwardConfidence = msg->raw.signals.forwardConfidence * 0.001;
    msg->lateralConfidence = msg->raw.signals.lateralConfidence * 0.001;
    msg->headConfidence = msg->raw.signals.headConfidence * 0.001;
}
// message ID 0x2C0 FusionAcceMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t longAcce :16;    //m/s2
			int64_t latAcce :16;    //m/s2
			uint64_t reserved :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double longAcce;
    double latAcce;
} FusionAcceMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionAcceMsg_ToCan(FusionAcceMsg_t * msg) 
{ 
    assert(msg->longAcce >= -20 && msg->longAcce <= 20);
    assert(msg->latAcce >= -20 && msg->latAcce <= 20);
    msg->raw.signals.longAcce = RoundLimitSigned(msg->longAcce, 0.01, 16);
    msg->raw.signals.latAcce = RoundLimitSigned(msg->latAcce, 0.01, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionAcceMsg_FromCan(FusionAcceMsg_t * msg) 
{ 
    msg->longAcce = msg->raw.signals.longAcce * 0.01;
    msg->latAcce = msg->raw.signals.latAcce * 0.01;
}
// message ID 0x15 ErrorFusion
enum FusionErrorCode
{
	Fusion_Reset = 0,
	Fusion_Init,
	Fusion_Speed_Def,
	Fusion_Steer_Angle1_Invalid,
	Fusion_Steer_Angle2_Invalid,
	Fusion_UWB1_Invalid,
	Fusion_fusion_Centre_UWB_Invalid,
	Fusion_UWB2_Invalid,
	Fusion_Speed_Input_Invalid,
	Fusion_Time_Step_Size_Invalid,
	Fusion_Beacon_Loc_Not_Defined,
	Fusion_Loc_Comms,
	Fusion_Steer1_Comms,
	Fusion_Steer2_Comms,
	Fusion_Motor1_Comms,
	Fusion_Motor2_Comms,
	Fusion_Odom_Null,
	Fusion_Incompatible_Version,
	Fusion_Front_Wheel_Speed_Comms,
	Fusion_Rear_Wheel_Speed_Comms,
	Fusion_Drv_Req_Comms,
	Fusion_Conflicting_Inputs,
	Fusion_Saved_Antenna_Offset_Missing,
	Fusion_Safety_Relay_Open,
	Fusion_Huge_Sensor_Update,
	Fusion_Drv_Info_Comms,
	//always add error codes above this
	Fusion_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t FusionResetError :1;
			uint64_t FusionInitFailed :1;
			uint64_t FusionSpeedDefError :1;
			uint64_t FusionSteerAngle1Invalid :1;
			uint64_t FusionSteeringAngle2Invalid :1;
			uint64_t FusionUWB1Invalid :1;
			uint64_t fusionCentreUWBInvalid :1;
			uint64_t FusionUWB2Invalid :1;
			uint64_t FusionSpeedInputInvalid :1;
			uint64_t FusionTimeStepSizeInvalid :1;
			uint64_t FusionBeaconLocNotDefined :1;
			uint64_t FusionLocCommsError :1;
			uint64_t FusionSteering1CommsError :1;
			uint64_t FusionSteering2CommsError :1;
			uint64_t FusionMotor1CommsError :1;
			uint64_t FusionMotor2CommsError :1;
			uint64_t FusionOdomNull :1;
			uint64_t FusionIncompatibleVersion :1;
			uint64_t FusionFrontWheelSpeedCommsError :1;
			uint64_t FusionRearWheelSpeedCommsError :1;
			uint64_t FusionDrvReqCommsError :1;
			uint64_t FusionConflictingInputsError :1;
			uint64_t FusionSavedAntennaOffsetMissing :1;
			uint64_t FusionSafetyRelayOpen :1;
			uint64_t FusionHugeSensorUpdate :1;
			uint64_t FusionDrvInfoCommsError :1;
		} signals;
	} raw;
} ErrorFusion_t;

// message ID 0x25 FusError
enum FusErrorCode
{
	fus_internal_reset = 0,
	fus_init_failed,
	fus_front_steer_invalid,
	fus_rear_steer_invalid,
	fus_speed_invalid,
	fus_time_step_size_invalid,
	fus_lidar_slam_stddev_nonpositive,
	fus_cam_slam_stddev_nonpositive,
	fus_motor_comms,
	fus_front_steer_comms,
	fus_rear_steer_comms,
	fus_veh_cholesky_failed,
	fus_veh_innovation_cov_not_psd,
	fus_veh_nonpositive_variance,
	fus_veh_nan_or_inf,
	fus_odo_cholesky_failed,
	fus_odo_innovation_cov_not_psd,
	fus_odo_nonpositive_variance,
	fus_odo_nan_or_inf,
	fus_drv_req_comms,
	fus_front_wheel_speed_comms,
	fus_rear_wheel_speed_comms,
	fus_conflicting_inputs, // OhmioLibraries label: fus_Reserved.
	fus_saved_antenna_offset_missing,
	fus_huge_sensor_update,
	fus_safety_relay_open,
	fus_drv_info_comms,
	//always add error codes above this
	fus_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t fus_internal_reset :1;
			uint64_t fus_init_failed :1;
			uint64_t fus_front_steer_invalid :1;
			uint64_t fus_rear_steer_invalid :1;
			uint64_t fus_speed_invalid :1;
			uint64_t fus_time_step_size_invalid :1;
			uint64_t fus_lidar_slam_stddev_nonpositive :1;
			uint64_t fus_cam_slam_stddev_nonpositive :1;
			uint64_t fus_motor_comms :1;
			uint64_t fus_front_steer_comms :1;
			uint64_t fus_rear_steer_comms :1;
			uint64_t fus_veh_cholesky_failed :1;
			uint64_t fus_veh_innovation_cov_not_psd :1;
			uint64_t fus_veh_nonpositive_variance :1;
			uint64_t fus_veh_nan_or_inf :1;
			uint64_t fus_odo_cholesky_failed :1;
			uint64_t fus_odo_innovation_cov_not_psd :1;
			uint64_t fus_odo_nonpositive_variance :1;
			uint64_t fus_odo_nan_or_inf :1;
			uint64_t fus_drv_req_comms :1;
			uint64_t fus_front_wheel_speed_comms :1;
			uint64_t fus_rear_wheel_speed_comms :1;
			uint64_t fus_conflicting_inputs :1; // OhmioLibraries label: reserved.
			uint64_t fus_saved_antenna_offset_missing :1;
			uint64_t fus_huge_sensor_update :1;
			uint64_t fus_safety_relay_open :1;
			uint64_t fus_drv_info_comms_error :1;
		} signals;
	} raw;
} FusError_t;

// message ID 0x215 FusionBiasOutlierMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t steerBias :8;    //deg
			uint64_t biasConfidence :16;
			uint64_t fUWBOutlier :8;
			uint64_t rearUWBOutlier :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double steerBias;
    double biasConfidence;
} FusionBiasOutlierMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionBiasOutlierMsg_ToCan(FusionBiasOutlierMsg_t * msg) 
{ 
    msg->raw.signals.steerBias = RoundLimitSigned(msg->steerBias, 0.1, 8);
    assert(msg->biasConfidence >= 0);
    msg->raw.signals.biasConfidence = RoundLimitUnsigned(msg->biasConfidence, 0.001, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionBiasOutlierMsg_FromCan(FusionBiasOutlierMsg_t * msg) 
{ 
    msg->steerBias = msg->raw.signals.steerBias * 0.1;
    msg->biasConfidence = msg->raw.signals.biasConfidence * 0.001;
}
// message ID 0x216 VehicleInfoMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t pitch :8;    //0.1degrees
			int64_t roll :8;    //0.1degrees
			uint64_t antennaDistance :16;    //mm
			uint64_t reserved :8;
			uint64_t time :24;    //ms
		} signals;
	} raw;
    double pitch;
    double roll;
} VehicleInfoMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void VehicleInfoMsg_ToCan(VehicleInfoMsg_t * msg) 
{ 
    msg->raw.signals.pitch = RoundLimitSigned(msg->pitch, 0.1, 8);
    msg->raw.signals.roll = RoundLimitSigned(msg->roll, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void VehicleInfoMsg_FromCan(VehicleInfoMsg_t * msg) 
{ 
    msg->pitch = msg->raw.signals.pitch * 0.1;
    msg->roll = msg->raw.signals.roll * 0.1;
}
// message ID 0x219 FusionFrontLatitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t latitude :36;    //degrees
			int64_t longAcc :8;    //m/s2
			int64_t pitch :8;    //degrees
			uint64_t observedAntennaOffset :10;    //mm
			uint64_t sync :2;
		} signals;
	} raw;
    double latitude;
    double longAcc;
    double pitch;
    double observedAntennaOffset;
} FusionFrontLatitude_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionFrontLatitude_ToCan(FusionFrontLatitude_t * msg) 
{ 
    assert(msg->latitude >= -90 && msg->latitude <= 90);
    assert(msg->longAcc >= -12.8 && msg->longAcc <= 12.7);
    assert(msg->pitch >= -12.8 && msg->pitch <= 12.7);
    assert(msg->observedAntennaOffset >= 2500 && msg->observedAntennaOffset <= 3523);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.latitude = RoundLimitSigned(msg->latitude, 0.00000001, 36);
    msg->raw.signals.longAcc = RoundLimitSigned(msg->longAcc, 0.1, 8);
    msg->raw.signals.pitch = RoundLimitSigned(msg->pitch, 0.1, 8);
    assert(msg->observedAntennaOffset - 2500 >= 0);
    msg->raw.signals.observedAntennaOffset = RoundLimitUnsigned(msg->observedAntennaOffset - 2500, 1, 10);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionFrontLatitude_FromCan(FusionFrontLatitude_t * msg) 
{ 
    msg->latitude = msg->raw.signals.latitude * 0.00000001;
    msg->longAcc = msg->raw.signals.longAcc * 0.1;
    msg->pitch = msg->raw.signals.pitch * 0.1;
    msg->observedAntennaOffset = msg->raw.signals.observedAntennaOffset * 1.0 + 2500;
}
// message ID 0x21B FusionRearLatitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t latitude :36;    //degrees
			uint64_t lateralConf :14;    //m
			int64_t latAcc :8;    //m/s2
			uint64_t unused :4;
			uint64_t sync :2;
		} signals;
	} raw;
    double latitude;
    double lateralConf;
    double latAcc;
} FusionRearLatitude_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionRearLatitude_ToCan(FusionRearLatitude_t * msg) 
{ 
    assert(msg->latitude >= -90 && msg->latitude <= 90);
    assert(msg->lateralConf <= 16.383);
    assert(msg->latAcc >= -12.8 && msg->latAcc <= 12.7);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.latitude = RoundLimitSigned(msg->latitude, 0.00000001, 36);
    assert(msg->lateralConf >= 0);
    msg->raw.signals.lateralConf = RoundLimitUnsigned(msg->lateralConf, 0.001, 14);
    msg->raw.signals.latAcc = RoundLimitSigned(msg->latAcc, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionRearLatitude_FromCan(FusionRearLatitude_t * msg) 
{ 
    msg->latitude = msg->raw.signals.latitude * 0.00000001;
    msg->lateralConf = msg->raw.signals.lateralConf * 0.001;
    msg->latAcc = msg->raw.signals.latAcc * 0.1;
}
// message ID 0x21C FusionRearLongitude
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t longitude :36;    //degrees
			uint64_t headConf :14;    //degrees
			uint64_t savedAntennaOffset :10;    //mm
			uint64_t fusionInitialisable :1;
			uint64_t reserved :1;
			uint64_t sync :2;
		} signals;
	} raw;
    double longitude;
    double headConf;
    double savedAntennaOffset;
} FusionRearLongitude_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionRearLongitude_ToCan(FusionRearLongitude_t * msg) 
{ 
    assert(msg->longitude >= -180 && msg->longitude <= 180);
    assert(msg->headConf <= 16.383);
    assert(msg->savedAntennaOffset >= 2500 && msg->savedAntennaOffset <= 3523);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.longitude = RoundLimitSigned(msg->longitude, 0.00000001, 36);
    assert(msg->headConf >= 0);
    msg->raw.signals.headConf = RoundLimitUnsigned(msg->headConf, 0.001, 14);
    assert(msg->savedAntennaOffset - 2500 >= 0);
    msg->raw.signals.savedAntennaOffset = RoundLimitUnsigned(msg->savedAntennaOffset - 2500, 1, 10);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void FusionRearLongitude_FromCan(FusionRearLongitude_t * msg) 
{ 
    msg->longitude = msg->raw.signals.longitude * 0.00000001;
    msg->headConf = msg->raw.signals.headConf * 0.001;
    msg->savedAntennaOffset = msg->raw.signals.savedAntennaOffset * 1.0 + 2500;
}
// message ID 0x21D FusionHeight
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t height :23;    //m
			int64_t speed :12;    //m/s
			uint64_t sync :2;
			uint64_t delay_gnss_front :10;
			uint64_t delay_gnss_rear :10;
			uint64_t compute_time :7;
		} signals;
	} raw;
    double height;
    double speed;
    double compute_time;
} FusionHeight_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void FusionHeight_ToCan(FusionHeight_t * msg) 
{ 
    assert(msg->height >= -553.5 && msg->height <= 6000);
    assert(msg->speed >= -20.47 && msg->speed <= 20.47);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.height = RoundLimitSigned(msg->height, 0.1, 16);
    msg->raw.signals.speed = RoundLimitSigned(msg->speed, 0.01, 12);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void FusionHeight_FromCan(FusionHeight_t * msg) 
{ 
    msg->height = msg->raw.signals.height * 0.1;
    msg->speed = msg->raw.signals.speed * 0.01;
}
// message ID 0x724 FusionFlagsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t fus_internal_reset :1;
			uint64_t init_failed :1;
			uint64_t front_steer_invalid :1;
			uint64_t rear_steer_invalid :1;
			uint64_t speed_invalid :1;
			uint64_t time_step_size_invalid :1;
			uint64_t lidar_slam_stddev_nonpositive :1;
			uint64_t cam_slam_stddev_nonpositive :1;
			uint64_t motor_comms :1;
			uint64_t front_steer_comms :1;
			uint64_t rear_steer_comms :1;
			uint64_t veh_cholesky_failed :1;
			uint64_t veh_innovation_cov_not_psd :1;
			uint64_t veh_nonpositive_variance :1;
			uint64_t veh_nan_or_inf :1;
			uint64_t odo_cholesky_failed :1;
			uint64_t odo_innovation_cov_not_psd :1;
			uint64_t odo_nonpositive_variance :1;
			uint64_t odo_nan_or_inf :1;
			uint64_t drv_req_comms :1;
			uint64_t front_wheel_speed_comms :1;
			uint64_t rear_wheel_speed_comms :1;
			uint64_t conflicting_inputs :1;
			uint64_t saved_antenna_offset_missing :1;
			uint64_t huge_sensor_update :1;
			uint64_t safety_relay_open :1;
			uint64_t drv_info_comms_error :1;
			uint64_t w_front_gnss_no_data_ubx :1;
			uint64_t w_rear_gnss_no_data :1;
			uint64_t w_odometry_suspicious :1;
			uint64_t w_gnss_antennas_out_of_range :1;
			uint64_t w_no_gnss_period_estimate :1;
			uint64_t w_front_gnss_comms :1;
			uint64_t w_rear_gnss_comms :1;
			// OhmioLibraries_36 label: no_engine_state.
			uint64_t w_no_engine_state :1;
			uint64_t w_large_gnss_delay :1;
			uint64_t w_large_lidar_delay :1;
			uint64_t reserved1 :3;
			uint64_t st_lidar_slam_no_data_can :1;
			uint64_t st_lidar_slam_no_kf :1;
			uint64_t st_cam_slam_no_data_can :1;
			uint64_t st_cam_slam_no_kf :1;
			uint64_t reserved2 :2;
			uint64_t st_using_front_gnss :1;
			uint64_t st_using_rear_gnss :1;
			uint64_t st_using_lidar_slam :1;
			uint64_t st_using_cam_slam :1;
			uint64_t st_using_imu_heading :1;
			uint64_t reserved3 :1;
			uint64_t st_dead_reckoning :1;
			uint64_t reserved4 :2;
			uint64_t st_external_reset :1;
		} signals;
	} raw;
} FusionFlagsMsg_t;

// message ID 0x725 ErrorFusionDebugMsg
enum FusionDebugMsgErrorCode
{
	fusdebug_Reset = 0,
	fusdebug_initialisation,
	fusdebug_steer_Angle_Front_Invalid,
	fusdebug_steer_Angle_Rear_Invalid,
	fusdebug_wheel_Speed_Invalid,
	fusdebug_time_Step_Size_Invalid,
	fusdebug_huge_sensor_update,
	fusdebug_Reserved,
	fusdebug_Reserved2,
	fusdebug_speed_Not_Available_But_Not_Zero,
	fusdebug_slam_Fwd_Std_Dev_Non_Positive,
	fusdebug_slam_Lat_Std_Dev_Non_Positive,
	fusdebug_slam_Head_Std_Dev_Non_Positive,
	fusdebug_fusion_Conflicting_Inputs,
	fusdebug_saved_antenna_offset_missing,
	fusdebug_safety_relay_open,
	fusdebug_drive_info_comms,
	fusdebug_Reserved3,
	fusdebug_Reserved4,
	fusdebug_Reserved5,
	fusdebug_Reserved6,
	fusdebug_Reserved7,
	fusdebug_Reserved8,
	fusdebug_Reserved9,
	fusdebug_Reserved10,
	fusdebug_Reserved11,
	fusdebug_Reserved12,
	fusdebug_Reserved13,
	fusdebug_Reserved14,
	fusdebug_Reserved15,
	fusdebug_Reserved16,
	fusdebug_Reserved17,
	fusdebug_cholesky_failed_veh,
	fusdebug_innovation_covariance_not_psd_veh,
	fusdebug_choleskey_failed_odo,
	fusdebug_innovation_convariance_not_psd_odo,
	fusdebug_steer_angle_front_unavailable,
	fusdebug_steer_angle_rear_unavailable,
	fusdebug_rtk_front_no_data_ubx,
	fusdebug_rtk_rear_no_data_ubx,
	fusdebug_rtk_front_no_data_can,
	fusdebug_rtk_rear_no_data_can,
	fusdebug_dead_reckoning,
	fusdebug_odometry_suspicious,
	fusdebug_Reserved18,
	fusdebug_gnss_antennas_out_of_range,
	fusdebug_using_lidar_slam,
	fusdebug_using_gps,
	fusdebug_fusion_initialisable,
	//always add error codes above this
	fusdebug_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t fusdebugReset :1;
			uint64_t initialisation :1;
			uint64_t steerAngleFrontInvalid :1;
			uint64_t steerAngleRearInvalid :1;
			uint64_t wheelSpeedInvalid :1;
			uint64_t timeStepSizeInvalid :1;
			uint64_t huge_sensor_update :1;
			uint64_t reserved :2;
			uint64_t speedNotAvailableButNotZero :1;
			uint64_t slamFwdStdDevNonPositive :1;
			uint64_t slamLatStdDevNonPositive :1;
			uint64_t slamHeadStdDevNonPositive :1;
			uint64_t fusionConflictingInputs :1;
			uint64_t saved_antenna_offset_missing :1;
			uint64_t safety_relay_open :1;
			uint64_t drive_info_comms :1;
			uint64_t reserved1 :15;
			uint64_t cholesky_failed_veh :1;
			uint64_t innovation_covariance_not_psd_veh :1;
			uint64_t choleskey_failed_odo :1;
			uint64_t innovation_convariance_not_psd_odo :1;
			uint64_t steer_angle_front_unavailable :1;
			uint64_t steer_angle_rear_unavailable :1;
			uint64_t rtk_front_no_data_ubx :1;
			uint64_t rtk_rear_no_data_ubx :1;
			uint64_t rtk_front_no_data_can :1;
			uint64_t rtk_rear_no_data_can :1;
			uint64_t dead_reckoning :1;
			uint64_t odometry_suspicious :1;
			uint64_t reserved2 :1;
			uint64_t gnss_antennas_out_of_range :1;
			uint64_t using_lidar_slam :1;
			uint64_t using_gps :1;
			uint64_t fusion_initialisable :1;
		} signals;
	} raw;
} ErrorFusionDebugMsg_t;

// message ID 0x727 IMUMag
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t x :20;    //uT
			int64_t y :20;    //uT
			int64_t z :20;    //uT
			uint64_t reserved :2;
			uint64_t sync :2;
		} signals;
	} raw;
    double x;
    double y;
    double z;
} IMUMag_t;
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void IMUMag_ToCan(IMUMag_t * msg) 
{ 
    assert(msg->x >= -229 && msg->x <= 229);
    assert(msg->y >= -229 && msg->y <= 229);
    assert(msg->z >= -229 && msg->z <= 229);
    /* 2-4 rerun: BK status[48-49] overlaps Origin z[40-59]; user confirmed status assert is excluded. */
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.x = RoundLimitSigned(msg->x, 0.007, 16);
    msg->raw.signals.y = RoundLimitSigned(msg->y, 0.007, 16);
    msg->raw.signals.z = RoundLimitSigned(msg->z, 0.007, 16);
}
/* 2-4 merge: BK function active despite Origin/BK signal layout conflict. See dbc_CAN.h/2-4_dbc_CAN_병합_점검_필요사항.md. */
static void IMUMag_FromCan(IMUMag_t * msg) 
{ 
    msg->x = msg->raw.signals.x * 0.007;
    msg->y = msg->raw.signals.y * 0.007;
    msg->z = msg->raw.signals.z * 0.007;
}
// message ID 0x621 IMURot
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t pitch :16;    //degrees
			int64_t roll :16;    //degrees
			uint64_t heading :16;    //degrees
			uint64_t accuracy :12;    //radians
			uint64_t status :2;
			uint64_t sync :2;
		} signals;
	} raw;
    double pitch;
    double roll;
    double heading;
    double accuracy;
} IMURot_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMURot_ToCan(IMURot_t * msg) 
{ 
    assert(msg->pitch >= -180 && msg->pitch <= 180);
    assert(msg->roll >= -180 && msg->roll <= 180);
    assert(msg->heading <= 360);
    assert(msg->accuracy <= 3.14);
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.pitch = RoundLimitSigned(msg->pitch, 0.0055, 16);
    msg->raw.signals.roll = RoundLimitSigned(msg->roll, 0.0055, 16);
    assert(msg->heading >= 0);
    msg->raw.signals.heading = RoundLimitUnsigned(msg->heading, 0.0055, 16);
    assert(msg->accuracy >= 0);
    msg->raw.signals.accuracy = RoundLimitUnsigned(msg->accuracy, 0.00077, 12);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMURot_FromCan(IMURot_t * msg) 
{ 
    msg->pitch = msg->raw.signals.pitch * 0.0055;
    msg->roll = msg->raw.signals.roll * 0.0055;
    msg->heading = msg->raw.signals.heading * 0.0055;
    msg->accuracy = msg->raw.signals.accuracy * 0.00077;
}
// message ID 0x622 IMUAcc
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t x :16;    //m/s^2
			int64_t y :16;    //m/s^2
			int64_t z :16;    //m/s^2
			uint64_t status :2;
			uint64_t reserved :12;
			uint64_t sync :2;
		} signals;
	} raw;
    double x;
    double y;
    double z;
} IMUAcc_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMUAcc_ToCan(IMUAcc_t * msg) 
{ 
    assert(msg->x >= -127 && msg->x <= 127);
    assert(msg->y >= -127 && msg->y <= 127);
    assert(msg->z >= -127 && msg->z <= 127);
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.x = RoundLimitSigned(msg->x, 0.0039, 16);
    msg->raw.signals.y = RoundLimitSigned(msg->y, 0.0039, 16);
    msg->raw.signals.z = RoundLimitSigned(msg->z, 0.0039, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMUAcc_FromCan(IMUAcc_t * msg) 
{ 
    msg->x = msg->raw.signals.x * 0.0039;
    msg->y = msg->raw.signals.y * 0.0039;
    msg->z = msg->raw.signals.z * 0.0039;
}
// message ID 0x623 IMUGyr
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t x :16;    //rad/s
			int64_t y :16;    //rad/s
			int64_t z :16;    //rad/s
			int64_t temperature :8;    //degrees
			uint64_t status :2;
			uint64_t unused :4;
			uint64_t sync :2;
		} signals;
	} raw;
    double x;
    double y;
    double z;
    double temperature;
} IMUGyr_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMUGyr_ToCan(IMUGyr_t * msg) 
{ 
    assert(msg->x >= -63 && msg->x <= 63);
    assert(msg->y >= -63 && msg->y <= 63);
    assert(msg->z >= -63 && msg->z <= 63);
    assert(msg->temperature >= -127 && msg->temperature <= 128);
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.x = RoundLimitSigned(msg->x, 0.00195, 16);
    msg->raw.signals.y = RoundLimitSigned(msg->y, 0.00195, 16);
    msg->raw.signals.z = RoundLimitSigned(msg->z, 0.00195, 16);
    msg->raw.signals.temperature = RoundLimitSigned(msg->temperature, 1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void IMUGyr_FromCan(IMUGyr_t * msg) 
{ 
    msg->x = msg->raw.signals.x * 0.00195;
    msg->y = msg->raw.signals.y * 0.00195;
    msg->z = msg->raw.signals.z * 0.00195;
    msg->temperature = msg->raw.signals.temperature * 1.0;
}
// message ID 0x624 IMUStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t status :32;
			uint64_t warnings :16;
			uint64_t heading :12;    //degrees
			uint64_t heading_available :1;
		} signals;
	} raw;
    double heading;
} IMUStatus_t;


void IMUStatus_ToCan(IMUStatus_t * msg) ;

void IMUStatus_FromCan(IMUStatus_t * msg) ;

// message ID 0x707 ObstaclePcWarning
enum ObstaclePcWarningErrorCode
{
	Obs_Front_Top_Lidar_Detecting_Body = 0,
	Obs_Rear_Top_Lidar_Detecting_Body,
	Obs_Front_Top_Lidar_Section_Missing,
	Obs_Front_Right_Lidar_Section_Missing,
	Obs_Front_Left_Lidar_Section_Missing,
	Obs_Rear_Top_Lidar_Section_Missing,
	Obs_Rear_Right_Lidar_Section_Missing,
	Obs_Rear_Left_Lidar_Section_Missing,
	Obs_Front_Top_Lidar_Calibration,
	Obs_Front_Right_Lidar_Calibration,
	Obs_Front_Left_Lidar_Calibration,
	Obs_Rear_Top_Lidar_Calibration,
	Obs_Rear_Right_Lidar_Calibration,
	Obs_Rear_Left_Lidar_Calibration,
	Obs_Keyframe_Saver,
	Obs_Odometry_Timeout,
	Obs_Keyframe_Loader_Database,
	Obs_Keyframe_Loader_Version,
	//always add warning codes above this
	Obs_NumWarningCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t ObsFrontTopLidarDetectingBody :1;
			uint64_t ObsRearTopLidarDetectingBody :1;
			uint64_t ObsFrontTopLidarSectionMissing :1;
			uint64_t ObsFrontRightLidarSectionMissing :1;
			uint64_t ObsFrontLeftLidarSectionMissing :1;
			uint64_t ObsRearTopLidarSectionMissing :1;
			uint64_t ObsRearRightLidarSectionMissing :1;
			uint64_t ObsRearLeftLidarSectionMissing :1;
			uint64_t ObsFrontTopLidarCalibration :1;
			uint64_t ObsFrontRightLidarCalibration :1;
			uint64_t ObsFrontLeftLidarCalibration :1;
			uint64_t ObsRearTopLidarCalibration :1;
			uint64_t ObsRearRightLidarCalibration :1;
			uint64_t ObsRearLeftLidarCalibration :1;
			uint64_t ObsKeyframeSaverError :1;
			uint64_t ObsOdometryTimeout :1;
			uint64_t ObsKeyframeLoaderDatabaseError :1;
			uint64_t ObsKeyframeLoaderVersionError :1;
		} signals;
	} raw;
} ObstaclePcWarning_t;

// message ID 0x313 VersionRespMsg
// message ID 0x314 BootloaderVersionRespMsg
// message ID 0x315 OcanDBCVersionMsg
// message ID 0x316 PcanDBCVersionMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t major :7;
			uint64_t debug :1;
			uint64_t minor :8;
			uint64_t build :32;
		} signals;
	} raw;
} VersionRespMsg_t;

// message ID 0x673 TrackMD5RespMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t idXORmd5 :64;
		} signals;
	} raw;
} TrackMD5RespMsg_t;

// message ID 0x411 LiveUpdateACKMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t ACK :8;
		} signals;
	} raw;
} LiveUpdateACKMsg_t;

// message ID 0x610 FileTransferMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t senderID :16;
			uint64_t receiverID :16;
			uint64_t action :8;
			uint64_t meaning :8;
			uint64_t extra :16;
		} signals;
	} raw;
} FileTransferMsg_t;

// message ID 0x611 FileAckMsg
// message ID 0x613 DataAckMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t senderID :16;
			uint64_t receiverID :16;
			uint64_t ack :8;
			uint64_t error :8;
			uint64_t index :8;
		} signals;
	} raw;
} TransferAckMsg_t;

// message ID 0x612 DataTransferMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t index :8;
			uint64_t data :48;
			uint64_t checksum :8;
		} signals;
	} raw;
} DataTransferMsg_t;

// message ID 0x7F0 AnyExceptionMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t moduleId :8;
			uint64_t taskId :8;
			uint64_t debug :32;
		} signals;
	} raw;
} AnyExceptionMsg_t;

// message ID 0x765 fusionExceptionMsg
// message ID 0x7C0 frontWheelExceptionMsg
// message ID 0x7C1 rearWheelExceptionMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t ex_addr :32;
			uint64_t ex_code :5;
			uint64_t reserved :3;
			uint64_t user_flag :8;
		} signals;
	} raw;
} ExceptionMsg_t;

// message ID 0x420 LiveUpdateData
// message ID 0x421 LiveUpdateRespMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t data :64;
		} signals;
	} raw;
} LiveUpdateMsg_t;

// message ID 0x290 Motor1Status
// message ID 0x291 Motor2Status
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t speed :16;    //rad/s
			int64_t motorTemp :8;    //degrees
			int64_t controllerTemp :8;    //degrees
			uint64_t directionFault :1;
			uint64_t noReqfor300ms :1;
			uint64_t reserved :14;
			uint64_t counter :8;
			uint64_t config :8;
		} signals;
	} raw;
    double speed;
    double motorTemp;
    double controllerTemp;
} MotorStatus_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void MotorStatus_ToCan(MotorStatus_t * msg) 
{ 
    assert(msg->speed >= -327.68 && msg->speed <= 327.67);
    assert(msg->motorTemp >= -128 && msg->motorTemp <= 127);
    assert(msg->controllerTemp >= -128 && msg->controllerTemp <= 127);
    assert(msg->raw.signals.directionFault <= 1);
    assert(msg->raw.signals.noReqfor300ms <= 1);
    assert(msg->raw.signals.counter <= 255);
    assert(msg->raw.signals.config <= 255);
    msg->raw.signals.speed = RoundLimitSigned(msg->speed, 0.01, 16);
    msg->raw.signals.motorTemp = RoundLimitSigned(msg->motorTemp, 1, 8);
    msg->raw.signals.controllerTemp = RoundLimitSigned(msg->controllerTemp, 1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void MotorStatus_FromCan(MotorStatus_t * msg) 
{ 
    msg->speed = msg->raw.signals.speed * 0.01;
    msg->motorTemp = msg->raw.signals.motorTemp * 1.0;
    msg->controllerTemp = msg->raw.signals.controllerTemp * 1.0;
}
// message ID 0x296 Motor3Status2
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t current :16;    //A
			uint64_t voltage :16;    //V
			uint64_t actualTorque :16;    //Nm
			uint64_t count :8;
			uint64_t reserved :4;
			uint64_t dampEnable :2;
			uint64_t lameStatus :2;
		} signals;
	} raw;
    double current;
} Motor3Status2_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status2_ToCan(Motor3Status2_t * msg) 
{ 
    assert(msg->raw.signals.actualTorque <= 3000);
    assert(msg->raw.signals.count <= 255);
    assert(msg->current + 600 >= 0);
    msg->raw.signals.current = RoundLimitUnsigned(msg->current + 600, 1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status2_FromCan(Motor3Status2_t * msg) 
{ 
    msg->current = msg->raw.signals.current * 1.0 - 600;
}
// message ID 0x580 Motor3Status3
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t HWVersionMinorL :4;
			uint64_t HWVersionMinorH :4;
			uint64_t HWVersionMajor :4;
			uint64_t reserved :4;
			uint64_t SWVersionMinorL :4;
			uint64_t SWVersionMinorH :4;
			uint64_t SWVersionMajor :4;
			uint64_t vehicleInfo :4;
			uint64_t SWReleaseYear :7;
			uint64_t SWReleaseDate :5;
			uint64_t SWReleaseMonth :4;
			uint64_t energyDeviceAddr :8;
			uint64_t programCode :8;
		} signals;
	} raw;
} Motor3Status3_t;

// message ID 0x581 Motor3Status4
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t productionUniqueNo :16;
			uint64_t factoryNo :16;
			uint64_t manufactureYear :7;
			uint64_t manufactureDate :5;
			uint64_t manufactureMonth :4;
			uint64_t deviceAddr :8;
		} signals;
	} raw;
} Motor3Status4_t;

// message ID 0x582 Motor3Status5
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t initAngleBeforeAdjust :12;    //degrees
			uint64_t AdjustResult :2;
			uint64_t reserved :2;
			uint64_t initAngleaAfterAdjust :12;    //degrees
		} signals;
	} raw;
    double initAngleBeforeAdjust;
    double initAngleaAfterAdjust;
} Motor3Status5_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status5_ToCan(Motor3Status5_t * msg) 
{ 
    assert(msg->initAngleBeforeAdjust <= 360);
    assert(msg->initAngleaAfterAdjust <= 360);
    assert(msg->initAngleBeforeAdjust >= 0);
    msg->raw.signals.initAngleBeforeAdjust = RoundLimitUnsigned(msg->initAngleBeforeAdjust, 0.1, 12);
    assert(msg->initAngleaAfterAdjust >= 0);
    msg->raw.signals.initAngleaAfterAdjust = RoundLimitUnsigned(msg->initAngleaAfterAdjust, 0.1, 12);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status5_FromCan(Motor3Status5_t * msg) 
{ 
    msg->initAngleBeforeAdjust = msg->raw.signals.initAngleBeforeAdjust * 0.1;
    msg->initAngleaAfterAdjust = msg->raw.signals.initAngleaAfterAdjust * 0.1;
}
// message ID 0x583 Motor3Status6
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t forwardCumulativeCharge :20;    //kWH
			uint64_t reverseCumulativeCharge :20;    //kWH
			uint64_t positiveCumulativePower :12;    //kWH
			uint64_t reverseCumulativePower :12;    //kWH
		} signals;
	} raw;
    double positiveCumulativePower;
    double reverseCumulativePower;
} Motor3Status6_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status6_ToCan(Motor3Status6_t * msg) 
{ 
    assert(msg->raw.signals.forwardCumulativeCharge <= 10000);
    assert(msg->raw.signals.reverseCumulativeCharge <= 10000);
    assert(msg->positiveCumulativePower <= 400);
    assert(msg->reverseCumulativePower <= 400);
    assert(msg->positiveCumulativePower >= 0);
    msg->raw.signals.positiveCumulativePower = RoundLimitUnsigned(msg->positiveCumulativePower, 0.1, 12);
    assert(msg->reverseCumulativePower >= 0);
    msg->raw.signals.reverseCumulativePower = RoundLimitUnsigned(msg->reverseCumulativePower, 0.1, 12);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void Motor3Status6_FromCan(Motor3Status6_t * msg) 
{ 
    msg->positiveCumulativePower = msg->raw.signals.positiveCumulativePower * 0.1;
    msg->reverseCumulativePower = msg->raw.signals.reverseCumulativePower * 0.1;
}
// message ID 0x12 ErrorFrontSteering
// message ID 0x13 ErrorRearSteering
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t SteeringReqCommsError :1;
			uint64_t SteeringReqSeqError :1;
			uint64_t SteeringMotorBlocked :1;
			uint64_t SteeringOverHeat :1;
			uint64_t SteeringAngleSensorError :1;
			uint64_t SteeringMotorPosSensorError :1;
			uint64_t SteeringVoltOutOfRange :1;
			uint64_t reserved :1;
			uint64_t volt :8;    //volt
			uint64_t SteerReqCommsWarn :1;
			uint64_t SteerReqSeqWarn :1;
			uint64_t SteerMotorHighCurrentWarn :1;
			uint64_t SteerHighTempWarn :1;
			uint64_t reserved1 :4;
			int64_t current :8;    //A
			int64_t RPM :16;    //rpm
			uint64_t volt_old :8;    //volt
			uint64_t tempProtectionFactor :8;
		} signals;
	} raw;
    double volt;
    double current;
    double RPM;
    double volt_old;
} ErrorSteering_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ErrorSteering_ToCan(ErrorSteering_t * msg) 
{ 
    assert(msg->volt >= 0);
    msg->raw.signals.volt = RoundLimitUnsigned(msg->volt, 0.1, 8);
    msg->raw.signals.current = RoundLimitSigned(msg->current, 1, 8);
    msg->raw.signals.RPM = RoundLimitSigned(msg->RPM, 1, 16);
    assert(msg->volt_old >= 0);
    msg->raw.signals.volt_old = RoundLimitUnsigned(msg->volt_old, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ErrorSteering_FromCan(ErrorSteering_t * msg) 
{ 
    msg->volt = msg->raw.signals.volt * 0.1;
    msg->current = msg->raw.signals.current * 1.0;
    msg->RPM = msg->raw.signals.RPM * 1.0;
    msg->volt_old = msg->raw.signals.volt_old * 0.1;
}
// message ID 0x14 ManualError
// message ID 0x26 Trans1Error
enum ManualErrorCode
{
	Man_Joystick_Disconnect = 0,
	Man_Joystick_Comms,
	Man_Joystick_Centre,
	Man_Safety_Relay_Open,
	Man_Dri_Info_Coms,
	Man_Duplicated_Joystick_Board,
	//always add error codes above this
	Man_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t ManJoystickDisconnect :1;
			uint64_t ManJoystickCommsError :1;
			uint64_t ManJoystickCentreError :1;
			uint64_t ManSafetyRelayOpen :1;
			uint64_t ManDriInfoComsError :1;
			uint64_t DuplicatedJoystickBoard :1;
		} signals;
	} raw;
} ErrorManual_t;

// message ID 0x590 RemoteSignalMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
			uint64_t startBtn :1;
			uint64_t emergencyBtn :1;
			uint64_t horn :1;
			uint64_t overtake :1;
		} signals;
	} raw;
} RemoteSignalMsg_t;

// message ID 0x16 ErrorBlackBox
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reserved :64;
		} signals;
	} raw;
} ErrorBlackBox_t;

// message ID 0x18 ErrorLeftMotor
enum LeftMotorErrorCode
{
	motor_Comms = 0,
	motor_Temp,
	//always add error codes above this
	motor_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t motorCommsError :1;
			uint64_t motorTempError :1;
		} signals;
	} raw;
} ErrorLeftMotor_t;

// message ID 0x1A ErrorEHB
enum EHBErrorCode
{
	EHB_Request_Warning = 0,
	EHB_Oil_Warning,
	EHB_Current_Sensor,
	EHB_NTC,
	EHB_Over_Temp_Warning,
	EHB_Power_Supply_Lv2,
	EHB_Pressure_Sensor,
	EHB_Can_Bus_Off,
	EHB_Power_Supply_Lv4,
	EHB_Power_Supply,
	EHB_Power_Drvr,
	EHB_Motor,
	EHB_Power_Switch,
	EHB_Fluid_Leakage,
	//always add error codes above this
	EHB_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t EHBRequestWarning :1;
			uint64_t EHBOilWarning :1;
			uint64_t EHBCurrentSensorFailed :1;
			uint64_t EHB_NTCFailed :1;
			uint64_t EHBOverTempWarning :1;
			uint64_t EHBPowerSupplyLv2 :1;
			uint64_t EHBPressureSensorFailed :1;
			uint64_t EHBCanBusOff :1;
			uint64_t EHBPowerSupplyLv4 :1;
			uint64_t EHBECUPowerSupplyFailed :1;
			uint64_t EHBPowerDriverFailed :1;
			uint64_t EHBMotorFailed :1;
			uint64_t EHBPowerSwitchFailed :1;
			uint64_t EHBFluidLeakageFailed :1;
		} signals;
	} raw;
} ErrorEHB_t;

// message ID 0x1B ErrorEHBT060
enum EHBT060ErrorCode
{
	T060_Request_Warning = 0,
	T060_Follow_Lv_1,
	T060_Vib_Lv_1,
	T060_NTCLv1,
	T060_NTCLv2,
	T060_Pressure_Sensor,
	T060_Over_Temp_Warning,
	T060_Low_Power_Lv_1,
	T060_High_Power_Lv_1,
	T060_Follow_Lv_2,
	T060_Vib_Lv_2,
	T060_Can_Bus_Off,
	T060_Over_Current,
	T060_Current_Sensor,
	T060_Low_Power_Lv_2,
	T060_High_Power_Lv_2,
	T060_Power_Switch,
	T060_Power_Drvr,
	T060_Motor_Pos,
	//always add error codes above this
	T060_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t T060RequestWarning :1;
			uint64_t T060FollowLv1 :1;
			uint64_t T060VibLv1 :1;
			uint64_t T060_NTCLv1 :1;
			uint64_t T060_NTCLv2 :1;
			uint64_t T060PressureSensorFailed :1;
			uint64_t T060OverTempWarning :1;
			uint64_t T060LowPowerLv1 :1;
			uint64_t T060HighPowerLv1 :1;
			uint64_t T060FollowLv2 :1;
			uint64_t T060VibLv2 :1;
			uint64_t T060CanBusOff :1;
			uint64_t T060OverCurrent :1;
			uint64_t T060CurrentSensorFailed :1;
			uint64_t T060LowPowerLv2 :1;
			uint64_t T060HighPowerLv2 :1;
			uint64_t T060PowerSwitchFailed :1;
			uint64_t T060PowerDriverFailed :1;
			uint64_t T060MotorPosFailed :1;
			uint64_t reserved :5;
			uint64_t T060Temp :8;    //Degrees
			uint64_t reserved1 :16;
			uint64_t softwareVersion :8;
			uint64_t hardwareVersion :8;
		} signals;
	} raw;
    double T060Temp;
} ErrorEHBT060_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ErrorEHBT060_ToCan(ErrorEHBT060_t * msg) 
{ 
    assert(msg->T060Temp >= -50 && msg->T060Temp <= 205);
    assert(msg->raw.signals.softwareVersion <= 255);
    assert(msg->raw.signals.hardwareVersion <= 255);
    assert(msg->T060Temp + 50 >= 0);
    msg->raw.signals.T060Temp = RoundLimitUnsigned(msg->T060Temp + 50, 1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void ErrorEHBT060_FromCan(ErrorEHBT060_t * msg) 
{ 
    msg->T060Temp = msg->raw.signals.T060Temp * 1.0 - 50;
}
// message ID 0x1C EPB1Msg
// message ID 0x1D parkBrake2
enum EPBMsgErrorCode
{
	EPB_Engage = 0,
	EPB_Disengage,
	EPB_Version,
	EPB_Safety_Relay_Open,
	EPB_Drv_Info_Comms,
	//always add error codes above this
	EPB_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t EPBEngageError :1;
			uint64_t EPBDisengageError :1;
			uint64_t EPBVersionError :1;
			uint64_t EPBSafetyRelayOpen :1;
			uint64_t EPBDrvInfoCommsError :1;
		} signals;
	} raw;
} EPBErrorMsg_t;

// message ID 0x1E frontSignal
// message ID 0x1F rearSignal
enum SignalMsgErrorCode
{
	signal_Version = 0,
	signal_Safety_Relay_Open,
	signal_Drv_Info_Comms,
	//always add error codes above this
	signal_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t signalVersionError :1;
			uint64_t signalSafetyRelayOpen :1;
			uint64_t signalDrvInfoCommsError :1;
		} signals;
	} raw;
} SignalErrorMsg_t;

// message ID 0x22 ErrorSafetyBoard
enum SafetyBoardErrorCode
{
	Safety_Line_Activated = 0,
	Safety_Relay_K2,
	Safety_Relay_K5,
	Safety_Relay_K3,
	//always add error codes above this
	Safety_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t SafetyLineActivated :1;
			uint64_t SafetyRelayK2Failed :1;
			uint64_t SafetyRelayK5Failed :1;
			uint64_t SafetyRelayK3Failed :1;
			uint64_t PowerSupplyV4Low :2;
		} signals;
	} raw;
} ErrorSafetyBoard_t;

// message ID 0x23 StartupErrorMsg
enum StartupMsgErrorCode
{
	startup_Version = 0,
	startup_bms_Status,
	startup_bms_Err_Level,
	startup_bms_Pos_Relay_Open,
	startup_Safety_Relay_Open,
	startup_Drv_Info_Comms,
	startup_lotte_Bms_Err,
	//always add error codes above this
	startup_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t startupVersionError :1;
			uint64_t bmsStatus :1;
			uint64_t bmsErrLevel :1;
			uint64_t bmsPosRelayOpen :1;
			uint64_t startupSafetyRelayOpen :1;
			uint64_t startupDriveInfoComms :1;
			uint64_t lotteBmsErr :1;
		} signals;
	} raw;
} StartupErrorMsg_t;

// message ID 0x80 ErrorFrontWheelSpeed
// message ID 0x81 ErrorRearWheelSpeed
enum WheelSpeedErrorCode
{
	wheel_board_config = 0,
	wheel_safety_relay_open,
	wheel_drv_info_comms,
	//always add error codes above this
	wheel_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t wheel_board_config_error :1;
			uint64_t wheel_safety_relay_open :1;
			uint64_t wheel_drv_info_comms_error :1;
		} signals;
	} raw;
} ErrorWheelSpeed_t;

// message ID 0x88 ErrorTeleOp
enum TeleOpErrorCode
{
	teleop_safety_relay_open = 0,
	teleop_drv_info_comms,
	//always add error codes above this
	teleop_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t teleop_safety_relay_open :1;
			uint64_t teleop_drv_info_comms_error :1;
		} signals;
	} raw;
} ErrorTeleOp_t;

// message ID 0x110 AtmelLocalisaionError
enum AtmelLocalisaionErrorCode
{
	Atloc_GPS1_Input = 0,
	Atloc_GPS2_Input,
	Atloc_Joystick_Comms,
	Atloc_Reserved,
	Atloc_Timer10ms_Process_Timeout,
	Atloc_Safety_Relay_Open,
	//always add error codes above this
	Atloc_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AtlocGPS1InputError :1;
			uint64_t AtlocGPS2InputError :1;
			uint64_t AtlocJoystickCommsError :1;
			uint64_t reserved :1;
			uint64_t AtlocTimer10msProcessTimeout :1;
			uint64_t AtlocSafetyRelayOpen :1;
		} signals;
	} raw;
} AtmelLocalisaionError_t;

// message ID 0x111 AtmelDriveError
enum AtmelDrvErrorCode
{
	Atdrive_Search_Closest_Point_Timeout = 0,
	Atdrive_Speed_Selection_Timeout,
	Atdrive_Calc_Drv_Timeout,
	Atdrive_Brake_Selection_Timeout,
	Atdrive_Safety_Relay_Open,
	//always add error codes above this
	Atdrive_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AtdriveSearchClosestPointTimeout :1;
			uint64_t AtdriveSpeedSelectionTimeout :1;
			uint64_t AtdriveCalcDriveTimeout :1;
			uint64_t AtdriveBrakeSelectionTimeout :1;
			uint64_t AtdriveSafetyRelayOpen :1;
		} signals;
	} raw;
} AtmelDriveError_t;

// message ID 0x114 AtmelManualError
enum AtmelManualErrorCode
{
	Atmanual_Joystick_Comms = 0,
	Atmanual_Safety_Relay_Open,
	//always add error codes above this
	Atmanual_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AtmanualJoystickCommsError :1;
			uint64_t AtmanualSafetyRelayOpen :1;
		} signals;
	} raw;
} AtmelManualError_t;

// message ID 0x115 AtmelFusionError
enum AtmelFusionErrorCode
{
	Atfusion_Timer1ms_Interrupt_Timeout = 0,
	Atfusion_Main_Loop_Timeout,
	Atfusion_Observe_Log_Timeout,
	Atfusion_Estimate_Log_Timeout,
	Atfusion_Safety_Relay_Open,
	//always add error codes above this
	Atfusion_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AtfusionTimer1msInterruptTimeout :1;
			uint64_t AtfusionMainLoopTimeout :1;
			uint64_t AtfusionObserveLogTimeout :1;
			uint64_t AtfusionEstimateLogTimeout :1;
			uint64_t AtfusionSafetyRelayOpen :1;
		} signals;
	} raw;
} AtmelFusionError_t;

// message ID 0x118 AtmelTeleopError
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t NotSpecified :1;
		} signals;
	} raw;
} AtmelTeleopError_t;

// message ID 0x11C AtmelSecurityError
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t NotSpecified :1;
		} signals;
	} raw;
} AtmelSecurityError_t;

// message ID 0x400 BatteryStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t main :16;    //V
			uint64_t controller :8;    //V
			uint64_t frontSteering :8;    //V
			uint64_t rearSteering :8;    //V
			uint64_t door :8;    //V
		} signals;
	} raw;
    double main;
    double controller;
    double frontSteering;
    double rearSteering;
    double door;
} BatteryStatusMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void BatteryStatusMsg_ToCan(BatteryStatusMsg_t * msg) 
{ 
    assert(msg->main <= 150.0);
    assert(msg->controller <= 14.0);
    assert(msg->frontSteering <= 14.0);
    assert(msg->rearSteering <= 14.0);
    assert(msg->door <= 14.0);
    assert(msg->main >= 0);
    msg->raw.signals.main = RoundLimitUnsigned(msg->main, 0.1, 16);
    assert(msg->controller >= 0);
    msg->raw.signals.controller = RoundLimitUnsigned(msg->controller, 0.1, 8);
    assert(msg->frontSteering >= 0);
    msg->raw.signals.frontSteering = RoundLimitUnsigned(msg->frontSteering, 0.1, 8);
    assert(msg->rearSteering >= 0);
    msg->raw.signals.rearSteering = RoundLimitUnsigned(msg->rearSteering, 0.1, 8);
    assert(msg->door >= 0);
    msg->raw.signals.door = RoundLimitUnsigned(msg->door, 0.1, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void BatteryStatusMsg_FromCan(BatteryStatusMsg_t * msg) 
{ 
    msg->main = msg->raw.signals.main * 0.1;
    msg->controller = msg->raw.signals.controller * 0.1;
    msg->frontSteering = msg->raw.signals.frontSteering * 0.1;
    msg->rearSteering = msg->raw.signals.rearSteering * 0.1;
    msg->door = msg->raw.signals.door * 0.1;
}
// message ID 0x28 ErrorFooting1
// message ID 0x29 ErrorFooting2
enum FootMsgErrorCode
{
	Foot_Extend = 0,
	Foot_Retract,
	Foot_Hw_Version,
	Foot_Time_Out,
	Foot_Retract_High_Current,
	Foot_No_Current,
	Foot_Short_Movement,
	Foot_Safety_Relay_Open,
	Foot_Drv_Info_Comms,
	//always add error codes above this
	Foot_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t FootExtendError :1;
			uint64_t FootRetractError :1;
			uint64_t FootHwVersionError :1;
			uint64_t FootTimeOut :1;
			uint64_t FootRetractHighCurrent :1;
			uint64_t FootNoCurrent :1;
			uint64_t FootShortMovement :1;
			uint64_t FootSafetyRelayOpen :1;
			uint64_t FootDrvInfoCommsError :1;
		} signals;
	} raw;
} ErrorFootMsg_t;

// message ID 0x2A ErrorSecurity
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t code :64;
		} signals;
	} raw;
} ErrorSecurity_t;

// message ID 0x324 SecuritySpeedMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxSpeed :16;    //mm/s
		} signals;
	} raw;
} SecuritySpeedMsg_t;

// message ID 0x60A SecurityWarningMsg
enum SecurityWarningMsgErrorCode
{
	collision_Comms_Delay = 0,
	collision_Comms_Missing,
	//always add warning codes above this
	collision_NumWarningCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t collisionCommsDelay :1;
			uint64_t collisionCommsMissing :1;
		} signals;
	} raw;
} SecurityWarningMsg_t;

// message ID 0x2D ErrorNetwork
enum NetworkErrorCode
{
	network_duplicate_board = 0,
	network_safety_relay_open,
	network_drv_info_comms,
	//always add error codes above this
	network_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t network_duplicate_board :1;
			uint64_t network_safety_relay_open :1;
			uint64_t network_drv_info_comms_error :1;
		} signals;
	} raw;
} ErrorNetwork_t;

// message ID 0x2E ErrorAccessory1
// message ID 0x2F ErrorAccessory2
enum AccessoryErrorCode
{
	Accessory_Incorrect_PCB = 0,
	Accessory_Non_Unique_ID,
	Accessory_Relay_Open,
	Accessory_Drv_Info_Comms,
	//always add error codes above this
	Accessory_NumErrorCodes,
};


typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t AccessoryIncorrectPCB :1;    //Accessory
			uint64_t AccessoryNonUniqueID :1;    //Accessory
			uint64_t AccessoryRelayOpen :1;    //Accessory
			uint64_t AccessoryDrvInfoComms :1;
		} signals;
	} raw;
} ErrorAccessory_t;

// message ID 0x217 LidarLatitudeUndelayed
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Latitude :36;    //degrees
			uint64_t CompassHeading :16;    //degrees
			uint64_t Available :1;
			uint64_t reserved :9;
			uint64_t sync :2;
		} signals;
	} raw;
    double Latitude;
    double CompassHeading;
} LidarLatitudeUndelayed_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LidarLatitudeUndelayed_ToCan(LidarLatitudeUndelayed_t * msg) 
{ 
    assert(msg->Latitude >= -90 && msg->Latitude <= 90);
    assert(msg->CompassHeading <= 360);
    assert(msg->raw.signals.Available <= 1);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.Latitude = RoundLimitSigned(msg->Latitude, 0.00000001, 36);
    assert(msg->CompassHeading >= 0);
    msg->raw.signals.CompassHeading = RoundLimitUnsigned(msg->CompassHeading, 0.1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LidarLatitudeUndelayed_FromCan(LidarLatitudeUndelayed_t * msg) 
{ 
    msg->Latitude = msg->raw.signals.Latitude * 0.00000001;
    msg->CompassHeading = msg->raw.signals.CompassHeading * 0.1;
}
// message ID 0x218 LidarLongitudeUndelayed
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Longitude :36;    //degrees
			uint64_t StepsBack :4;
			uint64_t reserved :22;
			uint64_t sync :2;
		} signals;
	} raw;
    double Longitude;
} LidarLongitudeUndelayed_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LidarLongitudeUndelayed_ToCan(LidarLongitudeUndelayed_t * msg) 
{ 
    assert(msg->Longitude >= -180 && msg->Longitude <= 180);
    assert(msg->raw.signals.StepsBack <= 1);
    assert(msg->raw.signals.sync <= 3);
    msg->raw.signals.Longitude = RoundLimitSigned(msg->Longitude, 0.00000001, 36);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void LidarLongitudeUndelayed_FromCan(LidarLongitudeUndelayed_t * msg) 
{ 
    msg->Longitude = msg->raw.signals.Longitude * 0.00000001;
}
// message ID 0x701 OdometryParameters
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t FrontOffset :8;    //degrees
			uint64_t FrontScale :8;
			int64_t RearOffset :8;    //degrees
			uint64_t RearScale :8;
			uint64_t WheelSpeedScale :8;
			uint64_t startupCount :14;
			uint64_t adaptiveCount :10;
		} signals;
	} raw;
    double FrontOffset;
    double FrontScale;
    double RearOffset;
    double RearScale;
    double WheelSpeedScale;
} OdometryParameters_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void OdometryParameters_ToCan(OdometryParameters_t * msg) 
{ 
    assert(msg->FrontOffset >= -5 && msg->FrontOffset <= 5);
    assert(msg->FrontScale >= 0.9 && msg->FrontScale <= 1.1);
    assert(msg->RearOffset >= -5 && msg->RearOffset <= 5);
    assert(msg->RearScale >= 0.9 && msg->RearScale <= 1.1);
    assert(msg->WheelSpeedScale >= 0.9 && msg->WheelSpeedScale <= 1.1);
    msg->raw.signals.FrontOffset = RoundLimitSigned(msg->FrontOffset, 0.0394, 8);
    assert(msg->FrontScale - 0.9 >= 0);
    msg->raw.signals.FrontScale = RoundLimitUnsigned(msg->FrontScale - 0.9, 0.00078432, 8);
    msg->raw.signals.RearOffset = RoundLimitSigned(msg->RearOffset, 0.0394, 8);
    assert(msg->RearScale - 0.9 >= 0);
    msg->raw.signals.RearScale = RoundLimitUnsigned(msg->RearScale - 0.9, 0.00078432, 8);
    assert(msg->WheelSpeedScale - 0.9 >= 0);
    msg->raw.signals.WheelSpeedScale = RoundLimitUnsigned(msg->WheelSpeedScale - 0.9, 0.00078432, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void OdometryParameters_FromCan(OdometryParameters_t * msg) 
{ 
    msg->FrontOffset = msg->raw.signals.FrontOffset * 0.0394;
    msg->FrontScale = msg->raw.signals.FrontScale * 0.00078432 + 0.9;
    msg->RearOffset = msg->raw.signals.RearOffset * 0.0394;
    msg->RearScale = msg->raw.signals.RearScale * 0.00078432 + 0.9;
    msg->WheelSpeedScale = msg->raw.signals.WheelSpeedScale * 0.00078432 + 0.9;
}
// message ID 0x423 AtmelUpdateRespMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t action :8;
			uint64_t address :16;
			uint64_t ACK :8;
			uint64_t major :8;
			uint64_t minor :8;
			uint64_t checksum :16;
		} signals;
	} raw;
} AtmelUpdateRespMsg_t;

// message ID 0x751 PlatoonSimMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t speed :32;    //mm/s
			uint64_t subWaypoint :32;
		} signals;
	} raw;
    double speed;
} PlatoonSimMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void PlatoonSimMsg_ToCan(PlatoonSimMsg_t * msg) 
{ 
    msg->raw.signals.speed = RoundLimitSigned(msg->speed, 1, 32);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void PlatoonSimMsg_FromCan(PlatoonSimMsg_t * msg) 
{ 
    msg->speed = msg->raw.signals.speed * 1.0;
}
// message ID 0x125 FrontPointDist
// message ID 0x126 RearPointDist
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t L1_dist :16;    //mm
			uint64_t L1_num_total :4;
			uint64_t L1_num_avg :4;
			uint64_t reserved :8;
			uint64_t L2_dist :16;    //mm
			uint64_t L2_num_total :4;
			uint64_t L2_num_avg :4;
		} signals;
	} raw;
} PointDistanceMsg_t;

// message ID 0x1A0 PlatoonDriveMsg
// message ID 0x1A1 Vehicle1CommsMsg
// message ID 0x1A2 Vehicle2CommsMsg
// message ID 0x1A3 Vehicle3CommsMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :4;
			uint64_t waypoint :16;
			int64_t speed :16;    //mm/s
			uint64_t reserved :4;
			uint64_t Time_Sync :24;    //ms
		} signals;
	} raw;
    double waypoint;
    double speed;
} InterVehicleCommsMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void InterVehicleCommsMsg_ToCan(InterVehicleCommsMsg_t * msg) 
{ 
    assert(msg->waypoint >= 0);
    msg->raw.signals.waypoint = RoundLimitUnsigned(msg->waypoint, 0.1, 16);
    msg->raw.signals.speed = RoundLimitSigned(msg->speed, 1, 16);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void InterVehicleCommsMsg_FromCan(InterVehicleCommsMsg_t * msg) 
{ 
    msg->waypoint = msg->raw.signals.waypoint * 0.1;
    msg->speed = msg->raw.signals.speed * 1.0;
}
// message ID 0x664 platStartTxMsg
// message ID 0x674 platStartRxMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t path :8;
			uint64_t speed :8;    //mm/s
			uint64_t checksum :8;
		} signals;
	} raw;
    double speed;
} PlatStartMsg_t;
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void PlatStartMsg_ToCan(PlatStartMsg_t * msg) 
{ 
    assert(msg->speed >= 0);
    msg->raw.signals.speed = RoundLimitUnsigned(msg->speed, 100, 8);
}
/* 2-4 merge: BK function definition activated from OhmioLibraries_BK. */
static void PlatStartMsg_FromCan(PlatStartMsg_t * msg) 
{ 
    msg->speed = msg->raw.signals.speed * 100 * 1.0;
}


#endif //main_DBC_TOOL_GENERATED_H
