#ifndef main_DBC_MSGID_DBC_TOOL_GENERATED_H
#define main_DBC_MSGID_DBC_TOOL_GENERATED_H

#define MAIN_CANBUS_VERSION_MAJOR 4
#define MAIN_CANBUS_VERSION_MINOR 15
#define MAIN_CANBUS_VERSION_BUILD 0xBEC99F67         // 32 bit hash code for the dbc file
// OhmioLibraries_36 used MAIN_CANBUS_VERSION_MINOR 9 and BUILD 0xE3A942C4.



typedef enum
{
    CAN_ID_LOC_ERROR    =    0x010,    //  localisation error code
    CAN_ID_DRIVE_ERROR    =    0x011,    //  drive controller error code
    CAN_ID_F_STEER_ERROR    =    0x012,    //  front steering error code byte0: error; byte 3: current; byte4-5: RPM
    CAN_ID_R_STEER_ERROR    =    0x013,    //  rear steering error code  byte0: error; byte 3: current; byte4-5: RPM
    CAN_ID_MANUAL_ERROR    =    0x014,    //  manual controller error code
    CAN_ID_FUSION_ERROR    =    0x015,    //  fusion error code
    CAN_ID_BLACK_BOX_ERROR    =    0x016,    //  black box error code
    CAN_ID_OBSTACLE_PC_ERROR    =    0x017,    //  obstacle detection PC error code
    CAN_ID_L_MOTOR_ERROR    =    0x018,    //  left motor error code (OLD LIFT USING 0x10 ID)
    CAN_ID_EHB_ERROR    =    0x01A,    //  hydraulic brake error code
    CAN_ID_ERROR_EHB_T060    =    0x01B,    //    ErrorEHBT060:  bit0: T060RequestWarning; bit1: T060FollowLv1; bit2: T060VibLv1; bit3: T060_NTCLv1; bit4: T060_NTCLv2; bit5: T060PressureSensorFailed; bit6: T060OverTempWarning; bit7: T060LowPowerLv1; bit8: T060HighPowerLv1; bit9: T060FollowLv2; bit10: T060VibLv2; bit11: T060CanBusOff; bit12: T060OverCurrent; bit13: T060CurrentSensorFailed; bit14: T060LowPowerLv2; bit15: T060HighPowerLv2; bit16: T060PowerSwitchFailed; bit17: T060PowerDriverFailed; bit18: T060MotorPosFailed; bits19-23: reserved; bits24-31: T060Temp; bits32-47: reserved1; bits48-55: softwareVersion; bits56-63: hardwareVersion; 
    CAN_ID_EPB1_ERROR    =    0x01C,    //  parking brake 1 error code
    CAN_ID_EPB2_ERROR    =    0x01D,    //  parking brake 2 error code
    CAN_ID_F_SIGNAL_ERROR    =    0x01E,    //  front signal error code
    CAN_ID_R_SIGNAL_ERROR    =    0x01F,    //  rear signal error code
    CAN_ID_EMERGENCY    =    0x020,    //	emergency byte0: FF = emergency stop
    CAN_ID_SAFETY_ERROR    =    0x022,    //	safety board error code
    CAN_ID_STARTUP_ERROR    =    0x023,    //    StartupErrorMsg:  bit0: startupVersionError; bit1: bmsStatus; bit2: bmsErrLevel; bit3: bmsPosRelayOpen; bit4: startupSafetyRelayOpen; bit5: startupDriveInfoComms; bit6: lotteBmsErr; 
    CAN_ID_ERROR_DRIVE_EXT    =    0x024,    //    ErrorDriveExt:  bit0: DrvextObsValidationCommsError; bit1: DrvextMotorNoResp; bit2: DrvextSafetyRelayOpen; bit3: DrvextParameterOutOfRange; bit4: DrvextMotorOverTemp; bit5: DrvextSpeedDeviationError; bit6: DrvextEPB1CommsError; bit7: DrvextEPB2CommsError; 
    CAN_ID_FUS_ERROR    =    0x025,    //    FusError:  bit0: fus_internal_reset; bit1: fus_init_failed; bit2: fus_front_steer_invalid; bit3: fus_rear_steer_invalid; bit4: fus_speed_invalid; bit5: fus_time_step_size_invalid; bit6: fus_lidar_slam_stddev_nonpositive; bit7: fus_cam_slam_stddev_nonpositive; bit8: fus_motor_comms; bit9: fus_front_steer_comms; bit10: fus_rear_steer_comms; bit11: fus_veh_cholesky_failed; bit12: fus_veh_innovation_cov_not_psd; bit13: fus_veh_nonpositive_variance; bit14: fus_veh_nan_or_inf; bit15: fus_odo_cholesky_failed; bit16: fus_odo_innovation_cov_not_psd; bit17: fus_odo_nonpositive_variance; bit18: fus_odo_nan_or_inf; bit19: fus_drv_req_comms; bit20: fus_front_wheel_speed_comms; bit21: fus_rear_wheel_speed_comms; bit22: fus_conflicting_inputs; bit23: fus_saved_antenna_offset_missing; bit24: fus_huge_sensor_update; bit25: fus_safety_relay_open; bit26: fus_drv_info_comms_error; 
    CAN_ID_TRANS1_ERROR    =    0x026,    //    Trans1Error:  bit0: ManJoystickDisconnect; bit1: ManJoystickCommsError; bit2: ManJoystickCentreError; bit3: ManSafetyRelayOpen; bit4: ManDriInfoComsError; bit5: DuplicatedJoystickBoard; 
    CAN_ID_FOOT1_ERROR    =    0x028,    //	footing 1 error code
    CAN_ID_FOOT2_ERROR    =    0x029,    //	footing 2 error code
    CAN_ID_ERROR_SECURITY    =    0x02A,    //    ErrorSecurity:  bits0-63: code; 
    CAN_ID_MANAGEMENT_ERROR    =    0x02B,    //    ManagementError:  bit0: monitorError; bit1: mgtStatusError; bit2: mgtDrvInfoCommsError; bit3: sharedDriveError; bits4-7: reserved; bits8-9: GPSOff; bits10-15: reserved1; bits16-17: drvGPSOff; bits18-19: ignoreDZ; bits20-21: mcuVersionsOk; bits22-23: recording; bits24-25: limpMode; 
    CAN_ID_ERROR_NETWORK    =    0x02D,    //    ErrorNetwork:  bit0: network_duplicate_board; bit1: network_safety_relay_open; bit2: network_drv_info_comms_error; 
    CAN_ID_ERROR_ACCESSORY1    =    0x02E,    //    ErrorAccessory1:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; 
    CAN_ID_ERROR_ACCESSORY2    =    0x02F,    //    ErrorAccessory2:  bit0: AccessoryIncorrectPCB; bit1: AccessoryNonUniqueID; bit2: AccessoryRelayOpen; bit3: AccessoryDrvInfoComms; 
    CAN_ID_DRIVE_WARNING    =    0x031,    //  drive controller warning code
    CAN_ID_TIMEPULSE_FRONT    =    0x038,    //    Timepulse_front:  bits0-31: localTime; bits32-33: sync; 
    CAN_ID_TIMEPULSE_REAR    =    0x039,    //    Timepulse_rear:  bits0-31: localTime; bits32-33: sync; 
    CAN_ID_FRONT_WHEEL_SPEED    =    0x03A,    //    frontWheelSpeed:  bits0-15: left; bits16-31: right; bits32-63: clock; 
    CAN_ID_REAR_WHEEL_SPEED    =    0x03B,    //    rearWheelSpeed:  bits0-15: left; bits16-31: right; bits32-63: clock; 
    CAN_ID_FRONT_WHEEL_CNT    =    0x03C,    //    frontWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; 
    CAN_ID_REAR_WHEEL_CNT    =    0x03D,    //    rearWheelCnt:  bits0-15: right_count; bits16-31: left_count; bits32-63: clock; 
    CAN_ID_RESET_REQ    =    0x040,    //  reset request byte0-1: unit id (FF = all unit)
    CAN_ID_LOC_RESET_CAUSE    =    0x050,    //  localisation reset cause
    CAN_ID_DRIVE_RESET_CAUSE    =    0x051,    //  drive controller reset cause
    CAN_ID_F_STEER_RESET_CAUSE    =    0x052,    //  front steering reset cause
    CAN_ID_R_STEER_RESET_CAUSE    =    0x053,    //  rear steering reset cause
    CAN_ID_MANUAL_RESET_CAUSE    =    0x054,    //  manual reset cause
    CAN_ID_FUSION_RESET_CAUSE    =    0x055,    //  fusion reset cause
    CAN_ID_BLACK_BOX_RESET_CAUSE    =    0x056,    //  black box reset cause
    CAN_ID_OBSTACLE_PC_RESET_CAUSE    =    0x057,    //  obstacle detection PC reset cause
    CAN_ID_L_MOTOR_RESET_CAUSE    =    0x058,    //  left motor reset cause
    CAN_ID_R_MOTOR_RESET_CAUSE    =    0x059,    //  right motor reset cause
    CAN_ID_EHB_RESET_CAUSE    =    0x05A,    //	hydraulic brake reset cause
    CAN_ID_EPB1_RESET_CAUSE    =    0x05C,    //	parking brake 1 reset cause
    CAN_ID_EPB2_RESET_CAUSE    =    0x05D,    //	parking brake 2 reset cause
    CAN_ID_F_SIGNAL_RESET_CAUSE    =    0x05E,    //	front signal reset cause
    CAN_ID_R_SIGNAL_RESET_CAUSE    =    0x05F,    //	rear signal reset cause
    CAN_ID_RESET_JOYSTICK    =    0x060,    //    ResetJoystick:  bits0-15: cause; 
    CAN_ID_ATMEL_RESET_SAFETY    =    0x062,    //    AtmelResetSafety:  bits0-7: cause; 
    CAN_ID_RESET_STARTUP    =    0x063,    //    ResetStartup:  bits0-15: cause; 
    CAN_ID_ATMEL_RESET_LOC    =    0x064,    //    AtmelResetLocalisation:  bits0-7: cause; 
    CAN_ID_ATMEL_RESET_DRIVE    =    0x065,    //    AtmelResetDrive:  bits0-7: cause; 
    CAN_ID_ATMEL_RESET_MANUAL    =    0x066,    //    AtmelResetManual:  bits0-7: cause; 
    CAN_ID_ATMEL_RESET_FUSION    =    0x067,    //    AtmelResetFusion:  bits0-7: cause; 
    CAN_ID_FOOT1_RESET_CAUSE    =    0x068,    //	footing 1 reset cause
    CAN_ID_FOOT2_RESET_CAUSE    =    0x069,    //	footing 2 reset cause
    CAN_ID_RESET_SECURITY    =    0x06A,    //    ResetSecurity:  bits0-15: cause; 
    CAN_ID_ATMEL_RESET_SECURITY    =    0x06C,    //    AtmelResetSecurity:  bits0-7: cause; 
    CAN_ID_RESET_NETWORK_COMM    =    0x06D,    //    ResetNetworkComm:  bits0-15: cause; 
    CAN_ID_RESET_ACCESSORY1    =    0x06E,    //    ResetAccessory1:  bits0-15: cause; 
    CAN_ID_RESET_ACCESSORY2    =    0x06F,    //    ResetAccessory2:  bits0-15: cause; 
    CAN_ID_RESET_WHEEL_SPEED1    =    0x070,    //    ResetWheelSpeed1:  bits0-15: cause; 
    CAN_ID_RESET_WHEEL_SPEED2    =    0x071,    //    ResetWheelSpeed2:  bits0-15: cause; 
    CAN_ID_RESET_TRANSLATOR    =    0x076,    //    ResetTranslator:  bits0-15: cause; 
    CAN_ID_RESET_TRANSLATOR2    =    0x077,    //    ResetTranslator2:  bits0-15: cause; 
    CAN_ID_RESET_TELE_OP    =    0x078,    //    ResetTeleOp:  bits0-15: cause; 
    CAN_ID_ATMEL_RESET_TELEOP    =    0x079,    //    AtmelResetTeleop:  bits0-7: cause; 
    CAN_ID_ERROR_FRONT_WHEEL_SPEED    =    0x080,    //    ErrorFrontWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; 
    CAN_ID_ERROR_REAR_WHEEL_SPEED    =    0x081,    //    ErrorRearWheelSpeed:  bit0: wheel_board_config_error; bit1: wheel_safety_relay_open; bit2: wheel_drv_info_comms_error; 
    CAN_ID_ERROR_TELE_OP    =    0x088,    //    ErrorTeleOp:  bit0: teleop_safety_relay_open; bit1: teleop_drv_info_comms_error; 
    CAN_ID_LOC_EXT_WDT_ERROR    =    0x110,    //  localisation external watchdog error code
    CAN_ID_DRIVE_EXT_WDT_ERROR    =    0x111,    //  drive controller external watchdog error code
    CAN_ID_MANUAL_EXT_WDT_ERROR    =    0x114,    //  manual controller external watchdog error code
    CAN_ID_FUSION_EXT_WDT_ERROR    =    0x115,    //  fusion external watchdog error code
    CAN_ID_ATMEL_TELEOP_ERROR    =    0x118,    //    AtmelTeleopError:  bit0: NotSpecified; 
    CAN_ID_ATMEL_SECURITY_ERROR    =    0x11C,    //    AtmelSecurityError:  bit0: NotSpecified; 
    CAN_ID_OBSTACLE    =    0x120,    //	obstacle byte0-1: distance (value * 40 to convert unint to mm); byte1: 1 = valid value
    CAN_ID_ULTRA_SOUND    =    0x121,    //  ultra sound byte0: Front AD1; byte1: Front AD2; byte2: Front AD3; byte3: Front AD4; byte4: Rear AD1; byte5: Rear AD2; byte6: Rear AD3; byte7: Rear AD4
    CAN_ID_OBSTACLE_DANGER_ZONE    =    0x122,    //    ObstacleDangerZoneMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bits23-39: reserved; bits40-63: timeStamp; 
    CAN_ID_OBSTACLE_TRACK_DISTANCE    =    0x123,    //    ObstacleTrackDistanceMsg:  bits0-12: trackDistance; bits13-25: sideDistanceA; bits26-38: sideDistanceB; bit39: moveAwayFlag; bit40: incSpeedFlag; bit41: ignoredObstacle; bit42: ClearOnRight; bit43: ClearOnLeft; bits44-58: reserved; bits59-63: BackDistance; 
    CAN_ID_OBSTACLE_DANGER_ZONE_STOP    =    0x124,    //    ObstacleDangerZoneStopMsg:  bits0-12: distance; bits13-20: timeToCollision; bit21: notMoving; bit22: movingSideways; bit23: occluded; bits24-31: tolerance; 
    CAN_ID_FRONT_POINT_DIST    =    0x125,    //    FrontPointDist:  bits0-15: L1_dist; bits16-19: L1_num_total; bits20-23: L1_num_avg; bits24-31: reserved; bits32-47: L2_dist; bits48-51: L2_num_total; bits52-55: L2_num_avg; 
    CAN_ID_REAR_POINT_DIST    =    0x126,    //    RearPointDist:  bits0-15: L1_dist; bits16-19: L1_num_total; bits20-23: L1_num_avg; bits24-31: reserved; bits32-47: L2_dist; bits48-51: L2_num_total; bits52-55: L2_num_avg; 
    CAN_ID_TRAFFIC_LIGHT    =    0x130,    //    TrafficLightMsg:  bits0-7: status; bits8-23: timeToChange; bits24-39: lightID; bit40: stopNow; 
    CAN_ID_EHB_REQUEST    =    0x150,    //  front brake request byte0: bit0-3 Enable, bit4-7 Parking Active; byte1: vehicle slope; byte2(MSB)-3 bit3-7(LSB): Vehicle speed; byte3: bite1-2 vehicle speed Q; byte4: Aim Pressure; byte5(MSB)-6 bit4-7: Vehicle acc.; byte6: bit0-3 counter; byte 7: checksum
    CAN_ID_BRAKE_REQ    =    0x160,    //	(NOT used in LIFT) drive control byte0-1: (int16)brake value; byte2-3: (int16) wheel speed - 0.01m/s; byte4: bit0-5: driving mode, bit6: brakeing flag, bit7: revere flag; byte5-7: (uint24)timestamp
    CAN_ID_MOTOR3_REQ    =    0x161,    //    Motor3ReqMsg:  
    CAN_ID_SPEED_REQ    =    0x162,    //  speed request byte0-1: (int16) left wheel speed - 0.01m/s; byte2-3: (int16) right wheel speed - 0.01m/s; byte4: bit0-5: driving mode, bit6: brakeing flag, bit7: revere flag; byte5-7: (uint24)timestamp
    CAN_ID_F_STEER_REQ    =    0x163,    // 	front steering request byte0-1: (int16)steering angle - 0.01degree; byte2: (uint8)speed steps; byte3: (uint8)packet counter; byte5-7: (uint24)timestamp
    CAN_ID_R_STEER_REQ    =    0x164,    // 	rear steering request byte0-1: (int16)steering angle - 0.01degree; byte2: (uint8)speed steps; byte3: (uint8)packet counter; byte5-7: (uint24)timestamp
    CAN_ID_SPEED2_TORQUE_REQ    =    0x165,    //    Speed2TorqueReqMsg:  bits0-15: currentSpeed; bits16-31: reqSpeed; bits32-47: currentTorque; bits48-55: startupFlag; bit56: motorStopped; bit57: motorStarting; 
    CAN_ID_SPEED2_TORQUE_RESP    =    0x166,    //    Speed2TorqueRespMsg:  bits0-15: reqTorque; 
    CAN_ID_MANUAL    =    0x180,    //	manual drive (joystick) byte0-1: (int16)front steering angle - 0.01degree; byte2: (uint8)slider value; byte4: bit0: stop flag, bit1: reverse flag, bit4: brake flag; byte5-6: (int16)rear steering angle - 0.01degree
    CAN_ID_JOYSTICK    =    0x181,    //    JoystickMsg:  
    CAN_ID_LOC_MANUAL    =    0x185,    //    LocManualMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle; bits56-63: id; 
    CAN_ID_LOC_JOYSTICK    =    0x186,    //    LocJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12; bits52-55: reserved; bits56-63: id; 
    CAN_ID_TELE_OP    =    0x183,    //    TeleOpMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12;    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_TRANS_DRIVE    =    0x187,    //    TransDriveMsg:  bits0-15: frontSteerAngle; bits16-23: slide; bits24-31: pressure; bit32: start; bit33: reverse; bits34-35: reserved; bit36: brake; bit37: EPB; bits38-39: reserved1; bits40-55: rearSteerAngle;    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_TRANS_JOYSTICK    =    0x188,    //    TransJoystickMsg:  bits0-9: x; bits10-19: y; bits20-23: hatswitch; bits24-31: rotation; bits32-39: throttle; bit40: b1; bit41: b2; bit42: b3; bit43: b4; bit44: b5; bit45: b6; bit46: b7; bit47: b8; bit48: b9; bit49: b10; bit50: b11; bit51: b12;    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_OBSTACLE_CTRL    =    0x670,    //	obstacle detection control data byte0-1: destination; byte2-3: control type; byte5-7: (uint24) timestamp    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_OBSTACLE_ACK    =    0x671,    //	obstacle detection  ACK command byte0: identifier; byte1-4: error code or NAK; byte5-7: (uint24) timestamp    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_OBSTACLE_TRACK    =    0x672,    // 	obstacle detection  track data byte0 bit0-3: ID; byte0-8 bits 4-63: data    // 2-4 merge: BK-only CAN_ID added
    CAN_ID_PLATOON_DRIVE    =    0x1A0,    //    PlatoonDriveMsg:  bits0-3: mode; bits4-19: waypoint; bits20-35: speed; bits36-39: reserved; bits40-63: Time_Sync; 
    CAN_ID_VEHICLE1_COMMS    =    0x1A1,    //    Vehicle1CommsMsg:  bits0-3: mode; bits4-19: waypoint; bits20-35: speed; bits36-39: reserved; bits40-63: Time_Sync; 
    CAN_ID_VEHICLE2_COMMS    =    0x1A2,    //    Vehicle2CommsMsg:  bits0-3: mode; bits4-19: waypoint; bits20-35: speed; bits36-39: reserved; bits40-63: Time_Sync; 
    CAN_ID_VEHICLE3_COMMS    =    0x1A3,    //    Vehicle3CommsMsg:  bits0-3: mode; bits4-19: waypoint; bits20-35: speed; bits36-39: reserved; bits40-63: Time_Sync; 
    CAN_ID_TIMESTAMP    =    0x200,    //	system timestamp byte0-7: 64 bit unit (ms)
    CAN_ID_DRIVE_REQUESTS    =    0x201,    //    DriveRequestsMsg:  bit0: driveGPSOff; bit1: mgtGPSOff; bit2: lidarLocOff; bit3: fusionReset; 
    CAN_ID_FUSION_LAT    =    0x210,    //	fusion front latitude byte0-4: bit0-33 = latitude * 1E8, bit 35 indicate (-) value, range -90 to +90, bit 36 outlier; byte5-7: (uint24) timestamp
    CAN_ID_FUSION_LONG    =    0x211,    // 	fusion front longitude byte0-4: bit0-34 = longitude * 1e8, bit 35 indicate (-) value, range -180 to +180; byte5-7: (uint24) timestamp
    CAN_ID_FUSION_OTHER    =    0x212,    //	fusion location info byte0-1: (uint16)heading - 0.1deg; byte2-3: (uint16) easting confidence - 0.0001m step; byte4-5: (uint16) northing confidence - 0.0001m step; byte6-7: (uint16) heading confidence - 0.0001m step
    CAN_ID_FUSION_LAT2    =    0x213,    //	fusion back latitude byte0-4: bit0-33 = latitude * 1E8, bit 35 indicate (-) value, range -90 to +90, bit 36 outlier; byte5-7: (uint24) timestamp
    CAN_ID_FUSION_LONG2    =    0x214,    // 	fusion back longitude byte0-4: bit0-34 = longitude * 1e8, bit 35 indicate (-) value, range -180 to +180; byte5-7: (uint24) timestamp
    CAN_ID_FUSION_BIAS_OUTLIER    =    0x215,    //	fusion bias and outliers byte0: (int8)steering bias; byte1-2: bias confidence; byte3: front UWB outlier; byte4: rear UWB outlier; byte5-7: (uint24) timestamp
    CAN_ID_VEHICLE_INFO    =    0x216,    //    VehicleInfoMsg:  bits0-7: pitch; bits8-15: roll; bits16-31: antennaDistance; bits32-39: reserved; bits40-63: time; 
    CAN_ID_LIDAR_LAT_UNDELAYED    =    0x217,    //    LidarLatitudeUndelayed:  bits0-35: Latitude; bits36-51: CompassHeading; bit52: Available; bits53-61: reserved; bits62-63: sync; 
    CAN_ID_LIDAR_LONG_UNDELAYED    =    0x218,    //    LidarLongitudeUndelayed:  bits0-35: Longitude; bits36-39: StepsBack; bits40-61: reserved; bits62-63: sync; 
    CAN_ID_FUSION_FRONT_LAT    =    0x219,    //    FusionFrontLatitude:  bits0-35: latitude; bits36-43: longAcc; bits44-51: pitch; bits52-61: observedAntennaOffset; bits62-63: sync; 
    CAN_ID_FUSION_FRONT_LONG    =    0x21A,    //    FusionFrontLongitude:  
    CAN_ID_FUSION_REAR_LAT    =    0x21B,    //    FusionRearLatitude:  bits0-35: latitude; bits36-49: lateralConf; bits50-57: latAcc; bits58-61: unused; bits62-63: sync; 
    CAN_ID_FUSION_REAR_LONG    =    0x21C,    //    FusionRearLongitude:  bits0-35: longitude; bits36-49: headConf; bits50-59: savedAntennaOffset; bit60: fusionInitialisable; bit61: reserved; bits62-63: sync; 
    CAN_ID_FUSION_HEIGHT    =    0x21D,    //    FusionHeight:  bits0-22: height; bits23-34: speed; bits35-36: sync; bits37-46: delay_gnss_front; bits47-56: delay_gnss_rear; bits57-63: compute_time; 
    CAN_ID_GPS_LAT    =    0x220,    //	gps front latitude byte0-4: bit0-33 = latitude * 1E8, bit 35 indicate (-) value, range -90 to +90, bit 36-39 quality; byte5-7: (uint24) timestamp
    CAN_ID_GPS_LONG    =    0x221,    // 	gps front longitude byte0-4: bit0-34 = longitude * 1e8, bit 35 indicate (-) value, range -180 to +180, bit 36-39 quality; byte5-7: (uint24) timestamp
    CAN_ID_GPS_HEIGHT    =    0x222,    //	gps front height byte0-1: (uint16)altitude - 0.01m; byte2-3: (uint16) Difference between WGS-84 and sea-level - 0.01m; byte4: no. of sat; byte5-7: (uint24) timestamp
    CAN_ID_GPS_COMBINED_HEIGHT    =    0x223,    //	gps front height byte0-3: (int32)total altitude - 0.01m; byte4: no. of sat; byte5-7: (uint24) timestamp
    CAN_ID_FRONT_GPS_UBX_PART1    =    0x225,    //    frontGpsUbxPart1:  bits0-35: Latitude; bits36-58: Height; bit59: reserved; bit60: Valid_Checksum; bit61: Data_Available; bits62-63: Sync; 
    CAN_ID_FRONT_GPS_UBX_PART2    =    0x226,    //    frontGpsUbxPart2:  bits0-35: Longitude; bits36-45: HorizontalAccuracy; bits46-55: VerticalAccuracy; bits56-57: CarrierSolution; bit58: pvtValidChecksum; bits59-61: reserved; bits62-63: Sync; 
    CAN_ID_FRONT_GPS_UBX_PART3    =    0x227,    //    frontGpsUbxPart3:  bits0-31: iTow; bits32-63: localTime; 
    CAN_ID_GPS2_LAT    =    0x230,    //	gps back latitude byte0-4: bit0-33 = latitude * 1E8, bit 35 indicate (-) value, range -90 to +90, bit 36-39 quality; byte5-7: (uint24) timestamp
    CAN_ID_GPS2_LONG    =    0x231,    // 	gps back longitude byte0-4: bit0-34 = longitude * 1e8, bit 35 indicate (-) value, range -180 to +180, bit 36-39 quality; byte5-7: (uint24) timestamp
    CAN_ID_GPS2_HEIGHT    =    0x232,    //	gps back height byte0-1: (uint16) altitude - 0.01m; byte2-3: (uint16) Difference between WGS-84 and sea-level - 0.01m; byte4: no. of sat; byte5-7: (uint24) timestamp
    CAN_ID_GPS_HEAD    =    0x233,    //	gps heading byte0-1: (uint16)heading - 0.1 deg
    CAN_ID_GPS2_COMBINED_HEIGHT    =    0x234,    //	gps back height byte0-3: (int32)total altitude - 0.01m; byte4: no. of sat; byte5-7: (uint24) timestamp
    CAN_ID_REAR_GPS_UBX_PART1    =    0x235,    //    rearGpsUbxPart1:  bits0-35: Latitude; bits36-58: Height; bit59: reserved; bit60: Valid_Checksum; bit61: Data_Available; bits62-63: Sync; 
    CAN_ID_REAR_GPS_UBX_PART2    =    0x236,    //    rearGpsUbxPart2:  bits0-35: Longitude; bits36-45: HorizontalAccuracy; bits46-55: VerticalAccuracy; bits56-57: CarrierSolution; bit58: pvtValidChecksum; bits59-61: reserved; bits62-63: Sync; 
    CAN_ID_REAR_GPS_UBX_PART3    =    0x237,    //    rearGpsUbxPart3:  bits0-31: iTow; bits32-63: localTime; 
    CAN_ID_LIDAR_SPEED    =    0x240,    //    LidarSpeed:  bits0-7: SpeedForward; bits8-15: SpeedRight; bits16-23: AngularSpeedLeft; bits24-31: SpeedForwardConfidence; bits32-39: SpeedRightConfidence; bits40-47: AngularSpeedLeftConfidence; bits48-55: MeanSquaredError; bit56: SpeedsInvalid; bits57-63: Reserved;
    CAN_ID_LIDAR_LAT    =    0x241,    //    LidarLatitude:  bits0-35: Latitude; bits36-43: LatitudeConfidence; bit44: LatitudeInvalid; bits45-61: Reserved; bits62-63: LiDarMsgSync;
    CAN_ID_LIDAR_LONG    =    0x242,    //    LidarLongitude:  bits0-35: Longitude; bits36-43: LateralStdDev; bit44: LongUnavailable; bit45: LateralInfStdDev; bits46-61: Reserved; bits62-63: sync; 
    CAN_ID_LIDAR_HEADING    =    0x243,    //    LidarHeading:  bits0-15: CompassHeading; bits16-23: HeadingStdDev; bits24-31: MeanSquaredError; bit32: HeadingUnavailable; bit33: HeadingInfStdDev; bits34-39: reserved; bits40-55: timeStamp; bits56-58: reserved1; bits59-61: msgVersion; bits62-63: sync; 
    CAN_ID_CAMERA_LAT    =    0x245,    //    CameraLatitude:  bits0-35: Latitude; bits36-43: ForwardStdDev; bit44: LatUnavailable; bit45: ForwardInfStdDev; bits46-53: Delay; bits54-61: Reserved; bits62-63: sync; 
    CAN_ID_CAMERA_LONG    =    0x246,    //    CameraLongitude:  bits0-35: Longitude; bits36-43: LateralStdDev; bit44: LongUnavailable; bit45: LateralInfStdDev; bits46-61: Reserved; bits62-63: sync; 
    CAN_ID_CAMERA_HEADING    =    0x247,    //    CameraHeading:  bits0-15: CompassHeading; bits16-23: HeadingStdDev; bits24-31: MeanSquaredError; bit32: HeadingUnavailable; bit33: HeadingInfStdDev; bits34-39: reserved; bits40-55: timeStamp; bits56-58: reserved1; bits59-61: msgVersion; bits62-63: sync; 
    CAN_ID_UWB_DISTANCE    =    0x250,    //  uwb distance byte0: id (7bits) rear uwb (1bit); byte2-4: distance (20bits) unit (mm); byte5-7: (uint24)timestamp
    CAN_ID_UWB_LAT    =    0x251,    //  uwb lat. byte0: id (7bits) rear uwb (1bit); byte2-6: lat. (unused)
    CAN_ID_UWB_LONG    =    0x252,    //  uwb lon. byte0: id (7bits) rear uwb (1bit); byte2-6: lon. (unused)
    CAN_ID_COMPASS    =    0x260,    //  compass byte0-1: heading; byte2-4: (uint24)timestamp
    CAN_ID_LIDAR_OFFSET    =    0x270,    //    LidarOffset:  bits0-13: literalDiff; bit14: reserved; bit15: literalValid; bits16-29: headingDiff; bit30: headingValid; 
    CAN_ID_CAMERA_OFFSET    =    0x271,    //    CameraOffset:  bits0-13: literalDiff; bit14: reserved; bit15: literalValid; bits16-29: headingDiff; bit30: headingValid; 
    CAN_ID_STEERING    =    0x280,    //	observed front steering byte0-1: (int16)steering angle - 0.01degree; byte2: opeartion status; byte3: heartbeat; byte5-7: (uint24) timestamp
    CAN_ID_STEERING2    =    0x281,    //	observed back steering byte0-1: (int16)steering angle - 0.01degree; byte2: opeartion status; byte3: heartbeat; byte5-7: (uint24) timestamp
    CAN_ID_MOTOR1    =    0x290,    //	observed master motor speed byte0-1: (int16)speed - 0.01rad/s; byte2: (int8)motor temp - degree; byte3: (int8)control temp - degree
    CAN_ID_MOTOR2    =    0x291,    //	(NOT used in LIFT) observed slave motor speed byte0-1: (int16)speed - 0.01rad/s; byte2: (int8)motor temp - degree; byte3: (int8)control temp - degree
    CAN_ID_MOTOR3_STATUS1    =    0x295,    //    Motor3Status1:  
    CAN_ID_MOTOR3_STATUS2    =    0x296,    //    Motor3Status2:  bits0-15: current; bits16-31: voltage; bits32-47: actualTorque; bits48-55: count; bits56-59: reserved; bits60-61: dampEnable; bits62-63: lameStatus; 
    CAN_ID_PARK_BRAKE_REQ    =    0x2B0,    //  park brake request byte0
    CAN_ID_PARK_BRAKE1_RESP    =    0x2B5,    //  park brake 1 response byte0: brake status; byte1: operational mode; byte2: error
    CAN_ID_PARK_BRAKE2_RESP    =    0x2B6,    //  park brake 2 response byte0: brake status; byte1: operational mode; byte2: error
    CAN_ID_FUSION_ACCE    =    0x2C0,    //	fusion acceleration byte0-1: longitudinal acce. -20 to + 20m/s2, 0.01 resolution; byte2-3: lateral acce. -20 to + 20m/s2, 0.01 resolution; byte5-7: (uint24) timestamp
    CAN_ID_DEVIATION_REQ    =    0x2C5,    //    DeviationReqMsg:  
    CAN_ID_DYNAMIC_TRACK_VALIDATION    =    0x300,    //    DynamicTrackValidationMsg:  
    CAN_ID_CONFIG_REQ    =    0x310,    //	parameter request command byte0-1: parameter ID, bit15: read flag; byte2-5: parameter set value; byte6: writeAll flag
    CAN_ID_CONFIG_RESP    =    0x311,    //	parameter response command byte0-1: parameter ID, byte2-5: parameter read value
    CAN_ID_VERSION_REQ    =    0x312,    //  version number request byte0-1: unit ID
    CAN_ID_VERSION_RESP    =    0x313,    //  version number response byte0-1: unit ID; byte2: major number; byte3: minor number; byte4-7: git commit
    CAN_ID_BL_VERSION_RESP    =    0x314,    //  bootloader version number response byte0-1: unit ID; byte2: major number; byte3: minor number; byte4-7: git commit
    CAN_ID_OCAN_DBC_VERSION    =    0x315,    //    OcanDBCVersionMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_PCAN_DBC_VERSION    =    0x316,    //    PcanDBCVersionMsg:  bits0-15: id; bits16-22: major; bit23: debug; bits24-31: minor; bits32-63: build; 
    CAN_ID_PARAMETER_CONF_SIGN    =    0x317,    //    ParameterConfSignMsg:  bits0-14: id; bit15: read; bits16-47: value; bit48: writeToMRAM; 
    CAN_ID_CONFIG_SIGN_RESP    =    0x318,    //    ConfigSignResp:  bits0-15: id; bits16-47: value; 
    CAN_ID_STATUS_REQ    =    0x320,    //	change driving controller mode byte0: mode value; byte1: drive path; byte2-3: max. driving speed; byte7: error check (bit61); use Lidar (bit62); use Ultra Sound (bit63)
    CAN_ID_DRIVE_INFO    =    0x321,    //  drive info byte0-1: current waypoint (bit0-11); byte1: drive path (bit12-15); byte2-3: max. driving speed; byte4-5: error distance to path - 0.0001m step; byte7: error check (bit61); use Lidar (bit62); use Ultra Sound (bit63)
    CAN_ID_BMS_STARTUP_STATUS    =    0x322,    //  BMS and startup statu byte0 bit0: BMS ready bit; byte1: startup status
    CAN_ID_LOADING_REQ    =    0x323,    //	loading mode request byte0-1: max. steering angle; byte1 bit0: direction; byte1 bit1: single/dual axis steering
    CAN_ID_SECURITY_SPEED    =    0x324,    //    SecuritySpeedMsg:  bits0-15: maxSpeed; 
    CAN_ID_DRIVE_INFO_LONG_WP    =    0x325,    //    DriveInfoLongWpMsg:  bits0-15: waypoint; bits16-31: maxSpeed; bits32-47: errorDistance; bits48-53: mode; bit54: brake; bit55: reverse; bits56-59: path; bit60: leftDrive; bit61: errorCheck; bit62: useLidar; bit63: useUltrasound; 
    CAN_ID_STOP_REQ    =    0x326,    //    StopReqMsg:  
    CAN_ID_OBS_TIED_MARGIN    =    0x327,    //    ObsTiedMarginMsg:  bits0-7: shrinkTime; bit8: left; bit9: right; 
    CAN_ID_DRIVE_INFO500K_WP    =    0x328,    //    DriveInfo500kWpMsg:  bits0-18: waypoint; bits19-23: reserved; bits24-31: maxSpeed; bits32-47: errorDistance; bits48-53: mode; bit54: brake; bit55: reverse; bits56-59: path; bit60: leftDrive; bit61: errorCheck; bit62: useLidar; 
    CAN_ID_EHB_STATUS    =    0x330,    //  hydraulic brake status byte0: bit0 status; byte0: bit1 Parking Request; byte1: pressure; byte2: bit6-7 brake condition; byte3: Brake Pedal Travel; byte4: bit0-3 EHB fault level; byte6: bit0-3 counter; byte7: checksum
    CAN_ID_EHB_PWR_STATUS    =    0x331,    //  hydraulic brake power status byte1: current; byte2: voltage; byte6: bit0-3 counter; byte7: checksum
    CAN_ID_EHB_T060POWER    =    0x332,    //    EHBT060PowerMsg:  bits0-7: reserved; bits8-15: voltage; bits16-21: s16_ADC; bits22-27: reserved1; bits28-31: cylinderPosition; bits32-35: reserved2; bits36-39: counter; bits40-43: reserved3; bits44-51: checksum; 
    CAN_ID_EPB_RELEASE    =    0x340,    //	park brake release command byte0: 0xAA fixed value; byte1: 0x02 fixed value
    CAN_ID_BATTERY    =    0x400,    //  battery value byte0-1: main power (0.1v); byte2: controller (0.1v); byte3: steering front (0.1v); byte4: steering rear (0.1v)
    CAN_ID_LIVE_UPDATE_REQ    =    0x410,    //  Live Update request  byte0-1: unit ID
    CAN_ID_LIVE_UPDATE_ACK    =    0x411,    //  Live Update ACK byte0-1: unit ID; byte2: ACK/NAK
    CAN_ID_LIVE_UPDATE_DATA    =    0x420,    //  PIC Live Update protocol
    CAN_ID_LIVE_UPDATE_RESP    =    0x421,    //  PIC Live Update response protocol
    CAN_ID_ATMEL_UPDATE_REQ    =    0x422,    //    AtmelUpdateReqMsg:  bits0-7: action; bits8-23: address; bits24-55: data; bits56-63: checksum; 
    CAN_ID_ATMEL_UPDATE_RESP    =    0x423,    //    AtmelUpdateRespMsg:  bits0-7: action; bits8-23: address; bits24-31: ACK; bits32-39: major; bits40-47: minor; bits48-63: checksum; 
    CAN_ID_F_SIGNAL_REQ    =    0x510,    //  front signal request byte0: front left indicator; byte1: front right indicator; byte2: front brake light
    CAN_ID_R_SIGNAL_REQ    =    0x511,    //  rear signal request byte0: rear left indicator; byte1: rear right indicator; byte2: rear brake light
    CAN_ID_F_SIGNAL_STATUS    =    0x520,    //  front signal status byte0: front left indicator; byte1: front right indicator; byte2: front brake light
    CAN_ID_R_SIGNAL_STATUS    =    0x521,    //  rear signal status byte0: rear left indicator; byte1: rear right indicator; byte2: rear brake light
    CAN_ID_FRONT_RIGHT_INDICATOR_LIGHT_REQ    =    0x530,    //    FrontRightIndicatorLightReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_RIGHT_INDICATOR_LIGHT_STATUS    =    0x531,    //    FrontRightIndicatorLightStatusMsg:  bits0-7: on; 
    CAN_ID_FRONT_LEFT_INDICATOR_LIGHT_REQ    =    0x540,    //    FrontLeftIndicatorLightReqMsg:  bits0-7: on; 
    CAN_ID_FRONT_LEFT_INDICATOR_LIGHT_STATUS    =    0x541,    //    FrontLeftIndicatorLightStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_BRAKE_LIGHT_REQ    =    0x550,    //    RearBrakeLightReqMsg:  bits0-7: on; 
    CAN_ID_REAR_BRAKE_LIGHT_STATUS    =    0x551,    //    RearBrakeLightStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_RIGHT_INDICATOR_LIGHT_REQ    =    0x560,    //    RearRightIndicatorLightReqMsg:  bits0-7: on; 
    CAN_ID_REAR_RIGHT_INDICATOR_LIGHT_STATUS    =    0x561,    //    RearRightIndicatorLightStatusMsg:  bits0-7: on; 
    CAN_ID_REAR_LEFT_INDICATOR_LIGHT_REQ    =    0x570,    //    RearLeftIndicatorLightReqMsg:  bits0-7: on; 
    CAN_ID_REAR_LEFT_INDICATOR_LIGHT_STATUS    =    0x571,    //    RearLeftIndicatorLightStatusMsg:  bits0-7: on; 
    CAN_ID_MOTOR3_STATUS3    =    0x580,    //    Motor3Status3:  bits0-3: HWVersionMinorL; bits4-7: HWVersionMinorH; bits8-11: HWVersionMajor; bits12-15: reserved; bits16-19: SWVersionMinorL; bits20-23: SWVersionMinorH; bits24-27: SWVersionMajor; bits28-31: vehicleInfo; bits32-38: SWReleaseYear; bits39-43: SWReleaseDate; bits44-47: SWReleaseMonth; bits48-55: energyDeviceAddr; bits56-63: programCode; 
    CAN_ID_MOTOR3_STATUS4    =    0x581,    //    Motor3Status4:  bits0-15: productionUniqueNo; bits16-31: factoryNo; bits32-38: manufactureYear; bits39-43: manufactureDate; bits44-47: manufactureMonth; bits48-55: deviceAddr; 
    CAN_ID_MOTOR3_STATUS5    =    0x582,    //    Motor3Status5:  bits0-11: initAngleBeforeAdjust; bits12-13: AdjustResult; bits14-15: reserved; bits16-27: initAngleaAfterAdjust; 
    CAN_ID_MOTOR3_STATUS6    =    0x583,    //    Motor3Status6:  bits0-19: forwardCumulativeCharge; bits20-39: reverseCumulativeCharge; bits40-51: positiveCumulativePower; bits52-63: reverseCumulativePower; 
    CAN_ID_BMS_STATUS_STD    =    0x584,    //    BMSStatusStdMsg:  bits0-15: maxDischargeCurrent; bits16-31: maxChargeCurrent; bits32-39: soc; bits40-47: maxBattVolt; bits48-55: count; bits56-61: reserved; bits62-63: errorLevel; 
    CAN_ID_REMOTE_SIGNAL    =    0x590,    //    RemoteSignalMsg:  bits0-15: id; bit16: startBtn; bit17: emergencyBtn; bit18: horn; bit19: overtake; 
    CAN_ID_EXT_OBS_LOC    =    0x5A0,    //    ExtObsLocMsg:  bits0-15: id; bits16-37: x; bits38-59: y; bit60: cleared; 
    CAN_ID_EXT_OBS_SPEED    =    0x5A1,    //    ExtObsSpeedMsg:  bits0-15: id; bits16-23: speed; bits24-32: heading; 
    CAN_ID_SYS_ERROR_REPORT    =    0x600,    //  report system error code byte0: unit id; byte1: error type; byte2-5: error code
    CAN_ID_SECURITY_WARNING    =    0x60A,    //    SecurityWarningMsg:  bit0: collisionCommsDelay; bit1: collisionCommsMissing; 
    CAN_ID_FILE_TRANSFER    =    0x610,    //	file transfer byte0-1: sender id; byte2-3: receiver id; byte4: action; byte5: meaning; byte6-7: extra data
    CAN_ID_FILE_ACK    =    0x611,    //	file ACK byte0-1: sender id; byte2-3: receiver id; byte4: ACK/NAK; byte5: error code
    CAN_ID_DATA_TRANSFER    =    0x612,    //	data transfer byte0: index; byte1-6: data; byte7: checksum
    CAN_ID_DATA_ACK    =    0x613,    //	data ACK byte0-1: sender id; byte2-3: receiver id; byte4: ACK/NAK; byte5: error code; byte6: index
    CAN_ID_IMU_ROT    =    0x621,    //    IMURot:  bits0-15: pitch; bits16-31: roll; bits32-47: heading; bits48-59: accuracy; bits60-61: status; bits62-63: sync; 
    CAN_ID_IMU_ACC    =    0x622,    //    IMUAcc:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-49: status; bits50-61: reserved; bits62-63: sync; 
    CAN_ID_IMU_GYR    =    0x623,    //    IMUGyr:  bits0-15: x; bits16-31: y; bits32-47: z; bits48-55: temperature; bits56-57: status; bits58-61: unused; bits62-63: sync; 
    CAN_ID_IMU_STATUS    =    0x624,    //    IMUStatus:  bits0-31: status; bits32-47: warnings; bits48-59: heading; bit60: heading_available; 
    CAN_ID_CONNECT_WP    =    0x630,    //    ConnectWp:  bits0-18: startWp; bits19-37: endWp; bits38-39: startTrack; bits40-41: endTrack; bits42-44: type; bits45-47: distanceWpForCurved; bit48: restore; 
    CAN_ID_MANAGE_CTRL    =    0x650,    //	management control data byte0-1: destination; byte2-3: control type; byte5-7: (uint24) timestamp
    CAN_ID_MANAGE_ACK    =    0x651,    //	management ACK command byte0: identifier; byte1-4: error code or NAK; byte5-7: (uint24) timestamp
    CAN_ID_MANAGE_TRACK    =    0x652,    // 	management track data byte0 bit0-3: ID; byte0-8 bits 4-63: data
    CAN_ID_DRIVE_CTRL_DATA    =    0x660,    //	drive controller control data byte0-1: destination; byte2-3: control type; byte5-7: (uint24) timestamp
    CAN_ID_DRIVE_ACK    =    0x661,    //	drive controller ACK command byte0: identifier; byte1-4: error code or NAK; byte5-7: (uint24) timestamp
    CAN_ID_DRIVE_TRACK    =    0x662,    // 	drive controller track data byte0 bit0-3: ID; byte0-8 bits 4-63: data
    CAN_ID_MD5_REQ    =    0x663,    //	drive controller MD5 request byte0-1: unit ID; byte2: drive path
    CAN_ID_PLAT_START_TX    =    0x664,    //    platStartTxMsg:  bits0-7: mode; bits8-15: path; bits16-23: speed; bits24-31: checksum; 
    CAN_ID_MD5_RESP    =    0x673,    //	MD5 response byte0-7: unit ID XOR MD5
    CAN_ID_PLAT_START_RX    =    0x674,    //    platStartRxMsg:  bits0-7: mode; bits8-15: path; bits16-23: speed; bits24-31: checksum; 
    CAN_ID_CALIBRATION    =    0x680,    //	steering calibration byte0-1: steering angle (int16)steering angle - 0.01degree; byte 2: set bits
    CAN_ID_STEER_CONFIG    =    0x681,    //  steering configuration byte0-1: unit ID
    CAN_ID_STEER_ID_REQUEST    =    0x682,    //  steering ID request byte0: 0xAA(fixed value)
    CAN_ID_STEER_ID_RESPONSE    =    0x683,    //  steering ID response byte0-1: unit ID
    CAN_ID_STEER_REQUEST    =    0x690,    //	steering value request byte0-1: front steering angle (int16)steering angle - 0.01degree; byte2-3: rear steering angle (int16)steering angle - 0.01degree
    CAN_ID_ODOMETER    =    0x700,    //    OdometerMsg:  bits0-31: value; 
    CAN_ID_ODOMETRY_PARAMETERS    =    0x701,    //    OdometryParameters:  bits0-7: FrontOffset; bits8-15: FrontScale; bits16-23: RearOffset; bits24-31: RearScale; bits32-39: WheelSpeedScale; bits40-53: startupCount; bits54-63: adaptiveCount; 
    CAN_ID_OBSTACLE_PC_WARNING    =    0x707,    //    ObstaclePcWarning:  bit0: ObsFrontTopLidarDetectingBody; bit1: ObsRearTopLidarDetectingBody; bit2: ObsFrontTopLidarSectionMissing; bit3: ObsFrontRightLidarSectionMissing; bit4: ObsFrontLeftLidarSectionMissing; bit5: ObsRearTopLidarSectionMissing; bit6: ObsRearRightLidarSectionMissing; bit7: ObsRearLeftLidarSectionMissing; bit8: ObsFrontTopLidarCalibration; bit9: ObsFrontRightLidarCalibration; bit10: ObsFrontLeftLidarCalibration; bit11: ObsRearTopLidarCalibration; bit12: ObsRearRightLidarCalibration; bit13: ObsRearLeftLidarCalibration; bit14: ObsKeyframeSaverError; bit15: ObsOdometryTimeout; bit16: ObsKeyframeLoaderDatabaseError; bit17: ObsKeyframeLoaderVersionError; 
    CAN_ID_VEHICLE_VIN    =    0x708,    //    VehicleVIN:  
    CAN_ID_LOG_INDICATOR    =    0x710,    //  start/stop black box logging byte0: bit 0
    CAN_ID_DRIVE_DEBUG_Ex    =    0x711,    //    DriveDebugMsg:  
    CAN_ID_PLAT_DEBUG    =    0x712,    //    PlatDebugMsg:  bits0-7: abortReason; 
    CAN_ID_STOP_DEBUG    =    0x713,    //    StopDebugMsg:  bits0-3: ClosestStop; bits4-7: reserved; bits8-11: trafficEventState; bits12-15: junctionManualEventState; bits16-31: closestDistance2Stop; bits32-47: trafficDistance2Stop; bits48-63: junctionManualDistance2Stop; 
    CAN_ID_FOOT1_DEBUG    =    0x718,    //    Foot1DebugMsg:  
    CAN_ID_FOOT2_DEBUG    =    0x719,    //    Foot2DebugMsg:  
    CAN_ID_EPB_DEBUG    =    0x71C,    //    EPBDebugMsg:  
    CAN_ID_DRIVE_DEBUG    =    0x720,    //  debug message byte0-1: shortest distance from ultra sound unit (mm); byte2-3: shortest obstacle distance (mm); byte7: bit63 hand brake status
    // Follows FusionFlagsMsg_t. OhmioLibraries_36 labels bit34 no_engine_state and reserves bits35-39.
    CAN_ID_FUSION_FLAGS    =    0x724,    //    FusionFlagsMsg:  bit0: fus_internal_reset; bit1: init_failed; bit2: front_steer_invalid; bit3: rear_steer_invalid; bit4: speed_invalid; bit5: time_step_size_invalid; bit6: lidar_slam_stddev_nonpositive; bit7: cam_slam_stddev_nonpositive; bit8: motor_comms; bit9: front_steer_comms; bit10: rear_steer_comms; bit11: veh_cholesky_failed; bit12: veh_innovation_cov_not_psd; bit13: veh_nonpositive_variance; bit14: veh_nan_or_inf; bit15: odo_cholesky_failed; bit16: odo_innovation_cov_not_psd; bit17: odo_nonpositive_variance; bit18: odo_nan_or_inf; bit19: drv_req_comms; bit20: front_wheel_speed_comms; bit21: rear_wheel_speed_comms; bit22: conflicting_inputs; bit23: saved_antenna_offset_missing; bit24: huge_sensor_update; bit25: safety_relay_open; bit26: drv_info_comms_error; bit27: w_front_gnss_no_data_ubx; bit28: w_rear_gnss_no_data; bit29: w_odometry_suspicious; bit30: w_gnss_antennas_out_of_range; bit31: w_no_gnss_period_estimate; bit32: w_front_gnss_comms; bit33: w_rear_gnss_comms; bit34: w_no_engine_state; bit35: w_large_gnss_delay; bit36: w_large_lidar_delay; bits37-39: reserved1; bit40: st_lidar_slam_no_data_can; bit41: st_lidar_slam_no_kf; bit42: st_cam_slam_no_data_can; bit43: st_cam_slam_no_kf; bits44-45: reserved2; bit46: st_using_front_gnss; bit47: st_using_rear_gnss; bit48: st_using_lidar_slam; bit49: st_using_cam_slam; bit50: st_using_imu_heading; bit51: reserved3; bit52: st_dead_reckoning; bits53-54: reserved4; bit55: st_external_reset; 
    CAN_ID_ERROR_FUSION_DEBUG    =    0x725,    //    ErrorFusionDebugMsg:  bit0: fusdebugReset; bit1: initialisation; bit2: steerAngleFrontInvalid; bit3: steerAngleRearInvalid; bit4: wheelSpeedInvalid; bit5: timeStepSizeInvalid; bit6: huge_sensor_update; bits7-8: reserved; bit9: speedNotAvailableButNotZero; bit10: slamFwdStdDevNonPositive; bit11: slamLatStdDevNonPositive; bit12: slamHeadStdDevNonPositive; bit13: fusionConflictingInputs; bit14: saved_antenna_offset_missing; bit15: safety_relay_open; bit16: drive_info_comms; bits17-31: reserved1; bit32: cholesky_failed_veh; bit33: innovation_covariance_not_psd_veh; bit34: choleskey_failed_odo; bit35: innovation_convariance_not_psd_odo; bit36: steer_angle_front_unavailable; bit37: steer_angle_rear_unavailable; bit38: rtk_front_no_data_ubx; bit39: rtk_rear_no_data_ubx; bit40: rtk_front_no_data_can; bit41: rtk_rear_no_data_can; bit42: dead_reckoning; bit43: odometry_suspicious; bit44: reserved2; bit45: gnss_antennas_out_of_range; bit46: using_lidar_slam; bit47: using_gps; bit48: fusion_initialisable; 
    CAN_ID_IMU_MAG    =    0x727,    //    IMUMag:  bits0-19: x; bits20-39: y; bits40-59: z; bits60-61: reserved; bits62-63: sync; 
    CAN_ID_FUSION_PERSISTENT_PARAMS    =    0x728,    //    FusionPersistentParams:  
    CAN_ID_NET_COMMS    =    0x73D,    //    NetCommsMsg:  
    CAN_ID_WHEEL_SPEED_EVENTS    =    0x740,    //    WheelSpeedEvents:  bits0-19: first_edge_offset; bit20: first_edge_direction; bits21-40: second_edge_offset; bit41: second_edge_direction; bits42-61: third_edge_offset; bit62: third_edge_direction; bit63: overflow; 
    CAN_ID_PLATOON_SIM    =    0x751,    //    PlatoonSimMsg:  bits0-31: speed; bits32-63: subWaypoint; 
    CAN_ID_FUSION_EXCEPTION    =    0x765,    //    fusionExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; 
    CAN_ID_LOC_ASSERT    =    0x7A0,    //    LocAssertMsg:  
    CAN_ID_DRV_ASSERT    =    0x7A1,    //    DrvAssertMsg:  
    CAN_ID_MANUAL_ASSERT    =    0x7A4,    //    ManualAssertMsg:  
    CAN_ID_FUS_ASSERT    =    0x7A5,    //    FusAssertMsg:  
    CAN_ID_EPB1_ASSERT    =    0x7AC,    //    Epb1AssertMsg:  
    CAN_ID_EPB2_ASSERT    =    0x7AD,    //    Epb2AssertMsg:  
    CAN_ID_STARTUP_ASSERT    =    0x7B3,    //    StartupAssertMsg:  
    CAN_ID_SECURITY_ASSERT    =    0x7BA,    //    SecurityAssertMsg:  
    CAN_ID_FRONT_WHEEL_EXCEPTION    =    0x7C0,    //    frontWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; 
    CAN_ID_REAR_WHEEL_EXCEPTION    =    0x7C1,    //    rearWheelExceptionMsg:  bits0-31: ex_addr; bits32-36: ex_code; bits37-39: reserved; bits40-47: user_flag; 
    CAN_ID_PRINT_MESSAGE    =    0x7F0,    //	printable ASCII code byte0: unit ID; byte1-7: ASCII characters
    CAN_ID_EMULATOR_LAT    =    0x7F2,    //    EmulatorLatitudeMsg:  bits0-34: latitude; bit35: sign; bit36: outlier; bits37-39: reserved; bits40-63: time; 
    CAN_ID_EMULATOR_LONG    =    0x7F3,    //    EmulatorLongitude:  bits0-34: longitude; bit35: sign; bits36-39: quality; bits40-63: time; 
    CAN_ID_EMULATOR_HEADING    =    0x7F4,    //    EmulatorHeadingMsg:  bits0-15: heading; 
} COMMON_CAN;


