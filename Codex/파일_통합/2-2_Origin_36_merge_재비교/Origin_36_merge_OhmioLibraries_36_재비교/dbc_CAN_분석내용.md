# dbc_CAN.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- 우측: `OhmioLibraries_36/include/canbus/dbc_CAN.h`
- 비교 목적: 36 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - Origin 유지 및 사용자 확인 결과

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| ConnectWp_t | Origin 유지 | 36에는 없는 `ConnectWp_t`를 통합본에 유지했다. |
| ErrorDriveExt_t | Origin 유지 | `Drvext_EPB1_Comms`, `Drvext_EPB2_Comms` 및 대응 bitfield를 유지했다. |
| ObstacleTrackDistanceMsg_t | Origin 유지 | bits44-58 reserved, bits59-63 `BackDistance` 및 double `BackDistance`를 유지했다. |
| FusionHeight_t | Origin 유지 | bits57-63 `compute_time` 및 double `compute_time`을 유지했다. |
| FusionFlagsMsg_t bit34 | 사용자 확인 완료 | 36의 `no_engine_state` 대신 `w_no_engine_state`로 확정했다. 36 명칭은 주석으로만 남겼다. |
| FusionFlagsMsg_t bits35-36 | Origin 유지 | 36은 bits35-39를 reserved로 보지만 통합본은 `w_large_gnss_delay`, `w_large_lidar_delay`, `reserved1:3` 구조를 유지했다. |
| ObstaclePcWarningErrorCode | 사용자 확인 완료 | 36의 `Obs_Keyframe_Database` 대신 `Obs_Keyframe_Saver`를 유지하고 loader 관련 두 항목을 유지했다. |
| ObstaclePcWarning_t bit14 | 사용자 확인 완료 | 36의 `ObsKeyframeDatabaseError` 대신 `ObsKeyframeSaverError`를 유지했다. bit16-17 loader error도 유지했다. |

## 재비교 판단

- 신규 사용자 점검 필요사항 없음.
- 이번 `2-2` 작업에서는 통합본 코드를 수정하지 않는다.
