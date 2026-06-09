#ifndef main_DBC_TOOL_GENERATED_H
#define main_DBC_TOOL_GENERATED_H

#include <stdint.h>
#include "additionalDbcCan.h"
#include "dbc_MsgID_main.h"


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


void UBXPart1Msg_ToCan(UBXPart1Msg_t * msg) ;

void UBXPart1Msg_FromCan(UBXPart1Msg_t * msg) ;

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


void UBXPart2Msg_ToCan(UBXPart2Msg_t * msg) ;

void UBXPart2Msg_FromCan(UBXPart2Msg_t * msg) ;

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


void WheelSpeedMsg_ToCan(WheelSpeedMsg_t * msg) ;

void WheelSpeedMsg_FromCan(WheelSpeedMsg_t * msg) ;

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


void WheelSpeedEvents_ToCan(WheelSpeedEvents_t * msg) ;

void WheelSpeedEvents_FromCan(WheelSpeedEvents_t * msg) ;

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


void EPBStatusMsg_ToCan(EPBStatusMsg_t * msg) ;

void EPBStatusMsg_FromCan(EPBStatusMsg_t * msg) ;

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


void ConfigRespMsg_ToCan(ConfigRespMsg_t * msg) ;

void ConfigRespMsg_FromCan(ConfigRespMsg_t * msg) ;

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


void ParameterConfMsg_ToCan(ParameterConfMsg_t * msg) ;

void ParameterConfMsg_FromCan(ParameterConfMsg_t * msg) ;

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


void ParameterConfSignMsg_ToCan(ParameterConfSignMsg_t * msg) ;

void ParameterConfSignMsg_FromCan(ParameterConfSignMsg_t * msg) ;

// message ID 0x320 SystemReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :6;
			uint64_t reserved :2;
			uint64_t path :8;
			uint64_t maxSpeed :16;    //m/s
			uint64_t reserved1 :28;
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


void SteerCalibrationMsg_ToCan(SteerCalibrationMsg_t * msg) ;

void SteerCalibrationMsg_FromCan(SteerCalibrationMsg_t * msg) ;

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


void SteerMsg_ToCan(SteerMsg_t * msg) ;

void SteerMsg_FromCan(SteerMsg_t * msg) ;

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


void TrafficLightMsg_ToCan(TrafficLightMsg_t * msg) ;

void TrafficLightMsg_FromCan(TrafficLightMsg_t * msg) ;

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


void BMSStatusStdMsg_ToCan(BMSStatusStdMsg_t * msg) ;

void BMSStatusStdMsg_FromCan(BMSStatusStdMsg_t * msg) ;

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


void SteeringStatusMsg_ToCan(SteeringStatusMsg_t * msg) ;

void SteeringStatusMsg_FromCan(SteeringStatusMsg_t * msg) ;

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


void SteeringRespMsg_ToCan(SteeringRespMsg_t * msg) ;

void SteeringRespMsg_FromCan(SteeringRespMsg_t * msg) ;

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


void EHBPowerMsg_ToCan(EHBPowerMsg_t * msg) ;

void EHBPowerMsg_FromCan(EHBPowerMsg_t * msg) ;

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


void EHBT060PowerMsg_ToCan(EHBT060PowerMsg_t * msg) ;

void EHBT060PowerMsg_FromCan(EHBT060PowerMsg_t * msg) ;

// message ID 0x180 ManualDriveMsg
// message ID 0x185 LocManualMsg
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


void ManualDriveMsg_ToCan(ManualDriveMsg_t * msg) ;

void ManualDriveMsg_FromCan(ManualDriveMsg_t * msg) ;

// message ID 0x181 JoystickMsg
// message ID 0x186 LocJoystickMsg
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


void EHBReqMsg_ToCan(EHBReqMsg_t * msg) ;

void EHBReqMsg_FromCan(EHBReqMsg_t * msg) ;

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


void MotorReqMsg_ToCan(MotorReqMsg_t * msg) ;

void MotorReqMsg_FromCan(MotorReqMsg_t * msg) ;

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


void SteeringReqMsg_ToCan(SteeringReqMsg_t * msg) ;

void SteeringReqMsg_FromCan(SteeringReqMsg_t * msg) ;

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