// the modules using CAN 
// Anywhere in your code using this enum put 
// static_assert(26 == LAST_UNIT_ID, "UNIT_ID changed"); // for C++
// _Static_assert(26 == LAST_UNIT_ID, "UNIT_ID changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    LOCALISATION_ID    =    0x00,
    DRIVE_CTRL_ID    =    0x01,
    FRONT_STEERING_ID    =    0x02,
    REAR_STEERING_ID    =    0x03,
    MANUAL_CTRL_ID    =    0x04,
    FUSION_ID    =    0x05,
    BLACK_BOX_ID    =    0x06,
    OBSTACLE_DETECTION_PC    =    0x07,
    LEFT_MOTOR_ID    =    0x08,
    RIGHT_MOTOR_ID    =    0x09,
    FRONT_BRAKE_ID    =    0x0A,
    REAR_BRAKE_ID    =    0x0B,
    PARK_BRAKE1_ID    =    0x0C,
    PARK_BRAKE2_ID    =    0x0D,
    FRONT_SIGNAL_ID    =    0x0E,
    REAR_SIGNAL_ID    =    0x0F,
    LIGHT_CTRL1_ID    =    0x10,
    LIGHT_CTRL2_ID    =    0x11,
    SAFETY_ID    =    0x12,
    START_UP_CTRL_ID    =    0x13,
    ATMEL_LOC_ID    =    0x14,
    ATMEL_DRIVE_ID    =    0x15,
    ATMEL_MANUAL_ID    =    0x16,
    ATMEL_FUSION_ID    =    0x17,
    FOOTING1_ID    =    0x18,
    FOOTING2_ID    =    0x19,
    SECURITY_ID    =    0x1A,
    MANAGEMENT_PC    =    0x1B,
    ATMEL_SECURITY_ID    =    0x1C,
    NETWORK_ID    =    0x1D,
    ACCESSORY1_ID    =    0x1E,
    ACCESSORY2_ID    =    0x1F,
    FRONT_WHEEL_ID    =    0x20,
    REAR_WHEEL_ID    =    0x21,
    MGT_INTERFACE_ID    =    0x22,
    DBC_ID    =    0x23,
    DRIVE_EXT_ID    =    0x24,
    FUSION_20MS_ID    =    0x25,
    TRANSLATOR_ID    =    0x26,
    TRANSLATOR2_ID    =    0x27,
    TELEOP_ID    =    0x28,
    ATMEL_TELEOP_ID    =    0x29,
    JOYSTICK_ID    =    0x2A,

    // Always add BEFORE this line
    LAST_UNIT_ID
} UNIT_ID;


