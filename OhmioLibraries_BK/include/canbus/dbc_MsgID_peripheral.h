#ifndef peripheral_DBC_MSGID_DBC_TOOL_GENERATED_H
#define peripheral_DBC_MSGID_DBC_TOOL_GENERATED_H

#define PERIPHERAL_CANBUS_VERSION_MAJOR 1
#define PERIPHERAL_CANBUS_VERSION_MINOR 12
#define PERIPHERAL_CANBUS_VERSION_BUILD 0x0E350456         // 32 bit hash code for the dbc file



typedef enum
{
    CAN_ID_VOICE_REQ    =    0x10200000,    //    voiceReq:  bits0-7: command; bits8-15: value; 
    CAN_ID_VOICE_RESP    =    0x1020000F,    //    voiceResp:  bits0-7: command; bits8-15: value; 
    CAN_ID_FRONT_MAIN_LIGHT_REQ    =    0x10300100,    //    FrontMainLightReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_MAIN_LIGHT_STATUS    =    0x1030010F,    //    FrontMainLightStatusMsg:  bits0-7: on; 
    CAN_ID_FRONT_DIP_LIGHT_REQ    =    0x10300110,    //    FrontDipLightReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_DIP_LIGHT_STATUS    =    0x1030011F,    //    FrontDipLightStatusMsg:  bits0-7: on; 
    CAN_ID_FRONT_DAY_LIGHT_REQ    =    0x10300120,    //    FrontDayLightReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_DAY_LIGHT_STATUS    =    0x1030012F,    //    FrontDayLightStatusMsg:  bits0-7: on; 
    CAN_ID_FRONT_POS_OUTLINE_MARKER_REQ    =    0x10300130,    //    FrontPosOutlineMarkerReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_POS_OUTLINE_MARKER_STATUS    =    0x1030013F,    //    FrontPosOutlineMarkerStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_REVERSE_LIGHT_REQ    =    0x10300200,    //    RearReverseLightReqMsg:  bits0-7: on; 
    CAN_ID_REAR_REVERSE_LIGHT_STATUS    =    0x1030020F,    //    RearReverseLightStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_TAIL_OUTLINE_MARKER_REQ    =    0x10300210,    //    RearTailOutlineMarkerReqMsg:  bits0-7: on; 
    CAN_ID_REAR_TAIL_OUTLINE_MARKER_STATUS    =    0x1030021F,    //    RearTailOutlineMarkerStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_REG_LIGHT_REQ    =    0x10300220,    //    RearRegLightReqMsg:  bits0-7: on; 
    CAN_ID_REAR_REG_LIGHT_STATUS    =    0x1030022F,    //    RearRegLightStatusMsg:  bits0-7: on; 
    CAN_ID_HORN_REQ    =    0x10300300,    //    HornReqMsg:  bits0-7: on; 
    CAN_ID_HORN_STATUS    =    0x1030030F,    //    HornStatusMsg:  bits0-7: on; 
    CAN_ID_LIGHT1_REQUEST    =    0x10400000,    //  front light request byte0: main light left; byte1: main light right; byte2: logo; byte3: flash; byte4: internal 1 PWM; byte5: internal 2 PWM
    CAN_ID_LIGHT1_STATUS    =    0x10400007,    //  front light status byte0: main light left; byte1: main light right; byte2: logo; byte3: flash; byte4: internal 1 PWM; byte5: internal 2 PWM
    CAN_ID_LIGHT2_REQUEST    =    0x10400008,    //  rear light request byte0: main light left; byte1: main light right; byte2: logo; byte3: flash; byte4: internal 1 PWM; byte5: internal 2 PWM
    CAN_ID_LIGHT2_STATUS    =    0x1040000F,    //  rear light status byte0: main light left; byte1: main light right; byte2: logo; byte3: flash; byte4: internal 1 PWM; byte5: internal 2 PWM
    CAN_ID_OVAL_LIGHT_FL_STATUS    =    0x10400010,    //  oval light front left status byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_FL_REQUEST    =    0x1040001F,    //  oval light front left request byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_FR_STATUS    =    0x10400020,    //  oval light front right status byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_FR_REQUEST    =    0x1040002F,    //  oval light front right request byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_RL_STATUS    =    0x10400030,    //  oval light rear left status byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_RL_REQUEST    =    0x1040003F,    //  oval light rear left request byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_RR_STATUS    =    0x10400040,    //  oval light rear right status byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_OVAL_LIGHT_RR_REQUEST    =    0x1040004F,    //  oval light rear right request byte0: mode; byte1: fixed colour bright; byte2: red brightness; byte3: green brightness; byte4: blue brightness
    CAN_ID_DOOR_STATUS    =    0x10400100,    //	door status byte0: heartbeat; byte1: status1; byte2: status2
    CAN_ID_DOOR_REQUEST    =    0x10400107,    //	door operation request byte0: heartbeat; byte1: operation
    CAN_ID_STEP_REQUEST    =    0x10400201,    //	step request byte0: bit0 in, bit1 out; byte6: count; byte7: checksum
    CAN_ID_STEP_STATUS    =    0x10400208,    //	step status byte0: bits0-2 status, bits3-5 error; byte2: current 0.1A; byte3: voltage 0.1A; byte6: count; byte7: checksum
    CAN_ID_AVAS_REQ    =    0x1050010,    //    AVASReqMsg:  bits0-7: speed; bit8: reverse; bits9-47: reserved; bits48-55: count; bits56-63: checksum; 
    CAN_ID_AVAS_STATUS    =    0x105001F,    //    AVASStatusMsg:  bit0: active; bits1-7: reserved; bits8-15: voltage; bits16-23: error; bits24-47: reserved1; bits48-55: count; bits56-63: checksum; 
    CAN_ID_FOOT_REQUEST    =    0x10600000,    //	footing operation request byte0
    CAN_ID_FOOT1_RESP    =    0x10600010,    //  footing 1 response byte0: status; byte1: operational mode; byte2: error
    CAN_ID_FOOT2_RESP    =    0x10600020,    //  footing 2 response byte0: status; byte1: operational mode; byte2: error
    CAN_ID_WIPER1_REQ    =    0x10700000,    //    Wiper1ReqMsg:  bits0-3: mode; bit4: washer; bits5-7: reserved; bits8-15: interval; 
    CAN_ID_WIPER1_STATUS    =    0x1070000F,    //    Wiper1StatusMsg:  bits0-3: mode; bit4: washer; bits5-7: reserved; bits8-15: interval; 
    CAN_ID_WIPER2_REQ    =    0x10700010,    //    Wiper2ReqMsg:  bits0-3: mode; bit4: washer; bits5-7: reserved; bits8-15: interval; 
    CAN_ID_WIPER2_STATUS    =    0x1070001F,    //    Wiper2StatusMsg:  bits0-3: mode; bit4: washer; bits5-7: reserved; bits8-15: interval; 
    CAN_ID_BMS_STATUS    =    0x1082F5F4,    //  battery management status response
    CAN_ID_BMS_STATUS2    =    0x1083F5F4,    //    BMSStatusMsg2:  bits0-15: voltage; bits16-31: DCLinkVolt; bits32-47: DCCurrent; bit48: chargerPlugOverTemp; bit49: chargerPlugTempLineBroke; bit50: heatRelayError; bit51: heatCircuitError; bits52-55: reserved; bits56-63: counter; 
    CAN_ID_BMS_STATUS3    =    0x1084F5F4,    //    BMSStatusMsg3:  bits0-15: maxDisCur; bits16-31: maxChargeCur; bits32-47: constDisCur; bits48-63: constChargeCur; 
    CAN_ID_BMS_STATUS4    =    0x1085F5F4,    //    BMSStatusMsg4:  bits0-15: remainEnergy; bits16-23: soh; bits24-31: soc; bits32-47: insResistance; bit48: posRelayClosed; bit49: negRelayClosed; bit50: preRelayClosed; bit51: chargeRelayClosed; bit52: fastChargeConnected; bit53: heatRelayClosed; bit54: disconnectReq; bit55: slowChargeConnected; bits56-63: counter; 
    CAN_ID_BMS_STATUS5    =    0x1086F5F4,    //    BMSStatusMsg5:  bits0-7: averageTemp; bits8-15: tempSensorNum; bits16-23: maxTemp; bits24-31: minTemp; bits32-39: maxTempNum; bits40-47: minTempNum; bits48-63: cellSumNum; 
    CAN_ID_BMS_STATUS6    =    0x1087F5F4,    //    BMSStatusMsg6:  bits0-15: maxCellVolt; bits16-31: minCellVolt; bits32-39: maxCellVoltNum; bits40-47: minCellVoltNum; bits48-63: averageCellVolt; 
    CAN_ID_BMS_STATUS7    =    0x1088F5F4,    //    BMSStatusMsg7:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-31: cellSamplingVolt; bits32-47: cellSamplingVolt2; bits48-63: cellSamplingVolt3; 
    CAN_ID_BMS_STATUS8    =    0x1089F5F4,    //    BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-31: cellSamplingTemp; bits32-47: cellSamplingTemp2; bits48-63: cellSamplingTemp3; 
    CAN_ID_BM_S2CHARGER_REQ    =    0x1806E5F4,    //    BMS2ChargerReqMsg:  bits0-15: maxChargeVolt; bits16-31: maxChargeCurrent; bit32: outputOff; bits33-39: reserved; bit40: heating; 
    CAN_ID_BMS_LOTTE_LANDMARK6    =    0x18359A24,    //    BmsLotteLandmark6:  bits0-7: Manufactoring_Y1; bits8-15: Manufactoring_Y2; bits16-23: Manufactoring_Y3; bits24-31: Manufactoring_Y4; bits32-39: Manufactoring_M1; bits40-47: Manufactoring_M2; bits48-55: Manufactoring_D1; bits56-63: Manufactoring_D2; 
    CAN_ID_BMS_LOTTE_LANDMARK7    =    0x18369A24,    //    BmsLotteLandmark7:  bits0-7: BMS_Serial_Y1; bits8-15: BMS_Serial_Y2; bits16-23: BMS_Serial_M1; bits24-31: BMS_Serial_M2; bits32-39: BMS_Serial_PC; bits40-47: BMS_Serial_N1; bits48-55: BMS_Serial_N2; bits56-63: BMS_Serial_N3; 
    CAN_ID_BMS_LOTTE_LANDMARK8    =    0x18379A24,    //    BmsLotteLandmark8:  bits0-15: BL8_SW_Ver; bits16-31: BL8_HW_Ver; 
    CAN_ID_BMS_LOTTE_CHARGER_INFO    =    0x18E54024,    //    BmsLotteChargerInfo:  bits0-1: CHG_Control; bits2-7: reserved; bits8-23: CHG_MAX_Voltage; bits24-39: CHG_MAX_Current; bit40: Load_Type; bit41: Load_Relay_Mode; bits42-47: reserved1; bits48-63: Remaining_Charging_Time; 
    CAN_ID_BMS_LOTTE_DRIVE1    =    0x18F51124,    //    BmsLotteDrive1:  bits0-15: BD1_Voltage; bits16-31: BD1_Current; bits32-47: BD1_Posi_ISO_Resistor; bits48-55: BD1_SOC; bits56-63: BD1_Number_of_Battery; 
    CAN_ID_BMS_LOTTE_DRIVE2    =    0x18F52224,    //    BmsLotteDrive2:  bits0-15: BD2_Cell_MAX_Volt; bits16-23: BD2_Cell_MAX_Volt_NO; bits24-39: BD2_Cell_MIN_Volt; bits40-47: BD2_Cell_MIN_Volt_NO; bits48-55: BD2_SOH; bits56-63: BD2_Battery_Capacity; 
    CAN_ID_BMS_LOTTE_DRIVE3    =    0x18F53324,    //    BmsLotteDrive3:  bits0-7: BD3_Batt_MAX_Temp; bits8-15: BD3_Max_Temp_NO; bits16-23: BD3_Batt_MIN_Temp; bits24-31: BD3_Min_Temp_NO; bits32-39: BD3_Vehicle_MAX_Charge_Power; bits40-47: BD3_Vehicle_MAX_Discharge_Power; bits48-55: BD3_Vehicle_Rated_CHG_Power; bits56-63: BD3_Vehicle_RatedDisCHG_Power; 
    CAN_ID_BMS_LOTTE_CHARGE_VEHICLE    =    0x18FD7524,    //    BmsLotteChargeVehicle:  bits0-1: Charge_OverCurrent; bits2-3: Auxiliary_Charge_Relay_Fault; bits4-5: CHG_Communicaiton_Fault; bits6-7: Charger_Warning; bits8-9: CHG_Indication; bits10-11: CHG_Connect_Indication; bits12-13: Turn_Off_Power_Battery; bits14-15: reserved; bits16-31: CHG_MAX_Voltage; bits32-47: CHG_MAX_Current; 
    CAN_ID_AIR_CON_REQ    =    0x18FF45F4,    //    AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; 
    CAN_ID_CHARGER_STATUS    =    0x18FF50E5,    //    ChargerStatusMsg:  bits0-15: outputVolt; bits16-31: outputCurrent; bit32: hardwareFail; bit33: overTemp; bit34: inputVoltError; bit35: batteryConnectError; bit36: CommsError; bit37: ChargerCableConnected; bits38-39: reserved; bits40-47: temperature; 
    CAN_ID_AIR_CON_STATUS    =    0x18FFC13A,    //    AirConStatusMsg:  bits0-7: reserved; bits8-15: airConTemp; bits16-23: roomTemp; 
    CAN_ID_SIGNAL1_DEBUG    =    0x19000010,    //    Signal1Debug:  bits0-7: sigState; bits8-15: steerState; bit16: io1; bit17: io2; bit18: io3; bit19: io4; bit20: io5; bit21: io6; bit22: EHBFire_io7; bit23: VCU_io8; bit24: steerFire; bits25-31: reserved; bit32: aux_in1; bit33: hw_in; bits34-39: reserved1; bits40-63: timestamp; 
    CAN_ID_SIGNAL2_DEBUG    =    0x19000020,    //    Signal2Debug:  bits0-7: sigState; bits8-15: steerState; bit16: io1; bit17: io2; bit18: io3; bit19: io4; bit20: io5; bit21: io6; bit22: EHBFire_io7; bit23: VCU_io8; bit24: steerFire; bits25-31: reserved; bit32: aux_in1; bit33: hw_in; bits34-39: reserved1; bits40-63: timestamp; 
    CAN_ID_DTG_SPEED_RPM    =    0x1B001000,    //    DTGSpeedRpmMsg:  bits0-15: motorRPM; bits16-23: speed; 
    CAN_ID_DTG_BRAKE_INFO    =    0x1B001010,    //    DTGBrakeInfoMsg:  bits0-7: EHBReqPressure; bits8-15: EHBActualPressure; bits16-23: EHBError; bits24-31: reserved; bits32-39: EPBReq; bits40-47: EPBLeftStatus; bits48-55: EPBRightStatus; 
    CAN_ID_BMS_STATUS_MSG111    =    0x1CF301F4,    //    BMSStatusMsg11:  bits0-31: vendorNum; bits32-47: hardwareVersion; bits48-63: softwareVersion; 
    CAN_ID_BMS_STATUS_MSG122    =    0x1CF302F4,    //    BMSStatusMsg12:  bits0-7: chargerPlugPosTemp; bits8-15: chargerPlugNegTemp; bits16-31: resistance; bits32-47: heatCurrent; 
    CAN_ID_PERIPHERAL_VERSION_REQ    =    0x1D000100,    //    PeripheralVersionReqMsg:  bits0-15: id; 
    CAN_ID_PERIPHERAL_VERSION    =    0x1D000101,    //    PeripheralVersionMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_PERIPHERAL_BOOT_VER    =    0x1D000102,    //    PeripheralBootVerMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_PERIPHERAL_OCAN_DBC_VER    =    0x1D000103,    //    PeripheralOcanDBCVerMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_PERIPHERAL_PCAN_DBC_VER    =    0x1D000104,    //    PeripheralPcanDBCVerMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_BMS_LOTTE_TOTAL_CHANGE_VALUE    =    0x3A3A107,    //    BmsLotteTotalChangeValue:  bits0-15: T_Change_Volt; bits16-31: T_Change_Temp; bits32-47: T_Change_Curr; 
    CAN_ID_BMS_REQ    =    0xC66F4F5,    //    BMSReqMsg:  bits0-7: mode; bits8-55: reserved; bits56-63: counter; 
    CAN_ID_BMS_LOTTE_VEHICLECONTROLLER    =    0xCF002EF,    //    BmsLotteVehiclecontroller:  bit0: reserved; bit1: V_BMS_HV_Connect_Cmd; 
    CAN_ID_BMS_LOTTE_STATUS    =    0xCF50124,    //    BmsLotteStatus:  bits0-1: BS_Cell_OVP_Warning; bits2-3: BS_Cell_UVP_Warning; bits4-5: BS_Insulation_Warning; bits6-7: BS_Temperature_Higher_Warning; bits8-9: BS_Contactor_Fault; bits10-11: BS_SOH_Warning; bits12-13: BS_Short_Circuit; bits14-15: BS_Feed_Warning; bits16-19: reserved; bits20-21: BS_Output_OverCurrent_Warning; bits22-23: BS_Cell_Imbalance_Warning; bits24-25: BS_Communication_Fault; bits26-27: BS_Hardware_FaultOWD; bits28-29: BS_Pack_Over_Voltage_Warning; bits30-31: BS_Power_Reduce_Indicator; bit32: BS_Negative_Contactor_Status; bit33: BS_Positive_Contactor_Status; bits34-35: BS_Fault_Level; bit36: BS_ShutDown_Request; bit37: BS_checkover; bit38: reserved1; bit39: BS_TBOX_Drop_Line; bit40: BS_Feedback_Current_Large; bit41: BS_Relay_Adhesion; bits42-43: BS_Pack_UVP_Warning; bits44-45: BS_Pack_Imbalance_TEMP_Warning; bits46-47: BS_Temperature_Lower_Warning; bit48: BS_SOC_high; bit49: BS_Interlock_Error; bit50: BS_Electronic_Lock_Error; bits51-52: BS_Charge_Temperature_High; bits53-54: BS_SOC_Low; bit55: reserved2; bit56: BS_Heating_Relay; bits57-59: reserved3; bits60-61: BS_Slow_Charge_Over_Current; bits62-63: BS_Fast_Charge_Over_Current; 
} COMMON_CAN_P;


