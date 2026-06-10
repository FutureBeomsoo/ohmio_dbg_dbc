# 2-1_Origin_36_병합 점검 필요사항

통합 결과에서 사용자 확인이 필요한 항목이다.

| 파일 | 위치/대상 | 점검 필요 내용 | 현재 처리 |
| --- | --- | --- | --- |
| 없음 | 없음 | 현재 남아 있는 사용자 점검 필요 항목 없음 | 모든 기존 점검 항목은 사용자 확인 완료 항목으로 이관 |


## 사용자 확인 완료 항목

| 파일 | 위치/대상 | 사용자 확인 | 반영 내용 |
| --- | --- | --- | --- |
| `dbc_CAN.h` | `FusionFlagsMsg_t` bit34 | `w_no_engine_state`로 확정 | `w_no_engine_state` 유지, `OhmioLibraries_36` 기준 명칭 `no_engine_state`는 주석으로 표기 |
| `dbc_MsgID_main.h` | version/hash | 현재 내용 유지 | `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67` 유지. 36 기준 값은 주석으로 표기 |
| `dbc_MsgID_main.h` | `CAN_ID_FUSION_FLAGS` | `FusionFlagsMsg_t` 기준 따름 | bit34 `w_no_engine_state` 포함 현재 `FusionFlagsMsg_t` 구조 기준 설명 유지 |
| `dbc_CAN.h` | `ObstaclePcWarningErrorCode` | `Obs_Keyframe_Saver`로 정의 | `Obs_Keyframe_Saver` 유지, `Obs_Keyframe_Database = Obs_Keyframe_Saver` alias 제거 |
| `dbc_CAN.h` | `ObstaclePcWarning_t` bit14 | Origin의 `ObsKeyframeSaverError` 유지 | 36의 `ObsKeyframeDatabaseError` 명칭은 병합 기준에서 제외 |
| `dbc_MsgID_main.h` | `CAN_ID_OBSTACLE_PC_WARNING` | Origin 기준 설명 유지 | bit14 `ObsKeyframeSaverError`, bit16 `ObsKeyframeLoaderDatabaseError`, bit17 `ObsKeyframeLoaderVersionError` 유지 |
