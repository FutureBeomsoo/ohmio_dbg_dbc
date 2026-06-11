# dbc_MsgID_main.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 917 | 862 |
| SHA256 | 4223f406ef5b | db26235e4f68 |
| Include | 0 | 0 |
| Define | 3 | 3 |
| Struct/Message | 0 | 0 |
| Enum | 33 | 31 |
| CAN_ID | 271 | 256 |
| Function | 0 | 0 |
| Unified diff | -120 | +65 |

## 전처리/Define 비교

- include 차이 없음.

| Define | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `MAIN_CANBUS_VERSION_MAJOR` | `4` | `2` | 값 변경 |
| `MAIN_CANBUS_VERSION_BUILD` | `0xBEC99F67` | `0x47AB1E0D` | 값/주석 변경 |
| `MAIN_CANBUS_VERSION_MINOR` | `15` | `110` | 값/주석 변경 |

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 0 | - |
| OhmioLibraries_BK에만 있는 struct | 0 | - |
| 공통 struct 중 layout/comment 차이 | 0 | - |

## CAN_ID 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 CAN_ID | 23 | `CAN_ID_ATMEL_RESET_TELEOP`, `CAN_ID_ATMEL_TELEOP_ERROR`, `CAN_ID_CONNECT_WP`, `CAN_ID_DRIVE_INFO500K_WP`, `CAN_ID_EMULATOR_HEADING`, `CAN_ID_EMULATOR_LAT`, `CAN_ID_EMULATOR_LONG`, `CAN_ID_EPB_DEBUG`, `CAN_ID_ERROR_NETWORK`, `CAN_ID_ERROR_TELE_OP`, `CAN_ID_EXT_OBS_LOC`, `CAN_ID_EXT_OBS_SPEED`, `CAN_ID_FUSION_PERSISTENT_PARAMS`, `CAN_ID_IMU_STATUS`, `CAN_ID_OBSTACLE_DANGER_ZONE_STOP`, `CAN_ID_OBSTACLE_PC_WARNING`, `CAN_ID_RESET_JOYSTICK`, `CAN_ID_RESET_TELE_OP`, `CAN_ID_RESET_TRANSLATOR2`, `CAN_ID_TIMEPULSE_FRONT`, `CAN_ID_TIMEPULSE_REAR`, `CAN_ID_TRANS1_ERROR`, `CAN_ID_VEHICLE_VIN` |
| OhmioLibraries_BK에만 있는 CAN_ID | 8 | `CAN_ID_ERROR_MOTOR_ADAPTOR`, `CAN_ID_ERROR_TRANS`, `CAN_ID_OBSTACLE_ACK`, `CAN_ID_OBSTACLE_CTRL`, `CAN_ID_OBSTACLE_TRACK`, `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK` |
| 같은 CAN_ID 이름의 값 변경 | 3 | `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` |
| 같은 CAN_ID 이름의 설명 변경 | 26 | `CAN_ID_DEVIATION_REQ`, `CAN_ID_DYNAMIC_TRACK_VALIDATION`, `CAN_ID_ERROR_ACCESSORY1`, `CAN_ID_ERROR_ACCESSORY2`, `CAN_ID_ERROR_DRIVE_EXT`, `CAN_ID_ERROR_FRONT_WHEEL_SPEED`, `CAN_ID_ERROR_FUSION_DEBUG`, `CAN_ID_ERROR_REAR_WHEEL_SPEED`, `CAN_ID_FRONT_WHEEL_CNT`, `CAN_ID_FRONT_WHEEL_EXCEPTION`, `CAN_ID_FUSION_EXCEPTION`, `CAN_ID_FUSION_FLAGS`, `CAN_ID_FUSION_FRONT_LONG`, `CAN_ID_FUSION_HEIGHT`, `CAN_ID_FUS_ERROR`, `CAN_ID_IMU_MAG`, `CAN_ID_LOC_JOYSTICK`, `CAN_ID_LOC_MANUAL`, `CAN_ID_MANAGEMENT_ERROR`, `CAN_ID_OBSTACLE_DANGER_ZONE`, `CAN_ID_OBSTACLE_TRACK_DISTANCE`, `CAN_ID_REAR_WHEEL_CNT`, `CAN_ID_REAR_WHEEL_EXCEPTION`, `CAN_ID_REMOTE_SIGNAL`, `CAN_ID_STARTUP_ERROR`, `CAN_ID_STOP_REQ` |
| 같은 numeric ID의 이름 차이 | 2 | 0x26, 0x2d |