void Speed2TorqueReqMsg_ToCan(Speed2TorqueReqMsg_t * msg) ;

void Speed2TorqueReqMsg_FromCan(Speed2TorqueReqMsg_t * msg) ;

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


void DriveInfoLongWpMsg_ToCan(DriveInfoLongWpMsg_t * msg) ;

void DriveInfoLongWpMsg_FromCan(DriveInfoLongWpMsg_t * msg) ;

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


void OdometerMsg_ToCan(OdometerMsg_t * msg) ;

void OdometerMsg_FromCan(OdometerMsg_t * msg) ;

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


void Speed2TorqueRespMsg_ToCan(Speed2TorqueRespMsg_t * msg) ;

void Speed2TorqueRespMsg_FromCan(Speed2TorqueRespMsg_t * msg) ;

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

// message ID 0x120 Obsolte_ObsLidarMsg
// message ID 0x121 Obsolete_UltraSoundMsg
// message ID 0x160 Obsolete_BrakeReqMsg
// message ID 0x220 Obsolete_latitudeFrontMsg
// message ID 0x221 Obsolete_longitudeFrontMsg
// message ID 0x222 Obsolete_heightFrontMsg
// message ID 0x223 Obsolete_combineHeightFrontMsg
// message ID 0x230 Obsolete_latitudeBackMsg
// message ID 0x231 Obsolete_longitudeBackMsg
// message ID 0x232 Obsolete_heightBackMsg
// message ID 0x233 Obsolete_HeadingMsg
// message ID 0x234 Obsolete_combineHeightBackMsg
// message ID 0x250 Obsolete_UWBDistanceMsg
// message ID 0x251 Obsolete_UWBLatitudeMsg
// message ID 0x252 Obsolete_UWBLongitudeMsg
// message ID 0x260 Obsolete_CompassMsg
// message ID 0x321 Obsolete_DriveInfoMsg
// message ID 0x710 Obsolete_LogIndMsg
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


void ObstacleEmergency_ToCan(ObstacleEmergency_t * msg) ;

void ObstacleEmergency_FromCan(ObstacleEmergency_t * msg) ;

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


void ObstacleDangerZoneMsg_ToCan(ObstacleDangerZoneMsg_t * msg) ;

void ObstacleDangerZoneMsg_FromCan(ObstacleDangerZoneMsg_t * msg) ;

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


void ObstacleTrackDistanceMsg_ToCan(ObstacleTrackDistanceMsg_t * msg) ;

void ObstacleTrackDistanceMsg_FromCan(ObstacleTrackDistanceMsg_t * msg) ;

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


void LidarSpeed_ToCan(LidarSpeed_t * msg) ;

void LidarSpeed_FromCan(LidarSpeed_t * msg) ;

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


void ObsLatitudeMsg_ToCan(ObsLatitudeMsg_t * msg) ;

void ObsLatitudeMsg_FromCan(ObsLatitudeMsg_t * msg) ;

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


void ObsLongitudeMsg_ToCan(ObsLongitudeMsg_t * msg) ;

void ObsLongitudeMsg_FromCan(ObsLongitudeMsg_t * msg) ;

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


void ObsHeadingMsg_ToCan(ObsHeadingMsg_t * msg) ;

void ObsHeadingMsg_FromCan(ObsHeadingMsg_t * msg) ;

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


void ObsTrackOffsetMsg_ToCan(ObsTrackOffsetMsg_t * msg) ;

void ObsTrackOffsetMsg_FromCan(ObsTrackOffsetMsg_t * msg) ;

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


void LatitudeMsg_ToCan(LatitudeMsg_t * msg) ;

void LatitudeMsg_FromCan(LatitudeMsg_t * msg) ;

// message ID 0x211 FusionLongitudeFront
// message ID 0x214 FusionLongitudeRear
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


void LongitudeMsg_ToCan(LongitudeMsg_t * msg) ;

void LongitudeMsg_FromCan(LongitudeMsg_t * msg) ;

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


void FusionInfoMsg_ToCan(FusionInfoMsg_t * msg) ;

void FusionInfoMsg_FromCan(FusionInfoMsg_t * msg) ;

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


void FusionAcceMsg_ToCan(FusionAcceMsg_t * msg) ;

