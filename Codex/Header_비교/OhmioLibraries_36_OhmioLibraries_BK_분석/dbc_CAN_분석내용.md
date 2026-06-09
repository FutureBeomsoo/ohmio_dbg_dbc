# dbc_CAN.h 비교 분석

- 비교 A: `OhmioLibraries_36` - `OhmioLibraries_36/include/canbus/dbc_CAN.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목 | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 3628 | 4787 |
| SHA256 | 2251ffadbd73 | e1d368cabda6 |
| Struct | 145 | 152 |
| Enum | 28 | 25 |
| CAN_ID | 0 | 0 |
| Function | 130 | 146 |
| Unified diff | -1527 | +2686 |

Diff hunk 위치:
- `@@ -1,166 +1,12 @@`
- `@@ -180,9 +26,23 @@`
- `@@ -192,9 +52,8 @@`
- `@@ -221,9 +80,31 @@`
- `@@ -247,9 +128,30 @@`
- `@@ -298,9 +200,50 @@`
- `@@ -320,9 +263,20 @@`
- `@@ -353,9 +307,19 @@`
- `@@ -364,12 +328,11 @@`
- `@@ -392,6 +355,7 @@`
- `@@ -408,6 +372,7 @@`
- `@@ -422,6 +387,7 @@`
- `@@ -453,9 +419,23 @@`
- `@@ -498,9 +478,21 @@`
- `@@ -519,8 +511,6 @@`
- `@@ -534,19 +524,25 @@`
- `@@ -565,9 +561,20 @@`
- `@@ -583,6 +590,52 @@`
- `@@ -599,7 +652,6 @@`
- `@@ -609,8 +661,6 @@`
- `@@ -640,7 +690,6 @@`
- `@@ -682,8 +731,7 @@`
- `@@ -696,7 +744,7 @@`
- `@@ -728,9 +776,28 @@`
- `@@ -755,9 +822,26 @@`
- `@@ -777,9 +861,23 @@`
- `@@ -831,9 +929,33 @@`
- `@@ -861,12 +983,37 @@`
- `@@ -883,7 +1030,6 @@`
- `@@ -891,12 +1037,32 @@`
- `@@ -920,8 +1086,6 @@`
- `@@ -969,9 +1133,43 @@`
- `@@ -1078,7 +1276,6 @@`
- `@@ -1097,7 +1294,6 @@`
- `@@ -1152,9 +1348,24 @@`
- `@@ -1176,9 +1387,21 @@`
- `@@ -1201,9 +1424,21 @@`
- `@@ -1216,6 +1451,55 @@`
- `@@ -1241,38 +1525,27 @@`
- `@@ -1293,9 +1566,6 @@`
- ... 추가 45개 hunk

### 전처리/Include 비교
Include 차이:
| Include | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| "ConversionHelper.h" |  | OhmioLibraries_BK |
| <assert.h> |  | OhmioLibraries_BK |
| <math.h> |  | OhmioLibraries_BK |

### CAN ID enum 비교
CAN_ID enum 항목이 없습니다.

### 일반 enum 비교
OhmioLibraries_36에만 있는 enum:
| Enum | entry 수 |
| --- | --- |
| AccessoryErrorCode | 5 |
| NetworkErrorCode | 4 |
| ObstaclePcWarningErrorCode | 17 |
| TeleOpErrorCode | 3 |
OhmioLibraries_BK에만 있는 enum:
| Enum | entry 수 |
| --- | --- |
| TransErrorCode | 5 |
#### AtmelLocalisaionErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Atloc_GPS1_Input | 0 |
| Atloc_GPS2_Input | 1 |
OhmioLibraries_BK에만 있는 entry:
| Entry | Value |
| --- | --- |
| Atloc_GPS_Input_Search | 0 |
| Atloc_UWB_Input_Search | 1 |
#### DrvExtErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Drvext_Motor_Over_Temp | 4 |
| Drvext_Parameter_Out_Of_Range | 3 |
| Drvext_Speed_Deviation | 5 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Drvext_NumErrorCodes | 6 | 3 |
#### DrvWarningMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Drv_Mcu_Ver_Incompatible | 7 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Drv_NumWarningCodes | 8 | 7 |
#### EPBMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| EPB_Drv_Info_Comms | 4 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| EPB_NumErrorCodes | 5 | 4 |
#### FootMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Foot_Drv_Info_Comms | 8 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Foot_NumErrorCodes | 9 | 8 |
#### FusErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| fus_drv_info_comms | 0x1A |
| fus_huge_sensor_update | 0x18 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| fus_NumErrorCodes | 0x1B | 0x19 |
| fus_safety_relay_open | 0x19 | 0x18 |
#### FusionDebugMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| fusdebug_Reserved18 | 0x2C |
| fusdebug_drive_info_comms | 0x10 |
| fusdebug_huge_sensor_update | 6 |
OhmioLibraries_BK에만 있는 entry:
| Entry | Value |
| --- | --- |
| fusdebug_odometry_Null | 6 |
| fusdebug_rtk_Front_Null | 7 |
| fusdebug_rtk_Rear_Null | 8 |
| fusdebug_w_huge_sensor_update | 0x31 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| fusdebug_NumErrorCodes | 0x31 | 0x32 |
| fusdebug_Reserved | 7 | 0x10 |
| fusdebug_Reserved10 | 0x18 | 0x19 |
| fusdebug_Reserved11 | 0x19 | 0x1A |
| fusdebug_Reserved12 | 0x1A | 0x1B |
| fusdebug_Reserved13 | 0x1B | 0x1C |
| fusdebug_Reserved14 | 0x1C | 0x1D |
| fusdebug_Reserved15 | 0x1D | 0x1E |
| fusdebug_Reserved16 | 0x1E | 0x1F |
| fusdebug_Reserved17 | 0x1F | 0x2C |
| fusdebug_Reserved2 | 8 | 0x11 |
| fusdebug_Reserved3 | 0x11 | 0x12 |
| fusdebug_Reserved4 | 0x12 | 0x13 |
| fusdebug_Reserved5 | 0x13 | 0x14 |
| fusdebug_Reserved6 | 0x14 | 0x15 |
| fusdebug_Reserved7 | 0x15 | 0x16 |
| fusdebug_Reserved8 | 0x16 | 0x17 |
| fusdebug_Reserved9 | 0x17 | 0x18 |
#### FusionErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Fusion_Drv_Info_Comms | 0x19 |
| Fusion_Huge_Sensor_Update | 0x18 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Fusion_NumErrorCodes | 0x1A | 0x18 |
#### LocalisationErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Loc_Dri_Info_Comms | 0xC |
OhmioLibraries_BK에만 있는 entry:
| Entry | Value |
| --- | --- |
| Loc_Reserved16 | 0x1B |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Loc_Reserved | 0xD | 0xC |
| Loc_Reserved10 | 0x16 | 0x15 |
| Loc_Reserved11 | 0x17 | 0x16 |
| Loc_Reserved12 | 0x18 | 0x17 |
| Loc_Reserved13 | 0x19 | 0x18 |
| Loc_Reserved14 | 0x1A | 0x19 |
| Loc_Reserved15 | 0x1B | 0x1A |
| Loc_Reserved2 | 0xE | 0xD |
| Loc_Reserved3 | 0xF | 0xE |
| Loc_Reserved4 | 0x10 | 0xF |
| Loc_Reserved5 | 0x11 | 0x10 |
| Loc_Reserved6 | 0x12 | 0x11 |
| Loc_Reserved7 | 0x13 | 0x12 |
| Loc_Reserved8 | 0x14 | 0x13 |
| Loc_Reserved9 | 0x15 | 0x14 |
#### ManagementErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| mgt_Drv_Info_Comms | 2 |
| mgt_shared_Drv | 3 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| mgt_NumErrorCodes | 4 | 2 |
#### ManualErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Man_Dri_Info_Coms | 4 |
| Man_Duplicated_Joystick_Board | 5 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Man_NumErrorCodes | 6 | 4 |
#### ObstaclePCErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| Obstacle_drv_info_comms | 0x18 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| Obstacle_NumErrorCodes | 0x19 | 0x18 |
#### SignalMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| signal_Drv_Info_Comms | 2 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| signal_NumErrorCodes | 3 | 2 |
#### StartupMsgErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| startup_Drv_Info_Comms | 5 |
| startup_lotte_Bms_Err | 6 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| startup_NumErrorCodes | 7 | 5 |
#### WheelSpeedErrorCode
OhmioLibraries_36에만 있는 entry:
| Entry | Value |
| --- | --- |
| wheel_drv_info_comms | 2 |
동일 entry 이름의 값 변경:
| Entry | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| wheel_NumErrorCodes | 3 | 2 |

### Struct/Message 비교
OhmioLibraries_36에만 있는 struct:
| Struct | message ID | bit 수 |
| --- | --- | --- |
| AnyExceptionMsg_t | 0x7F0 AnyExceptionMsg | 48 |
| AtmelTeleopError_t | 0x118 AtmelTeleopError | 1 |
| DriveInfo500kWpMsg_t | 0x328 DriveInfo500kWpMsg | 63 |
| EmulatorHeadingMsg_t | 0x7F4 EmulatorHeadingMsg | 16 |
| ErrorNetwork_t | 0x2D ErrorNetwork | 3 |
| ErrorTeleOp_t | 0x88 ErrorTeleOp | 2 |
| ExtObsLocMsg_t | 0x5A0 ExtObsLocMsg | 61 |
| ExtObsSpeedMsg_t | 0x5A1 ExtObsSpeedMsg | 33 |
| GpsPpsMsg_t | 0x38 Timepulse_front, 0x39 Timepulse_rear | 34 |
| IMUStatus_t | 0x624 IMUStatus | 61 |
| LatitudeMsg_t | 0x210 FusionLatitudeFrontMsg, 0x213 FusionLatitudeRearMsg, 0x7F2 EmulatorLatitudeMsg | 64 |
| ObsoleteMsg_t | 0x120 Obsolte_ObsLidarMsg, 0x121 Obsolete_UltraSoundMsg, 0x160 Obsolete_BrakeReqMsg, 0x220 Obsolete_latitudeFrontMsg, 0x221 Obsolete_longitudeFrontMsg, 0x222 Obsolete_heightFrontMsg, 0x223 Obsolete_combineHeightFrontMsg, 0x230 Obsolete_latitudeBackMsg, 0x231 Obsolete_longitudeBackMsg, 0x232 Obsolete_heightBackMsg, 0x233 Obsolete_HeadingMsg, 0x234 Obsolete_combineHeightBackMsg, 0x250 Obsolete_UWBDistanceMsg, 0x251 Obsolete_UWBLatitudeMsg, 0x252 Obsolete_UWBLongitudeMsg, 0x260 Obsolete_CompassMsg, 0x321 Obsolete_DriveInfoMsg, 0x710 Obsolete_LogIndMsg | 64 |
| ObstacleDangerZoneStopMsg_t | 0x124 ObstacleDangerZoneStopMsg | 32 |
| ObstaclePcWarning_t | 0x707 ObstaclePcWarning | 16 |
OhmioLibraries_BK에만 있는 struct:
| Struct | message ID | bit 수 |
| --- | --- | --- |
| BrakeReqMsg_t | 0x160 BrakeReqMsg | 64 |
| CombinedHeightMsg_t | 0x223 combineHeightFrontMsg, 0x234 combineHeightBackMsg | 64 |
| CompassMsg_t | 0x260 CompassMsg | 64 |
| DeviationReqMsg_t | 0x2C5 DeviationReqMsg | 38 |
| DriveInfoMsg_t | 0x321 DriveInfoMsg | 64 |
| DynamicTrackValidationMsg_t | 0x300 DynamicTrackValidationMsg | 56 |
| ErrorMotorAdaptor_t | 0x2D ErrorMotorAdaptor | 64 |
| ErrorTrans_t | 0x26 ErrorTrans | 4 |
| FusionFrontLongitude_t | 0x21A FusionFrontLongitude | 64 |
| FusionLatitudeMsg_t | 0x210 FusionLatitudeFrontMsg, 0x213 FusionLatitudeRearMsg | 64 |
| GPSLatitudeMsg_t | 0x220 latitudeFrontMsg, 0x230 latitudeBackMsg | 64 |
| HeadingMsg_t | 0x233 HeadingMsg | 16 |
| HeightMsg_t | 0x222 heightFrontMsg, 0x232 heightBackMsg | 64 |
| LogIndMsg_t | 0x710 LogIndMsg | 1 |
| ObstacleDetectionLiDARMsg_t | 0x120 ObstacleDetectionLiDARMsg | 64 |
| PrintASCIIMsg_t | 0x7F0 PrintASCIIMsg | 64 |
| StopReqMsg_t | 0x326 StopReqMsg | 32 |
| UWBDistanceMsg_t | 0x250 UWBDistanceMsg | 64 |
| UWBLatitudeMsg_t | 0x251 UWBLatitudeMsg | 56 |
| UWBLongitudeMsg_t | 0x252 UWBLongitudeMsg | 56 |
| UltraSoundMsg_t | 0x121 UltraSoundMsg | 48 |
변경된 공통 struct: 41개
#### AtmelLocalisaionError_t
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| AtlocGPS1InputError | bit0 uint64_t AtlocGPS1InputError:1 | bit0 uint64_t AtlocGPSInputSearchError:1 |
| AtlocGPS2InputError | bit1 uint64_t AtlocGPS2InputError:1 | bit1 uint64_t AtlocUWBInputSearchError:1 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| AtlocGPSInputSearchError | bit0 uint64_t AtlocGPSInputSearchError:1 | bit0 uint64_t AtlocGPS1InputError:1 |
| AtlocUWBInputSearchError | bit1 uint64_t AtlocUWBInputSearchError:1 | bit1 uint64_t AtlocGPS2InputError:1 |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit0 | bit0 uint64_t AtlocGPS1InputError:1 | bit0 uint64_t AtlocGPSInputSearchError:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit1 | bit1 uint64_t AtlocGPS2InputError:1 | bit1 uint64_t AtlocUWBInputSearchError:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### AtmelResetMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x62 AtmelResetSafety, 0x64 AtmelResetLocalisation, 0x65 AtmelResetDrive, 0x66 AtmelResetManual, 0x67 AtmelResetFusion, 0x6C AtmelResetSecurity, 0x79 AtmelResetTeleop, OhmioLibraries_BK=0x62 AtmelResetSafety, 0x64 AtmelResetLocalisation, 0x65 AtmelResetDrive, 0x66 AtmelResetManual, 0x67 AtmelResetFusion, 0x6C AtmelResetSecurity
#### DriveWarningMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=8, OhmioLibraries_BK=7
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| DrvMcuVerIncompatible | bit7 uint64_t DrvMcuVerIncompatible:1 | - |
#### EPBErrorMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=5, OhmioLibraries_BK=4
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| EPBDrvInfoCommsError | bit4 uint64_t EPBDrvInfoCommsError:1 | - |
#### ErrorAccessory_t
- Signal 총 bit 수 변경: OhmioLibraries_36=4, OhmioLibraries_BK=64
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| AccessoryDrvInfoComms | bit3 uint64_t AccessoryDrvInfoComms:1 | bits0-63 uint64_t code:64 |
| AccessoryIncorrectPCB | bit0 uint64_t AccessoryIncorrectPCB:1, // Accessory | bits0-63 uint64_t code:64 |
| AccessoryNonUniqueID | bit1 uint64_t AccessoryNonUniqueID:1, // Accessory | bits0-63 uint64_t code:64 |
| AccessoryRelayOpen | bit2 uint64_t AccessoryRelayOpen:1, // Accessory | bits0-63 uint64_t code:64 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| code | bits0-63 uint64_t code:64 | bit0 uint64_t AccessoryIncorrectPCB:1, // Accessory, bit1 uint64_t AccessoryNonUniqueID:1, // Accessory, bit2 uint64_t AccessoryRelayOpen:1, // Accessory, bit3 uint64_t AccessoryDrvInfoComms:1 |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit0 | bit0 uint64_t AccessoryIncorrectPCB:1, // Accessory | bits0-63 uint64_t code:64 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit1 | bit1 uint64_t AccessoryNonUniqueID:1, // Accessory | bits0-63 uint64_t code:64 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit2 | bit2 uint64_t AccessoryRelayOpen:1, // Accessory | bits0-63 uint64_t code:64 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit3 | bit3 uint64_t AccessoryDrvInfoComms:1 | bits0-63 uint64_t code:64 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### ErrorDriveExt_t
- Signal 총 bit 수 변경: OhmioLibraries_36=6, OhmioLibraries_BK=3
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| DrvextMotorOverTemp | bit4 uint64_t DrvextMotorOverTemp:1 | - |
| DrvextParameterOutOfRange | bit3 uint64_t DrvextParameterOutOfRange:1 | - |
| DrvextSpeedDeviationError | bit5 uint64_t DrvextSpeedDeviationError:1 | - |
#### ErrorFootMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=9, OhmioLibraries_BK=8
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| FootDrvInfoCommsError | bit8 uint64_t FootDrvInfoCommsError:1 | - |
#### ErrorFusionDebugMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=49, OhmioLibraries_BK=50
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits7-8 uint64_t reserved:2 | bits16-31 uint64_t reserved:16 | bit/type/unit 변경 |
| reserved1 | bits17-31 uint64_t reserved1:15 | bit44 uint64_t reserved1:1 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| drive_info_comms | bit16 uint64_t drive_info_comms:1 | bits16-31 uint64_t reserved:16 |
| huge_sensor_update | bit6 uint64_t huge_sensor_update:1 | bit6 uint64_t odometryNull:1 |
| reserved2 | bit44 uint64_t reserved2:1 | bit44 uint64_t reserved1:1 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| odometryNull | bit6 uint64_t odometryNull:1 | bit6 uint64_t huge_sensor_update:1 |
| rtkFrontNull | bit7 uint64_t rtkFrontNull:1 | bits7-8 uint64_t reserved:2 |
| rtkRearNull | bit8 uint64_t rtkRearNull:1 | bits7-8 uint64_t reserved:2 |
| w_huge_sensor_update | bit49 uint64_t w_huge_sensor_update:1 | - |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit7 | bits7-8 uint64_t reserved:2 | bit7 uint64_t rtkFrontNull:1 | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit8 | bits7-8 uint64_t reserved:2 | bit8 uint64_t rtkRearNull:1 | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit16 | bit16 uint64_t drive_info_comms:1 | bits16-31 uint64_t reserved:16 | Reserved 대체 후보: OhmioLibraries_BK reserved |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit6 | bit6 uint64_t huge_sensor_update:1 | bit6 uint64_t odometryNull:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### ErrorFusion_t
- Signal 총 bit 수 변경: OhmioLibraries_36=26, OhmioLibraries_BK=24
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| FusionDrvInfoCommsError | bit25 uint64_t FusionDrvInfoCommsError:1 | - |
| FusionHugeSensorUpdate | bit24 uint64_t FusionHugeSensorUpdate:1 | - |
#### ErrorLocalisation_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits13-27 uint64_t reserved:15 | bits12-27 uint64_t reserved:16 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| LocDriInfoCommsError | bit12 uint64_t LocDriInfoCommsError:1 | bits12-27 uint64_t reserved:16 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit12 | bit12 uint64_t LocDriInfoCommsError:1 | bits12-27 uint64_t reserved:16 | Reserved 대체 후보: OhmioLibraries_BK reserved |
#### ErrorManual_t
- message ID 주석 변경: OhmioLibraries_36=0x14 ManualError, 0x26 Trans1Error, OhmioLibraries_BK=0x14 ErrorManual
- Signal 총 bit 수 변경: OhmioLibraries_36=6, OhmioLibraries_BK=4
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| DuplicatedJoystickBoard | bit5 uint64_t DuplicatedJoystickBoard:1 | - |
| ManDriInfoComsError | bit4 uint64_t ManDriInfoComsError:1 | - |
#### ErrorObstaclePC_t
- Signal 총 bit 수 변경: OhmioLibraries_36=25, OhmioLibraries_BK=24
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| Obstacle_drv_info_comms_error | bit24 uint64_t Obstacle_drv_info_comms_error:1 | - |
#### ErrorReportMsg_t
- raw buffer 크기 변경: OhmioLibraries_36=6, OhmioLibraries_BK=8
#### ErrorWheelSpeed_t
- Signal 총 bit 수 변경: OhmioLibraries_36=3, OhmioLibraries_BK=2
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| wheel_drv_info_comms_error | bit2 uint64_t wheel_drv_info_comms_error:1 | - |
#### ExceptionMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| ex_addr | bits0-31 uint64_t ex_addr:32 | bits32-36 uint64_t ex_addr:5 | bit/type/unit 변경 |
| ex_code | bits32-36 uint64_t ex_code:5 | bits0-31 uint64_t ex_code:32 | bit/type/unit 변경 |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits0-31 | bits0-31 uint64_t ex_addr:32 | bits0-31 uint64_t ex_code:32 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits32-36 | bits32-36 uint64_t ex_code:5 | bits32-36 uint64_t ex_addr:5 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### FusError_t
- Signal 총 bit 수 변경: OhmioLibraries_36=27, OhmioLibraries_BK=25
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| fus_safety_relay_open | bit25 uint64_t fus_safety_relay_open:1 | bit24 uint64_t fus_safety_relay_open:1 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| fus_drv_info_comms_error | bit26 uint64_t fus_drv_info_comms_error:1 | - |
| fus_huge_sensor_update | bit24 uint64_t fus_huge_sensor_update:1 | bit24 uint64_t fus_safety_relay_open:1 |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit24 | bit24 uint64_t fus_huge_sensor_update:1 | bit24 uint64_t fus_safety_relay_open:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### FusionFlagsMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=56, OhmioLibraries_BK=54
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits35-39 uint64_t reserved:5 | bits25-26 uint64_t reserved:2 | bit/type/unit 변경 |
| reserved1 | bits44-45 uint64_t reserved1:2 | bits35-39 uint64_t reserved1:5 | bit/type/unit 변경 |
| safety_relay_open | bit25 uint64_t safety_relay_open:1 | bit24 uint64_t safety_relay_open:1 | bit/type/unit 변경 |
| st_dead_reckoning | bit52 uint64_t st_dead_reckoning:1 | bit50 uint64_t st_dead_reckoning:1 | bit/type/unit 변경 |
| st_external_reset | bit55 uint64_t st_external_reset:1 | bit53 uint64_t st_external_reset:1 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| drv_info_comms_error | bit26 uint64_t drv_info_comms_error:1 | bits25-26 uint64_t reserved:2 |
| huge_sensor_update | bit24 uint64_t huge_sensor_update:1 | bit24 uint64_t safety_relay_open:1 |
| no_engine_state | bit34 uint64_t no_engine_state:1 | bit34 uint64_t w_huge_sensor_update:1 |
| reserved3 | bits53-54 uint64_t reserved3:2 | bit53 uint64_t st_external_reset:1 |
| st_using_imu_heading | bit50 uint64_t st_using_imu_heading:1 | bit50 uint64_t st_dead_reckoning:1 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| st_front_gnss_no_data_can | bit44 uint64_t st_front_gnss_no_data_can:1 | bits44-45 uint64_t reserved1:2 |
| st_rear_gnss_no_data_can | bit45 uint64_t st_rear_gnss_no_data_can:1 | bits44-45 uint64_t reserved1:2 |
| st_recent_gnss_available | bit52 uint64_t st_recent_gnss_available:1 | bit52 uint64_t st_dead_reckoning:1 |
| w_huge_sensor_update | bit34 uint64_t w_huge_sensor_update:1 | bit34 uint64_t no_engine_state:1 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit25 | bit25 uint64_t safety_relay_open:1 | bits25-26 uint64_t reserved:2 | Reserved 대체 후보: OhmioLibraries_BK reserved |
| bit26 | bit26 uint64_t drv_info_comms_error:1 | bits25-26 uint64_t reserved:2 | Reserved 대체 후보: OhmioLibraries_BK reserved |
| bit44 | bits44-45 uint64_t reserved1:2 | bit44 uint64_t st_front_gnss_no_data_can:1 | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit45 | bits44-45 uint64_t reserved1:2 | bit45 uint64_t st_rear_gnss_no_data_can:1 | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit53 | bits53-54 uint64_t reserved3:2 | bit53 uint64_t st_external_reset:1 | Reserved 대체 후보: OhmioLibraries_36 reserved |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit24 | bit24 uint64_t huge_sensor_update:1 | bit24 uint64_t safety_relay_open:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit34 | bit34 uint64_t no_engine_state:1 | bit34 uint64_t w_huge_sensor_update:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit50 | bit50 uint64_t st_using_imu_heading:1 | bit50 uint64_t st_dead_reckoning:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bit52 | bit52 uint64_t st_dead_reckoning:1 | bit52 uint64_t st_recent_gnss_available:1 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### FusionHeight_t
- raw buffer 크기 변경: OhmioLibraries_36=8, OhmioLibraries_BK=4
- Signal 총 bit 수 변경: OhmioLibraries_36=57, OhmioLibraries_BK=32
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| height | bits0-22 int64_t height:23, // m | bits0-15 int64_t height:16, // m | bit/type/unit 변경 |
| speed | bits23-34 int64_t speed:12, // m/s | bits16-27 int64_t speed:12, // m/s | bit/type/unit 변경 |
| sync | bits35-36 uint64_t sync:2 | bits30-31 uint64_t sync:2 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| delay_gnss_front | bits37-46 uint64_t delay_gnss_front:10 | - |
| delay_gnss_rear | bits47-56 uint64_t delay_gnss_rear:10 | - |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| reserved | bits28-29 uint64_t reserved:2 | bits23-34 int64_t speed:12, // m/s |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits28-29 | bits23-34 int64_t speed:12, // m/s | bits28-29 uint64_t reserved:2 | Reserved 대체 후보: OhmioLibraries_BK reserved |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits0-15 | bits0-22 int64_t height:23, // m | bits0-15 int64_t height:16, // m | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits16-22 | bits0-22 int64_t height:23, // m | bits16-27 int64_t speed:12, // m/s | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits23-27 | bits23-34 int64_t speed:12, // m/s | bits16-27 int64_t speed:12, // m/s | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits30-31 | bits23-34 int64_t speed:12, // m/s | bits30-31 uint64_t sync:2 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### IMUAcc_t
- message ID 주석 변경: OhmioLibraries_36=0x622 IMUAcc, OhmioLibraries_BK=0x262 IMUAcc
#### IMUGyr_t
- message ID 주석 변경: OhmioLibraries_36=0x623 IMUGyr, OhmioLibraries_BK=0x263 IMUGyr
#### IMUMag_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| x | bits0-19 int64_t x:20, // uT | bits0-15 int64_t x:16, // uT | bit/type/unit 변경 |
| y | bits20-39 int64_t y:20, // uT | bits16-31 int64_t y:16, // uT | bit/type/unit 변경 |
| z | bits40-59 int64_t z:20, // uT | bits32-47 int64_t z:16, // uT | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| reserved | bits60-61 uint64_t reserved:2 | bits50-61 uint64_t unused:12 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| status | bits48-49 uint64_t status:2 | bits40-59 int64_t z:20, // uT |
| unused | bits50-61 uint64_t unused:12 | bits40-59 int64_t z:20, // uT, bits60-61 uint64_t reserved:2 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits50-59 | bits40-59 int64_t z:20, // uT | bits50-61 uint64_t unused:12 | Reserved 대체 후보: OhmioLibraries_BK reserved |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits0-15 | bits0-19 int64_t x:20, // uT | bits0-15 int64_t x:16, // uT | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits16-19 | bits0-19 int64_t x:20, // uT | bits16-31 int64_t y:16, // uT | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits20-31 | bits20-39 int64_t y:20, // uT | bits16-31 int64_t y:16, // uT | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits32-39 | bits20-39 int64_t y:20, // uT | bits32-47 int64_t z:16, // uT | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits40-47 | bits40-59 int64_t z:20, // uT | bits32-47 int64_t z:16, // uT | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits48-49 | bits40-59 int64_t z:20, // uT | bits48-49 uint64_t status:2 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### IMURot_t
- message ID 주석 변경: OhmioLibraries_36=0x621 IMURot, OhmioLibraries_BK=0x261 IMURot
#### JoystickMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x181 JoystickMsg, 0x186 LocJoystickMsg, OhmioLibraries_BK=0x181 JoystickMsg, 0x183 TeleOpMsg, 0x186 LocJoystickMsg, 0x188 TransJoystickMsg
- Signal 총 bit 수 변경: OhmioLibraries_36=64, OhmioLibraries_BK=52
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| id | bits56-63 uint64_t id:8 | - |
| reserved | bits52-55 uint64_t reserved:4 | - |
#### LidarSpeed_t
- Signal 총 bit 수 변경: OhmioLibraries_36=62, OhmioLibraries_BK=57
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| delay | bits57-61 uint64_t delay:5, // mSec | - |
물리/편의 member 차이:
| member | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| delay | double delay | - |
#### LongitudeMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x211 FusionLongitudeFront, 0x214 FusionLongitudeRear, 0x7F3 EmulatorLongitude, OhmioLibraries_BK=0x211 FusionLongitudeFront, 0x214 FusionLongitudeRear, 0x221 longitudeFrontMsg, 0x231 longitudeBackMsg
#### ManagementError_t
- Signal 총 bit 수 변경: OhmioLibraries_36=26, OhmioLibraries_BK=18
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits4-7 uint64_t reserved:4 | bits2-7 uint64_t reserved:6 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| ignoreDZ | bits18-19 uint64_t ignoreDZ:2 | - |
| limpMode | bits24-25 uint64_t limpMode:2 | - |
| mcuVersionsOk | bits20-21 uint64_t mcuVersionsOk:2 | - |
| mgtDrvInfoCommsError | bit2 uint64_t mgtDrvInfoCommsError:1 | bits2-7 uint64_t reserved:6 |
| recording | bits22-23 uint64_t recording:2 | - |
| sharedDriveError | bit3 uint64_t sharedDriveError:1 | bits2-7 uint64_t reserved:6 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit2 | bit2 uint64_t mgtDrvInfoCommsError:1 | bits2-7 uint64_t reserved:6 | Reserved 대체 후보: OhmioLibraries_BK reserved |
| bit3 | bit3 uint64_t sharedDriveError:1 | bits2-7 uint64_t reserved:6 | Reserved 대체 후보: OhmioLibraries_BK reserved |
#### ManualDriveMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x180 ManualDriveMsg, 0x185 LocManualMsg, OhmioLibraries_BK=0x180 ManualDriveMsg, 0x185 LocManualMsg, 0x187 TransDriveMsg
- Signal 총 bit 수 변경: OhmioLibraries_36=64, OhmioLibraries_BK=56
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| id | bits56-63 uint64_t id:8 | - |
#### ObstacleDangerZoneMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits23-39 uint64_t reserved:17 | bits21-39 uint64_t reserved:19 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| movingSideways | bit22 uint64_t movingSideways:1, // bool | bits21-39 uint64_t reserved:19 |
| notMoving | bit21 uint64_t notMoving:1, // bool | bits21-39 uint64_t reserved:19 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit21 | bit21 uint64_t notMoving:1, // bool | bits21-39 uint64_t reserved:19 | Reserved 대체 후보: OhmioLibraries_BK reserved |
| bit22 | bit22 uint64_t movingSideways:1, // bool | bits21-39 uint64_t reserved:19 | Reserved 대체 후보: OhmioLibraries_BK reserved |
#### ObstacleEmergency_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits27-31 uint64_t reserved:5 | bits26-31 uint64_t reserved:6 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| obsErrorStop | bit26 uint64_t obsErrorStop:1, // bool | bits26-31 uint64_t reserved:6 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit26 | bit26 uint64_t obsErrorStop:1, // bool | bits26-31 uint64_t reserved:6 | Reserved 대체 후보: OhmioLibraries_BK reserved |
#### ObstacleTrackDistanceMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=44, OhmioLibraries_BK=42
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| ClearOnLeft | bit43 uint64_t ClearOnLeft:1, // bool | - |
| ClearOnRight | bit42 uint64_t ClearOnRight:1, // bool | - |
#### OdometerMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| value | bits0-31 uint64_t value:32, // km | bits0-31 uint64_t value:32, // m | bit/type/unit 변경 |
#### RemoteSignalMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=20, OhmioLibraries_BK=19
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| overtake | bit19 uint64_t overtake:1 | - |
#### ResetCauseMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x50 ResetLocalisation, 0x51 ResetDrive, 0x52 ResetSteering1, 0x53 ResetSteering2, 0x54 ResetManual, 0x55 ResetFusion, 0x56 ResetBlackBox, 0x57 ResetObsPC, 0x58 ResetLMotor, 0x59 ResetRMotor, 0x5A ResetEHB, 0x5C ResetEPB1, 0x5D ResetEPB2, 0x5E ResetSignal1, 0x5F ResetSignal2, 0x60 ResetJoystick, 0x63 ResetStartup, 0x68 ResetFoot1, 0x69 ResetFoot2, 0x6D ResetNetworkComm, 0x6E ResetAccessory1, 0x6F ResetAccessory2, 0x70 ResetWheelSpeed1, 0x71 ResetWheelSpeed2, 0x76 ResetTranslator, 0x77 ResetTranslator2, 0x78 ResetTeleOp, OhmioLibraries_BK=0x50 ResetLocalisation, 0x51 ResetDrive, 0x52 ResetSteering1, 0x53 ResetSteering2, 0x54 ResetManual, 0x55 ResetFusion, 0x56 ResetBlackBox, 0x57 ResetObsPC, 0x58 ResetLMotor, 0x59 ResetRMotor, 0x5A ResetEHB, 0x5C ResetEPB1, 0x5D ResetEPB2, 0x5E ResetSignal1, 0x5F ResetSignal2, 0x63 ResetStartup, 0x68 ResetFoot1, 0x69 ResetFoot2, 0x6D ResetNetworkComm, 0x6E ResetAccessory1, 0x6F ResetAccessory2, 0x70 ResetWheelSpeed1, 0x71 ResetWheelSpeed2, 0x76 ResetTranslator
#### SignalErrorMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=3, OhmioLibraries_BK=2
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| signalDrvInfoCommsError | bit2 uint64_t signalDrvInfoCommsError:1 | - |
#### StartupErrorMsg_t
- Signal 총 bit 수 변경: OhmioLibraries_36=7, OhmioLibraries_BK=5
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| lotteBmsErr | bit6 uint64_t lotteBmsErr:1 | - |
| startupDriveInfoComms | bit5 uint64_t startupDriveInfoComms:1 | - |
#### StartupStatusMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| reserved | bits5-6 uint64_t reserved:2 | bits4-6 uint64_t reserved:3 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| safetyLineErr | bit4 uint64_t safetyLineErr:1 | bits4-6 uint64_t reserved:3 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bit4 | bit4 uint64_t safetyLineErr:1 | bits4-6 uint64_t reserved:3 | Reserved 대체 후보: OhmioLibraries_BK reserved |
#### SystemReqMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| mode | bits0-5 uint64_t mode:6 | bits0-7 uint64_t mode:8 | bit/type/unit 변경 |
| reserved | bits6-7 uint64_t reserved:2 | bits40-60 uint64_t reserved:21 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| driveDisalowed | bit60 uint64_t driveDisalowed:1 | bits40-60 uint64_t reserved:21 |
| reserved1 | bits32-59 uint64_t reserved1:28 | bits32-39 uint64_t brakePressure:8, // bar, bits40-60 uint64_t reserved:21 |
OhmioLibraries_BK에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_36 겹침 영역 |
| --- | --- | --- |
| brakePressure | bits32-39 uint64_t brakePressure:8, // bar | bits32-59 uint64_t reserved1:28 |
Reserved 대체 후보:
| 범위 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits6-7 | bits6-7 uint64_t reserved:2 | bits0-7 uint64_t mode:8 | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bits32-39 | bits32-59 uint64_t reserved1:28 | bits32-39 uint64_t brakePressure:8, // bar | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit60 | bit60 uint64_t driveDisalowed:1 | bits40-60 uint64_t reserved:21 | Reserved 대체 후보: OhmioLibraries_BK reserved |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits0-5 | bits0-5 uint64_t mode:6 | bits0-7 uint64_t mode:8 | 동일 bit 영역의 non-reserved 정의 불일치 |
#### TrackAckMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x651 TrackAckManageMsg, 0x661 TrackAckDriveMsg, OhmioLibraries_BK=0x651 TrackAckManageMsg, 0x661 TrackAckDriveMsg, 0x671 TrackAckObsMsg
#### TrackCtrlMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x650 TrackCtrlManageMsg, 0x660 TrackCtrlDriveMsg, OhmioLibraries_BK=0x650 TrackCtrlManageMsg, 0x660 TrackCtrlDriveMsg, 0x670 TrackCtrlObsMsg
#### TrackDataMsg_t
- message ID 주석 변경: OhmioLibraries_36=0x652 TrackDataManageMsg, 0x662 TrackDataDriveMsg, OhmioLibraries_BK=0x652 TrackDataManageMsg, 0x662 TrackDataDriveMsg, 0x672 TrackDataObsMsg
#### WheelCountMsg_t
동일 Signal 이름의 정의 변경:
| Signal | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| left_count | bits16-31 uint64_t left_count:16 | bits32-63 uint64_t left_count:32 | bit/type/unit 변경 |
| right_count | bits0-15 uint64_t right_count:16 | bits0-31 uint64_t right_count:32 | bit/type/unit 변경 |
OhmioLibraries_36에만 있는 Signal:
| Signal | 정의 | OhmioLibraries_BK 겹침 영역 |
| --- | --- | --- |
| clock | bits32-63 uint64_t clock:32, // decinanos | bits32-63 uint64_t left_count:32 |
비트 범위 충돌:
| 겹침 | OhmioLibraries_36 | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| bits0-15 | bits0-15 uint64_t right_count:16 | bits0-31 uint64_t right_count:32 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits16-31 | bits16-31 uint64_t left_count:16 | bits0-31 uint64_t right_count:32 | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits32-63 | bits32-63 uint64_t clock:32, // decinanos | bits32-63 uint64_t left_count:32 | 동일 bit 영역의 non-reserved 정의 불일치 |

### 함수 선언/정의 비교
OhmioLibraries_36에만 있는 함수:
| Function | Kind | Signature |
| --- | --- | --- |
| DriveInfo500kWpMsg_FromCan | prototype | void DriveInfo500kWpMsg_FromCan(DriveInfo500kWpMsg_t * msg) |
| DriveInfo500kWpMsg_ToCan | prototype | void DriveInfo500kWpMsg_ToCan(DriveInfo500kWpMsg_t * msg) |
| EmulatorHeadingMsg_FromCan | prototype | void EmulatorHeadingMsg_FromCan(EmulatorHeadingMsg_t * msg) |
| EmulatorHeadingMsg_ToCan | prototype | void EmulatorHeadingMsg_ToCan(EmulatorHeadingMsg_t * msg) |
| ExtObsLocMsg_FromCan | prototype | void ExtObsLocMsg_FromCan(ExtObsLocMsg_t * msg) |
| ExtObsLocMsg_ToCan | prototype | void ExtObsLocMsg_ToCan(ExtObsLocMsg_t * msg) |
| ExtObsSpeedMsg_FromCan | prototype | void ExtObsSpeedMsg_FromCan(ExtObsSpeedMsg_t * msg) |
| ExtObsSpeedMsg_ToCan | prototype | void ExtObsSpeedMsg_ToCan(ExtObsSpeedMsg_t * msg) |
| IMUStatus_FromCan | prototype | void IMUStatus_FromCan(IMUStatus_t * msg) |
| IMUStatus_ToCan | prototype | void IMUStatus_ToCan(IMUStatus_t * msg) |
| LatitudeMsg_FromCan | prototype | void LatitudeMsg_FromCan(LatitudeMsg_t * msg) |
| LatitudeMsg_ToCan | prototype | void LatitudeMsg_ToCan(LatitudeMsg_t * msg) |
| ObstacleDangerZoneStopMsg_FromCan | prototype | void ObstacleDangerZoneStopMsg_FromCan(ObstacleDangerZoneStopMsg_t * msg) |
| ObstacleDangerZoneStopMsg_ToCan | prototype | void ObstacleDangerZoneStopMsg_ToCan(ObstacleDangerZoneStopMsg_t * msg) |
OhmioLibraries_BK에만 있는 함수:
| Function | Kind | Signature |
| --- | --- | --- |
| CombinedHeightMsg_FromCan | definition | void CombinedHeightMsg_FromCan(CombinedHeightMsg_t * msg) |
| CombinedHeightMsg_ToCan | definition | void CombinedHeightMsg_ToCan(CombinedHeightMsg_t * msg) |
| CompassMsg_FromCan | definition | void CompassMsg_FromCan(CompassMsg_t * msg) |
| CompassMsg_ToCan | definition | void CompassMsg_ToCan(CompassMsg_t * msg) |
| DeviationReqMsg_FromCan | definition | void DeviationReqMsg_FromCan(DeviationReqMsg_t * msg) |
| DeviationReqMsg_ToCan | definition | void DeviationReqMsg_ToCan(DeviationReqMsg_t * msg) |
| DriveInfoMsg_FromCan | definition | void DriveInfoMsg_FromCan(DriveInfoMsg_t * msg) |
| DriveInfoMsg_ToCan | definition | void DriveInfoMsg_ToCan(DriveInfoMsg_t * msg) |
| DynamicTrackValidationMsg_FromCan | definition | void DynamicTrackValidationMsg_FromCan(DynamicTrackValidationMsg_t * msg) |
| DynamicTrackValidationMsg_ToCan | definition | void DynamicTrackValidationMsg_ToCan(DynamicTrackValidationMsg_t * msg) |
| FusionFrontLongitude_FromCan | definition | void FusionFrontLongitude_FromCan(FusionFrontLongitude_t * msg) |
| FusionFrontLongitude_ToCan | definition | void FusionFrontLongitude_ToCan(FusionFrontLongitude_t * msg) |
| FusionLatitudeMsg_FromCan | definition | void FusionLatitudeMsg_FromCan(FusionLatitudeMsg_t * msg) |
| FusionLatitudeMsg_ToCan | definition | void FusionLatitudeMsg_ToCan(FusionLatitudeMsg_t * msg) |
| GPSLatitudeMsg_FromCan | definition | void GPSLatitudeMsg_FromCan(GPSLatitudeMsg_t * msg) |
| GPSLatitudeMsg_ToCan | definition | void GPSLatitudeMsg_ToCan(GPSLatitudeMsg_t * msg) |
| HeadingMsg_FromCan | definition | void HeadingMsg_FromCan(HeadingMsg_t * msg) |
| HeadingMsg_ToCan | definition | void HeadingMsg_ToCan(HeadingMsg_t * msg) |
| HeightMsg_FromCan | definition | void HeightMsg_FromCan(HeightMsg_t * msg) |
| HeightMsg_ToCan | definition | void HeightMsg_ToCan(HeightMsg_t * msg) |
| ObstacleDetectionLiDARMsg_FromCan | definition | void ObstacleDetectionLiDARMsg_FromCan(ObstacleDetectionLiDARMsg_t * msg) |
| ObstacleDetectionLiDARMsg_ToCan | definition | void ObstacleDetectionLiDARMsg_ToCan(ObstacleDetectionLiDARMsg_t * msg) |
| StopReqMsg_FromCan | definition | void StopReqMsg_FromCan(StopReqMsg_t * msg) |
| StopReqMsg_ToCan | definition | void StopReqMsg_ToCan(StopReqMsg_t * msg) |
| UWBLatitudeMsg_FromCan | definition | void UWBLatitudeMsg_FromCan(UWBLatitudeMsg_t * msg) |
| UWBLatitudeMsg_ToCan | definition | void UWBLatitudeMsg_ToCan(UWBLatitudeMsg_t * msg) |
| UWBLongitudeMsg_FromCan | definition | void UWBLongitudeMsg_FromCan(UWBLongitudeMsg_t * msg) |
| UWBLongitudeMsg_ToCan | definition | void UWBLongitudeMsg_ToCan(UWBLongitudeMsg_t * msg) |
| UltraSoundMsg_FromCan | definition | void UltraSoundMsg_FromCan(UltraSoundMsg_t * msg) |
| UltraSoundMsg_ToCan | definition | void UltraSoundMsg_ToCan(UltraSoundMsg_t * msg) |
함수 선언/정의 형태 변경:
| Function | OhmioLibraries_36 | OhmioLibraries_BK |
| --- | --- | --- |
| BMSStatusStdMsg_FromCan | prototype | static definition |
| BMSStatusStdMsg_ToCan | prototype | static definition |
| BatteryStatusMsg_FromCan | prototype | static definition |
| BatteryStatusMsg_ToCan | prototype | static definition |
| ConfigRespMsg_FromCan | prototype | static definition |
| ConfigRespMsg_ToCan | prototype | static definition |
| DriveInfoLongWpMsg_FromCan | prototype | static definition |
| DriveInfoLongWpMsg_ToCan | prototype | static definition |
| EHBPowerMsg_FromCan | prototype | static definition |
| EHBPowerMsg_ToCan | prototype | static definition |
| EHBReqMsg_FromCan | prototype | static definition |
| EHBReqMsg_ToCan | prototype | static definition |
| EHBT060PowerMsg_FromCan | prototype | static definition |
| EHBT060PowerMsg_ToCan | prototype | static definition |
| EPBStatusMsg_FromCan | prototype | static definition |
| EPBStatusMsg_ToCan | prototype | static definition |
| ErrorEHBT060_FromCan | prototype | static definition |
| ErrorEHBT060_ToCan | prototype | static definition |
| ErrorSteering_FromCan | prototype | static definition |
| ErrorSteering_ToCan | prototype | static definition |
| FusionAcceMsg_FromCan | prototype | static definition |
| FusionAcceMsg_ToCan | prototype | static definition |
| FusionBiasOutlierMsg_FromCan | prototype | static definition |
| FusionBiasOutlierMsg_ToCan | prototype | static definition |
| FusionFrontLatitude_FromCan | prototype | static definition |
| FusionFrontLatitude_ToCan | prototype | static definition |
| FusionHeight_FromCan | prototype | static definition |
| FusionHeight_ToCan | prototype | static definition |
| FusionInfoMsg_FromCan | prototype | static definition |
| FusionInfoMsg_ToCan | prototype | static definition |
| FusionRearLatitude_FromCan | prototype | static definition |
| FusionRearLatitude_ToCan | prototype | static definition |
| FusionRearLongitude_FromCan | prototype | static definition |
| FusionRearLongitude_ToCan | prototype | static definition |
| IMUAcc_FromCan | prototype | static definition |
| IMUAcc_ToCan | prototype | static definition |
| IMUGyr_FromCan | prototype | static definition |
| IMUGyr_ToCan | prototype | static definition |
| IMUMag_FromCan | prototype | static definition |
| IMUMag_ToCan | prototype | static definition |
| IMURot_FromCan | prototype | static definition |
| IMURot_ToCan | prototype | static definition |
| InterVehicleCommsMsg_FromCan | prototype | static definition |
| InterVehicleCommsMsg_ToCan | prototype | static definition |
| LidarLatitudeUndelayed_FromCan | prototype | static definition |
| LidarLatitudeUndelayed_ToCan | prototype | static definition |
| LidarLongitudeUndelayed_FromCan | prototype | static definition |
| LidarLongitudeUndelayed_ToCan | prototype | static definition |
| LidarSpeed_FromCan | prototype | static definition |
| LidarSpeed_ToCan | prototype | static definition |
| LongitudeMsg_FromCan | prototype | static definition |
| LongitudeMsg_ToCan | prototype | static definition |
| ManualDriveMsg_FromCan | prototype | static definition |
| ManualDriveMsg_ToCan | prototype | static definition |
| Motor3Status2_FromCan | prototype | static definition |
| Motor3Status2_ToCan | prototype | static definition |
| Motor3Status5_FromCan | prototype | static definition |
| Motor3Status5_ToCan | prototype | static definition |
| Motor3Status6_FromCan | prototype | static definition |
| Motor3Status6_ToCan | prototype | static definition |
| MotorReqMsg_FromCan | prototype | static definition |
| MotorReqMsg_ToCan | prototype | static definition |
| MotorStatus_FromCan | prototype | static definition |
| MotorStatus_ToCan | prototype | static definition |
| ObsHeadingMsg_FromCan | prototype | static definition |
| ObsHeadingMsg_ToCan | prototype | static definition |
| ObsLatitudeMsg_FromCan | prototype | static definition |
| ObsLatitudeMsg_ToCan | prototype | static definition |
| ObsLongitudeMsg_FromCan | prototype | static definition |
| ObsLongitudeMsg_ToCan | prototype | static definition |
| ObsTrackOffsetMsg_FromCan | prototype | static definition |
| ObsTrackOffsetMsg_ToCan | prototype | static definition |
| ObstacleDangerZoneMsg_FromCan | prototype | static definition |
| ObstacleDangerZoneMsg_ToCan | prototype | static definition |
| ObstacleEmergency_FromCan | prototype | static definition |
| ObstacleEmergency_ToCan | prototype | static definition |
| ObstacleTrackDistanceMsg_FromCan | prototype | static definition |
| ObstacleTrackDistanceMsg_ToCan | prototype | static definition |
| OdometerMsg_FromCan | prototype | static definition |
| OdometerMsg_ToCan | prototype | static definition |
| OdometryParameters_FromCan | prototype | static definition |
| OdometryParameters_ToCan | prototype | static definition |
| ParameterConfMsg_FromCan | prototype | static definition |
| ParameterConfMsg_ToCan | prototype | static definition |
| ParameterConfSignMsg_FromCan | prototype | static definition |
| ParameterConfSignMsg_ToCan | prototype | static definition |
| PlatStartMsg_FromCan | prototype | static definition |
| PlatStartMsg_ToCan | prototype | static definition |
| PlatoonSimMsg_FromCan | prototype | static definition |
| PlatoonSimMsg_ToCan | prototype | static definition |
| Speed2TorqueReqMsg_FromCan | prototype | static definition |
| Speed2TorqueReqMsg_ToCan | prototype | static definition |
| Speed2TorqueRespMsg_FromCan | prototype | static definition |
| Speed2TorqueRespMsg_ToCan | prototype | static definition |
| SteerCalibrationMsg_FromCan | prototype | static definition |
| SteerCalibrationMsg_ToCan | prototype | static definition |
| SteerMsg_FromCan | prototype | static definition |
| SteerMsg_ToCan | prototype | static definition |
| SteeringReqMsg_FromCan | prototype | static definition |
| SteeringReqMsg_ToCan | prototype | static definition |
| SteeringRespMsg_FromCan | prototype | static definition |
| SteeringRespMsg_ToCan | prototype | static definition |
| SteeringStatusMsg_FromCan | prototype | static definition |
| SteeringStatusMsg_ToCan | prototype | static definition |
| TrafficLightMsg_FromCan | prototype | static definition |
| TrafficLightMsg_ToCan | prototype | static definition |
| UBXPart1Msg_FromCan | prototype | static definition |
| UBXPart1Msg_ToCan | prototype | static definition |
| UBXPart2Msg_FromCan | prototype | static definition |
| UBXPart2Msg_ToCan | prototype | static definition |
| VehicleInfoMsg_FromCan | prototype | static definition |
| VehicleInfoMsg_ToCan | prototype | static definition |
| WheelSpeedEvents_FromCan | prototype | static definition |
| WheelSpeedEvents_ToCan | prototype | static definition |
| WheelSpeedMsg_FromCan | prototype | static definition |
| WheelSpeedMsg_ToCan | prototype | static definition |

## 사용자 점검 후보
- DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 6 -> 3
- DrvWarningMsgErrorCode.Drv_NumWarningCodes 값 변경: 8 -> 7
- EPBMsgErrorCode.EPB_NumErrorCodes 값 변경: 5 -> 4
- FootMsgErrorCode.Foot_NumErrorCodes 값 변경: 9 -> 8
- FusErrorCode.fus_NumErrorCodes 값 변경: 0x1B -> 0x19
- FusErrorCode.fus_safety_relay_open 값 변경: 0x19 -> 0x18
- FusionDebugMsgErrorCode.fusdebug_NumErrorCodes 값 변경: 0x31 -> 0x32
- FusionDebugMsgErrorCode.fusdebug_Reserved 값 변경: 7 -> 0x10
- FusionDebugMsgErrorCode.fusdebug_Reserved10 값 변경: 0x18 -> 0x19
- FusionDebugMsgErrorCode.fusdebug_Reserved11 값 변경: 0x19 -> 0x1A
- FusionDebugMsgErrorCode.fusdebug_Reserved12 값 변경: 0x1A -> 0x1B
- FusionDebugMsgErrorCode.fusdebug_Reserved13 값 변경: 0x1B -> 0x1C
- FusionDebugMsgErrorCode.fusdebug_Reserved14 값 변경: 0x1C -> 0x1D
- FusionDebugMsgErrorCode.fusdebug_Reserved15 값 변경: 0x1D -> 0x1E
- FusionDebugMsgErrorCode.fusdebug_Reserved16 값 변경: 0x1E -> 0x1F
- FusionDebugMsgErrorCode.fusdebug_Reserved17 값 변경: 0x1F -> 0x2C
- FusionDebugMsgErrorCode.fusdebug_Reserved2 값 변경: 8 -> 0x11
- FusionDebugMsgErrorCode.fusdebug_Reserved3 값 변경: 0x11 -> 0x12
- FusionDebugMsgErrorCode.fusdebug_Reserved4 값 변경: 0x12 -> 0x13
- FusionDebugMsgErrorCode.fusdebug_Reserved5 값 변경: 0x13 -> 0x14
- FusionDebugMsgErrorCode.fusdebug_Reserved6 값 변경: 0x14 -> 0x15
- FusionDebugMsgErrorCode.fusdebug_Reserved7 값 변경: 0x15 -> 0x16
- FusionDebugMsgErrorCode.fusdebug_Reserved8 값 변경: 0x16 -> 0x17
- FusionDebugMsgErrorCode.fusdebug_Reserved9 값 변경: 0x17 -> 0x18
- FusionErrorCode.Fusion_NumErrorCodes 값 변경: 0x1A -> 0x18
- LocalisationErrorCode.Loc_Reserved 값 변경: 0xD -> 0xC
- LocalisationErrorCode.Loc_Reserved10 값 변경: 0x16 -> 0x15
- LocalisationErrorCode.Loc_Reserved11 값 변경: 0x17 -> 0x16
- LocalisationErrorCode.Loc_Reserved12 값 변경: 0x18 -> 0x17
- LocalisationErrorCode.Loc_Reserved13 값 변경: 0x19 -> 0x18
- LocalisationErrorCode.Loc_Reserved14 값 변경: 0x1A -> 0x19
- LocalisationErrorCode.Loc_Reserved15 값 변경: 0x1B -> 0x1A
- LocalisationErrorCode.Loc_Reserved2 값 변경: 0xE -> 0xD
- LocalisationErrorCode.Loc_Reserved3 값 변경: 0xF -> 0xE
- LocalisationErrorCode.Loc_Reserved4 값 변경: 0x10 -> 0xF
- LocalisationErrorCode.Loc_Reserved5 값 변경: 0x11 -> 0x10
- LocalisationErrorCode.Loc_Reserved6 값 변경: 0x12 -> 0x11
- LocalisationErrorCode.Loc_Reserved7 값 변경: 0x13 -> 0x12
- LocalisationErrorCode.Loc_Reserved8 값 변경: 0x14 -> 0x13
- LocalisationErrorCode.Loc_Reserved9 값 변경: 0x15 -> 0x14
- ManagementErrorCode.mgt_NumErrorCodes 값 변경: 4 -> 2
- ManualErrorCode.Man_NumErrorCodes 값 변경: 6 -> 4
- ObstaclePCErrorCode.Obstacle_NumErrorCodes 값 변경: 0x19 -> 0x18
- SignalMsgErrorCode.signal_NumErrorCodes 값 변경: 3 -> 2
- StartupMsgErrorCode.startup_NumErrorCodes 값 변경: 7 -> 5
- WheelSpeedErrorCode.wheel_NumErrorCodes 값 변경: 3 -> 2
- AtmelLocalisaionError_t: non-reserved bit 범위 충돌 2건
- ErrorAccessory_t: non-reserved bit 범위 충돌 4건
- ErrorFusionDebugMsg_t: non-reserved bit 범위 충돌 1건
- ErrorFusionDebugMsg_t: Reserved 대체 후보 3건
- ErrorLocalisation_t: Reserved 대체 후보 1건
- ExceptionMsg_t: non-reserved bit 범위 충돌 2건
- FusError_t: non-reserved bit 범위 충돌 1건
- FusionFlagsMsg_t: non-reserved bit 범위 충돌 4건
- FusionFlagsMsg_t: Reserved 대체 후보 5건
- FusionHeight_t: non-reserved bit 범위 충돌 4건
- FusionHeight_t: Reserved 대체 후보 1건
- IMUMag_t: non-reserved bit 범위 충돌 6건
- IMUMag_t: Reserved 대체 후보 1건
- ManagementError_t: Reserved 대체 후보 2건
- ObstacleDangerZoneMsg_t: Reserved 대체 후보 2건
- ObstacleEmergency_t: Reserved 대체 후보 1건
- StartupStatusMsg_t: Reserved 대체 후보 1건
- SystemReqMsg_t: non-reserved bit 범위 충돌 1건
- SystemReqMsg_t: Reserved 대체 후보 3건
- WheelCountMsg_t: non-reserved bit 범위 충돌 3건
