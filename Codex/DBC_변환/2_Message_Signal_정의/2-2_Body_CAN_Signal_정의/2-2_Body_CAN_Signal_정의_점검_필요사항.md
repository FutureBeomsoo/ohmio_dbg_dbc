# 2-2_Body_CAN_Signal_정의 점검 필요사항

## Big Endian 표기 Signal

- 아래 Signal은 변환 함수의 byte-swap 패턴이 확인되어 DBC에 `@0`으로 표기했다.

| Message | Signal | DBC CAN ID | 원본 CAN ID | start bit | length | factor | offset | min | max | 근거 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| DoorStatusMsg | dcdcVolt | 2420113664 | 0x10400100 | 31 | 16 | 0.049 | 0 | 0 | 3211.215 | dbc_CAN_peripheral.h:314 ToCan temp RoundLimit(msg->dcdcVolt, 0.049) byte-swap |
| DoorStatusMsg | battVolt | 2420113664 | 0x10400100 | 47 | 16 | 0.049 | 0 | 0 | 3211.215 | dbc_CAN_peripheral.h:314 ToCan temp RoundLimit(msg->battVolt, 0.049) byte-swap |
| BMSStatusMsg2 | voltage | 2424567284 | 0x1083F5F4 | 7 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:570 ToCan temp RoundLimit(msg->voltage, 0.1) byte-swap |
| BMSStatusMsg2 | DCLinkVolt | 2424567284 | 0x1083F5F4 | 23 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:570 ToCan temp RoundLimit(msg->DCLinkVolt, 0.1) byte-swap |
| BMSStatusMsg2 | DCCurrent | 2424567284 | 0x1083F5F4 | 39 | 16 | 0.1 | -1000 | -1000 | 1000 | dbc_CAN_peripheral.h:570 ToCan temp RoundLimit(msg->DCCurrent + 1000, 0.1) byte-swap |
| BMSStatusMsg3 | maxDisCur | 2424632820 | 0x1084F5F4 | 7 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:619 ToCan temp RoundLimit(msg->maxDisCur, 0.1) byte-swap |
| BMSStatusMsg3 | maxChargeCur | 2424632820 | 0x1084F5F4 | 23 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:619 ToCan temp RoundLimit(msg->maxChargeCur, 0.1) byte-swap |
| BMSStatusMsg3 | constDisCur | 2424632820 | 0x1084F5F4 | 39 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:619 ToCan temp RoundLimit(msg->constDisCur, 0.1) byte-swap |
| BMSStatusMsg3 | constChargeCur | 2424632820 | 0x1084F5F4 | 55 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:619 ToCan temp RoundLimit(msg->constChargeCur, 0.1) byte-swap |
| BMSStatusMsg4 | remainEnergy | 2424698356 | 0x1085F5F4 | 7 | 16 | 0.1 | 0 | 0 | 1000 | dbc_CAN_peripheral.h:678 ToCan temp RoundLimit(msg->remainEnergy, 0.1) byte-swap |
| BMSStatusMsg4 | insResistance | 2424698356 | 0x1085F5F4 | 39 | 16 | 1 | 0 | 0 | 65535 | dbc_CAN_peripheral.h:678 ToCan temp RoundLimit(msg->insResistance, 1) byte-swap |
| BMSStatusMsg5 | cellSumNum | 2424763892 | 0x1086F5F4 | 55 | 16 | 1 | 0 | 1 | 65535 | dbc_CAN_peripheral.h:736 ToCan temp RoundLimit(msg->cellSumNum, 1) byte-swap |
| BMSStatusMsg6 | maxCellVolt | 2424829428 | 0x1087F5F4 | 7 | 16 | 1 | 0 | 0 | 5000 | dbc_CAN_peripheral.h:783 ToCan temp RoundLimit(msg->maxCellVolt, 1) byte-swap |
| BMSStatusMsg6 | minCellVolt | 2424829428 | 0x1087F5F4 | 23 | 16 | 1 | 0 | 0 | 5000 | dbc_CAN_peripheral.h:783 ToCan temp RoundLimit(msg->minCellVolt, 1) byte-swap |
| BMSStatusMsg6 | averageCellVolt | 2424829428 | 0x1087F5F4 | 55 | 16 | 1 | 0 | 0 | 5000 | dbc_CAN_peripheral.h:783 ToCan temp RoundLimit(msg->averageCellVolt, 1) byte-swap |
| BMSStatusMsg7 | cellSamplingVolt | 2424894964 | 0x1088F5F4 | 23 | 16 | 0.001 | 0 | 0 | 5 | dbc_CAN_peripheral.h:829 ToCan temp RoundLimit(msg->cellSamplingVolt, 0.001) byte-swap |
| BMSStatusMsg7 | cellSamplingVolt2 | 2424894964 | 0x1088F5F4 | 39 | 16 | 0.001 | 0 | 0 | 5 | dbc_CAN_peripheral.h:829 ToCan temp RoundLimit(msg->cellSamplingVolt2, 0.001) byte-swap |
| BMSStatusMsg7 | cellSamplingVolt3 | 2424894964 | 0x1088F5F4 | 55 | 16 | 0.001 | 0 | 0 | 5 | dbc_CAN_peripheral.h:829 ToCan temp RoundLimit(msg->cellSamplingVolt3, 0.001) byte-swap |
| BMSStatusMsg8 | cellSamplingTemp | 2424960500 | 0x1089F5F4 | 23 | 8 | 1 | -40 | -40 | 210 | dbc_CAN_peripheral.h:881 ToCan temp RoundLimit(msg->cellSamplingTemp + 40, 1) byte-swap |
| BMSStatusMsg8 | cellSamplingTemp2 | 2424960500 | 0x1089F5F4 | 31 | 8 | 1 | -40 | -40 | 210 | dbc_CAN_peripheral.h:881 ToCan temp RoundLimit(msg->cellSamplingTemp2 + 40, 1) byte-swap |
| BMSStatusMsg8 | cellSamplingTemp3 | 2424960500 | 0x1089F5F4 | 39 | 8 | 1 | -40 | -40 | 210 | dbc_CAN_peripheral.h:881 ToCan temp RoundLimit(msg->cellSamplingTemp3 + 40, 1) byte-swap |
| BMS2ChargerReqMsg | maxChargeVolt | 2550588916 | 0x1806E5F4 | 7 | 16 | 0.1 | 0 | 0 | 6553.5 | dbc_CAN_peripheral.h:986 ToCan temp RoundLimit(msg->maxChargeVolt, 0.1) byte-swap |
| BMS2ChargerReqMsg | maxChargeCurrent | 2550588916 | 0x1806E5F4 | 23 | 16 | 0.1 | 0 | 0 | 6553.5 | dbc_CAN_peripheral.h:986 ToCan temp RoundLimit(msg->maxChargeCurrent, 0.1) byte-swap |
| BmsLotteLandmark8 | BL8_SW_Ver | 2553780772 | 0x18379A24 | 7 | 16 | 1 | 0 | 0 | 65535 | dbc_CAN_peripheral.h:1588 ToCan temp RoundLimit(msg->BL8_SW_Ver, 1) byte-swap |
| BmsLotteLandmark8 | BL8_HW_Ver | 2553780772 | 0x18379A24 | 23 | 16 | 1 | 0 | 0 | 65535 | dbc_CAN_peripheral.h:1588 ToCan temp RoundLimit(msg->BL8_HW_Ver, 1) byte-swap |
| ChargerStatusMsg | outputVolt | 2566869221 | 0x18FF50E5 | 7 | 16 | 0.1 | 0 | 0 | 6553.5 | dbc_CAN_peripheral.h:1029 ToCan temp RoundLimit(msg->outputVolt, 0.1) byte-swap |
| ChargerStatusMsg | outputCurrent | 2566869221 | 0x18FF50E5 | 23 | 16 | 0.1 | 0 | 0 | 6553.5 | dbc_CAN_peripheral.h:1029 ToCan temp RoundLimit(msg->outputCurrent, 0.1) byte-swap |
| BMSStatusMsg12 | resistance | 2633171700 | 0x1CF302F4 | 23 | 16 | 1 | 0 | 0 | 65535 | dbc_CAN_peripheral.h:941 ToCan temp RoundLimit(msg->resistance, 1) byte-swap |
| BMSStatusMsg12 | heatCurrent | 2633171700 | 0x1CF302F4 | 39 | 16 | 0.1 | -1000 | -1000 | 1000 | dbc_CAN_peripheral.h:941 ToCan temp RoundLimit(msg->heatCurrent + 1000, 0.1) byte-swap |