### CAN_ID 상세

| CAN_ID | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `CAN_ID_ATMEL_RESET_TELEOP` | `0x79` AtmelResetTeleop:  bits0-7: cause; |  | Origin_36_merge에만 있음 |
| `CAN_ID_ATMEL_TELEOP_ERROR` | `0x118` AtmelTeleopError:  bit0: NotSpecified; |  | Origin_36_merge에만 있음 |
| `CAN_ID_CONNECT_WP` | `0x630` ConnectWp:  bits0-18: startWp; bits19-37: endWp; bits38-39: startTrack; bits40-41: endTrack; bits42-44: type; bits45-47: distanceWpForCurved; bit48: restore; |  | Origin_36_merge에만 있음 |
| `CAN_ID_DRIVE_INFO500K_WP` | `0x328` DriveInfo500kWpMsg:  bits0-18: waypoint; bits19-23: reserved; bits24-31: maxSpeed; bits32-47: errorDistance; bits48-53: mode; bit54: brake; bit55: reverse; bits56-59: path; bit60: leftDrive; bit61: errorCheck; bit62: useLidar; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_HEADING` | `0x7f4` EmulatorHeadingMsg:  bits0-15: heading; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_LAT` | `0x7f2` EmulatorLatitudeMsg:  bits0-34: latitude; bit35: sign; bit36: outlier; bits37-39: reserved; bits40-63: time; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_LONG` | `0x7f3` EmulatorLongitude:  bits0-34: longitude; bit35: sign; bits36-39: quality; bits40-63: time; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EPB_DEBUG` | `0x71c` EPBDebugMsg: |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_NETWORK` | `0x2d` ErrorNetwork:  bit0: network_duplicate_board; bit1: network_safety_relay_open; bit2: network_drv_info_comms_error; |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_TELE_OP` | `0x88` ErrorTeleOp:  bit0: teleop_safety_relay_open; bit1: teleop_drv_info_comms_error; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EXT_OBS_LOC` | `0x5a0` ExtObsLocMsg:  bits0-15: id; bits16-37: x; bits38-59: y; bit60: cleared; |  | Origin_36_merge에만 있음 |
| `CAN_ID_EXT_OBS_SPEED` | `0x5a1` ExtObsSpeedMsg:  bits0-15: id; bits16-23: speed; bits24-32: heading; |  | Origin_36_merge에만 있음 |
| `CAN_ID_FUSION_PERSISTENT_PARAMS` | `0x728` FusionPersistentParams: |  | Origin_36_merge에만 있음 |
| `CAN_ID_IMU_STATUS` | `0x624` IMUStatus:  bits0-31: status; bits32-47: warnings; bits48-59: heading; bit60: heading_available; |  | Origin_36_merge에만 있음 |
| `CAN_ID_OBSTACLE_DANGER_ZONE_STOP` | `0x124` ObstacleDangerZoneStopMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bit23: occluded; bits24-31: tolerance; |  | Origin_36_merge에만 있음 |
| `CAN_ID_OBSTACLE_PC_WARNING` | `0x707` ObstaclePcWarning:  bit0: ObsFrontTopLidarDetectingBody; bit1: ObsRearTopLidarDetectingBody; bit2: ObsFrontTopLidarSectionMissing; bit3: ObsFrontRightLidarSectionMissing; bit4: ObsFrontLeftLidarSectionMissing; bit5: ObsRearTopLidarSectionMissing; bit6: ObsRearRightLidarSectionMissing; bit7: ObsRearLeftLidarSectionMissing; bit8: ObsFrontTopLidarCalibration; bit9: ObsFrontRightLidarCalibration; bit10: ObsFrontLeftLidarCalibration; bit11: ObsRearTopLidarCalibration; bit12: ObsRearRightLidarCalibration; bit13: ObsRearLeftLidarCalibration; bit14: ObsKeyframeSaverError; bit15: ObsOdometryTimeout; bit16: ObsKeyframeLoaderDatabaseError; bit17: ObsKeyframeLoaderVersionError; |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_JOYSTICK` | `0x60` ResetJoystick:  bits0-15: cause; |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_TELE_OP` | `0x78` ResetTeleOp:  bits0-15: cause; |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_TRANSLATOR2` | `0x77` ResetTranslator2:  bits0-15: cause; |  | Origin_36_merge에만 있음 |
| `CAN_ID_TIMEPULSE_FRONT` | `0x38` Timepulse_front:  bits0-31: localTime; bits32-33: sync; |  | Origin_36_merge에만 있음 |
| `CAN_ID_TIMEPULSE_REAR` | `0x39` Timepulse_rear:  bits0-31: localTime; bits32-33: sync; |  | Origin_36_merge에만 있음 |
| `CAN_ID_TRANS1_ERROR` | `0x26` Trans1Error:  bit0: ManJoystickDisconnect; bit1: ManJoystickCommsError; bit2: ManJoystickCentreError; bit3: ManSafetyRelayOpen; bit4: ManDriInfoComsError; bit5: DuplicatedJoystickBoard; |  | Origin_36_merge에만 있음 |
| `CAN_ID_VEHICLE_VIN` | `0x708` VehicleVIN: |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_MOTOR_ADAPTOR` |  | `0x2d` ErrorMotorAdaptor:  bits0-63: code; | OhmioLibraries_BK에만 있음 |
| `CAN_ID_ERROR_TRANS` |  | `0x26` ErrorTrans:  bit0: TransJoystickDisconnect; bit1: TransJoystickCommsError; bit2: TransJoystickCentreError; bit3: TransSafetyRelayOpen; | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_ACK` |  | `0x671` obstacle detection  ACK command byte0: identifier; byte1-4: error code or NAK; byte5-7: (uint24) timestamp | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_CTRL` |  | `0x670` obstacle detection control data byte0-1: destination; byte2-3: control type; byte5-7: (uint24) timestamp | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_TRACK` |  | `0x672` obstacle detection  track data byte0 bit0-3: ID; byte0-8 bits 4-63: data | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TELE_OP` |  | `0x183` TeleOpMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TRANS_DRIVE` |  | `0x187` TransDriveMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TRANS_JOYSTICK` |  | `0x188` TransJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; | OhmioLibraries_BK에만 있음 |
| `CAN_ID_IMU_ACC` | `0x622` IMUAcc:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: reserved; bits62-63: sync; | `0x262` IMUAcc:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: reserved; bits62-63: sync; | 값 변경 |
| `CAN_ID_IMU_GYR` | `0x623` IMUGyr:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-55: temperature; bits56-57: status; bits58-61: unused; bits62-63: sync; | `0x263` IMUGyr:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-55: temperature; bits56-57: status; bits58-61: unused; bits62-63: sync; | 값 변경 |
| `CAN_ID_IMU_ROT` | `0x621` IMURot:  bits0-15: pitch; bits16-31: roll; bits32-47: heading; bits48-59: accuracy; bits60-61: status; bits62-63: sync; | `0x261` IMURot:  bits0-15: pitch; bits16-31: roll; bits32-47: heading; bits48-59: accuracy; bits60-61: status; bits62-63: sync; | 값 변경 |

### CAN_ID 설명/comment 차이

| CAN_ID | Value | Origin_36_merge 설명 | OhmioLibraries_BK 설명 |
| --- | --- | --- | --- |
| `CAN_ID_DEVIATION_REQ` | `0x2c5` | DeviationReqMsg: | DeviationReqMsg:  bits0-15: waypoint; bits16-23: offset; bits24-31: speed; bit32: InFlag; bits33-35: acceleration; bit36: OffsetActive; bit37: NoDeviation; |
| `CAN_ID_DYNAMIC_TRACK_VALIDATION` | `0x300` | DynamicTrackValidationMsg: | DynamicTrackValidationMsg:  bits0-15: waypoint; bits16-35: x; bits36-55: y; |
| `CAN_ID_ERROR_ACCESSORY1` | `0x2e` | ErrorAccessory1:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; | ErrorAccessory1:  bits0-63: code; |
| `CAN_ID_ERROR_ACCESSORY2` | `0x2f` | ErrorAccessory2:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; | ErrorAccessory2:  bits0-63: code; |
| `CAN_ID_ERROR_DRIVE_EXT` | `0x24` | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5: DrvextSpeedDeviationError; bit6: DrvextEPB1CommsError; bit7: DrvextEPB2CommsError; | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; |
| `CAN_ID_ERROR_FRONT_WHEEL_SPEED` | `0x80` | ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; | ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; |
| `CAN_ID_ERROR_FUSION_DEBUG` | `0x725` | ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: huge_sensor_update; bits7-8: reserved; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open; bit16: drive_info_comms; bits17-31: reserved1; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34: choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36: steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx; bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42: dead_reckoning; bit43: odometry_suspicious; bit44: reserved2; bit45: gnss_antennas_out_of_range; bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; | ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: odometryNull; bit7: rtkFrontNull; bit8: rtkRearNull; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open; bits16-31: reserved; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34: choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36: steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx; bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42: dead_reckoning; bit43: odometry_suspicious; bit44: reserved1; bit45: gnss_antennas_out_of_range; bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; bit49: w_huge_sensor_update; |
| `CAN_ID_ERROR_REAR_WHEEL_SPEED` | `0x81` | ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; | ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; |
| `CAN_ID_FRONT_WHEEL_CNT` | `0x3c` | frontWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; | frontWheelCnt:  bits0-31: right_count; bits32-63: left_count; |
| `CAN_ID_FRONT_WHEEL_EXCEPTION` | `0x7c0` | frontWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | frontWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| `CAN_ID_FUSION_EXCEPTION` | `0x765` | fusionExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | fusionExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| `CAN_ID_FUSION_FLAGS` | `0x724` | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25: safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_no_engine_state; bit35: w_large_gnss_delay; bit36: w_large_lidar_delay; bits37-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bits44-45: reserved2; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved3; bit52: st_dead_reckoning; bits53-54: reserved4; bit55: st_external_reset; | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: safety_relay_open; bits25-26: reserved; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_huge_sensor_update; bits35-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bit44: st_front_gnss_no_data_can; bit45: st_rear_gnss_no_data_can; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_dead_reckoning; bit51: reserved2; bit52: st_recent_gnss_available; bit53: st_external_reset; |
| `CAN_ID_FUSION_FRONT_LONG` | `0x21a` | FusionFrontLongitude: | FusionFrontLongitude:  bits0-35: longitude; bits36-49: forwardConf; bits50-61: heading; bits62-63: sync; |
| `CAN_ID_FUSION_HEIGHT` | `0x21d` | FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front; bits47-56: delay_gnss_rear; bits57-63: compute_time; | FusionHeight:  bits0-15: height; bits16-27: speed; bits28-29: reserved; bits30-31: sync; |
| `CAN_ID_FUS_ERROR` | `0x25` | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open; bit26: fus_drv_info_comms_error; | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_safety_relay_open; |
| `CAN_ID_IMU_MAG` | `0x727` | IMUMag:  bits0-19: x; bits20-39: y; bits40-59: z; bits60-61: reserved; bits62-63: sync; | IMUMag:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: unused; bits62-63: sync; |
| `CAN_ID_LOC_JOYSTICK` | `0x186` | LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; bits52-55: reserved; bits56-63: id; | LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; |
| `CAN_ID_LOC_MANUAL` | `0x185` | LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; bits56-63: id; | LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; |
| `CAN_ID_MANAGEMENT_ERROR` | `0x2b` | ManagementError:  bit0: monitorError; bit1: mgtStatusError; bit2: mgtDrvInfoCommsError; bit3: sharedDriveError; bits4-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff; bits18-19: ignoreDZ; bits20-21: mcuVersionsOk; bits22-23: recording; bits24-25: limpMode; | ManagementError:  bit0: monitorError; bit1: mgtStatusError; bits2-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff; |
| `CAN_ID_OBSTACLE_DANGER_ZONE` | `0x122` | ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bits23-39: reserved; bits40-63: timeStamp; | ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bits21-39: reserved; bits40-63: timeStamp; |
| `CAN_ID_OBSTACLE_TRACK_DISTANCE` | `0x123` | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42: ClearOnRight; bit43: ClearOnLeft; bits44-58: reserved; bits59-63: BackDistance; | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; |
| `CAN_ID_REAR_WHEEL_CNT` | `0x3d` | rearWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; | rearWheelCnt:  bits0-31: right_count; bits32-63: left_count; |
| `CAN_ID_REAR_WHEEL_EXCEPTION` | `0x7c1` | rearWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | rearWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| `CAN_ID_REMOTE_SIGNAL` | `0x590` | RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; bit19: overtake; | RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; |
| `CAN_ID_STARTUP_ERROR` | `0x23` | StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3: bmsPosRelayOpen; bit4: startupSafetyRelayOpen; bit5: startupDriveInfoComms; bit6: lotteBmsErr; | StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3: bmsPosRelayOpen; bit4: startupSafetyRelayOpen; |
| `CAN_ID_STOP_REQ` | `0x326` | StopReqMsg: | StopReqMsg:  bits0-15: waypoint; bits16-23: decelerate; bit24: deceFlag; bits25-27: reserved; bits28-31: reason; |

### 같은 numeric ID의 이름 차이

| Value | Origin_36_merge name | OhmioLibraries_BK name |
| --- | --- | --- |
| `0x26` | `CAN_ID_TRANS1_ERROR` | `CAN_ID_ERROR_TRANS` |
| `0x2d` | `CAN_ID_ERROR_NETWORK` | `CAN_ID_ERROR_MOTOR_ADAPTOR` |

## Enum 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 enum | 2 | `CONNECT_TRACK_TYPE`, `RESET_PARAMETER` |
| OhmioLibraries_BK에만 있는 enum | 0 | - |
| 공통 enum entry 차이 | 5 | `COMMON_CAN`, `PARAMETER_ID`, `STOP_REASON`, `SYS_STATES`, `UNIT_ID` |

### COMMON_CAN

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `CAN_ID_ATMEL_RESET_TELEOP` | `0x79` |  | Origin_36_merge에만 있음 |
| `CAN_ID_ATMEL_TELEOP_ERROR` | `0x118` |  | Origin_36_merge에만 있음 |
| `CAN_ID_CONNECT_WP` | `0x630` |  | Origin_36_merge에만 있음 |
| `CAN_ID_DRIVE_INFO500K_WP` | `0x328` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_HEADING` | `0x7f4` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_LAT` | `0x7f2` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EMULATOR_LONG` | `0x7f3` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EPB_DEBUG` | `0x71c` |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_NETWORK` | `0x2d` |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_TELE_OP` | `0x88` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EXT_OBS_LOC` | `0x5a0` |  | Origin_36_merge에만 있음 |
| `CAN_ID_EXT_OBS_SPEED` | `0x5a1` |  | Origin_36_merge에만 있음 |
| `CAN_ID_FUSION_PERSISTENT_PARAMS` | `0x728` |  | Origin_36_merge에만 있음 |
| `CAN_ID_IMU_STATUS` | `0x624` |  | Origin_36_merge에만 있음 |
| `CAN_ID_OBSTACLE_DANGER_ZONE_STOP` | `0x124` |  | Origin_36_merge에만 있음 |
| `CAN_ID_OBSTACLE_PC_WARNING` | `0x707` |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_JOYSTICK` | `0x60` |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_TELE_OP` | `0x78` |  | Origin_36_merge에만 있음 |
| `CAN_ID_RESET_TRANSLATOR2` | `0x77` |  | Origin_36_merge에만 있음 |
| `CAN_ID_TIMEPULSE_FRONT` | `0x38` |  | Origin_36_merge에만 있음 |
| `CAN_ID_TIMEPULSE_REAR` | `0x39` |  | Origin_36_merge에만 있음 |
| `CAN_ID_TRANS1_ERROR` | `0x26` |  | Origin_36_merge에만 있음 |
| `CAN_ID_VEHICLE_VIN` | `0x708` |  | Origin_36_merge에만 있음 |
| `CAN_ID_ERROR_MOTOR_ADAPTOR` |  | `0x2d` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_ERROR_TRANS` |  | `0x26` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_ACK` |  | `0x671` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_CTRL` |  | `0x670` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_OBSTACLE_TRACK` |  | `0x672` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TELE_OP` |  | `0x183` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TRANS_DRIVE` |  | `0x187` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_TRANS_JOYSTICK` |  | `0x188` | OhmioLibraries_BK에만 있음 |
| `CAN_ID_DEVIATION_REQ` | `0x2c5` | `0x2c5` | 주석 변경 |
| `CAN_ID_DYNAMIC_TRACK_VALIDATION` | `0x300` | `0x300` | 주석 변경 |
| `CAN_ID_ERROR_ACCESSORY1` | `0x2e` | `0x2e` | 주석 변경 |
| `CAN_ID_ERROR_ACCESSORY2` | `0x2f` | `0x2f` | 주석 변경 |
| `CAN_ID_ERROR_DRIVE_EXT` | `0x24` | `0x24` | 주석 변경 |
| `CAN_ID_ERROR_FRONT_WHEEL_SPEED` | `0x80` | `0x80` | 주석 변경 |
| `CAN_ID_ERROR_FUSION_DEBUG` | `0x725` | `0x725` | 주석 변경 |
| `CAN_ID_ERROR_REAR_WHEEL_SPEED` | `0x81` | `0x81` | 주석 변경 |
| `CAN_ID_FRONT_WHEEL_CNT` | `0x3c` | `0x3c` | 주석 변경 |
| `CAN_ID_FRONT_WHEEL_EXCEPTION` | `0x7c0` | `0x7c0` | 주석 변경 |
| `CAN_ID_FUSION_EXCEPTION` | `0x765` | `0x765` | 주석 변경 |
| `CAN_ID_FUSION_FLAGS` | `0x724` | `0x724` | 주석 변경 |
| `CAN_ID_FUSION_FRONT_LONG` | `0x21a` | `0x21a` | 주석 변경 |
| `CAN_ID_FUSION_HEIGHT` | `0x21d` | `0x21d` | 주석 변경 |
| `CAN_ID_FUS_ERROR` | `0x25` | `0x25` | 주석 변경 |
| `CAN_ID_IMU_ACC` | `0x622` | `0x262` | 값 변경 |
| `CAN_ID_IMU_GYR` | `0x623` | `0x263` | 값 변경 |
| `CAN_ID_IMU_MAG` | `0x727` | `0x727` | 주석 변경 |
| `CAN_ID_IMU_ROT` | `0x621` | `0x261` | 값 변경 |
| `CAN_ID_LOC_JOYSTICK` | `0x186` | `0x186` | 주석 변경 |
| `CAN_ID_LOC_MANUAL` | `0x185` | `0x185` | 주석 변경 |
| `CAN_ID_MANAGEMENT_ERROR` | `0x2b` | `0x2b` | 주석 변경 |
| `CAN_ID_OBSTACLE_DANGER_ZONE` | `0x122` | `0x122` | 주석 변경 |
| `CAN_ID_OBSTACLE_TRACK_DISTANCE` | `0x123` | `0x123` | 주석 변경 |
| `CAN_ID_REAR_WHEEL_CNT` | `0x3d` | `0x3d` | 주석 변경 |
| `CAN_ID_REAR_WHEEL_EXCEPTION` | `0x7c1` | `0x7c1` | 주석 변경 |
| `CAN_ID_REMOTE_SIGNAL` | `0x590` | `0x590` | 주석 변경 |
| `CAN_ID_STARTUP_ERROR` | `0x23` | `0x23` | 주석 변경 |
| `CAN_ID_STOP_REQ` | `0x326` | `0x326` | 주석 변경 |

### PARAMETER_ID

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `PARAMETER_CURVE_IMPROVEMENT` | `4` |  | Origin_36_merge에만 있음 |
| `PARAMETER_MIN_SPEED_DEC_STEP_DRIVE` | `1` |  | Origin_36_merge에만 있음 |
| `PARAMETER_ODOMETER` | `0x90` |  | Origin_36_merge에만 있음 |
| `PARAMETER_SPEED_KI` | `0x86` |  | Origin_36_merge에만 있음 |
| `PARAMETER_SPEED_KP` | `0x85` |  | Origin_36_merge에만 있음 |
| `PARAMETER_STEER_DELTA` | `0xa` |  | Origin_36_merge에만 있음 |
| `PARAMETER_HEADING_KD` |  | `0x86` | OhmioLibraries_BK에만 있음 |
| `PARAMETER_HEADING_KI` |  | `0x85` | OhmioLibraries_BK에만 있음 |
| `PARAMETER_POST_PROC_HEADING_FILTER_LENGTH` |  | `1` | OhmioLibraries_BK에만 있음 |
| `PARAMETER_RESERVED1` |  | `0xa` | OhmioLibraries_BK에만 있음 |
| `PARAMETER_SPEED_INC_STEP` |  | `4` | OhmioLibraries_BK에만 있음 |
| `NUMBER_OF_PARAMETER_ID` | `0x91` | `0x8d` | 값 변경 |

### STOP_REASON

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `STOP_JOYSTICK_STOP` | `2` |  | Origin_36_merge에만 있음 |
| `STOP_MANAGEMENT_STOP` | `0` |  | Origin_36_merge에만 있음 |
| `STOP_PORTER_ID` | `4` |  | Origin_36_merge에만 있음 |
| `STOP_REMOTE_STOP` | `3` |  | Origin_36_merge에만 있음 |
| `STOP_MANUAL_STOP` |  | `3` | OhmioLibraries_BK에만 있음 |
| `STOP_UNKNOW_STOP` |  | `0` | OhmioLibraries_BK에만 있음 |
| `STOP_USER_STOP` |  | `1` | OhmioLibraries_BK에만 있음 |
| `NUMBER_OF_STOP_REASON` | `5` | `4` | 값 변경 |
| `STOP_BUS_STOP` | `1` | `2` | 값 변경 |

### SYS_STATES

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `SYS_RESERVED` | `6` |  | Origin_36_merge에만 있음 |
| `SYS_RESERVED2` | `9` |  | Origin_36_merge에만 있음 |
| `SYS_RESERVED3` | `0xe` |  | Origin_36_merge에만 있음 |
| `SYS_RESERVED4` | `0x10` |  | Origin_36_merge에만 있음 |
| `SYS_RESERVED5` | `0x12` |  | Origin_36_merge에만 있음 |
| `SYS_TOWING` | `5` |  | Origin_36_merge에만 있음 |
| `SYS_CHARGE` |  | `0xe` | OhmioLibraries_BK에만 있음 |
| `SYS_DUMP_LOG` |  | `5` | OhmioLibraries_BK에만 있음 |
| `SYS_DUMP_REC` |  | `6` | OhmioLibraries_BK에만 있음 |
| `SYS_POST_PROC` |  | `9` | OhmioLibraries_BK에만 있음 |
| `SYS_SELECT` |  | `0x10` | OhmioLibraries_BK에만 있음 |
| `SYS_WAIT_TRANS` |  | `0x12` | OhmioLibraries_BK에만 있음 |

### UNIT_ID

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `ATMEL_TELEOP_ID` | `0x29` |  | Origin_36_merge에만 있음 |
| `JOYSTICK_ID` | `0x2a` |  | Origin_36_merge에만 있음 |
| `TELEOP_ID` | `0x28` |  | Origin_36_merge에만 있음 |
| `TRANSLATOR2_ID` | `0x27` |  | Origin_36_merge에만 있음 |
| `LAST_UNIT_ID` | `0x2b` | `0x27` | 값 변경 |

## Function 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 function | 0 | - |
| OhmioLibraries_BK에만 있는 function | 0 | - |
| 공통 function 형태/구현 차이 | 0 | - |