// the set of ATMEL RESET 
// Anywhere in your code using this enum put 
// static_assert(0x09 == NUMBER_OF_ATMEL_RESET, "ATMEL RESET changed"); // for C++
// _static_assert(0x09 == NUMBER_OF_ATMEL_RESET, "ATMEL RESET changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    ATMEL_NONE    =    0x00,
    ATMEL_POWERON    =    0x01,
    ATMEL_EXTERNAL    =    0x02,
    ATMEL_BROWNOUT    =    0x04,
    ATMEL_WATCHDOG    =    0x08,

    /* number of mode in total */
    NUMBER_OF_ATMEL_RESET,
} ATMEL_RESET;

// the set of BOOT ACTION 
// Anywhere in your code using this enum put 
// static_assert(0x08 == NUMBER_OF_BOOT_ACTION, "BOOT ACTION changed"); // for C++
// _static_assert(0x08 == NUMBER_OF_BOOT_ACTION, "BOOT ACTION changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    BOOT_INFO    =    0x00,
    BOOT_ERASE    =    0x01,
    BOOT_WRITE    =    0x02,
    BOOT_VERIFY    =    0x03,
    BOOT_JUMP_TO_APP    =    0x04,
    BOOT_EXIT    =    0x05,
    BOOT_ENCRYPT_KEY    =    0x06,
    BOOT_DEVICE_ID    =    0x07,

    /* number of mode in total */
    NUMBER_OF_BOOT_ACTION,
} BOOT_ACTION;

