# 2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영 점검 필요사항

이번 수정 작업에서 새로 발생한 사용자 점검 필요사항은 없다.

## 확인 완료

| 대상 | 상태 |
| --- | --- |
| `ObstaclePcWarningErrorCode` | `Obs_Keyframe_Saver` 유지, `Obs_Keyframe_Database` 제거 |
| `ObstaclePcWarning_t` bit14 | `ObsKeyframeSaverError` 유지, `ObsKeyframeDatabaseError` 제외 |
| `CAN_ID_OBSTACLE_PC_WARNING` | Origin 기준 설명 유지 |

## 남아 있는 기존 점검 항목

아래 항목은 이번 수정 작업 범위가 아니므로 기존 `2-1_Origin_36_병합_점검_필요사항.md`에 남겨 두었다.

| 대상 | 상태 |
| --- | --- |
| `FusionFlagsMsg_t` bit34 | 사용자 확인 필요 |
| `dbc_MsgID_main.h` version/hash | 사용자 확인 필요 |
| `CAN_ID_FUSION_FLAGS` | 사용자 확인 필요 |
