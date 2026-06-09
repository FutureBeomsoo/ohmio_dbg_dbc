#ifndef peripheral_DBC_TOOL_GENERATED_H
#define peripheral_DBC_TOOL_GENERATED_H
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include "ConversionHelper.h"
#include "dbc_MsgID_peripheral.h"


// message ID 0xC66F4F5 BMSReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t reserved :48;
			uint64_t counter :8;
		} signals;
	} raw;
} BMSReqMsg_t;

// message ID 0x10200000 voiceReq
// message ID 0x1020000F voiceResp
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t command :8;
			uint64_t value :8;
		} signals;
	} raw;
} VoiceMsg_t;

// message ID 0x10300100 FrontMainLightReqMsg
// message ID 0x1030010F FrontMainLightStatusMsg
// message ID 0x10300110 FrontDipLightReqMsg
// message ID 0x1030011F FrontDipLightStatusMsg
// message ID 0x10300120 FrontDayLightReqMsg
// message ID 0x1030012F FrontDayLightStatusMsg
// message ID 0x10300130 FrontPosOutlineMarkerReqMsg
// message ID 0x1030013F FrontPosOutlineMarkerStatusMsg
// message ID 0x10300200 RearReverseLightReqMsg
// message ID 0x1030020F RearReverseLightStatusMsg
// message ID 0x10300210 RearTailOutlineMarkerReqMsg
// message ID 0x1030021F RearTailOutlineMarkerStatusMsg
// message ID 0x10300220 RearRegLightReqMsg
// message ID 0x1030022F RearRegLightStatusMsg
// message ID 0x10300300 HornReqMsg
// message ID 0x1030030F HornStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t on :8;
		} signals;
	} raw;
} LightMsg_t;

// message ID 0x10400000 FrontLightReq
// message ID 0x10400007 FrontLightStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mainLeft :8;
			uint64_t mainRight :8;
			uint64_t logo :8;
			uint64_t reserved :8;
			uint64_t internalPWM :8;
		} signals;
	} raw;
} FrontLightMsg_t;

// message ID 0x10400008 RearLightReq
// message ID 0x1040000F RearLightStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mainLeft :8;
			uint64_t mainRight :8;
			uint64_t logo :8;
			uint64_t audio :8;
			uint64_t reserved :16;
			uint64_t horn :8;
			uint64_t flash :8;
		} signals;
	} raw;
} RearLightMsg_t;

// message ID 0x10400010 OvalFrontLeftStatus
// message ID 0x10400020 OvalFrontRightStatus
// message ID 0x10400030 OvalRearLeftStatus
// message ID 0x10400040 OvalRearRightStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t fixBright :8;
			uint64_t redBright :8;
			uint64_t greenBright :8;
			uint64_t blueBright :8;
			uint64_t redError :8;
			uint64_t greenError :8;
			uint64_t blueError :8;
		} signals;
	} raw;
} OvalLightStatusMsg_t;

// message ID 0x1040001F OvalFrontLeftReq
// message ID 0x1040002F OvalFrontRightReq
// message ID 0x1040003F OvalRearLeftReq
// message ID 0x1040004F OvalRearRightReq
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :8;
			uint64_t fixBright :8;
			uint64_t redBright :8;
			uint64_t greenBright :8;
			uint64_t blueBright :8;
		} signals;
	} raw;
} OvalLightReqMsg_t;

// message ID 0x10400107 DoorReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t heartbeat :8;
			uint64_t open :1;
			uint64_t close :1;
			uint64_t buttonEnable :1;
		} signals;
	} raw;
} DoorReqMsg_t;

// message ID 0x10600000 FootReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t request :8;
			uint64_t liftFire :8;
		} signals;
	} raw;
} FootReqMsg_t;

// message ID 0x18FF45F4 AirConReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :2;
			uint64_t level :2;
			uint64_t temperature :4;
		} signals;
	} raw;
    double temperature;
} AirConReqMsg_t;


static void AirConReqMsg_ToCan(AirConReqMsg_t * msg) 
{ 
    assert(msg->temperature >= 15 && msg->temperature <= 30);
    assert(msg->temperature - 15 >= 0);
    msg->raw.signals.temperature = RoundLimitUnsigned(msg->temperature - 15, 1, 4);
}

static void AirConReqMsg_FromCan(AirConReqMsg_t * msg) 
{ 
    msg->temperature = msg->raw.signals.temperature * 1.0 + 15;
}



// message ID 0x1050010 AVASReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t speed :8;    //km/h
			uint64_t reverse :1;
			uint64_t reserved :39;
			uint64_t count :8;
			uint64_t checksum :8;
		} signals;
	} raw;
    double speed;
} AVASReqMsg_t;


static void AVASReqMsg_ToCan(AVASReqMsg_t * msg) 
{ 
    assert(msg->speed <= 50);
    assert(msg->raw.signals.reverse <= 1);
    assert(msg->raw.signals.count <= 255);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->speed >= 0);
    msg->raw.signals.speed = RoundLimitUnsigned(msg->speed, 0.2, 8);
}

static void AVASReqMsg_FromCan(AVASReqMsg_t * msg) 
{ 
    msg->speed = msg->raw.signals.speed * 0.2;
}



// message ID 0x1B001000 DTGSpeedRpmMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t motorRPM :16;    //rpm
			uint64_t speed :8;    //km/h
		} signals;
	} raw;
    double motorRPM;
} DTGSpeedRpmMsg_t;


static void DTGSpeedRpmMsg_ToCan(DTGSpeedRpmMsg_t * msg) 
{ 
    assert(msg->raw.signals.speed <= 255);
    msg->raw.signals.motorRPM = RoundLimitSigned(msg->motorRPM, 1, 16);
}

static void DTGSpeedRpmMsg_FromCan(DTGSpeedRpmMsg_t * msg) 
{ 
    msg->motorRPM = msg->raw.signals.motorRPM * 1.0;
}



// message ID 0x1B001010 DTGBrakeInfoMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t EHBReqPressure :8;    //bar
			uint64_t EHBActualPressure :8;    //bar
			uint64_t EHBError :8;
			uint64_t reserved :8;
			uint64_t EPBReq :8;
			uint64_t EPBLeftStatus :8;
			uint64_t EPBRightStatus :8;
		} signals;
	} raw;
} DTGBrakeInfoMsg_t;

// message ID 0x1D000100 PeripheralVersionReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t id :16;
		} signals;
	} raw;
} PeripheralVersionReqMsg_t;

// message ID 0x10400100 DoorStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t heartbeat :8;
			uint64_t opening :1;
			uint64_t closing :1;
			uint64_t opened :1;
			uint64_t closed :1;
			uint64_t openTimeout :1;
			uint64_t closeTimeout :1;
			uint64_t buttonEnable :1;
			uint64_t reserved :1;
			uint64_t doorLock :1;
			uint64_t doorClamp :1;
			uint64_t fault1 :1;
			uint64_t fault2 :1;
			uint64_t buttonPressed :1;
			uint64_t reserved1 :3;
			uint64_t dcdcVolt :16;    //V
			uint64_t battVolt :16;    //V
		} signals;
	} raw;
    double dcdcVolt;
    double battVolt;
} DoorStatusMsg_t;


