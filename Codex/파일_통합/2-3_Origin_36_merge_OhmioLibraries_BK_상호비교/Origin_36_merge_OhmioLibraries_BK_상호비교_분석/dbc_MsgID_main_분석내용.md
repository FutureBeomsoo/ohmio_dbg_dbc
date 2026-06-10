# dbc_MsgID_main.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 918 | 863 |
| SHA256 | 4223f406ef5b | db26235e4f68 |
| Include | 0 | 0 |
| Define | 3 | 3 |
| Struct/Message | 0 | 0 |
| Enum | 33 | 31 |
| CAN_ID | 271 | 256 |
| Function | 0 | 0 |
| Unified diff | +120 | -65 |

## 전처리/Define 비교

- include 차이 없음.

| Define | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| MAIN_CANBUS_VERSION_BUILD | 0xBEC99F67         // 32 bit hash code for the dbc file | 0x47AB1E0D         // 32 bit hash code for the dbc file |
| MAIN_CANBUS_VERSION_MAJOR | 4 | 2 |
| MAIN_CANBUS_VERSION_MINOR | 15 | 110 |

## Message/Struct 비교

- struct/message 차이 없음.

## CAN_ID 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 CAN_ID | `CAN_ID_ATMEL_RESET_TELEOP`, `CAN_ID_ATMEL_TELEOP_ERROR`, `CAN_ID_CONNECT_WP`, `CAN_ID_DRIVE_INFO500K_WP`, `CAN_ID_EMULATOR_HEADING`, `CAN_ID_EMULATOR_LAT`, `CAN_ID_EMULATOR_LONG`, `CAN_ID_EPB_DEBUG`, `CAN_ID_ERROR_NETWORK`, `CAN_ID_ERROR_TELE_OP`, `CAN_ID_EXT_OBS_LOC`, `CAN_ID_EXT_OBS_SPEED`, `CAN_ID_FUSION_PERSISTENT_PARAMS`, `CAN_ID_IMU_STATUS`, `CAN_ID_OBSTACLE_DANGER_ZONE_STOP`, `CAN_ID_OBSTACLE_PC_WARNING`, `CAN_ID_RESET_JOYSTICK`, `CAN_ID_RESET_TELE_OP`, `CAN_ID_RESET_TRANSLATOR2`, `CAN_ID_TIMEPULSE_FRONT`, `CAN_ID_TIMEPULSE_REAR`, `CAN_ID_TRANS1_ERROR`, `CAN_ID_VEHICLE_VIN` | 23 |
| OhmioLibraries_BK에만 있는 CAN_ID | `CAN_ID_ERROR_MOTOR_ADAPTOR`, `CAN_ID_ERROR_TRANS`, `CAN_ID_OBSTACLE_ACK`, `CAN_ID_OBSTACLE_CTRL`, `CAN_ID_OBSTACLE_TRACK`, `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK` | 8 |
| 동일 CAN_ID 이름의 값/설명 변경 | `CAN_ID_DEVIATION_REQ`, `CAN_ID_DYNAMIC_TRACK_VALIDATION`, `CAN_ID_ERROR_ACCESSORY1`, `CAN_ID_ERROR_ACCESSORY2`, `CAN_ID_ERROR_DRIVE_EXT`, `CAN_ID_ERROR_FRONT_WHEEL_SPEED`, `CAN_ID_ERROR_FUSION_DEBUG`, `CAN_ID_ERROR_REAR_WHEEL_SPEED`, `CAN_ID_FRONT_WHEEL_CNT`, `CAN_ID_FRONT_WHEEL_EXCEPTION`, `CAN_ID_FUSION_EXCEPTION`, `CAN_ID_FUSION_FLAGS`, `CAN_ID_FUSION_FRONT_LONG`, `CAN_ID_FUSION_HEIGHT`, `CAN_ID_FUS_ERROR`, `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_MAG`, `CAN_ID_IMU_ROT`, `CAN_ID_LOC_JOYSTICK`, `CAN_ID_LOC_MANUAL`, `CAN_ID_MANAGEMENT_ERROR`, `CAN_ID_OBSTACLE_DANGER_ZONE`, `CAN_ID_OBSTACLE_TRACK_DISTANCE`, `CAN_ID_REAR_WHEEL_CNT`, `CAN_ID_REAR_WHEEL_EXCEPTION`, `CAN_ID_REMOTE_SIGNAL`, `CAN_ID_STARTUP_ERROR`, `CAN_ID_STOP_REQ` | 29 |

