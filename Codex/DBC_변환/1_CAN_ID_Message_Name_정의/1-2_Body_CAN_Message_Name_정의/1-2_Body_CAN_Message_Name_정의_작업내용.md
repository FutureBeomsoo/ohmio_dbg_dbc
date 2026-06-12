# 1-2_Body_CAN_Message_Name_정의 작업내용

## 작업 개요

- 작업 일시: 2026-06-12 10:56:38 KST
- CAN 구분: Body CAN
- CAN 형식: CAN 2.0B
- DBC CAN ID 표기: CAN 2.0B 확장 ID는 원본 CAN ID에 `0x80000000` 플래그를 더한 Vector DBC 10진수 표기를 적용했다.
- Baudrate: 250000
- 작업 범위: CAN ID, Message Name, DLC, Transmit Node, Signal 참고 Struct comment 정의
- 원본 파일은 수정하지 않았다.

## 참조 파일별 결과

| 파일 | 용도 | 확인 항목 수 | 미연결 message ID 수 |
| --- | --- | --- | --- |
| dbc_CAN_peripheral.h | message ID 주석 + typedef struct | 83 | 0 |
| Security_CAN.h | message ID 주석 + typedef struct | 2 | 0 |
| dbc_MsgID_peripheral.h | CAN_ID enum 대조 | 83 | - |
| dbc_MsgID_security.h | CAN_ID enum 대조 | 2 | - |

## 산출물

- `1-2_Body_CAN_Message_Name_정의_BO_초안.dbc`
- `1-2_Body_CAN_Message_Name_정의_작업내용.md`
- `1-2_Body_CAN_Message_Name_정의_오류사항.md`
- `1-2_Body_CAN_Message_Name_정의_점검_필요사항.md`
- `1-2_Body_CAN_Message_Name_정의_작업기록.md`

## Message 정의 목록

