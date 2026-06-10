# dbc_CAN.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- 우측: `OhmioLibraries/include/canbus/dbc_CAN.h`
- 비교 목적: Origin 대비 통합본 변경/추가 반영 확인

## 결과 요약

- 상태: 차이 있음 - 병합 반영 결과

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| FusErrorCode bit22 | 36 반영 | Origin의 `fus_Reserved` 위치를 36의 실제 signal `fus_conflicting_inputs`로 대체했다. Origin 명칭은 주석으로 남겼다. |
| FusError_t bit22 | 36 반영 | Origin의 `reserved` bit를 `fus_conflicting_inputs`로 대체했다. Origin 명칭은 주석으로 남겼다. |
| FusionFlagsMsg_t bit22 | 36 반영 | Origin의 `reserved` bit를 `conflicting_inputs`로 대체했다. |
| FusionFlagsMsg_t bit34 | 사용자 확인 완료 | `w_no_engine_state`를 유지하고 36 기준 `no_engine_state` 명칭은 참고 주석으로 표기했다. |

## 재비교 판단

- 신규 사용자 점검 필요사항 없음.
- 이번 `2-2` 작업에서는 통합본 코드를 수정하지 않는다.