static void DoorStatusMsg_ToCan(DoorStatusMsg_t * msg) 
{ 
    assert(msg->raw.signals.heartbeat <= 255);
    assert(msg->raw.signals.opening <= 1);
    assert(msg->raw.signals.closing <= 1);
    assert(msg->raw.signals.opened <= 1);
    assert(msg->raw.signals.closed <= 1);
    assert(msg->raw.signals.openTimeout <= 1);
    assert(msg->raw.signals.closeTimeout <= 1);
    assert(msg->raw.signals.buttonEnable <= 1);
    assert(msg->raw.signals.doorLock <= 1);
    assert(msg->raw.signals.doorClamp <= 1);
    assert(msg->raw.signals.fault1 <= 1);
    assert(msg->raw.signals.fault2 <= 1);
    assert(msg->raw.signals.buttonPressed <= 1);
    assert(msg->dcdcVolt >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->dcdcVolt, 0.049, 16);
    msg->raw.signals.dcdcVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->battVolt >= 0);
    temp = RoundLimitUnsigned(msg->battVolt, 0.049, 16);
    msg->raw.signals.battVolt = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void DoorStatusMsg_FromCan(DoorStatusMsg_t * msg) 
{ 
    msg->dcdcVolt = ((msg->raw.signals.dcdcVolt >> 8) + ((msg->raw.signals.dcdcVolt & 0xFF) << 8)) * 0.049;
    msg->battVolt = ((msg->raw.signals.battVolt >> 8) + ((msg->raw.signals.battVolt & 0xFF) << 8)) * 0.049;
}



// message ID 0x10600010 Foot1Status
typedef struct{ 
	union
	{ 
		uint8_t buf[5];
		struct
		{
			uint64_t status :8;
			uint64_t mode :8;
			uint64_t error :8;
			uint64_t current :16;    //A
		} signals;
	} raw;
    double current;
} Foot1Status_t;


static void Foot1Status_ToCan(Foot1Status_t * msg) 
{ 
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.mode <= 2);
    assert(msg->raw.signals.error <= 1);
    assert(msg->current <= 30);
    assert(msg->current >= 0);
    msg->raw.signals.current = RoundLimitUnsigned(msg->current, 0.01, 16);
}

static void Foot1Status_FromCan(Foot1Status_t * msg) 
{ 
    msg->current = msg->raw.signals.current * 0.01;
}



// message ID 0x10600020 Foot2Status
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
			uint64_t liftFireStatus :1;
			uint64_t reserved :7;
			uint64_t liftOutStatus :1;
		} signals;
	} raw;
    double current;
} Foot2Status_t;


static void Foot2Status_ToCan(Foot2Status_t * msg) 
{ 
    assert(msg->raw.signals.status <= 3);
    assert(msg->raw.signals.mode <= 2);
    assert(msg->raw.signals.error <= 1);
    assert(msg->current <= 30);
    assert(msg->raw.signals.liftFireStatus <= 1);
    assert(msg->raw.signals.liftOutStatus <= 1);
    assert(msg->current >= 0);
    msg->raw.signals.current = RoundLimitUnsigned(msg->current, 0.01, 16);
}

static void Foot2Status_FromCan(Foot2Status_t * msg) 
{ 
    msg->current = msg->raw.signals.current * 0.01;
}



// message ID 0x10400201 StepReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t in :1;
			uint64_t out :1;
			uint64_t reserved :46;
			uint64_t count :8;
			uint64_t checksum :8;
		} signals;
	} raw;
} StepReqMsg_t;

// message ID 0x10400208 StepStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t status :3;
			uint64_t motorFault :1;
			uint64_t overCurrent :1;
			uint64_t overWeight :1;
			uint64_t reserved :10;
			uint64_t current :8;    //A
			uint64_t voltage :8;    //V
			uint64_t reserved1 :16;
			uint64_t count :8;
			uint64_t checksum :8;
		} signals;
	} raw;
    double current;
    double voltage;
} StepStatusMsg_t;


static void StepStatusMsg_ToCan(StepStatusMsg_t * msg) 
{ 
    assert(msg->raw.signals.status <= 4);
    assert(msg->raw.signals.motorFault <= 1);
    assert(msg->raw.signals.overCurrent <= 1);
    assert(msg->raw.signals.overWeight <= 1);
    assert(msg->current <= 25.5);
    assert(msg->voltage <= 25.5);
    assert(msg->raw.signals.count <= 255);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->current >= 0);
    msg->raw.signals.current = RoundLimitUnsigned(msg->current, 0.1, 8);
    assert(msg->voltage >= 0);
    msg->raw.signals.voltage = RoundLimitUnsigned(msg->voltage, 0.1, 8);
}

static void StepStatusMsg_FromCan(StepStatusMsg_t * msg) 
{ 
    msg->current = msg->raw.signals.current * 0.1;
    msg->voltage = msg->raw.signals.voltage * 0.1;
}



// message ID 0x10700000 Wiper1ReqMsg
// message ID 0x1070000F Wiper1StatusMsg
// message ID 0x10700010 Wiper2ReqMsg
// message ID 0x1070001F Wiper2StatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t mode :4;
			uint64_t washer :1;
			uint64_t reserved :3;
			uint64_t interval :8;    //sec
		} signals;
	} raw;
    double interval;
} WiperMsg_t;


static void WiperMsg_ToCan(WiperMsg_t * msg) 
{ 
    assert(msg->interval >= 0);
    msg->raw.signals.interval = RoundLimitUnsigned(msg->interval, 0.1, 8);
}

static void WiperMsg_FromCan(WiperMsg_t * msg) 
{ 
    msg->interval = msg->raw.signals.interval * 0.1;
}



// message ID 0x1082F5F4 BMSStatusMsg1
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t errorLevel :2;
			uint64_t status :4;
			uint64_t quickChargeReq :1;
			uint64_t slowChargeReq :1;
			uint64_t insulationError :2;
			uint64_t overCurrent :2;
			uint64_t overTemp :2;
			uint64_t unevenTemp :2;
			uint64_t unbalanceVolt :2;
			uint64_t lowSOC :2;
			uint64_t highSOC :2;
			uint64_t lowTemp :2;
			uint64_t highInrushCurrent :2;
			uint64_t highVolt :2;
			uint64_t lowVolt :2;
			uint64_t highCellVolt :2;
			uint64_t lowCellVolt :2;
			uint64_t highFeedbackCurrent :2;
			uint64_t currentSensorError :1;
			uint64_t commsError :1;
			uint64_t TempSensorError :1;
			uint64_t slowChargeOverCurrent :1;
			uint64_t prechargeError :1;
			uint64_t chargeInterlockError :1;
			uint64_t dischargeInterlockError :1;
			uint64_t positiveRelayError :1;
			uint64_t negativeRelayError :1;
			uint64_t voltSamplingLineBroke :1;
			uint64_t reserved :1;
			uint64_t batteryPackUnmatch :1;
			uint64_t internalCommsError :1;
			uint64_t cellVoltSamplingLineBroke :1;
			uint64_t tempSamplingLineBroke :1;
			uint64_t currentSamplingLineBroke :1;
			uint64_t fastChargeCommsError :1;
			uint64_t carChargeCommsError :1;
			uint64_t continuousDischargeOverCurrent :2;
			uint64_t counter :8;
		} signals;
	} raw;
} BMSStatusMsg1_t;

// message ID 0x1083F5F4 BMSStatusMsg2
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t voltage :16;    //V
			uint64_t DCLinkVolt :16;    //V
			uint64_t DCCurrent :16;    //A
			uint64_t chargerPlugOverTemp :1;
			uint64_t chargerPlugTempLineBroke :1;
			uint64_t heatRelayError :1;
			uint64_t heatCircuitError :1;
			uint64_t reserved :4;
			uint64_t counter :8;
		} signals;
	} raw;
    double voltage;
    double DCLinkVolt;
    double DCCurrent;
} BMSStatusMsg2_t;