// the set of AVAS ERROR 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_AVAS_ERROR, "AVAS ERROR changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_AVAS_ERROR, "AVAS ERROR changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    AVAS_NORMAL    =    0x00,
    AVAS_OVER_CURRENT    =    0x01,
    AVAS_OVER_VOLTAGE    =    0x02,

    /* number of mode in total */
    NUMBER_OF_AVAS_ERROR,
} AVAS_ERROR;

// the set of BMS COMPLETE 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_BMS_COMPLETE, "BMS COMPLETE changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_BMS_COMPLETE, "BMS COMPLETE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_NO_Fault    =    0x00,
    BMS_Level1    =    0x01,
    BMS_Level2    =    0x02,
    BMS_Level3    =    0x03,

    /* number of mode in total */
    NUMBER_OF_BMS_COMPLETE,
} BMS_COMPLETE;

// the set of BMS CONNECT 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_BMS_CONNECT, "BMS CONNECT changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_BMS_CONNECT, "BMS CONNECT changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_No_Connect    =    0x00,
    BMS_Charge    =    0x01,
    BMS_Complate    =    0x02,
    BMS_undefine    =    0x03,

    /* number of mode in total */
    NUMBER_OF_BMS_CONNECT,
} BMS_CONNECT;

// the set of BMS CONNECT IND 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_BMS_CONNECT_IND, "BMS CONNECT IND changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_BMS_CONNECT_IND, "BMS CONNECT IND changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_Not_Conntected    =    0x00,
    BMS_Slow    =    0x01,
    BMS_Fast    =    0x02,

    /* number of mode in total */
    NUMBER_OF_BMS_CONNECT_IND,
} BMS_CONNECT_IND;

