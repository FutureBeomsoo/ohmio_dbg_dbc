# Header_비교 점검 필요사항

통합 단계에서 사용자 확인 또는 의사결정이 필요한 후보입니다.
| 비교 쌍                                | 파일                     | 점검 항목                                                             |
| ----------------------------------- | ---------------------- | ----------------------------------------------------------------- |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 8 -> 6                 |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | ObstaclePcWarningErrorCode.Obs_NumWarningCodes 값 변경: 0x12 -> 0x10 |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | FusError_t: Reserved 대체 후보 1건                                     |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | FusionFlagsMsg_t: non-reserved bit 범위 충돌 1건                       |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | FusionFlagsMsg_t: Reserved 대체 후보 3건                               |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | ObstaclePcWarning_t: non-reserved bit 범위 충돌 1건                    |
| OhmioLibraries_OhmioLibraries_36    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xBEC99F67 -> 0xE3A942C4       |
| OhmioLibraries_OhmioLibraries_36    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 15 -> 9                        |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 8 -> 6                 |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | ObstaclePcWarningErrorCode.Obs_NumWarningCodes 값 변경: 0x12 -> 0x10 |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | FusError_t: Reserved 대체 후보 1건                                     |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | FusionFlagsMsg_t: non-reserved bit 범위 충돌 1건                       |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | FusionFlagsMsg_t: Reserved 대체 후보 3건                               |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | ObstaclePcWarning_t: non-reserved bit 범위 충돌 1건                    |
| OhmioLibraries_Ohmio_lib_include    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xBEC99F67 -> 0xE3A942C4       |
| OhmioLibraries_Ohmio_lib_include    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 15 -> 9                        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN_peripheral.h   | BMSStatusMsg8_t: non-reserved bit 범위 충돌 6건                        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 8 -> 3                 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | DrvWarningMsgErrorCode.Drv_NumWarningCodes 값 변경: 8 -> 7           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | EPBMsgErrorCode.EPB_NumErrorCodes 값 변경: 5 -> 4                    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FootMsgErrorCode.Foot_NumErrorCodes 값 변경: 9 -> 8                  |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusErrorCode.fus_NumErrorCodes 값 변경: 0x1B -> 0x19                 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusErrorCode.fus_safety_relay_open 값 변경: 0x19 -> 0x18             |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_NumErrorCodes 값 변경: 0x31 -> 0x32 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved 값 변경: 7 -> 0x10         |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved10 값 변경: 0x18 -> 0x19    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved11 값 변경: 0x19 -> 0x1A    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved12 값 변경: 0x1A -> 0x1B    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved13 값 변경: 0x1B -> 0x1C    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved14 값 변경: 0x1C -> 0x1D    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved15 값 변경: 0x1D -> 0x1E    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved16 값 변경: 0x1E -> 0x1F    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved17 값 변경: 0x1F -> 0x2C    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved2 값 변경: 8 -> 0x11        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved3 값 변경: 0x11 -> 0x12     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved4 값 변경: 0x12 -> 0x13     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved5 값 변경: 0x13 -> 0x14     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved6 값 변경: 0x14 -> 0x15     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved7 값 변경: 0x15 -> 0x16     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved8 값 변경: 0x16 -> 0x17     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved9 값 변경: 0x17 -> 0x18     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionErrorCode.Fusion_NumErrorCodes 값 변경: 0x1A -> 0x18           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved 값 변경: 0xD -> 0xC               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved10 값 변경: 0x16 -> 0x15           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved11 값 변경: 0x17 -> 0x16           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved12 값 변경: 0x18 -> 0x17           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved13 값 변경: 0x19 -> 0x18           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved14 값 변경: 0x1A -> 0x19           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved15 값 변경: 0x1B -> 0x1A           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved2 값 변경: 0xE -> 0xD              |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved3 값 변경: 0xF -> 0xE              |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved4 값 변경: 0x10 -> 0xF             |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved5 값 변경: 0x11 -> 0x10            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved6 값 변경: 0x12 -> 0x11            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved7 값 변경: 0x13 -> 0x12            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved8 값 변경: 0x14 -> 0x13            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved9 값 변경: 0x15 -> 0x14            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ManagementErrorCode.mgt_NumErrorCodes 값 변경: 4 -> 2                |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ManualErrorCode.Man_NumErrorCodes 값 변경: 6 -> 4                    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ObstaclePCErrorCode.Obstacle_NumErrorCodes 값 변경: 0x19 -> 0x18     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | SignalMsgErrorCode.signal_NumErrorCodes 값 변경: 3 -> 2              |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | StartupMsgErrorCode.startup_NumErrorCodes 값 변경: 7 -> 5            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | WheelSpeedErrorCode.wheel_NumErrorCodes 값 변경: 3 -> 2              |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | AtmelLocalisaionError_t: non-reserved bit 범위 충돌 2건                |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ErrorAccessory_t: non-reserved bit 범위 충돌 4건                       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ErrorFusionDebugMsg_t: non-reserved bit 범위 충돌 1건                  |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ErrorFusionDebugMsg_t: Reserved 대체 후보 3건                          |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ErrorLocalisation_t: Reserved 대체 후보 1건                            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ExceptionMsg_t: non-reserved bit 범위 충돌 2건                         |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusError_t: non-reserved bit 범위 충돌 1건                             |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusError_t: Reserved 대체 후보 1건                                     |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionFlagsMsg_t: non-reserved bit 범위 충돌 4건                       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionFlagsMsg_t: Reserved 대체 후보 8건                               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionHeight_t: non-reserved bit 범위 충돌 4건                         |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | FusionHeight_t: Reserved 대체 후보 1건                                 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | IMUMag_t: non-reserved bit 범위 충돌 6건                               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | IMUMag_t: Reserved 대체 후보 1건                                       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ManagementError_t: Reserved 대체 후보 2건                              |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ObstacleDangerZoneMsg_t: Reserved 대체 후보 2건                        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | ObstacleEmergency_t: Reserved 대체 후보 1건                            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | StartupStatusMsg_t: Reserved 대체 후보 1건                             |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | SystemReqMsg_t: non-reserved bit 범위 충돌 1건                         |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | SystemReqMsg_t: Reserved 대체 후보 3건                                 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | WheelCountMsg_t: non-reserved bit 범위 충돌 3건                        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xBEC99F67 -> 0x47AB1E0D       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MAJOR 버전 값 변경: 4 -> 2                         |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 15 -> 110                      |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | CAN_ID_IMU_ACC 값 변경: 0x622 -> 0x262                               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | CAN_ID_IMU_GYR 값 변경: 0x623 -> 0x263                               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | CAN_ID_IMU_ROT 값 변경: 0x621 -> 0x261                               |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | 0x26 symbolic name 불일치                                            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | 0x2D symbolic name 불일치                                            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | PARAMETER_ID.NUMBER_OF_PARAMETER_ID 값 변경: 0x91 -> 0x8D            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | STOP_REASON.NUMBER_OF_STOP_REASON 값 변경: 5 -> 4                    |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | STOP_REASON.STOP_BUS_STOP 값 변경: 1 -> 2                            |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | UNIT_ID.LAST_UNIT_ID 값 변경: 0x2B -> 0x27                           |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_BUILD 버전 값 변경: 0xD1134632 -> 0x0E350456 |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MAJOR 버전 값 변경: 2 -> 1                   |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MINOR 버전 값 변경: 3 -> 12                  |
| OhmioLibraries_OhmioLibraries_BK    | ConversionHelper.h     | RoundLimitUnsigned 함수 body 변경                                     |
| OhmioLibraries_OhmioLibraries_BK    | ConversionHelper.h     | RoundUnsigned 함수 body 변경                                          |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN_peripheral.h   | BMSStatusMsg8_t: non-reserved bit 범위 충돌 6건                        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 6 -> 3                 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | DrvWarningMsgErrorCode.Drv_NumWarningCodes 값 변경: 8 -> 7           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | EPBMsgErrorCode.EPB_NumErrorCodes 값 변경: 5 -> 4                    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FootMsgErrorCode.Foot_NumErrorCodes 값 변경: 9 -> 8                  |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusErrorCode.fus_NumErrorCodes 값 변경: 0x1B -> 0x19                 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusErrorCode.fus_safety_relay_open 값 변경: 0x19 -> 0x18             |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_NumErrorCodes 값 변경: 0x31 -> 0x32 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved 값 변경: 7 -> 0x10         |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved10 값 변경: 0x18 -> 0x19    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved11 값 변경: 0x19 -> 0x1A    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved12 값 변경: 0x1A -> 0x1B    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved13 값 변경: 0x1B -> 0x1C    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved14 값 변경: 0x1C -> 0x1D    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved15 값 변경: 0x1D -> 0x1E    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved16 값 변경: 0x1E -> 0x1F    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved17 값 변경: 0x1F -> 0x2C    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved2 값 변경: 8 -> 0x11        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved3 값 변경: 0x11 -> 0x12     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved4 값 변경: 0x12 -> 0x13     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved5 값 변경: 0x13 -> 0x14     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved6 값 변경: 0x14 -> 0x15     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved7 값 변경: 0x15 -> 0x16     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved8 값 변경: 0x16 -> 0x17     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved9 값 변경: 0x17 -> 0x18     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionErrorCode.Fusion_NumErrorCodes 값 변경: 0x1A -> 0x18           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved 값 변경: 0xD -> 0xC               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved10 값 변경: 0x16 -> 0x15           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved11 값 변경: 0x17 -> 0x16           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved12 값 변경: 0x18 -> 0x17           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved13 값 변경: 0x19 -> 0x18           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved14 값 변경: 0x1A -> 0x19           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved15 값 변경: 0x1B -> 0x1A           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved2 값 변경: 0xE -> 0xD              |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved3 값 변경: 0xF -> 0xE              |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved4 값 변경: 0x10 -> 0xF             |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved5 값 변경: 0x11 -> 0x10            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved6 값 변경: 0x12 -> 0x11            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved7 값 변경: 0x13 -> 0x12            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved8 값 변경: 0x14 -> 0x13            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved9 값 변경: 0x15 -> 0x14            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ManagementErrorCode.mgt_NumErrorCodes 값 변경: 4 -> 2                |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ManualErrorCode.Man_NumErrorCodes 값 변경: 6 -> 4                    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ObstaclePCErrorCode.Obstacle_NumErrorCodes 값 변경: 0x19 -> 0x18     |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | SignalMsgErrorCode.signal_NumErrorCodes 값 변경: 3 -> 2              |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | StartupMsgErrorCode.startup_NumErrorCodes 값 변경: 7 -> 5            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | WheelSpeedErrorCode.wheel_NumErrorCodes 값 변경: 3 -> 2              |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | AtmelLocalisaionError_t: non-reserved bit 범위 충돌 2건                |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ErrorAccessory_t: non-reserved bit 범위 충돌 4건                       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ErrorFusionDebugMsg_t: non-reserved bit 범위 충돌 1건                  |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ErrorFusionDebugMsg_t: Reserved 대체 후보 3건                          |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ErrorLocalisation_t: Reserved 대체 후보 1건                            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ExceptionMsg_t: non-reserved bit 범위 충돌 2건                         |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusError_t: non-reserved bit 범위 충돌 1건                             |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionFlagsMsg_t: non-reserved bit 범위 충돌 4건                       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionFlagsMsg_t: Reserved 대체 후보 5건                               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionHeight_t: non-reserved bit 범위 충돌 4건                         |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | FusionHeight_t: Reserved 대체 후보 1건                                 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | IMUMag_t: non-reserved bit 범위 충돌 6건                               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | IMUMag_t: Reserved 대체 후보 1건                                       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ManagementError_t: Reserved 대체 후보 2건                              |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ObstacleDangerZoneMsg_t: Reserved 대체 후보 2건                        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | ObstacleEmergency_t: Reserved 대체 후보 1건                            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | StartupStatusMsg_t: Reserved 대체 후보 1건                             |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | SystemReqMsg_t: non-reserved bit 범위 충돌 1건                         |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | SystemReqMsg_t: Reserved 대체 후보 3건                                 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | WheelCountMsg_t: non-reserved bit 범위 충돌 3건                        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xE3A942C4 -> 0x47AB1E0D       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MAJOR 버전 값 변경: 4 -> 2                         |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 9 -> 110                       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_ACC 값 변경: 0x622 -> 0x262                               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_GYR 값 변경: 0x623 -> 0x263                               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_ROT 값 변경: 0x621 -> 0x261                               |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | 0x26 symbolic name 불일치                                            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | 0x2D symbolic name 불일치                                            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | PARAMETER_ID.NUMBER_OF_PARAMETER_ID 값 변경: 0x91 -> 0x8D            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | STOP_REASON.NUMBER_OF_STOP_REASON 값 변경: 5 -> 4                    |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | STOP_REASON.STOP_BUS_STOP 값 변경: 1 -> 2                            |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | UNIT_ID.LAST_UNIT_ID 값 변경: 0x2B -> 0x27                           |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_BUILD 버전 값 변경: 0xD1134632 -> 0x0E350456 |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MAJOR 버전 값 변경: 2 -> 1                   |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MINOR 버전 값 변경: 3 -> 12                  |
| OhmioLibraries_36_OhmioLibraries_BK | ConversionHelper.h     | RoundLimitUnsigned 함수 body 변경                                     |
| OhmioLibraries_36_OhmioLibraries_BK | ConversionHelper.h     | RoundUnsigned 함수 body 변경                                          |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN_peripheral.h   | BMSStatusMsg8_t: non-reserved bit 범위 충돌 6건                        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 6 -> 3                 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | DrvWarningMsgErrorCode.Drv_NumWarningCodes 값 변경: 8 -> 7           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | EPBMsgErrorCode.EPB_NumErrorCodes 값 변경: 5 -> 4                    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FootMsgErrorCode.Foot_NumErrorCodes 값 변경: 9 -> 8                  |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusErrorCode.fus_NumErrorCodes 값 변경: 0x1B -> 0x19                 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusErrorCode.fus_safety_relay_open 값 변경: 0x19 -> 0x18             |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_NumErrorCodes 값 변경: 0x31 -> 0x32 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved 값 변경: 7 -> 0x10         |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved10 값 변경: 0x18 -> 0x19    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved11 값 변경: 0x19 -> 0x1A    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved12 값 변경: 0x1A -> 0x1B    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved13 값 변경: 0x1B -> 0x1C    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved14 값 변경: 0x1C -> 0x1D    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved15 값 변경: 0x1D -> 0x1E    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved16 값 변경: 0x1E -> 0x1F    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved17 값 변경: 0x1F -> 0x2C    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved2 값 변경: 8 -> 0x11        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved3 값 변경: 0x11 -> 0x12     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved4 값 변경: 0x12 -> 0x13     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved5 값 변경: 0x13 -> 0x14     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved6 값 변경: 0x14 -> 0x15     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved7 값 변경: 0x15 -> 0x16     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved8 값 변경: 0x16 -> 0x17     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionDebugMsgErrorCode.fusdebug_Reserved9 값 변경: 0x17 -> 0x18     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionErrorCode.Fusion_NumErrorCodes 값 변경: 0x1A -> 0x18           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved 값 변경: 0xD -> 0xC               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved10 값 변경: 0x16 -> 0x15           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved11 값 변경: 0x17 -> 0x16           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved12 값 변경: 0x18 -> 0x17           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved13 값 변경: 0x19 -> 0x18           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved14 값 변경: 0x1A -> 0x19           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved15 값 변경: 0x1B -> 0x1A           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved2 값 변경: 0xE -> 0xD              |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved3 값 변경: 0xF -> 0xE              |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved4 값 변경: 0x10 -> 0xF             |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved5 값 변경: 0x11 -> 0x10            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved6 값 변경: 0x12 -> 0x11            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved7 값 변경: 0x13 -> 0x12            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved8 값 변경: 0x14 -> 0x13            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | LocalisationErrorCode.Loc_Reserved9 값 변경: 0x15 -> 0x14            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ManagementErrorCode.mgt_NumErrorCodes 값 변경: 4 -> 2                |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ManualErrorCode.Man_NumErrorCodes 값 변경: 6 -> 4                    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ObstaclePCErrorCode.Obstacle_NumErrorCodes 값 변경: 0x19 -> 0x18     |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | SignalMsgErrorCode.signal_NumErrorCodes 값 변경: 3 -> 2              |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | StartupMsgErrorCode.startup_NumErrorCodes 값 변경: 7 -> 5            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | WheelSpeedErrorCode.wheel_NumErrorCodes 값 변경: 3 -> 2              |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | AtmelLocalisaionError_t: non-reserved bit 범위 충돌 2건                |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ErrorAccessory_t: non-reserved bit 범위 충돌 4건                       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ErrorFusionDebugMsg_t: non-reserved bit 범위 충돌 1건                  |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ErrorFusionDebugMsg_t: Reserved 대체 후보 3건                          |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ErrorLocalisation_t: Reserved 대체 후보 1건                            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ExceptionMsg_t: non-reserved bit 범위 충돌 2건                         |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusError_t: non-reserved bit 범위 충돌 1건                             |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionFlagsMsg_t: non-reserved bit 범위 충돌 4건                       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionFlagsMsg_t: Reserved 대체 후보 5건                               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionHeight_t: non-reserved bit 범위 충돌 4건                         |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | FusionHeight_t: Reserved 대체 후보 1건                                 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | IMUMag_t: non-reserved bit 범위 충돌 6건                               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | IMUMag_t: Reserved 대체 후보 1건                                       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ManagementError_t: Reserved 대체 후보 2건                              |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ObstacleDangerZoneMsg_t: Reserved 대체 후보 2건                        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | ObstacleEmergency_t: Reserved 대체 후보 1건                            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | StartupStatusMsg_t: Reserved 대체 후보 1건                             |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | SystemReqMsg_t: non-reserved bit 범위 충돌 1건                         |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | SystemReqMsg_t: Reserved 대체 후보 3건                                 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | WheelCountMsg_t: non-reserved bit 범위 충돌 3건                        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_BUILD 버전 값 변경: 0xE3A942C4 -> 0x47AB1E0D       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MAJOR 버전 값 변경: 4 -> 2                         |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | MAIN_CANBUS_VERSION_MINOR 버전 값 변경: 9 -> 110                       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_ACC 값 변경: 0x622 -> 0x262                               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_GYR 값 변경: 0x623 -> 0x263                               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | CAN_ID_IMU_ROT 값 변경: 0x621 -> 0x261                               |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | 0x26 symbolic name 불일치                                            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | 0x2D symbolic name 불일치                                            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | PARAMETER_ID.NUMBER_OF_PARAMETER_ID 값 변경: 0x91 -> 0x8D            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | STOP_REASON.NUMBER_OF_STOP_REASON 값 변경: 5 -> 4                    |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | STOP_REASON.STOP_BUS_STOP 값 변경: 1 -> 2                            |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | UNIT_ID.LAST_UNIT_ID 값 변경: 0x2B -> 0x27                           |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_BUILD 버전 값 변경: 0xD1134632 -> 0x0E350456 |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MAJOR 버전 값 변경: 2 -> 1                   |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_peripheral.h | PERIPHERAL_CANBUS_VERSION_MINOR 버전 값 변경: 3 -> 12                  |
| Ohmio_lib_include_OhmioLibraries_BK | ConversionHelper.h     | RoundLimitUnsigned 함수 body 변경                                     |
| Ohmio_lib_include_OhmioLibraries_BK | ConversionHelper.h     | RoundUnsigned 함수 body 변경                                          |