static void BMSStatusMsg2_ToCan(BMSStatusMsg2_t * msg) 
{ 
    assert(msg->voltage <= 1000);
    assert(msg->DCLinkVolt <= 1000);
    assert(msg->DCCurrent >= -1000 && msg->DCCurrent <= 1000);
    assert(msg->raw.signals.chargerPlugOverTemp <= 1);
    assert(msg->raw.signals.chargerPlugTempLineBroke <= 1);
    assert(msg->raw.signals.heatRelayError <= 1);
    assert(msg->raw.signals.heatCircuitError <= 1);
    assert(msg->raw.signals.counter <= 255);
    assert(msg->voltage >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->voltage, 0.1, 16);
    msg->raw.signals.voltage = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->DCLinkVolt >= 0);
    temp = RoundLimitUnsigned(msg->DCLinkVolt, 0.1, 16);
    msg->raw.signals.DCLinkVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->DCCurrent + 1000 >= 0);
    temp = RoundLimitUnsigned(msg->DCCurrent + 1000, 0.1, 16);
    msg->raw.signals.DCCurrent = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg2_FromCan(BMSStatusMsg2_t * msg) 
{ 
    msg->voltage = ((msg->raw.signals.voltage >> 8) + ((msg->raw.signals.voltage & 0xFF) << 8)) * 0.1;
    msg->DCLinkVolt = ((msg->raw.signals.DCLinkVolt >> 8) + ((msg->raw.signals.DCLinkVolt & 0xFF) << 8)) * 0.1;
    msg->DCCurrent = ((msg->raw.signals.DCCurrent >> 8) + ((msg->raw.signals.DCCurrent & 0xFF) << 8)) * 0.1 - 1000;
}



// message ID 0x1084F5F4 BMSStatusMsg3
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxDisCur :16;    //A
			uint64_t maxChargeCur :16;    //A
			uint64_t constDisCur :16;    //A
			uint64_t constChargeCur :16;    //A
		} signals;
	} raw;
    double maxDisCur;
    double maxChargeCur;
    double constDisCur;
    double constChargeCur;
} BMSStatusMsg3_t;


static void BMSStatusMsg3_ToCan(BMSStatusMsg3_t * msg) 
{ 
    assert(msg->maxDisCur <= 1000);
    assert(msg->maxChargeCur <= 1000);
    assert(msg->constDisCur <= 1000);
    assert(msg->constChargeCur <= 1000);
    assert(msg->maxDisCur >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->maxDisCur, 0.1, 16);
    msg->raw.signals.maxDisCur = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->maxChargeCur >= 0);
    temp = RoundLimitUnsigned(msg->maxChargeCur, 0.1, 16);
    msg->raw.signals.maxChargeCur = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->constDisCur >= 0);
    temp = RoundLimitUnsigned(msg->constDisCur, 0.1, 16);
    msg->raw.signals.constDisCur = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->constChargeCur >= 0);
    temp = RoundLimitUnsigned(msg->constChargeCur, 0.1, 16);
    msg->raw.signals.constChargeCur = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg3_FromCan(BMSStatusMsg3_t * msg) 
{ 
    msg->maxDisCur = ((msg->raw.signals.maxDisCur >> 8) + ((msg->raw.signals.maxDisCur & 0xFF) << 8)) * 0.1;
    msg->maxChargeCur = ((msg->raw.signals.maxChargeCur >> 8) + ((msg->raw.signals.maxChargeCur & 0xFF) << 8)) * 0.1;
    msg->constDisCur = ((msg->raw.signals.constDisCur >> 8) + ((msg->raw.signals.constDisCur & 0xFF) << 8)) * 0.1;
    msg->constChargeCur = ((msg->raw.signals.constChargeCur >> 8) + ((msg->raw.signals.constChargeCur & 0xFF) << 8)) * 0.1;
}



// message ID 0x1085F5F4 BMSStatusMsg4
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t remainEnergy :16;    //kwh
			uint64_t soh :8;    //%
			uint64_t soc :8;    //%
			uint64_t insResistance :16;    //kOhm
			uint64_t posRelayClosed :1;
			uint64_t negRelayClosed :1;
			uint64_t preRelayClosed :1;
			uint64_t chargeRelayClosed :1;
			uint64_t fastChargeConnected :1;
			uint64_t heatRelayClosed :1;
			uint64_t disconnectReq :1;
			uint64_t slowChargeConnected :1;
			uint64_t counter :8;
		} signals;
	} raw;
    double remainEnergy;
    double soh;
    double soc;
    double insResistance;
} BMSStatusMsg4_t;


static void BMSStatusMsg4_ToCan(BMSStatusMsg4_t * msg) 
{ 
    assert(msg->remainEnergy <= 1000);
    assert(msg->soh <= 100);
    assert(msg->soc <= 100);
    assert(msg->insResistance <= 65535);
    assert(msg->raw.signals.posRelayClosed <= 1);
    assert(msg->raw.signals.negRelayClosed <= 1);
    assert(msg->raw.signals.preRelayClosed <= 1);
    assert(msg->raw.signals.chargeRelayClosed <= 1);
    assert(msg->raw.signals.fastChargeConnected <= 1);
    assert(msg->raw.signals.heatRelayClosed <= 1);
    assert(msg->raw.signals.disconnectReq <= 1);
    assert(msg->raw.signals.slowChargeConnected <= 1);
    assert(msg->raw.signals.counter <= 255);
    assert(msg->soh >= 0);
    msg->raw.signals.soh = RoundLimitUnsigned(msg->soh, 0.5, 8);
    assert(msg->soc >= 0);
    msg->raw.signals.soc = RoundLimitUnsigned(msg->soc, 0.5, 8);
    assert(msg->remainEnergy >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->remainEnergy, 0.1, 16);
    msg->raw.signals.remainEnergy = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->insResistance >= 0);
    temp = RoundLimitUnsigned(msg->insResistance, 1, 16);
    msg->raw.signals.insResistance = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg4_FromCan(BMSStatusMsg4_t * msg) 
{ 
    msg->soh = msg->raw.signals.soh * 0.5;
    msg->soc = msg->raw.signals.soc * 0.5;
    msg->remainEnergy = ((msg->raw.signals.remainEnergy >> 8) + ((msg->raw.signals.remainEnergy & 0xFF) << 8)) * 0.1;
    msg->insResistance = ((msg->raw.signals.insResistance >> 8) + ((msg->raw.signals.insResistance & 0xFF) << 8)) * 1.0;
}



// message ID 0x1086F5F4 BMSStatusMsg5
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t averageTemp :8;    //degrees
			uint64_t tempSensorNum :8;
			uint64_t maxTemp :8;    //degrees
			uint64_t minTemp :8;    //degrees
			uint64_t maxTempNum :8;
			uint64_t minTempNum :8;
			uint64_t cellSumNum :16;
		} signals;
	} raw;
    double averageTemp;
    double maxTemp;
    double minTemp;
    double cellSumNum;
} BMSStatusMsg5_t;


static void BMSStatusMsg5_ToCan(BMSStatusMsg5_t * msg) 
{ 
    assert(msg->averageTemp >= -100 && msg->averageTemp <= 150);
    assert(msg->raw.signals.tempSensorNum >= 1 && msg->raw.signals.tempSensorNum <= 255);
    assert(msg->maxTemp >= -100 && msg->maxTemp <= 150);
    assert(msg->minTemp >= -100 && msg->minTemp <= 150);
    assert(msg->raw.signals.maxTempNum >= 1 && msg->raw.signals.maxTempNum <= 255);
    assert(msg->raw.signals.minTempNum >= 1 && msg->raw.signals.minTempNum <= 255);
    assert(msg->cellSumNum >= 1 && msg->cellSumNum <= 65535);
    assert(msg->averageTemp + 100 >= 0);
    msg->raw.signals.averageTemp = RoundLimitUnsigned(msg->averageTemp + 100, 1, 8);
    assert(msg->maxTemp + 100 >= 0);
    msg->raw.signals.maxTemp = RoundLimitUnsigned(msg->maxTemp + 100, 1, 8);
    assert(msg->minTemp + 100 >= 0);
    msg->raw.signals.minTemp = RoundLimitUnsigned(msg->minTemp + 100, 1, 8);
    assert(msg->cellSumNum >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->cellSumNum, 1, 16);
    msg->raw.signals.cellSumNum = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg5_FromCan(BMSStatusMsg5_t * msg) 
{ 
    msg->averageTemp = msg->raw.signals.averageTemp * 1.0 - 100;
    msg->maxTemp = msg->raw.signals.maxTemp * 1.0 - 100;
    msg->minTemp = msg->raw.signals.minTemp * 1.0 - 100;
    msg->cellSumNum = ((msg->raw.signals.cellSumNum >> 8) + ((msg->raw.signals.cellSumNum & 0xFF) << 8)) * 1.0;
}



// message ID 0x1087F5F4 BMSStatusMsg6
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxCellVolt :16;    //mV
			uint64_t minCellVolt :16;    //mV
			uint64_t maxCellVoltNum :8;
			uint64_t minCellVoltNum :8;
			uint64_t averageCellVolt :16;    //mV
		} signals;
	} raw;
    double maxCellVolt;
    double minCellVolt;
    double averageCellVolt;
} BMSStatusMsg6_t;