// the set of CONNECT TRACK TYPE 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_CONNECT_TRACK_TYPE, "CONNECT TRACK TYPE changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_CONNECT_TRACK_TYPE, "CONNECT TRACK TYPE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    CONNECT_STRAIGHT    =    0x00,
    CONNECT_CURVED    =    0x01,
    CONNECT_PARALLEL_NOT_IMPLEMENTED    =    0x02,

    /* number of mode in total */
    NUMBER_OF_CONNECT_TRACK_TYPE,
} CONNECT_TRACK_TYPE;

// the set of EPB ERROR 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_EPB_ERROR, "EPB ERROR changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_EPB_ERROR, "EPB ERROR changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    EPB_NO_ERROR    =    0x00,
    EPB_TIMEOUT    =    0x01,
    EPB_RESET    =    0x02,

    /* number of mode in total */
    NUMBER_OF_EPB_ERROR,
} EPB_ERROR;

// the set of EPB MODE 
// Anywhere in your code using this enum put 
// static_assert(0x05 == NUMBER_OF_EPB_MODE, "EPB MODE changed"); // for C++
// _static_assert(0x05 == NUMBER_OF_EPB_MODE, "EPB MODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    EPB_STARTUP    =    0x00,
    EPB_ENGAGING    =    0x01,
    EPB_DISENGAGING    =    0x02,
    EPB_IDLE    =    0x03,
    EPB_STOPPING    =    0x04,

    /* number of mode in total */
    NUMBER_OF_EPB_MODE,
} EPB_MODE;

