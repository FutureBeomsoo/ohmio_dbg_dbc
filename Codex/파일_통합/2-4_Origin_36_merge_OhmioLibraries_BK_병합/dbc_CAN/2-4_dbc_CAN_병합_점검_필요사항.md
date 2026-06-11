# 2-4_dbc_CAN_병합 점검 필요사항

| 대상 | 내용 |
| --- | --- |
| BK-only struct `ErrorMotorAdaptor` | 활성 추가 제외 확정. `CAN_ID_ERROR_MOTOR_ADAPTOR` 0x2D는 Origin `CAN_ID_ERROR_NETWORK` 0x2D 정의를 유지한다. |
| BK-only struct `ErrorTrans` | 활성 추가 제외 확정. `CAN_ID_ERROR_TRANS`와 `CAN_ID_TRANS1_ERROR`는 사실상 같은 message로 판단하고 Origin 정의를 유지한다. |
| BK-only enum | `TransErrorCode` 활성 추가 제외 확정. |
| BK-only struct `BrakeReqMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x160 |
| BK-only struct `CombinedHeightMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x223, 0x234 |
| BK-only struct `CompassMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x260 |
| BK-only struct `DeviationReqMsg` | 활성 추가 제외 확정. `additionalDbcCan.h`에서 이미 정의 처리되어 `dbc_CAN.h`에는 중복 추가하지 않는다; message ID: 0x2c5 |
| BK-only struct `DriveInfoMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x321 |
| BK-only struct `DynamicTrackValidationMsg` | 활성 추가 제외 확정. `additionalDbcCan.h`에서 이미 정의 처리되어 `dbc_CAN.h`에는 중복 추가하지 않는다; message ID: 0x300 |
| BK-only struct `FusionFrontLongitude` | 활성 추가 제외 확정. `additionalDbcCan.h`에서 이미 정의 처리되어 `dbc_CAN.h`에는 중복 추가하지 않는다; message ID: 0x21a |
| BK-only struct `FusionLatitudeMsg` | 활성 추가 제외 확정. `FusionLatitudeFrontMsg`(0x210), `FusionLatitudeRearMsg`(0x213)에 대응되는 `LatitudeMsg_t`가 정의되어 있으며, 같은 이유로 `FusionLatitudeMsg_ToCan/FromCan`은 `LatitudeMsg_ToCan/FromCan`에 반영한다. |
| BK-only struct `GPSLatitudeMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x220, 0x230 |
| BK-only struct `HeadingMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x233 |
| BK-only struct `HeightMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x222, 0x232 |
| BK-only struct `LogIndMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x710 |
| BK-only struct `ObstacleDetectionLiDARMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x120 |
| BK-only struct `PrintASCIIMsg` | 활성 추가 제외 확정. Origin 정의를 유지한다; message ID: 0x7f0 |
| BK-only struct `StopReqMsg` | 활성 추가 제외 확정. `additionalDbcCan.h`에서 이미 정의 처리되어 `dbc_CAN.h`에는 중복 추가하지 않는다; message ID: 0x326 |
| BK-only struct `UWBDistanceMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x250 |
| BK-only struct `UWBLatitudeMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x251 |
| BK-only struct `UWBLongitudeMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x252 |
| BK-only struct `UltraSoundMsg` | BK 정의 반영 확정. Origin `ObsoleteMsg` 기준 정의는 주석 표기하고 후속 header 수정 작업에서 반영 필요; message ID: 0x121 |
| `0x221`, `0x231` Longitude mapping | 설명 필요. BK에서는 `LongitudeMsg_t`에 포함되지만 현재 결과는 `ObsoleteMsg_t` comment와 `LongitudeMsg_t` comment가 분리되어 있어 후속 정리 필요. |
| `IMUMag_ToCan()` `status` assert | 활성 추가 제외 확정. Origin 우성 규칙에 따라 struct 내 `status`는 제외한다. |
| `SystemReqMsg` | 사용자 확정 layout 반영 필요. bits0-7 `mode`, bits32-39 `brakePressure`, bits40-59 `reserved`, bits60-61 `driveDisalowed`로 후속 header 수정 작업에서 반영한다. |
| `TransDriveMsg`, `TeleOpMsg`, `TransJoystickMsg` mapping | 설명 필요. BK에서 `TransDriveMsg`(0x187)는 `ManualDriveMsg_t`, `TeleOpMsg`(0x183)와 `TransJoystickMsg`(0x188)는 `JoystickMsg_t`에 함께 매핑되므로 후속 comment/alias 정리 필요. |
| `TrackCtrlObsMsg`, `TrackAckObsMsg`, `TrackDataObsMsg` mapping | 설명 필요. BK에서 0x670/0x671/0x672는 `TrackCtrlMsg_t`/`TrackAckMsg_t`/`TrackDataMsg_t`에 함께 매핑되므로 후속 comment/alias 정리 필요. |
| 공통 function 활성 반영 | layout 충돌 message의 BK function 활성 반영 상태를 유지한다. 충돌 주석이 있는 함수는 후속 동작 검증 권장. |