### CAN_ID 값/설명 변경 상세

| CAN_ID | Origin 값 | BK 값 | Origin 설명 | BK 설명 |
| --- | --- | --- | --- | --- |
| CAN_ID_DEVIATION_REQ | 0x2C5 | 0x2C5 | DeviationReqMsg: | DeviationReqMsg:  bits0-15: waypoint; bits16-23: offset; bits24-31: speed; bit32: InFlag; bits33-35: acceleration; bit36: OffsetActive; bit37: NoDeviation; |
| CAN_ID_DYNAMIC_TRACK_VALIDATION | 0x300 | 0x300 | DynamicTrackValidationMsg: | DynamicTrackValidationMsg:  bits0-15: waypoint; bits16-35: x; bits36-55: y; |
| CAN_ID_ERROR_ACCESSORY1 | 0x02E | 0x02E | ErrorAccessory1:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; | ErrorAccessory1:  bits0-63: code; |
| CAN_ID_ERROR_ACCESSORY2 | 0x02F | 0x02F | ErrorAccessory2:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; | ErrorAccessory2:  bits0-63: code; |
| CAN_ID_ERROR_DRIVE_EXT | 0x024 | 0x024 | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5: DrvextSpeedDeviationError; bit6: DrvextEPB1CommsError; bit7: DrvextEPB2CommsError; | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; |
| CAN_ID_ERROR_FRONT_WHEEL_SPEED | 0x080 | 0x080 | ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; | ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; |
| CAN_ID_ERROR_FUSION_DEBUG | 0x725 | 0x725 | ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: huge_sensor_update; bits7-8: reserved; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open; bit16: drive_info_comms; bits17-31: reserved1; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34: choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36: steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx; bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42: dead_reckoning; bit43: odometry_suspicious; bit44: reserved2; bit45: gnss_antennas_out_of_range; bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; | ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: odometryNull; bit7: rtkFrontNull; bit8: rtkRearNull; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open; bits16-31: reserved; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34: choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36: steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx; bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42: dead_reckoning; bit43: odometry_suspicious; bit44: reserved1; bit45: gnss_antennas_out_of_range; bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; bit49: w_huge_sensor_update; |
| CAN_ID_ERROR_REAR_WHEEL_SPEED | 0x081 | 0x081 | ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; | ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; |
| CAN_ID_FRONT_WHEEL_CNT | 0x03C | 0x03C | frontWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; | frontWheelCnt:  bits0-31: right_count; bits32-63: left_count; |
| CAN_ID_FRONT_WHEEL_EXCEPTION | 0x7C0 | 0x7C0 | frontWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | frontWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| CAN_ID_FUSION_EXCEPTION | 0x765 | 0x765 | fusionExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | fusionExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| CAN_ID_FUSION_FLAGS | 0x724 | 0x724 | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25: safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_no_engine_state; bit35: w_large_gnss_delay; bit36: w_large_lidar_delay; bits37-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bits44-45: reserved2; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved3; bit52: st_dead_reckoning; bits53-54: reserved4; bit55: st_external_reset; | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: safety_relay_open; bits25-26: reserved; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_huge_sensor_update; bits35-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bit44: st_front_gnss_no_data_can; bit45: st_rear_gnss_no_data_can; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_dead_reckoning; bit51: reserved2; bit52: st_recent_gnss_available; bit53: st_external_reset; |
| CAN_ID_FUSION_FRONT_LONG | 0x21A | 0x21A | FusionFrontLongitude: | FusionFrontLongitude:  bits0-35: longitude; bits36-49: forwardConf; bits50-61: heading; bits62-63: sync; |
| CAN_ID_FUSION_HEIGHT | 0x21D | 0x21D | FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front; bits47-56: delay_gnss_rear; bits57-63: compute_time; | FusionHeight:  bits0-15: height; bits16-27: speed; bits28-29: reserved; bits30-31: sync; |
| CAN_ID_FUS_ERROR | 0x025 | 0x025 | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open; bit26: fus_drv_info_comms_error; | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_safety_relay_open; |
| CAN_ID_IMU_ACC | 0x622 | 0x262 | IMUAcc:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: reserved; bits62-63: sync; | IMUAcc:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: reserved; bits62-63: sync; |
| CAN_ID_IMU_GYR | 0x623 | 0x263 | IMUGyr:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-55: temperature; bits56-57: status; bits58-61: unused; bits62-63: sync; | IMUGyr:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-55: temperature; bits56-57: status; bits58-61: unused; bits62-63: sync; |
| CAN_ID_IMU_MAG | 0x727 | 0x727 | IMUMag:  bits0-19: x; bits20-39: y; bits40-59: z; bits60-61: reserved; bits62-63: sync; | IMUMag:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: unused; bits62-63: sync; |
| CAN_ID_IMU_ROT | 0x621 | 0x261 | IMURot:  bits0-15: pitch; bits16-31: roll; bits32-47: heading; bits48-59: accuracy; bits60-61: status; bits62-63: sync; | IMURot:  bits0-15: pitch; bits16-31: roll; bits32-47: heading; bits48-59: accuracy; bits60-61: status; bits62-63: sync; |
| CAN_ID_LOC_JOYSTICK | 0x186 | 0x186 | LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; bits52-55: reserved; bits56-63: id; | LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; |
| CAN_ID_LOC_MANUAL | 0x185 | 0x185 | LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; bits56-63: id; | LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; |
| CAN_ID_MANAGEMENT_ERROR | 0x02B | 0x02B | ManagementError:  bit0: monitorError; bit1: mgtStatusError; bit2: mgtDrvInfoCommsError; bit3: sharedDriveError; bits4-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff; bits18-19: ignoreDZ; bits20-21: mcuVersionsOk; bits22-23: recording; bits24-25: limpMode; | ManagementError:  bit0: monitorError; bit1: mgtStatusError; bits2-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff; |
| CAN_ID_OBSTACLE_DANGER_ZONE | 0x122 | 0x122 | ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bits23-39: reserved; bits40-63: timeStamp; | ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bits21-39: reserved; bits40-63: timeStamp; |
| CAN_ID_OBSTACLE_TRACK_DISTANCE | 0x123 | 0x123 | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42: ClearOnRight; bit43: ClearOnLeft; bits44-58: reserved; bits59-63: BackDistance; | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; |
| CAN_ID_REAR_WHEEL_CNT | 0x03D | 0x03D | rearWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; | rearWheelCnt:  bits0-31: right_count; bits32-63: left_count; |
| CAN_ID_REAR_WHEEL_EXCEPTION | 0x7C1 | 0x7C1 | rearWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; | rearWheelExceptionMsg:  bits0-31: ex_code; bits32-36: ex_addr; bits37-39: reserved; bits40-47: user_flag; |
| CAN_ID_REMOTE_SIGNAL | 0x590 | 0x590 | RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; bit19: overtake; | RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; |
| CAN_ID_STARTUP_ERROR | 0x023 | 0x023 | StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3: bmsPosRelayOpen; bit4: startupSafetyRelayOpen; bit5: startupDriveInfoComms; bit6: lotteBmsErr; | StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3: bmsPosRelayOpen; bit4: startupSafetyRelayOpen; |
| CAN_ID_STOP_REQ | 0x326 | 0x326 | StopReqMsg: | StopReqMsg:  bits0-15: waypoint; bits16-23: decelerate; bit24: deceFlag; bits25-27: reserved; bits28-31: reason; |