// the set of BMS ERROR LEVEL 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_BMS_ERROR_LEVEL, "BMS ERROR LEVEL changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_BMS_ERROR_LEVEL, "BMS ERROR LEVEL changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_NO_ERROR    =    0x00,
    BMS_LEVEL1    =    0x01,
    BMS_LEVEL2    =    0x02,
    BMS_LEVEL3    =    0x03,

    /* number of mode in total */
    NUMBER_OF_BMS_ERROR_LEVEL,
} BMS_ERROR_LEVEL;

// the set of BMS LOAD TYPE 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_BMS_LOAD_TYPE, "BMS LOAD TYPE changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_BMS_LOAD_TYPE, "BMS LOAD TYPE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_Battery    =    0x00,
    BMS_Heating    =    0x01,

    /* number of mode in total */
    NUMBER_OF_BMS_LOAD_TYPE,
} BMS_LOAD_TYPE;

// the set of BMS NORMAL FAULT 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_BMS_NORMAL_FAULT, "BMS NORMAL FAULT changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_BMS_NORMAL_FAULT, "BMS NORMAL FAULT changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_Normal    =    0x00,
    BMS_Fault    =    0x01,

    /* number of mode in total */
    NUMBER_OF_BMS_NORMAL_FAULT,
} BMS_NORMAL_FAULT;