void FusionAcceMsg_FromCan(FusionAcceMsg_t * msg) ;

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
	fus_Reserved,
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
			uint64_t reserved :1;
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


void FusionBiasOutlierMsg_ToCan(FusionBiasOutlierMsg_t * msg) ;

void FusionBiasOutlierMsg_FromCan(FusionBiasOutlierMsg_t * msg) ;

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


void VehicleInfoMsg_ToCan(VehicleInfoMsg_t * msg) ;

void VehicleInfoMsg_FromCan(VehicleInfoMsg_t * msg) ;

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


void FusionFrontLatitude_ToCan(FusionFrontLatitude_t * msg) ;

void FusionFrontLatitude_FromCan(FusionFrontLatitude_t * msg) ;

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


void FusionRearLatitude_ToCan(FusionRearLatitude_t * msg) ;

void FusionRearLatitude_FromCan(FusionRearLatitude_t * msg) ;

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


void FusionRearLongitude_ToCan(FusionRearLongitude_t * msg) ;

void FusionRearLongitude_FromCan(FusionRearLongitude_t * msg) ;

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


void FusionHeight_ToCan(FusionHeight_t * msg) ;

void FusionHeight_FromCan(FusionHeight_t * msg) ;

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
			uint64_t reserved :1;
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


void IMUMag_ToCan(IMUMag_t * msg) ;

void IMUMag_FromCan(IMUMag_t * msg) ;

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


void IMURot_ToCan(IMURot_t * msg) ;

void IMURot_FromCan(IMURot_t * msg) ;

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


void IMUAcc_ToCan(IMUAcc_t * msg) ;

void IMUAcc_FromCan(IMUAcc_t * msg) ;

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


void IMUGyr_ToCan(IMUGyr_t * msg) ;

void IMUGyr_FromCan(IMUGyr_t * msg) ;

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


void MotorStatus_ToCan(MotorStatus_t * msg) ;

void MotorStatus_FromCan(MotorStatus_t * msg) ;

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


void Motor3Status2_ToCan(Motor3Status2_t * msg) ;

void Motor3Status2_FromCan(Motor3Status2_t * msg) ;

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


void Motor3Status5_ToCan(Motor3Status5_t * msg) ;

void Motor3Status5_FromCan(Motor3Status5_t * msg) ;

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


void Motor3Status6_ToCan(Motor3Status6_t * msg) ;

void Motor3Status6_FromCan(Motor3Status6_t * msg) ;

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


void ErrorSteering_ToCan(ErrorSteering_t * msg) ;

void ErrorSteering_FromCan(ErrorSteering_t * msg) ;

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


void ErrorEHBT060_ToCan(ErrorEHBT060_t * msg) ;

void ErrorEHBT060_FromCan(ErrorEHBT060_t * msg) ;

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


void BatteryStatusMsg_ToCan(BatteryStatusMsg_t * msg) ;

void BatteryStatusMsg_FromCan(BatteryStatusMsg_t * msg) ;

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


void LidarLatitudeUndelayed_ToCan(LidarLatitudeUndelayed_t * msg) ;

void LidarLatitudeUndelayed_FromCan(LidarLatitudeUndelayed_t * msg) ;

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


void LidarLongitudeUndelayed_ToCan(LidarLongitudeUndelayed_t * msg) ;

void LidarLongitudeUndelayed_FromCan(LidarLongitudeUndelayed_t * msg) ;

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


void OdometryParameters_ToCan(OdometryParameters_t * msg) ;

void OdometryParameters_FromCan(OdometryParameters_t * msg) ;

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


void PlatoonSimMsg_ToCan(PlatoonSimMsg_t * msg) ;

void PlatoonSimMsg_FromCan(PlatoonSimMsg_t * msg) ;

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


void InterVehicleCommsMsg_ToCan(InterVehicleCommsMsg_t * msg) ;

void InterVehicleCommsMsg_FromCan(InterVehicleCommsMsg_t * msg) ;

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


void PlatStartMsg_ToCan(PlatStartMsg_t * msg) ;

void PlatStartMsg_FromCan(PlatStartMsg_t * msg) ;

#endif //main_DBC_TOOL_GENERATED_H
