# 2-4_dbc_MsgID_main_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/dbc_MsgID_main_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_MsgID_main.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| BK-only CAN_ID | 8개 |
| Origin-only CAN_ID | 23개 |
| CAN_ID 값 변경 | `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` |
| CAN_ID 설명 변경 | 26개 |
| 같은 numeric ID 이름 차이 | `0x26`, `0x2D` |
| version/hash 차이 | `MAJOR 4/2`, `MINOR 15/110`, `BUILD 0xBEC99F67/0x47AB1E0D` |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. version/hash는 기본 정의 충돌이므로 Origin 값을 유지하고 BK 값은 점검사항에 기록한다.
3. Origin-only CAN_ID는 유지한다.
4. BK-only CAN_ID 중 numeric ID 충돌이 없는 항목은 추가 후보로 반영한다.
5. `CAN_ID_ERROR_TRANS`/`CAN_ID_TRANS1_ERROR`의 `0x26`, `CAN_ID_ERROR_MOTOR_ADAPTOR`/`CAN_ID_ERROR_NETWORK`의 `0x2D`는 Origin 우성으로 유지하고 BK 항목은 점검사항에 기록한다.
6. `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` 값 변경은 Origin 값을 유지한다.
7. CAN_ID 설명/comment는 최종 활성 struct 정의와 일치하도록 정리하되, 충돌이 있는 BK 설명은 점검사항에 남긴다.
8. enum entry 충돌은 Origin entry/value를 우선 유지하고 BK-only entry는 numeric 충돌 여부를 확인해 반영 후보로 분류한다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_dbc_MsgID_main_병합_작업내용.md` | main CAN ID 병합 상세 |
| `2-4_dbc_MsgID_main_병합_점검_필요사항.md` | CAN_ID 충돌, version/hash, enum 충돌 |
| `2-4_dbc_MsgID_main_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_dbc_MsgID_main_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.