static void BMSStatusMsg6_ToCan(BMSStatusMsg6_t * msg) 
{ 
    assert(msg->maxCellVolt <= 5000);
    assert(msg->minCellVolt <= 5000);
    assert(msg->raw.signals.maxCellVoltNum >= 1 && msg->raw.signals.maxCellVoltNum <= 255);
    assert(msg->raw.signals.minCellVoltNum >= 1 && msg->raw.signals.minCellVoltNum <= 255);
    assert(msg->averageCellVolt <= 5000);
    assert(msg->maxCellVolt >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->maxCellVolt, 1, 16);
    msg->raw.signals.maxCellVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->minCellVolt >= 0);
    temp = RoundLimitUnsigned(msg->minCellVolt, 1, 16);
    msg->raw.signals.minCellVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->averageCellVolt >= 0);
    temp = RoundLimitUnsigned(msg->averageCellVolt, 1, 16);
    msg->raw.signals.averageCellVolt = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg6_FromCan(BMSStatusMsg6_t * msg) 
{ 
    msg->maxCellVolt = ((msg->raw.signals.maxCellVolt >> 8) + ((msg->raw.signals.maxCellVolt & 0xFF) << 8)) * 1.0;
    msg->minCellVolt = ((msg->raw.signals.minCellVolt >> 8) + ((msg->raw.signals.minCellVolt & 0xFF) << 8)) * 1.0;
    msg->averageCellVolt = ((msg->raw.signals.averageCellVolt >> 8) + ((msg->raw.signals.averageCellVolt & 0xFF) << 8)) * 1.0;
}



// message ID 0x1088F5F4 BMSStatusMsg7
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t totalPacketFrames :8;
			uint64_t packetSeqNum :8;
			uint64_t cellSamplingVolt :16;    //V
			uint64_t cellSamplingVolt2 :16;    //V
			uint64_t cellSamplingVolt3 :16;    //V
		} signals;
	} raw;
    double cellSamplingVolt;
    double cellSamplingVolt2;
    double cellSamplingVolt3;
} BMSStatusMsg7_t;


static void BMSStatusMsg7_ToCan(BMSStatusMsg7_t * msg) 
{ 
    assert(msg->raw.signals.totalPacketFrames <= 255);
    assert(msg->raw.signals.packetSeqNum >= 1 && msg->raw.signals.packetSeqNum <= 255);
    assert(msg->cellSamplingVolt <= 5);
    assert(msg->cellSamplingVolt2 <= 5);
    assert(msg->cellSamplingVolt3 <= 5);
    assert(msg->cellSamplingVolt >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->cellSamplingVolt, 0.001, 16);
    msg->raw.signals.cellSamplingVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->cellSamplingVolt2 >= 0);
    temp = RoundLimitUnsigned(msg->cellSamplingVolt2, 0.001, 16);
    msg->raw.signals.cellSamplingVolt2 = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->cellSamplingVolt3 >= 0);
    temp = RoundLimitUnsigned(msg->cellSamplingVolt3, 0.001, 16);
    msg->raw.signals.cellSamplingVolt3 = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg7_FromCan(BMSStatusMsg7_t * msg) 
{ 
    msg->cellSamplingVolt = ((msg->raw.signals.cellSamplingVolt >> 8) + ((msg->raw.signals.cellSamplingVolt & 0xFF) << 8)) * 0.001;
    msg->cellSamplingVolt2 = ((msg->raw.signals.cellSamplingVolt2 >> 8) + ((msg->raw.signals.cellSamplingVolt2 & 0xFF) << 8)) * 0.001;
    msg->cellSamplingVolt3 = ((msg->raw.signals.cellSamplingVolt3 >> 8) + ((msg->raw.signals.cellSamplingVolt3 & 0xFF) << 8)) * 0.001;
}



// message ID 0x1089F5F4 BMSStatusMsg8
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t totalPacketFrames :8;
			uint64_t packetSeqNum :8;
			uint64_t cellSamplingTemp :16;    //degrees
			uint64_t cellSamplingTemp2 :16;    //degrees
			uint64_t cellSamplingTemp3 :16;    //degrees
		} signals;
	} raw;
    double cellSamplingTemp;
    double cellSamplingTemp2;
    double cellSamplingTemp3;
} BMSStatusMsg8_t;


static void BMSStatusMsg8_ToCan(BMSStatusMsg8_t * msg) 
{ 
    assert(msg->raw.signals.totalPacketFrames <= 255);
    assert(msg->raw.signals.packetSeqNum <= 255);
    assert(msg->cellSamplingTemp >= -40 && msg->cellSamplingTemp <= 210);
    assert(msg->cellSamplingTemp2 >= -40 && msg->cellSamplingTemp2 <= 210);
    assert(msg->cellSamplingTemp3 >= -40 && msg->cellSamplingTemp3 <= 210);
    assert(msg->cellSamplingTemp + 40 >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->cellSamplingTemp + 40, 1, 16);
    msg->raw.signals.cellSamplingTemp = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->cellSamplingTemp2 + 40 >= 0);
    temp = RoundLimitUnsigned(msg->cellSamplingTemp2 + 40, 1, 16);
    msg->raw.signals.cellSamplingTemp2 = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->cellSamplingTemp3 + 40 >= 0);
    temp = RoundLimitUnsigned(msg->cellSamplingTemp3 + 40, 1, 16);
    msg->raw.signals.cellSamplingTemp3 = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg8_FromCan(BMSStatusMsg8_t * msg) 
{ 
    msg->cellSamplingTemp = ((msg->raw.signals.cellSamplingTemp >> 8) + ((msg->raw.signals.cellSamplingTemp & 0xFF) << 8)) * 1.0 - 40;
    msg->cellSamplingTemp2 = ((msg->raw.signals.cellSamplingTemp2 >> 8) + ((msg->raw.signals.cellSamplingTemp2 & 0xFF) << 8)) * 1.0 - 40;
    msg->cellSamplingTemp3 = ((msg->raw.signals.cellSamplingTemp3 >> 8) + ((msg->raw.signals.cellSamplingTemp3 & 0xFF) << 8)) * 1.0 - 40;
}



// message ID 0x1CF301F4 BMSStatusMsg11
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t vendorNum :32;
			uint64_t hardwareVersion :16;
			uint64_t softwareVersion :16;
		} signals;
	} raw;
} BMSStatusMsg11_t;

// message ID 0x1CF302F4 BMSStatusMsg12
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t chargerPlugPosTemp :8;    //degrees
			uint64_t chargerPlugNegTemp :8;    //degrees
			uint64_t resistance :16;    //kOhm
			uint64_t heatCurrent :16;    //A
		} signals;
	} raw;
    double chargerPlugPosTemp;
    double chargerPlugNegTemp;
    double heatCurrent;
    double resistance;
} BMSStatusMsg12_t;