## Enum 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 enum | `CONNECT_TRACK_TYPE`, `RESET_PARAMETER` | 2 |
| 공통 enum entry 차이 | `COMMON_CAN`, `PARAMETER_ID`, `STOP_REASON`, `SYS_STATES`, `UNIT_ID` | 5 |

### 공통 enum entry 차이 상세

#### COMMON_CAN
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| CAN_ID_ATMEL_RESET_TELEOP | 121 |  |
| CAN_ID_ATMEL_TELEOP_ERROR | 280 |  |
| CAN_ID_CONNECT_WP | 1584 |  |
| CAN_ID_DRIVE_INFO500K_WP | 808 |  |
| CAN_ID_EMULATOR_HEADING | 2036 |  |
| CAN_ID_EMULATOR_LAT | 2034 |  |
| CAN_ID_EMULATOR_LONG | 2035 |  |
| CAN_ID_EPB_DEBUG | 1820 |  |
| CAN_ID_ERROR_NETWORK | 45 |  |
| CAN_ID_ERROR_TELE_OP | 136 |  |
| CAN_ID_EXT_OBS_LOC | 1440 |  |
| CAN_ID_EXT_OBS_SPEED | 1441 |  |
| CAN_ID_FUSION_PERSISTENT_PARAMS | 1832 |  |
| CAN_ID_IMU_STATUS | 1572 |  |
| CAN_ID_OBSTACLE_DANGER_ZONE_STOP | 292 |  |
| CAN_ID_OBSTACLE_PC_WARNING | 1799 |  |
| CAN_ID_RESET_JOYSTICK | 96 |  |
| CAN_ID_RESET_TELE_OP | 120 |  |
| CAN_ID_RESET_TRANSLATOR2 | 119 |  |
| CAN_ID_TIMEPULSE_FRONT | 56 |  |
| CAN_ID_ERROR_MOTOR_ADAPTOR |  | 45 |
| CAN_ID_ERROR_TRANS |  | 38 |
| CAN_ID_OBSTACLE_ACK |  | 1649 |
| CAN_ID_OBSTACLE_CTRL |  | 1648 |
| CAN_ID_OBSTACLE_TRACK |  | 1650 |
| CAN_ID_TELE_OP |  | 387 |
| CAN_ID_TRANS_DRIVE |  | 391 |
| CAN_ID_TRANS_JOYSTICK |  | 392 |
| CAN_ID_IMU_ACC | 1570 | 610 |
| CAN_ID_IMU_GYR | 1571 | 611 |
| CAN_ID_IMU_ROT | 1569 | 609 |

