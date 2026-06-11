# 2-4_dbc_CAN_peripheral_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN_peripheral.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/dbc_CAN_peripheral_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_CAN_peripheral.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| Origin-only struct | 5개 |
| 공통 struct layout/comment 차이 | `AirConReqMsg`, `BMSStatusMsg8` |
| Origin-only function | `AirConJJK161StatusMsg_FromCan`, `AirConJJK161StatusMsg_ToCan` |
| 공통 function 차이 | 58개 |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. Origin-only struct/function은 유지한다.
3. `AirConReqMsg`, `BMSStatusMsg8` layout 충돌은 기본적으로 Origin 정의를 유지한다.
4. Reserved vs named signal이 확인되는 경우 named signal을 반영한다.
5. 공통 function 중 layout 충돌이 없는 message는 BK 함수 정의 반영을 검토한다.
6. `AirConReqMsg`, `BMSStatusMsg8`처럼 layout 충돌이 있는 message의 BK function도 활성 반영하되, 충돌 내용을 주석 표시하고 점검사항에 남긴다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_dbc_CAN_peripheral_병합_작업내용.md` | peripheral message 병합 상세 |
| `2-4_dbc_CAN_peripheral_병합_점검_필요사항.md` | layout 충돌과 function 정책 |
| `2-4_dbc_CAN_peripheral_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_dbc_CAN_peripheral_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.