static void BMSStatusMsg12_ToCan(BMSStatusMsg12_t * msg) 
{ 
    assert(msg->chargerPlugPosTemp >= -100 && msg->chargerPlugPosTemp <= 150);
    assert(msg->chargerPlugNegTemp >= -100 && msg->chargerPlugNegTemp <= 150);
    assert(msg->resistance <= 65535);
    assert(msg->heatCurrent >= -1000 && msg->heatCurrent <= 1000);
    assert(msg->chargerPlugPosTemp + 100 >= 0);
    msg->raw.signals.chargerPlugPosTemp = RoundLimitUnsigned(msg->chargerPlugPosTemp + 100, 1, 8);
    assert(msg->chargerPlugNegTemp + 100 >= 0);
    msg->raw.signals.chargerPlugNegTemp = RoundLimitUnsigned(msg->chargerPlugNegTemp + 100, 1, 8);
    assert(msg->resistance >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->resistance, 1, 16);
    msg->raw.signals.resistance = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->heatCurrent + 1000 >= 0);
    temp = RoundLimitUnsigned(msg->heatCurrent + 1000, 0.1, 16);
    msg->raw.signals.heatCurrent = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMSStatusMsg12_FromCan(BMSStatusMsg12_t * msg) 
{ 
    msg->chargerPlugPosTemp = msg->raw.signals.chargerPlugPosTemp * 1.0 - 100;
    msg->chargerPlugNegTemp = msg->raw.signals.chargerPlugNegTemp * 1.0 - 100;
    msg->resistance = ((msg->raw.signals.resistance >> 8) + ((msg->raw.signals.resistance & 0xFF) << 8)) * 1.0;
    msg->heatCurrent = ((msg->raw.signals.heatCurrent >> 8) + ((msg->raw.signals.heatCurrent & 0xFF) << 8)) * 0.1 - 1000;
}



// message ID 0x1806E5F4 BMS2ChargerReqMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxChargeVolt :16;    //V
			uint64_t maxChargeCurrent :16;    //A
			uint64_t outputOff :1;
			uint64_t reserved :7;
			uint64_t heating :1;
		} signals;
	} raw;
    double maxChargeVolt;
    double maxChargeCurrent;
} BMS2ChargerReqMsg_t;


static void BMS2ChargerReqMsg_ToCan(BMS2ChargerReqMsg_t * msg) 
{ 
    assert(msg->raw.signals.outputOff <= 1);
    assert(msg->raw.signals.heating <= 1);
    assert(msg->maxChargeVolt >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->maxChargeVolt, 0.1, 16);
    msg->raw.signals.maxChargeVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->maxChargeCurrent >= 0);
    temp = RoundLimitUnsigned(msg->maxChargeCurrent, 0.1, 16);
    msg->raw.signals.maxChargeCurrent = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BMS2ChargerReqMsg_FromCan(BMS2ChargerReqMsg_t * msg) 
{ 
    msg->maxChargeVolt = ((msg->raw.signals.maxChargeVolt >> 8) + ((msg->raw.signals.maxChargeVolt & 0xFF) << 8)) * 0.1;
    msg->maxChargeCurrent = ((msg->raw.signals.maxChargeCurrent >> 8) + ((msg->raw.signals.maxChargeCurrent & 0xFF) << 8)) * 0.1;
}



// message ID 0x18FF50E5 ChargerStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t outputVolt :16;    //V
			uint64_t outputCurrent :16;    //A
			uint64_t hardwareFail :1;
			uint64_t overTemp :1;
			uint64_t inputVoltError :1;
			uint64_t batteryConnectError :1;
			uint64_t CommsError :1;
			uint64_t ChargerCableConnected :1;
			uint64_t reserved :2;
			uint64_t temperature :8;    //degrees
		} signals;
	} raw;
    double outputVolt;
    double outputCurrent;
    double temperature;
} ChargerStatusMsg_t;


static void ChargerStatusMsg_ToCan(ChargerStatusMsg_t * msg) 
{ 
    assert(msg->raw.signals.hardwareFail <= 1);
    assert(msg->raw.signals.overTemp <= 1);
    assert(msg->raw.signals.inputVoltError <= 1);
    assert(msg->raw.signals.batteryConnectError <= 1);
    assert(msg->raw.signals.CommsError <= 1);
    assert(msg->raw.signals.ChargerCableConnected <= 1);
    assert(msg->temperature >= -100 && msg->temperature <= 155);
    assert(msg->temperature + 100 >= 0);
    msg->raw.signals.temperature = RoundLimitUnsigned(msg->temperature + 100, 1, 8);
    assert(msg->outputVolt >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->outputVolt, 0.1, 16);
    msg->raw.signals.outputVolt = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->outputCurrent >= 0);
    temp = RoundLimitUnsigned(msg->outputCurrent, 0.1, 16);
    msg->raw.signals.outputCurrent = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void ChargerStatusMsg_FromCan(ChargerStatusMsg_t * msg) 
{ 
    msg->temperature = msg->raw.signals.temperature * 1.0 - 100;
    msg->outputVolt = ((msg->raw.signals.outputVolt >> 8) + ((msg->raw.signals.outputVolt & 0xFF) << 8)) * 0.1;
    msg->outputCurrent = ((msg->raw.signals.outputCurrent >> 8) + ((msg->raw.signals.outputCurrent & 0xFF) << 8)) * 0.1;
}



// message ID 0x18FFC13A AirConStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reserved :8;
			uint64_t airConTemp :8;    //degree C
			uint64_t roomTemp :8;    //degree C
		} signals;
	} raw;
    double airConTemp;
    double roomTemp;
} AirConStatusMsg_t;


static void AirConStatusMsg_ToCan(AirConStatusMsg_t * msg) 
{ 
    assert(msg->airConTemp >= -40 && msg->airConTemp <= 214);
    assert(msg->roomTemp >= -40 && msg->roomTemp <= 214);
    assert(msg->airConTemp + 40 >= 0);
    msg->raw.signals.airConTemp = RoundLimitUnsigned(msg->airConTemp + 40, 1, 8);
    assert(msg->roomTemp + 40 >= 0);
    msg->raw.signals.roomTemp = RoundLimitUnsigned(msg->roomTemp + 40, 1, 8);
}

static void AirConStatusMsg_FromCan(AirConStatusMsg_t * msg) 
{ 
    msg->airConTemp = msg->raw.signals.airConTemp * 1.0 - 40;
    msg->roomTemp = msg->raw.signals.roomTemp * 1.0 - 40;
}



// message ID 0x105001F AVASStatusMsg
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t active :1;
			uint64_t reserved :7;
			uint64_t voltage :8;    //V
			uint64_t error :8;
			uint64_t reserved1 :24;
			uint64_t count :8;
			uint64_t checksum :8;
		} signals;
	} raw;
    double voltage;
} AVASStatusMsg_t;


static void AVASStatusMsg_ToCan(AVASStatusMsg_t * msg) 
{ 
    assert(msg->raw.signals.active <= 1);
    assert(msg->voltage <= 25.5);
    assert(msg->raw.signals.error <= 255);
    assert(msg->raw.signals.count <= 255);
    assert(msg->raw.signals.checksum <= 255);
    assert(msg->voltage >= 0);
    msg->raw.signals.voltage = RoundLimitUnsigned(msg->voltage, 0.1, 8);
}

static void AVASStatusMsg_FromCan(AVASStatusMsg_t * msg) 
{ 
    msg->voltage = msg->raw.signals.voltage * 0.1;
}



// message ID 0x19000010 Signal1Debug
// message ID 0x19000020 Signal2Debug
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t sigState :8;
			uint64_t steerState :8;
			uint64_t io1 :1;
			uint64_t io2 :1;
			uint64_t io3 :1;
			uint64_t io4 :1;
			uint64_t io5 :1;
			uint64_t io6 :1;
			uint64_t EHBFire_io7 :1;
			uint64_t VCU_io8 :1;
			uint64_t steerFire :1;
			uint64_t reserved :7;
			uint64_t aux_in1 :1;
			uint64_t hw_in :1;
			uint64_t reserved1 :6;
			uint64_t timestamp :24;
		} signals;
	} raw;
} SignalDebugMsg_t;