| CAN | 원본 헤더 | message ID line | 원본 CAN ID | DBC CAN ID | Message Name | DLC | Transmit Node | Signal 참고 Struct | Struct line | 확인 상태 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Body | dbc_CAN_peripheral.h | 199 | 0x1050010 | 2164588560 | AVASReqMsg | 8 | Vector__XXX | AVASReqMsg_t | 200 | 확인 |
| Body | dbc_CAN_peripheral.h | 1135 | 0x105001F | 2164588575 | AVASStatusMsg | 8 | Vector__XXX | AVASStatusMsg_t | 1136 | 확인 |
| Body | dbc_CAN_peripheral.h | 1607 | 0x3A3A107 | 2208538887 | BmsLotteTotalChangeValue | 8 | Vector__XXX | BmsLotteTotalChangeValue_t | 1608 | 확인 |
| Body | Security_CAN.h | 8 | 0x480019B | 2222981531 | CollisionEventInfo | 8 | Vector__XXX | CollisionEventInfo_t | 9 | 확인 |
| Body | Security_CAN.h | 25 | 0x484019B | 2223243675 | CollisionEventConfig1 | 8 | Vector__XXX | CollisionEventConfig1_t | 26 | 확인 |
| Body | dbc_CAN_peripheral.h | 11 | 0xC66F4F5 | 2355557621 | BMSReqMsg | 8 | Vector__XXX | BMSReqMsg_t | 12 | 확인 |
| Body | dbc_CAN_peripheral.h | 1640 | 0xCF002EF | 2364539631 | BmsLotteVehiclecontroller | 8 | Vector__XXX | BmsLotteVehiclecontroller_t | 1641 | 확인 |
| Body | dbc_CAN_peripheral.h | 1216 | 0xCF50124 | 2364866852 | BmsLotteStatus | 8 | Vector__XXX | BmsLotteStatus_t | 1217 | 확인 |
| Body | dbc_CAN_peripheral.h | 25 | 0x10200000 | 2418016256 | voiceReq | 8 | Vector__XXX | VoiceMsg_t | 27 | 확인 |
| Body | dbc_CAN_peripheral.h | 26 | 0x1020000F | 2418016271 | voiceResp | 8 | Vector__XXX | VoiceMsg_t | 27 | 확인 |
| Body | dbc_CAN_peripheral.h | 39 | 0x10300100 | 2419065088 | FrontMainLightReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 40 | 0x1030010F | 2419065103 | FrontMainLightStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 41 | 0x10300110 | 2419065104 | FrontDipLightReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 42 | 0x1030011F | 2419065119 | FrontDipLightStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 43 | 0x10300120 | 2419065120 | FrontDayLightReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 44 | 0x1030012F | 2419065135 | FrontDayLightStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 45 | 0x10300130 | 2419065136 | FrontPosOutlineMarkerReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 46 | 0x1030013F | 2419065151 | FrontPosOutlineMarkerStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 47 | 0x10300200 | 2419065344 | RearReverseLightReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 48 | 0x1030020F | 2419065359 | RearReverseLightStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 49 | 0x10300210 | 2419065360 | RearTailOutlineMarkerReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 50 | 0x1030021F | 2419065375 | RearTailOutlineMarkerStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 51 | 0x10300220 | 2419065376 | RearRegLightReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 52 | 0x1030022F | 2419065391 | RearRegLightStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 53 | 0x10300300 | 2419065600 | HornReqMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 54 | 0x1030030F | 2419065615 | HornStatusMsg | 8 | Vector__XXX | LightMsg_t | 55 | 확인 |
| Body | dbc_CAN_peripheral.h | 66 | 0x10400000 | 2420113408 | FrontLightReq | 8 | Vector__XXX | FrontLightMsg_t | 68 | 확인 |
| Body | dbc_CAN_peripheral.h | 67 | 0x10400007 | 2420113415 | FrontLightStatus | 8 | Vector__XXX | FrontLightMsg_t | 68 | 확인 |
| Body | dbc_CAN_peripheral.h | 83 | 0x10400008 | 2420113416 | RearLightReq | 8 | Vector__XXX | RearLightMsg_t | 85 | 확인 |
| Body | dbc_CAN_peripheral.h | 84 | 0x1040000F | 2420113423 | RearLightStatus | 8 | Vector__XXX | RearLightMsg_t | 85 | 확인 |
| Body | dbc_CAN_peripheral.h | 102 | 0x10400010 | 2420113424 | OvalFrontLeftStatus | 8 | Vector__XXX | OvalLightStatusMsg_t | 106 | 확인 |
| Body | dbc_CAN_peripheral.h | 124 | 0x1040001F | 2420113439 | OvalFrontLeftReq | 8 | Vector__XXX | OvalLightReqMsg_t | 128 | 확인 |
| Body | dbc_CAN_peripheral.h | 103 | 0x10400020 | 2420113440 | OvalFrontRightStatus | 8 | Vector__XXX | OvalLightStatusMsg_t | 106 | 확인 |
| Body | dbc_CAN_peripheral.h | 125 | 0x1040002F | 2420113455 | OvalFrontRightReq | 8 | Vector__XXX | OvalLightReqMsg_t | 128 | 확인 |
| Body | dbc_CAN_peripheral.h | 104 | 0x10400030 | 2420113456 | OvalRearLeftStatus | 8 | Vector__XXX | OvalLightStatusMsg_t | 106 | 확인 |
| Body | dbc_CAN_peripheral.h | 126 | 0x1040003F | 2420113471 | OvalRearLeftReq | 8 | Vector__XXX | OvalLightReqMsg_t | 128 | 확인 |
| Body | dbc_CAN_peripheral.h | 105 | 0x10400040 | 2420113472 | OvalRearRightStatus | 8 | Vector__XXX | OvalLightStatusMsg_t | 106 | 확인 |
| Body | dbc_CAN_peripheral.h | 127 | 0x1040004F | 2420113487 | OvalRearRightReq | 8 | Vector__XXX | OvalLightReqMsg_t | 128 | 확인 |
| Body | dbc_CAN_peripheral.h | 284 | 0x10400100 | 2420113664 | DoorStatusMsg | 8 | Vector__XXX | DoorStatusMsg_t | 285 | 확인 |
| Body | dbc_CAN_peripheral.h | 143 | 0x10400107 | 2420113671 | DoorReqMsg | 8 | Vector__XXX | DoorReqMsg_t | 144 | 확인 |
| Body | dbc_CAN_peripheral.h | 409 | 0x10400201 | 2420113921 | StepReqMsg | 8 | Vector__XXX | StepReqMsg_t | 410 | 확인 |
| Body | dbc_CAN_peripheral.h | 425 | 0x10400208 | 2420113928 | StepStatusMsg | 8 | Vector__XXX | StepStatusMsg_t | 426 | 확인 |
| Body | dbc_CAN_peripheral.h | 158 | 0x10600000 | 2422210560 | FootReqMsg | 8 | Vector__XXX | FootReqMsg_t | 159 | 확인 |
| Body | dbc_CAN_peripheral.h | 344 | 0x10600010 | 2422210576 | Foot1Status | 5 | Vector__XXX | Foot1Status_t | 345 | 확인 |
| Body | dbc_CAN_peripheral.h | 374 | 0x10600020 | 2422210592 | Foot2Status | 7 | Vector__XXX | Foot2Status_t | 375 | 확인 |
| Body | dbc_CAN_peripheral.h | 469 | 0x10700000 | 2423259136 | Wiper1ReqMsg | 8 | Vector__XXX | WiperMsg_t | 473 | 확인 |
| Body | dbc_CAN_peripheral.h | 470 | 0x1070000F | 2423259151 | Wiper1StatusMsg | 8 | Vector__XXX | WiperMsg_t | 473 | 확인 |
| Body | dbc_CAN_peripheral.h | 471 | 0x10700010 | 2423259152 | Wiper2ReqMsg | 8 | Vector__XXX | WiperMsg_t | 473 | 확인 |
| Body | dbc_CAN_peripheral.h | 472 | 0x1070001F | 2423259167 | Wiper2StatusMsg | 8 | Vector__XXX | WiperMsg_t | 473 | 확인 |
| Body | dbc_CAN_peripheral.h | 498 | 0x1082F5F4 | 2424501748 | BMSStatusMsg1 | 8 | Vector__XXX | BMSStatusMsg1_t | 499 | 확인 |
| Body | dbc_CAN_peripheral.h | 547 | 0x1083F5F4 | 2424567284 | BMSStatusMsg2 | 8 | Vector__XXX | BMSStatusMsg2_t | 548 | 확인 |
| Body | dbc_CAN_peripheral.h | 600 | 0x1084F5F4 | 2424632820 | BMSStatusMsg3 | 8 | Vector__XXX | BMSStatusMsg3_t | 601 | 확인 |
| Body | dbc_CAN_peripheral.h | 650 | 0x1085F5F4 | 2424698356 | BMSStatusMsg4 | 8 | Vector__XXX | BMSStatusMsg4_t | 651 | 확인 |
| Body | dbc_CAN_peripheral.h | 714 | 0x1086F5F4 | 2424763892 | BMSStatusMsg5 | 8 | Vector__XXX | BMSStatusMsg5_t | 715 | 확인 |
| Body | dbc_CAN_peripheral.h | 764 | 0x1087F5F4 | 2424829428 | BMSStatusMsg6 | 8 | Vector__XXX | BMSStatusMsg6_t | 765 | 확인 |
| Body | dbc_CAN_peripheral.h | 810 | 0x1088F5F4 | 2424894964 | BMSStatusMsg7 | 8 | Vector__XXX | BMSStatusMsg7_t | 811 | 확인 |
| Body | dbc_CAN_peripheral.h | 856 | 0x1089F5F4 | 2424960500 | BMSStatusMsg8 | 8 | Vector__XXX | BMSStatusMsg8_t | 857 | 확인 |
| Body | dbc_CAN_peripheral.h | 968 | 0x1806E5F4 | 2550588916 | BMS2ChargerReqMsg | 8 | Vector__XXX | BMS2ChargerReqMsg_t | 969 | 확인 |
| Body | dbc_CAN_peripheral.h | 1460 | 0x18359A24 | 2553649700 | BmsLotteLandmark6 | 8 | Vector__XXX | BmsLotteLandmark6_t | 1461 | 확인 |
| Body | dbc_CAN_peripheral.h | 1518 | 0x18369A24 | 2553715236 | BmsLotteLandmark7 | 8 | Vector__XXX | BmsLotteLandmark7_t | 1519 | 확인 |
| Body | dbc_CAN_peripheral.h | 1573 | 0x18379A24 | 2553780772 | BmsLotteLandmark8 | 8 | Vector__XXX | BmsLotteLandmark8_t | 1574 | 확인 |
| Body | dbc_CAN_peripheral.h | 1421 | 0x18E54024 | 2565160996 | BmsLotteChargerInfo | 8 | Vector__XXX | BmsLotteChargerInfo_t | 1422 | 확인 |
| Body | dbc_CAN_peripheral.h | 1264 | 0x18F51124 | 2566197540 | BmsLotteDrive1 | 8 | Vector__XXX | BmsLotteDrive1_t | 1265 | 확인 |
| Body | dbc_CAN_peripheral.h | 1299 | 0x18F52224 | 2566201892 | BmsLotteDrive2 | 8 | Vector__XXX | BmsLotteDrive2_t | 1300 | 확인 |
| Body | dbc_CAN_peripheral.h | 1337 | 0x18F53324 | 2566206244 | BmsLotteDrive3 | 8 | Vector__XXX | BmsLotteDrive3_t | 1338 | 확인 |
| Body | dbc_CAN_peripheral.h | 1377 | 0x18FD7524 | 2566747428 | BmsLotteChargeVehicle | 8 | Vector__XXX | BmsLotteChargeVehicle_t | 1378 | 확인 |
| Body | dbc_CAN_peripheral.h | 171 | 0x18FF45F4 | 2566866420 | AirConReqMsg | 8 | Vector__XXX | AirConReqMsg_t | 172 | 확인 |
| Body | dbc_CAN_peripheral.h | 1005 | 0x18FF50E5 | 2566869221 | ChargerStatusMsg | 8 | Vector__XXX | ChargerStatusMsg_t | 1006 | 확인 |
| Body | dbc_CAN_peripheral.h | 1056 | 0x18FFC13A | 2566897978 | AirConStatusMsg | 8 | Vector__XXX | AirConStatusMsg_t | 1057 | 확인 |
| Body | dbc_CAN_peripheral.h | 1087 | 0x18FFC13B | 2566897979 | AirConVersionMsg | 8 | Vector__XXX | AirConVersionMsg_t | 1088 | 확인 |
| Body | dbc_CAN_peripheral.h | 1102 | 0x18FFC13C | 2566897980 | AirConJJK161StatusMsg | 8 | Vector__XXX | AirConJJK161StatusMsg_t | 1103 | 확인 |
| Body | dbc_CAN_peripheral.h | 1169 | 0x19000010 | 2566914064 | Signal1Debug | 8 | Vector__XXX | SignalDebugMsg_t | 1171 | 확인 |
| Body | dbc_CAN_peripheral.h | 1170 | 0x19000020 | 2566914080 | Signal2Debug | 8 | Vector__XXX | SignalDebugMsg_t | 1171 | 확인 |
| Body | dbc_CAN_peripheral.h | 230 | 0x1B001000 | 2600472576 | DTGSpeedRpmMsg | 8 | Vector__XXX | DTGSpeedRpmMsg_t | 231 | 확인 |
| Body | dbc_CAN_peripheral.h | 254 | 0x1B001010 | 2600472592 | DTGBrakeInfoMsg | 8 | Vector__XXX | DTGBrakeInfoMsg_t | 255 | 확인 |
| Body | dbc_CAN_peripheral.h | 908 | 0x1CF301F4 | 2633171444 | BMSStatusMsg11 | 8 | Vector__XXX | BMSStatusMsg11_t | 909 | 확인 |
| Body | dbc_CAN_peripheral.h | 922 | 0x1CF302F4 | 2633171700 | BMSStatusMsg12 | 8 | Vector__XXX | BMSStatusMsg12_t | 923 | 확인 |
| Body | dbc_CAN_peripheral.h | 1665 | 0x1CF303F4 | 2633171956 | BMSChargingCurrent | 8 | Vector__XXX | BMSChargingCurrent_t | 1666 | 확인 |
| Body | dbc_CAN_peripheral.h | 1681 | 0x1CF304F4 | 2633172212 | BMSChargingCurrentReply | 8 | Vector__XXX | BMSChargingCurrentReply_t | 1682 | 확인 |
| Body | dbc_CAN_peripheral.h | 272 | 0x1D000100 | 2634023168 | PeripheralVersionReqMsg | 8 | Vector__XXX | PeripheralVersionReqMsg_t | 273 | 확인 |
| Body | dbc_CAN_peripheral.h | 1197 | 0x1D000101 | 2634023169 | PeripheralVersionMsg | 8 | Vector__XXX | PeripheralVersionRespMsg_t | 1201 | 확인 |
| Body | dbc_CAN_peripheral.h | 1198 | 0x1D000102 | 2634023170 | PeripheralBootVerMsg | 8 | Vector__XXX | PeripheralVersionRespMsg_t | 1201 | 확인 |
| Body | dbc_CAN_peripheral.h | 1199 | 0x1D000103 | 2634023171 | PeripheralOcanDBCVerMsg | 8 | Vector__XXX | PeripheralVersionRespMsg_t | 1201 | 확인 |
| Body | dbc_CAN_peripheral.h | 1200 | 0x1D000104 | 2634023172 | PeripheralPcanDBCVerMsg | 8 | Vector__XXX | PeripheralVersionRespMsg_t | 1201 | 확인 |
| Body | dbc_CAN_peripheral.h | 1653 | 0x1F000000 | 2667577344 | Recovery | 1 | Vector__XXX | Recovery_t | 1654 | 확인 |