## 예약 필드 제외 목록

| Message | DBC CAN ID | 원본 CAN ID | Struct | Field | start bit | length | 원본 헤더 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| AVASReqMsg | 2164588560 | 0x1050010 | AVASReqMsg_t | reserved | 9 | 39 | dbc_CAN_peripheral.h |
| AVASStatusMsg | 2164588575 | 0x105001F | AVASStatusMsg_t | reserved | 1 | 7 | dbc_CAN_peripheral.h |
| AVASStatusMsg | 2164588575 | 0x105001F | AVASStatusMsg_t | reserved1 | 24 | 24 | dbc_CAN_peripheral.h |
| BMSReqMsg | 2355557621 | 0xC66F4F5 | BMSReqMsg_t | reserved | 8 | 48 | dbc_CAN_peripheral.h |
| BmsLotteVehiclecontroller | 2364539631 | 0xCF002EF | BmsLotteVehiclecontroller_t | reserved | 0 | 1 | dbc_CAN_peripheral.h |
| BmsLotteStatus | 2364866852 | 0xCF50124 | BmsLotteStatus_t | reserved | 16 | 4 | dbc_CAN_peripheral.h |
| BmsLotteStatus | 2364866852 | 0xCF50124 | BmsLotteStatus_t | reserved1 | 38 | 1 | dbc_CAN_peripheral.h |
| BmsLotteStatus | 2364866852 | 0xCF50124 | BmsLotteStatus_t | reserved2 | 55 | 1 | dbc_CAN_peripheral.h |
| BmsLotteStatus | 2364866852 | 0xCF50124 | BmsLotteStatus_t | reserved3 | 57 | 3 | dbc_CAN_peripheral.h |
| FrontLightReq | 2420113408 | 0x10400000 | FrontLightMsg_t | reserved | 24 | 8 | dbc_CAN_peripheral.h |
| FrontLightStatus | 2420113415 | 0x10400007 | FrontLightMsg_t | reserved | 24 | 8 | dbc_CAN_peripheral.h |
| RearLightReq | 2420113416 | 0x10400008 | RearLightMsg_t | reserved | 32 | 16 | dbc_CAN_peripheral.h |
| RearLightStatus | 2420113423 | 0x1040000F | RearLightMsg_t | reserved | 32 | 16 | dbc_CAN_peripheral.h |
| DoorStatusMsg | 2420113664 | 0x10400100 | DoorStatusMsg_t | reserved | 15 | 1 | dbc_CAN_peripheral.h |
| DoorStatusMsg | 2420113664 | 0x10400100 | DoorStatusMsg_t | reserved1 | 21 | 3 | dbc_CAN_peripheral.h |
| StepReqMsg | 2420113921 | 0x10400201 | StepReqMsg_t | reserved | 2 | 46 | dbc_CAN_peripheral.h |
| StepStatusMsg | 2420113928 | 0x10400208 | StepStatusMsg_t | reserved | 6 | 10 | dbc_CAN_peripheral.h |
| StepStatusMsg | 2420113928 | 0x10400208 | StepStatusMsg_t | reserved1 | 32 | 16 | dbc_CAN_peripheral.h |
| Foot2Status | 2422210592 | 0x10600020 | Foot2Status_t | reserved | 41 | 7 | dbc_CAN_peripheral.h |
| Wiper1ReqMsg | 2423259136 | 0x10700000 | WiperMsg_t | reserved | 5 | 3 | dbc_CAN_peripheral.h |
| Wiper1StatusMsg | 2423259151 | 0x1070000F | WiperMsg_t | reserved | 5 | 3 | dbc_CAN_peripheral.h |
| Wiper2ReqMsg | 2423259152 | 0x10700010 | WiperMsg_t | reserved | 5 | 3 | dbc_CAN_peripheral.h |
| Wiper2StatusMsg | 2423259167 | 0x1070001F | WiperMsg_t | reserved | 5 | 3 | dbc_CAN_peripheral.h |
| BMSStatusMsg1 | 2424501748 | 0x1082F5F4 | BMSStatusMsg1_t | reserved | 46 | 1 | dbc_CAN_peripheral.h |
| BMSStatusMsg2 | 2424567284 | 0x1083F5F4 | BMSStatusMsg2_t | reserved | 52 | 4 | dbc_CAN_peripheral.h |
| BMS2ChargerReqMsg | 2550588916 | 0x1806E5F4 | BMS2ChargerReqMsg_t | reserved | 33 | 7 | dbc_CAN_peripheral.h |
| BmsLotteChargerInfo | 2565160996 | 0x18E54024 | BmsLotteChargerInfo_t | reserved | 2 | 6 | dbc_CAN_peripheral.h |
| BmsLotteChargerInfo | 2565160996 | 0x18E54024 | BmsLotteChargerInfo_t | reserved1 | 42 | 6 | dbc_CAN_peripheral.h |
| BmsLotteChargeVehicle | 2566747428 | 0x18FD7524 | BmsLotteChargeVehicle_t | reserved | 14 | 2 | dbc_CAN_peripheral.h |
| ChargerStatusMsg | 2566869221 | 0x18FF50E5 | ChargerStatusMsg_t | reserved | 38 | 2 | dbc_CAN_peripheral.h |
| AirConStatusMsg | 2566897978 | 0x18FFC13A | AirConStatusMsg_t | reserved | 0 | 8 | dbc_CAN_peripheral.h |
| AirConVersionMsg | 2566897979 | 0x18FFC13B | AirConVersionMsg_t | reserved | 0 | 8 | dbc_CAN_peripheral.h |
| AirConJJK161StatusMsg | 2566897980 | 0x18FFC13C | AirConJJK161StatusMsg_t | reserved | 2 | 2 | dbc_CAN_peripheral.h |
| AirConJJK161StatusMsg | 2566897980 | 0x18FFC13C | AirConJJK161StatusMsg_t | reserved1 | 11 | 5 | dbc_CAN_peripheral.h |
| AirConJJK161StatusMsg | 2566897980 | 0x18FFC13C | AirConJJK161StatusMsg_t | reserved2 | 48 | 8 | dbc_CAN_peripheral.h |
| Signal1Debug | 2566914064 | 0x19000010 | SignalDebugMsg_t | reserved | 25 | 7 | dbc_CAN_peripheral.h |
| Signal1Debug | 2566914064 | 0x19000010 | SignalDebugMsg_t | reserved1 | 34 | 6 | dbc_CAN_peripheral.h |
| Signal2Debug | 2566914080 | 0x19000020 | SignalDebugMsg_t | reserved | 25 | 7 | dbc_CAN_peripheral.h |
| Signal2Debug | 2566914080 | 0x19000020 | SignalDebugMsg_t | reserved1 | 34 | 6 | dbc_CAN_peripheral.h |
| DTGBrakeInfoMsg | 2600472592 | 0x1B001010 | DTGBrakeInfoMsg_t | reserved | 24 | 8 | dbc_CAN_peripheral.h |
| Recovery | 2667577344 | 0x1F000000 | Recovery_t | reserved | 0 | 8 | dbc_CAN_peripheral.h |

