# 1-1_Chassis_CAN_Message_Name_정의 작업내용

## 작업 개요

- 작업 일시: 2026-06-12 10:56:38 KST
- CAN 구분: Chassis CAN
- CAN 형식: CAN 2.0A
- Baudrate: 500000
- 작업 범위: CAN ID, Message Name, DLC, Transmit Node, Signal 참고 Struct comment 정의
- 원본 파일은 수정하지 않았다.

## 참조 파일별 결과

| 파일 | 용도 | 확인 항목 수 | 미연결 message ID 수 |
| --- | --- | --- | --- |
| additionalDbcCan.h | message ID 주석 + typedef struct | 6 | 2 |
| dbc_CAN.h | message ID 주석 + typedef struct | 256 | 0 |
| dbc_MsgID_main.h | CAN_ID enum 대조 | 277 | - |

## 산출물

- `1-1_Chassis_CAN_Message_Name_정의_BO_초안.dbc`
- `1-1_Chassis_CAN_Message_Name_정의_작업내용.md`
- `1-1_Chassis_CAN_Message_Name_정의_오류사항.md`
- `1-1_Chassis_CAN_Message_Name_정의_점검_필요사항.md`
- `1-1_Chassis_CAN_Message_Name_정의_작업기록.md`

## Message 정의 목록

