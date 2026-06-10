# 2-1_Origin_36_병합_수정_잔여점검항목_확정반영 예정 작업계획

## 작업 목적

`2-1_Origin_36_병합_점검_필요사항.md`에 남아 있는 점검 필요 항목 3개에 대해 사용자가 작성한 확인 내용을 반영한다.

## 사용자 확인 내용

| 대상 | 사용자 확인 |
| --- | --- |
| `FusionFlagsMsg_t` bit34 | `w_no_engine_state`로 확정. `OhmioLibraries_36` 기준 명칭 `no_engine_state`는 주석으로 표기 |
| `dbc_MsgID_main.h` version/hash | 현재 내용 유지 |
| `CAN_ID_FUSION_FLAGS` | `FusionFlagsMsg_t` 기준을 따름 |

## 작업 구분

이 작업은 기존 `2-1_Origin_36_병합`의 추가 수정 작업이다.

- 원 작업: `Codex/파일_통합/2-1_Origin_36_병합/`
- 수정 작업 기록 위치: `Codex/파일_통합/2-1_Origin_36_병합_수정_잔여점검항목_확정반영/`
- 원본 폴더 `OhmioLibraries`, `OhmioLibraries_36`는 수정하지 않는다.
- `2-2. 2-1 결과 재비교`는 이 작업에 포함하지 않는다.

## 수정 대상

사용자 동의 후 아래 파일만 수정한다.

| 파일 | 수정 내용 |
| --- | --- |
| `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h` | `FusionFlagsMsg_t` bit34의 `OHMIO_INTEGRATION_CHECK` 주석을 확정 주석으로 변경. 필드명 `w_no_engine_state`는 유지하고, `OhmioLibraries_36` 기준 명칭 `no_engine_state`를 주석으로 표기 |
| `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h` | version/hash는 현재 값 `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67` 유지. version/hash 관련 `OHMIO_INTEGRATION_CHECK` 주석 제거. `CAN_ID_FUSION_FLAGS` 관련 `OHMIO_INTEGRATION_CHECK` 주석을 `FusionFlagsMsg_t` 기준 확정 상태로 변경 또는 제거 |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_점검_필요사항.md` | 활성 점검 표에서 `FusionFlagsMsg_t` bit34, version/hash, `CAN_ID_FUSION_FLAGS` 항목 제거. 사용자 확인 완료 항목 표에 3개 항목 추가 |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_작업내용.md` | 남은 점검 항목 확정 반영 내용을 append |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_작업기록.md` | 이번 수정 작업 로그를 append |
| `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_오류사항.md` | 수정 중 오류가 있으면 append, 없으면 오류 없음 기록 append |

## 적용 기준

- `FusionFlagsMsg_t` bit34 필드명은 `w_no_engine_state`로 확정한다.
- `OhmioLibraries_36`의 `no_engine_state` 명칭은 참고 주석으로만 남긴다.
- `CAN_ID_FUSION_FLAGS` 설명은 현재 `FusionFlagsMsg_t` 구조 기준을 따른다.
- version/hash는 현재 통합본 값인 `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67`을 유지한다.
- 사용자 확인 완료 항목은 더 이상 점검 필요 항목으로 남기지 않는다.

## 검증 계획

사용자 동의 후 수정 적용 뒤 아래를 확인한다.

1. 통합 코드에서 남은 `OHMIO_INTEGRATION_CHECK`가 없는지 확인한다.
2. `FusionFlagsMsg_t` bit34가 `w_no_engine_state`로 유지되는지 확인한다.
3. `OhmioLibraries_36` 기준 명칭 `no_engine_state`가 확정 주석으로만 남는지 확인한다.
4. `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67`이 유지되는지 확인한다.
5. `dbc_CAN.h`, `dbc_MsgID_main.h` 문법 검사를 수행한다.
6. 점검 필요사항 문서에서 활성 점검 표가 비어 있거나 남은 항목 없음 상태인지 확인한다.

## 진행 조건

이 문서는 작업계획이다. 사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 수정 작업을 진행한다.


## 사용자 확인

`version/hash` 현재 상태에서 변경 사항없음.
    이유 : 
        1. OhmioLibraries 기준으로 적용 -> ok.
        2. OhmioLibraries_36 기준 표기 주석 -> ok.