// message ID 0x1D000101 PeripheralVersionMsg
// message ID 0x1D000102 PeripheralBootVerMsg
// message ID 0x1D000103 PeripheralOcanDBCVerMsg
// message ID 0x1D000104 PeripheralPcanDBCVerMsg
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
} PeripheralVersionRespMsg_t;

// message ID 0xCF50124 BmsLotteStatus
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t BS_Cell_OVP_Warning :2;
			uint64_t BS_Cell_UVP_Warning :2;
			uint64_t BS_Insulation_Warning :2;
			uint64_t BS_Temperature_Higher_Warning :2;
			uint64_t BS_Contactor_Fault :2;
			uint64_t BS_SOH_Warning :2;
			uint64_t BS_Short_Circuit :2;
			uint64_t BS_Feed_Warning :2;
			uint64_t reserved :4;
			uint64_t BS_Output_OverCurrent_Warning :2;
			uint64_t BS_Cell_Imbalance_Warning :2;
			uint64_t BS_Communication_Fault :2;
			uint64_t BS_Hardware_FaultOWD :2;
			uint64_t BS_Pack_Over_Voltage_Warning :2;
			uint64_t BS_Power_Reduce_Indicator :2;
			uint64_t BS_Negative_Contactor_Status :1;
			uint64_t BS_Positive_Contactor_Status :1;
			uint64_t BS_Fault_Level :2;
			uint64_t BS_ShutDown_Request :1;
			uint64_t BS_checkover :1;
			uint64_t reserved1 :1;
			uint64_t BS_TBOX_Drop_Line :1;
			uint64_t BS_Feedback_Current_Large :1;
			uint64_t BS_Relay_Adhesion :1;
			uint64_t BS_Pack_UVP_Warning :2;
			uint64_t BS_Pack_Imbalance_TEMP_Warning :2;
			uint64_t BS_Temperature_Lower_Warning :2;
			uint64_t BS_SOC_high :1;
			uint64_t BS_Interlock_Error :1;
			uint64_t BS_Electronic_Lock_Error :1;
			uint64_t BS_Charge_Temperature_High :2;
			uint64_t BS_SOC_Low :2;
			uint64_t reserved2 :1;
			uint64_t BS_Heating_Relay :1;
			uint64_t reserved3 :3;
			uint64_t BS_Slow_Charge_Over_Current :2;
			uint64_t BS_Fast_Charge_Over_Current :2;
		} signals;
	} raw;
} BmsLotteStatus_t;

// message ID 0x18F51124 BmsLotteDrive1
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t BD1_Voltage :16;    //V
			int64_t BD1_Current :16;    //A
			uint64_t BD1_Posi_ISO_Resistor :16;    //M??
			uint64_t BD1_SOC :8;    //%
			uint64_t BD1_Number_of_Battery :8;
		} signals;
	} raw;
    double BD1_Voltage;
    double BD1_Current;
} BmsLotteDrive1_t;


static void BmsLotteDrive1_ToCan(BmsLotteDrive1_t * msg) 
{ 
    assert(msg->BD1_Voltage <= 6553.5);
    assert(msg->BD1_Current >= -320 && msg->BD1_Current <= 6233.5);
    assert(msg->raw.signals.BD1_Posi_ISO_Resistor <= 65535);
    assert(msg->raw.signals.BD1_SOC <= 255);
    assert(msg->raw.signals.BD1_Number_of_Battery <= 255);
    assert(msg->BD1_Voltage >= 0);
    msg->raw.signals.BD1_Voltage = RoundLimitUnsigned(msg->BD1_Voltage, 0.1, 16);
    msg->raw.signals.BD1_Current = RoundLimitSigned(msg->BD1_Current + 320, 0.1, 16);
}

static void BmsLotteDrive1_FromCan(BmsLotteDrive1_t * msg) 
{ 
    msg->BD1_Voltage = msg->raw.signals.BD1_Voltage * 0.1;
    msg->BD1_Current = msg->raw.signals.BD1_Current * 0.1 - 320;
}



// message ID 0x18F52224 BmsLotteDrive2
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t BD2_Cell_MAX_Volt :16;    //V
			uint64_t BD2_Cell_MAX_Volt_NO :8;
			uint64_t BD2_Cell_MIN_Volt :16;    //V
			uint64_t BD2_Cell_MIN_Volt_NO :8;
			uint64_t BD2_SOH :8;    //%
			uint64_t BD2_Battery_Capacity :8;    //Ah
		} signals;
	} raw;
    double BD2_Cell_MAX_Volt;
    double BD2_Cell_MIN_Volt;
} BmsLotteDrive2_t;


static void BmsLotteDrive2_ToCan(BmsLotteDrive2_t * msg) 
{ 
    assert(msg->BD2_Cell_MAX_Volt <= 65.535);
    assert(msg->raw.signals.BD2_Cell_MAX_Volt_NO <= 255);
    assert(msg->BD2_Cell_MIN_Volt <= 65.535);
    assert(msg->raw.signals.BD2_Cell_MIN_Volt_NO <= 255);
    assert(msg->raw.signals.BD2_SOH <= 255);
    assert(msg->raw.signals.BD2_Battery_Capacity <= 255);
    assert(msg->BD2_Cell_MAX_Volt >= 0);
    msg->raw.signals.BD2_Cell_MAX_Volt = RoundLimitUnsigned(msg->BD2_Cell_MAX_Volt, 0.001, 16);
    assert(msg->BD2_Cell_MIN_Volt >= 0);
    msg->raw.signals.BD2_Cell_MIN_Volt = RoundLimitUnsigned(msg->BD2_Cell_MIN_Volt, 0.001, 16);
}

static void BmsLotteDrive2_FromCan(BmsLotteDrive2_t * msg) 
{ 
    msg->BD2_Cell_MAX_Volt = msg->raw.signals.BD2_Cell_MAX_Volt * 0.001;
    msg->BD2_Cell_MIN_Volt = msg->raw.signals.BD2_Cell_MIN_Volt * 0.001;
}



// message ID 0x18F53324 BmsLotteDrive3
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t BD3_Batt_MAX_Temp :8;    //??
			uint64_t BD3_Max_Temp_NO :8;
			int64_t BD3_Batt_MIN_Temp :8;    //??
			uint64_t BD3_Min_Temp_NO :8;
			uint64_t BD3_Vehicle_MAX_Charge_Power :8;    //KW
			uint64_t BD3_Vehicle_MAX_Discharge_Power :8;    //KW
			uint64_t BD3_Vehicle_Rated_CHG_Power :8;    //KW
			uint64_t BD3_Vehicle_RatedDisCHG_Power :8;    //KW
		} signals;
	} raw;
    double BD3_Batt_MAX_Temp;
    double BD3_Batt_MIN_Temp;
} BmsLotteDrive3_t;


static void BmsLotteDrive3_ToCan(BmsLotteDrive3_t * msg) 
{ 
    assert(msg->BD3_Batt_MAX_Temp >= -168 && msg->BD3_Batt_MAX_Temp <= 87);
    assert(msg->raw.signals.BD3_Max_Temp_NO <= 255);
    assert(msg->BD3_Batt_MIN_Temp >= -168 && msg->BD3_Batt_MIN_Temp <= 87);
    assert(msg->raw.signals.BD3_Min_Temp_NO <= 255);
    assert(msg->raw.signals.BD3_Vehicle_MAX_Charge_Power <= 255);
    assert(msg->raw.signals.BD3_Vehicle_MAX_Discharge_Power <= 255);
    assert(msg->raw.signals.BD3_Vehicle_Rated_CHG_Power <= 255);
    assert(msg->raw.signals.BD3_Vehicle_RatedDisCHG_Power <= 255);
    msg->raw.signals.BD3_Batt_MAX_Temp = RoundLimitSigned(msg->BD3_Batt_MAX_Temp + 40, 1, 8);
    msg->raw.signals.BD3_Batt_MIN_Temp = RoundLimitSigned(msg->BD3_Batt_MIN_Temp + 40, 1, 8);
}

