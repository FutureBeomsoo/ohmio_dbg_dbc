# dbc_CAN.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 3663 | 4788 |
| SHA256 | acde60291555 | e1d368cabda6 |
| Include | 3 | 6 |
| Define | 0 | 0 |
| Struct/Message | 146 | 152 |
| Enum | 28 | 25 |
| CAN_ID | 0 | 0 |
| Function | 130 | 146 |
| Unified diff | +1041 | -2166 |

## 전처리/Define 비교

| Include | 구분 | 비고 |
| --- | --- | --- |
| "ConversionHelper.h" | OhmioLibraries_BK에만 있음 |  |
| <assert.h> | OhmioLibraries_BK에만 있음 |  |
| <math.h> | OhmioLibraries_BK에만 있음 |  |

- define 차이 없음.

## Message/Struct 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 struct | `AnyExceptionMsg`, `AtmelTeleopError`, `ConnectWp`, `DriveInfo500kWpMsg`, `EmulatorHeadingMsg`, `ErrorNetwork`, `ErrorTeleOp`, `ExtObsLocMsg`, `ExtObsSpeedMsg`, `GpsPpsMsg`, `IMUStatus`, `LatitudeMsg`, `ObsoleteMsg`, `ObstacleDangerZoneStopMsg`, `ObstaclePcWarning` | 15 |
| OhmioLibraries_BK에만 있는 struct | `BrakeReqMsg`, `CombinedHeightMsg`, `CompassMsg`, `DeviationReqMsg`, `DriveInfoMsg`, `DynamicTrackValidationMsg`, `ErrorMotorAdaptor`, `ErrorTrans`, `FusionFrontLongitude`, `FusionLatitudeMsg`, `GPSLatitudeMsg`, `HeadingMsg`, `HeightMsg`, `LogIndMsg`, `ObstacleDetectionLiDARMsg`, `PrintASCIIMsg`, `StopReqMsg`, `UWBDistanceMsg`, `UWBLatitudeMsg`, `UWBLongitudeMsg`, `UltraSoundMsg` | 21 |
| 공통 struct의 signal layout 차이 | `AtmelLocalisaionError`, `AtmelResetMsg`, `DriveWarningMsg`, `EPBErrorMsg`, `ErrorAccessory`, `ErrorDriveExt`, `ErrorFootMsg`, `ErrorFusion`, `ErrorFusionDebugMsg`, `ErrorLocalisation`, `ErrorManual`, `ErrorObstaclePC`, `ErrorWheelSpeed`, `ExceptionMsg`, `FusError`, `FusionFlagsMsg`, `FusionHeight`, `IMUAcc`, `IMUGyr`, `IMUMag`, `IMURot`, `JoystickMsg`, `LidarSpeed`, `LongitudeMsg`, `ManagementError`, `ManualDriveMsg`, `ObstacleDangerZoneMsg`, `ObstacleEmergency`, `ObstacleTrackDistanceMsg`, `RemoteSignalMsg`, `ResetCauseMsg`, `SignalErrorMsg`, `StartupErrorMsg`, `StartupStatusMsg`, `SystemReqMsg`, `TrackAckMsg`, `TrackCtrlMsg`, `TrackDataMsg`, `WheelCountMsg` | 39 |

### 공통 struct signal layout 차이

