# 2-1_Chassis_CAN_Signal_정의 점검 필요사항

## Big Endian 표기 Signal

- Big Endian으로 확정된 Signal은 없다.

## 예약 필드 제외 목록

| Message | DBC CAN ID | 원본 CAN ID | Struct | Field | start bit | length | 원본 헤더 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| ErrorLocalisation | 16 | 0x10 | ErrorLocalisation_t | reserved | 13 | 15 | dbc_CAN.h |
| ErrorFrontSteering | 18 | 0x12 | ErrorSteering_t | reserved | 7 | 1 | dbc_CAN.h |
| ErrorFrontSteering | 18 | 0x12 | ErrorSteering_t | reserved1 | 20 | 4 | dbc_CAN.h |
| ErrorRearSteering | 19 | 0x13 | ErrorSteering_t | reserved | 7 | 1 | dbc_CAN.h |
| ErrorRearSteering | 19 | 0x13 | ErrorSteering_t | reserved1 | 20 | 4 | dbc_CAN.h |
| ErrorBlackBox | 22 | 0x16 | ErrorBlackBox_t | reserved | 0 | 64 | dbc_CAN.h |
| ErrorEHBT060 | 27 | 0x1B | ErrorEHBT060_t | reserved | 19 | 5 | dbc_CAN.h |
| ErrorEHBT060 | 27 | 0x1B | ErrorEHBT060_t | reserved1 | 32 | 16 | dbc_CAN.h |
| ObstacleEmergency | 32 | 0x20 | ObstacleEmergency_t | reserved | 27 | 5 | dbc_CAN.h |
| ManagementError | 43 | 0x2B | ManagementError_t | reserved | 4 | 4 | dbc_CAN.h |
| ManagementError | 43 | 0x2B | ManagementError_t | reserved1 | 10 | 6 | dbc_CAN.h |
| AtmelLocalisaionError | 272 | 0x110 | AtmelLocalisaionError_t | reserved | 3 | 1 | dbc_CAN.h |
| ObstacleDangerZoneMsg | 290 | 0x122 | ObstacleDangerZoneMsg_t | reserved | 23 | 17 | dbc_CAN.h |
| ObstacleTrackDistanceMsg | 291 | 0x123 | ObstacleTrackDistanceMsg_t | reserved | 44 | 15 | dbc_CAN.h |
| FrontPointDist | 293 | 0x125 | PointDistanceMsg_t | reserved | 24 | 8 | dbc_CAN.h |
| RearPointDist | 294 | 0x126 | PointDistanceMsg_t | reserved | 24 | 8 | dbc_CAN.h |
| EHBReqMsg | 336 | 0x150 | EHBReqMsg_t | reserved | 24 | 1 | dbc_CAN.h |
| EHBReqMsg | 336 | 0x150 | EHBReqMsg_t | reserved1 | 40 | 8 | dbc_CAN.h |
| EHBReqMsg | 336 | 0x150 | EHBReqMsg_t | reserved2 | 52 | 4 | dbc_CAN.h |
| Motor3ReqMsg | 353 | 0x161 | Motor3ReqMsg_t | reserved | 56 | 2 | additionalDbcCan.h |
| Motor3ReqMsg | 353 | 0x161 | Motor3ReqMsg_t | reserved1 | 60 | 2 | additionalDbcCan.h |
| frontSteeringReq | 355 | 0x163 | SteeringReqMsg_t | reserved | 33 | 7 | dbc_CAN.h |
| rearSteeringReq | 356 | 0x164 | SteeringReqMsg_t | reserved | 33 | 7 | dbc_CAN.h |
| ManualDriveMsg | 384 | 0x180 | ManualDriveMsg_t | reserved | 34 | 2 | dbc_CAN.h |
| ManualDriveMsg | 384 | 0x180 | ManualDriveMsg_t | reserved1 | 38 | 2 | dbc_CAN.h |
| JoystickMsg | 385 | 0x181 | JoystickMsg_t | reserved | 52 | 4 | dbc_CAN.h |
| TeleOpMsg | 387 | 0x183 | JoystickMsg_t | reserved | 52 | 4 | dbc_CAN.h |
| LocManualMsg | 389 | 0x185 | ManualDriveMsg_t | reserved | 34 | 2 | dbc_CAN.h |
| LocManualMsg | 389 | 0x185 | ManualDriveMsg_t | reserved1 | 38 | 2 | dbc_CAN.h |
| LocJoystickMsg | 390 | 0x186 | JoystickMsg_t | reserved | 52 | 4 | dbc_CAN.h |
| TransDriveMsg | 391 | 0x187 | ManualDriveMsg_t | reserved | 34 | 2 | dbc_CAN.h |
| TransDriveMsg | 391 | 0x187 | ManualDriveMsg_t | reserved1 | 38 | 2 | dbc_CAN.h |
| TransJoystickMsg | 392 | 0x188 | JoystickMsg_t | reserved | 52 | 4 | dbc_CAN.h |
| PlatoonDriveMsg | 416 | 0x1A0 | InterVehicleCommsMsg_t | reserved | 36 | 4 | dbc_CAN.h |
| Vehicle1CommsMsg | 417 | 0x1A1 | InterVehicleCommsMsg_t | reserved | 36 | 4 | dbc_CAN.h |
| Vehicle2CommsMsg | 418 | 0x1A2 | InterVehicleCommsMsg_t | reserved | 36 | 4 | dbc_CAN.h |
| Vehicle3CommsMsg | 419 | 0x1A3 | InterVehicleCommsMsg_t | reserved | 36 | 4 | dbc_CAN.h |
| FusionLatitudeFrontMsg | 528 | 0x210 | LatitudeMsg_t | reserved | 37 | 3 | dbc_CAN.h |
| FusionLatitudeRearMsg | 531 | 0x213 | LatitudeMsg_t | reserved | 37 | 3 | dbc_CAN.h |
| VehicleInfoMsg | 534 | 0x216 | VehicleInfoMsg_t | reserved | 32 | 8 | dbc_CAN.h |
| LidarLatitudeUndelayed | 535 | 0x217 | LidarLatitudeUndelayed_t | reserved | 53 | 9 | dbc_CAN.h |
| LidarLongitudeUndelayed | 536 | 0x218 | LidarLongitudeUndelayed_t | reserved | 40 | 22 | dbc_CAN.h |
| FusionRearLatitude | 539 | 0x21B | FusionRearLatitude_t | unused | 58 | 4 | dbc_CAN.h |
| FusionRearLongitude | 540 | 0x21C | FusionRearLongitude_t | reserved | 61 | 1 | dbc_CAN.h |
| frontGpsUbxPart1 | 549 | 0x225 | UBXPart1Msg_t | reserved | 59 | 1 | dbc_CAN.h |
| frontGpsUbxPart2 | 550 | 0x226 | UBXPart2Msg_t | reserved | 59 | 3 | dbc_CAN.h |
| rearGpsUbxPart1 | 565 | 0x235 | UBXPart1Msg_t | reserved | 59 | 1 | dbc_CAN.h |
| rearGpsUbxPart2 | 566 | 0x236 | UBXPart2Msg_t | reserved | 59 | 3 | dbc_CAN.h |
| LidarLatitude | 577 | 0x241 | ObsLatitudeMsg_t | Reserved | 54 | 8 | dbc_CAN.h |
| LidarLongitude | 578 | 0x242 | ObsLongitudeMsg_t | Reserved | 46 | 16 | dbc_CAN.h |
| LidarHeading | 579 | 0x243 | ObsHeadingMsg_t | reserved | 34 | 6 | dbc_CAN.h |
| LidarHeading | 579 | 0x243 | ObsHeadingMsg_t | reserved1 | 56 | 3 | dbc_CAN.h |
| CameraLatitude | 581 | 0x245 | ObsLatitudeMsg_t | Reserved | 54 | 8 | dbc_CAN.h |
| CameraLongitude | 582 | 0x246 | ObsLongitudeMsg_t | Reserved | 46 | 16 | dbc_CAN.h |
| CameraHeading | 583 | 0x247 | ObsHeadingMsg_t | reserved | 34 | 6 | dbc_CAN.h |
| CameraHeading | 583 | 0x247 | ObsHeadingMsg_t | reserved1 | 56 | 3 | dbc_CAN.h |
| Obsolete_UWBDistanceMsg | 592 | 0x250 | UWBDistanceMsg_t | reserved | 8 | 12 | dbc_CAN.h |
| Obsolete_CompassMsg | 608 | 0x260 | CompassMsg_t | reserved | 16 | 24 | dbc_CAN.h |
| LidarOffset | 624 | 0x270 | ObsTrackOffsetMsg_t | reserved | 14 | 1 | dbc_CAN.h |
| CameraOffset | 625 | 0x271 | ObsTrackOffsetMsg_t | reserved | 14 | 1 | dbc_CAN.h |
| Motor1Status | 656 | 0x290 | MotorStatus_t | reserved | 34 | 14 | dbc_CAN.h |
| Motor2Status | 657 | 0x291 | MotorStatus_t | reserved | 34 | 14 | dbc_CAN.h |
| Motor3Status2 | 662 | 0x296 | Motor3Status2_t | reserved | 56 | 4 | dbc_CAN.h |
| FusionAcceMsg | 704 | 0x2C0 | FusionAcceMsg_t | reserved | 32 | 8 | dbc_CAN.h |
| SystemReqMsg | 800 | 0x320 | SystemReqMsg_t | reserved | 40 | 20 | dbc_CAN.h |
| Obsolete_DriveInfoMsg | 801 | 0x321 | DriveInfoMsg_t | reserved | 56 | 4 | dbc_CAN.h |
| StartupStatusMsg | 802 | 0x322 | StartupStatusMsg_t | reserved | 5 | 2 | dbc_CAN.h |
| DriveInfo500kWpMsg | 808 | 0x328 | DriveInfo500kWpMsg_t | reserved | 19 | 5 | dbc_CAN.h |
| EHBStatusMsg | 816 | 0x330 | EHBStatusMsg_t | reserved | 2 | 6 | dbc_CAN.h |
| EHBStatusMsg | 816 | 0x330 | EHBStatusMsg_t | reserved1 | 16 | 6 | dbc_CAN.h |
| EHBStatusMsg | 816 | 0x330 | EHBStatusMsg_t | reserved2 | 36 | 4 | dbc_CAN.h |
| EHBStatusMsg | 816 | 0x330 | EHBStatusMsg_t | reserved3 | 52 | 4 | dbc_CAN.h |
| EHBPowerMsg | 817 | 0x331 | EHBPowerMsg_t | reserved | 8 | 4 | dbc_CAN.h |
| EHBPowerMsg | 817 | 0x331 | EHBPowerMsg_t | reserved1 | 26 | 6 | dbc_CAN.h |
| EHBPowerMsg | 817 | 0x331 | EHBPowerMsg_t | reserved2 | 40 | 8 | dbc_CAN.h |
| EHBPowerMsg | 817 | 0x331 | EHBPowerMsg_t | reserved3 | 52 | 4 | dbc_CAN.h |
| EHBT060PowerMsg | 818 | 0x332 | EHBT060PowerMsg_t | reserved | 0 | 8 | dbc_CAN.h |
| EHBT060PowerMsg | 818 | 0x332 | EHBT060PowerMsg_t | reserved1 | 22 | 6 | dbc_CAN.h |
| EHBT060PowerMsg | 818 | 0x332 | EHBT060PowerMsg_t | reserved2 | 36 | 4 | dbc_CAN.h |
| EHBT060PowerMsg | 818 | 0x332 | EHBT060PowerMsg_t | reserved3 | 52 | 4 | dbc_CAN.h |
| Motor3Status3 | 1408 | 0x580 | Motor3Status3_t | reserved | 12 | 4 | dbc_CAN.h |
| Motor3Status5 | 1410 | 0x582 | Motor3Status5_t | reserved | 14 | 2 | dbc_CAN.h |
| BMSStatusStdMsg | 1412 | 0x584 | BMSStatusStdMsg_t | reserved | 56 | 6 | dbc_CAN.h |
| IMUAcc | 1570 | 0x622 | IMUAcc_t | reserved | 50 | 12 | dbc_CAN.h |
| IMUGyr | 1571 | 0x623 | IMUGyr_t | unused | 58 | 4 | dbc_CAN.h |
| TrackCtrlManageMsg | 1616 | 0x650 | TrackCtrlMsg_t | reserved | 32 | 8 | dbc_CAN.h |
| TrackDataManageMsg | 1618 | 0x652 | TrackDataMsg_t | reserved | 4 | 4 | dbc_CAN.h |
| TrackCtrlDriveMsg | 1632 | 0x660 | TrackCtrlMsg_t | reserved | 32 | 8 | dbc_CAN.h |
| TrackDataDriveMsg | 1634 | 0x662 | TrackDataMsg_t | reserved | 4 | 4 | dbc_CAN.h |
| TrackCtrlObsMsg | 1648 | 0x670 | TrackCtrlMsg_t | reserved | 32 | 8 | dbc_CAN.h |
| TrackDataObsMsg | 1650 | 0x672 | TrackDataMsg_t | reserved | 4 | 4 | dbc_CAN.h |
| StopDebugMsg | 1811 | 0x713 | StopDebugMsg_t | reserved | 4 | 4 | dbc_CAN.h |
| FusionFlagsMsg | 1828 | 0x724 | FusionFlagsMsg_t | reserved1 | 37 | 3 | dbc_CAN.h |
| FusionFlagsMsg | 1828 | 0x724 | FusionFlagsMsg_t | reserved2 | 44 | 2 | dbc_CAN.h |
| FusionFlagsMsg | 1828 | 0x724 | FusionFlagsMsg_t | reserved3 | 51 | 1 | dbc_CAN.h |
| FusionFlagsMsg | 1828 | 0x724 | FusionFlagsMsg_t | reserved4 | 53 | 2 | dbc_CAN.h |
| ErrorFusionDebugMsg | 1829 | 0x725 | ErrorFusionDebugMsg_t | reserved | 7 | 2 | dbc_CAN.h |
| ErrorFusionDebugMsg | 1829 | 0x725 | ErrorFusionDebugMsg_t | reserved1 | 17 | 15 | dbc_CAN.h |
| ErrorFusionDebugMsg | 1829 | 0x725 | ErrorFusionDebugMsg_t | reserved2 | 44 | 1 | dbc_CAN.h |
| IMUMag | 1831 | 0x727 | IMUMag_t | reserved | 60 | 2 | dbc_CAN.h |
| fusionExceptionMsg | 1893 | 0x765 | ExceptionMsg_t | reserved | 37 | 3 | dbc_CAN.h |
| frontWheelExceptionMsg | 1984 | 0x7C0 | ExceptionMsg_t | reserved | 37 | 3 | dbc_CAN.h |
| rearWheelExceptionMsg | 1985 | 0x7C1 | ExceptionMsg_t | reserved | 37 | 3 | dbc_CAN.h |
| EmulatorLatitudeMsg | 2034 | 0x7F2 | LatitudeMsg_t | reserved | 37 | 3 | dbc_CAN.h |