// the set of EPB REQUEST 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_EPB_REQUEST, "EPB REQUEST changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_EPB_REQUEST, "EPB REQUEST changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    EPB_NO_REQ    =    0x00,
    EPB_ENGAGE_REQ    =    0x01,
    EPB_DISENGAGE_REQ    =    0x02,

    /* number of mode in total */
    NUMBER_OF_EPB_REQUEST,
} EPB_REQUEST;

// the set of EPB STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_EPB_STATUS, "EPB STATUS changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_EPB_STATUS, "EPB STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    EPB_UNKNOWN    =    0x00,
    EPB_ENGAGED    =    0x01,
    EPB_DISENGAGED    =    0x02,
    EPB_STOPPED    =    0x03,

    /* number of mode in total */
    NUMBER_OF_EPB_STATUS,
} EPB_STATUS;

// the set of ERROR TYPE 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_ERROR_TYPE, "ERROR TYPE changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_ERROR_TYPE, "ERROR TYPE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    ERROR_CURRENT    =    0x00,
    ERROR_INITIAL    =    0x01,
    ERROR_ACCUMULATED    =    0x02,

    /* number of mode in total */
    NUMBER_OF_ERROR_TYPE,
} ERROR_TYPE;

// the set of MAX STEER ANGLE 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_MAX_STEER_ANGLE, "MAX STEER ANGLE changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_MAX_STEER_ANGLE, "MAX STEER ANGLE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MAX_ANGLE_5    =    0x00,
    MAX_ANGLE_10    =    0x01,
    MAX_ANGLE_FULL    =    0x02,

    /* number of mode in total */
    NUMBER_OF_MAX_STEER_ANGLE,
} MAX_STEER_ANGLE;

