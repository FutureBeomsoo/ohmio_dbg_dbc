# 2-4_dbc_CAN_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/dbc_CAN.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/dbc_CAN_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_CAN.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| BK-only struct | 21개 |
| Origin-only struct | 15개 |
| 공통 struct layout/comment 차이 | 39개 |
| Origin-only function | 14개 |
| BK-only function | 30개 |
| 공통 function 차이 | 116개 |
| enum entry 차이 | 15개 |
| include 차이 | BK에 `"ConversionHelper.h"`, `<assert.h>`, `<math.h>` 있음 |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. Origin-only struct/function은 유지한다.
3. BK-only struct는 CAN ID, message name, cross-file 중복 여부를 확인한 뒤 충돌 없으면 추가한다.
4. `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg`처럼 Origin의 `additionalDbcCan.h`에 존재하고 BK의 `dbc_CAN.h`에 존재하는 항목은 사용자 의견에 따라 Origin의 `additionalDbcCan.h` 위치에 정의한다.
5. 공통 struct layout 충돌은 기본적으로 Origin 정의를 유지한다.
6. 같은 bit field에서 Origin이 reserved이고 BK가 named signal이면 BK named signal을 반영한다.
7. enum entry 충돌은 기본적으로 Origin entry/value를 유지하고 BK entry/value는 점검사항에 기록한다.
8. BK-only function은 대응 struct를 활성 추가한 경우에만 활성 반영한다.
9. 공통 function 중 struct/member 충돌이 없는 경우 BK 함수 정의 반영을 검토한다.
10. 공통 function 중 struct/member 충돌이 있는 경우에도 사용자 의견에 따라 BK 함수 정의를 활성 반영하되, 충돌 내용을 주석 표시하고 점검사항에 남긴다.
11. include는 활성 반영한 function이 필요로 하는 경우에만 추가한다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_dbc_CAN_병합_작업내용.md` | `dbc_CAN.h` 병합 작업 상세 |
| `2-4_dbc_CAN_병합_점검_필요사항.md` | BK-only struct, layout 충돌, enum 충돌, function 충돌 |
| `2-4_dbc_CAN_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_dbc_CAN_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.

## 사용자 의견

`DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg`처럼 Origin의 `additionalDbcCan.h`에 존재하고 BK의 `dbc_CAN.h`에 존재하는 항목은 Origin의 위치에 지시 규칙대로 정의.

위 사용자 의견은 병합 계획 4번에 반영 완료.
