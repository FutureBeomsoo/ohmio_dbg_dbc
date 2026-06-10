# dbc_MsgID_main.h 비교 분석

- 비교 A: `OhmioLibraries` - `OhmioLibraries/include/canbus/dbc_MsgID_main.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목           | OhmioLibraries | OhmioLibraries_BK |
| ------------ | -------------- | ----------------- |
| Line         | 915            | 862               |
| SHA256       | a68c96238d55   | db26235e4f68      |
| Struct       | 0              | 0                 |
| Enum         | 33             | 31                |
| CAN_ID       | 271            | 256               |
| Function     | 0              | 0                 |
| Unified diff | -118           | +65               |


Diff hunk 위치:
- `@@ -1,9 +1,9 @@`
- `@@ -26,24 +26,22 @@`
- `@@ -60,7 +58,6 @@`
- `@@ -77,23 +74,17 @@`
- `@@ -107,8 +98,11 @@`
- `@@ -125,10 +119,10 @@`
- `@@ -155,6 +149,9 @@`
- `@@ -167,8 +164,8 @@`
- `@@ -184,9 +181,8 @@`
- `@@ -217,20 +213,13 @@`
- `@@ -239,6 +228,9 @@`
- `@@ -248,24 +240,20 @@`
- `@@ -274,12 +262,9 @@`
- `@@ -329,10 +314,6 @@`
- `@@ -375,21 +356,6 @@`
- `@@ -641,34 +607,33 @@`
- `@@ -711,23 +676,6 @@`
- `@@ -796,16 +744,15 @@`
- `@@ -823,20 +770,20 @@`

### 전처리/Include 비교
Macro 값 변경:
| Macro                     | OhmioLibraries | OhmioLibraries_BK |
| ------------------------- | -------------- | ----------------- |
| MAIN_CANBUS_VERSION_BUILD | 0xBEC99F67     | 0x47AB1E0D        |
| MAIN_CANBUS_VERSION_MAJOR | 4              | 2                 |
| MAIN_CANBUS_VERSION_MINOR | 15             | 110               |


### CAN ID enum 비교
OhmioLibraries에만 있는 CAN_ID:
| Name                             | Value | Comment                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| -------------------------------- | ----- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| CAN_ID_ATMEL_RESET_TELEOP        | 0x79  | AtmelResetTeleop:  bits0-7: cause;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| CAN_ID_ATMEL_TELEOP_ERROR        | 0x118 | AtmelTeleopError:  bit0: NotSpecified;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| CAN_ID_CONNECT_WP                | 0x630 | ConnectWp:  bits0-18: startWp; bits19-37: endWp; bits38-39: startTrack; bits40-41: endTrack; bits42-44: type; bits45-47: distanceWpForCurved; bit48: restore;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| CAN_ID_DRIVE_INFO500K_WP         | 0x328 | DriveInfo500kWpMsg:  bits0-18: waypoint; bits19-23: reserved; bits24-31: maxSpeed; bits32-47: errorDistance; bits48-53: mode; bit54: brake; bit55: reverse; bits56-59: path; bit60: leftDrive; bit61: errorCheck; bit62: useLidar;                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| CAN_ID_EMULATOR_HEADING          | 0x7F4 | EmulatorHeadingMsg:  bits0-15: heading;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| CAN_ID_EMULATOR_LAT              | 0x7F2 | EmulatorLatitudeMsg:  bits0-34: latitude; bit35: sign; bit36: outlier; bits37-39: reserved; bits40-63: time;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| CAN_ID_EMULATOR_LONG             | 0x7F3 | EmulatorLongitude:  bits0-34: longitude; bit35: sign; bits36-39: quality; bits40-63: time;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| CAN_ID_EPB_DEBUG                 | 0x71C | EPBDebugMsg:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| CAN_ID_ERROR_NETWORK             | 0x2D  | ErrorNetwork:  bit0: network_duplicate_board; bit1: network_safety_relay_open; bit2: network_drv_info_comms_error;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| CAN_ID_ERROR_TELE_OP             | 0x88  | ErrorTeleOp:  bit0: teleop_safety_relay_open; bit1: teleop_drv_info_comms_error;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| CAN_ID_EXT_OBS_LOC               | 0x5A0 | ExtObsLocMsg:  bits0-15: id; bits16-37: x; bits38-59: y; bit60: cleared;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| CAN_ID_EXT_OBS_SPEED             | 0x5A1 | ExtObsSpeedMsg:  bits0-15: id; bits16-23: speed; bits24-32: heading;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| CAN_ID_FUSION_PERSISTENT_PARAMS  | 0x728 | FusionPersistentParams:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| CAN_ID_IMU_STATUS                | 0x624 | IMUStatus:  bits0-31: status; bits32-47: warnings; bits48-59: heading; bit60: heading_available;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| CAN_ID_OBSTACLE_DANGER_ZONE_STOP | 0x124 | ObstacleDangerZoneStopMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bit23: occluded; bits24-31: tolerance;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
| CAN_ID_OBSTACLE_PC_WARNING       | 0x707 | ObstaclePcWarning:  bit0: ObsFrontTopLidarDetectingBody; bit1: ObsRearTopLidarDetectingBody; bit2: ObsFrontTopLidarSectionMissing; bit3: ObsFrontRightLidarSectionMissing; bit4: ObsFrontLeftLidarSectionMissing; bit5: ObsRearTopLidarSectionMissing; bit6: ObsRearRightLidarSectionMissing; bit7: ObsRearLeftLidarSectionMissing; bit8: ObsFrontTopLidarCalibration; bit9: ObsFrontRightLidarCalibration; bit10: ObsFrontLeftLidarCalibration; bit11: ObsRearTopLidarCalibration; bit12: ObsRearRightLidarCalibration; bit13: ObsRearLeftLidarCalibration; bit14: ObsKeyframeSaverError; bit15: ObsOdometryTimeout; bit16: ObsKeyframeLoaderDatabaseError; bit17: ObsKeyframeLoaderVersionError; |
| CAN_ID_RESET_JOYSTICK            | 0x60  | ResetJoystick:  bits0-15: cause;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| CAN_ID_RESET_TELE_OP             | 0x78  | ResetTeleOp:  bits0-15: cause;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| CAN_ID_RESET_TRANSLATOR2         | 0x77  | ResetTranslator2:  bits0-15: cause;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| CAN_ID_TIMEPULSE_FRONT           | 0x38  | Timepulse_front:  bits0-31: localTime; bits32-33: sync;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| CAN_ID_TIMEPULSE_REAR            | 0x39  | Timepulse_rear:  bits0-31: localTime; bits32-33: sync;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| CAN_ID_TRANS1_ERROR              | 0x26  | Trans1Error:  bit0: ManJoystickDisconnect; bit1: ManJoystickCommsError; bit2: ManJoystickCentreError; bit3: ManSafetyRelayOpen; bit4: ManDriInfoComsError; bit5: DuplicatedJoystickBoard;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| CAN_ID_VEHICLE_VIN               | 0x708 | VehicleVIN:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |

OhmioLibraries_BK에만 있는 CAN_ID:
| Name                       | Value | Comment                                                                                                                                                                                                                                             |
| -------------------------- | ----- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| CAN_ID_ERROR_MOTOR_ADAPTOR | 0x2D  | ErrorMotorAdaptor:  bits0-63: code;                                                                                                                                                                                                                 |
| CAN_ID_ERROR_TRANS         | 0x26  | ErrorTrans:  bit0: TransJoystickDisconnect; bit1: TransJoystickCommsError; bit2: TransJoystickCentreError; bit3: TransSafetyRelayOpen;                                                                                                              |
| CAN_ID_OBSTACLE_ACK        | 0x671 | obstacle detection  ACK command byte0: identifier; byte1-4: error code or NAK; byte5-7: (uint24) timestamp                                                                                                                                          |
| CAN_ID_OBSTACLE_CTRL       | 0x670 | obstacle detection control data byte0-1: destination; byte2-3: control type; byte5-7: (uint24) timestamp                                                                                                                                            |
| CAN_ID_OBSTACLE_TRACK      | 0x672 | obstacle detection  track data byte0 bit0-3: ID; byte0-8 bits 4-63: data                                                                                                                                                                            |
| CAN_ID_TELE_OP             | 0x183 | TeleOpMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12;        |
| CAN_ID_TRANS_DRIVE         | 0x187 | TransDriveMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle;                                     |
| CAN_ID_TRANS_JOYSTICK      | 0x188 | TransJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; |

동일 CAN_ID 이름의 값 변경:
| Name           | OhmioLibraries | OhmioLibraries_BK |
| -------------- | -------------- | ----------------- |
| CAN_ID_IMU_ACC | 0x622          | 0x262             |
| CAN_ID_IMU_GYR | 0x623          | 0x263             |
| CAN_ID_IMU_ROT | 0x621          | 0x261             |

동일 numeric ID의 symbolic name 불일치:
| Value | OhmioLibraries       | OhmioLibraries_BK          |
| ----- | -------------------- | -------------------------- |
| 0x26  | CAN_ID_TRANS1_ERROR  | CAN_ID_ERROR_TRANS         |
| 0x2D  | CAN_ID_ERROR_NETWORK | CAN_ID_ERROR_MOTOR_ADAPTOR |

동일 CAN_ID 이름/값의 주석 정의 변경:
#### CAN_ID_DEVIATION_REQ (0x2C5)
  - OhmioLibraries: DeviationReqMsg:
  - OhmioLibraries_BK: DeviationReqMsg:  bits0-15: waypoint; bits16-23: offset; bits24-31: speed; bit32: InFlag;
                       bits33-35: acceleration; bit36: OffsetActive; bit37: NoDeviation;
#### CAN_ID_DYNAMIC_TRACK_VALIDATION (0x300)
  - OhmioLibraries: DynamicTrackValidationMsg:
  - OhmioLibraries_BK: DynamicTrackValidationMsg:  bits0-15: waypoint; bits16-35: x; bits36-55: y;
#### CAN_ID_ERROR_ACCESSORY1 (0x2E)
  - OhmioLibraries: ErrorAccessory1:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen;
                    bit3: AccessoryDrvInfoComms;
  - OhmioLibraries_BK: ErrorAccessory1:  bits0-63: code;
#### CAN_ID_ERROR_ACCESSORY2 (0x2F)
  - OhmioLibraries: ErrorAccessory2:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen;
                    bit3: AccessoryDrvInfoComms;
  - OhmioLibraries_BK: ErrorAccessory2:  bits0-63: code;
#### CAN_ID_ERROR_DRIVE_EXT (0x24)
  - OhmioLibraries: ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2:
                    DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5:
                    DrvextSpeedDeviationError; bit6: DrvextEPB1CommsError; bit7: DrvextEPB2CommsError;
  - OhmioLibraries_BK: ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2:
                       DrvextSafetyRelayOpen;
#### CAN_ID_ERROR_FRONT_WHEEL_SPEED (0x80)
  - OhmioLibraries: ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2:
                    wheel_drv_info_comms_error;
  - OhmioLibraries_BK: ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open;
#### CAN_ID_ERROR_FUSION_DEBUG (0x725)
  - OhmioLibraries: ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3:
                    steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: huge_sensor_update;
                    bits7-8: reserved; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11:
                    slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14:
                    saved_antenna_offset_missing; bit15: safety_relay_open; bit16: drive_info_comms; bits17-31:
                    reserved1; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34:
                    choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36:
                    steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx;
                    bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42:
                    dead_reckoning; bit43: odometry_suspicious; bit44: reserved2; bit45: gnss_antennas_out_of_range;
                    bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable;
  - OhmioLibraries_BK: ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid;
                       bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6:
                       odometryNull; bit7: rtkFrontNull; bit8: rtkRearNull; bit9: speedNotAvailableButNotZero; bit10:
                       slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive;
                       bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open;
                       bits16-31: reserved; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34:
                       choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36:
                       steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx;
                       bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42:
                       dead_reckoning; bit43: odometry_suspicious; bit44: reserved1; bit45: gnss_antennas_out_of_range;
                       bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; bit49:
                       w_huge_sensor_update;
#### CAN_ID_ERROR_REAR_WHEEL_SPEED (0x81)
  - OhmioLibraries: ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2:
                    wheel_drv_info_comms_error;
  - OhmioLibraries_BK: ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open;
#### CAN_ID_FRONT_WHEEL_CNT (0x3C)
  - OhmioLibraries: frontWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock;
  - OhmioLibraries_BK: frontWheelCnt:  bits0-31: right_count; bits32-63: left_count;
#### CAN_ID_FRONT_WHEEL_EXCEPTION (0x7C0)
  - OhmioLibraries: frontWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47:
                    user_flag;
  - OhmioLibraries_BK: frontWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47:
                       user_flag;
#### CAN_ID_FUSION_EXCEPTION (0x765)
  - OhmioLibraries: fusionExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47:
                    user_flag;
  - OhmioLibraries_BK: fusionExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47:
                       user_flag;
#### CAN_ID_FUSION_FLAGS (0x724)
  - OhmioLibraries: FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3:
                    rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6:
                    lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9:
                    front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12:
                    veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15:
                    odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18:
                    odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms;
                    bit22: reserved; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25:
                    safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28:
                    w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31:
                    w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34:
                    w_no_engine_state; bit35: w_large_gnss_delay; bit36: w_large_lidar_delay; bits37-39: reserved1;
                    bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43:
                    st_cam_slam_no_kf; bits44-45: reserved2; bit46: st_using_front_gnss; bit47: st_using_rear_gnss;
                    bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved3;
                    bit52: st_dead_reckoning; bits53-54: reserved4; bit55: st_external_reset;
  - OhmioLibraries_BK: FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3:
                       rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6:
                       lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9:
                       front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12:
                       veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15:
                       odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18:
                       odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21:
                       rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24:
                       safety_relay_open; bits25-26: reserved; bit27: w_front_gnss_no_data_ubx; bit28:
                       w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31:
                       w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34:
                       w_huge_sensor_update; bits35-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41:
                       st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bit44:
                       st_front_gnss_no_data_can; bit45: st_rear_gnss_no_data_can; bit46: st_using_front_gnss; bit47:
                       st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50:
                       st_dead_reckoning; bit51: reserved2; bit52: st_recent_gnss_available; bit53: st_external_reset;
#### CAN_ID_FUSION_FRONT_LONG (0x21A)
  - OhmioLibraries: FusionFrontLongitude:
  - OhmioLibraries_BK: FusionFrontLongitude:  bits0-35: longitude; bits36-49: forwardConf; bits50-61: heading;
                       bits62-63: sync;
#### CAN_ID_FUSION_HEIGHT (0x21D)
  - OhmioLibraries: FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front;
                    bits47-56: delay_gnss_rear; bits57-63: compute_time;
  - OhmioLibraries_BK: FusionHeight:  bits0-15: height; bits16-27: speed; bits28-29: reserved; bits30-31: sync;
#### CAN_ID_FUS_ERROR (0x25)
  - OhmioLibraries: FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3:
                    fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6:
                    fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms;
                    bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12:
                    fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf;
                    bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17:
                    fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20:
                    fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: reserved; bit23:
                    fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open;
                    bit26: fus_drv_info_comms_error;
  - OhmioLibraries_BK: FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3:
                       fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6:
                       fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms;
                       bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12:
                       fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf;
                       bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17:
                       fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20:
                       fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs;
                       bit23: fus_saved_antenna_offset_missing; bit24: fus_safety_relay_open;
#### CAN_ID_IMU_MAG (0x727)
  - OhmioLibraries: IMUMag:  bits0-19: x; bits20-39: y; bits40-59: z; bits60-61: reserved; bits62-63: sync;
  - OhmioLibraries_BK: IMUMag:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: unused;
                       bits62-63: sync;
#### CAN_ID_LOC_JOYSTICK (0x186)
  - OhmioLibraries: LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39:
                    throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8;
                    bit48: b9; bit49: b10; bit50: b11; bit51: b12; bits52-55: reserved; bits56-63: id;
  - OhmioLibraries_BK: LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39:
                       throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8;
                       bit48: b9; bit49: b10; bit50: b11; bit51: b12;
#### CAN_ID_LOC_MANUAL (0x185)
  - OhmioLibraries: LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start;
                    bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55:
                    rearSteerAngle; bits56-63: id;
  - OhmioLibraries_BK: LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start;
                       bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55:
                       rearSteerAngle;
#### CAN_ID_MANAGEMENT_ERROR (0x2B)
  - OhmioLibraries: ManagementError:  bit0: monitorError; bit1: mgtStatusError; bit2: mgtDrvInfoCommsError; bit3:
                    sharedDriveError; bits4-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff;
                    bits18-19: ignoreDZ; bits20-21: mcuVersionsOk; bits22-23: recording; bits24-25: limpMode;
  - OhmioLibraries_BK: ManagementError:  bit0: monitorError; bit1: mgtStatusError; bits2-7: reserved; bits8-9: GPSOff;
                       bits10-15: reserved1; bits16-17: drvGPSOff;
#### CAN_ID_OBSTACLE_DANGER_ZONE (0x122)
  - OhmioLibraries: ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22:
                    movingSideways; bits23-39: reserved; bits40-63: timeStamp;
  - OhmioLibraries_BK: ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bits21-39: reserved;
                       bits40-63: timeStamp;
#### CAN_ID_OBSTACLE_TRACK_DISTANCE (0x123)
  - OhmioLibraries: ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38:
                    sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42:
                    ClearOnRight; bit43: ClearOnLeft; bits44-58: reserved; bits59-63: BackDistance;
  - OhmioLibraries_BK: ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38:
                       sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle;
#### CAN_ID_REAR_WHEEL_CNT (0x3D)
  - OhmioLibraries: rearWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock;
  - OhmioLibraries_BK: rearWheelCnt:  bits0-31: right_count; bits32-63: left_count;
#### CAN_ID_REAR_WHEEL_EXCEPTION (0x7C1)
  - OhmioLibraries: rearWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47:
                    user_flag;
  - OhmioLibraries_BK: rearWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47:
                       user_flag;
#### CAN_ID_REMOTE_SIGNAL (0x590)
  - OhmioLibraries: RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; bit19: overtake;
  - OhmioLibraries_BK: RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn;
#### CAN_ID_STARTUP_ERROR (0x23)
  - OhmioLibraries: StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3:
                    bmsPosRelayOpen; bit4: startupSafetyRelayOpen; bit5: startupDriveInfoComms; bit6: lotteBmsErr;
  - OhmioLibraries_BK: StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3:
                       bmsPosRelayOpen; bit4: startupSafetyRelayOpen;
#### CAN_ID_STOP_REQ (0x326)
  - OhmioLibraries: StopReqMsg:
  - OhmioLibraries_BK: StopReqMsg:  bits0-15: waypoint; bits16-23: decelerate; bit24: deceFlag; bits25-27: reserved;
                       bits28-31: reason;

### 일반 enum 비교
OhmioLibraries에만 있는 enum:
| Enum               | entry 수 |
| ------------------ | ------- |
| CONNECT_TRACK_TYPE | 4       |
| RESET_PARAMETER    | 6       |

#### PARAMETER_ID
OhmioLibraries에만 있는 entry:
| Entry                              | Value |
| ---------------------------------- | ----- |
| PARAMETER_CURVE_IMPROVEMENT        | 4     |
| PARAMETER_MIN_SPEED_DEC_STEP_DRIVE | 1     |
| PARAMETER_ODOMETER                 | 0x90  |
| PARAMETER_SPEED_KI                 | 0x86  |
| PARAMETER_SPEED_KP                 | 0x85  |
| PARAMETER_STEER_DELTA              | 0xA   |

OhmioLibraries_BK에만 있는 entry:
| Entry                                     | Value |
| ----------------------------------------- | ----- |
| PARAMETER_HEADING_KD                      | 0x86  |
| PARAMETER_HEADING_KI                      | 0x85  |
| PARAMETER_POST_PROC_HEADING_FILTER_LENGTH | 1     |
| PARAMETER_RESERVED1                       | 0xA   |
| PARAMETER_SPEED_INC_STEP                  | 4     |

동일 entry 이름의 값 변경:
| Entry                  | OhmioLibraries | OhmioLibraries_BK |
| ---------------------- | -------------- | ----------------- |
| NUMBER_OF_PARAMETER_ID | 0x91           | 0x8D              |

#### STOP_REASON
OhmioLibraries에만 있는 entry:
| Entry                | Value |
| -------------------- | ----- |
| STOP_JOYSTICK_STOP   | 2     |
| STOP_MANAGEMENT_STOP | 0     |
| STOP_PORTER_ID       | 4     |
| STOP_REMOTE_STOP     | 3     |

OhmioLibraries_BK에만 있는 entry:
| Entry            | Value |
| ---------------- | ----- |
| STOP_MANUAL_STOP | 3     |
| STOP_UNKNOW_STOP | 0     |
| STOP_USER_STOP   | 1     |

동일 entry 이름의 값 변경:
| Entry                 | OhmioLibraries | OhmioLibraries_BK |
| --------------------- | -------------- | ----------------- |
| NUMBER_OF_STOP_REASON | 5              | 4                 |
| STOP_BUS_STOP         | 1              | 2                 |

#### SYS_STATES
OhmioLibraries에만 있는 entry:
| Entry         | Value |
| ------------- | ----- |
| SYS_RESERVED  | 6     |
| SYS_RESERVED2 | 9     |
| SYS_RESERVED3 | 0xE   |
| SYS_RESERVED4 | 0x10  |
| SYS_RESERVED5 | 0x12  |
| SYS_TOWING    | 5     |

OhmioLibraries_BK에만 있는 entry:
| Entry          | Value |
| -------------- | ----- |
| SYS_CHARGE     | 0xE   |
| SYS_DUMP_LOG   | 5     |
| SYS_DUMP_REC   | 6     |
| SYS_POST_PROC  | 9     |
| SYS_SELECT     | 0x10  |
| SYS_WAIT_TRANS | 0x12  |

#### UNIT_ID
OhmioLibraries에만 있는 entry:
| Entry           | Value |
| --------------- | ----- |
| ATMEL_TELEOP_ID | 0x29  |
| JOYSTICK_ID     | 0x2A  |
| TELEOP_ID       | 0x28  |
| TRANSLATOR2_ID  | 0x27  |

동일 entry 이름의 값 변경:
| Entry        | OhmioLibraries | OhmioLibraries_BK |
| ------------ | -------------- | ----------------- |
| LAST_UNIT_ID | 0x2B           | 0x27              |


### Struct/Message 비교
양쪽 struct 목록은 동일합니다.
공통 struct의 Signal layout 차이는 없습니다.

### 함수 선언/정의 비교
함수 선언/정의 차이는 없습니다.

## 사용자 점검 후보
- MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xBEC99F67 -> 0x47AB1E0D
- MAIN_CANBUS_VERSION_MAJOR 버전 값 변경: 4 -> 2
- MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 15 -> 110
- CAN_ID_IMU_ACC 값 변경: 0x622 -> 0x262
- CAN_ID_IMU_GYR 값 변경: 0x623 -> 0x263
- CAN_ID_IMU_ROT 값 변경: 0x621 -> 0x261
- 0x26 symbolic name 불일치
- 0x2D symbolic name 불일치
- PARAMETER_ID.NUMBER_OF_PARAMETER_ID 값 변경: 0x91 -> 0x8D
- STOP_REASON.NUMBER_OF_STOP_REASON 값 변경: 5 -> 4
- STOP_REASON.STOP_BUS_STOP 값 변경: 1 -> 2
- UNIT_ID.LAST_UNIT_ID 값 변경: 0x2B -> 0x27
