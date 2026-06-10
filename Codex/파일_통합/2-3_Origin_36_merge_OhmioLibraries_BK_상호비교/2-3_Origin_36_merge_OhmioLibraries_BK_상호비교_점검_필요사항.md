# 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교 점검 필요사항

상호 비교 결과에서 사용자 판단이 필요한 항목이다.

## 점검 필요사항

| 대상 | 점검 필요 내용 | 설명 |
| --- | --- | --- |
| BK 전체 | BK schema 통합 범위 판단 필요 | BK 대비 6개 header에서 차이가 있고, main/peripheral schema 모두 대규모 차이가 있다. |
| `dbc_CAN.h` BK-only struct/message | 통합/제외 판단 필요 | `BrakeReqMsg`, `CombinedHeightMsg`, `CompassMsg`, `DriveInfoMsg`, `DynamicTrackValidationMsg`, `DeviationReqMsg`, `StopReqMsg`, `FusionFrontLongitude`, `GPSLatitudeMsg`, `UWBLatitudeMsg`, `UWBLongitudeMsg`, `UltraSoundMsg`, `ErrorMotorAdaptor`, `ErrorTrans`, `LogIndMsg`, `PrintASCIIMsg` 등 BK-only 항목이 있다. |
| `dbc_MsgID_main.h` BK-only CAN_ID | 통합/제외 판단 필요 | `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK`, `CAN_ID_ERROR_TRANS`, `CAN_ID_ERROR_MOTOR_ADAPTOR`, `CAN_ID_OBSTACLE_CTRL`, `CAN_ID_OBSTACLE_ACK`, `CAN_ID_OBSTACLE_TRACK` 등이 BK에만 있다. |
| main version/hash | 정책 판단 필요 | BK는 `MAIN_CANBUS_VERSION_MAJOR 2`, `MINOR 110`, `BUILD 0x47AB1E0D`; Origin_36_merge는 `MAJOR 4`, `MINOR 15`, `BUILD 0xBEC99F67`이다. |
| `dbc_CAN.h` 공통 message layout | 충돌 판단 필요 | `WheelCountMsg`, `SystemReqMsg`, `ManagementError`, Fusion/Obstacle/error 계열 등 공통 message의 bit 구조 차이가 있다. |
| `dbc_MsgID_main.h` 공통 CAN_ID 설명 | 충돌 판단 필요 | `CAN_ID_FUSION_FLAGS`, `CAN_ID_FUSION_HEIGHT`, `CAN_ID_ERROR_FUSION_DEBUG`, `CAN_ID_OBSTACLE_TRACK_DISTANCE`, `CAN_ID_STARTUP_ERROR` 등 설명/bit mapping 차이가 있다. |
| `additionalDbcCan.h` / `dbc_CAN_peripheral.h` 함수 구현 | 구현 위치 정책 확인 필요 | BK는 header 내부 `static` 구현을 포함하고, Origin_36_merge는 prototype 중심이다. |
| `ConversionHelper.h` | 변환 정책 확인 필요 | BK는 음수 입력 assert를 사용하고, Origin_36_merge는 `value <= 0`을 0으로 clamp한다. |
| `dbc_CAN_peripheral.h` peripheral schema | 통합/제외 판단 필요 | AirCon, BMS charging current, Recovery, BMSStatusMsg8 등 peripheral message 구조 차이가 있다. |
| `dbc_MsgID_peripheral.h` peripheral version/hash | 정책 판단 필요 | BK는 `PERIPHERAL_CANBUS_VERSION_MAJOR 1`, `MINOR 12`, `BUILD 0x0E350456`; Origin_36_merge는 `MAJOR 2`, `MINOR 3`, `BUILD 0xD1134632`이다. |

## 점검 필요사항 없음으로 분류한 항목

| 대상 | 판정 |
| --- | --- |
| `Security_CAN.h` | 파일 동일 |
| `dbc_MsgID_security.h` | 파일 동일 |