// the set of BMS NORMAL FEED 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_BMS_NORMAL_FEED, "BMS NORMAL FEED changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_BMS_NORMAL_FEED, "BMS NORMAL FEED changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_NormalF    =    0x00,
    BMS_Feed    =    0x01,

    /* number of mode in total */
    NUMBER_OF_BMS_NORMAL_FEED,
} BMS_NORMAL_FEED;

// the set of BMS OPEN CLOSE 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_BMS_OPEN_CLOSE, "BMS OPEN CLOSE changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_BMS_OPEN_CLOSE, "BMS OPEN CLOSE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_OPEN    =    0x00,
    BMS_CLOSE    =    0x01,

    /* number of mode in total */
    NUMBER_OF_BMS_OPEN_CLOSE,
} BMS_OPEN_CLOSE;

// the set of BMS STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x0B == NUMBER_OF_BMS_STATUS, "BMS STATUS changed"); // for C++
// _static_assert(0x0B == NUMBER_OF_BMS_STATUS, "BMS STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BMS_INIT    =    0x00,
    BMS_POWER_ON    =    0x01,
    BMS_PRECHARGE    =    0x02,
    BMS_RESERVED    =    0x03,
    BMS_DISCHARGE    =    0x04,
    BMS_HEATING    =    0x05,
    BMS_SLOW_CHARGE    =    0x06,
    BMS_FAST_CHARGE    =    0x07,
    BMS_COMPLETED_CHARGE    =    0x08,
    BMS_RESERVED2    =    0x09,
    BMS_FAILURE    =    0x0A,

    /* number of mode in total */
    NUMBER_OF_BMS_STATUS,
} BMS_STATUS;

