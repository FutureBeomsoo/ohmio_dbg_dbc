# 2-2_Origin_36_merge_재비교 점검 필요사항

재비교 결과에서 사용자 확인이 필요한 항목이다.

## 신규 점검 필요사항

| 대상 | 점검 필요 내용 | 설명 |
| --- | --- | --- |
| OhmioLibraries_BK 전체 | BK까지 통합 대상인지 재확인 필요 | `Origin_36_merge`는 Origin+36 기준으로 정리된 상태이며, BK 대비 대규모 schema 차이가 남아 있다. |
| BK `dbc_CAN.h` | BK-only message/struct 처리 필요 | `BrakeReqMsg`, `DriveInfoMsg`, `DynamicTrackValidationMsg`, `DeviationReqMsg`, `StopReqMsg`, `FusionFrontLongitude`, `UltraSoundMsg`, `ErrorTrans`, `ErrorMotorAdaptor`, `LogIndMsg` 등 BK에만 있는 항목을 통합할지 제외할지 판단 필요. |
| BK `dbc_MsgID_main.h` | BK-only CAN_ID 처리 필요 | `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK`, `CAN_ID_ERROR_TRANS`, `CAN_ID_ERROR_MOTOR_ADAPTOR`, `CAN_ID_OBSTACLE_CTRL/ACK/TRACK` 등을 통합할지 제외할지 판단 필요. |
| BK main version/hash | 정책 확인 필요 | BK는 `MAIN_CANBUS_VERSION_MAJOR 2`, `MINOR 110`, `BUILD 0x47AB1E0D`; 통합본은 `MAJOR 4`, `MINOR 15`, `BUILD 0xBEC99F67`이다. |
| BK `additionalDbcCan.h`, `dbc_CAN_peripheral.h` | 변환 함수 구현 위치 확인 필요 | BK는 다수 변환 함수를 header 내부 `static` 구현으로 포함하고, 통합본은 선언만 둔다. 실제 구현 파일 기준 확인이 필요하다. |
| BK `ConversionHelper.h` | 동작 정책 확인 필요 | BK는 음수 입력에 assert를 사용하고 통합본은 0으로 clamp한다. 변환 정책 확인이 필요하다. |
| BK peripheral schema | 통합/제외 판단 필요 | AirCon, BMS charging current, Recovery, BMSStatusMsg8 등 peripheral schema가 BK와 통합본 사이에서 다르다. |

## 점검 필요사항 아님

| 대상 | 상태 | 설명 |
| --- | --- | --- |
| Origin/36 대비 `Obs_Keyframe_*` 차이 | 사용자 확인 완료 | `Obs_Keyframe_Saver`, `ObsKeyframeSaverError` 유지로 확정된 항목이다. |
| Origin/36 대비 `FusionFlagsMsg_t` bit34 | 사용자 확인 완료 | `w_no_engine_state` 유지, 36 명칭 주석 표기로 확정된 항목이다. |
| Origin/36 대비 version/hash | 사용자 확인 완료 | 현재 통합본 version/hash 유지로 확정된 항목이다. |