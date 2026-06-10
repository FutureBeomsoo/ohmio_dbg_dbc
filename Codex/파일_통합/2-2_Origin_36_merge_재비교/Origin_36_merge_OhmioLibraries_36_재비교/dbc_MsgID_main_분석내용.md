# dbc_MsgID_main.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- 우측: `OhmioLibraries_36/include/canbus/dbc_MsgID_main.h`
- 비교 목적: 36 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - Origin 유지 및 사용자 확인 결과

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| version/hash | 사용자 확인 완료 | 36 값 `MINOR 9`, `BUILD 0xE3A942C4` 대신 통합본 값 `MINOR 15`, `BUILD 0xBEC99F67`을 유지했다. |
| CAN_ID_ERROR_DRIVE_EXT | Origin 유지 | 36 설명에는 bit6-7이 없지만 통합본은 EPB1/EPB2 comms error 설명을 유지했다. |
| CAN_ID_OBSTACLE_TRACK_DISTANCE | Origin 유지 | 통합본은 reserved/back distance 설명을 유지했다. |
| CAN_ID_FUSION_HEIGHT | Origin 유지 | 통합본은 `compute_time` 설명을 유지했다. |
| CAN_ID_CONNECT_WP / CONNECT_TRACK_TYPE | Origin 유지 | 36에는 없지만 통합본에 유지했다. |
| CAN_ID_OBSTACLE_PC_WARNING | 사용자 확인 완료 | 36 bit14 `ObsKeyframeDatabaseError` 대신 Origin 기준 saver/loader 설명을 유지했다. |
| CAN_ID_FUSION_FLAGS | 사용자 확인 완료 | `FusionFlagsMsg_t` 기준 설명을 유지했다. bit34는 `w_no_engine_state`로 확정했다. |

## 재비교 판단

- 신규 사용자 점검 필요사항 없음.
- 이번 `2-2` 작업에서는 통합본 코드를 수정하지 않는다.