// the set of MBS CHARGE ON 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_MBS_CHARGE_ON, "MBS CHARGE ON changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_MBS_CHARGE_ON, "MBS CHARGE ON changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MBS_Charging    =    0x00,
    MBS_Off    =    0x01,

    /* number of mode in total */
    NUMBER_OF_MBS_CHARGE_ON,
} MBS_CHARGE_ON;

// the set of P EPB REQUEST 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_P_EPB_REQUEST, "P EPB REQUEST changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_P_EPB_REQUEST, "P EPB REQUEST changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    P_EPB_IDLE    =    0x00,
    P_EPB_ENGAGEMENT    =    0x01,
    P_EPB_DIS_ENGAGEMENT    =    0x02,

    /* number of mode in total */
    NUMBER_OF_P_EPB_REQUEST,
} P_EPB_REQUEST;

// the set of P EPB STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x05 == NUMBER_OF_P_EPB_STATUS, "P EPB STATUS changed"); // for C++
// _static_assert(0x05 == NUMBER_OF_P_EPB_STATUS, "P EPB STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    P_EPB_STARTUP    =    0x00,
    P_EPB_ENGAGING    =    0x01,
    P_EPB_ENGAGED    =    0x02,
    P_EPB_DIS_ENGAGING    =    0x03,
    P_EPB_DIS_ENGAGED    =    0x04,

    /* number of mode in total */
    NUMBER_OF_P_EPB_STATUS,
} P_EPB_STATUS;

// the set of POWER REDUCER 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_POWER_REDUCER, "POWER REDUCER changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_POWER_REDUCER, "POWER REDUCER changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    POWER_Normal    =    0x00,
    POWER_Positive_Fault    =    0x01,
    POWER_Negative_Fault    =    0x02,
    POWER_Total_Fault    =    0x03,

    /* number of mode in total */
    NUMBER_OF_POWER_REDUCER,
} POWER_REDUCER;

// the set of WIPER MODE 
// Anywhere in your code using this enum put 
// static_assert(0x09 == NUMBER_OF_WIPER_MODE, "WIPER MODE changed"); // for C++
// _static_assert(0x09 == NUMBER_OF_WIPER_MODE, "WIPER MODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    WIPER_IDLE    =    0x00,
    WIPER_RESET    =    0x01,
    WIPER_INTERVAL    =    0x02,
    WIPER_LOW_SPEED    =    0x03,
    WIPER_HIGH_SPEED    =    0x04,
    WIPER_DONT_CARE    =    0x08,

    /* number of mode in total */
    NUMBER_OF_WIPER_MODE,
} WIPER_MODE;

#endif //peripheral_DBC_MSGID_DBC_TOOL_GENERATED_H
