# 2-4_dbc_MsgID_peripheral_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_peripheral.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/dbc_MsgID_peripheral.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/dbc_MsgID_peripheral_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_MsgID_peripheral.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| Origin-only CAN_ID | `CAN_ID_AIR_CON_JJ_K161STATUS`, `CAN_ID_AIR_CON_VERSION`, `CAN_ID_BMS_CHARGING_CURRENT`, `CAN_ID_BMS_CHARGING_CURRENT_REPLY`, `CAN_ID_RECOVERY` |
| BK-only CAN_ID | 없음 |
| CAN_ID 설명 변경 | `CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` |
| enum entry 차이 | `COMMON_CAN_P` |
| version/hash 차이 | `MAJOR 2/1`, `MINOR 3/12`, `BUILD 0xD1134632/0x0E350456` |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. version/hash는 Origin 값을 유지하고 BK 값은 점검사항에 기록한다.
3. Origin-only CAN_ID와 enum은 유지한다.
4. `CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` 설명 차이는 최종 `dbc_CAN_peripheral.h` struct 정의와 일치하도록 정리한다.
5. BK 설명이 최종 활성 struct와 맞지 않는 경우 점검사항에 기록한다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_dbc_MsgID_peripheral_병합_작업내용.md` | peripheral CAN ID 병합 상세 |
| `2-4_dbc_MsgID_peripheral_병합_점검_필요사항.md` | version/hash와 comment 충돌 |
| `2-4_dbc_MsgID_peripheral_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_dbc_MsgID_peripheral_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.
