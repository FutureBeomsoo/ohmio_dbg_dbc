# dbc_MsgID_main.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- 우측: `OhmioLibraries/include/canbus/dbc_MsgID_main.h`
- 비교 목적: Origin 대비 통합본 변경/추가 반영 확인

## 결과 요약

- 상태: 차이 있음 - 병합 반영 결과

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| version/hash | 사용자 확인 완료 | Origin 값 `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67`을 유지한다. 36 기준 version/hash는 참고 주석으로 기록했다. |
| CAN_ID_FUS_ERROR bit22 | 36 반영 | 설명을 `reserved`에서 `fus_conflicting_inputs`로 갱신했다. |
| CAN_ID_FUSION_FLAGS bit22 | 36 반영 | 설명을 `reserved`에서 `conflicting_inputs`로 갱신했다. |
| CAN_ID_FUSION_FLAGS bit34 | 사용자 확인 완료 | `FusionFlagsMsg_t` 기준 설명을 유지하고 36 기준 명칭은 참고 주석으로 표기했다. |

## 재비교 판단

- 신규 사용자 점검 필요사항 없음.
- 이번 `2-2` 작업에서는 통합본 코드를 수정하지 않는다.