## 기본값 적용 또는 수동 점검 대상

- 변환 함수에서 factor/offset을 직접 확정하지 못한 항목은 기본값으로 작성했다.

| Message | Signal | DBC CAN ID | 원본 CAN ID | start bit | length | factor | offset | min | max | 상태 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| ErrorLocalisation | LocCANCommsError | 16 | 0x10 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocCompassCommsError | 16 | 0x10 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocGPS1CommsError | 16 | 0x10 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocGPS2CommsError | 16 | 0x10 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocUWB1CommsError | 16 | 0x10 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocUWB2CommsError | 16 | 0x10 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocGPS1SerialError | 16 | 0x10 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocGPS2SerialError | 16 | 0x10 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocJoystickDisconnect | 16 | 0x10 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocJoystickCommsError | 16 | 0x10 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocJoystickCentreError | 16 | 0x10 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocSafetyRelayOpen | 16 | 0x10 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | LocDriInfoCommsError | 16 | 0x10 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | motorCommsError | 16 | 0x10 | 28 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLocalisation | motorTempError | 16 | 0x10 | 29 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvFusCommsError | 17 | 0x11 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvFusionQuality2 | 17 | 0x11 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvFusionQuality1 | 17 | 0x11 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | HeadingError | 17 | 0x11 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DistanceError | 17 | 0x11 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvSteeringCommsError | 17 | 0x11 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvSteering2CommsError | 17 | 0x11 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvMotorCommsError | 17 | 0x11 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | TrackValidationFailed | 17 | 0x11 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | ObsValidationFailed | 17 | 0x11 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvObsCommsError | 17 | 0x11 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvObsStopCommsError | 17 | 0x11 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvUltraSoundCommsError | 17 | 0x11 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvUltraSoundMissingUnit | 17 | 0x11 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | Steering1Stopped | 17 | 0x11 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | Steering2Stopped | 17 | 0x11 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvMgtCommsError | 17 | 0x11 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | V2xError | 17 | 0x11 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvObsDangerZoneCommsError | 17 | 0x11 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DeviationError | 17 | 0x11 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | LostJoystick | 17 | 0x11 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvEHBCommsError | 17 | 0x11 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvObsBufferingError | 17 | 0x11 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvGracefulStopped | 17 | 0x11 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvSafetyCommsError | 17 | 0x11 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvRollingTooFar | 17 | 0x11 | 25 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvSpeed2TorqueCommsError | 17 | 0x11 | 26 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvLocationJump | 17 | 0x11 | 27 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvDeltaSteerReqError | 17 | 0x11 | 28 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | DrvOffTrack | 17 | 0x11 | 29 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | WPDistanceError | 17 | 0x11 | 30 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveController | TelportDenied | 17 | 0x11 | 31 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringReqCommsError | 18 | 0x12 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringReqSeqError | 18 | 0x12 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringMotorBlocked | 18 | 0x12 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringOverHeat | 18 | 0x12 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringAngleSensorError | 18 | 0x12 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringMotorPosSensorError | 18 | 0x12 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteeringVoltOutOfRange | 18 | 0x12 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteerReqCommsWarn | 18 | 0x12 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteerReqSeqWarn | 18 | 0x12 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteerMotorHighCurrentWarn | 18 | 0x12 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | SteerHighTempWarn | 18 | 0x12 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontSteering | tempProtectionFactor | 18 | 0x12 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| ErrorRearSteering | SteeringReqCommsError | 19 | 0x13 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringReqSeqError | 19 | 0x13 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringMotorBlocked | 19 | 0x13 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringOverHeat | 19 | 0x13 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringAngleSensorError | 19 | 0x13 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringMotorPosSensorError | 19 | 0x13 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteeringVoltOutOfRange | 19 | 0x13 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteerReqCommsWarn | 19 | 0x13 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteerReqSeqWarn | 19 | 0x13 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteerMotorHighCurrentWarn | 19 | 0x13 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | SteerHighTempWarn | 19 | 0x13 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearSteering | tempProtectionFactor | 19 | 0x13 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| ManualError | ManJoystickDisconnect | 20 | 0x14 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ManualError | ManJoystickCommsError | 20 | 0x14 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ManualError | ManJoystickCentreError | 20 | 0x14 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ManualError | ManSafetyRelayOpen | 20 | 0x14 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ManualError | ManDriInfoComsError | 20 | 0x14 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ManualError | DuplicatedJoystickBoard | 20 | 0x14 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionResetError | 21 | 0x15 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionInitFailed | 21 | 0x15 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSpeedDefError | 21 | 0x15 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSteerAngle1Invalid | 21 | 0x15 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSteeringAngle2Invalid | 21 | 0x15 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionUWB1Invalid | 21 | 0x15 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | fusionCentreUWBInvalid | 21 | 0x15 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionUWB2Invalid | 21 | 0x15 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSpeedInputInvalid | 21 | 0x15 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionTimeStepSizeInvalid | 21 | 0x15 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionBeaconLocNotDefined | 21 | 0x15 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionLocCommsError | 21 | 0x15 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSteering1CommsError | 21 | 0x15 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSteering2CommsError | 21 | 0x15 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionMotor1CommsError | 21 | 0x15 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionMotor2CommsError | 21 | 0x15 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionOdomNull | 21 | 0x15 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionIncompatibleVersion | 21 | 0x15 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionFrontWheelSpeedCommsError | 21 | 0x15 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionRearWheelSpeedCommsError | 21 | 0x15 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionDrvReqCommsError | 21 | 0x15 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionConflictingInputsError | 21 | 0x15 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSavedAntennaOffsetMissing | 21 | 0x15 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionSafetyRelayOpen | 21 | 0x15 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionHugeSensorUpdate | 21 | 0x15 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusion | FusionDrvInfoCommsError | 21 | 0x15 | 25 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_front_left_lidar_fault | 23 | 0x17 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_front_top_lidar_fault | 23 | 0x17 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_front_right_lidar_fault | 23 | 0x17 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_rear_left_lidar_fault | 23 | 0x17 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_rear_top_lidar_fault | 23 | 0x17 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_rear_right_lidar_fault | 23 | 0x17 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_CAN_localisation_msg_error | 23 | 0x17 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_transform_broadcaster_error | 23 | 0x17 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_CAN_wheel_speed_msg_error | 23 | 0x17 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_CAN_front_steering_msg_error | 23 | 0x17 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_CAN_back_steering_msg_error | 23 | 0x17 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_ground_segmentation_msg_error | 23 | 0x17 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_map_msg_error | 23 | 0x17 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_path_planning_msg_error | 23 | 0x17 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_collision_distance_msg_error | 23 | 0x17 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_emergency_envelope_msg_error | 23 | 0x17 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_lidar_calibration_msg_error | 23 | 0x17 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_multiple_lidar_fault | 23 | 0x17 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_map_source_missing | 23 | 0x17 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_map_multiple_missing | 23 | 0x17 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_dangerous_parameter | 23 | 0x17 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_Heartbeat_detection_error | 23 | 0x17 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_wp_mismatch | 23 | 0x17 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_track_mismatch | 23 | 0x17 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorObstaclePC | Obstacle_drv_info_comms_error | 23 | 0x17 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLeftMotor | motorCommsError | 24 | 0x18 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorLeftMotor | motorTempError | 24 | 0x18 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBRequestWarning | 26 | 0x1A | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBOilWarning | 26 | 0x1A | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBCurrentSensorFailed | 26 | 0x1A | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHB_NTCFailed | 26 | 0x1A | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBOverTempWarning | 26 | 0x1A | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBPowerSupplyLv2 | 26 | 0x1A | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBPressureSensorFailed | 26 | 0x1A | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBCanBusOff | 26 | 0x1A | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBPowerSupplyLv4 | 26 | 0x1A | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBECUPowerSupplyFailed | 26 | 0x1A | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBPowerDriverFailed | 26 | 0x1A | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBMotorFailed | 26 | 0x1A | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBPowerSwitchFailed | 26 | 0x1A | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHB | EHBFluidLeakageFailed | 26 | 0x1A | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060RequestWarning | 27 | 0x1B | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060FollowLv1 | 27 | 0x1B | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060VibLv1 | 27 | 0x1B | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060_NTCLv1 | 27 | 0x1B | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060_NTCLv2 | 27 | 0x1B | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060PressureSensorFailed | 27 | 0x1B | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060OverTempWarning | 27 | 0x1B | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060LowPowerLv1 | 27 | 0x1B | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060HighPowerLv1 | 27 | 0x1B | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060FollowLv2 | 27 | 0x1B | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060VibLv2 | 27 | 0x1B | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060CanBusOff | 27 | 0x1B | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060OverCurrent | 27 | 0x1B | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060CurrentSensorFailed | 27 | 0x1B | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060LowPowerLv2 | 27 | 0x1B | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060HighPowerLv2 | 27 | 0x1B | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060PowerSwitchFailed | 27 | 0x1B | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060PowerDriverFailed | 27 | 0x1B | 17 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | T060MotorPosFailed | 27 | 0x1B | 18 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorEHBT060 | softwareVersion | 27 | 0x1B | 48 | 8 | 1 | 0 | 0 | 255 | default |
| ErrorEHBT060 | hardwareVersion | 27 | 0x1B | 56 | 8 | 1 | 0 | 0 | 255 | default |
| EPB1Msg | EPBEngageError | 28 | 0x1C | 0 | 1 | 1 | 0 | 0 | 1 | default |
| EPB1Msg | EPBDisengageError | 28 | 0x1C | 1 | 1 | 1 | 0 | 0 | 1 | default |
| EPB1Msg | EPBVersionError | 28 | 0x1C | 2 | 1 | 1 | 0 | 0 | 1 | default |
| EPB1Msg | EPBSafetyRelayOpen | 28 | 0x1C | 3 | 1 | 1 | 0 | 0 | 1 | default |
| EPB1Msg | EPBDrvInfoCommsError | 28 | 0x1C | 4 | 1 | 1 | 0 | 0 | 1 | default |
| parkBrake2 | EPBEngageError | 29 | 0x1D | 0 | 1 | 1 | 0 | 0 | 1 | default |
| parkBrake2 | EPBDisengageError | 29 | 0x1D | 1 | 1 | 1 | 0 | 0 | 1 | default |
| parkBrake2 | EPBVersionError | 29 | 0x1D | 2 | 1 | 1 | 0 | 0 | 1 | default |
| parkBrake2 | EPBSafetyRelayOpen | 29 | 0x1D | 3 | 1 | 1 | 0 | 0 | 1 | default |
| parkBrake2 | EPBDrvInfoCommsError | 29 | 0x1D | 4 | 1 | 1 | 0 | 0 | 1 | default |
| frontSignal | signalVersionError | 30 | 0x1E | 0 | 1 | 1 | 0 | 0 | 1 | default |
| frontSignal | signalSafetyRelayOpen | 30 | 0x1E | 1 | 1 | 1 | 0 | 0 | 1 | default |
| frontSignal | signalDrvInfoCommsError | 30 | 0x1E | 2 | 1 | 1 | 0 | 0 | 1 | default |
| rearSignal | signalVersionError | 31 | 0x1F | 0 | 1 | 1 | 0 | 0 | 1 | default |
| rearSignal | signalSafetyRelayOpen | 31 | 0x1F | 1 | 1 | 1 | 0 | 0 | 1 | default |
| rearSignal | signalDrvInfoCommsError | 31 | 0x1F | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleEmergency | stop | 32 | 0x20 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ObstacleEmergency | minDistance | 32 | 0x20 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| ObstacleEmergency | maxDistance | 32 | 0x20 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| ObstacleEmergency | overtake | 32 | 0x20 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleEmergency | movingAway | 32 | 0x20 | 25 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleEmergency | obsErrorStop | 32 | 0x20 | 26 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSafetyBoard | SafetyLineActivated | 34 | 0x22 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSafetyBoard | SafetyRelayK2Failed | 34 | 0x22 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSafetyBoard | SafetyRelayK5Failed | 34 | 0x22 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSafetyBoard | SafetyRelayK3Failed | 34 | 0x22 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSafetyBoard | PowerSupplyV4Low | 34 | 0x22 | 4 | 2 | 1 | 0 | 0 | 3 | default |
| StartupErrorMsg | startupVersionError | 35 | 0x23 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | bmsStatus | 35 | 0x23 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | bmsErrLevel | 35 | 0x23 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | bmsPosRelayOpen | 35 | 0x23 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | startupSafetyRelayOpen | 35 | 0x23 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | startupDriveInfoComms | 35 | 0x23 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| StartupErrorMsg | lotteBmsErr | 35 | 0x23 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextObsValidationCommsError | 36 | 0x24 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextMotorNoResp | 36 | 0x24 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextSafetyRelayOpen | 36 | 0x24 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextParameterOutOfRange | 36 | 0x24 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextMotorOverTemp | 36 | 0x24 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextSpeedDeviationError | 36 | 0x24 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextEPB1CommsError | 36 | 0x24 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorDriveExt | DrvextEPB2CommsError | 36 | 0x24 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_internal_reset | 37 | 0x25 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_init_failed | 37 | 0x25 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_front_steer_invalid | 37 | 0x25 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_rear_steer_invalid | 37 | 0x25 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_speed_invalid | 37 | 0x25 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_time_step_size_invalid | 37 | 0x25 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_lidar_slam_stddev_nonpositive | 37 | 0x25 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_cam_slam_stddev_nonpositive | 37 | 0x25 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_motor_comms | 37 | 0x25 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_front_steer_comms | 37 | 0x25 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_rear_steer_comms | 37 | 0x25 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_veh_cholesky_failed | 37 | 0x25 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_veh_innovation_cov_not_psd | 37 | 0x25 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_veh_nonpositive_variance | 37 | 0x25 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_veh_nan_or_inf | 37 | 0x25 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_odo_cholesky_failed | 37 | 0x25 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_odo_innovation_cov_not_psd | 37 | 0x25 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_odo_nonpositive_variance | 37 | 0x25 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_odo_nan_or_inf | 37 | 0x25 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_drv_req_comms | 37 | 0x25 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_front_wheel_speed_comms | 37 | 0x25 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_rear_wheel_speed_comms | 37 | 0x25 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_conflicting_inputs | 37 | 0x25 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_saved_antenna_offset_missing | 37 | 0x25 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_huge_sensor_update | 37 | 0x25 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_safety_relay_open | 37 | 0x25 | 25 | 1 | 1 | 0 | 0 | 1 | default |
| FusError | fus_drv_info_comms_error | 37 | 0x25 | 26 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | ManJoystickDisconnect | 38 | 0x26 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | ManJoystickCommsError | 38 | 0x26 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | ManJoystickCentreError | 38 | 0x26 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | ManSafetyRelayOpen | 38 | 0x26 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | ManDriInfoComsError | 38 | 0x26 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| Trans1Error | DuplicatedJoystickBoard | 38 | 0x26 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootExtendError | 40 | 0x28 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootRetractError | 40 | 0x28 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootHwVersionError | 40 | 0x28 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootTimeOut | 40 | 0x28 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootRetractHighCurrent | 40 | 0x28 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootNoCurrent | 40 | 0x28 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootShortMovement | 40 | 0x28 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootSafetyRelayOpen | 40 | 0x28 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting1 | FootDrvInfoCommsError | 40 | 0x28 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootExtendError | 41 | 0x29 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootRetractError | 41 | 0x29 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootHwVersionError | 41 | 0x29 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootTimeOut | 41 | 0x29 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootRetractHighCurrent | 41 | 0x29 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootNoCurrent | 41 | 0x29 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootShortMovement | 41 | 0x29 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootSafetyRelayOpen | 41 | 0x29 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFooting2 | FootDrvInfoCommsError | 41 | 0x29 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorSecurity | code | 42 | 0x2A | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| ManagementError | monitorError | 43 | 0x2B | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ManagementError | mgtStatusError | 43 | 0x2B | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ManagementError | mgtDrvInfoCommsError | 43 | 0x2B | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ManagementError | sharedDriveError | 43 | 0x2B | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ManagementError | GPSOff | 43 | 0x2B | 8 | 2 | 1 | 0 | 0 | 3 | default |
| ManagementError | drvGPSOff | 43 | 0x2B | 16 | 2 | 1 | 0 | 0 | 3 | default |
| ManagementError | ignoreDZ | 43 | 0x2B | 18 | 2 | 1 | 0 | 0 | 3 | default |
| ManagementError | mcuVersionsOk | 43 | 0x2B | 20 | 2 | 1 | 0 | 0 | 3 | default |
| ManagementError | recording | 43 | 0x2B | 22 | 2 | 1 | 0 | 0 | 3 | default |
| ManagementError | limpMode | 43 | 0x2B | 24 | 2 | 1 | 0 | 0 | 3 | default |
| ErrorNetwork | network_duplicate_board | 45 | 0x2D | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorNetwork | network_safety_relay_open | 45 | 0x2D | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorNetwork | network_drv_info_comms_error | 45 | 0x2D | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory1 | AccessoryIncorrectPCB | 46 | 0x2E | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory1 | AccessoryNonUniqueID | 46 | 0x2E | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory1 | AccessoryRelayOpen | 46 | 0x2E | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory1 | AccessoryDrvInfoComms | 46 | 0x2E | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory2 | AccessoryIncorrectPCB | 47 | 0x2F | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory2 | AccessoryNonUniqueID | 47 | 0x2F | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory2 | AccessoryRelayOpen | 47 | 0x2F | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorAccessory2 | AccessoryDrvInfoComms | 47 | 0x2F | 3 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvTrafficCommsError | 49 | 0x31 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvV2xWarn | 49 | 0x31 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvMgtCommsWarn | 49 | 0x31 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvMotorOff | 49 | 0x31 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvNetCommsError | 49 | 0x31 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvNoSteer1Type | 49 | 0x31 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvNoSteer2Type | 49 | 0x31 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| DriveWarningMsg | DrvMcuVerIncompatible | 49 | 0x31 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| Timepulse_front | localTime | 56 | 0x38 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| Timepulse_front | sync | 56 | 0x38 | 32 | 2 | 1 | 0 | 0 | 3 | default |
| Timepulse_rear | localTime | 57 | 0x39 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| Timepulse_rear | sync | 57 | 0x39 | 32 | 2 | 1 | 0 | 0 | 3 | default |
| frontWheelSpeed | clock | 58 | 0x3A | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| rearWheelSpeed | clock | 59 | 0x3B | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| frontWheelCnt | right_count | 60 | 0x3C | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| frontWheelCnt | left_count | 60 | 0x3C | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| frontWheelCnt | clock | 60 | 0x3C | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| rearWheelCnt | right_count | 61 | 0x3D | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| rearWheelCnt | left_count | 61 | 0x3D | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| rearWheelCnt | clock | 61 | 0x3D | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| ResetReqMsg | reset | 64 | 0x40 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetReqMsg | shutdown | 64 | 0x40 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetReqMsg | parameter | 64 | 0x40 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetLocalisation | cause | 80 | 0x50 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetDrive | cause | 81 | 0x51 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetSteering1 | cause | 82 | 0x52 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetSteering2 | cause | 83 | 0x53 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetManual | cause | 84 | 0x54 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetFusion | cause | 85 | 0x55 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetBlackBox | cause | 86 | 0x56 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetObsPC | cause | 87 | 0x57 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetLMotor | cause | 88 | 0x58 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetRMotor | cause | 89 | 0x59 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetEHB | cause | 90 | 0x5A | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetEPB1 | cause | 92 | 0x5C | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetEPB2 | cause | 93 | 0x5D | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetSignal1 | cause | 94 | 0x5E | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetSignal2 | cause | 95 | 0x5F | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetJoystick | cause | 96 | 0x60 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelResetSafety | cause | 98 | 0x62 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ResetStartup | cause | 99 | 0x63 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelResetLocalisation | cause | 100 | 0x64 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelResetDrive | cause | 101 | 0x65 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelResetManual | cause | 102 | 0x66 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelResetFusion | cause | 103 | 0x67 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ResetFoot1 | cause | 104 | 0x68 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetFoot2 | cause | 105 | 0x69 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetSecurity | cause | 106 | 0x6A | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelResetSecurity | cause | 108 | 0x6C | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ResetNetworkComm | cause | 109 | 0x6D | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetAccessory1 | cause | 110 | 0x6E | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetAccessory2 | cause | 111 | 0x6F | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetWheelSpeed1 | cause | 112 | 0x70 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetWheelSpeed2 | cause | 113 | 0x71 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetTranslator | cause | 118 | 0x76 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetTranslator2 | cause | 119 | 0x77 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ResetTeleOp | cause | 120 | 0x78 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelResetTeleop | cause | 121 | 0x79 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ErrorFrontWheelSpeed | wheel_board_config_error | 128 | 0x80 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontWheelSpeed | wheel_safety_relay_open | 128 | 0x80 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFrontWheelSpeed | wheel_drv_info_comms_error | 128 | 0x80 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearWheelSpeed | wheel_board_config_error | 129 | 0x81 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearWheelSpeed | wheel_safety_relay_open | 129 | 0x81 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorRearWheelSpeed | wheel_drv_info_comms_error | 129 | 0x81 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorTeleOp | teleop_safety_relay_open | 136 | 0x88 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorTeleOp | teleop_drv_info_comms_error | 136 | 0x88 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelLocalisaionError | AtlocGPS1InputError | 272 | 0x110 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelLocalisaionError | AtlocGPS2InputError | 272 | 0x110 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelLocalisaionError | AtlocJoystickCommsError | 272 | 0x110 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelLocalisaionError | AtlocTimer10msProcessTimeout | 272 | 0x110 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelLocalisaionError | AtlocSafetyRelayOpen | 272 | 0x110 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelDriveError | AtdriveSearchClosestPointTimeout | 273 | 0x111 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelDriveError | AtdriveSpeedSelectionTimeout | 273 | 0x111 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelDriveError | AtdriveCalcDriveTimeout | 273 | 0x111 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelDriveError | AtdriveBrakeSelectionTimeout | 273 | 0x111 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelDriveError | AtdriveSafetyRelayOpen | 273 | 0x111 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelManualError | AtmanualJoystickCommsError | 276 | 0x114 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelManualError | AtmanualSafetyRelayOpen | 276 | 0x114 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelFusionError | AtfusionTimer1msInterruptTimeout | 277 | 0x115 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelFusionError | AtfusionMainLoopTimeout | 277 | 0x115 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelFusionError | AtfusionObserveLogTimeout | 277 | 0x115 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelFusionError | AtfusionEstimateLogTimeout | 277 | 0x115 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelFusionError | AtfusionSafetyRelayOpen | 277 | 0x115 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelTeleopError | NotSpecified | 280 | 0x118 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| AtmelSecurityError | NotSpecified | 284 | 0x11C | 0 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolte_ObsLidarMsg | obstacleDistanceLiDARvalid | 288 | 0x120 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolte_ObsLidarMsg | obstacleDistanceLiDARtimestamp | 288 | 0x120 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| ObstacleDangerZoneMsg | notMoving | 290 | 0x122 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleDangerZoneMsg | movingSideways | 290 | 0x122 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleDangerZoneMsg | timeStamp | 290 | 0x122 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| ObstacleTrackDistanceMsg | moveAwayFlag | 291 | 0x123 | 39 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleTrackDistanceMsg | incSpeedFlag | 291 | 0x123 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleTrackDistanceMsg | ignoredObstacle | 291 | 0x123 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleTrackDistanceMsg | ClearOnRight | 291 | 0x123 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleTrackDistanceMsg | ClearOnLeft | 291 | 0x123 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleTrackDistanceMsg | BackDistance | 291 | 0x123 | 59 | 5 | 1 | 0 | 0 | 31 | default |
| ObstacleDangerZoneStopMsg | distance | 292 | 0x124 | 0 | 13 | 1 | 0 | 0 | 8191 | default |
| ObstacleDangerZoneStopMsg | timeToCollision | 292 | 0x124 | 13 | 8 | 1 | 0 | 0 | 255 | default |
| ObstacleDangerZoneStopMsg | notMoving | 292 | 0x124 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleDangerZoneStopMsg | movingSideways | 292 | 0x124 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleDangerZoneStopMsg | occluded | 292 | 0x124 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| ObstacleDangerZoneStopMsg | tolerance | 292 | 0x124 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| FrontPointDist | L1_dist | 293 | 0x125 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| FrontPointDist | L1_num_total | 293 | 0x125 | 16 | 4 | 1 | 0 | 0 | 15 | default |
| FrontPointDist | L1_num_avg | 293 | 0x125 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| FrontPointDist | L2_dist | 293 | 0x125 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| FrontPointDist | L2_num_total | 293 | 0x125 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| FrontPointDist | L2_num_avg | 293 | 0x125 | 52 | 4 | 1 | 0 | 0 | 15 | default |
| RearPointDist | L1_dist | 294 | 0x126 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| RearPointDist | L1_num_total | 294 | 0x126 | 16 | 4 | 1 | 0 | 0 | 15 | default |
| RearPointDist | L1_num_avg | 294 | 0x126 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| RearPointDist | L2_dist | 294 | 0x126 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| RearPointDist | L2_num_total | 294 | 0x126 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| RearPointDist | L2_num_avg | 294 | 0x126 | 52 | 4 | 1 | 0 | 0 | 15 | default |
| TrafficLightMsg | status | 304 | 0x130 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| TrafficLightMsg | lightID | 304 | 0x130 | 24 | 16 | 1 | 0 | 0 | 65535 | default |
| TrafficLightMsg | stopNow | 304 | 0x130 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| EHBReqMsg | enable | 336 | 0x150 | 0 | 4 | 1 | 0 | 0 | 2 | default |
| EHBReqMsg | parkActive | 336 | 0x150 | 4 | 4 | 1 | 0 | 0 | 2 | default |
| EHBReqMsg | speed | 336 | 0x150 | 16 | 8 | 1 | 0 | 0 | 255 | default / review |
| EHBReqMsg | speedQ | 336 | 0x150 | 25 | 2 | 1 | 0 | 0 | 2 | default |
| EHBReqMsg | speedEx | 336 | 0x150 | 27 | 5 | 1 | 0 | 0 | 31 | default / review |
| EHBReqMsg | pressure | 336 | 0x150 | 32 | 8 | 1 | 0 | 0 | 100 | default |
| EHBReqMsg | counter | 336 | 0x150 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| EHBReqMsg | checksum | 336 | 0x150 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolete_BrakeReqMsg | obsoleted | 352 | 0x160 | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| Motor3ReqMsg | controlModel | 353 | 0x161 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| Motor3ReqMsg | direction | 353 | 0x161 | 2 | 2 | 1 | 0 | 0 | 2 | default |
| Motor3ReqMsg | mode | 353 | 0x161 | 4 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3ReqMsg | torque | 353 | 0x161 | 24 | 16 | 1 | 0 | 0 | 65535 | default |
| Motor3ReqMsg | count | 353 | 0x161 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3ReqMsg | damp | 353 | 0x161 | 58 | 2 | 1 | 0 | 0 | 2 | default |
| Motor3ReqMsg | lame | 353 | 0x161 | 62 | 2 | 1 | 0 | 0 | 2 | default |
| MotorReqMsg | mode | 354 | 0x162 | 32 | 6 | 1 | 0 | 0 | 63 | default |
| MotorReqMsg | brake | 354 | 0x162 | 38 | 1 | 1 | 0 | 0 | 1 | default |
| MotorReqMsg | reverse | 354 | 0x162 | 39 | 1 | 1 | 0 | 0 | 1 | default |
| MotorReqMsg | time | 354 | 0x162 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| frontSteeringReq | speed | 355 | 0x163 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| frontSteeringReq | counter | 355 | 0x163 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| frontSteeringReq | mode | 355 | 0x163 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| frontSteeringReq | time | 355 | 0x163 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| rearSteeringReq | speed | 356 | 0x164 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| rearSteeringReq | counter | 356 | 0x164 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| rearSteeringReq | mode | 356 | 0x164 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| rearSteeringReq | time | 356 | 0x164 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Speed2TorqueReqMsg | startupFlag | 357 | 0x165 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Speed2TorqueReqMsg | motorStopped | 357 | 0x165 | 56 | 1 | 1 | 0 | 0 | 1 | default |
| Speed2TorqueReqMsg | motorStarting | 357 | 0x165 | 57 | 1 | 1 | 0 | 0 | 1 | default |
| ManualDriveMsg | slide | 384 | 0x180 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| ManualDriveMsg | pressure | 384 | 0x180 | 24 | 8 | 1 | 0 | 0 | 50 | default |
| ManualDriveMsg | start | 384 | 0x180 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| ManualDriveMsg | reverse | 384 | 0x180 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| ManualDriveMsg | brake | 384 | 0x180 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| ManualDriveMsg | EPB | 384 | 0x180 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| ManualDriveMsg | id | 384 | 0x180 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| JoystickMsg | x | 385 | 0x181 | 0 | 10 | 1 | 0 | 0 | 1023 | default |
| JoystickMsg | y | 385 | 0x181 | 10 | 10 | 1 | 0 | 0 | 1023 | default |
| JoystickMsg | hatswitch | 385 | 0x181 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| JoystickMsg | rotation | 385 | 0x181 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| JoystickMsg | throttle | 385 | 0x181 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| JoystickMsg | b1 | 385 | 0x181 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b2 | 385 | 0x181 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b3 | 385 | 0x181 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b4 | 385 | 0x181 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b5 | 385 | 0x181 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b6 | 385 | 0x181 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b7 | 385 | 0x181 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b8 | 385 | 0x181 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b9 | 385 | 0x181 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b10 | 385 | 0x181 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b11 | 385 | 0x181 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | b12 | 385 | 0x181 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| JoystickMsg | id | 385 | 0x181 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| TeleOpMsg | x | 387 | 0x183 | 0 | 10 | 1 | 0 | 0 | 1023 | default |
| TeleOpMsg | y | 387 | 0x183 | 10 | 10 | 1 | 0 | 0 | 1023 | default |
| TeleOpMsg | hatswitch | 387 | 0x183 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| TeleOpMsg | rotation | 387 | 0x183 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| TeleOpMsg | throttle | 387 | 0x183 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| TeleOpMsg | b1 | 387 | 0x183 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b2 | 387 | 0x183 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b3 | 387 | 0x183 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b4 | 387 | 0x183 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b5 | 387 | 0x183 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b6 | 387 | 0x183 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b7 | 387 | 0x183 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b8 | 387 | 0x183 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b9 | 387 | 0x183 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b10 | 387 | 0x183 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b11 | 387 | 0x183 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | b12 | 387 | 0x183 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| TeleOpMsg | id | 387 | 0x183 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| LocManualMsg | slide | 389 | 0x185 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| LocManualMsg | pressure | 389 | 0x185 | 24 | 8 | 1 | 0 | 0 | 50 | default |
| LocManualMsg | start | 389 | 0x185 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| LocManualMsg | reverse | 389 | 0x185 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| LocManualMsg | brake | 389 | 0x185 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| LocManualMsg | EPB | 389 | 0x185 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| LocManualMsg | id | 389 | 0x185 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| LocJoystickMsg | x | 390 | 0x186 | 0 | 10 | 1 | 0 | 0 | 1023 | default |
| LocJoystickMsg | y | 390 | 0x186 | 10 | 10 | 1 | 0 | 0 | 1023 | default |
| LocJoystickMsg | hatswitch | 390 | 0x186 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| LocJoystickMsg | rotation | 390 | 0x186 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| LocJoystickMsg | throttle | 390 | 0x186 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| LocJoystickMsg | b1 | 390 | 0x186 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b2 | 390 | 0x186 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b3 | 390 | 0x186 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b4 | 390 | 0x186 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b5 | 390 | 0x186 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b6 | 390 | 0x186 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b7 | 390 | 0x186 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b8 | 390 | 0x186 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b9 | 390 | 0x186 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b10 | 390 | 0x186 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b11 | 390 | 0x186 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | b12 | 390 | 0x186 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| LocJoystickMsg | id | 390 | 0x186 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| TransDriveMsg | slide | 391 | 0x187 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| TransDriveMsg | pressure | 391 | 0x187 | 24 | 8 | 1 | 0 | 0 | 50 | default |
| TransDriveMsg | start | 391 | 0x187 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| TransDriveMsg | reverse | 391 | 0x187 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| TransDriveMsg | brake | 391 | 0x187 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| TransDriveMsg | EPB | 391 | 0x187 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| TransDriveMsg | id | 391 | 0x187 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| TransJoystickMsg | x | 392 | 0x188 | 0 | 10 | 1 | 0 | 0 | 1023 | default |
| TransJoystickMsg | y | 392 | 0x188 | 10 | 10 | 1 | 0 | 0 | 1023 | default |
| TransJoystickMsg | hatswitch | 392 | 0x188 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| TransJoystickMsg | rotation | 392 | 0x188 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| TransJoystickMsg | throttle | 392 | 0x188 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| TransJoystickMsg | b1 | 392 | 0x188 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b2 | 392 | 0x188 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b3 | 392 | 0x188 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b4 | 392 | 0x188 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b5 | 392 | 0x188 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b6 | 392 | 0x188 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b7 | 392 | 0x188 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b8 | 392 | 0x188 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b9 | 392 | 0x188 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b10 | 392 | 0x188 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b11 | 392 | 0x188 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | b12 | 392 | 0x188 | 51 | 1 | 1 | 0 | 0 | 1 | default |
| TransJoystickMsg | id | 392 | 0x188 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| PlatoonDriveMsg | mode | 416 | 0x1A0 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| PlatoonDriveMsg | Time_Sync | 416 | 0x1A0 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Vehicle1CommsMsg | mode | 417 | 0x1A1 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Vehicle1CommsMsg | Time_Sync | 417 | 0x1A1 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Vehicle2CommsMsg | mode | 418 | 0x1A2 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Vehicle2CommsMsg | Time_Sync | 418 | 0x1A2 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Vehicle3CommsMsg | mode | 419 | 0x1A3 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Vehicle3CommsMsg | Time_Sync | 419 | 0x1A3 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| TimestampMsg | time | 512 | 0x200 | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| DriveRequestsMsg | driveGPSOff | 513 | 0x201 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| DriveRequestsMsg | mgtGPSOff | 513 | 0x201 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| DriveRequestsMsg | lidarLocOff | 513 | 0x201 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| DriveRequestsMsg | fusionReset | 513 | 0x201 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLatitudeFrontMsg | sign | 528 | 0x210 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLatitudeFrontMsg | outlier | 528 | 0x210 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLatitudeFrontMsg | time | 528 | 0x210 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| FusionLongitudeFront | sign | 529 | 0x211 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLongitudeFront | quality | 529 | 0x211 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| FusionLongitudeFront | time | 529 | 0x211 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| FusionLatitudeRearMsg | sign | 531 | 0x213 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLatitudeRearMsg | outlier | 531 | 0x213 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLatitudeRearMsg | time | 531 | 0x213 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| FusionLongitudeRear | sign | 532 | 0x214 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| FusionLongitudeRear | quality | 532 | 0x214 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| FusionLongitudeRear | time | 532 | 0x214 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| FusionBiasOutlierMsg | fUWBOutlier | 533 | 0x215 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| FusionBiasOutlierMsg | rearUWBOutlier | 533 | 0x215 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| FusionBiasOutlierMsg | time | 533 | 0x215 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| VehicleInfoMsg | antennaDistance | 534 | 0x216 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| VehicleInfoMsg | time | 534 | 0x216 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| LidarLatitudeUndelayed | Available | 535 | 0x217 | 52 | 1 | 1 | 0 | 0 | 1 | default |
| LidarLatitudeUndelayed | sync | 535 | 0x217 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| LidarLongitudeUndelayed | StepsBack | 536 | 0x218 | 36 | 4 | 1 | 0 | 0 | 1 | default |
| LidarLongitudeUndelayed | sync | 536 | 0x218 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| FusionFrontLatitude | sync | 537 | 0x219 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| FusionFrontLongitude | sync | 538 | 0x21A | 62 | 2 | 1 | 0 | 0 | 3 | default |
| FusionRearLatitude | sync | 539 | 0x21B | 62 | 2 | 1 | 0 | 0 | 3 | default |
| FusionRearLongitude | fusionInitialisable | 540 | 0x21C | 60 | 1 | 1 | 0 | 0 | 1 | default |
| FusionRearLongitude | sync | 540 | 0x21C | 62 | 2 | 1 | 0 | 0 | 3 | default |
| FusionHeight | sync | 541 | 0x21D | 35 | 2 | 1 | 0 | 0 | 3 | default |
| FusionHeight | delay_gnss_front | 541 | 0x21D | 37 | 10 | 1 | 0 | 0 | 1023 | default |
| FusionHeight | delay_gnss_rear | 541 | 0x21D | 47 | 10 | 1 | 0 | 0 | 1023 | default |
| FusionHeight | compute_time | 541 | 0x21D | 57 | 7 | 1 | 0 | 0 | 127 | default |
| Obsolete_latitudeFrontMsg | sign | 544 | 0x220 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_latitudeFrontMsg | quality | 544 | 0x220 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| Obsolete_latitudeFrontMsg | time | 544 | 0x220 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_longitudeFrontMsg | sign | 545 | 0x221 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_longitudeFrontMsg | quality | 545 | 0x221 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| Obsolete_longitudeFrontMsg | time | 545 | 0x221 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_heightFrontMsg | noOfSatellites | 546 | 0x222 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolete_heightFrontMsg | time | 546 | 0x222 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_combineHeightFrontMsg | noOfSatellites | 547 | 0x223 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolete_combineHeightFrontMsg | time | 547 | 0x223 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| frontGpsUbxPart1 | Valid_Checksum | 549 | 0x225 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| frontGpsUbxPart1 | Data_Available | 549 | 0x225 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| frontGpsUbxPart1 | Sync | 549 | 0x225 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| frontGpsUbxPart2 | CarrierSolution | 550 | 0x226 | 56 | 2 | 1 | 0 | 0 | 2 | default |
| frontGpsUbxPart2 | pvtValidChecksum | 550 | 0x226 | 58 | 1 | 1 | 0 | 0 | 1 | default |
| frontGpsUbxPart2 | Sync | 550 | 0x226 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| frontGpsUbxPart3 | iTow | 551 | 0x227 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| frontGpsUbxPart3 | localTime | 551 | 0x227 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| Obsolete_latitudeBackMsg | sign | 560 | 0x230 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_latitudeBackMsg | quality | 560 | 0x230 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| Obsolete_latitudeBackMsg | time | 560 | 0x230 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_longitudeBackMsg | sign | 561 | 0x231 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_longitudeBackMsg | quality | 561 | 0x231 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| Obsolete_longitudeBackMsg | time | 561 | 0x231 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_heightBackMsg | noOfSatellites | 562 | 0x232 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolete_heightBackMsg | time | 562 | 0x232 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_combineHeightBackMsg | noOfSatellites | 564 | 0x234 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| Obsolete_combineHeightBackMsg | time | 564 | 0x234 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| rearGpsUbxPart1 | Valid_Checksum | 565 | 0x235 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| rearGpsUbxPart1 | Data_Available | 565 | 0x235 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| rearGpsUbxPart1 | Sync | 565 | 0x235 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| rearGpsUbxPart2 | CarrierSolution | 566 | 0x236 | 56 | 2 | 1 | 0 | 0 | 2 | default |
| rearGpsUbxPart2 | pvtValidChecksum | 566 | 0x236 | 58 | 1 | 1 | 0 | 0 | 1 | default |
| rearGpsUbxPart2 | Sync | 566 | 0x236 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| rearGpsUbxPart3 | iTow | 567 | 0x237 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| rearGpsUbxPart3 | localTime | 567 | 0x237 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| LidarSpeed | SpeedsInvalid | 576 | 0x240 | 56 | 1 | 1 | 0 | 0 | 1 | default |
| LidarSpeed | delay | 576 | 0x240 | 57 | 5 | 1 | 0 | 0 | 31 | default |
| LidarLatitude | LatUnavailable | 577 | 0x241 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| LidarLatitude | ForwardInfStdDev | 577 | 0x241 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| LidarLatitude | sync | 577 | 0x241 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| LidarLongitude | LongUnavailable | 578 | 0x242 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| LidarLongitude | LateralInfStdDev | 578 | 0x242 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| LidarLongitude | sync | 578 | 0x242 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| LidarHeading | HeadingUnavailable | 579 | 0x243 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| LidarHeading | HeadingInfStdDev | 579 | 0x243 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| LidarHeading | timeStamp | 579 | 0x243 | 40 | 16 | 1 | 0 | 0 | 65535 | default |
| LidarHeading | msgVersion | 579 | 0x243 | 59 | 3 | 1 | 0 | 0 | 7 | default |
| LidarHeading | sync | 579 | 0x243 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| CameraLatitude | LatUnavailable | 581 | 0x245 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| CameraLatitude | ForwardInfStdDev | 581 | 0x245 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| CameraLatitude | sync | 581 | 0x245 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| CameraLongitude | LongUnavailable | 582 | 0x246 | 44 | 1 | 1 | 0 | 0 | 1 | default |
| CameraLongitude | LateralInfStdDev | 582 | 0x246 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| CameraLongitude | sync | 582 | 0x246 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| CameraHeading | HeadingUnavailable | 583 | 0x247 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| CameraHeading | HeadingInfStdDev | 583 | 0x247 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| CameraHeading | timeStamp | 583 | 0x247 | 40 | 16 | 1 | 0 | 0 | 65535 | default |
| CameraHeading | msgVersion | 583 | 0x247 | 59 | 3 | 1 | 0 | 0 | 7 | default |
| CameraHeading | sync | 583 | 0x247 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| Obsolete_UWBDistanceMsg | id | 592 | 0x250 | 0 | 7 | 1 | 0 | 0 | 127 | default |
| Obsolete_UWBDistanceMsg | rearUnit | 592 | 0x250 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_UWBDistanceMsg | distance | 592 | 0x250 | 20 | 20 | 1 | 0 | 0 | 1048575 | default |
| Obsolete_UWBDistanceMsg | time | 592 | 0x250 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Obsolete_UWBLatitudeMsg | id | 593 | 0x251 | 0 | 20 | 1 | 0 | 0 | 1048575 | default |
| Obsolete_UWBLongitudeMsg | id | 594 | 0x252 | 0 | 20 | 1 | 0 | 0 | 1048575 | default |
| Obsolete_CompassMsg | time | 608 | 0x260 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| LidarOffset | literalValid | 624 | 0x270 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| LidarOffset | headingValid | 624 | 0x270 | 30 | 1 | 1 | 0 | 0 | 1 | default |
| CameraOffset | literalValid | 625 | 0x271 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| CameraOffset | headingValid | 625 | 0x271 | 30 | 1 | 1 | 0 | 0 | 1 | default |
| frontSteeringStatus | status | 640 | 0x280 | 16 | 3 | 1 | 0 | 0 | 3 | default |
| frontSteeringStatus | calibrationSet | 640 | 0x280 | 19 | 2 | 1 | 0 | 0 | 3 | default |
| frontSteeringStatus | sensorFailed | 640 | 0x280 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| frontSteeringStatus | factorSet | 640 | 0x280 | 22 | 2 | 1 | 0 | 0 | 3 | default |
| frontSteeringStatus | heartbeat | 640 | 0x280 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| frontSteeringStatus | time | 640 | 0x280 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| rearSteeringStatus | status | 641 | 0x281 | 16 | 3 | 1 | 0 | 0 | 3 | default |
| rearSteeringStatus | calibrationSet | 641 | 0x281 | 19 | 2 | 1 | 0 | 0 | 3 | default |
| rearSteeringStatus | sensorFailed | 641 | 0x281 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| rearSteeringStatus | factorSet | 641 | 0x281 | 22 | 2 | 1 | 0 | 0 | 3 | default |
| rearSteeringStatus | heartbeat | 641 | 0x281 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| rearSteeringStatus | time | 641 | 0x281 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| Motor1Status | directionFault | 656 | 0x290 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| Motor1Status | noReqfor300ms | 656 | 0x290 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| Motor1Status | counter | 656 | 0x290 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor1Status | config | 656 | 0x290 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| Motor2Status | directionFault | 657 | 0x291 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| Motor2Status | noReqfor300ms | 657 | 0x291 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| Motor2Status | counter | 657 | 0x291 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor2Status | config | 657 | 0x291 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status1 | controlModel | 661 | 0x295 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| Motor3Status1 | direction | 661 | 0x295 | 2 | 2 | 1 | 0 | 0 | 3 | default |
| Motor3Status1 | mode | 661 | 0x295 | 4 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status1 | torqueDir | 661 | 0x295 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| Motor3Status1 | errorCode | 661 | 0x295 | 56 | 6 | 1 | 0 | 0 | 63 | default |
| Motor3Status1 | faultLevel | 661 | 0x295 | 62 | 2 | 1 | 0 | 0 | 2 | default |
| Motor3Status2 | voltage | 662 | 0x296 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| Motor3Status2 | actualTorque | 662 | 0x296 | 32 | 16 | 1 | 0 | 0 | 3000 | default |
| Motor3Status2 | count | 662 | 0x296 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status2 | dampEnable | 662 | 0x296 | 60 | 2 | 1 | 0 | 0 | 3 | default |
| Motor3Status2 | lameStatus | 662 | 0x296 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| EPBReqMsg | request | 688 | 0x2B0 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| EPB1Status | status | 693 | 0x2B5 | 0 | 8 | 1 | 0 | 0 | 2 | default |
| EPB1Status | mode | 693 | 0x2B5 | 8 | 8 | 1 | 0 | 0 | 3 | default |
| EPB1Status | error | 693 | 0x2B5 | 16 | 8 | 1 | 0 | 0 | 1 | default |
| EPB2Status | status | 694 | 0x2B6 | 0 | 8 | 1 | 0 | 0 | 2 | default |
| EPB2Status | mode | 694 | 0x2B6 | 8 | 8 | 1 | 0 | 0 | 3 | default |
| EPB2Status | error | 694 | 0x2B6 | 16 | 8 | 1 | 0 | 0 | 1 | default |
| FusionAcceMsg | time | 704 | 0x2C0 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| DeviationReqMsg | waypointLow | 709 | 0x2C5 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DeviationReqMsg | InFlag | 709 | 0x2C5 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| DeviationReqMsg | OffsetActive | 709 | 0x2C5 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| DeviationReqMsg | NoDeviation | 709 | 0x2C5 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| DeviationReqMsg | waypointHigh | 709 | 0x2C5 | 38 | 3 | 1 | 0 | 0 | 7 | default |
| DynamicTrackValidationMsg | waypointLow | 768 | 0x300 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DynamicTrackValidationMsg | waypointHigh | 768 | 0x300 | 56 | 3 | 1 | 0 | 0 | 7 | default |
| ParameterConfMsg | id | 784 | 0x310 | 0 | 15 | 1 | 0 | 0 | 32767 | default |
| ParameterConfMsg | read | 784 | 0x310 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ParameterConfMsg | writeAll | 784 | 0x310 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| ParameterConfMsg | writeLast | 784 | 0x310 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| ConfigResp | id | 785 | 0x311 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| VersionReqMsg | id | 786 | 0x312 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| VersionRespMsg | id | 787 | 0x313 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| VersionRespMsg | major | 787 | 0x313 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| VersionRespMsg | debug | 787 | 0x313 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| VersionRespMsg | minor | 787 | 0x313 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| VersionRespMsg | build | 787 | 0x313 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| BootloaderVersionRespMsg | id | 788 | 0x314 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| BootloaderVersionRespMsg | major | 788 | 0x314 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| BootloaderVersionRespMsg | debug | 788 | 0x314 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| BootloaderVersionRespMsg | minor | 788 | 0x314 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| BootloaderVersionRespMsg | build | 788 | 0x314 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| OcanDBCVersionMsg | id | 789 | 0x315 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| OcanDBCVersionMsg | major | 789 | 0x315 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| OcanDBCVersionMsg | debug | 789 | 0x315 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| OcanDBCVersionMsg | minor | 789 | 0x315 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| OcanDBCVersionMsg | build | 789 | 0x315 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| PcanDBCVersionMsg | id | 790 | 0x316 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| PcanDBCVersionMsg | major | 790 | 0x316 | 16 | 7 | 1 | 0 | 0 | 127 | default |
| PcanDBCVersionMsg | debug | 790 | 0x316 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| PcanDBCVersionMsg | minor | 790 | 0x316 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| PcanDBCVersionMsg | build | 790 | 0x316 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| ParameterConfSignMsg | id | 791 | 0x317 | 0 | 15 | 1 | 0 | 0 | 32767 | default |
| ParameterConfSignMsg | read | 791 | 0x317 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ParameterConfSignMsg | writeToMRAM | 791 | 0x317 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| ConfigSignResp | id | 792 | 0x318 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| SystemReqMsg | mode | 800 | 0x320 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| SystemReqMsg | path | 800 | 0x320 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| SystemReqMsg | maxSpeed | 800 | 0x320 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| SystemReqMsg | brakePressure | 800 | 0x320 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| SystemReqMsg | driveDisalowed | 800 | 0x320 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| SystemReqMsg | errorCheck | 800 | 0x320 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| SystemReqMsg | useLidar | 800 | 0x320 | 62 | 1 | 1 | 0 | 0 | 1 | default |
| SystemReqMsg | useUltrasound | 800 | 0x320 | 63 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | waypoint | 801 | 0x321 | 0 | 12 | 1 | 0 | 0 | 4095 | default |
| Obsolete_DriveInfoMsg | path | 801 | 0x321 | 12 | 4 | 1 | 0 | 0 | 3 | default |
| Obsolete_DriveInfoMsg | maxSpeed | 801 | 0x321 | 16 | 16 | 1 | 0 | 500 | 12000 | default |
| Obsolete_DriveInfoMsg | mode | 801 | 0x321 | 48 | 6 | 1 | 0 | 0 | 63 | default |
| Obsolete_DriveInfoMsg | brake | 801 | 0x321 | 54 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | reverse | 801 | 0x321 | 55 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | cord | 801 | 0x321 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | errorCheck | 801 | 0x321 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | useLidar | 801 | 0x321 | 62 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_DriveInfoMsg | useUltrasound | 801 | 0x321 | 63 | 1 | 1 | 0 | 0 | 1 | default |
| StartupStatusMsg | bms | 802 | 0x322 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| StartupStatusMsg | emergencyLevel | 802 | 0x322 | 1 | 3 | 1 | 0 | 0 | 7 | default |
| StartupStatusMsg | safetyLineErr | 802 | 0x322 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| StartupStatusMsg | motorRly | 802 | 0x322 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| StartupStatusMsg | status | 802 | 0x322 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| StartupStatusMsg | key1 | 802 | 0x322 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| StartupStatusMsg | key2 | 802 | 0x322 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| LoadingReqMsg | maxAngle | 803 | 0x323 | 0 | 2 | 1 | 0 | 0 | 3 | default |
| LoadingReqMsg | reverse | 803 | 0x323 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| LoadingReqMsg | dualAxis | 803 | 0x323 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| LoadingReqMsg | horn | 803 | 0x323 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| LoadingReqMsg | EHB | 803 | 0x323 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| LoadingReqMsg | EPB | 803 | 0x323 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| SecuritySpeedMsg | maxSpeed | 804 | 0x324 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DriveInfoLongWpMsg | waypoint | 805 | 0x325 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DriveInfoLongWpMsg | maxSpeed | 805 | 0x325 | 16 | 16 | 1 | 0 | 500 | 12000 | default |
| DriveInfoLongWpMsg | mode | 805 | 0x325 | 48 | 6 | 1 | 0 | 0 | 63 | default |
| DriveInfoLongWpMsg | brake | 805 | 0x325 | 54 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfoLongWpMsg | reverse | 805 | 0x325 | 55 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfoLongWpMsg | path | 805 | 0x325 | 56 | 4 | 1 | 0 | 0 | 3 | default |
| DriveInfoLongWpMsg | leftDrive | 805 | 0x325 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfoLongWpMsg | errorCheck | 805 | 0x325 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfoLongWpMsg | useLidar | 805 | 0x325 | 62 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfoLongWpMsg | useUltrasound | 805 | 0x325 | 63 | 1 | 1 | 0 | 0 | 1 | default |
| StopReqMsg | waypointLow | 806 | 0x326 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| StopReqMsg | deceFlag | 806 | 0x326 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| StopReqMsg | waypointHigh | 806 | 0x326 | 25 | 3 | 1 | 0 | 0 | 7 | default |
| StopReqMsg | reason | 806 | 0x326 | 28 | 4 | 1 | 0 | 0 | 15 | default |
| ObsTiedMarginMsg | shrinkTime | 807 | 0x327 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ObsTiedMarginMsg | left | 807 | 0x327 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ObsTiedMarginMsg | right | 807 | 0x327 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfo500kWpMsg | waypoint | 808 | 0x328 | 0 | 19 | 1 | 0 | 0 | 524287 | default |
| DriveInfo500kWpMsg | maxSpeed | 808 | 0x328 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| DriveInfo500kWpMsg | errorDistance | 808 | 0x328 | 32 | 16 | 1 | 0 | -32768 | 32767 | default |
| DriveInfo500kWpMsg | mode | 808 | 0x328 | 48 | 6 | 1 | 0 | 0 | 63 | default |
| DriveInfo500kWpMsg | brake | 808 | 0x328 | 54 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfo500kWpMsg | reverse | 808 | 0x328 | 55 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfo500kWpMsg | path | 808 | 0x328 | 56 | 4 | 1 | 0 | 0 | 15 | default |
| DriveInfo500kWpMsg | leftDrive | 808 | 0x328 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfo500kWpMsg | errorCheck | 808 | 0x328 | 61 | 1 | 1 | 0 | 0 | 1 | default |
| DriveInfo500kWpMsg | useLidar | 808 | 0x328 | 62 | 1 | 1 | 0 | 0 | 1 | default |
| EHBStatusMsg | active | 816 | 0x330 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| EHBStatusMsg | parkReq | 816 | 0x330 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| EHBStatusMsg | pressure | 816 | 0x330 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| EHBStatusMsg | condition | 816 | 0x330 | 22 | 2 | 1 | 0 | 0 | 3 | default |
| EHBStatusMsg | pedalTravel | 816 | 0x330 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| EHBStatusMsg | faultLevel | 816 | 0x330 | 32 | 4 | 1 | 0 | 0 | 15 | default |
| EHBStatusMsg | aimPressure | 816 | 0x330 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| EHBStatusMsg | counter | 816 | 0x330 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| EHBStatusMsg | checksum | 816 | 0x330 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| EHBPowerMsg | current | 817 | 0x331 | 0 | 8 | 1 | 0 | 0 | 255 | default / review |
| EHBPowerMsg | currentEx | 817 | 0x331 | 12 | 4 | 1 | 0 | 0 | 15 | default / review |
| EHBPowerMsg | s16_ADC | 817 | 0x331 | 24 | 2 | 1 | 0 | 0 | 3 | default / review |
| EHBPowerMsg | s16_ADCEx | 817 | 0x331 | 32 | 8 | 1 | 0 | 0 | 255 | default / review |
| EHBPowerMsg | counter | 817 | 0x331 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| EHBPowerMsg | checksum | 817 | 0x331 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| EHBT060PowerMsg | s16_ADC | 818 | 0x332 | 16 | 6 | 1 | 0 | 0 | 63 | default / review |
| EHBT060PowerMsg | s16_ADCEx | 818 | 0x332 | 28 | 4 | 1 | 0 | 0 | 15 | default / review |
| EHBT060PowerMsg | cylinderPosition | 818 | 0x332 | 32 | 4 | 1 | 0 | 0 | 15 | default / review |
| EHBT060PowerMsg | cylinderPositionEx | 818 | 0x332 | 40 | 8 | 1 | 0 | 0 | 255 | default / review |
| EHBT060PowerMsg | counter | 818 | 0x332 | 48 | 4 | 1 | 0 | 0 | 15 | default |
| EHBT060PowerMsg | checksum | 818 | 0x332 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| EPBReleaseMsg | AA | 832 | 0x340 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| EPBReleaseMsg | A02 | 832 | 0x340 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| LiveUpdateReqMsg | id | 1040 | 0x410 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| LiveUpdateACKMsg | id | 1041 | 0x411 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| LiveUpdateACKMsg | ACK | 1041 | 0x411 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| LiveUpdateData | data | 1056 | 0x420 | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| LiveUpdateRespMsg | data | 1057 | 0x421 | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| AtmelUpdateReqMsg | action | 1058 | 0x422 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateReqMsg | address | 1058 | 0x422 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelUpdateReqMsg | data | 1058 | 0x422 | 24 | 32 | 1 | 0 | 0 | 4294967295 | default |
| AtmelUpdateReqMsg | checksum | 1058 | 0x422 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateRespMsg | action | 1059 | 0x423 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateRespMsg | address | 1059 | 0x423 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| AtmelUpdateRespMsg | ACK | 1059 | 0x423 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateRespMsg | major | 1059 | 0x423 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateRespMsg | minor | 1059 | 0x423 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| AtmelUpdateRespMsg | checksum | 1059 | 0x423 | 48 | 16 | 1 | 0 | 0 | 65535 | default |
| frontReqIndicatorBrake | left | 1296 | 0x510 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| frontReqIndicatorBrake | right | 1296 | 0x510 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| frontReqIndicatorBrake | brake | 1296 | 0x510 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| rearReqIndicatorBrake | left | 1297 | 0x511 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| rearReqIndicatorBrake | right | 1297 | 0x511 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| rearReqIndicatorBrake | brake | 1297 | 0x511 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| frontStatusIndicatorBrake | left | 1312 | 0x520 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| frontStatusIndicatorBrake | right | 1312 | 0x520 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| frontStatusIndicatorBrake | brake | 1312 | 0x520 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| rearStatusIndicatorBrake | left | 1313 | 0x521 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| rearStatusIndicatorBrake | right | 1313 | 0x521 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| rearStatusIndicatorBrake | brake | 1313 | 0x521 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| FrontRightIndicatorLightReqMsg | on | 1328 | 0x530 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontRightIndicatorLightStatusMsg | on | 1329 | 0x531 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLeftIndicatorLightReqMsg | on | 1344 | 0x540 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| FrontLeftIndicatorLightStatusMsg | on | 1345 | 0x541 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearBrakeLightReqMsg | on | 1360 | 0x550 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearBrakeLightStatusMsg | on | 1361 | 0x551 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearRightIndicatorLightReqMsg | on | 1376 | 0x560 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearRightIndicatorLightStatusMsg | on | 1377 | 0x561 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearLeftIndicatorLightReqMsg | on | 1392 | 0x570 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| RearLeftIndicatorLightStatusMsg | on | 1393 | 0x571 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status3 | HWVersionMinorL | 1408 | 0x580 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | HWVersionMinorH | 1408 | 0x580 | 4 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | HWVersionMajor | 1408 | 0x580 | 8 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | SWVersionMinorL | 1408 | 0x580 | 16 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | SWVersionMinorH | 1408 | 0x580 | 20 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | SWVersionMajor | 1408 | 0x580 | 24 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | vehicleInfo | 1408 | 0x580 | 28 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | SWReleaseYear | 1408 | 0x580 | 32 | 7 | 1 | 0 | 0 | 127 | default |
| Motor3Status3 | SWReleaseDate | 1408 | 0x580 | 39 | 5 | 1 | 0 | 0 | 31 | default |
| Motor3Status3 | SWReleaseMonth | 1408 | 0x580 | 44 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status3 | energyDeviceAddr | 1408 | 0x580 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status3 | programCode | 1408 | 0x580 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status4 | productionUniqueNo | 1409 | 0x581 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| Motor3Status4 | factoryNo | 1409 | 0x581 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| Motor3Status4 | manufactureYear | 1409 | 0x581 | 32 | 7 | 1 | 0 | 0 | 127 | default |
| Motor3Status4 | manufactureDate | 1409 | 0x581 | 39 | 5 | 1 | 0 | 0 | 31 | default |
| Motor3Status4 | manufactureMonth | 1409 | 0x581 | 44 | 4 | 1 | 0 | 0 | 15 | default |
| Motor3Status4 | deviceAddr | 1409 | 0x581 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| Motor3Status5 | AdjustResult | 1410 | 0x582 | 12 | 2 | 1 | 0 | 0 | 3 | default |
| Motor3Status6 | forwardCumulativeCharge | 1411 | 0x583 | 0 | 20 | 1 | 0 | 0 | 10000 | default |
| Motor3Status6 | reverseCumulativeCharge | 1411 | 0x583 | 20 | 20 | 1 | 0 | 0 | 10000 | default |
| BMSStatusStdMsg | maxBattVolt | 1412 | 0x584 | 40 | 8 | 1 | 0 | 0 | 250 | default |
| BMSStatusStdMsg | count | 1412 | 0x584 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| BMSStatusStdMsg | errorLevel | 1412 | 0x584 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| RemoteSignalMsg | id | 1424 | 0x590 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| RemoteSignalMsg | startBtn | 1424 | 0x590 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| RemoteSignalMsg | emergencyBtn | 1424 | 0x590 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| RemoteSignalMsg | horn | 1424 | 0x590 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| RemoteSignalMsg | overtake | 1424 | 0x590 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| ExtObsLocMsg | id | 1440 | 0x5A0 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ExtObsLocMsg | x | 1440 | 0x5A0 | 16 | 22 | 1 | 0 | -2097152 | 2097151 | default |
| ExtObsLocMsg | y | 1440 | 0x5A0 | 38 | 22 | 1 | 0 | -2097152 | 2097151 | default |
| ExtObsLocMsg | cleared | 1440 | 0x5A0 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| ExtObsSpeedMsg | id | 1441 | 0x5A1 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| ExtObsSpeedMsg | speed | 1441 | 0x5A1 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| ExtObsSpeedMsg | heading | 1441 | 0x5A1 | 24 | 9 | 1 | 0 | 0 | 511 | default |
| ErrorReportMsg | id | 1536 | 0x600 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| ErrorReportMsg | type | 1536 | 0x600 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| ErrorReportMsg | error | 1536 | 0x600 | 16 | 32 | 1 | 0 | 0 | 4294967295 | default |
| SecurityWarningMsg | collisionCommsDelay | 1546 | 0x60A | 0 | 1 | 1 | 0 | 0 | 1 | default |
| SecurityWarningMsg | collisionCommsMissing | 1546 | 0x60A | 1 | 1 | 1 | 0 | 0 | 1 | default |
| FileTransferMsg | senderID | 1552 | 0x610 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| FileTransferMsg | receiverID | 1552 | 0x610 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| FileTransferMsg | action | 1552 | 0x610 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| FileTransferMsg | meaning | 1552 | 0x610 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| FileTransferMsg | extra | 1552 | 0x610 | 48 | 16 | 1 | 0 | 0 | 65535 | default |
| FileAckMsg | senderID | 1553 | 0x611 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| FileAckMsg | receiverID | 1553 | 0x611 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| FileAckMsg | ack | 1553 | 0x611 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| FileAckMsg | error | 1553 | 0x611 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| FileAckMsg | index | 1553 | 0x611 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| DataTransferMsg | index | 1554 | 0x612 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| DataTransferMsg | data | 1554 | 0x612 | 8 | 48 | 1 | 0 | 0 | 281474976710655 | default |
| DataTransferMsg | checksum | 1554 | 0x612 | 56 | 8 | 1 | 0 | 0 | 255 | default |
| DataAckMsg | senderID | 1555 | 0x613 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DataAckMsg | receiverID | 1555 | 0x613 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| DataAckMsg | ack | 1555 | 0x613 | 32 | 8 | 1 | 0 | 0 | 255 | default |
| DataAckMsg | error | 1555 | 0x613 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| DataAckMsg | index | 1555 | 0x613 | 48 | 8 | 1 | 0 | 0 | 255 | default |
| IMURot | status | 1569 | 0x621 | 60 | 2 | 1 | 0 | 0 | 3 | default |
| IMURot | sync | 1569 | 0x621 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| IMUAcc | status | 1570 | 0x622 | 48 | 2 | 1 | 0 | 0 | 3 | default |
| IMUAcc | sync | 1570 | 0x622 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| IMUGyr | status | 1571 | 0x623 | 56 | 2 | 1 | 0 | 0 | 3 | default |
| IMUGyr | sync | 1571 | 0x623 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| IMUStatus | status | 1572 | 0x624 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| IMUStatus | warnings | 1572 | 0x624 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| IMUStatus | heading | 1572 | 0x624 | 48 | 12 | 1 | 0 | 0 | 4095 | default |
| IMUStatus | heading_available | 1572 | 0x624 | 60 | 1 | 1 | 0 | 0 | 1 | default |
| ConnectWp | startWp | 1584 | 0x630 | 0 | 19 | 1 | 0 | 0 | 524287 | default |
| ConnectWp | endWp | 1584 | 0x630 | 19 | 19 | 1 | 0 | 0 | 524287 | default |
| ConnectWp | startTrack | 1584 | 0x630 | 38 | 2 | 1 | 0 | 0 | 3 | default |
| ConnectWp | endTrack | 1584 | 0x630 | 40 | 2 | 1 | 0 | 0 | 3 | default |
| ConnectWp | type | 1584 | 0x630 | 42 | 3 | 1 | 0 | 0 | 7 | default |
| ConnectWp | distanceWpForCurved | 1584 | 0x630 | 45 | 3 | 1 | 0 | 0 | 7 | default |
| ConnectWp | restore | 1584 | 0x630 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| TrackCtrlManageMsg | destination | 1616 | 0x650 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlManageMsg | type | 1616 | 0x650 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlManageMsg | time | 1616 | 0x650 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| TrackAckManageMsg | response | 1617 | 0x651 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| TrackAckManageMsg | waypoint | 1617 | 0x651 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackDataManageMsg | id | 1618 | 0x652 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| TrackDataManageMsg | data | 1618 | 0x652 | 8 | 56 | 1 | 0 | 0 | 72057594037927935 | default |
| TrackCtrlDriveMsg | destination | 1632 | 0x660 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlDriveMsg | type | 1632 | 0x660 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlDriveMsg | time | 1632 | 0x660 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| TrackAckDriveMsg | response | 1633 | 0x661 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| TrackAckDriveMsg | waypoint | 1633 | 0x661 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackDataDriveMsg | id | 1634 | 0x662 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| TrackDataDriveMsg | data | 1634 | 0x662 | 8 | 56 | 1 | 0 | 0 | 72057594037927935 | default |
| TrackMD5ReqMsg | id | 1635 | 0x663 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackMD5ReqMsg | path | 1635 | 0x663 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| platStartTxMsg | mode | 1636 | 0x664 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| platStartTxMsg | path | 1636 | 0x664 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| platStartTxMsg | checksum | 1636 | 0x664 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| TrackCtrlObsMsg | destination | 1648 | 0x670 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlObsMsg | type | 1648 | 0x670 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackCtrlObsMsg | time | 1648 | 0x670 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| TrackAckObsMsg | response | 1649 | 0x671 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| TrackAckObsMsg | waypoint | 1649 | 0x671 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| TrackDataObsMsg | id | 1650 | 0x672 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| TrackDataObsMsg | data | 1650 | 0x672 | 8 | 56 | 1 | 0 | 0 | 72057594037927935 | default |
| TrackMD5RespMsg | idXORmd5 | 1651 | 0x673 | 0 | 64 | 1 | 0 | 0 | 18446744073709551615 | default |
| platStartRxMsg | mode | 1652 | 0x674 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| platStartRxMsg | path | 1652 | 0x674 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| platStartRxMsg | checksum | 1652 | 0x674 | 24 | 8 | 1 | 0 | 0 | 255 | default |
| SteerCalibrationMsg | mode | 1664 | 0x680 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| SteerCalibrationMsg | id | 1664 | 0x680 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| SteerConfigMsg | id | 1665 | 0x681 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| SteerConfigReqMsg | AA | 1666 | 0x682 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| SteerConfigReqMsg | id | 1666 | 0x682 | 8 | 16 | 1 | 0 | 0 | 65535 | default |
| SteeringRespMsg | id | 1667 | 0x683 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| SteeringRespMsg | manufactureNo | 1667 | 0x683 | 16 | 8 | 1 | 0 | 0 | 255 | default |
| OdometryParameters | startupCount | 1793 | 0x701 | 40 | 14 | 1 | 0 | 0 | 16383 | default |
| OdometryParameters | adaptiveCount | 1793 | 0x701 | 54 | 10 | 1 | 0 | 0 | 1023 | default |
| ObstaclePcWarning | ObsFrontTopLidarDetectingBody | 1799 | 0x707 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearTopLidarDetectingBody | 1799 | 0x707 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontTopLidarSectionMissing | 1799 | 0x707 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontRightLidarSectionMissing | 1799 | 0x707 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontLeftLidarSectionMissing | 1799 | 0x707 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearTopLidarSectionMissing | 1799 | 0x707 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearRightLidarSectionMissing | 1799 | 0x707 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearLeftLidarSectionMissing | 1799 | 0x707 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontTopLidarCalibration | 1799 | 0x707 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontRightLidarCalibration | 1799 | 0x707 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsFrontLeftLidarCalibration | 1799 | 0x707 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearTopLidarCalibration | 1799 | 0x707 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearRightLidarCalibration | 1799 | 0x707 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsRearLeftLidarCalibration | 1799 | 0x707 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsKeyframeSaverError | 1799 | 0x707 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsOdometryTimeout | 1799 | 0x707 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsKeyframeLoaderDatabaseError | 1799 | 0x707 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ObstaclePcWarning | ObsKeyframeLoaderVersionError | 1799 | 0x707 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| Obsolete_LogIndMsg | logObsoleted | 1808 | 0x710 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| PlatDebugMsg | abortReason | 1810 | 0x712 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| StopDebugMsg | ClosestStop | 1811 | 0x713 | 0 | 4 | 1 | 0 | 0 | 15 | default |
| StopDebugMsg | trafficEventState | 1811 | 0x713 | 8 | 4 | 1 | 0 | 0 | 15 | default |
| StopDebugMsg | junctionManualEventState | 1811 | 0x713 | 12 | 4 | 1 | 0 | 0 | 15 | default |
| StopDebugMsg | closestDistance2Stop | 1811 | 0x713 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| StopDebugMsg | trafficDistance2Stop | 1811 | 0x713 | 32 | 16 | 1 | 0 | 0 | 65535 | default |
| StopDebugMsg | junctionManualDistance2Stop | 1811 | 0x713 | 48 | 16 | 1 | 0 | 0 | 65535 | default |
| DebugMsg | ultrasoundDistance | 1824 | 0x720 | 0 | 16 | 1 | 0 | 0 | 65535 | default |
| DebugMsg | lidarDistance | 1824 | 0x720 | 16 | 16 | 1 | 0 | 0 | 65535 | default |
| FusionFlagsMsg | fus_internal_reset | 1828 | 0x724 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | init_failed | 1828 | 0x724 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | front_steer_invalid | 1828 | 0x724 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | rear_steer_invalid | 1828 | 0x724 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | speed_invalid | 1828 | 0x724 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | time_step_size_invalid | 1828 | 0x724 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | lidar_slam_stddev_nonpositive | 1828 | 0x724 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | cam_slam_stddev_nonpositive | 1828 | 0x724 | 7 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | motor_comms | 1828 | 0x724 | 8 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | front_steer_comms | 1828 | 0x724 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | rear_steer_comms | 1828 | 0x724 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | veh_cholesky_failed | 1828 | 0x724 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | veh_innovation_cov_not_psd | 1828 | 0x724 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | veh_nonpositive_variance | 1828 | 0x724 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | veh_nan_or_inf | 1828 | 0x724 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | odo_cholesky_failed | 1828 | 0x724 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | odo_innovation_cov_not_psd | 1828 | 0x724 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | odo_nonpositive_variance | 1828 | 0x724 | 17 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | odo_nan_or_inf | 1828 | 0x724 | 18 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | drv_req_comms | 1828 | 0x724 | 19 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | front_wheel_speed_comms | 1828 | 0x724 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | rear_wheel_speed_comms | 1828 | 0x724 | 21 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | conflicting_inputs | 1828 | 0x724 | 22 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | saved_antenna_offset_missing | 1828 | 0x724 | 23 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | huge_sensor_update | 1828 | 0x724 | 24 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | safety_relay_open | 1828 | 0x724 | 25 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | drv_info_comms_error | 1828 | 0x724 | 26 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_front_gnss_no_data_ubx | 1828 | 0x724 | 27 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_rear_gnss_no_data | 1828 | 0x724 | 28 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_odometry_suspicious | 1828 | 0x724 | 29 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_gnss_antennas_out_of_range | 1828 | 0x724 | 30 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_no_gnss_period_estimate | 1828 | 0x724 | 31 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_front_gnss_comms | 1828 | 0x724 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_rear_gnss_comms | 1828 | 0x724 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_no_engine_state | 1828 | 0x724 | 34 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_large_gnss_delay | 1828 | 0x724 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | w_large_lidar_delay | 1828 | 0x724 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_lidar_slam_no_data_can | 1828 | 0x724 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_lidar_slam_no_kf | 1828 | 0x724 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_cam_slam_no_data_can | 1828 | 0x724 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_cam_slam_no_kf | 1828 | 0x724 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_using_front_gnss | 1828 | 0x724 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_using_rear_gnss | 1828 | 0x724 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_using_lidar_slam | 1828 | 0x724 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_using_cam_slam | 1828 | 0x724 | 49 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_using_imu_heading | 1828 | 0x724 | 50 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_dead_reckoning | 1828 | 0x724 | 52 | 1 | 1 | 0 | 0 | 1 | default |
| FusionFlagsMsg | st_external_reset | 1828 | 0x724 | 55 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | fusdebugReset | 1829 | 0x725 | 0 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | initialisation | 1829 | 0x725 | 1 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | steerAngleFrontInvalid | 1829 | 0x725 | 2 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | steerAngleRearInvalid | 1829 | 0x725 | 3 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | wheelSpeedInvalid | 1829 | 0x725 | 4 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | timeStepSizeInvalid | 1829 | 0x725 | 5 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | huge_sensor_update | 1829 | 0x725 | 6 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | speedNotAvailableButNotZero | 1829 | 0x725 | 9 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | slamFwdStdDevNonPositive | 1829 | 0x725 | 10 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | slamLatStdDevNonPositive | 1829 | 0x725 | 11 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | slamHeadStdDevNonPositive | 1829 | 0x725 | 12 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | fusionConflictingInputs | 1829 | 0x725 | 13 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | saved_antenna_offset_missing | 1829 | 0x725 | 14 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | safety_relay_open | 1829 | 0x725 | 15 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | drive_info_comms | 1829 | 0x725 | 16 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | cholesky_failed_veh | 1829 | 0x725 | 32 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | innovation_covariance_not_psd_veh | 1829 | 0x725 | 33 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | choleskey_failed_odo | 1829 | 0x725 | 34 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | innovation_convariance_not_psd_odo | 1829 | 0x725 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | steer_angle_front_unavailable | 1829 | 0x725 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | steer_angle_rear_unavailable | 1829 | 0x725 | 37 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | rtk_front_no_data_ubx | 1829 | 0x725 | 38 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | rtk_rear_no_data_ubx | 1829 | 0x725 | 39 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | rtk_front_no_data_can | 1829 | 0x725 | 40 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | rtk_rear_no_data_can | 1829 | 0x725 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | dead_reckoning | 1829 | 0x725 | 42 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | odometry_suspicious | 1829 | 0x725 | 43 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | gnss_antennas_out_of_range | 1829 | 0x725 | 45 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | using_lidar_slam | 1829 | 0x725 | 46 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | using_gps | 1829 | 0x725 | 47 | 1 | 1 | 0 | 0 | 1 | default |
| ErrorFusionDebugMsg | fusion_initialisable | 1829 | 0x725 | 48 | 1 | 1 | 0 | 0 | 1 | default |
| IMUMag | sync | 1831 | 0x727 | 62 | 2 | 1 | 0 | 0 | 3 | default |
| WheelSpeedEvents | first_edge_direction | 1856 | 0x740 | 20 | 1 | 1 | 0 | 0 | 1 | default |
| WheelSpeedEvents | second_edge_direction | 1856 | 0x740 | 41 | 1 | 1 | 0 | 0 | 1 | default |
| WheelSpeedEvents | third_edge_direction | 1856 | 0x740 | 62 | 1 | 1 | 0 | 0 | 1 | default |
| WheelSpeedEvents | overflow | 1856 | 0x740 | 63 | 1 | 1 | 0 | 0 | 1 | default |
| PlatoonSimMsg | subWaypoint | 1873 | 0x751 | 32 | 32 | 1 | 0 | 0 | 4294967295 | default |
| fusionExceptionMsg | ex_addr | 1893 | 0x765 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| fusionExceptionMsg | ex_code | 1893 | 0x765 | 32 | 5 | 1 | 0 | 0 | 31 | default |
| fusionExceptionMsg | user_flag | 1893 | 0x765 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| frontWheelExceptionMsg | ex_addr | 1984 | 0x7C0 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| frontWheelExceptionMsg | ex_code | 1984 | 0x7C0 | 32 | 5 | 1 | 0 | 0 | 31 | default |
| frontWheelExceptionMsg | user_flag | 1984 | 0x7C0 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| rearWheelExceptionMsg | ex_addr | 1985 | 0x7C1 | 0 | 32 | 1 | 0 | 0 | 4294967295 | default |
| rearWheelExceptionMsg | ex_code | 1985 | 0x7C1 | 32 | 5 | 1 | 0 | 0 | 31 | default |
| rearWheelExceptionMsg | user_flag | 1985 | 0x7C1 | 40 | 8 | 1 | 0 | 0 | 255 | default |
| AnyExceptionMsg | moduleId | 2032 | 0x7F0 | 0 | 8 | 1 | 0 | 0 | 255 | default |
| AnyExceptionMsg | taskId | 2032 | 0x7F0 | 8 | 8 | 1 | 0 | 0 | 255 | default |
| AnyExceptionMsg | debug | 2032 | 0x7F0 | 16 | 32 | 1 | 0 | 0 | 4294967295 | default |
| EmulatorLatitudeMsg | sign | 2034 | 0x7F2 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| EmulatorLatitudeMsg | outlier | 2034 | 0x7F2 | 36 | 1 | 1 | 0 | 0 | 1 | default |
| EmulatorLatitudeMsg | time | 2034 | 0x7F2 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| EmulatorLongitude | sign | 2035 | 0x7F3 | 35 | 1 | 1 | 0 | 0 | 1 | default |
| EmulatorLongitude | quality | 2035 | 0x7F3 | 36 | 4 | 1 | 0 | 0 | 7 | default |
| EmulatorLongitude | time | 2035 | 0x7F3 | 40 | 24 | 1 | 0 | 0 | 16777215 | default |
| EmulatorHeadingMsg | heading | 2036 | 0x7F4 | 0 | 16 | 1 | 0 | 0 | 65535 | default |

