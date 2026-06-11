# dbc_CAN.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 3662 | 4787 |
| SHA256 | acde60291555 | e1d368cabda6 |
| Include | 3 | 6 |
| Define | 1 | 1 |
| Struct/Message | 146 | 152 |
| Enum | 28 | 25 |
| CAN_ID | 0 | 0 |
| Function | 130 | 146 |
| Unified diff | -1560 | +2685 |

## 전처리/Define 비교

| Include | 구분 |
| --- | --- |
| `"ConversionHelper.h"` | OhmioLibraries_BK에만 있음 |
| `<assert.h>` | OhmioLibraries_BK에만 있음 |
| `<math.h>` | OhmioLibraries_BK에만 있음 |

- define 차이 없음.

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 15 | `AnyExceptionMsg`, `AtmelTeleopError`, `ConnectWp`, `DriveInfo500kWpMsg`, `EmulatorHeadingMsg`, `ErrorNetwork`, `ErrorTeleOp`, `ExtObsLocMsg`, `ExtObsSpeedMsg`, `GpsPpsMsg`, `IMUStatus`, `LatitudeMsg`, `ObsoleteMsg`, `ObstacleDangerZoneStopMsg`, `ObstaclePcWarning` |
| OhmioLibraries_BK에만 있는 struct | 21 | `BrakeReqMsg`, `CombinedHeightMsg`, `CompassMsg`, `DeviationReqMsg`, `DriveInfoMsg`, `DynamicTrackValidationMsg`, `ErrorMotorAdaptor`, `ErrorTrans`, `FusionFrontLongitude`, `FusionLatitudeMsg`, `GPSLatitudeMsg`, `HeadingMsg`, `HeightMsg`, `LogIndMsg`, `ObstacleDetectionLiDARMsg`, `PrintASCIIMsg`, `StopReqMsg`, `UWBDistanceMsg`, `UWBLatitudeMsg`, `UWBLongitudeMsg`, `UltraSoundMsg` |
| 공통 struct 중 layout/comment 차이 | 39 | `AtmelLocalisaionError`, `AtmelResetMsg`, `DriveWarningMsg`, `EPBErrorMsg`, `ErrorAccessory`, `ErrorDriveExt`, `ErrorFootMsg`, `ErrorFusion`, `ErrorFusionDebugMsg`, `ErrorLocalisation`, `ErrorManual`, `ErrorObstaclePC`, `ErrorWheelSpeed`, `ExceptionMsg`, `FusError`, `FusionFlagsMsg`, `FusionHeight`, `IMUAcc`, `IMUGyr`, `IMUMag`, `IMURot`, `JoystickMsg`, `LidarSpeed`, `LongitudeMsg`, `ManagementError`, `ManualDriveMsg`, `ObstacleDangerZoneMsg`, `ObstacleEmergency`, `ObstacleTrackDistanceMsg`, `RemoteSignalMsg`, `ResetCauseMsg`, `SignalErrorMsg`, `StartupErrorMsg`, `StartupStatusMsg`, `SystemReqMsg`, `TrackAckMsg`, `TrackCtrlMsg`, `TrackDataMsg`, `WheelCountMsg` |

### Origin_36_merge에만 있는 struct

| Struct | Line | Message ID comment | Total bits |
| --- | ---: | --- | ---: |
| `AnyExceptionMsg` | 2622 | 0x7F0 AnyExceptionMsg | 48 |
| `AtmelTeleopError` | 3304 | 0x118 AtmelTeleopError | 1 |
| `ConnectWp` | 588 | 0x630 ConnectWp | 49 |
| `DriveInfo500kWpMsg` | 1267 | 0x328 DriveInfo500kWpMsg | 63 |
| `EmulatorHeadingMsg` | 1408 | 0x7F4 EmulatorHeadingMsg | 16 |
| `ErrorNetwork` | 3447 |  | 3 |
| `ErrorTeleOp` | 3183 |  | 2 |
| `ExtObsLocMsg` | 1426 | 0x5A0 ExtObsLocMsg | 61 |
| `ExtObsSpeedMsg` | 1448 | 0x5A1 ExtObsSpeedMsg | 33 |
| `GpsPpsMsg` | 11 | 0x38 Timepulse_front; 0x39 Timepulse_rear | 34 |
| `IMUStatus` | 2456 | 0x624 IMUStatus | 61 |
| `LatitudeMsg` | 1811 | 0x210 FusionLatitudeFrontMsg; 0x213 FusionLatitudeRearMsg; 0x7F2 EmulatorLatitudeMsg | 64 |
| `ObsoleteMsg` | 1486 | 0x231 Obsolete_longitudeBackMsg; 0x232 Obsolete_heightBackMsg; 0x233 Obsolete_HeadingMsg; 0x234 Obsolete_combineHeightBackMsg; 0x250 Obsolete_UWBDistanceMsg; 0x251 Obsolete_UWBLatitudeMsg; 0x252 Obsolete_UWBLongitudeMsg; 0x260 Obsolete_CompassMsg; 0x321 Obsolete_DriveInfoMsg; 0x710 Obsolete_LogIndMsg | 64 |
| `ObstacleDangerZoneStopMsg` | 1577 | 0x124 ObstacleDangerZoneStopMsg | 32 |
| `ObstaclePcWarning` | 2502 |  | 18 |

### OhmioLibraries_BK에만 있는 struct

| Struct | Line | Message ID comment | Total bits |
| --- | ---: | --- | ---: |
| `BrakeReqMsg` | 1163 | 0x160 BrakeReqMsg | 64 |
| `CombinedHeightMsg` | 1957 | 0x223 combineHeightFrontMsg; 0x234 combineHeightBackMsg | 64 |
| `CompassMsg` | 2014 | 0x260 CompassMsg | 64 |
| `DeviationReqMsg` | 595 | 0x2C5 DeviationReqMsg | 38 |
| `DriveInfoMsg` | 1456 | 0x321 DriveInfoMsg | 64 |
| `DynamicTrackValidationMsg` | 2979 | 0x300 DynamicTrackValidationMsg | 56 |
| `ErrorMotorAdaptor` | 4510 | 0x2D ErrorMotorAdaptor | 64 |
| `ErrorTrans` | 4161 |  | 4 |
| `FusionFrontLongitude` | 2477 | 0x21A FusionFrontLongitude | 64 |
| `FusionLatitudeMsg` | 2363 | 0x210 FusionLatitudeFrontMsg; 0x213 FusionLatitudeRearMsg | 64 |
| `GPSLatitudeMsg` | 1671 | 0x220 latitudeFrontMsg; 0x230 latitudeBackMsg | 64 |
| `HeadingMsg` | 1986 | 0x233 HeadingMsg | 16 |
| `HeightMsg` | 1920 | 0x222 heightFrontMsg; 0x232 heightBackMsg | 64 |
| `LogIndMsg` | 536 | 0x710 LogIndMsg | 1 |
| `ObstacleDetectionLiDARMsg` | 3341 | 0x120 ObstacleDetectionLiDARMsg | 64 |
| `PrintASCIIMsg` | 3101 | 0x7F0 PrintASCIIMsg | 64 |
| `StopReqMsg` | 217 | 0x326 StopReqMsg | 32 |
| `UWBDistanceMsg` | 2044 | 0x250 UWBDistanceMsg | 64 |
| `UWBLatitudeMsg` | 2060 | 0x251 UWBLatitudeMsg | 56 |
| `UWBLongitudeMsg` | 2089 | 0x252 UWBLongitudeMsg | 56 |
| `UltraSoundMsg` | 4319 | 0x121 UltraSoundMsg | 48 |

### 공통 struct layout/comment 차이