// the set of MOTOR3 CONTROL MODEL 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_MOTOR3_CONTROL_MODEL, "MOTOR3 CONTROL MODEL changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_MOTOR3_CONTROL_MODEL, "MOTOR3 CONTROL MODEL changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_INVALID_MODEL    =    0x00,
    MOTOR3_SPEED    =    0x01,
    MOTOR3_TORQUE_THROTTLE    =    0x02,
    MOTOR3_TORQUE_TORQUE    =    0x03,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_CONTROL_MODEL,
} MOTOR3_CONTROL_MODEL;

// the set of MOTOR3 DAMP CONTROL 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_MOTOR3_DAMP_CONTROL, "MOTOR3 DAMP CONTROL changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_MOTOR3_DAMP_CONTROL, "MOTOR3 DAMP CONTROL changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_INVALID_DAMP_FUNC    =    0x00,
    MOTOR3_NO_DAMP_FUNC    =    0x01,
    MOTOR3_ACTIVE_DAMP_FUNC    =    0x02,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_DAMP_CONTROL,
} MOTOR3_DAMP_CONTROL;

// the set of MOTOR3 DIRECTION 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_MOTOR3_DIRECTION, "MOTOR3 DIRECTION changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_MOTOR3_DIRECTION, "MOTOR3 DIRECTION changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_INVALID_DIR    =    0x00,
    MOTOR3_FORWARD    =    0x01,
    MOTOR3_REVERSE    =    0x02,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_DIRECTION,
} MOTOR3_DIRECTION;