static void BmsLotteDrive3_FromCan(BmsLotteDrive3_t * msg) 
{ 
    msg->BD3_Batt_MAX_Temp = msg->raw.signals.BD3_Batt_MAX_Temp * 1.0 - 40;
    msg->BD3_Batt_MIN_Temp = msg->raw.signals.BD3_Batt_MIN_Temp * 1.0 - 40;
}



// message ID 0x18FD7524 BmsLotteChargeVehicle
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t Charge_OverCurrent :2;
			uint64_t Auxiliary_Charge_Relay_Fault :2;
			uint64_t CHG_Communicaiton_Fault :2;
			uint64_t Charger_Warning :2;
			uint64_t CHG_Indication :2;
			uint64_t CHG_Connect_Indication :2;
			uint64_t Turn_Off_Power_Battery :2;
			uint64_t reserved :2;
			uint64_t CHG_MAX_Voltage :16;    //V
			int64_t CHG_MAX_Current :16;
		} signals;
	} raw;
    double CHG_MAX_Voltage;
    double CHG_MAX_Current;
} BmsLotteChargeVehicle_t;


static void BmsLotteChargeVehicle_ToCan(BmsLotteChargeVehicle_t * msg) 
{ 
    assert(msg->raw.signals.Charge_OverCurrent <= 3);
    assert(msg->raw.signals.Auxiliary_Charge_Relay_Fault <= 3);
    assert(msg->raw.signals.CHG_Communicaiton_Fault <= 3);
    assert(msg->raw.signals.Charger_Warning <= 3);
    assert(msg->raw.signals.CHG_Indication <= 3);
    assert(msg->raw.signals.CHG_Connect_Indication <= 3);
    assert(msg->raw.signals.Turn_Off_Power_Battery <= 3);
    assert(msg->CHG_MAX_Voltage <= 6553.5);
    assert(msg->CHG_MAX_Current >= -320 && msg->CHG_MAX_Current <= 6233.5);
    assert(msg->CHG_MAX_Voltage >= 0);
    msg->raw.signals.CHG_MAX_Voltage = RoundLimitUnsigned(msg->CHG_MAX_Voltage, 0.1, 16);
    msg->raw.signals.CHG_MAX_Current = RoundLimitSigned(msg->CHG_MAX_Current + 320, 0.1, 16);
}

static void BmsLotteChargeVehicle_FromCan(BmsLotteChargeVehicle_t * msg) 
{ 
    msg->CHG_MAX_Voltage = msg->raw.signals.CHG_MAX_Voltage * 0.1;
    msg->CHG_MAX_Current = msg->raw.signals.CHG_MAX_Current * 0.1 - 320;
}



// message ID 0x18E54024 BmsLotteChargerInfo
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t CHG_Control :2;
			uint64_t reserved :6;
			uint64_t CHG_MAX_Voltage :16;    //V
			int64_t CHG_MAX_Current :16;    //A
			uint64_t Load_Type :1;
			uint64_t Load_Relay_Mode :1;
			uint64_t reserved1 :6;
			uint64_t Remaining_Charging_Time :16;    //min
		} signals;
	} raw;
    double CHG_MAX_Voltage;
    double CHG_MAX_Current;
} BmsLotteChargerInfo_t;


static void BmsLotteChargerInfo_ToCan(BmsLotteChargerInfo_t * msg) 
{ 
    assert(msg->raw.signals.CHG_Control <= 3);
    assert(msg->CHG_MAX_Voltage <= 6553.5);
    assert(msg->CHG_MAX_Current >= -320 && msg->CHG_MAX_Current <= 6233.5);
    assert(msg->raw.signals.Load_Type <= 1);
    assert(msg->raw.signals.Load_Relay_Mode <= 1);
    assert(msg->raw.signals.Remaining_Charging_Time <= 65535);
    assert(msg->CHG_MAX_Voltage >= 0);
    msg->raw.signals.CHG_MAX_Voltage = RoundLimitUnsigned(msg->CHG_MAX_Voltage, 0.1, 16);
    msg->raw.signals.CHG_MAX_Current = RoundLimitSigned(msg->CHG_MAX_Current + 320, 0.1, 16);
}

static void BmsLotteChargerInfo_FromCan(BmsLotteChargerInfo_t * msg) 
{ 
    msg->CHG_MAX_Voltage = msg->raw.signals.CHG_MAX_Voltage * 0.1;
    msg->CHG_MAX_Current = msg->raw.signals.CHG_MAX_Current * 0.1 - 320;
}



// message ID 0x18359A24 BmsLotteLandmark6
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t Manufactoring_Y1 :8;
			int64_t Manufactoring_Y2 :8;
			int64_t Manufactoring_Y3 :8;
			int64_t Manufactoring_Y4 :8;
			int64_t Manufactoring_M1 :8;
			int64_t Manufactoring_M2 :8;
			int64_t Manufactoring_D1 :8;
			int64_t Manufactoring_D2 :8;
		} signals;
	} raw;
    double Manufactoring_Y1;
    double Manufactoring_Y2;
    double Manufactoring_Y3;
    double Manufactoring_Y4;
    double Manufactoring_M1;
    double Manufactoring_M2;
    double Manufactoring_D1;
    double Manufactoring_D2;
} BmsLotteLandmark6_t;


static void BmsLotteLandmark6_ToCan(BmsLotteLandmark6_t * msg) 
{ 
    assert(msg->Manufactoring_Y1 >= -48 && msg->Manufactoring_Y1 <= 207);
    assert(msg->Manufactoring_Y2 >= -48 && msg->Manufactoring_Y2 <= 207);
    assert(msg->Manufactoring_Y3 >= -48 && msg->Manufactoring_Y3 <= 207);
    assert(msg->Manufactoring_Y4 >= -48 && msg->Manufactoring_Y4 <= 207);
    assert(msg->Manufactoring_M1 >= -48 && msg->Manufactoring_M1 <= 207);
    assert(msg->Manufactoring_M2 >= -48 && msg->Manufactoring_M2 <= 207);
    assert(msg->Manufactoring_D1 >= -48 && msg->Manufactoring_D1 <= 207);
    assert(msg->Manufactoring_D2 >= -48 && msg->Manufactoring_D2 <= 207);
    msg->raw.signals.Manufactoring_Y1 = RoundLimitSigned(msg->Manufactoring_Y1 + 48, 1, 8);
    msg->raw.signals.Manufactoring_Y2 = RoundLimitSigned(msg->Manufactoring_Y2 + 48, 1, 8);
    msg->raw.signals.Manufactoring_Y3 = RoundLimitSigned(msg->Manufactoring_Y3 + 48, 1, 8);
    msg->raw.signals.Manufactoring_Y4 = RoundLimitSigned(msg->Manufactoring_Y4 + 48, 1, 8);
    msg->raw.signals.Manufactoring_M1 = RoundLimitSigned(msg->Manufactoring_M1 + 48, 1, 8);
    msg->raw.signals.Manufactoring_M2 = RoundLimitSigned(msg->Manufactoring_M2 + 48, 1, 8);
    msg->raw.signals.Manufactoring_D1 = RoundLimitSigned(msg->Manufactoring_D1 + 48, 1, 8);
    msg->raw.signals.Manufactoring_D2 = RoundLimitSigned(msg->Manufactoring_D2 + 48, 1, 8);
}