| Struct | 차이 요약 | bit overlap 충돌 예시 |
| --- | --- | --- |
| `AtmelLocalisaionError` | Origin_36_merge signal only: `AtlocGPS1InputError`, `AtlocGPS2InputError`<br>BK signal only: `AtlocGPSInputSearchError`, `AtlocUWBInputSearchError` | 0-0: Origin `AtlocGPS1InputError`[0-0] vs BK `AtlocGPSInputSearchError`[0-0]<br>1-1: Origin `AtlocGPS2InputError`[1-1] vs BK `AtlocUWBInputSearchError`[1-1] |
| `AtmelResetMsg` | message ID comment differs | - |
| `DriveWarningMsg` | Origin_36_merge signal only: `DrvMcuVerIncompatible`<br>total bits 8 != 7 | - |
| `EPBErrorMsg` | Origin_36_merge signal only: `EPBDrvInfoCommsError`<br>total bits 5 != 4 | - |
| `ErrorAccessory` | Origin_36_merge signal only: `AccessoryDrvInfoComms`, `AccessoryIncorrectPCB`, `AccessoryNonUniqueID`, `AccessoryRelayOpen`<br>BK signal only: `code`<br>total bits 4 != 64<br>message ID comment differs | 0-0: Origin `AccessoryIncorrectPCB`[0-0] vs BK `code`[0-63]<br>1-1: Origin `AccessoryNonUniqueID`[1-1] vs BK `code`[0-63]<br>2-2: Origin `AccessoryRelayOpen`[2-2] vs BK `code`[0-63]<br>3-3: Origin `AccessoryDrvInfoComms`[3-3] vs BK `code`[0-63] |
| `ErrorDriveExt` | Origin_36_merge signal only: `DrvextEPB1CommsError`, `DrvextEPB2CommsError`, `DrvextMotorOverTemp`, `DrvextParameterOutOfRange`, `DrvextSpeedDeviationError`<br>total bits 8 != 3 | - |
| `ErrorFootMsg` | Origin_36_merge signal only: `FootDrvInfoCommsError`<br>total bits 9 != 8 | - |
| `ErrorFusion` | Origin_36_merge signal only: `FusionDrvInfoCommsError`, `FusionHugeSensorUpdate`<br>total bits 26 != 24 | - |
| `ErrorFusionDebugMsg` | Origin_36_merge signal only: `drive_info_comms`, `huge_sensor_update`, `reserved2`<br>BK signal only: `odometryNull`, `rtkFrontNull`, `rtkRearNull`, `w_huge_sensor_update`<br>same signal bit/type change: `reserved` width: 2 != 16; lsb: 7 != 16; msb: 8 != 31; `reserved1` width: 15 != 1; lsb: 17 != 44; msb: 31 != 44<br>total bits 49 != 50 | 6-6: Origin `huge_sensor_update`[6-6] vs BK `odometryNull`[6-6]<br>7-7: Origin `reserved`[7-8] vs BK `rtkFrontNull`[7-7]<br>8-8: Origin `reserved`[7-8] vs BK `rtkRearNull`[8-8]<br>16-16: Origin `drive_info_comms`[16-16] vs BK `reserved`[16-31]<br>17-31: Origin `reserved1`[17-31] vs BK `reserved`[16-31] |
| `ErrorLocalisation` | Origin_36_merge signal only: `LocDriInfoCommsError`<br>same signal bit/type change: `reserved` width: 15 != 16; lsb: 13 != 12 | 12-12: Origin `LocDriInfoCommsError`[12-12] vs BK `reserved`[12-27]<br>13-27: Origin `reserved`[13-27] vs BK `reserved`[12-27] |
| `ErrorManual` | Origin_36_merge signal only: `DuplicatedJoystickBoard`, `ManDriInfoComsError`<br>total bits 6 != 4 | - |
| `ErrorObstaclePC` | Origin_36_merge signal only: `Obstacle_drv_info_comms_error`<br>total bits 25 != 24 | - |
| `ErrorWheelSpeed` | Origin_36_merge signal only: `wheel_drv_info_comms_error`<br>total bits 3 != 2 | - |
| `ExceptionMsg` | same signal bit/type change: `ex_addr` width: 32 != 5; lsb: 0 != 32; msb: 31 != 36; `ex_code` width: 5 != 32; lsb: 32 != 0; msb: 36 != 31 | 0-31: Origin `ex_addr`[0-31] vs BK `ex_code`[0-31]<br>32-36: Origin `ex_code`[32-36] vs BK `ex_addr`[32-36] |
| `FusError` | Origin_36_merge signal only: `fus_drv_info_comms_error`, `fus_huge_sensor_update`<br>same signal bit/type change: `fus_safety_relay_open` lsb: 25 != 24; msb: 25 != 24<br>total bits 27 != 25 | 24-24: Origin `fus_huge_sensor_update`[24-24] vs BK `fus_safety_relay_open`[24-24] |
| `FusionFlagsMsg` | Origin_36_merge signal only: `drv_info_comms_error`, `huge_sensor_update`, `reserved3`, `reserved4`, `st_using_imu_heading`, `w_large_gnss_delay`, `w_large_lidar_delay`, `w_no_engine_state`<br>BK signal only: `reserved`, `st_front_gnss_no_data_can`, `st_rear_gnss_no_data_can`, `st_recent_gnss_available`, `w_huge_sensor_update`<br>same signal bit/type change: `reserved1` width: 3 != 5; lsb: 37 != 35; `reserved2` width: 2 != 1; lsb: 44 != 51; msb: 45 != 51; `safety_relay_open` lsb: 25 != 24; msb: 25 != 24; `st_dead_reckoning` lsb: 52 != 50; msb: 52 != 50; `st_external_reset` lsb: 55 != 53; msb: 55 != 53<br>total bits 56 != 54 | 24-24: Origin `huge_sensor_update`[24-24] vs BK `safety_relay_open`[24-24]<br>25-25: Origin `safety_relay_open`[25-25] vs BK `reserved`[25-26]<br>26-26: Origin `drv_info_comms_error`[26-26] vs BK `reserved`[25-26]<br>34-34: Origin `w_no_engine_state`[34-34] vs BK `w_huge_sensor_update`[34-34]<br>35-35: Origin `w_large_gnss_delay`[35-35] vs BK `reserved1`[35-39] |
| `FusionHeight` | Origin_36_merge signal only: `compute_time`, `delay_gnss_front`, `delay_gnss_rear`<br>BK signal only: `reserved`<br>same signal bit/type change: `height` width: 23 != 16; msb: 22 != 15; `speed` lsb: 23 != 16; msb: 34 != 27; `sync` lsb: 35 != 30; msb: 36 != 31<br>total bits 64 != 32<br>Origin_36_merge decoded field only: `compute_time` | 0-15: Origin `height`[0-22] vs BK `height`[0-15]<br>16-22: Origin `height`[0-22] vs BK `speed`[16-27]<br>23-27: Origin `speed`[23-34] vs BK `speed`[16-27]<br>28-29: Origin `speed`[23-34] vs BK `reserved`[28-29]<br>30-31: Origin `speed`[23-34] vs BK `sync`[30-31] |
| `IMUAcc` | message ID comment differs | - |
| `IMUGyr` | message ID comment differs | - |
| `IMUMag` | Origin_36_merge signal only: `reserved`<br>BK signal only: `status`, `unused`<br>same signal bit/type change: `x` width: 20 != 16; msb: 19 != 15; `y` width: 20 != 16; lsb: 20 != 16; msb: 39 != 31; `z` width: 20 != 16; lsb: 40 != 32; msb: 59 != 47 | 0-15: Origin `x`[0-19] vs BK `x`[0-15]<br>16-19: Origin `x`[0-19] vs BK `y`[16-31]<br>20-31: Origin `y`[20-39] vs BK `y`[16-31]<br>32-39: Origin `y`[20-39] vs BK `z`[32-47]<br>40-47: Origin `z`[40-59] vs BK `z`[32-47] |
| `IMURot` | message ID comment differs | - |
| `JoystickMsg` | Origin_36_merge signal only: `id`, `reserved`<br>total bits 64 != 52<br>message ID comment differs | - |
| `LidarSpeed` | Origin_36_merge signal only: `delay`<br>total bits 62 != 57<br>Origin_36_merge decoded field only: `delay` | - |
| `LongitudeMsg` | message ID comment differs | - |
| `ManagementError` | Origin_36_merge signal only: `ignoreDZ`, `limpMode`, `mcuVersionsOk`, `mgtDrvInfoCommsError`, `recording`, `sharedDriveError`<br>same signal bit/type change: `reserved` width: 4 != 6; lsb: 4 != 2<br>total bits 26 != 18 | 2-2: Origin `mgtDrvInfoCommsError`[2-2] vs BK `reserved`[2-7]<br>3-3: Origin `sharedDriveError`[3-3] vs BK `reserved`[2-7]<br>4-7: Origin `reserved`[4-7] vs BK `reserved`[2-7] |
| `ManualDriveMsg` | Origin_36_merge signal only: `id`<br>total bits 64 != 56<br>message ID comment differs | - |
| `ObstacleDangerZoneMsg` | Origin_36_merge signal only: `movingSideways`, `notMoving`<br>same signal bit/type change: `reserved` width: 17 != 19; lsb: 23 != 21 | 21-21: Origin `notMoving`[21-21] vs BK `reserved`[21-39]<br>22-22: Origin `movingSideways`[22-22] vs BK `reserved`[21-39]<br>23-39: Origin `reserved`[23-39] vs BK `reserved`[21-39] |
| `ObstacleEmergency` | Origin_36_merge signal only: `obsErrorStop`<br>same signal bit/type change: `reserved` width: 5 != 6; lsb: 27 != 26 | 26-26: Origin `obsErrorStop`[26-26] vs BK `reserved`[26-31]<br>27-31: Origin `reserved`[27-31] vs BK `reserved`[26-31] |
| `ObstacleTrackDistanceMsg` | Origin_36_merge signal only: `BackDistance`, `ClearOnLeft`, `ClearOnRight`, `reserved`<br>total bits 64 != 42<br>Origin_36_merge decoded field only: `BackDistance` | - |
| `RemoteSignalMsg` | Origin_36_merge signal only: `overtake`<br>total bits 20 != 19 | - |
| `ResetCauseMsg` | message ID comment differs | - |
| `SignalErrorMsg` | Origin_36_merge signal only: `signalDrvInfoCommsError`<br>total bits 3 != 2 | - |
| `StartupErrorMsg` | Origin_36_merge signal only: `lotteBmsErr`, `startupDriveInfoComms`<br>total bits 7 != 5 | - |
| `StartupStatusMsg` | Origin_36_merge signal only: `safetyLineErr`<br>same signal bit/type change: `reserved` width: 2 != 3; lsb: 5 != 4 | 4-4: Origin `safetyLineErr`[4-4] vs BK `reserved`[4-6]<br>5-6: Origin `reserved`[5-6] vs BK `reserved`[4-6] |
| `SystemReqMsg` | Origin_36_merge signal only: `driveDisalowed`, `reserved1`<br>BK signal only: `brakePressure`<br>same signal bit/type change: `mode` width: 6 != 8; msb: 5 != 7; `reserved` width: 2 != 21; lsb: 6 != 40; msb: 7 != 60 | 0-5: Origin `mode`[0-5] vs BK `mode`[0-7]<br>6-7: Origin `reserved`[6-7] vs BK `mode`[0-7]<br>32-39: Origin `reserved1`[32-59] vs BK `brakePressure`[32-39]<br>40-59: Origin `reserved1`[32-59] vs BK `reserved`[40-60]<br>60-60: Origin `driveDisalowed`[60-60] vs BK `reserved`[40-60] |
| `TrackAckMsg` | message ID comment differs | - |
| `TrackCtrlMsg` | message ID comment differs | - |
| `TrackDataMsg` | message ID comment differs | - |
| `WheelCountMsg` | Origin_36_merge signal only: `clock`<br>same signal bit/type change: `left_count` width: 16 != 32; lsb: 16 != 32; msb: 31 != 63; `right_count` width: 16 != 32; msb: 15 != 31 | 0-15: Origin `right_count`[0-15] vs BK `right_count`[0-31]<br>16-31: Origin `left_count`[16-31] vs BK `right_count`[0-31]<br>32-63: Origin `clock`[32-63] vs BK `left_count`[32-63] |

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 enum | 4 | `AccessoryErrorCode`, `NetworkErrorCode`, `ObstaclePcWarningErrorCode`, `TeleOpErrorCode` |
| OhmioLibraries_BK에만 있는 enum | 1 | `TransErrorCode` |
| 공통 enum entry 차이 | 15 | `AtmelLocalisaionErrorCode`, `DrvExtErrorCode`, `DrvWarningMsgErrorCode`, `EPBMsgErrorCode`, `FootMsgErrorCode`, `FusErrorCode`, `FusionDebugMsgErrorCode`, `FusionErrorCode`, `LocalisationErrorCode`, `ManagementErrorCode`, `ManualErrorCode`, `ObstaclePCErrorCode`, `SignalMsgErrorCode`, `StartupMsgErrorCode`, `WheelSpeedErrorCode` |

### AtmelLocalisaionErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Atloc_GPS1_Input` | `0` |  | Origin_36_merge에만 있음 |
| `Atloc_GPS2_Input` | `1` |  | Origin_36_merge에만 있음 |
| `Atloc_GPS_Input_Search` |  | `0` | OhmioLibraries_BK에만 있음 |
| `Atloc_UWB_Input_Search` |  | `1` | OhmioLibraries_BK에만 있음 |

### DrvExtErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Drvext_EPB1_Comms` | `6` |  | Origin_36_merge에만 있음 |
| `Drvext_EPB2_Comms` | `7` |  | Origin_36_merge에만 있음 |
| `Drvext_Motor_Over_Temp` | `4` |  | Origin_36_merge에만 있음 |
| `Drvext_Parameter_Out_Of_Range` | `3` |  | Origin_36_merge에만 있음 |
| `Drvext_Speed_Deviation` | `5` |  | Origin_36_merge에만 있음 |
| `Drvext_NumErrorCodes` | `8` | `3` | 값 변경 |

### DrvWarningMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Drv_Mcu_Ver_Incompatible` | `7` |  | Origin_36_merge에만 있음 |
| `Drv_NumWarningCodes` | `8` | `7` | 값 변경 |

### EPBMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `EPB_Drv_Info_Comms` | `4` |  | Origin_36_merge에만 있음 |
| `EPB_NumErrorCodes` | `5` | `4` | 값 변경 |

### FootMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Foot_Drv_Info_Comms` | `8` |  | Origin_36_merge에만 있음 |
| `Foot_NumErrorCodes` | `9` | `8` | 값 변경 |

### FusErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `fus_drv_info_comms` | `0x1a` |  | Origin_36_merge에만 있음 |
| `fus_huge_sensor_update` | `0x18` |  | Origin_36_merge에만 있음 |
| `fus_NumErrorCodes` | `0x1b` | `0x19` | 값 변경 |
| `fus_conflicting_inputs` | `0x16` | `0x16` | 주석 변경 |
| `fus_safety_relay_open` | `0x19` | `0x18` | 값 변경 |

### FusionDebugMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `fusdebug_Reserved18` | `0x2c` |  | Origin_36_merge에만 있음 |
| `fusdebug_drive_info_comms` | `0x10` |  | Origin_36_merge에만 있음 |
| `fusdebug_huge_sensor_update` | `6` |  | Origin_36_merge에만 있음 |
| `fusdebug_odometry_Null` |  | `6` | OhmioLibraries_BK에만 있음 |
| `fusdebug_rtk_Front_Null` |  | `7` | OhmioLibraries_BK에만 있음 |
| `fusdebug_rtk_Rear_Null` |  | `8` | OhmioLibraries_BK에만 있음 |
| `fusdebug_w_huge_sensor_update` |  | `0x31` | OhmioLibraries_BK에만 있음 |
| `fusdebug_NumErrorCodes` | `0x31` | `0x32` | 값 변경 |
| `fusdebug_Reserved` | `7` | `0x10` | 값 변경 |
| `fusdebug_Reserved10` | `0x18` | `0x19` | 값 변경 |
| `fusdebug_Reserved11` | `0x19` | `0x1a` | 값 변경 |
| `fusdebug_Reserved12` | `0x1a` | `0x1b` | 값 변경 |
| `fusdebug_Reserved13` | `0x1b` | `0x1c` | 값 변경 |
| `fusdebug_Reserved14` | `0x1c` | `0x1d` | 값 변경 |
| `fusdebug_Reserved15` | `0x1d` | `0x1e` | 값 변경 |
| `fusdebug_Reserved16` | `0x1e` | `0x1f` | 값 변경 |
| `fusdebug_Reserved17` | `0x1f` | `0x2c` | 값 변경 |
| `fusdebug_Reserved2` | `8` | `0x11` | 값 변경 |
| `fusdebug_Reserved3` | `0x11` | `0x12` | 값 변경 |
| `fusdebug_Reserved4` | `0x12` | `0x13` | 값 변경 |
| `fusdebug_Reserved5` | `0x13` | `0x14` | 값 변경 |
| `fusdebug_Reserved6` | `0x14` | `0x15` | 값 변경 |
| `fusdebug_Reserved7` | `0x15` | `0x16` | 값 변경 |
| `fusdebug_Reserved8` | `0x16` | `0x17` | 값 변경 |
| `fusdebug_Reserved9` | `0x17` | `0x18` | 값 변경 |

### FusionErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Fusion_Drv_Info_Comms` | `0x19` |  | Origin_36_merge에만 있음 |
| `Fusion_Huge_Sensor_Update` | `0x18` |  | Origin_36_merge에만 있음 |
| `Fusion_NumErrorCodes` | `0x1a` | `0x18` | 값 변경 |

### LocalisationErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Loc_Dri_Info_Comms` | `0xc` |  | Origin_36_merge에만 있음 |
| `Loc_Reserved16` |  | `0x1b` | OhmioLibraries_BK에만 있음 |
| `Loc_Reserved` | `0xd` | `0xc` | 값 변경 |
| `Loc_Reserved10` | `0x16` | `0x15` | 값 변경 |
| `Loc_Reserved11` | `0x17` | `0x16` | 값 변경 |
| `Loc_Reserved12` | `0x18` | `0x17` | 값 변경 |
| `Loc_Reserved13` | `0x19` | `0x18` | 값 변경 |
| `Loc_Reserved14` | `0x1a` | `0x19` | 값 변경 |
| `Loc_Reserved15` | `0x1b` | `0x1a` | 값 변경 |
| `Loc_Reserved2` | `0xe` | `0xd` | 값 변경 |
| `Loc_Reserved3` | `0xf` | `0xe` | 값 변경 |
| `Loc_Reserved4` | `0x10` | `0xf` | 값 변경 |
| `Loc_Reserved5` | `0x11` | `0x10` | 값 변경 |
| `Loc_Reserved6` | `0x12` | `0x11` | 값 변경 |
| `Loc_Reserved7` | `0x13` | `0x12` | 값 변경 |
| `Loc_Reserved8` | `0x14` | `0x13` | 값 변경 |
| `Loc_Reserved9` | `0x15` | `0x14` | 값 변경 |

### ManagementErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `mgt_Drv_Info_Comms` | `2` |  | Origin_36_merge에만 있음 |
| `mgt_shared_Drv` | `3` |  | Origin_36_merge에만 있음 |
| `mgt_NumErrorCodes` | `4` | `2` | 값 변경 |

### ManualErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Man_Dri_Info_Coms` | `4` |  | Origin_36_merge에만 있음 |
| `Man_Duplicated_Joystick_Board` | `5` |  | Origin_36_merge에만 있음 |
| `Man_NumErrorCodes` | `6` | `4` | 값 변경 |

### ObstaclePCErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `Obstacle_drv_info_comms` | `0x18` |  | Origin_36_merge에만 있음 |
| `Obstacle_NumErrorCodes` | `0x19` | `0x18` | 값 변경 |

### SignalMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `signal_Drv_Info_Comms` | `2` |  | Origin_36_merge에만 있음 |
| `signal_NumErrorCodes` | `3` | `2` | 값 변경 |

### StartupMsgErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `startup_Drv_Info_Comms` | `5` |  | Origin_36_merge에만 있음 |
| `startup_lotte_Bms_Err` | `6` |  | Origin_36_merge에만 있음 |
| `startup_NumErrorCodes` | `7` | `5` | 값 변경 |

### WheelSpeedErrorCode

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `wheel_drv_info_comms` | `2` |  | Origin_36_merge에만 있음 |
| `wheel_NumErrorCodes` | `3` | `2` | 값 변경 |

## Function 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 function | 14 | `DriveInfo500kWpMsg_FromCan`, `DriveInfo500kWpMsg_ToCan`, `EmulatorHeadingMsg_FromCan`, `EmulatorHeadingMsg_ToCan`, `ExtObsLocMsg_FromCan`, `ExtObsLocMsg_ToCan`, `ExtObsSpeedMsg_FromCan`, `ExtObsSpeedMsg_ToCan`, `IMUStatus_FromCan`, `IMUStatus_ToCan`, `LatitudeMsg_FromCan`, `LatitudeMsg_ToCan`, `ObstacleDangerZoneStopMsg_FromCan`, `ObstacleDangerZoneStopMsg_ToCan` |
| OhmioLibraries_BK에만 있는 function | 30 | `CombinedHeightMsg_FromCan`, `CombinedHeightMsg_ToCan`, `CompassMsg_FromCan`, `CompassMsg_ToCan`, `DeviationReqMsg_FromCan`, `DeviationReqMsg_ToCan`, `DriveInfoMsg_FromCan`, `DriveInfoMsg_ToCan`, `DynamicTrackValidationMsg_FromCan`, `DynamicTrackValidationMsg_ToCan`, `FusionFrontLongitude_FromCan`, `FusionFrontLongitude_ToCan`, `FusionLatitudeMsg_FromCan`, `FusionLatitudeMsg_ToCan`, `GPSLatitudeMsg_FromCan`, `GPSLatitudeMsg_ToCan`, `HeadingMsg_FromCan`, `HeadingMsg_ToCan`, `HeightMsg_FromCan`, `HeightMsg_ToCan`, `ObstacleDetectionLiDARMsg_FromCan`, `ObstacleDetectionLiDARMsg_ToCan`, `StopReqMsg_FromCan`, `StopReqMsg_ToCan`, `UWBLatitudeMsg_FromCan`, `UWBLatitudeMsg_ToCan`, `UWBLongitudeMsg_FromCan`, `UWBLongitudeMsg_ToCan`, `UltraSoundMsg_FromCan`, `UltraSoundMsg_ToCan` |
| 공통 function 형태/구현 차이 | 116 | `BMSStatusStdMsg_FromCan`, `BMSStatusStdMsg_ToCan`, `BatteryStatusMsg_FromCan`, `BatteryStatusMsg_ToCan`, `ConfigRespMsg_FromCan`, `ConfigRespMsg_ToCan`, `DriveInfoLongWpMsg_FromCan`, `DriveInfoLongWpMsg_ToCan`, `EHBPowerMsg_FromCan`, `EHBPowerMsg_ToCan`, `EHBReqMsg_FromCan`, `EHBReqMsg_ToCan`, `EHBT060PowerMsg_FromCan`, `EHBT060PowerMsg_ToCan`, `EPBStatusMsg_FromCan`, `EPBStatusMsg_ToCan`, `ErrorEHBT060_FromCan`, `ErrorEHBT060_ToCan`, `ErrorSteering_FromCan`, `ErrorSteering_ToCan`, `FusionAcceMsg_FromCan`, `FusionAcceMsg_ToCan`, `FusionBiasOutlierMsg_FromCan`, `FusionBiasOutlierMsg_ToCan`, `FusionFrontLatitude_FromCan`, `FusionFrontLatitude_ToCan`, `FusionHeight_FromCan`, `FusionHeight_ToCan`, `FusionInfoMsg_FromCan`, `FusionInfoMsg_ToCan`, `FusionRearLatitude_FromCan`, `FusionRearLatitude_ToCan`, `FusionRearLongitude_FromCan`, `FusionRearLongitude_ToCan`, `IMUAcc_FromCan`, `IMUAcc_ToCan`, `IMUGyr_FromCan`, `IMUGyr_ToCan`, `IMUMag_FromCan`, `IMUMag_ToCan`, `IMURot_FromCan`, `IMURot_ToCan`, `InterVehicleCommsMsg_FromCan`, `InterVehicleCommsMsg_ToCan`, `LidarLatitudeUndelayed_FromCan`, `LidarLatitudeUndelayed_ToCan`, `LidarLongitudeUndelayed_FromCan`, `LidarLongitudeUndelayed_ToCan`, `LidarSpeed_FromCan`, `LidarSpeed_ToCan`, `LongitudeMsg_FromCan`, `LongitudeMsg_ToCan`, `ManualDriveMsg_FromCan`, `ManualDriveMsg_ToCan`, `Motor3Status2_FromCan`, `Motor3Status2_ToCan`, `Motor3Status5_FromCan`, `Motor3Status5_ToCan`, `Motor3Status6_FromCan`, `Motor3Status6_ToCan` 외 56개 |