// the set of MOTOR3 ERROR CODE 
// Anywhere in your code using this enum put 
// static_assert(0x3E == NUMBER_OF_MOTOR3_ERROR_CODE, "MOTOR3 ERROR CODE changed"); // for C++
// _static_assert(0x3E == NUMBER_OF_MOTOR3_ERROR_CODE, "MOTOR3 ERROR CODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_OVER_CURRENT    =    0x02,
    MOTOR3_OVER_VOLT    =    0x05,
    MOTOR3_LOW_VOLT    =    0x09,
    MOTOR3_MISS_PHASE    =    0x0D,
    MOTOR3_CTRL_OVER_TEMP    =    0x0E,
    MOTOR3_ZERO_DRIFT_OVER_RANGE    =    0x12,
    MOTOR3_EEPROM_WRITE_ERROR    =    0x15,
    MOTOR3_ROTATION_ERROR    =    0x16,
    MOTOR3_VOLT_OUT_RANGE    =    0x1A,
    MOTOR3_BLOCK_ERROR    =    0x1B,
    MOTOR3_AD_CABLE_MISSING    =    0x1C,
    MOTOR3_PRECHARGE_TIMEOUT    =    0x1D,
    MOTOR3_DRIVE_LOW_VOLT    =    0x20,
    MOTOR3_BMS_VOLT_ERROR    =    0x29,
    MOTOR3_OVER_SPEED    =    0x2A,
    MOTOR3_OVER_TEMP    =    0x2D,
    MOTOR3_CAN_COMMAND_ERROR    =    0x2F,
    MOTOR3_POWERUP_SPEED_ERROR    =    0x30,
    MOTOR3_CAN_COMMS_TIMEOUT    =    0x36,
    MOTOR3_TEMP_SENSOR_MISS    =    0x39,
    MOTOR3_REQ_COUNT_OVERTIME    =    0x3A,
    MOTOR3_OVER_VOLT_CONTACTOR_OFF    =    0x3B,
    MOTOR3_VDC_TOO_LOW    =    0x3D,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_ERROR_CODE,
} MOTOR3_ERROR_CODE;

// the set of MOTOR3 ERROR LEVEL 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_MOTOR3_ERROR_LEVEL, "MOTOR3 ERROR LEVEL changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_MOTOR3_ERROR_LEVEL, "MOTOR3 ERROR LEVEL changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_NO_ERROR    =    0x00,
    MOTOR3_LEVEL1    =    0x01,
    MOTOR3_LEVEL2    =    0x02,
    MOTOR3_INVALID_ERROR    =    0x03,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_ERROR_LEVEL,
} MOTOR3_ERROR_LEVEL;

// the set of MOTOR3 INFO 
// Anywhere in your code using this enum put 
// static_assert(0x0A == NUMBER_OF_MOTOR3_INFO, "MOTOR3 INFO changed"); // for C++
// _static_assert(0x0A == NUMBER_OF_MOTOR3_INFO, "MOTOR3 INFO changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_ELECTRIC    =    0x01,
    MOTOR3_OIL_ELECTRIC    =    0x02,
    MOTOR3_GAS_ELECTRIC    =    0x03,
    MOTOR3_COMPOSITE_PLUG_IN    =    0x04,
    MOTOR3_FUEL    =    0x05,
    MOTOR3_TROLLEYBUS    =    0x06,
    MOTOR3_XCVT    =    0x07,
    MOTOR3_BATTERY_PLUG_IN    =    0x08,
    MOTOR3_ICVT    =    0x09,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_INFO,
} MOTOR3_INFO;

// the set of MOTOR3 LAME CONTROL 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_MOTOR3_LAME_CONTROL, "MOTOR3 LAME CONTROL changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_MOTOR3_LAME_CONTROL, "MOTOR3 LAME CONTROL changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_NO_FAULT    =    0x00,
    MOTOR3_ALLOW_LAME    =    0x01,
    MOTOR3_NOT_ALLOW_LAME    =    0x02,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_LAME_CONTROL,
} MOTOR3_LAME_CONTROL;

// the set of MOTOR3 MODE 
// Anywhere in your code using this enum put 
// static_assert(0x0D == NUMBER_OF_MOTOR3_MODE, "MOTOR3 MODE changed"); // for C++
// _static_assert(0x0D == NUMBER_OF_MOTOR3_MODE, "MOTOR3 MODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    MOTOR3_D_POSITION    =    0x01,
    MOTOR3_POWER_GENERATION    =    0x02,
    MOTOR3_N_POSITION    =    0x03,
    MOTOR3_RESET    =    0x04,
    MOTOR3_H_VOLT_EMG_BREAK    =    0x05,
    MOTOR3_SHUTDOWN    =    0x06,
    MOTOR3_ANTI_SLIP    =    0x09,
    MOTOR3_CRUISE_SPEED    =    0x0A,
    MOTOR3_CREEP    =    0x0B,
    MOTOR3_LOCKED    =    0x0C,

    /* number of mode in total */
    NUMBER_OF_MOTOR3_MODE,
} MOTOR3_MODE;

// the set of PARAMETER ID 
// Anywhere in your code using this enum put 
// static_assert(0x91 == NUMBER_OF_PARAMETER_ID, "PARAMETER ID changed"); // for C++
// _static_assert(0x91 == NUMBER_OF_PARAMETER_ID, "PARAMETER ID changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    PARAMETER_MIN_SPEED_DEC_STEP_DRIVE    =    0x01,
    PARAMETER_LOCATION_FILTER_LENGTH    =    0x02,
    PARAMETER_DISTANCE_BETWEEN_WAYPOINTS    =    0x03,
    PARAMETER_CURVE_IMPROVEMENT    =    0x04,
    PARAMETER_RIGHT_HAND_DRIVE    =    0x05,
    PARAMETER_REQUEST_ACCEPT_STOP_DIST    =    0x06,
    PARAMETER_MANUAL_STEER_FIL    =    0x07,
    PARAMETER_SPEED_INC_STEP_MANUAL    =    0x08,
    PARAMETER_MAX_SPEED    =    0x09,
    PARAMETER_STEER_DELTA    =    0x0A,
    PARAMETER_LOOK_AHEAD_DIST    =    0x0B,
    PARAMETER_MIN_LOOK_AHEAD_DIST    =    0x0C,
    PARAMETER_WHEEL_RADIUS    =    0x83,
    PARAMETER_HEADING_KP    =    0x84,
    PARAMETER_SPEED_KP    =    0x85,
    PARAMETER_SPEED_KI    =    0x86,
    PARAMETER_BRAKE_KI    =    0x87,
    PARAMETER_SPEED_INC_STEP_DRIVE    =    0x88,
    PARAMETER_STEERING_TYPE    =    0x89,
    PARAMETER_DRIVE_MAX_SPEED    =    0x8A,
    PARAMETER_DRIVE_MIN_SPEED    =    0x8B,
    PARAMETER_OBS_DECELERATION    =    0x8C,
    PARAMETER_ODOMETER    =    0x90,

    /* number of mode in total */
    NUMBER_OF_PARAMETER_ID,
} PARAMETER_ID;