static void BmsLotteLandmark6_FromCan(BmsLotteLandmark6_t * msg) 
{ 
    msg->Manufactoring_Y1 = msg->raw.signals.Manufactoring_Y1 * 1.0 - 48;
    msg->Manufactoring_Y2 = msg->raw.signals.Manufactoring_Y2 * 1.0 - 48;
    msg->Manufactoring_Y3 = msg->raw.signals.Manufactoring_Y3 * 1.0 - 48;
    msg->Manufactoring_Y4 = msg->raw.signals.Manufactoring_Y4 * 1.0 - 48;
    msg->Manufactoring_M1 = msg->raw.signals.Manufactoring_M1 * 1.0 - 48;
    msg->Manufactoring_M2 = msg->raw.signals.Manufactoring_M2 * 1.0 - 48;
    msg->Manufactoring_D1 = msg->raw.signals.Manufactoring_D1 * 1.0 - 48;
    msg->Manufactoring_D2 = msg->raw.signals.Manufactoring_D2 * 1.0 - 48;
}



// message ID 0x18369A24 BmsLotteLandmark7
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t BMS_Serial_Y1 :8;
			int64_t BMS_Serial_Y2 :8;
			int64_t BMS_Serial_M1 :8;
			int64_t BMS_Serial_M2 :8;
			uint64_t BMS_Serial_PC :8;
			int64_t BMS_Serial_N1 :8;
			int64_t BMS_Serial_N2 :8;
			int64_t BMS_Serial_N3 :8;
		} signals;
	} raw;
    double BMS_Serial_Y1;
    double BMS_Serial_Y2;
    double BMS_Serial_M1;
    double BMS_Serial_M2;
    double BMS_Serial_N1;
    double BMS_Serial_N2;
    double BMS_Serial_N3;
} BmsLotteLandmark7_t;


static void BmsLotteLandmark7_ToCan(BmsLotteLandmark7_t * msg) 
{ 
    assert(msg->BMS_Serial_Y1 >= -48 && msg->BMS_Serial_Y1 <= 207);
    assert(msg->BMS_Serial_Y2 >= -48 && msg->BMS_Serial_Y2 <= 207);
    assert(msg->BMS_Serial_M1 >= -48 && msg->BMS_Serial_M1 <= 207);
    assert(msg->BMS_Serial_M2 >= -48 && msg->BMS_Serial_M2 <= 207);
    assert(msg->raw.signals.BMS_Serial_PC <= 255);
    assert(msg->BMS_Serial_N1 >= -48 && msg->BMS_Serial_N1 <= 207);
    assert(msg->BMS_Serial_N2 >= -48 && msg->BMS_Serial_N2 <= 207);
    assert(msg->BMS_Serial_N3 >= -48 && msg->BMS_Serial_N3 <= 207);
    msg->raw.signals.BMS_Serial_Y1 = RoundLimitSigned(msg->BMS_Serial_Y1 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_Y2 = RoundLimitSigned(msg->BMS_Serial_Y2 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_M1 = RoundLimitSigned(msg->BMS_Serial_M1 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_M2 = RoundLimitSigned(msg->BMS_Serial_M2 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_N1 = RoundLimitSigned(msg->BMS_Serial_N1 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_N2 = RoundLimitSigned(msg->BMS_Serial_N2 + 48, 1, 8);
    msg->raw.signals.BMS_Serial_N3 = RoundLimitSigned(msg->BMS_Serial_N3 + 48, 1, 8);
}

static void BmsLotteLandmark7_FromCan(BmsLotteLandmark7_t * msg) 
{ 
    msg->BMS_Serial_Y1 = msg->raw.signals.BMS_Serial_Y1 * 1.0 - 48;
    msg->BMS_Serial_Y2 = msg->raw.signals.BMS_Serial_Y2 * 1.0 - 48;
    msg->BMS_Serial_M1 = msg->raw.signals.BMS_Serial_M1 * 1.0 - 48;
    msg->BMS_Serial_M2 = msg->raw.signals.BMS_Serial_M2 * 1.0 - 48;
    msg->BMS_Serial_N1 = msg->raw.signals.BMS_Serial_N1 * 1.0 - 48;
    msg->BMS_Serial_N2 = msg->raw.signals.BMS_Serial_N2 * 1.0 - 48;
    msg->BMS_Serial_N3 = msg->raw.signals.BMS_Serial_N3 * 1.0 - 48;
}



// message ID 0x18379A24 BmsLotteLandmark8
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t BL8_SW_Ver :16;
			uint64_t BL8_HW_Ver :16;
		} signals;
	} raw;
    double BL8_SW_Ver;
    double BL8_HW_Ver;
} BmsLotteLandmark8_t;


static void BmsLotteLandmark8_ToCan(BmsLotteLandmark8_t * msg) 
{ 
    assert(msg->BL8_SW_Ver <= 65535);
    assert(msg->BL8_HW_Ver <= 65535);
    assert(msg->BL8_SW_Ver >= 0);
    uint64_t temp = RoundLimitUnsigned(msg->BL8_SW_Ver, 1, 16);
    msg->raw.signals.BL8_SW_Ver = (temp >> 8) + ((temp & 0xFF) << 8);

    assert(msg->BL8_HW_Ver >= 0);
    temp = RoundLimitUnsigned(msg->BL8_HW_Ver, 1, 16);
    msg->raw.signals.BL8_HW_Ver = (temp >> 8) + ((temp & 0xFF) << 8);

}

static void BmsLotteLandmark8_FromCan(BmsLotteLandmark8_t * msg) 
{ 
    msg->BL8_SW_Ver = ((msg->raw.signals.BL8_SW_Ver >> 8) + ((msg->raw.signals.BL8_SW_Ver & 0xFF) << 8)) * 1.0;
    msg->BL8_HW_Ver = ((msg->raw.signals.BL8_HW_Ver >> 8) + ((msg->raw.signals.BL8_HW_Ver & 0xFF) << 8)) * 1.0;
}



// message ID 0x3A3A107 BmsLotteTotalChangeValue
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			int64_t T_Change_Volt :16;    //V
			int64_t T_Change_Temp :16;    //??/f:0.1
			int64_t T_Change_Curr :16;    //A
		} signals;
	} raw;
    double T_Change_Volt;
    double T_Change_Temp;
    double T_Change_Curr;
} BmsLotteTotalChangeValue_t;


static void BmsLotteTotalChangeValue_ToCan(BmsLotteTotalChangeValue_t * msg) 
{ 
    assert(msg->T_Change_Volt >= -32.768 && msg->T_Change_Volt <= 32.767);
    assert(msg->T_Change_Temp >= -32768 && msg->T_Change_Temp <= 32767);
    assert(msg->T_Change_Curr >= -3276.8 && msg->T_Change_Curr <= 3276.7);
    msg->raw.signals.T_Change_Volt = RoundLimitSigned(msg->T_Change_Volt, 0.001, 16);
    msg->raw.signals.T_Change_Temp = RoundLimitSigned(msg->T_Change_Temp, 1, 16);
    msg->raw.signals.T_Change_Curr = RoundLimitSigned(msg->T_Change_Curr, 0.1, 16);
}

static void BmsLotteTotalChangeValue_FromCan(BmsLotteTotalChangeValue_t * msg) 
{ 
    msg->T_Change_Volt = msg->raw.signals.T_Change_Volt * 0.001;
    msg->T_Change_Temp = msg->raw.signals.T_Change_Temp * 1.0;
    msg->T_Change_Curr = msg->raw.signals.T_Change_Curr * 0.1;
}



// message ID 0xCF002EF BmsLotteVehiclecontroller
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t reserved :1;
			uint64_t V_BMS_HV_Connect_Cmd :1;
		} signals;
	} raw;
} BmsLotteVehiclecontroller_t;

#endif //peripheral_DBC_TOOL_GENERATED_H