## 사용자 의견
    ErrorMotorAdaptor : 활성 추가 제외 확정. - CAN ID 0x02D 에대하여 Origin 정의 그대로 반영.
    ErrorTrans : 활성 추가 제외 확정. - CAN_ID_ERROR_TRANS 와 CAN_ID_TRANS1_ERROR은 사실상 같은 Message로 판단, Origin 정의 그대로 반영.
    `TransErrorCode` : 활성 추가 제외 확정.
    다음 Message(Struct) 에 대한 정의는 OhmioLibraries_BK 정의를 반영 확정하고, Origin_36_merge 기준 정의 주석 표기. - Origin_36_merge기준 Signal(Member)가 모두 reserved
        'message ID 0x120 Obsolte_ObsLidarMsg' 
        'message ID 0x121 Obsolete_UltraSoundMsg'
        'message ID 0x160 Obsolete_BrakeReqMsg'
        'message ID 0x220 Obsolete_latitudeFrontMsg'
        'message ID 0x221 Obsolete_longitudeFrontMsg'
        'message ID 0x222 Obsolete_heightFrontMsg'
        'message ID 0x223 Obsolete_combineHeightFrontMsg'
        'message ID 0x230 Obsolete_latitudeBackMsg'
        'message ID 0x231 Obsolete_longitudeBackMsg'
        'message ID 0x232 Obsolete_heightBackMsg'
        'message ID 0x233 Obsolete_HeadingMsg'
        'message ID 0x234 Obsolete_combineHeightBackMsg'
        'message ID 0x250 Obsolete_UWBDistanceMsg'
        'message ID 0x251 Obsolete_UWBLatitudeMsg'
        'message ID 0x252 Obsolete_UWBLongitudeMsg'
        'message ID 0x260 Obsolete_CompassMsg'
        'message ID 0x321 Obsolete_DriveInfoMsg'
        'message ID 0x710 Obsolete_LogIndMsg'
    
        0x221 0x231 왜 누락 되었는지 설명 필요.

    'DeviationReqMsg' 'DynamicTrackValidationMsg' 'FusionFrontLongitude' 'StopReqMsg' : 활성 추가 제외 확정 - additionalDbcCan에서 이미 정의 처리.


    `FusionLatitudeMsg` : 활성 추가 제외 확정 - 같은 Message FusionLatitudeFrontMsg(0x210) FusionLatitudeRearMsg(0x213)에 대응 되는 LatitudeMsg_t 가 정의 되어 있음.
        같은 이유로 FusionLatitudeMsg_ToCan() FusionLatitudeMsg_FromCan() 함수 정의 대해서 LatitudeMsg_ToCan() LatitudeMsg_FromCan()에 반영.

    'PrintASCIIMsg' : 활성 추가 제외 확정 - Origin 정의 반영.

    `IMUMag_ToCan()` `status` assert : 활성 추가 제외 확정. - Origin 우성 규칙에 따라 struct 내 `status` 제외.

    message ID 0x320 SystemReqMsg :
        bits 0-7 : mode , bit 32-39 : brakePressure, bit 40-59 :  reserved, bit 60-61 : driveDisalowed 로 반영
        mode : Origin_36_merge 의 6-7 에서  reserved임으로 해당 부분까지 mode로 정의해도 충돌이 없음.
        brakePressure : 해당 위치에 Origin_36_merg가 reserved임으로 brakePressure로 정의해도 충돌이 없음.
        driveDisalowed : 해당 위치에 OhmioLibraries_BK가 reserved임으로 driveDisalowed로 정의해도 충돌이 없음.
    
    message ID 0x187 TransDriveMsg 누락 이유 설명 필요.
    message ID 0x183 TeleOpMsg 누락 이유 설명 필요.
    message ID 0x188 TransJoystickMsg 누락 이유 설명 필요.
    message ID 0x670 TrackCtrlObsMsg
    message ID 0x671 TrackAckObsMsg 누락 이유 설명 필요.
    message ID 0x672 TrackDataObsMsg 누락 이유 설명 필요.
    
