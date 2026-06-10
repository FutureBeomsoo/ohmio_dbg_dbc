# 2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영 예정 작업계획

## 작업 목적

`2-1_Origin_36_병합` 결과에 대해 사용자가 확인한 `ObstaclePcWarning_t` bit14 판단을 반영한다.

- 사용자 확인: `Obs_Keyframe_Saver`로 정의
- 적용 기준: Origin의 `ObsKeyframeSaverError` 유지
- 36의 `ObsKeyframeDatabaseError` 명칭은 병합 기준에서 제외

## 작업 구분

이 작업은 기존 `2-1_Origin_36_병합`의 추가 수정 작업이다.

- 원 작업: `Codex/파일_통합/2-1_Origin_36_병합/`
- 수정 작업 기록 위치: `Codex/파일_통합/2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영/`
- 원본 폴더 `OhmioLibraries`, `OhmioLibraries_36`는 수정하지 않는다.
- `2-2. 2-1 결과 재비교`는 이 작업에 포함하지 않는다.


## 수정 대상

사용자 동의 후 아래 파일만 수정한다.

| 파일 | 수정 내용 |
| --- | --- |
| `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h` | `ObstaclePcWarningErrorCode`에서 `Obs_Keyframe_Database = Obs_Keyframe_Saver` alias 제거. `ObstaclePcWarning_t` bit14의 `OHMIO_INTEGRATION_CHECK` 주석 제거 또는 확정 반영 주석으로 변경. `Obs_Keyframe_Saver`, `ObsKeyframeSaverError`는 유지 |
| `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h` | `CAN_ID_OBSTACLE_PC_WARNING`의 bit14 충돌 점검 주석 제거 또는 확정 반영 주석으로 변경. Origin 기준 bit14 `ObsKeyframeSaverError`, bit16-17 설명은 유지 |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_점검_필요사항.md` | 활성 점검 표에서 `ObstaclePcWarning_t` bit14 항목 제거. `사용자 확인 완료 항목`에 표 형식으로 반영 |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_작업내용.md` | 기존 alias 추가/충돌 점검 기록을 사용자 확인 완료 및 Origin 기준 확정 내용으로 수정 |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_작업기록.md` | 이번 수정 작업 로그를 append |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_오류사항.md` | 수정 중 오류가 있으면 append, 없으면 오류 없음 기록 append |

## 적용 기준

- `Obs_Keyframe_Saver`와 `ObsKeyframeSaverError`를 확정 기준으로 둔다.
- `Obs_Keyframe_Database`, `ObsKeyframeDatabaseError`는 통합 헤더 코드에서 제거한다.
- 사용자 확인 완료 항목은 더 이상 점검 필요 항목으로 남기지 않는다.
- 다른 점검 필요 항목인 `FusionFlagsMsg_t` bit34, version/hash, `CAN_ID_FUSION_FLAGS`는 이번 작업에서 확정하지 않는다.

## 검증 계획

사용자 동의 후 수정 적용 뒤 아래를 확인한다.

1. 통합 헤더 코드에서 `Obs_Keyframe_Database`, `ObsKeyframeDatabaseError`가 남아 있지 않은지 확인한다.
2. `Obs_Keyframe_Saver`, `ObsKeyframeSaverError`가 유지되는지 확인한다.
3. `dbc_CAN.h`, `dbc_MsgID_main.h` 문법 검사를 수행한다.
4. 점검 필요사항 문서에서 `ObstaclePcWarning_t` bit14가 활성 점검 표가 아닌 사용자 확인 완료 항목에만 있는지 확인한다.

## 진행 조건

이 문서는 작업계획이다. 사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 수정 작업을 진행한다.


## 사용자 확인
- 해당 작업은 파일통합/2-1_OhmioLibraries_OhmioLibraries_36_병합/2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영 의 카테고리로 보는게 맞지않은가?

- `Obs_Keyframe_Database` 에 대한 주석 내용 표시. 
    e.g. // OhmioLibraries_36 기준 Obs_Keyframe_Database 로 표기.