| Struct | 차이 내용 |
| --- | --- |
| AtmelLocalisaionError | Origin_36_merge only: `AtlocGPS1InputError`, `AtlocGPS2InputError`<br>BK only: `AtlocGPSInputSearchError`, `AtlocUWBInputSearchError` |
| AtmelResetMsg | message comment/attribute 차이 |
| DriveWarningMsg | Origin_36_merge only: `DrvMcuVerIncompatible`<br>total bits 8 vs 7 |
| EPBErrorMsg | Origin_36_merge only: `EPBDrvInfoCommsError`<br>total bits 5 vs 4 |
| ErrorAccessory | Origin_36_merge only: `AccessoryDrvInfoComms`, `AccessoryIncorrectPCB`, `AccessoryNonUniqueID`, `AccessoryRelayOpen`<br>BK only: `code`<br>total bits 4 vs 64 |
| ErrorDriveExt | Origin_36_merge only: `DrvextEPB1CommsError`, `DrvextEPB2CommsError`, `DrvextMotorOverTemp`, `DrvextParameterOutOfRange`, `DrvextSpeedDeviationError`<br>total bits 8 vs 3 |
| ErrorFootMsg | Origin_36_merge only: `FootDrvInfoCommsError`<br>total bits 9 vs 8 |
| ErrorFusion | Origin_36_merge only: `FusionDrvInfoCommsError`, `FusionHugeSensorUpdate`<br>total bits 26 vs 24 |
| ErrorFusionDebugMsg | Origin_36_merge only: `drive_info_comms`, `huge_sensor_update`, `reserved2`<br>BK only: `odometryNull`, `rtkFrontNull`, `rtkRearNull`, `w_huge_sensor_update`<br>bit width changed: `reserved`, `reserved1`<br>total bits 49 vs 50 |
| ErrorLocalisation | Origin_36_merge only: `LocDriInfoCommsError`<br>bit width changed: `reserved` |
| ErrorManual | Origin_36_merge only: `DuplicatedJoystickBoard`, `ManDriInfoComsError`<br>total bits 6 vs 4 |
| ErrorObstaclePC | Origin_36_merge only: `Obstacle_drv_info_comms_error`<br>total bits 25 vs 24 |
| ErrorWheelSpeed | Origin_36_merge only: `wheel_drv_info_comms_error`<br>total bits 3 vs 2 |
| ExceptionMsg | bit width changed: `ex_addr`, `ex_code` |
| FusError | Origin_36_merge only: `fus_drv_info_comms_error`, `fus_huge_sensor_update`<br>total bits 27 vs 25 |
| FusionFlagsMsg | Origin_36_merge only: `drv_info_comms_error`, `huge_sensor_update`, `reserved3`, `reserved4`, `st_using_imu_heading`, `w_large_gnss_delay`, `w_large_lidar_delay`, `w_no_engine_state`<br>BK only: `reserved`, `st_front_gnss_no_data_can`, `st_rear_gnss_no_data_can`, `st_recent_gnss_available`, `w_huge_sensor_update`<br>bit width changed: `reserved1`, `reserved2`<br>total bits 56 vs 54 |
| FusionHeight | Origin_36_merge only: `compute_time`, `delay_gnss_front`, `delay_gnss_rear`<br>BK only: `reserved`<br>bit width changed: `height`<br>total bits 64 vs 32 |
| IMUAcc | message comment/attribute 차이 |
| IMUGyr | message comment/attribute 차이 |
| IMUMag | Origin_36_merge only: `reserved`<br>BK only: `status`, `unused`<br>bit width changed: `x`, `y`, `z` |
| IMURot | message comment/attribute 차이 |
| JoystickMsg | Origin_36_merge only: `id`, `reserved`<br>total bits 64 vs 52 |
| LidarSpeed | Origin_36_merge only: `delay`<br>total bits 62 vs 57 |
| LongitudeMsg | message comment/attribute 차이 |
| ManagementError | Origin_36_merge only: `ignoreDZ`, `limpMode`, `mcuVersionsOk`, `mgtDrvInfoCommsError`, `recording`, `sharedDriveError`<br>bit width changed: `reserved`<br>total bits 26 vs 18 |
| ManualDriveMsg | Origin_36_merge only: `id`<br>total bits 64 vs 56 |
| ObstacleDangerZoneMsg | Origin_36_merge only: `movingSideways`, `notMoving`<br>bit width changed: `reserved` |
| ObstacleEmergency | Origin_36_merge only: `obsErrorStop`<br>bit width changed: `reserved` |
| ObstacleTrackDistanceMsg | Origin_36_merge only: `BackDistance`, `ClearOnLeft`, `ClearOnRight`, `reserved`<br>total bits 64 vs 42 |
| RemoteSignalMsg | Origin_36_merge only: `overtake`<br>total bits 20 vs 19 |

- struct layout 차이 9개 추가 생략.

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 enum | `AccessoryErrorCode`, `NetworkErrorCode`, `ObstaclePcWarningErrorCode`, `TeleOpErrorCode` | 4 |
| OhmioLibraries_BK에만 있는 enum | `TransErrorCode` | 1 |
| 공통 enum entry 차이 | `AtmelLocalisaionErrorCode`, `DrvExtErrorCode`, `DrvWarningMsgErrorCode`, `EPBMsgErrorCode`, `FootMsgErrorCode`, `FusErrorCode`, `FusionDebugMsgErrorCode`, `FusionErrorCode`, `LocalisationErrorCode`, `ManagementErrorCode`, `ManualErrorCode`, `ObstaclePCErrorCode`, `SignalMsgErrorCode`, `StartupMsgErrorCode`, `WheelSpeedErrorCode` | 15 |

### 공통 enum entry 차이 상세

#### AtmelLocalisaionErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Atloc_GPS1_Input | 0 |  |
| Atloc_GPS2_Input | 1 |  |
| Atloc_GPS_Input_Search |  | 0 |
| Atloc_UWB_Input_Search |  | 1 |

#### DrvExtErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Drvext_EPB1_Comms | 6 |  |
| Drvext_EPB2_Comms | 7 |  |
| Drvext_Motor_Over_Temp | 4 |  |
| Drvext_Parameter_Out_Of_Range | 3 |  |
| Drvext_Speed_Deviation | 5 |  |
| Drvext_NumErrorCodes | 8 | 3 |

#### DrvWarningMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Drv_Mcu_Ver_Incompatible | 7 |  |
| Drv_NumWarningCodes | 8 | 7 |

#### EPBMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| EPB_Drv_Info_Comms | 4 |  |
| EPB_NumErrorCodes | 5 | 4 |

#### FootMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Foot_Drv_Info_Comms | 8 |  |
| Foot_NumErrorCodes | 9 | 8 |

#### FusErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| fus_drv_info_comms | 26 |  |
| fus_huge_sensor_update | 24 |  |
| fus_NumErrorCodes | 27 | 25 |
| fus_safety_relay_open | 25 | 24 |

#### FusionDebugMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| fusdebug_Reserved18 | 44 |  |
| fusdebug_drive_info_comms | 16 |  |
| fusdebug_huge_sensor_update | 6 |  |
| fusdebug_odometry_Null |  | 6 |
| fusdebug_rtk_Front_Null |  | 7 |
| fusdebug_rtk_Rear_Null |  | 8 |
| fusdebug_w_huge_sensor_update |  | 49 |
| fusdebug_NumErrorCodes | 49 | 50 |
| fusdebug_Reserved | 7 | 16 |
| fusdebug_Reserved10 | 24 | 25 |
| fusdebug_Reserved11 | 25 | 26 |
| fusdebug_Reserved12 | 26 | 27 |
| fusdebug_Reserved13 | 27 | 28 |
| fusdebug_Reserved14 | 28 | 29 |
| fusdebug_Reserved15 | 29 | 30 |
| fusdebug_Reserved16 | 30 | 31 |
| fusdebug_Reserved17 | 31 | 44 |
| fusdebug_Reserved2 | 8 | 17 |
| fusdebug_Reserved3 | 17 | 18 |
| fusdebug_Reserved4 | 18 | 19 |
| fusdebug_Reserved5 | 19 | 20 |
| fusdebug_Reserved6 | 20 | 21 |
| fusdebug_Reserved7 | 21 | 22 |
| fusdebug_Reserved8 | 22 | 23 |
| fusdebug_Reserved9 | 23 | 24 |

#### FusionErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Fusion_Drv_Info_Comms | 25 |  |
| Fusion_Huge_Sensor_Update | 24 |  |
| Fusion_NumErrorCodes | 26 | 24 |

#### LocalisationErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Loc_Dri_Info_Comms | 12 |  |
| Loc_Reserved16 |  | 27 |
| Loc_Reserved | 13 | 12 |
| Loc_Reserved10 | 22 | 21 |
| Loc_Reserved11 | 23 | 22 |
| Loc_Reserved12 | 24 | 23 |
| Loc_Reserved13 | 25 | 24 |
| Loc_Reserved14 | 26 | 25 |
| Loc_Reserved15 | 27 | 26 |
| Loc_Reserved2 | 14 | 13 |
| Loc_Reserved3 | 15 | 14 |
| Loc_Reserved4 | 16 | 15 |
| Loc_Reserved5 | 17 | 16 |
| Loc_Reserved6 | 18 | 17 |
| Loc_Reserved7 | 19 | 18 |
| Loc_Reserved8 | 20 | 19 |
| Loc_Reserved9 | 21 | 20 |

#### ManagementErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| mgt_Drv_Info_Comms | 2 |  |
| mgt_shared_Drv | 3 |  |
| mgt_NumErrorCodes | 4 | 2 |

#### ManualErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Man_Dri_Info_Coms | 4 |  |
| Man_Duplicated_Joystick_Board | 5 |  |
| Man_NumErrorCodes | 6 | 4 |

#### ObstaclePCErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Obstacle_drv_info_comms | 24 |  |
| Obstacle_NumErrorCodes | 25 | 24 |

#### SignalMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| signal_Drv_Info_Comms | 2 |  |
| signal_NumErrorCodes | 3 | 2 |

#### StartupMsgErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| startup_Drv_Info_Comms | 5 |  |
| startup_lotte_Bms_Err | 6 |  |
| startup_NumErrorCodes | 7 | 5 |

#### WheelSpeedErrorCode
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| wheel_drv_info_comms | 2 |  |
| wheel_NumErrorCodes | 3 | 2 |