## 기본값 적용 또는 수동 점검 대상

- 변환 함수에서 factor/offset을 직접 확정하지 못한 항목은 기본값으로 작성했다.

| Message | Signal | DBC CAN ID | 원본 CAN ID | start bit | length | factor | offset | min | max | 상태 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| AVASReqMsg | reverse | 2164588560 | 0x1050010 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| AVASReqMsg | count | 2164588560 | 0x1050010 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| AVASReqMsg | checksum | 2164588560 | 0x1050010 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| AVASStatusMsg | active | 2164588575 | 0x105001F | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AVASStatusMsg | error | 2164588575 | 0x105001F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| AVASStatusMsg | count | 2164588575 | 0x105001F | 48 | 8 | 1 | 0 | 0 | 255 | default |
| AVASStatusMsg | checksum | 2164588575 | 0x105001F | 56 | 8 | 1 | 0 | 0 | 255 | default |
| CollisionEventInfo | counter | 2222981531 | 0x480019B | 0 | 8 | 1 | 0 | 0 | 255 | default |
| CollisionEventInfo | remoteID | 2222981531 | 0x480019B | 8 | 8 | 1 | 0 | 0 | 255 | default |
| CollisionEventInfo | distance | 2222981531 | 0x480019B | 16 | 8 | 1 | 0 | 0 | 255 | default |
| CollisionEventInfo | direction | 2222981531 | 0x480019B | 24 | 4 | 1 | 0 | 0 | 15 | default |
| CollisionEventInfo | status | 2222981531 | 0x480019B | 28 | 4 | 1 | 0 | 0 | 15 | default |
| CollisionEventInfo | timestamp | 2222981531 | 0x480019B | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| BMSReqMsg | mode | 2355557621 | 0xC66F4F5 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| BMSReqMsg | counter | 2355557621 | 0xC66F4F5 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteVehiclecontroller | V_BMS_HV_Connect_Cmd | 2364539631 | 0xCF002EF | 1 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Cell_OVP_Warning | 2364866852 | 0xCF50124 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Cell_UVP_Warning | 2364866852 | 0xCF50124 | 2 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Insulation_Warning | 2364866852 | 0xCF50124 | 4 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Temperature_Higher_Warning | 2364866852 | 0xCF50124 | 6 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Contactor_Fault | 2364866852 | 0xCF50124 | 8 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_SOH_Warning | 2364866852 | 0xCF50124 | 10 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Short_Circuit | 2364866852 | 0xCF50124 | 12 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Feed_Warning | 2364866852 | 0xCF50124 | 14 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Output_OverCurrent_Warning | 2364866852 | 0xCF50124 | 20 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Cell_Imbalance_Warning | 2364866852 | 0xCF50124 | 22 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Communication_Fault | 2364866852 | 0xCF50124 | 24 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Hardware_FaultOWD | 2364866852 | 0xCF50124 | 26 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Pack_Over_Voltage_Warning | 2364866852 | 0xCF50124 | 28 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Power_Reduce_Indicator | 2364866852 | 0xCF50124 | 30 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Negative_Contactor_Status | 2364866852 | 0xCF50124 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Positive_Contactor_Status | 2364866852 | 0xCF50124 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Fault_Level | 2364866852 | 0xCF50124 | 34 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_ShutDown_Request | 2364866852 | 0xCF50124 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_checkover | 2364866852 | 0xCF50124 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_TBOX_Drop_Line | 2364866852 | 0xCF50124 | 39 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Feedback_Current_Large | 2364866852 | 0xCF50124 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Relay_Adhesion | 2364866852 | 0xCF50124 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Pack_UVP_Warning | 2364866852 | 0xCF50124 | 42 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Pack_Imbalance_TEMP_Warning | 2364866852 | 0xCF50124 | 44 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Temperature_Lower_Warning | 2364866852 | 0xCF50124 | 46 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_SOC_high | 2364866852 | 0xCF50124 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Interlock_Error | 2364866852 | 0xCF50124 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Electronic_Lock_Error | 2364866852 | 0xCF50124 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Charge_Temperature_High | 2364866852 | 0xCF50124 | 51 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_SOC_Low | 2364866852 | 0xCF50124 | 53 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Heating_Relay | 2364866852 | 0xCF50124 | 56 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteStatus | BS_Slow_Charge_Over_Current | 2364866852 | 0xCF50124 | 60 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteStatus | BS_Fast_Charge_Over_Current | 2364866852 | 0xCF50124 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| voiceReq | command | 2418016256 | 0x10200000 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| voiceReq | value | 2418016256 | 0x10200000 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| voiceResp | command | 2418016271 | 0x1020000F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| voiceResp | value | 2418016271 | 0x1020000F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| FrontMainLightReqMsg | on | 2419065088 | 0x10300100 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontMainLightStatusMsg | on | 2419065103 | 0x1030010F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontDipLightReqMsg | on | 2419065104 | 0x10300110 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontDipLightStatusMsg | on | 2419065119 | 0x1030011F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontDayLightReqMsg | on | 2419065120 | 0x10300120 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontDayLightStatusMsg | on | 2419065135 | 0x1030012F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontPosOutlineMarkerReqMsg | on | 2419065136 | 0x10300130 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontPosOutlineMarkerStatusMsg | on | 2419065151 | 0x1030013F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearReverseLightReqMsg | on | 2419065344 | 0x10300200 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearReverseLightStatusMsg | on | 2419065359 | 0x1030020F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearTailOutlineMarkerReqMsg | on | 2419065360 | 0x10300210 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearTailOutlineMarkerStatusMsg | on | 2419065375 | 0x1030021F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearRegLightReqMsg | on | 2419065376 | 0x10300220 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearRegLightStatusMsg | on | 2419065391 | 0x1030022F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| HornReqMsg | on | 2419065600 | 0x10300300 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| HornStatusMsg | on | 2419065615 | 0x1030030F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightReq | mainLeft | 2420113408 | 0x10400000 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightReq | mainRight | 2420113408 | 0x10400000 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightReq | logo | 2420113408 | 0x10400000 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightReq | internalPWM | 2420113408 | 0x10400000 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightStatus | mainLeft | 2420113415 | 0x10400007 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightStatus | mainRight | 2420113415 | 0x10400007 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightStatus | logo | 2420113415 | 0x10400007 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLightStatus | internalPWM | 2420113415 | 0x10400007 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | mainLeft | 2420113416 | 0x10400008 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | mainRight | 2420113416 | 0x10400008 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | logo | 2420113416 | 0x10400008 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | audio | 2420113416 | 0x10400008 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | horn | 2420113416 | 0x10400008 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightReq | flash | 2420113416 | 0x10400008 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | mainLeft | 2420113423 | 0x1040000F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | mainRight | 2420113423 | 0x1040000F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | logo | 2420113423 | 0x1040000F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | audio | 2420113423 | 0x1040000F | 24 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | horn | 2420113423 | 0x1040000F | 48 | 8 | 1 | 0 | 0 | 255 | default |
| RearLightStatus | flash | 2420113423 | 0x1040000F | 56 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | mode | 2420113424 | 0x10400010 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | fixBright | 2420113424 | 0x10400010 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | redBright | 2420113424 | 0x10400010 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | greenBright | 2420113424 | 0x10400010 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | blueBright | 2420113424 | 0x10400010 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | redError | 2420113424 | 0x10400010 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | greenError | 2420113424 | 0x10400010 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftStatus | blueError | 2420113424 | 0x10400010 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftReq | mode | 2420113439 | 0x1040001F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftReq | fixBright | 2420113439 | 0x1040001F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftReq | redBright | 2420113439 | 0x1040001F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftReq | greenBright | 2420113439 | 0x1040001F | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontLeftReq | blueBright | 2420113439 | 0x1040001F | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | mode | 2420113440 | 0x10400020 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | fixBright | 2420113440 | 0x10400020 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | redBright | 2420113440 | 0x10400020 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | greenBright | 2420113440 | 0x10400020 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | blueBright | 2420113440 | 0x10400020 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | redError | 2420113440 | 0x10400020 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | greenError | 2420113440 | 0x10400020 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightStatus | blueError | 2420113440 | 0x10400020 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightReq | mode | 2420113455 | 0x1040002F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightReq | fixBright | 2420113455 | 0x1040002F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightReq | redBright | 2420113455 | 0x1040002F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightReq | greenBright | 2420113455 | 0x1040002F | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalFrontRightReq | blueBright | 2420113455 | 0x1040002F | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | mode | 2420113456 | 0x10400030 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | fixBright | 2420113456 | 0x10400030 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | redBright | 2420113456 | 0x10400030 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | greenBright | 2420113456 | 0x10400030 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | blueBright | 2420113456 | 0x10400030 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | redError | 2420113456 | 0x10400030 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | greenError | 2420113456 | 0x10400030 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftStatus | blueError | 2420113456 | 0x10400030 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftReq | mode | 2420113471 | 0x1040003F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftReq | fixBright | 2420113471 | 0x1040003F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftReq | redBright | 2420113471 | 0x1040003F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftReq | greenBright | 2420113471 | 0x1040003F | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearLeftReq | blueBright | 2420113471 | 0x1040003F | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | mode | 2420113472 | 0x10400040 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | fixBright | 2420113472 | 0x10400040 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | redBright | 2420113472 | 0x10400040 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | greenBright | 2420113472 | 0x10400040 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | blueBright | 2420113472 | 0x10400040 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | redError | 2420113472 | 0x10400040 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | greenError | 2420113472 | 0x10400040 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightStatus | blueError | 2420113472 | 0x10400040 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightReq | mode | 2420113487 | 0x1040004F | 0 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightReq | fixBright | 2420113487 | 0x1040004F | 8 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightReq | redBright | 2420113487 | 0x1040004F | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightReq | greenBright | 2420113487 | 0x1040004F | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OvalRearRightReq | blueBright | 2420113487 | 0x1040004F | 32 | 8 | 1 | 0 | 0 | 255 | default |
| DoorStatusMsg | heartbeat | 2420113664 | 0x10400100 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| DoorStatusMsg | opening | 2420113664 | 0x10400100 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | closing | 2420113664 | 0x10400100 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | opened | 2420113664 | 0x10400100 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | closed | 2420113664 | 0x10400100 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | openTimeout | 2420113664 | 0x10400100 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | closeTimeout | 2420113664 | 0x10400100 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | buttonEnable | 2420113664 | 0x10400100 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | doorLock | 2420113664 | 0x10400100 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | doorClamp | 2420113664 | 0x10400100 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | fault1 | 2420113664 | 0x10400100 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | fault2 | 2420113664 | 0x10400100 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| DoorStatusMsg | buttonPressed | 2420113664 | 0x10400100 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| DoorReqMsg | heartbeat | 2420113671 | 0x10400107 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| DoorReqMsg | open | 2420113671 | 0x10400107 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| DoorReqMsg | close | 2420113671 | 0x10400107 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| DoorReqMsg | buttonEnable | 2420113671 | 0x10400107 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| StepReqMsg | in | 2420113921 | 0x10400201 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| StepReqMsg | out | 2420113921 | 0x10400201 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| StepReqMsg | count | 2420113921 | 0x10400201 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| StepReqMsg | checksum | 2420113921 | 0x10400201 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| StepStatusMsg | status | 2420113928 | 0x10400208 | 0 | 3 | 1 | 0 | 0 | 4 | default |
| StepStatusMsg | motorFault | 2420113928 | 0x10400208 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| StepStatusMsg | overCurrent | 2420113928 | 0x10400208 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| StepStatusMsg | overWeight | 2420113928 | 0x10400208 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| StepStatusMsg | count | 2420113928 | 0x10400208 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| StepStatusMsg | checksum | 2420113928 | 0x10400208 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| FootReqMsg | request | 2422210560 | 0x10600000 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FootReqMsg | liftFire | 2422210560 | 0x10600000 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| Foot1Status | status | 2422210576 | 0x10600010 | 0 | 8 | 1 | 0 | 0 | 3 | default |
| Foot1Status | mode | 2422210576 | 0x10600010 | 8 | 8 | 1 | 0 | 0 | 2 | default |
| Foot1Status | error | 2422210576 | 0x10600010 | 16 | 8 | 1 | 0 | 0 | 1 | default |
| Foot2Status | status | 2422210592 | 0x10600020 | 0 | 8 | 1 | 0 | 0 | 3 | default |
| Foot2Status | mode | 2422210592 | 0x10600020 | 8 | 8 | 1 | 0 | 0 | 2 | default |
| Foot2Status | error | 2422210592 | 0x10600020 | 16 | 8 | 1 | 0 | 0 | 1 | default |
| Foot2Status | liftFireStatus | 2422210592 | 0x10600020 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| Foot2Status | liftOutStatus | 2422210592 | 0x10600020 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| Wiper1ReqMsg | mode | 2423259136 | 0x10700000 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Wiper1ReqMsg | washer | 2423259136 | 0x10700000 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| Wiper1StatusMsg | mode | 2423259151 | 0x1070000F | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Wiper1StatusMsg | washer | 2423259151 | 0x1070000F | 4 | 1 | 1 | 0 | 0 | 1 | default |
| Wiper2ReqMsg | mode | 2423259152 | 0x10700010 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Wiper2ReqMsg | washer | 2423259152 | 0x10700010 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| Wiper2StatusMsg | mode | 2423259167 | 0x1070001F | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Wiper2StatusMsg | washer | 2423259167 | 0x1070001F | 4 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | errorLevel | 2424501748 | 0x1082F5F4 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | status | 2424501748 | 0x1082F5F4 | 2 | 4 | 1 | 0 | 0 | 15 | default |
| BMSStatusMsg1 | quickChargeReq | 2424501748 | 0x1082F5F4 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | slowChargeReq | 2424501748 | 0x1082F5F4 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | insulationError | 2424501748 | 0x1082F5F4 | 8 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | overCurrent | 2424501748 | 0x1082F5F4 | 10 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | overTemp | 2424501748 | 0x1082F5F4 | 12 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | unevenTemp | 2424501748 | 0x1082F5F4 | 14 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | unbalanceVolt | 2424501748 | 0x1082F5F4 | 16 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | lowSOC | 2424501748 | 0x1082F5F4 | 18 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | highSOC | 2424501748 | 0x1082F5F4 | 20 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | lowTemp | 2424501748 | 0x1082F5F4 | 22 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | highInrushCurrent | 2424501748 | 0x1082F5F4 | 24 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | highVolt | 2424501748 | 0x1082F5F4 | 26 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | lowVolt | 2424501748 | 0x1082F5F4 | 28 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | highCellVolt | 2424501748 | 0x1082F5F4 | 30 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | lowCellVolt | 2424501748 | 0x1082F5F4 | 32 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | highFeedbackCurrent | 2424501748 | 0x1082F5F4 | 34 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | currentSensorError | 2424501748 | 0x1082F5F4 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | commsError | 2424501748 | 0x1082F5F4 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | TempSensorError | 2424501748 | 0x1082F5F4 | 38 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | slowChargeOverCurrent | 2424501748 | 0x1082F5F4 | 39 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | prechargeError | 2424501748 | 0x1082F5F4 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | chargeInterlockError | 2424501748 | 0x1082F5F4 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | dischargeInterlockError | 2424501748 | 0x1082F5F4 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | positiveRelayError | 2424501748 | 0x1082F5F4 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | negativeRelayError | 2424501748 | 0x1082F5F4 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | voltSamplingLineBroke | 2424501748 | 0x1082F5F4 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | batteryPackUnmatch | 2424501748 | 0x1082F5F4 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | internalCommsError | 2424501748 | 0x1082F5F4 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | cellVoltSamplingLineBroke | 2424501748 | 0x1082F5F4 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | tempSamplingLineBroke | 2424501748 | 0x1082F5F4 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | currentSamplingLineBroke | 2424501748 | 0x1082F5F4 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | fastChargeCommsError | 2424501748 | 0x1082F5F4 | 52 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | carChargeCommsError | 2424501748 | 0x1082F5F4 | 53 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg1 | continuousDischargeOverCurrent | 2424501748 | 0x1082F5F4 | 54 | 2 | 1 | 0 | 0 | 3 | default |
| BMSStatusMsg1 | counter | 2424501748 | 0x1082F5F4 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg2 | chargerPlugOverTemp | 2424567284 | 0x1083F5F4 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg2 | chargerPlugTempLineBroke | 2424567284 | 0x1083F5F4 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg2 | heatRelayError | 2424567284 | 0x1083F5F4 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg2 | heatCircuitError | 2424567284 | 0x1083F5F4 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg2 | counter | 2424567284 | 0x1083F5F4 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg4 | posRelayClosed | 2424698356 | 0x1085F5F4 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | negRelayClosed | 2424698356 | 0x1085F5F4 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | preRelayClosed | 2424698356 | 0x1085F5F4 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | chargeRelayClosed | 2424698356 | 0x1085F5F4 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | fastChargeConnected | 2424698356 | 0x1085F5F4 | 52 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | heatRelayClosed | 2424698356 | 0x1085F5F4 | 53 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | disconnectReq | 2424698356 | 0x1085F5F4 | 54 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | slowChargeConnected | 2424698356 | 0x1085F5F4 | 55 | 1 | 1 | 0 | 0 | 1 | default |
| BMSStatusMsg4 | counter | 2424698356 | 0x1085F5F4 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg5 | tempSensorNum | 2424763892 | 0x1086F5F4 | 8 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg5 | maxTempNum | 2424763892 | 0x1086F5F4 | 32 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg5 | minTempNum | 2424763892 | 0x1086F5F4 | 40 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg6 | maxCellVoltNum | 2424829428 | 0x1087F5F4 | 32 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg6 | minCellVoltNum | 2424829428 | 0x1087F5F4 | 40 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg7 | totalPacketFrames | 2424894964 | 0x1088F5F4 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg7 | packetSeqNum | 2424894964 | 0x1088F5F4 | 8 | 8 | 1 | 0 | 1 | 255 | default |
| BMSStatusMsg8 | totalPacketFrames | 2424960500 | 0x1089F5F4 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg8 | packetSeqNum | 2424960500 | 0x1089F5F4 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg8 | cellSamplingTemp4 | 2424960500 | 0x1089F5F4 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg8 | cellSamplingTemp5 | 2424960500 | 0x1089F5F4 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg8 | cellSamplingTemp6 | 2424960500 | 0x1089F5F4 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BMS2ChargerReqMsg | outputOff | 2550588916 | 0x1806E5F4 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| BMS2ChargerReqMsg | heating | 2550588916 | 0x1806E5F4 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteLandmark7 | BMS_Serial_PC | 2553715236 | 0x18369A24 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteChargerInfo | CHG_Control | 2565160996 | 0x18E54024 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargerInfo | Load_Type | 2565160996 | 0x18E54024 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteChargerInfo | Load_Relay_Mode | 2565160996 | 0x18E54024 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| BmsLotteChargerInfo | Remaining_Charging_Time | 2565160996 | 0x18E54024 | 48 | 16 | 1 | 0 | 0 | 65535 | default |
| BmsLotteDrive1 | BD1_Posi_ISO_Resistor | 2566197540 | 0x18F51124 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| BmsLotteDrive1 | BD1_SOC | 2566197540 | 0x18F51124 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive1 | BD1_Number_of_Battery | 2566197540 | 0x18F51124 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive2 | BD2_Cell_MAX_Volt_NO | 2566201892 | 0x18F52224 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive2 | BD2_Cell_MIN_Volt_NO | 2566201892 | 0x18F52224 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive2 | BD2_SOH | 2566201892 | 0x18F52224 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive2 | BD2_Battery_Capacity | 2566201892 | 0x18F52224 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Max_Temp_NO | 2566206244 | 0x18F53324 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Min_Temp_NO | 2566206244 | 0x18F53324 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Vehicle_MAX_Charge_Power | 2566206244 | 0x18F53324 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Vehicle_MAX_Discharge_Power | 2566206244 | 0x18F53324 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Vehicle_Rated_CHG_Power | 2566206244 | 0x18F53324 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteDrive3 | BD3_Vehicle_RatedDisCHG_Power | 2566206244 | 0x18F53324 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| BmsLotteChargeVehicle | Charge_OverCurrent | 2566747428 | 0x18FD7524 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | Auxiliary_Charge_Relay_Fault | 2566747428 | 0x18FD7524 | 2 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | CHG_Communicaiton_Fault | 2566747428 | 0x18FD7524 | 4 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | Charger_Warning | 2566747428 | 0x18FD7524 | 6 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | CHG_Indication | 2566747428 | 0x18FD7524 | 8 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | CHG_Connect_Indication | 2566747428 | 0x18FD7524 | 10 | 2 | 1 | 0 | 0 | 3 | default |
| BmsLotteChargeVehicle | Turn_Off_Power_Battery | 2566747428 | 0x18FD7524 | 12 | 2 | 1 | 0 | 0 | 3 | default |
| AirConReqMsg | mode | 2566866420 | 0x18FF45F4 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| AirConReqMsg | level | 2566866420 | 0x18FF45F4 | 2 | 2 | 1 | 0 | 0 | 3 | default |
| AirConReqMsg | roofLight | 2566866420 | 0x18FF45F4 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| AirConReqMsg | JJK161Level | 2566866420 | 0x18FF45F4 | 16 | 3 | 1 | 0 | 0 | 7 | default |
| ChargerStatusMsg | hardwareFail | 2566869221 | 0x18FF50E5 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| ChargerStatusMsg | overTemp | 2566869221 | 0x18FF50E5 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| ChargerStatusMsg | inputVoltError | 2566869221 | 0x18FF50E5 | 34 | 1 | 1 | 0 | 0 | 1 | default |
| ChargerStatusMsg | batteryConnectError | 2566869221 | 0x18FF50E5 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| ChargerStatusMsg | CommsError | 2566869221 | 0x18FF50E5 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| ChargerStatusMsg | ChargerCableConnected | 2566869221 | 0x18FF50E5 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| AirConVersionMsg | ManufactCode | 2566897979 | 0x18FFC13B | 8 | 8 | 1 | 0 | 0 | 255 | default |
| AirConVersionMsg | HWMajorVer | 2566897979 | 0x18FFC13B | 16 | 8 | 1 | 0 | 0 | 255 | default |
| AirConVersionMsg | HWMinorVer | 2566897979 | 0x18FFC13B | 24 | 8 | 1 | 0 | 0 | 255 | default |
| AirConJJK161StatusMsg | mode | 2566897980 | 0x18FFC13C | 0 | 2 | 1 | 0 | 0 | 3 | default |
| AirConJJK161StatusMsg | reqTemp | 2566897980 | 0x18FFC13C | 4 | 4 | 1 | 0 | 0 | 15 | default |
| AirConJJK161StatusMsg | level | 2566897980 | 0x18FFC13C | 8 | 3 | 1 | 0 | 0 | 7 | default |
| AirConJJK161StatusMsg | airConTemp1 | 2566897980 | 0x18FFC13C | 16 | 8 | 1 | 0 | 0 | 255 | default |
| AirConJJK161StatusMsg | airConTemp2 | 2566897980 | 0x18FFC13C | 24 | 8 | 1 | 0 | 0 | 255 | default |
| AirConJJK161StatusMsg | roomTemp | 2566897980 | 0x18FFC13C | 32 | 8 | 1 | 0 | 0 | 255 | default |
| AirConJJK161StatusMsg | outdoorTemp | 2566897980 | 0x18FFC13C | 40 | 8 | 1 | 0 | 0 | 255 | default |
| AirConJJK161StatusMsg | errorCode | 2566897980 | 0x18FFC13C | 56 | 6 | 1 | 0 | 0 | 63 | default |
| AirConJJK161StatusMsg | errorLevel | 2566897980 | 0x18FFC13C | 62 | 2 | 1 | 0 | 0 | 3 | default |
| Signal1Debug | sigState | 2566914064 | 0x19000010 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| Signal1Debug | steerState | 2566914064 | 0x19000010 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| Signal1Debug | io1 | 2566914064 | 0x19000010 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | io2 | 2566914064 | 0x19000010 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | io3 | 2566914064 | 0x19000010 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | io4 | 2566914064 | 0x19000010 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | io5 | 2566914064 | 0x19000010 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | io6 | 2566914064 | 0x19000010 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | EHBFire_io7 | 2566914064 | 0x19000010 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | VCU_io8 | 2566914064 | 0x19000010 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | steerFire | 2566914064 | 0x19000010 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | aux_in1 | 2566914064 | 0x19000010 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | hw_in | 2566914064 | 0x19000010 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| Signal1Debug | timestamp | 2566914064 | 0x19000010 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Signal2Debug | sigState | 2566914080 | 0x19000020 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| Signal2Debug | steerState | 2566914080 | 0x19000020 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| Signal2Debug | io1 | 2566914080 | 0x19000020 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | io2 | 2566914080 | 0x19000020 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | io3 | 2566914080 | 0x19000020 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | io4 | 2566914080 | 0x19000020 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | io5 | 2566914080 | 0x19000020 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | io6 | 2566914080 | 0x19000020 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | EHBFire_io7 | 2566914080 | 0x19000020 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | VCU_io8 | 2566914080 | 0x19000020 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | steerFire | 2566914080 | 0x19000020 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | aux_in1 | 2566914080 | 0x19000020 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | hw_in | 2566914080 | 0x19000020 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| Signal2Debug | timestamp | 2566914080 | 0x19000020 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| DTGSpeedRpmMsg | speed | 2600472576 | 0x1B001000 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EHBReqPressure | 2600472592 | 0x1B001010 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EHBActualPressure | 2600472592 | 0x1B001010 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EHBError | 2600472592 | 0x1B001010 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EPBReq | 2600472592 | 0x1B001010 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EPBLeftStatus | 2600472592 | 0x1B001010 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| DTGBrakeInfoMsg | EPBRightStatus | 2600472592 | 0x1B001010 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusMsg11 | vendorNum | 2633171444 | 0x1CF301F4 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| BMSStatusMsg11 | hardwareVersion | 2633171444 | 0x1CF301F4 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| BMSStatusMsg11 | softwareVersion | 2633171444 | 0x1CF301F4 | 48 | 16 | 1 | 0 | 0 | 65535 | default |
| BMSChargingCurrent | byte0 | 2633171956 | 0x1CF303F4 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| BMSChargingCurrent | byte1 | 2633171956 | 0x1CF303F4 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| BMSChargingCurrent | byte2 | 2633171956 | 0x1CF303F4 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| BMSChargingCurrent | ChargeCurrent | 2633171956 | 0x1CF303F4 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| BMSChargingCurrent | byte4 | 2633171956 | 0x1CF303F4 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| BMSChargingCurrentReply | ChargingCurrent | 2633172212 | 0x1CF304F4 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| PeripheralVersionReqMsg | id | 2634023168 | 0x1D000100 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PeripheralVersionMsg | id | 2634023169 | 0x1D000101 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PeripheralVersionMsg | major | 2634023169 | 0x1D000101 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| PeripheralVersionMsg | debug | 2634023169 | 0x1D000101 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| PeripheralVersionMsg | minor | 2634023169 | 0x1D000101 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| PeripheralVersionMsg | build | 2634023169 | 0x1D000101 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| PeripheralBootVerMsg | id | 2634023170 | 0x1D000102 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PeripheralBootVerMsg | major | 2634023170 | 0x1D000102 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| PeripheralBootVerMsg | debug | 2634023170 | 0x1D000102 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| PeripheralBootVerMsg | minor | 2634023170 | 0x1D000102 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| PeripheralBootVerMsg | build | 2634023170 | 0x1D000102 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| PeripheralOcanDBCVerMsg | id | 2634023171 | 0x1D000103 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PeripheralOcanDBCVerMsg | major | 2634023171 | 0x1D000103 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| PeripheralOcanDBCVerMsg | debug | 2634023171 | 0x1D000103 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| PeripheralOcanDBCVerMsg | minor | 2634023171 | 0x1D000103 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| PeripheralOcanDBCVerMsg | build | 2634023171 | 0x1D000103 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| PeripheralPcanDBCVerMsg | id | 2634023172 | 0x1D000104 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PeripheralPcanDBCVerMsg | major | 2634023172 | 0x1D000104 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| PeripheralPcanDBCVerMsg | debug | 2634023172 | 0x1D000104 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| PeripheralPcanDBCVerMsg | minor | 2634023172 | 0x1D000104 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| PeripheralPcanDBCVerMsg | build | 2634023172 | 0x1D000104 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |

## 추가 점검 메모