### 공통 function 차이 상세

| Function | Origin_36_merge | OhmioLibraries_BK | 차이 |
| --- | --- | --- | --- |
| `BMSStatusStdMsg_FromCan` | declared; `void BMSStatusStdMsg_FromCan(BMSStatusStdMsg_t * msg)` | static defined; `void BMSStatusStdMsg_FromCan(BMSStatusStdMsg_t * msg)` | static, defined |
| `BMSStatusStdMsg_ToCan` | declared; `void BMSStatusStdMsg_ToCan(BMSStatusStdMsg_t * msg)` | static defined; `void BMSStatusStdMsg_ToCan(BMSStatusStdMsg_t * msg)` | static, defined |
| `BatteryStatusMsg_FromCan` | declared; `void BatteryStatusMsg_FromCan(BatteryStatusMsg_t * msg)` | static defined; `void BatteryStatusMsg_FromCan(BatteryStatusMsg_t * msg)` | static, defined |
| `BatteryStatusMsg_ToCan` | declared; `void BatteryStatusMsg_ToCan(BatteryStatusMsg_t * msg)` | static defined; `void BatteryStatusMsg_ToCan(BatteryStatusMsg_t * msg)` | static, defined |
| `ConfigRespMsg_FromCan` | declared; `void ConfigRespMsg_FromCan(ConfigRespMsg_t * msg)` | static defined; `void ConfigRespMsg_FromCan(ConfigRespMsg_t * msg)` | static, defined |
| `ConfigRespMsg_ToCan` | declared; `void ConfigRespMsg_ToCan(ConfigRespMsg_t * msg)` | static defined; `void ConfigRespMsg_ToCan(ConfigRespMsg_t * msg)` | static, defined |
| `DriveInfoLongWpMsg_FromCan` | declared; `void DriveInfoLongWpMsg_FromCan(DriveInfoLongWpMsg_t * msg)` | static defined; `void DriveInfoLongWpMsg_FromCan(DriveInfoLongWpMsg_t * msg)` | static, defined |
| `DriveInfoLongWpMsg_ToCan` | declared; `void DriveInfoLongWpMsg_ToCan(DriveInfoLongWpMsg_t * msg)` | static defined; `void DriveInfoLongWpMsg_ToCan(DriveInfoLongWpMsg_t * msg)` | static, defined |
| `EHBPowerMsg_FromCan` | declared; `void EHBPowerMsg_FromCan(EHBPowerMsg_t * msg)` | static defined; `void EHBPowerMsg_FromCan(EHBPowerMsg_t * msg)` | static, defined |
| `EHBPowerMsg_ToCan` | declared; `void EHBPowerMsg_ToCan(EHBPowerMsg_t * msg)` | static defined; `void EHBPowerMsg_ToCan(EHBPowerMsg_t * msg)` | static, defined |
| `EHBReqMsg_FromCan` | declared; `void EHBReqMsg_FromCan(EHBReqMsg_t * msg)` | static defined; `void EHBReqMsg_FromCan(EHBReqMsg_t * msg)` | static, defined |
| `EHBReqMsg_ToCan` | declared; `void EHBReqMsg_ToCan(EHBReqMsg_t * msg)` | static defined; `void EHBReqMsg_ToCan(EHBReqMsg_t * msg)` | static, defined |
| `EHBT060PowerMsg_FromCan` | declared; `void EHBT060PowerMsg_FromCan(EHBT060PowerMsg_t * msg)` | static defined; `void EHBT060PowerMsg_FromCan(EHBT060PowerMsg_t * msg)` | static, defined |
| `EHBT060PowerMsg_ToCan` | declared; `void EHBT060PowerMsg_ToCan(EHBT060PowerMsg_t * msg)` | static defined; `void EHBT060PowerMsg_ToCan(EHBT060PowerMsg_t * msg)` | static, defined |
| `EPBStatusMsg_FromCan` | declared; `void EPBStatusMsg_FromCan(EPBStatusMsg_t * msg)` | static defined; `void EPBStatusMsg_FromCan(EPBStatusMsg_t * msg)` | static, defined |
| `EPBStatusMsg_ToCan` | declared; `void EPBStatusMsg_ToCan(EPBStatusMsg_t * msg)` | static defined; `void EPBStatusMsg_ToCan(EPBStatusMsg_t * msg)` | static, defined |
| `ErrorEHBT060_FromCan` | declared; `void ErrorEHBT060_FromCan(ErrorEHBT060_t * msg)` | static defined; `void ErrorEHBT060_FromCan(ErrorEHBT060_t * msg)` | static, defined |
| `ErrorEHBT060_ToCan` | declared; `void ErrorEHBT060_ToCan(ErrorEHBT060_t * msg)` | static defined; `void ErrorEHBT060_ToCan(ErrorEHBT060_t * msg)` | static, defined |
| `ErrorSteering_FromCan` | declared; `void ErrorSteering_FromCan(ErrorSteering_t * msg)` | static defined; `void ErrorSteering_FromCan(ErrorSteering_t * msg)` | static, defined |
| `ErrorSteering_ToCan` | declared; `void ErrorSteering_ToCan(ErrorSteering_t * msg)` | static defined; `void ErrorSteering_ToCan(ErrorSteering_t * msg)` | static, defined |
| `FusionAcceMsg_FromCan` | declared; `void FusionAcceMsg_FromCan(FusionAcceMsg_t * msg)` | static defined; `void FusionAcceMsg_FromCan(FusionAcceMsg_t * msg)` | static, defined |
| `FusionAcceMsg_ToCan` | declared; `void FusionAcceMsg_ToCan(FusionAcceMsg_t * msg)` | static defined; `void FusionAcceMsg_ToCan(FusionAcceMsg_t * msg)` | static, defined |
| `FusionBiasOutlierMsg_FromCan` | declared; `void FusionBiasOutlierMsg_FromCan(FusionBiasOutlierMsg_t * msg)` | static defined; `void FusionBiasOutlierMsg_FromCan(FusionBiasOutlierMsg_t * msg)` | static, defined |
| `FusionBiasOutlierMsg_ToCan` | declared; `void FusionBiasOutlierMsg_ToCan(FusionBiasOutlierMsg_t * msg)` | static defined; `void FusionBiasOutlierMsg_ToCan(FusionBiasOutlierMsg_t * msg)` | static, defined |
| `FusionFrontLatitude_FromCan` | declared; `void FusionFrontLatitude_FromCan(FusionFrontLatitude_t * msg)` | static defined; `void FusionFrontLatitude_FromCan(FusionFrontLatitude_t * msg)` | static, defined |
| `FusionFrontLatitude_ToCan` | declared; `void FusionFrontLatitude_ToCan(FusionFrontLatitude_t * msg)` | static defined; `void FusionFrontLatitude_ToCan(FusionFrontLatitude_t * msg)` | static, defined |
| `FusionHeight_FromCan` | declared; `void FusionHeight_FromCan(FusionHeight_t * msg)` | static defined; `void FusionHeight_FromCan(FusionHeight_t * msg)` | static, defined |
| `FusionHeight_ToCan` | declared; `void FusionHeight_ToCan(FusionHeight_t * msg)` | static defined; `void FusionHeight_ToCan(FusionHeight_t * msg)` | static, defined |
| `FusionInfoMsg_FromCan` | declared; `void FusionInfoMsg_FromCan(FusionInfoMsg_t * msg)` | static defined; `void FusionInfoMsg_FromCan(FusionInfoMsg_t * msg)` | static, defined |
| `FusionInfoMsg_ToCan` | declared; `void FusionInfoMsg_ToCan(FusionInfoMsg_t * msg)` | static defined; `void FusionInfoMsg_ToCan(FusionInfoMsg_t * msg)` | static, defined |
| `FusionRearLatitude_FromCan` | declared; `void FusionRearLatitude_FromCan(FusionRearLatitude_t * msg)` | static defined; `void FusionRearLatitude_FromCan(FusionRearLatitude_t * msg)` | static, defined |
| `FusionRearLatitude_ToCan` | declared; `void FusionRearLatitude_ToCan(FusionRearLatitude_t * msg)` | static defined; `void FusionRearLatitude_ToCan(FusionRearLatitude_t * msg)` | static, defined |
| `FusionRearLongitude_FromCan` | declared; `void FusionRearLongitude_FromCan(FusionRearLongitude_t * msg)` | static defined; `void FusionRearLongitude_FromCan(FusionRearLongitude_t * msg)` | static, defined |
| `FusionRearLongitude_ToCan` | declared; `void FusionRearLongitude_ToCan(FusionRearLongitude_t * msg)` | static defined; `void FusionRearLongitude_ToCan(FusionRearLongitude_t * msg)` | static, defined |
| `IMUAcc_FromCan` | declared; `void IMUAcc_FromCan(IMUAcc_t * msg)` | static defined; `void IMUAcc_FromCan(IMUAcc_t * msg)` | static, defined |
| `IMUAcc_ToCan` | declared; `void IMUAcc_ToCan(IMUAcc_t * msg)` | static defined; `void IMUAcc_ToCan(IMUAcc_t * msg)` | static, defined |
| `IMUGyr_FromCan` | declared; `void IMUGyr_FromCan(IMUGyr_t * msg)` | static defined; `void IMUGyr_FromCan(IMUGyr_t * msg)` | static, defined |
| `IMUGyr_ToCan` | declared; `void IMUGyr_ToCan(IMUGyr_t * msg)` | static defined; `void IMUGyr_ToCan(IMUGyr_t * msg)` | static, defined |
| `IMUMag_FromCan` | declared; `void IMUMag_FromCan(IMUMag_t * msg)` | static defined; `void IMUMag_FromCan(IMUMag_t * msg)` | static, defined |
| `IMUMag_ToCan` | declared; `void IMUMag_ToCan(IMUMag_t * msg)` | static defined; `void IMUMag_ToCan(IMUMag_t * msg)` | static, defined |
| `IMURot_FromCan` | declared; `void IMURot_FromCan(IMURot_t * msg)` | static defined; `void IMURot_FromCan(IMURot_t * msg)` | static, defined |
| `IMURot_ToCan` | declared; `void IMURot_ToCan(IMURot_t * msg)` | static defined; `void IMURot_ToCan(IMURot_t * msg)` | static, defined |
| `InterVehicleCommsMsg_FromCan` | declared; `void InterVehicleCommsMsg_FromCan(InterVehicleCommsMsg_t * msg)` | static defined; `void InterVehicleCommsMsg_FromCan(InterVehicleCommsMsg_t * msg)` | static, defined |
| `InterVehicleCommsMsg_ToCan` | declared; `void InterVehicleCommsMsg_ToCan(InterVehicleCommsMsg_t * msg)` | static defined; `void InterVehicleCommsMsg_ToCan(InterVehicleCommsMsg_t * msg)` | static, defined |
| `LidarLatitudeUndelayed_FromCan` | declared; `void LidarLatitudeUndelayed_FromCan(LidarLatitudeUndelayed_t * msg)` | static defined; `void LidarLatitudeUndelayed_FromCan(LidarLatitudeUndelayed_t * msg)` | static, defined |
| `LidarLatitudeUndelayed_ToCan` | declared; `void LidarLatitudeUndelayed_ToCan(LidarLatitudeUndelayed_t * msg)` | static defined; `void LidarLatitudeUndelayed_ToCan(LidarLatitudeUndelayed_t * msg)` | static, defined |
| `LidarLongitudeUndelayed_FromCan` | declared; `void LidarLongitudeUndelayed_FromCan(LidarLongitudeUndelayed_t * msg)` | static defined; `void LidarLongitudeUndelayed_FromCan(LidarLongitudeUndelayed_t * msg)` | static, defined |
| `LidarLongitudeUndelayed_ToCan` | declared; `void LidarLongitudeUndelayed_ToCan(LidarLongitudeUndelayed_t * msg)` | static defined; `void LidarLongitudeUndelayed_ToCan(LidarLongitudeUndelayed_t * msg)` | static, defined |
| `LidarSpeed_FromCan` | declared; `void LidarSpeed_FromCan(LidarSpeed_t * msg)` | static defined; `void LidarSpeed_FromCan(LidarSpeed_t * msg)` | static, defined |
| `LidarSpeed_ToCan` | declared; `void LidarSpeed_ToCan(LidarSpeed_t * msg)` | static defined; `void LidarSpeed_ToCan(LidarSpeed_t * msg)` | static, defined |
| `LongitudeMsg_FromCan` | declared; `void LongitudeMsg_FromCan(LongitudeMsg_t * msg)` | static defined; `void LongitudeMsg_FromCan(LongitudeMsg_t * msg)` | static, defined |
| `LongitudeMsg_ToCan` | declared; `void LongitudeMsg_ToCan(LongitudeMsg_t * msg)` | static defined; `void LongitudeMsg_ToCan(LongitudeMsg_t * msg)` | static, defined |
| `ManualDriveMsg_FromCan` | declared; `void ManualDriveMsg_FromCan(ManualDriveMsg_t * msg)` | static defined; `void ManualDriveMsg_FromCan(ManualDriveMsg_t * msg)` | static, defined |
| `ManualDriveMsg_ToCan` | declared; `void ManualDriveMsg_ToCan(ManualDriveMsg_t * msg)` | static defined; `void ManualDriveMsg_ToCan(ManualDriveMsg_t * msg)` | static, defined |
| `Motor3Status2_FromCan` | declared; `void Motor3Status2_FromCan(Motor3Status2_t * msg)` | static defined; `void Motor3Status2_FromCan(Motor3Status2_t * msg)` | static, defined |
| `Motor3Status2_ToCan` | declared; `void Motor3Status2_ToCan(Motor3Status2_t * msg)` | static defined; `void Motor3Status2_ToCan(Motor3Status2_t * msg)` | static, defined |
| `Motor3Status5_FromCan` | declared; `void Motor3Status5_FromCan(Motor3Status5_t * msg)` | static defined; `void Motor3Status5_FromCan(Motor3Status5_t * msg)` | static, defined |
| `Motor3Status5_ToCan` | declared; `void Motor3Status5_ToCan(Motor3Status5_t * msg)` | static defined; `void Motor3Status5_ToCan(Motor3Status5_t * msg)` | static, defined |
| `Motor3Status6_FromCan` | declared; `void Motor3Status6_FromCan(Motor3Status6_t * msg)` | static defined; `void Motor3Status6_FromCan(Motor3Status6_t * msg)` | static, defined |
| `Motor3Status6_ToCan` | declared; `void Motor3Status6_ToCan(Motor3Status6_t * msg)` | static defined; `void Motor3Status6_ToCan(Motor3Status6_t * msg)` | static, defined |
| `MotorReqMsg_FromCan` | declared; `void MotorReqMsg_FromCan(MotorReqMsg_t * msg)` | static defined; `void MotorReqMsg_FromCan(MotorReqMsg_t * msg)` | static, defined |
| `MotorReqMsg_ToCan` | declared; `void MotorReqMsg_ToCan(MotorReqMsg_t * msg)` | static defined; `void MotorReqMsg_ToCan(MotorReqMsg_t * msg)` | static, defined |
| `MotorStatus_FromCan` | declared; `void MotorStatus_FromCan(MotorStatus_t * msg)` | static defined; `void MotorStatus_FromCan(MotorStatus_t * msg)` | static, defined |
| `MotorStatus_ToCan` | declared; `void MotorStatus_ToCan(MotorStatus_t * msg)` | static defined; `void MotorStatus_ToCan(MotorStatus_t * msg)` | static, defined |
| `ObsHeadingMsg_FromCan` | declared; `void ObsHeadingMsg_FromCan(ObsHeadingMsg_t * msg)` | static defined; `void ObsHeadingMsg_FromCan(ObsHeadingMsg_t * msg)` | static, defined |
| `ObsHeadingMsg_ToCan` | declared; `void ObsHeadingMsg_ToCan(ObsHeadingMsg_t * msg)` | static defined; `void ObsHeadingMsg_ToCan(ObsHeadingMsg_t * msg)` | static, defined |
| `ObsLatitudeMsg_FromCan` | declared; `void ObsLatitudeMsg_FromCan(ObsLatitudeMsg_t * msg)` | static defined; `void ObsLatitudeMsg_FromCan(ObsLatitudeMsg_t * msg)` | static, defined |
| `ObsLatitudeMsg_ToCan` | declared; `void ObsLatitudeMsg_ToCan(ObsLatitudeMsg_t * msg)` | static defined; `void ObsLatitudeMsg_ToCan(ObsLatitudeMsg_t * msg)` | static, defined |
| `ObsLongitudeMsg_FromCan` | declared; `void ObsLongitudeMsg_FromCan(ObsLongitudeMsg_t * msg)` | static defined; `void ObsLongitudeMsg_FromCan(ObsLongitudeMsg_t * msg)` | static, defined |
| `ObsLongitudeMsg_ToCan` | declared; `void ObsLongitudeMsg_ToCan(ObsLongitudeMsg_t * msg)` | static defined; `void ObsLongitudeMsg_ToCan(ObsLongitudeMsg_t * msg)` | static, defined |
| `ObsTrackOffsetMsg_FromCan` | declared; `void ObsTrackOffsetMsg_FromCan(ObsTrackOffsetMsg_t * msg)` | static defined; `void ObsTrackOffsetMsg_FromCan(ObsTrackOffsetMsg_t * msg)` | static, defined |
| `ObsTrackOffsetMsg_ToCan` | declared; `void ObsTrackOffsetMsg_ToCan(ObsTrackOffsetMsg_t * msg)` | static defined; `void ObsTrackOffsetMsg_ToCan(ObsTrackOffsetMsg_t * msg)` | static, defined |
| `ObstacleDangerZoneMsg_FromCan` | declared; `void ObstacleDangerZoneMsg_FromCan(ObstacleDangerZoneMsg_t * msg)` | static defined; `void ObstacleDangerZoneMsg_FromCan(ObstacleDangerZoneMsg_t * msg)` | static, defined |
| `ObstacleDangerZoneMsg_ToCan` | declared; `void ObstacleDangerZoneMsg_ToCan(ObstacleDangerZoneMsg_t * msg)` | static defined; `void ObstacleDangerZoneMsg_ToCan(ObstacleDangerZoneMsg_t * msg)` | static, defined |
| `ObstacleEmergency_FromCan` | declared; `void ObstacleEmergency_FromCan(ObstacleEmergency_t * msg)` | static defined; `void ObstacleEmergency_FromCan(ObstacleEmergency_t * msg)` | static, defined |
| `ObstacleEmergency_ToCan` | declared; `void ObstacleEmergency_ToCan(ObstacleEmergency_t * msg)` | static defined; `void ObstacleEmergency_ToCan(ObstacleEmergency_t * msg)` | static, defined |
| `ObstacleTrackDistanceMsg_FromCan` | declared; `void ObstacleTrackDistanceMsg_FromCan(ObstacleTrackDistanceMsg_t * msg)` | static defined; `void ObstacleTrackDistanceMsg_FromCan(ObstacleTrackDistanceMsg_t * msg)` | static, defined |
| `ObstacleTrackDistanceMsg_ToCan` | declared; `void ObstacleTrackDistanceMsg_ToCan(ObstacleTrackDistanceMsg_t * msg)` | static defined; `void ObstacleTrackDistanceMsg_ToCan(ObstacleTrackDistanceMsg_t * msg)` | static, defined |
| `OdometerMsg_FromCan` | declared; `void OdometerMsg_FromCan(OdometerMsg_t * msg)` | static defined; `void OdometerMsg_FromCan(OdometerMsg_t * msg)` | static, defined |
| `OdometerMsg_ToCan` | declared; `void OdometerMsg_ToCan(OdometerMsg_t * msg)` | static defined; `void OdometerMsg_ToCan(OdometerMsg_t * msg)` | static, defined |
| `OdometryParameters_FromCan` | declared; `void OdometryParameters_FromCan(OdometryParameters_t * msg)` | static defined; `void OdometryParameters_FromCan(OdometryParameters_t * msg)` | static, defined |
| `OdometryParameters_ToCan` | declared; `void OdometryParameters_ToCan(OdometryParameters_t * msg)` | static defined; `void OdometryParameters_ToCan(OdometryParameters_t * msg)` | static, defined |
| `ParameterConfMsg_FromCan` | declared; `void ParameterConfMsg_FromCan(ParameterConfMsg_t * msg)` | static defined; `void ParameterConfMsg_FromCan(ParameterConfMsg_t * msg)` | static, defined |
| `ParameterConfMsg_ToCan` | declared; `void ParameterConfMsg_ToCan(ParameterConfMsg_t * msg)` | static defined; `void ParameterConfMsg_ToCan(ParameterConfMsg_t * msg)` | static, defined |
| `ParameterConfSignMsg_FromCan` | declared; `void ParameterConfSignMsg_FromCan(ParameterConfSignMsg_t * msg)` | static defined; `void ParameterConfSignMsg_FromCan(ParameterConfSignMsg_t * msg)` | static, defined |
| `ParameterConfSignMsg_ToCan` | declared; `void ParameterConfSignMsg_ToCan(ParameterConfSignMsg_t * msg)` | static defined; `void ParameterConfSignMsg_ToCan(ParameterConfSignMsg_t * msg)` | static, defined |
| `PlatStartMsg_FromCan` | declared; `void PlatStartMsg_FromCan(PlatStartMsg_t * msg)` | static defined; `void PlatStartMsg_FromCan(PlatStartMsg_t * msg)` | static, defined |
| `PlatStartMsg_ToCan` | declared; `void PlatStartMsg_ToCan(PlatStartMsg_t * msg)` | static defined; `void PlatStartMsg_ToCan(PlatStartMsg_t * msg)` | static, defined |
| `PlatoonSimMsg_FromCan` | declared; `void PlatoonSimMsg_FromCan(PlatoonSimMsg_t * msg)` | static defined; `void PlatoonSimMsg_FromCan(PlatoonSimMsg_t * msg)` | static, defined |
| `PlatoonSimMsg_ToCan` | declared; `void PlatoonSimMsg_ToCan(PlatoonSimMsg_t * msg)` | static defined; `void PlatoonSimMsg_ToCan(PlatoonSimMsg_t * msg)` | static, defined |
| `Speed2TorqueReqMsg_FromCan` | declared; `void Speed2TorqueReqMsg_FromCan(Speed2TorqueReqMsg_t * msg)` | static defined; `void Speed2TorqueReqMsg_FromCan(Speed2TorqueReqMsg_t * msg)` | static, defined |
| `Speed2TorqueReqMsg_ToCan` | declared; `void Speed2TorqueReqMsg_ToCan(Speed2TorqueReqMsg_t * msg)` | static defined; `void Speed2TorqueReqMsg_ToCan(Speed2TorqueReqMsg_t * msg)` | static, defined |
| `Speed2TorqueRespMsg_FromCan` | declared; `void Speed2TorqueRespMsg_FromCan(Speed2TorqueRespMsg_t * msg)` | static defined; `void Speed2TorqueRespMsg_FromCan(Speed2TorqueRespMsg_t * msg)` | static, defined |
| `Speed2TorqueRespMsg_ToCan` | declared; `void Speed2TorqueRespMsg_ToCan(Speed2TorqueRespMsg_t * msg)` | static defined; `void Speed2TorqueRespMsg_ToCan(Speed2TorqueRespMsg_t * msg)` | static, defined |
| `SteerCalibrationMsg_FromCan` | declared; `void SteerCalibrationMsg_FromCan(SteerCalibrationMsg_t * msg)` | static defined; `void SteerCalibrationMsg_FromCan(SteerCalibrationMsg_t * msg)` | static, defined |
| `SteerCalibrationMsg_ToCan` | declared; `void SteerCalibrationMsg_ToCan(SteerCalibrationMsg_t * msg)` | static defined; `void SteerCalibrationMsg_ToCan(SteerCalibrationMsg_t * msg)` | static, defined |
| `SteerMsg_FromCan` | declared; `void SteerMsg_FromCan(SteerMsg_t * msg)` | static defined; `void SteerMsg_FromCan(SteerMsg_t * msg)` | static, defined |
| `SteerMsg_ToCan` | declared; `void SteerMsg_ToCan(SteerMsg_t * msg)` | static defined; `void SteerMsg_ToCan(SteerMsg_t * msg)` | static, defined |
| `SteeringReqMsg_FromCan` | declared; `void SteeringReqMsg_FromCan(SteeringReqMsg_t * msg)` | static defined; `void SteeringReqMsg_FromCan(SteeringReqMsg_t * msg)` | static, defined |
| `SteeringReqMsg_ToCan` | declared; `void SteeringReqMsg_ToCan(SteeringReqMsg_t * msg)` | static defined; `void SteeringReqMsg_ToCan(SteeringReqMsg_t * msg)` | static, defined |
| `SteeringRespMsg_FromCan` | declared; `void SteeringRespMsg_FromCan(SteeringRespMsg_t * msg)` | static defined; `void SteeringRespMsg_FromCan(SteeringRespMsg_t * msg)` | static, defined |
| `SteeringRespMsg_ToCan` | declared; `void SteeringRespMsg_ToCan(SteeringRespMsg_t * msg)` | static defined; `void SteeringRespMsg_ToCan(SteeringRespMsg_t * msg)` | static, defined |
| `SteeringStatusMsg_FromCan` | declared; `void SteeringStatusMsg_FromCan(SteeringStatusMsg_t * msg)` | static defined; `void SteeringStatusMsg_FromCan(SteeringStatusMsg_t * msg)` | static, defined |
| `SteeringStatusMsg_ToCan` | declared; `void SteeringStatusMsg_ToCan(SteeringStatusMsg_t * msg)` | static defined; `void SteeringStatusMsg_ToCan(SteeringStatusMsg_t * msg)` | static, defined |
| `TrafficLightMsg_FromCan` | declared; `void TrafficLightMsg_FromCan(TrafficLightMsg_t * msg)` | static defined; `void TrafficLightMsg_FromCan(TrafficLightMsg_t * msg)` | static, defined |
| `TrafficLightMsg_ToCan` | declared; `void TrafficLightMsg_ToCan(TrafficLightMsg_t * msg)` | static defined; `void TrafficLightMsg_ToCan(TrafficLightMsg_t * msg)` | static, defined |
| `UBXPart1Msg_FromCan` | declared; `void UBXPart1Msg_FromCan(UBXPart1Msg_t * msg)` | static defined; `void UBXPart1Msg_FromCan(UBXPart1Msg_t * msg)` | static, defined |
| `UBXPart1Msg_ToCan` | declared; `void UBXPart1Msg_ToCan(UBXPart1Msg_t * msg)` | static defined; `void UBXPart1Msg_ToCan(UBXPart1Msg_t * msg)` | static, defined |
| `UBXPart2Msg_FromCan` | declared; `void UBXPart2Msg_FromCan(UBXPart2Msg_t * msg)` | static defined; `void UBXPart2Msg_FromCan(UBXPart2Msg_t * msg)` | static, defined |
| `UBXPart2Msg_ToCan` | declared; `void UBXPart2Msg_ToCan(UBXPart2Msg_t * msg)` | static defined; `void UBXPart2Msg_ToCan(UBXPart2Msg_t * msg)` | static, defined |
| `VehicleInfoMsg_FromCan` | declared; `void VehicleInfoMsg_FromCan(VehicleInfoMsg_t * msg)` | static defined; `void VehicleInfoMsg_FromCan(VehicleInfoMsg_t * msg)` | static, defined |
| `VehicleInfoMsg_ToCan` | declared; `void VehicleInfoMsg_ToCan(VehicleInfoMsg_t * msg)` | static defined; `void VehicleInfoMsg_ToCan(VehicleInfoMsg_t * msg)` | static, defined |
| `WheelSpeedEvents_FromCan` | declared; `void WheelSpeedEvents_FromCan(WheelSpeedEvents_t * msg)` | static defined; `void WheelSpeedEvents_FromCan(WheelSpeedEvents_t * msg)` | static, defined |
| `WheelSpeedEvents_ToCan` | declared; `void WheelSpeedEvents_ToCan(WheelSpeedEvents_t * msg)` | static defined; `void WheelSpeedEvents_ToCan(WheelSpeedEvents_t * msg)` | static, defined |
| `WheelSpeedMsg_FromCan` | declared; `void WheelSpeedMsg_FromCan(WheelSpeedMsg_t * msg)` | static defined; `void WheelSpeedMsg_FromCan(WheelSpeedMsg_t * msg)` | static, defined |
| `WheelSpeedMsg_ToCan` | declared; `void WheelSpeedMsg_ToCan(WheelSpeedMsg_t * msg)` | static defined; `void WheelSpeedMsg_ToCan(WheelSpeedMsg_t * msg)` | static, defined |