## 함수 선언/정의 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 함수 | `DriveInfo500kWpMsg_FromCan`, `DriveInfo500kWpMsg_ToCan`, `EmulatorHeadingMsg_FromCan`, `EmulatorHeadingMsg_ToCan`, `ExtObsLocMsg_FromCan`, `ExtObsLocMsg_ToCan`, `ExtObsSpeedMsg_FromCan`, `ExtObsSpeedMsg_ToCan`, `IMUStatus_FromCan`, `IMUStatus_ToCan`, `LatitudeMsg_FromCan`, `LatitudeMsg_ToCan`, `ObstacleDangerZoneStopMsg_FromCan`, `ObstacleDangerZoneStopMsg_ToCan` | 14 |
| OhmioLibraries_BK에만 있는 함수 | `CombinedHeightMsg_FromCan`, `CombinedHeightMsg_ToCan`, `CompassMsg_FromCan`, `CompassMsg_ToCan`, `DeviationReqMsg_FromCan`, `DeviationReqMsg_ToCan`, `DriveInfoMsg_FromCan`, `DriveInfoMsg_ToCan`, `DynamicTrackValidationMsg_FromCan`, `DynamicTrackValidationMsg_ToCan`, `FusionFrontLongitude_FromCan`, `FusionFrontLongitude_ToCan`, `FusionLatitudeMsg_FromCan`, `FusionLatitudeMsg_ToCan`, `GPSLatitudeMsg_FromCan`, `GPSLatitudeMsg_ToCan`, `HeadingMsg_FromCan`, `HeadingMsg_ToCan`, `HeightMsg_FromCan`, `HeightMsg_ToCan`, `ObstacleDetectionLiDARMsg_FromCan`, `ObstacleDetectionLiDARMsg_ToCan`, `StopReqMsg_FromCan`, `StopReqMsg_ToCan`, `UWBLatitudeMsg_FromCan`, `UWBLatitudeMsg_ToCan`, `UWBLongitudeMsg_FromCan`, `UWBLongitudeMsg_ToCan`, `UltraSoundMsg_FromCan`, `UltraSoundMsg_ToCan` | 30 |
| 동일 함수의 선언/정의 형태 변경 | `BMSStatusStdMsg_FromCan`, `BMSStatusStdMsg_ToCan`, `BatteryStatusMsg_FromCan`, `BatteryStatusMsg_ToCan`, `ConfigRespMsg_FromCan`, `ConfigRespMsg_ToCan`, `DriveInfoLongWpMsg_FromCan`, `DriveInfoLongWpMsg_ToCan`, `EHBPowerMsg_FromCan`, `EHBPowerMsg_ToCan`, `EHBReqMsg_FromCan`, `EHBReqMsg_ToCan`, `EHBT060PowerMsg_FromCan`, `EHBT060PowerMsg_ToCan`, `EPBStatusMsg_FromCan`, `EPBStatusMsg_ToCan`, `ErrorEHBT060_FromCan`, `ErrorEHBT060_ToCan`, `ErrorSteering_FromCan`, `ErrorSteering_ToCan`, `FusionAcceMsg_FromCan`, `FusionAcceMsg_ToCan`, `FusionBiasOutlierMsg_FromCan`, `FusionBiasOutlierMsg_ToCan`, `FusionFrontLatitude_FromCan`, `FusionFrontLatitude_ToCan`, `FusionHeight_FromCan`, `FusionHeight_ToCan`, `FusionInfoMsg_FromCan`, `FusionInfoMsg_ToCan`, `FusionRearLatitude_FromCan`, `FusionRearLatitude_ToCan`, `FusionRearLongitude_FromCan`, `FusionRearLongitude_ToCan`, `IMUAcc_FromCan`, `IMUAcc_ToCan`, `IMUGyr_FromCan`, `IMUGyr_ToCan`, `IMUMag_FromCan`, `IMUMag_ToCan`, `IMURot_FromCan`, `IMURot_ToCan`, `InterVehicleCommsMsg_FromCan`, `InterVehicleCommsMsg_ToCan`, `LidarLatitudeUndelayed_FromCan`, `LidarLatitudeUndelayed_ToCan`, `LidarLongitudeUndelayed_FromCan`, `LidarLongitudeUndelayed_ToCan`, `LidarSpeed_FromCan`, `LidarSpeed_ToCan`, ... (66개 추가) | 116 |

| Function | Origin_36_merge | OhmioLibraries_BK |
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

- 함수 형태 변경 36개 추가 생략.

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| BK-only 항목 판단 필요 | BK에만 있는 message/CAN_ID/enum의 통합 또는 제외 기준 필요 |
| 충돌/변경 판단 필요 | 동일 이름/ID에서 bit 구조, 설명, enum 값 차이가 있음 |
| 함수 구현 위치 정책 필요 | header 내부 static 구현과 prototype 중심 구조가 혼재함 |
