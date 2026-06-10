# dbc_MsgID_main.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- 우측: `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h`
- 비교 목적: BK 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - BK 대비 미통합/대체 후보 다수

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| version/hash | 통합본 유지 | BK `MAJOR 2`, `MINOR 110`, `BUILD 0x47AB1E0D` 대비 통합본은 `MAJOR 4`, `MINOR 15`, `BUILD 0xBEC99F67`이다. |
| 통합본에만 있는 대표 CAN_ID | 통합본 추가 | `CAN_ID_TIMEPULSE_FRONT`, `CAN_ID_TIMEPULSE_REAR`, `CAN_ID_RESET_JOYSTICK`, `CAN_ID_RESET_TRANSLATOR2`, `CAN_ID_RESET_TELE_OP`, `CAN_ID_ERROR_TELE_OP`, `CAN_ID_ATMEL_TELEOP_ERROR`, `CAN_ID_OBSTACLE_DANGER_ZONE_STOP`, `CAN_ID_CONNECT_WP`, `CAN_ID_OBSTACLE_PC_WARNING`, `CAN_ID_EXT_OBS_LOC`, `CAN_ID_EXT_OBS_SPEED`, `CAN_ID_IMU_STATUS`, `CAN_ID_FUSION_PERSISTENT_PARAMS`, `CAN_ID_EMULATOR_LAT/LONG/HEADING` 등이 통합본에만 있다. |
| BK에만 있는 CAN_ID | BK 미반영 후보 | `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK`, `CAN_ID_ERROR_TRANS`, `CAN_ID_ERROR_MOTOR_ADAPTOR`, `CAN_ID_OBSTACLE_CTRL`, `CAN_ID_OBSTACLE_ACK`, `CAN_ID_OBSTACLE_TRACK` 등이 BK에만 있다. |
| changed CAN_ID 설명 | 대규모 차이 | `CAN_ID_STARTUP_ERROR`, `CAN_ID_ERROR_DRIVE_EXT`, `CAN_ID_FUS_ERROR`, `CAN_ID_MANAGEMENT_ERROR`, `CAN_ID_FRONT_WHEEL_CNT`, `CAN_ID_OBSTACLE_DANGER_ZONE`, `CAN_ID_OBSTACLE_TRACK_DISTANCE`, `CAN_ID_FUSION_HEIGHT`, `CAN_ID_FUSION_FLAGS`, `CAN_ID_ERROR_FUSION_DEBUG`, `CAN_ID_FUSION_EXCEPTION` 등 설명이 다르다. |
| enum 차이 | 통합본 추가/변경 | `CONNECT_TRACK_TYPE`, `RESET_PARAMETER`는 통합본에만 있고, `PARAMETER_ID`, `STOP_REASON`, `SYSTEM_MODE` 등 값/entry 차이가 있다. |

## 재비교 판단

- BK 대비 차이는 기존 `2-1` 사용자 확인 완료 항목과 별개로 검토해야 한다.
- 이번 `2-2` 작업에서는 분석만 수행하며 통합본 코드는 수정하지 않는다.