| CAN | 원본 헤더 | message ID line | 원본 CAN ID | DBC CAN ID | Message Name | DLC | Transmit Node | Signal 참고 Struct | Struct line | 확인 상태 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Chassis | dbc_CAN.h | 118 | 0x10 | 16 | ErrorLocalisation | 8 | Vector__XXX | ErrorLocalisation_t | 156 | 확인 |
| Chassis | dbc_CAN.h | 1240 | 0x11 | 17 | ErrorDriveController | 8 | Vector__XXX | ErrorDriveController_t | 1280 | 확인 |
| Chassis | dbc_CAN.h | 3765 | 0x12 | 18 | ErrorFrontSteering | 8 | Vector__XXX | ErrorSteering_t | 3767 | 확인 |
| Chassis | dbc_CAN.h | 3766 | 0x13 | 19 | ErrorRearSteering | 8 | Vector__XXX | ErrorSteering_t | 3767 | 확인 |
| Chassis | dbc_CAN.h | 3816 | 0x14 | 20 | ManualError | 8 | Vector__XXX | ErrorManual_t | 3831 | 확인 |
| Chassis | dbc_CAN.h | 2695 | 0x15 | 21 | ErrorFusion | 8 | Vector__XXX | ErrorFusion_t | 2729 | 확인 |
| Chassis | dbc_CAN.h | 3863 | 0x16 | 22 | ErrorBlackBox | 8 | Vector__XXX | ErrorBlackBox_t | 3864 | 확인 |
| Chassis | dbc_CAN.h | 2269 | 0x17 | 23 | ErrorObstaclePC | 8 | Vector__XXX | ErrorObstaclePC_t | 2302 | 확인 |
| Chassis | dbc_CAN.h | 3875 | 0x18 | 24 | ErrorLeftMotor | 8 | Vector__XXX | ErrorLeftMotor_t | 3885 | 확인 |
| Chassis | dbc_CAN.h | 3897 | 0x1A | 26 | ErrorEHB | 8 | Vector__XXX | ErrorEHB_t | 3919 | 확인 |
| Chassis | dbc_CAN.h | 3943 | 0x1B | 27 | ErrorEHBT060 | 8 | Vector__XXX | ErrorEHBT060_t | 3970 | 확인 |
| Chassis | dbc_CAN.h | 4018 | 0x1C | 28 | EPB1Msg | 8 | Vector__XXX | EPBErrorMsg_t | 4032 | 확인 |
| Chassis | dbc_CAN.h | 4019 | 0x1D | 29 | parkBrake2 | 8 | Vector__XXX | EPBErrorMsg_t | 4032 | 확인 |
| Chassis | dbc_CAN.h | 4047 | 0x1E | 30 | frontSignal | 8 | Vector__XXX | SignalErrorMsg_t | 4059 | 확인 |
| Chassis | dbc_CAN.h | 4048 | 0x1F | 31 | rearSignal | 8 | Vector__XXX | SignalErrorMsg_t | 4059 | 확인 |
| Chassis | dbc_CAN.h | 2139 | 0x20 | 32 | ObstacleEmergency | 8 | Vector__XXX | ObstacleEmergency_t | 2140 | 확인 |
| Chassis | dbc_CAN.h | 4072 | 0x22 | 34 | ErrorSafetyBoard | 8 | Vector__XXX | ErrorSafetyBoard_t | 4084 | 확인 |
| Chassis | dbc_CAN.h | 4099 | 0x23 | 35 | StartupErrorMsg | 8 | Vector__XXX | StartupErrorMsg_t | 4114 | 확인 |
| Chassis | dbc_CAN.h | 1582 | 0x24 | 36 | ErrorDriveExt | 8 | Vector__XXX | ErrorDriveExt_t | 1598 | 확인 |
| Chassis | dbc_CAN.h | 2765 | 0x25 | 37 | FusError | 8 | Vector__XXX | FusError_t | 2800 | 확인 |
| Chassis | dbc_CAN.h | 3817 | 0x26 | 38 | Trans1Error | 8 | Vector__XXX | ErrorManual_t | 3831 | 확인 |
| Chassis | dbc_CAN.h | 4358 | 0x28 | 40 | ErrorFooting1 | 8 | Vector__XXX | ErrorFootMsg_t | 4376 | 확인 |
| Chassis | dbc_CAN.h | 4359 | 0x29 | 41 | ErrorFooting2 | 8 | Vector__XXX | ErrorFootMsg_t | 4376 | 확인 |
| Chassis | dbc_CAN.h | 4395 | 0x2A | 42 | ErrorSecurity | 8 | Vector__XXX | ErrorSecurity_t | 4396 | 확인 |
| Chassis | dbc_CAN.h | 630 | 0x2B | 43 | ManagementError | 8 | Vector__XXX | ManagementError_t | 642 | 확인 |
| Chassis | dbc_CAN.h | 4441 | 0x2D | 45 | ErrorNetwork | 8 | Vector__XXX | ErrorNetwork_t | 4452 | 확인 |
| Chassis | dbc_CAN.h | 4465 | 0x2E | 46 | ErrorAccessory1 | 8 | Vector__XXX | ErrorAccessory_t | 4478 | 확인 |
| Chassis | dbc_CAN.h | 4466 | 0x2F | 47 | ErrorAccessory2 | 8 | Vector__XXX | ErrorAccessory_t | 4478 | 확인 |
| Chassis | dbc_CAN.h | 1322 | 0x31 | 49 | DriveWarningMsg | 8 | Vector__XXX | DriveWarningMsg_t | 1338 | 확인 |
| Chassis | dbc_CAN.h | 12 | 0x38 | 56 | Timepulse_front | 5 | Vector__XXX | GpsPpsMsg_t | 14 | 확인 |
| Chassis | dbc_CAN.h | 13 | 0x39 | 57 | Timepulse_rear | 5 | Vector__XXX | GpsPpsMsg_t | 14 | 확인 |
| Chassis | dbc_CAN.h | 194 | 0x3A | 58 | frontWheelSpeed | 8 | Vector__XXX | WheelSpeedMsg_t | 196 | 확인 |
| Chassis | dbc_CAN.h | 195 | 0x3B | 59 | rearWheelSpeed | 8 | Vector__XXX | WheelSpeedMsg_t | 196 | 확인 |
| Chassis | dbc_CAN.h | 226 | 0x3C | 60 | frontWheelCnt | 8 | Vector__XXX | WheelCountMsg_t | 228 | 확인 |
| Chassis | dbc_CAN.h | 227 | 0x3D | 61 | rearWheelCnt | 8 | Vector__XXX | WheelCountMsg_t | 228 | 확인 |
| Chassis | dbc_CAN.h | 328 | 0x40 | 64 | ResetReqMsg | 8 | Vector__XXX | ResetReqMsg_t | 329 | 확인 |
| Chassis | dbc_CAN.h | 725 | 0x50 | 80 | ResetLocalisation | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 726 | 0x51 | 81 | ResetDrive | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 727 | 0x52 | 82 | ResetSteering1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 728 | 0x53 | 83 | ResetSteering2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 729 | 0x54 | 84 | ResetManual | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 730 | 0x55 | 85 | ResetFusion | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 731 | 0x56 | 86 | ResetBlackBox | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 732 | 0x57 | 87 | ResetObsPC | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 733 | 0x58 | 88 | ResetLMotor | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 734 | 0x59 | 89 | ResetRMotor | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 735 | 0x5A | 90 | ResetEHB | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 736 | 0x5C | 92 | ResetEPB1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 737 | 0x5D | 93 | ResetEPB2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 738 | 0x5E | 94 | ResetSignal1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 739 | 0x5F | 95 | ResetSignal2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 740 | 0x60 | 96 | ResetJoystick | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 775 | 0x62 | 98 | AtmelResetSafety | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 741 | 0x63 | 99 | ResetStartup | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 776 | 0x64 | 100 | AtmelResetLocalisation | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 777 | 0x65 | 101 | AtmelResetDrive | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 778 | 0x66 | 102 | AtmelResetManual | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 779 | 0x67 | 103 | AtmelResetFusion | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 742 | 0x68 | 104 | ResetFoot1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 743 | 0x69 | 105 | ResetFoot2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 763 | 0x6A | 106 | ResetSecurity | 5 | Vector__XXX | ResetSecurity_t | 764 | 확인 |
| Chassis | dbc_CAN.h | 780 | 0x6C | 108 | AtmelResetSecurity | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 744 | 0x6D | 109 | ResetNetworkComm | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 745 | 0x6E | 110 | ResetAccessory1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 746 | 0x6F | 111 | ResetAccessory2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 747 | 0x70 | 112 | ResetWheelSpeed1 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 748 | 0x71 | 113 | ResetWheelSpeed2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 749 | 0x76 | 118 | ResetTranslator | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 750 | 0x77 | 119 | ResetTranslator2 | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 751 | 0x78 | 120 | ResetTeleOp | 8 | Vector__XXX | ResetCauseMsg_t | 752 | 확인 |
| Chassis | dbc_CAN.h | 781 | 0x79 | 121 | AtmelResetTeleop | 8 | Vector__XXX | AtmelResetMsg_t | 782 | 확인 |
| Chassis | dbc_CAN.h | 4131 | 0x80 | 128 | ErrorFrontWheelSpeed | 8 | Vector__XXX | ErrorWheelSpeed_t | 4143 | 확인 |
| Chassis | dbc_CAN.h | 4132 | 0x81 | 129 | ErrorRearWheelSpeed | 8 | Vector__XXX | ErrorWheelSpeed_t | 4143 | 확인 |
| Chassis | dbc_CAN.h | 4156 | 0x88 | 136 | ErrorTeleOp | 8 | Vector__XXX | ErrorTeleOp_t | 4166 | 확인 |
| Chassis | dbc_CAN.h | 4178 | 0x110 | 272 | AtmelLocalisaionError | 8 | Vector__XXX | AtmelLocalisaionError_t | 4192 | 확인 |
| Chassis | dbc_CAN.h | 4208 | 0x111 | 273 | AtmelDriveError | 8 | Vector__XXX | AtmelDriveError_t | 4221 | 확인 |
| Chassis | dbc_CAN.h | 4236 | 0x114 | 276 | AtmelManualError | 8 | Vector__XXX | AtmelManualError_t | 4246 | 확인 |
| Chassis | dbc_CAN.h | 4258 | 0x115 | 277 | AtmelFusionError | 8 | Vector__XXX | AtmelFusionError_t | 4271 | 확인 |
| Chassis | dbc_CAN.h | 4286 | 0x118 | 280 | AtmelTeleopError | 8 | Vector__XXX | AtmelTeleopError_t | 4287 | 확인 |
| Chassis | dbc_CAN.h | 4298 | 0x11C | 284 | AtmelSecurityError | 8 | Vector__XXX | AtmelSecurityError_t | 4299 | 확인 |
| Chassis | dbc_CAN.h | 1764 | 0x120 | 288 | Obsolte_ObsLidarMsg | 8 | Vector__XXX | ObstacleDetectionLiDARMsg_t | 1765 | 확인 |
| Chassis | dbc_CAN.h | 1800 | 0x121 | 289 | Obsolete_UltraSoundMsg | 8 | Vector__XXX | UltraSoundMsg_t | 1801 | 확인 |
| Chassis | dbc_CAN.h | 2171 | 0x122 | 290 | ObstacleDangerZoneMsg | 8 | Vector__XXX | ObstacleDangerZoneMsg_t | 2172 | 확인 |
| Chassis | dbc_CAN.h | 2203 | 0x123 | 291 | ObstacleTrackDistanceMsg | 8 | Vector__XXX | ObstacleTrackDistanceMsg_t | 2204 | 확인 |
| Chassis | dbc_CAN.h | 2244 | 0x124 | 292 | ObstacleDangerZoneStopMsg | 8 | Vector__XXX | ObstacleDangerZoneStopMsg_t | 2245 | 확인 |
| Chassis | dbc_CAN.h | 4642 | 0x125 | 293 | FrontPointDist | 8 | Vector__XXX | PointDistanceMsg_t | 4644 | 확인 |
| Chassis | dbc_CAN.h | 4643 | 0x126 | 294 | RearPointDist | 8 | Vector__XXX | PointDistanceMsg_t | 4644 | 확인 |
| Chassis | dbc_CAN.h | 664 | 0x130 | 304 | TrafficLightMsg | 8 | Vector__XXX | TrafficLightMsg_t | 665 | 확인 |
| Chassis | dbc_CAN.h | 1179 | 0x150 | 336 | EHBReqMsg | 8 | Vector__XXX | EHBReqMsg_t | 1180 | 확인 |
| Chassis | dbc_CAN.h | 1855 | 0x160 | 352 | Obsolete_BrakeReqMsg | 8 | Vector__XXX | BrakeReqMsg_t | 1856 | 확인 |
| Chassis | additionalDbcCan.h | 80 | 0x161 | 353 | Motor3ReqMsg | 8 | Vector__XXX | Motor3ReqMsg_t | 81 | 확인 |
| Chassis | dbc_CAN.h | 1386 | 0x162 | 354 | MotorReqMsg | 8 | Vector__XXX | MotorReqMsg_t | 1387 | 확인 |
| Chassis | dbc_CAN.h | 1421 | 0x163 | 355 | frontSteeringReq | 8 | Vector__XXX | SteeringReqMsg_t | 1423 | 확인 |
| Chassis | dbc_CAN.h | 1422 | 0x164 | 356 | rearSteeringReq | 8 | Vector__XXX | SteeringReqMsg_t | 1423 | 확인 |
| Chassis | dbc_CAN.h | 1453 | 0x165 | 357 | Speed2TorqueReqMsg | 8 | Vector__XXX | Speed2TorqueReqMsg_t | 1454 | 확인 |
| Chassis | dbc_CAN.h | 1654 | 0x166 | 358 | Speed2TorqueRespMsg | 8 | Vector__XXX | Speed2TorqueRespMsg_t | 1655 | 확인 |
| Chassis | dbc_CAN.h | 1084 | 0x180 | 384 | ManualDriveMsg | 8 | Vector__XXX | ManualDriveMsg_t | 1087 | 확인 |
| Chassis | dbc_CAN.h | 1129 | 0x181 | 385 | JoystickMsg | 8 | Vector__XXX | JoystickMsg_t | 1133 | 확인 |
| Chassis | dbc_CAN.h | 1130 | 0x183 | 387 | TeleOpMsg | 8 | Vector__XXX | JoystickMsg_t | 1133 | 확인 |
| Chassis | dbc_CAN.h | 1085 | 0x185 | 389 | LocManualMsg | 8 | Vector__XXX | ManualDriveMsg_t | 1087 | 확인 |
| Chassis | dbc_CAN.h | 1131 | 0x186 | 390 | LocJoystickMsg | 8 | Vector__XXX | JoystickMsg_t | 1133 | 확인 |
| Chassis | dbc_CAN.h | 1086 | 0x187 | 391 | TransDriveMsg | 8 | Vector__XXX | ManualDriveMsg_t | 1087 | 확인 |
| Chassis | dbc_CAN.h | 1132 | 0x188 | 392 | TransJoystickMsg | 8 | Vector__XXX | JoystickMsg_t | 1133 | 확인 |
| Chassis | dbc_CAN.h | 4661 | 0x1A0 | 416 | PlatoonDriveMsg | 8 | Vector__XXX | InterVehicleCommsMsg_t | 4665 | 확인 |
| Chassis | dbc_CAN.h | 4662 | 0x1A1 | 417 | Vehicle1CommsMsg | 8 | Vector__XXX | InterVehicleCommsMsg_t | 4665 | 확인 |
| Chassis | dbc_CAN.h | 4663 | 0x1A2 | 418 | Vehicle2CommsMsg | 8 | Vector__XXX | InterVehicleCommsMsg_t | 4665 | 확인 |
| Chassis | dbc_CAN.h | 4664 | 0x1A3 | 419 | Vehicle3CommsMsg | 8 | Vector__XXX | InterVehicleCommsMsg_t | 4665 | 확인 |
| Chassis | dbc_CAN.h | 182 | 0x200 | 512 | TimestampMsg | 8 | Vector__XXX | TimestampMsg_t | 183 | 확인 |
| Chassis | dbc_CAN.h | 1616 | 0x201 | 513 | DriveRequestsMsg | 8 | Vector__XXX | DriveRequestsMsg_t | 1617 | 확인 |
| Chassis | dbc_CAN.h | 2554 | 0x210 | 528 | FusionLatitudeFrontMsg | 8 | Vector__XXX | LatitudeMsg_t | 2557 | 확인 |
| Chassis | dbc_CAN.h | 2592 | 0x211 | 529 | FusionLongitudeFront | 8 | Vector__XXX | LongitudeMsg_t | 2597 | 확인 |
| Chassis | dbc_CAN.h | 2627 | 0x212 | 530 | FusionInfoMsg | 8 | Vector__XXX | FusionInfoMsg_t | 2628 | 확인 |
| Chassis | dbc_CAN.h | 2555 | 0x213 | 531 | FusionLatitudeRearMsg | 8 | Vector__XXX | LatitudeMsg_t | 2557 | 확인 |
| Chassis | dbc_CAN.h | 2593 | 0x214 | 532 | FusionLongitudeRear | 8 | Vector__XXX | LongitudeMsg_t | 2597 | 확인 |
| Chassis | dbc_CAN.h | 2837 | 0x215 | 533 | FusionBiasOutlierMsg | 8 | Vector__XXX | FusionBiasOutlierMsg_t | 2838 | 확인 |
| Chassis | dbc_CAN.h | 2867 | 0x216 | 534 | VehicleInfoMsg | 8 | Vector__XXX | VehicleInfoMsg_t | 2868 | 확인 |
| Chassis | dbc_CAN.h | 4492 | 0x217 | 535 | LidarLatitudeUndelayed | 8 | Vector__XXX | LidarLatitudeUndelayed_t | 4493 | 확인 |
| Chassis | dbc_CAN.h | 4526 | 0x218 | 536 | LidarLongitudeUndelayed | 8 | Vector__XXX | LidarLongitudeUndelayed_t | 4527 | 확인 |
| Chassis | dbc_CAN.h | 2896 | 0x219 | 537 | FusionFrontLatitude | 8 | Vector__XXX | FusionFrontLatitude_t | 2897 | 확인 |
| Chassis | additionalDbcCan.h | 267 | 0x21A | 538 | FusionFrontLongitude | 8 | Vector__XXX | FusionFrontLongitude_t | 268 | 확인 |
| Chassis | dbc_CAN.h | 2937 | 0x21B | 539 | FusionRearLatitude | 8 | Vector__XXX | FusionRearLatitude_t | 2938 | 확인 |
| Chassis | dbc_CAN.h | 2974 | 0x21C | 540 | FusionRearLongitude | 8 | Vector__XXX | FusionRearLongitude_t | 2975 | 확인 |
| Chassis | dbc_CAN.h | 3013 | 0x21D | 541 | FusionHeight | 8 | Vector__XXX | FusionHeight_t | 3014 | 확인 |
| Chassis | dbc_CAN.h | 1867 | 0x220 | 544 | Obsolete_latitudeFrontMsg | 8 | Vector__XXX | GPSLatitudeMsg_t | 1869 | 확인 |
| Chassis | dbc_CAN.h | 2594 | 0x221 | 545 | Obsolete_longitudeFrontMsg | 8 | Vector__XXX | LongitudeMsg_t | 2597 | 확인 |
| Chassis | dbc_CAN.h | 1900 | 0x222 | 546 | Obsolete_heightFrontMsg | 8 | Vector__XXX | HeightMsg_t | 1902 | 확인 |
| Chassis | dbc_CAN.h | 1934 | 0x223 | 547 | Obsolete_combineHeightFrontMsg | 8 | Vector__XXX | CombinedHeightMsg_t | 1936 | 확인 |
| Chassis | dbc_CAN.h | 26 | 0x225 | 549 | frontGpsUbxPart1 | 8 | Vector__XXX | UBXPart1Msg_t | 28 | 확인 |
| Chassis | dbc_CAN.h | 61 | 0x226 | 550 | frontGpsUbxPart2 | 8 | Vector__XXX | UBXPart2Msg_t | 63 | 확인 |
| Chassis | dbc_CAN.h | 104 | 0x227 | 551 | frontGpsUbxPart3 | 8 | Vector__XXX | UBXPart3Msg_t | 106 | 확인 |
| Chassis | dbc_CAN.h | 1868 | 0x230 | 560 | Obsolete_latitudeBackMsg | 8 | Vector__XXX | GPSLatitudeMsg_t | 1869 | 확인 |
| Chassis | dbc_CAN.h | 2595 | 0x231 | 561 | Obsolete_longitudeBackMsg | 8 | Vector__XXX | LongitudeMsg_t | 2597 | 확인 |
| Chassis | dbc_CAN.h | 1901 | 0x232 | 562 | Obsolete_heightBackMsg | 8 | Vector__XXX | HeightMsg_t | 1902 | 확인 |
| Chassis | dbc_CAN.h | 1961 | 0x233 | 563 | Obsolete_HeadingMsg | 8 | Vector__XXX | HeadingMsg_t | 1962 | 확인 |
| Chassis | dbc_CAN.h | 1935 | 0x234 | 564 | Obsolete_combineHeightBackMsg | 8 | Vector__XXX | CombinedHeightMsg_t | 1936 | 확인 |
| Chassis | dbc_CAN.h | 27 | 0x235 | 565 | rearGpsUbxPart1 | 8 | Vector__XXX | UBXPart1Msg_t | 28 | 확인 |
| Chassis | dbc_CAN.h | 62 | 0x236 | 566 | rearGpsUbxPart2 | 8 | Vector__XXX | UBXPart2Msg_t | 63 | 확인 |
| Chassis | dbc_CAN.h | 105 | 0x237 | 567 | rearGpsUbxPart3 | 8 | Vector__XXX | UBXPart3Msg_t | 106 | 확인 |
| Chassis | dbc_CAN.h | 2337 | 0x240 | 576 | LidarSpeed | 8 | Vector__XXX | LidarSpeed_t | 2338 | 확인 |
| Chassis | dbc_CAN.h | 2397 | 0x241 | 577 | LidarLatitude | 8 | Vector__XXX | ObsLatitudeMsg_t | 2399 | 확인 |
| Chassis | dbc_CAN.h | 2438 | 0x242 | 578 | LidarLongitude | 8 | Vector__XXX | ObsLongitudeMsg_t | 2440 | 확인 |
| Chassis | dbc_CAN.h | 2474 | 0x243 | 579 | LidarHeading | 8 | Vector__XXX | ObsHeadingMsg_t | 2476 | 확인 |
| Chassis | dbc_CAN.h | 2398 | 0x245 | 581 | CameraLatitude | 8 | Vector__XXX | ObsLatitudeMsg_t | 2399 | 확인 |
| Chassis | dbc_CAN.h | 2439 | 0x246 | 582 | CameraLongitude | 8 | Vector__XXX | ObsLongitudeMsg_t | 2440 | 확인 |
| Chassis | dbc_CAN.h | 2475 | 0x247 | 583 | CameraHeading | 8 | Vector__XXX | ObsHeadingMsg_t | 2476 | 확인 |
| Chassis | dbc_CAN.h | 2013 | 0x250 | 592 | Obsolete_UWBDistanceMsg | 8 | Vector__XXX | UWBDistanceMsg_t | 2014 | 확인 |
| Chassis | dbc_CAN.h | 2029 | 0x251 | 593 | Obsolete_UWBLatitudeMsg | 8 | Vector__XXX | UWBLatitudeMsg_t | 2030 | 확인 |
| Chassis | dbc_CAN.h | 2055 | 0x252 | 594 | Obsolete_UWBLongitudeMsg | 8 | Vector__XXX | UWBLongitudeMsg_t | 2056 | 확인 |
| Chassis | dbc_CAN.h | 1986 | 0x260 | 608 | Obsolete_CompassMsg | 8 | Vector__XXX | CompassMsg_t | 1987 | 확인 |
| Chassis | dbc_CAN.h | 2520 | 0x270 | 624 | LidarOffset | 8 | Vector__XXX | ObsTrackOffsetMsg_t | 2522 | 확인 |
| Chassis | dbc_CAN.h | 2521 | 0x271 | 625 | CameraOffset | 8 | Vector__XXX | ObsTrackOffsetMsg_t | 2522 | 확인 |
| Chassis | dbc_CAN.h | 888 | 0x280 | 640 | frontSteeringStatus | 8 | Vector__XXX | SteeringStatusMsg_t | 890 | 확인 |
| Chassis | dbc_CAN.h | 889 | 0x281 | 641 | rearSteeringStatus | 8 | Vector__XXX | SteeringStatusMsg_t | 890 | 확인 |
| Chassis | dbc_CAN.h | 3584 | 0x290 | 656 | Motor1Status | 8 | Vector__XXX | MotorStatus_t | 3586 | 확인 |
| Chassis | dbc_CAN.h | 3585 | 0x291 | 657 | Motor2Status | 8 | Vector__XXX | MotorStatus_t | 3586 | 확인 |
| Chassis | additionalDbcCan.h | 13 | 0x295 | 661 | Motor3Status1 | 8 | Vector__XXX | Motor3Status1_t | 14 | 확인 |
| Chassis | dbc_CAN.h | 3627 | 0x296 | 662 | Motor3Status2 | 8 | Vector__XXX | Motor3Status2_t | 3628 | 확인 |
| Chassis | dbc_CAN.h | 1486 | 0x2B0 | 688 | EPBReqMsg | 8 | Vector__XXX | EPBReqMsg_t | 1487 | 확인 |
| Chassis | dbc_CAN.h | 285 | 0x2B5 | 693 | EPB1Status | 7 | Vector__XXX | EPBStatusMsg_t | 287 | 확인 |
| Chassis | dbc_CAN.h | 286 | 0x2B6 | 694 | EPB2Status | 7 | Vector__XXX | EPBStatusMsg_t | 287 | 확인 |
| Chassis | dbc_CAN.h | 2665 | 0x2C0 | 704 | FusionAcceMsg | 8 | Vector__XXX | FusionAcceMsg_t | 2666 | 확인 |
| Chassis | additionalDbcCan.h | 223 | 0x2C5 | 709 | DeviationReqMsg | 8 | Vector__XXX | DeviationReqMsg_t | 224 | 확인 |
| Chassis | additionalDbcCan.h | 163 | 0x300 | 768 | DynamicTrackValidationMsg | 8 | Vector__XXX | DynamicTrackValidationMsg_t | 164 | 확인 |
| Chassis | dbc_CAN.h | 384 | 0x310 | 784 | ParameterConfMsg | 8 | Vector__XXX | ParameterConfMsg_t | 385 | 확인 |
| Chassis | dbc_CAN.h | 359 | 0x311 | 785 | ConfigResp | 8 | Vector__XXX | ConfigRespMsg_t | 361 | 확인 |
| Chassis | dbc_CAN.h | 413 | 0x312 | 786 | VersionReqMsg | 8 | Vector__XXX | VersionReqMsg_t | 414 | 확인 |
| Chassis | dbc_CAN.h | 3449 | 0x313 | 787 | VersionRespMsg | 8 | Vector__XXX | VersionRespMsg_t | 3453 | 확인 |
| Chassis | dbc_CAN.h | 3450 | 0x314 | 788 | BootloaderVersionRespMsg | 8 | Vector__XXX | VersionRespMsg_t | 3453 | 확인 |
| Chassis | dbc_CAN.h | 3451 | 0x315 | 789 | OcanDBCVersionMsg | 8 | Vector__XXX | VersionRespMsg_t | 3453 | 확인 |
| Chassis | dbc_CAN.h | 3452 | 0x316 | 790 | PcanDBCVersionMsg | 8 | Vector__XXX | VersionRespMsg_t | 3453 | 확인 |
| Chassis | dbc_CAN.h | 425 | 0x317 | 791 | ParameterConfSignMsg | 8 | Vector__XXX | ParameterConfSignMsg_t | 426 | 확인 |
| Chassis | dbc_CAN.h | 360 | 0x318 | 792 | ConfigSignResp | 8 | Vector__XXX | ConfigRespMsg_t | 361 | 확인 |
| Chassis | dbc_CAN.h | 452 | 0x320 | 800 | SystemReqMsg | 8 | Vector__XXX | SystemReqMsg_t | 453 | 확인 |
| Chassis | dbc_CAN.h | 2081 | 0x321 | 801 | Obsolete_DriveInfoMsg | 8 | Vector__XXX | DriveInfoMsg_t | 2082 | 확인 |
| Chassis | dbc_CAN.h | 814 | 0x322 | 802 | StartupStatusMsg | 5 | Vector__XXX | StartupStatusMsg_t | 815 | 확인 |
| Chassis | dbc_CAN.h | 1162 | 0x323 | 803 | LoadingReqMsg | 8 | Vector__XXX | LoadingReqMsg_t | 1163 | 확인 |
| Chassis | dbc_CAN.h | 4407 | 0x324 | 804 | SecuritySpeedMsg | 8 | Vector__XXX | SecuritySpeedMsg_t | 4408 | 확인 |
| Chassis | dbc_CAN.h | 1498 | 0x325 | 805 | DriveInfoLongWpMsg | 8 | Vector__XXX | DriveInfoLongWpMsg_t | 1499 | 확인 |
| Chassis | additionalDbcCan.h | 193 | 0x326 | 806 | StopReqMsg | 8 | Vector__XXX | StopReqMsg_t | 194 | 확인 |
| Chassis | dbc_CAN.h | 1676 | 0x327 | 807 | ObsTiedMarginMsg | 8 | Vector__XXX | ObsTiedMarginMsg_t | 1677 | 확인 |
| Chassis | dbc_CAN.h | 1540 | 0x328 | 808 | DriveInfo500kWpMsg | 8 | Vector__XXX | DriveInfo500kWpMsg_t | 1541 | 확인 |
| Chassis | dbc_CAN.h | 960 | 0x330 | 816 | EHBStatusMsg | 8 | Vector__XXX | EHBStatusMsg_t | 961 | 확인 |
| Chassis | dbc_CAN.h | 984 | 0x331 | 817 | EHBPowerMsg | 8 | Vector__XXX | EHBPowerMsg_t | 985 | 확인 |
| Chassis | dbc_CAN.h | 1034 | 0x332 | 818 | EHBT060PowerMsg | 8 | Vector__XXX | EHBT060PowerMsg_t | 1035 | 확인 |
| Chassis | dbc_CAN.h | 472 | 0x340 | 832 | EPBReleaseMsg | 8 | Vector__XXX | EPBReleaseMsg_t | 473 | 확인 |
| Chassis | dbc_CAN.h | 4310 | 0x400 | 1024 | BatteryStatusMsg | 8 | Vector__XXX | BatteryStatusMsg_t | 4311 | 확인 |
| Chassis | dbc_CAN.h | 618 | 0x410 | 1040 | LiveUpdateReqMsg | 8 | Vector__XXX | LiveUpdateReqMsg_t | 619 | 확인 |
| Chassis | dbc_CAN.h | 3480 | 0x411 | 1041 | LiveUpdateACKMsg | 8 | Vector__XXX | LiveUpdateACKMsg_t | 3481 | 확인 |
| Chassis | dbc_CAN.h | 3571 | 0x420 | 1056 | LiveUpdateData | 8 | Vector__XXX | LiveUpdateMsg_t | 3573 | 확인 |
| Chassis | dbc_CAN.h | 3572 | 0x421 | 1057 | LiveUpdateRespMsg | 8 | Vector__XXX | LiveUpdateMsg_t | 3573 | 확인 |
| Chassis | dbc_CAN.h | 692 | 0x422 | 1058 | AtmelUpdateReqMsg | 8 | Vector__XXX | AtmelUpdateReqMsg_t | 693 | 확인 |
| Chassis | dbc_CAN.h | 4602 | 0x423 | 1059 | AtmelUpdateRespMsg | 8 | Vector__XXX | AtmelUpdateRespMsg_t | 4603 | 확인 |
| Chassis | dbc_CAN.h | 342 | 0x510 | 1296 | frontReqIndicatorBrake | 8 | Vector__XXX | IndicatorBrakeStatusAndReqMsg_t | 346 | 확인 |
| Chassis | dbc_CAN.h | 343 | 0x511 | 1297 | rearReqIndicatorBrake | 8 | Vector__XXX | IndicatorBrakeStatusAndReqMsg_t | 346 | 확인 |
| Chassis | dbc_CAN.h | 344 | 0x520 | 1312 | frontStatusIndicatorBrake | 8 | Vector__XXX | IndicatorBrakeStatusAndReqMsg_t | 346 | 확인 |
| Chassis | dbc_CAN.h | 345 | 0x521 | 1313 | rearStatusIndicatorBrake | 8 | Vector__XXX | IndicatorBrakeStatusAndReqMsg_t | 346 | 확인 |
| Chassis | dbc_CAN.h | 793 | 0x530 | 1328 | FrontRightIndicatorLightReqMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 794 | 0x531 | 1329 | FrontRightIndicatorLightStatusMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 795 | 0x540 | 1344 | FrontLeftIndicatorLightReqMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 796 | 0x541 | 1345 | FrontLeftIndicatorLightStatusMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 797 | 0x550 | 1360 | RearBrakeLightReqMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 798 | 0x551 | 1361 | RearBrakeLightStatusMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 799 | 0x560 | 1376 | RearRightIndicatorLightReqMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 800 | 0x561 | 1377 | RearRightIndicatorLightStatusMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 801 | 0x570 | 1392 | RearLeftIndicatorLightReqMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 802 | 0x571 | 1393 | RearLeftIndicatorLightStatusMsg | 8 | Vector__XXX | IndicatorBrakeLightMsg_t | 803 | 확인 |
| Chassis | dbc_CAN.h | 3658 | 0x580 | 1408 | Motor3Status3 | 8 | Vector__XXX | Motor3Status3_t | 3659 | 확인 |
| Chassis | dbc_CAN.h | 3682 | 0x581 | 1409 | Motor3Status4 | 8 | Vector__XXX | Motor3Status4_t | 3683 | 확인 |
| Chassis | dbc_CAN.h | 3699 | 0x582 | 1410 | Motor3Status5 | 8 | Vector__XXX | Motor3Status5_t | 3700 | 확인 |
| Chassis | dbc_CAN.h | 3731 | 0x583 | 1411 | Motor3Status6 | 8 | Vector__XXX | Motor3Status6_t | 3732 | 확인 |
| Chassis | dbc_CAN.h | 847 | 0x584 | 1412 | BMSStatusStdMsg | 8 | Vector__XXX | BMSStatusStdMsg_t | 848 | 확인 |
| Chassis | dbc_CAN.h | 3847 | 0x590 | 1424 | RemoteSignalMsg | 8 | Vector__XXX | RemoteSignalMsg_t | 3848 | 확인 |
| Chassis | dbc_CAN.h | 1708 | 0x5A0 | 1440 | ExtObsLocMsg | 8 | Vector__XXX | ExtObsLocMsg_t | 1709 | 확인 |
| Chassis | dbc_CAN.h | 1730 | 0x5A1 | 1441 | ExtObsSpeedMsg | 8 | Vector__XXX | ExtObsSpeedMsg_t | 1731 | 확인 |
| Chassis | dbc_CAN.h | 833 | 0x600 | 1536 | ErrorReportMsg | 6 | Vector__XXX | ErrorReportMsg_t | 834 | 확인 |
| Chassis | dbc_CAN.h | 4419 | 0x60A | 1546 | SecurityWarningMsg | 8 | Vector__XXX | SecurityWarningMsg_t | 4429 | 확인 |
| Chassis | dbc_CAN.h | 3493 | 0x610 | 1552 | FileTransferMsg | 8 | Vector__XXX | FileTransferMsg_t | 3494 | 확인 |
| Chassis | dbc_CAN.h | 3509 | 0x611 | 1553 | FileAckMsg | 8 | Vector__XXX | TransferAckMsg_t | 3511 | 확인 |
| Chassis | dbc_CAN.h | 3526 | 0x612 | 1554 | DataTransferMsg | 8 | Vector__XXX | DataTransferMsg_t | 3527 | 확인 |
| Chassis | dbc_CAN.h | 3510 | 0x613 | 1555 | DataAckMsg | 8 | Vector__XXX | TransferAckMsg_t | 3511 | 확인 |
| Chassis | dbc_CAN.h | 3249 | 0x621 | 1569 | IMURot | 8 | Vector__XXX | IMURot_t | 3250 | 확인 |
| Chassis | dbc_CAN.h | 3293 | 0x622 | 1570 | IMUAcc | 8 | Vector__XXX | IMUAcc_t | 3294 | 확인 |
| Chassis | dbc_CAN.h | 3331 | 0x623 | 1571 | IMUGyr | 8 | Vector__XXX | IMUGyr_t | 3332 | 확인 |
| Chassis | dbc_CAN.h | 3374 | 0x624 | 1572 | IMUStatus | 8 | Vector__XXX | IMUStatus_t | 3375 | 확인 |
| Chassis | dbc_CAN.h | 707 | 0x630 | 1584 | ConnectWp | 8 | Vector__XXX | ConnectWp_t | 708 | 확인 |
| Chassis | dbc_CAN.h | 485 | 0x650 | 1616 | TrackCtrlManageMsg | 8 | Vector__XXX | TrackCtrlMsg_t | 488 | 확인 |
| Chassis | dbc_CAN.h | 502 | 0x651 | 1617 | TrackAckManageMsg | 8 | Vector__XXX | TrackAckMsg_t | 505 | 확인 |
| Chassis | dbc_CAN.h | 517 | 0x652 | 1618 | TrackDataManageMsg | 8 | Vector__XXX | TrackDataMsg_t | 520 | 확인 |
| Chassis | dbc_CAN.h | 486 | 0x660 | 1632 | TrackCtrlDriveMsg | 8 | Vector__XXX | TrackCtrlMsg_t | 488 | 확인 |
| Chassis | dbc_CAN.h | 503 | 0x661 | 1633 | TrackAckDriveMsg | 8 | Vector__XXX | TrackAckMsg_t | 505 | 확인 |
| Chassis | dbc_CAN.h | 518 | 0x662 | 1634 | TrackDataDriveMsg | 8 | Vector__XXX | TrackDataMsg_t | 520 | 확인 |
| Chassis | dbc_CAN.h | 1227 | 0x663 | 1635 | TrackMD5ReqMsg | 8 | Vector__XXX | TrackMD5ReqMsg_t | 1228 | 확인 |
| Chassis | dbc_CAN.h | 4694 | 0x664 | 1636 | platStartTxMsg | 8 | Vector__XXX | PlatStartMsg_t | 4696 | 확인 |
| Chassis | dbc_CAN.h | 487 | 0x670 | 1648 | TrackCtrlObsMsg | 8 | Vector__XXX | TrackCtrlMsg_t | 488 | 확인 |
| Chassis | dbc_CAN.h | 504 | 0x671 | 1649 | TrackAckObsMsg | 8 | Vector__XXX | TrackAckMsg_t | 505 | 확인 |
| Chassis | dbc_CAN.h | 519 | 0x672 | 1650 | TrackDataObsMsg | 8 | Vector__XXX | TrackDataMsg_t | 520 | 확인 |
| Chassis | dbc_CAN.h | 3468 | 0x673 | 1651 | TrackMD5RespMsg | 8 | Vector__XXX | TrackMD5RespMsg_t | 3469 | 확인 |
| Chassis | dbc_CAN.h | 4695 | 0x674 | 1652 | platStartRxMsg | 8 | Vector__XXX | PlatStartMsg_t | 4696 | 확인 |
| Chassis | dbc_CAN.h | 533 | 0x680 | 1664 | SteerCalibrationMsg | 8 | Vector__XXX | SteerCalibrationMsg_t | 534 | 확인 |
| Chassis | dbc_CAN.h | 565 | 0x681 | 1665 | SteerConfigMsg | 8 | Vector__XXX | SteerConfigMsg_t | 566 | 확인 |
| Chassis | dbc_CAN.h | 577 | 0x682 | 1666 | SteerConfigReqMsg | 8 | Vector__XXX | SteerConfigReqMsg_t | 578 | 확인 |
| Chassis | dbc_CAN.h | 928 | 0x683 | 1667 | SteeringRespMsg | 8 | Vector__XXX | SteeringRespMsg_t | 929 | 확인 |
| Chassis | dbc_CAN.h | 590 | 0x690 | 1680 | SteerMsg | 8 | Vector__XXX | SteerMsg_t | 591 | 확인 |
| Chassis | dbc_CAN.h | 1631 | 0x700 | 1792 | OdometerMsg | 8 | Vector__XXX | OdometerMsg_t | 1632 | 확인 |
| Chassis | dbc_CAN.h | 4554 | 0x701 | 1793 | OdometryParameters | 8 | Vector__XXX | OdometryParameters_t | 4555 | 확인 |
| Chassis | dbc_CAN.h | 3395 | 0x707 | 1799 | ObstaclePcWarning | 8 | Vector__XXX | ObstaclePcWarning_t | 3421 | 확인 |
| Chassis | dbc_CAN.h | 2127 | 0x710 | 1808 | Obsolete_LogIndMsg | 8 | Vector__XXX | LogIndMsg_t | 2128 | 확인 |
| Chassis | dbc_CAN.h | 1356 | 0x712 | 1810 | PlatDebugMsg | 8 | Vector__XXX | PlatDebugMsg_t | 1357 | 확인 |
| Chassis | dbc_CAN.h | 1368 | 0x713 | 1811 | StopDebugMsg | 8 | Vector__XXX | StopDebugMsg_t | 1369 | 확인 |
| Chassis | dbc_CAN.h | 1569 | 0x720 | 1824 | DebugMsg | 8 | Vector__XXX | DebugMsg_t | 1570 | 확인 |
| Chassis | dbc_CAN.h | 3047 | 0x724 | 1828 | FusionFlagsMsg | 8 | Vector__XXX | FusionFlagsMsg_t | 3048 | 확인 |
| Chassis | dbc_CAN.h | 3111 | 0x725 | 1829 | ErrorFusionDebugMsg | 8 | Vector__XXX | ErrorFusionDebugMsg_t | 3168 | 확인 |
| Chassis | dbc_CAN.h | 3212 | 0x727 | 1831 | IMUMag | 8 | Vector__XXX | IMUMag_t | 3213 | 확인 |
| Chassis | dbc_CAN.h | 241 | 0x740 | 1856 | WheelSpeedEvents | 8 | Vector__XXX | WheelSpeedEvents_t | 242 | 확인 |
| Chassis | dbc_CAN.h | 4619 | 0x751 | 1873 | PlatoonSimMsg | 8 | Vector__XXX | PlatoonSimMsg_t | 4620 | 확인 |
| Chassis | dbc_CAN.h | 3554 | 0x765 | 1893 | fusionExceptionMsg | 8 | Vector__XXX | ExceptionMsg_t | 3557 | 확인 |
| Chassis | dbc_CAN.h | 3555 | 0x7C0 | 1984 | frontWheelExceptionMsg | 8 | Vector__XXX | ExceptionMsg_t | 3557 | 확인 |
| Chassis | dbc_CAN.h | 3556 | 0x7C1 | 1985 | rearWheelExceptionMsg | 8 | Vector__XXX | ExceptionMsg_t | 3557 | 확인 |
| Chassis | dbc_CAN.h | 3540 | 0x7F0 | 2032 | AnyExceptionMsg | 8 | Vector__XXX | AnyExceptionMsg_t | 3541 | 확인 |
| Chassis | dbc_CAN.h | 2556 | 0x7F2 | 2034 | EmulatorLatitudeMsg | 8 | Vector__XXX | LatitudeMsg_t | 2557 | 확인 |
| Chassis | dbc_CAN.h | 2596 | 0x7F3 | 2035 | EmulatorLongitude | 8 | Vector__XXX | LongitudeMsg_t | 2597 | 확인 |
| Chassis | dbc_CAN.h | 1690 | 0x7F4 | 2036 | EmulatorHeadingMsg | 8 | Vector__XXX | EmulatorHeadingMsg_t | 1691 | 확인 |
