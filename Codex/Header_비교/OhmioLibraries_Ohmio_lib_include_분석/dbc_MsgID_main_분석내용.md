# dbc_MsgID_main.h 비교 분석

- 비교 A: `OhmioLibraries` - `OhmioLibraries/include/canbus/dbc_MsgID_main.h`
- 비교 B: `Ohmio_lib_include` - `OhmioLibraries_36/Ohmio_lib_include/include/canbus/dbc_MsgID_main.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목 | OhmioLibraries | Ohmio_lib_include |
| --- | --- | --- |
| Line | 915 | 899 |
| SHA256 | a68c96238d55 | 2037a55d2fd0 |
| Struct | 0 | 0 |
| Enum | 33 | 32 |
| CAN_ID | 271 | 270 |
| Function | 0 | 0 |
| Unified diff | -24 | +8 |

Diff hunk 위치:
- `@@ -2,8 +2,8 @@`
- `@@ -27,8 +27,8 @@`
- `@@ -92,7 +92,7 @@`
- `@@ -128,7 +128,7 @@`
- `@@ -230,7 +230,6 @@`
- `@@ -248,7 +247,7 @@`
- `@@ -258,7 +257,7 @@`
- `@@ -376,21 +375,6 @@`

### 전처리/Include 비교
Macro 값 변경:
| Macro | OhmioLibraries | Ohmio_lib_include |
| --- | --- | --- |
| MAIN_CANBUS_VERSION_BUILD | 0xBEC99F67 | 0xE3A942C4 |
| MAIN_CANBUS_VERSION_MINOR | 15 | 9 |

### CAN ID enum 비교
OhmioLibraries에만 있는 CAN_ID:
| Name | Value | Comment |
| --- | --- | --- |
| CAN_ID_CONNECT_WP | 0x630 | ConnectWp:  bits0-18: startWp; bits19-37: endWp; bits38-39: startTrack; bits40-41: endTrack; bits42-44: type; bits45-47: distanceWpForCurved; bit48: restore; |
동일 CAN_ID 이름/값의 주석 정의 변경:
| Name | Value | OhmioLibraries | Ohmio_lib_include |
| --- | --- | --- | --- |
| CAN_ID_ERROR_DRIVE_EXT | 0x24 | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5: DrvextSpeedDeviationError; bit6: DrvextEPB1CommsError; bit7: DrvextEPB2CommsError; | ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5: DrvextSpeedDeviationError; |
| CAN_ID_FUSION_FLAGS | 0x724 | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: reserved; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25: safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_no_engine_state; bit35: w_large_gnss_delay; bit36: w_large_lidar_delay; bits37-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bits44-45: reserved2; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved3; bit52: st_dead_reckoning; bits53-54: reserved4; bit55: st_external_reset; | FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25: safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: no_engine_state; bits35-39: reserved; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bits44-45: reserved1; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved2; bit52: st_dead_reckoning; bits53-54: reserved3; bit55: st_external_reset; |
| CAN_ID_FUSION_HEIGHT | 0x21D | FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front; bits47-56: delay_gnss_rear; bits57-63: compute_time; | FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front; bits47-56: delay_gnss_rear; |
| CAN_ID_FUS_ERROR | 0x25 | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: reserved; bit23: fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open; bit26: fus_drv_info_comms_error; | FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open; bit26: fus_drv_info_comms_error; |
| CAN_ID_OBSTACLE_PC_WARNING | 0x707 | ObstaclePcWarning:  bit0: ObsFrontTopLidarDetectingBody; bit1: ObsRearTopLidarDetectingBody; bit2: ObsFrontTopLidarSectionMissing; bit3: ObsFrontRightLidarSectionMissing; bit4: ObsFrontLeftLidarSectionMissing; bit5: ObsRearTopLidarSectionMissing; bit6: ObsRearRightLidarSectionMissing; bit7: ObsRearLeftLidarSectionMissing; bit8: ObsFrontTopLidarCalibration; bit9: ObsFrontRightLidarCalibration; bit10: ObsFrontLeftLidarCalibration; bit11: ObsRearTopLidarCalibration; bit12: ObsRearRightLidarCalibration; bit13: ObsRearLeftLidarCalibration; bit14: ObsKeyframeSaverError; bit15: ObsOdometryTimeout; bit16: ObsKeyframeLoaderDatabaseError; bit17: ObsKeyframeLoaderVersionError; | ObstaclePcWarning:  bit0: ObsFrontTopLidarDetectingBody; bit1: ObsRearTopLidarDetectingBody; bit2: ObsFrontTopLidarSectionMissing; bit3: ObsFrontRightLidarSectionMissing; bit4: ObsFrontLeftLidarSectionMissing; bit5: ObsRearTopLidarSectionMissing; bit6: ObsRearRightLidarSectionMissing; bit7: ObsRearLeftLidarSectionMissing; bit8: ObsFrontTopLidarCalibration; bit9: ObsFrontRightLidarCalibration; bit10: ObsFrontLeftLidarCalibration; bit11: ObsRearTopLidarCalibration; bit12: ObsRearRightLidarCalibration; bit13: ObsRearLeftLidarCalibration; bit14: ObsKeyframeDatabaseError; bit15: ObsOdometryTimeout; |
| CAN_ID_OBSTACLE_TRACK_DISTANCE | 0x123 | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42: ClearOnRight; bit43: ClearOnLeft; bits44-58: reserved; bits59-63: BackDistance; | ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42: ClearOnRight; bit43: ClearOnLeft; |

### 일반 enum 비교
OhmioLibraries에만 있는 enum:
| Enum | entry 수 |
| --- | --- |
| CONNECT_TRACK_TYPE | 4 |

### Struct/Message 비교
양쪽 struct 목록은 동일합니다.
공통 struct의 Signal layout 차이는 없습니다.

### 함수 선언/정의 비교
함수 선언/정의 차이는 없습니다.

## 사용자 점검 후보
- MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xBEC99F67 -> 0xE3A942C4
- MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 15 -> 9