// the set of PATH 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_PATH, "PATH changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_PATH, "PATH changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    PATH_TRACK_1_FORWARD    =    0x00,
    PATH_TRACK_2_FORWARD    =    0x01,
    PATH_TRACK_1_REVERSE    =    0x02,
    PATH_TRACK_2_REVERSE    =    0x03,

    /* number of mode in total */
    NUMBER_OF_PATH,
} PATH;

// the set of PICRESET REASON 
// Anywhere in your code using this enum put 
// static_assert(0x81 == NUMBER_OF_PICRESET_REASON, "PICRESET REASON changed"); // for C++
// _static_assert(0x81 == NUMBER_OF_PICRESET_REASON, "PICRESET REASON changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    PICRESET_NONE    =    0x00,
    PICRESET_BROWNOUT    =    0x02,
    PICRESET_POWERON    =    0x03,
    PICRESET_WDT_TIMEOUT    =    0x10,
    PICRESET_DMT_TIMEOUT    =    0x20,
    PICRESET_CONFIG_MISMATCH    =    0x200,
    PICRESET_ALL    =    0x2F3,
    PICRESET_SOFTWARE    =    0x40,
    PICRESET_MCLR    =    0x80,

    /* number of mode in total */
    NUMBER_OF_PICRESET_REASON,
} PICRESET_REASON;

// the set of RESET PARAMETER 
// Anywhere in your code using this enum put 
// static_assert(0x14 == NUMBER_OF_RESET_PARAMETER, "RESET PARAMETER changed"); // for C++
// _static_assert(0x14 == NUMBER_OF_RESET_PARAMETER, "RESET PARAMETER changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    RESET_RESERVED    =    0x00,
    RESET_FUS_ALL_PARAM    =    0x10,
    RESET_FUS_ANTENNA_DIST    =    0x11,
    RESET_FUS_ODOMETRY    =    0x12,
    RESET_FUS_IMU    =    0x13,

    /* number of mode in total */
    NUMBER_OF_RESET_PARAMETER,
} RESET_PARAMETER;

// the set of STARTUP STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x08 == NUMBER_OF_STARTUP_STATUS, "STARTUP STATUS changed"); // for C++
// _static_assert(0x08 == NUMBER_OF_STARTUP_STATUS, "STARTUP STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    STARTUP_START    =    0x00,
    STARTUP_OP1    =    0x01,
    STARTUP_OP2    =    0x02,
    STARTUP_EMERGENCY    =    0x03,
    STARTUP_RECOVERY    =    0x04,
    STARTUP_SHUTDOWN_REQ    =    0x05,
    STARTUP_SHUTDOWN    =    0x06,
    STARTUP_IDLE    =    0x07,

    /* number of mode in total */
    NUMBER_OF_STARTUP_STATUS,
} STARTUP_STATUS;

// the set of STEER CALIBRATION MODE 
// Anywhere in your code using this enum put 
// static_assert(0x23 == NUMBER_OF_STEER_CALIBRATION_MODE, "STEER CALIBRATION MODE changed"); // for C++
// _static_assert(0x23 == NUMBER_OF_STEER_CALIBRATION_MODE, "STEER CALIBRATION MODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    STEER_DO_NOTHING    =    0x00,
    STEER_SET_CURRENT_POS_AS_ZERO    =    0x11,
    STEER_SET_FACTOR    =    0x22,

    /* number of mode in total */
    NUMBER_OF_STEER_CALIBRATION_MODE,
} STEER_CALIBRATION_MODE;

// the set of STEER MODE 
// Anywhere in your code using this enum put 
// static_assert(0x02 == NUMBER_OF_STEER_MODE, "STEER MODE changed"); // for C++
// _static_assert(0x02 == NUMBER_OF_STEER_MODE, "STEER MODE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    STEER_SET_STANDBY    =    0x00,
    STEER_SET_OPERATION    =    0x01,

    /* number of mode in total */
    NUMBER_OF_STEER_MODE,
} STEER_MODE;

// the set of STEER STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x05 == NUMBER_OF_STEER_STATUS, "STEER STATUS changed"); // for C++
// _static_assert(0x05 == NUMBER_OF_STEER_STATUS, "STEER STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    STEER_NOT_WORKING    =    0x00,
    STEER_STARTING    =    0x01,
    STEER_OPERATING    =    0x02,
    STEER_MALFUNCTION    =    0x03,
    STEER_STANDBY    =    0x04,

    /* number of mode in total */
    NUMBER_OF_STEER_STATUS,
} STEER_STATUS;

// the set of STOP REASON 
// Anywhere in your code using this enum put 
// static_assert(0x05 == NUMBER_OF_STOP_REASON, "STOP REASON changed"); // for C++
// _static_assert(0x05 == NUMBER_OF_STOP_REASON, "STOP REASON changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    STOP_MANAGEMENT_STOP    =    0x00,
    STOP_BUS_STOP    =    0x01,
    STOP_JOYSTICK_STOP    =    0x02,
    STOP_REMOTE_STOP    =    0x03,
    STOP_PORTER_ID    =    0x04,

    /* number of mode in total */
    NUMBER_OF_STOP_REASON,
} STOP_REASON;

// the set of SYS STATES 
// Anywhere in your code using this enum put 
// static_assert(0x15 == NUMBER_OF_SYS_STATES, "SYS STATES changed"); // for C++
// _static_assert(0x15 == NUMBER_OF_SYS_STATES, "SYS STATES changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    SYS_IDLE    =    0x00,
    SYS_MANUAL    =    0x01,
    SYS_START    =    0x02,
    SYS_DRIVE    =    0x03,
    SYS_END    =    0x04,
    SYS_TOWING    =    0x05,
    SYS_RESERVED    =    0x06,
    SYS_LOAD    =    0x07,
    SYS_REMOTE    =    0x08,
    SYS_RESERVED2    =    0x09,
    SYS_ERROR    =    0x0A,
    SYS_VALIDATE    =    0x0B,
    SYS_EMERGENCY    =    0x0C,
    SYS_WAIT    =    0x0D,
    SYS_RESERVED3    =    0x0E,
    SYS_CALIBRATION    =    0x0F,
    SYS_RESERVED4    =    0x10,
    SYS_VALIDATE_OB    =    0x11,
    SYS_RESERVED5    =    0x12,
    SYS_START_UP    =    0x13,
    SYS_LOADING    =    0x14,

    /* number of mode in total */
    NUMBER_OF_SYS_STATES,
} SYS_STATES;

// the set of TRACK DESTINATION 
// Anywhere in your code using this enum put 
// static_assert(0x04 == NUMBER_OF_TRACK_DESTINATION, "TRACK DESTINATION changed"); // for C++
// _static_assert(0x04 == NUMBER_OF_TRACK_DESTINATION, "TRACK DESTINATION changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    TRACK_RESERVED_ADDR    =    0x00,
    TRACK_MANAGEMENT_ADDR    =    0x01,
    TRACK_DRIVE_ADDR    =    0x02,
    TRACK_OBSTACLE_ADDR    =    0x03,

    /* number of mode in total */
    NUMBER_OF_TRACK_DESTINATION,
} TRACK_DESTINATION;

// the set of TRAFFIC LIGHT STATUS 
// Anywhere in your code using this enum put 
// static_assert(0x85 == NUMBER_OF_TRAFFIC_LIGHT_STATUS, "TRAFFIC LIGHT STATUS changed"); // for C++
// _static_assert(0x85 == NUMBER_OF_TRAFFIC_LIGHT_STATUS, "TRAFFIC LIGHT STATUS changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    TRAFFIC_IDLE    =    0x00,
    TRAFFIC_STOP    =    0x01,
    TRAFFIC_GO    =    0x02,
    TRAFFIC_NO_TIME    =    0x03,
    TRAFFIC_ERROR_DATA    =    0x80,
    TRAFFIC_ERROR_EVENT    =    0x81,
    TRAFFIC_ERROR_INPUT    =    0x82,
    TRAFFIC_ERROR_PRIMARY    =    0x83,
    TRAFFIC_ERROR_SECONDARY    =    0x84,

    /* number of mode in total */
    NUMBER_OF_TRAFFIC_LIGHT_STATUS,
} TRAFFIC_LIGHT_STATUS;

// the set of TRANSFER ACKNOWLEDGE 
// Anywhere in your code using this enum put 
// static_assert(0x03 == NUMBER_OF_TRANSFER_ACKNOWLEDGE, "TRANSFER ACKNOWLEDGE changed"); // for C++
// _static_assert(0x03 == NUMBER_OF_TRANSFER_ACKNOWLEDGE, "TRANSFER ACKNOWLEDGE changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    TRANSFER_ACK    =    0x01,
    TRANSFER_NAK    =    0x02,

    /* number of mode in total */
    NUMBER_OF_TRANSFER_ACKNOWLEDGE,
} TRANSFER_ACKNOWLEDGE;

// the set of TRANSFER ACTION 
// Anywhere in your code using this enum put 
// static_assert(0x06 == NUMBER_OF_TRANSFER_ACTION, "TRANSFER ACTION changed"); // for C++
// _static_assert(0x06 == NUMBER_OF_TRANSFER_ACTION, "TRANSFER ACTION changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
    TRANSFER_UPLOAD    =    0x01,
    TRANSFER_VERIFY    =    0x02,
    TRANSFER_DOWNLOAD    =    0x03,
    TRANSFER_PARTIAL_VERIFY    =    0x04,
    TRANSFER_RESEND    =    0x05,

    /* number of mode in total */
    NUMBER_OF_TRANSFER_ACTION,
} TRANSFER_ACTION;

#endif //main_DBC_MSGID_DBC_TOOL_GENERATED_H