## 추가 점검 메모

- EHBPowerMsg_t.current: composite decode uses current, currentEx in dbc_CAN.h:1028; individual DBC signals kept raw/default
- EHBPowerMsg_t.current: split temp assignment in dbc_CAN.h:1009 requires manual review
- EHBPowerMsg_t.currentEx: split temp assignment in dbc_CAN.h:1009 requires manual review
- EHBPowerMsg_t.s16_ADC: composite decode uses s16_ADC, s16_ADCEx in dbc_CAN.h:1028; individual DBC signals kept raw/default
- EHBPowerMsg_t.s16_ADC: split temp assignment in dbc_CAN.h:1009 requires manual review
- EHBPowerMsg_t.s16_ADCEx: split temp assignment in dbc_CAN.h:1009 requires manual review
- EHBReqMsg_t.speed: composite decode uses speed, speedEx in dbc_CAN.h:1222; individual DBC signals kept raw/default
- EHBReqMsg_t.speed: split temp assignment in dbc_CAN.h:1204 requires manual review
- EHBReqMsg_t.speedEx: split temp assignment in dbc_CAN.h:1204 requires manual review
- EHBT060PowerMsg_t.cylinderPosition: composite decode uses cylinderPosition, cylinderPositionEx in dbc_CAN.h:1078; individual DBC signals kept raw/default
- EHBT060PowerMsg_t.cylinderPosition: split temp assignment in dbc_CAN.h:1059 requires manual review
- EHBT060PowerMsg_t.cylinderPositionEx: split temp assignment in dbc_CAN.h:1059 requires manual review
- EHBT060PowerMsg_t.s16_ADC: composite decode uses s16_ADC, s16_ADCEx in dbc_CAN.h:1078; individual DBC signals kept raw/default
- EHBT060PowerMsg_t.s16_ADC: split temp assignment in dbc_CAN.h:1059 requires manual review
- EHBT060PowerMsg_t.s16_ADCEx: split temp assignment in dbc_CAN.h:1059 requires manual review
- GPSLatitudeMsg_t.latitude: decode expression not parsed in dbc_CAN.h:1892: -(msg->raw.signals.latitude * 0.00000001)
- LatitudeMsg_t.latitude: decode expression not parsed in dbc_CAN.h:2584: -(msg->raw.signals.latitude * 0.00000001)
- LongitudeMsg_t.longitude: decode expression not parsed in dbc_CAN.h:2620: -(msg->raw.signals.longitude * 0.00000001)