- entry 차이 3개 추가 생략.

#### PARAMETER_ID
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| PARAMETER_CURVE_IMPROVEMENT | 4 |  |
| PARAMETER_MIN_SPEED_DEC_STEP_DRIVE | 1 |  |
| PARAMETER_ODOMETER | 144 |  |
| PARAMETER_SPEED_KI | 134 |  |
| PARAMETER_SPEED_KP | 133 |  |
| PARAMETER_STEER_DELTA | 10 |  |
| PARAMETER_HEADING_KD |  | 134 |
| PARAMETER_HEADING_KI |  | 133 |
| PARAMETER_POST_PROC_HEADING_FILTER_LENGTH |  | 1 |
| PARAMETER_RESERVED1 |  | 10 |
| PARAMETER_SPEED_INC_STEP |  | 4 |
| NUMBER_OF_PARAMETER_ID | 145 | 141 |

#### STOP_REASON
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| STOP_JOYSTICK_STOP | 2 |  |
| STOP_MANAGEMENT_STOP | 0 |  |
| STOP_PORTER_ID | 4 |  |
| STOP_REMOTE_STOP | 3 |  |
| STOP_MANUAL_STOP |  | 3 |
| STOP_UNKNOW_STOP |  | 0 |
| STOP_USER_STOP |  | 1 |
| NUMBER_OF_STOP_REASON | 5 | 4 |
| STOP_BUS_STOP | 1 | 2 |

#### SYS_STATES
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| SYS_RESERVED | 6 |  |
| SYS_RESERVED2 | 9 |  |
| SYS_RESERVED3 | 14 |  |
| SYS_RESERVED4 | 16 |  |
| SYS_RESERVED5 | 18 |  |
| SYS_TOWING | 5 |  |
| SYS_CHARGE |  | 14 |
| SYS_DUMP_LOG |  | 5 |
| SYS_DUMP_REC |  | 6 |
| SYS_POST_PROC |  | 9 |
| SYS_SELECT |  | 16 |
| SYS_WAIT_TRANS |  | 18 |

#### UNIT_ID
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| ATMEL_TELEOP_ID | 41 |  |
| JOYSTICK_ID | 42 |  |
| TELEOP_ID | 40 |  |
| TRANSLATOR2_ID | 39 |  |
| LAST_UNIT_ID | 43 | 39 |


## 함수 선언/정의 비교

- 함수 선언/정의 차이 없음.

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| BK-only 항목 판단 필요 | BK에만 있는 message/CAN_ID/enum의 통합 또는 제외 기준 필요 |
| 충돌/변경 판단 필요 | 동일 이름/ID에서 bit 구조, 설명, enum 값 차이가 있음 |
| version/hash 또는 변환 정책 필요 | define 또는 helper 동작 차이 확인 필요 |
