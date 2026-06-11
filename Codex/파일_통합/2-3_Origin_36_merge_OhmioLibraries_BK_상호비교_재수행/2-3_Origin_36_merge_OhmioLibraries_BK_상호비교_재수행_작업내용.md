# 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행 작업내용

## 작업 범위

- `Codex/can_headerfile_commnad.txt`를 다시 확인한 기준으로 2-3 상호 비교를 재수행했다.
- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus`
- 기존 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교/` 산출물은 수정하지 않았다.
- `Origin_36_merge` header와 `OhmioLibraries_BK` 원본 header는 수정하지 않았다.
- 이번 작업은 비교 분석 재수행이며 통합 적용은 수행하지 않았다.

## 생성 산출물

| 산출물 | 상태 | 내용 |
| --- | --- | --- |
| `Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/` | 생성 | header별 8개 분석 문서 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_작업내용.md` | 생성 | 재수행 내용 요약 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_점검_필요사항.md` | 생성 | 사용자 판단 필요사항 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_오류사항.md` | 생성 | 오류 및 제한 사항 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_작업기록.md` | 생성 | 작업 로그 |

## 파일별 결과 요약

| 파일 | 상태 | 주요 차이 |
| --- | --- | --- |
| `additionalDbcCan.h` | 차이 있음 | Origin-only struct 4; Origin-only function 11; function 차이 4; preprocessor/define 차이 |
| `dbc_CAN_peripheral.h` | 차이 있음 | Origin-only struct 5; struct layout/comment 차이 2; Origin-only function 2; function 차이 58; preprocessor/define 차이 |
| `dbc_CAN.h` | 차이 있음 | BK-only struct 21; Origin-only struct 15; struct layout/comment 차이 39; Origin-only function 14; BK-only function 30; enum entry 차이 15; function 차이 116; preprocessor/define 차이 |
| `Security_CAN.h` | 동일 | 차이 없음 |
| `dbc_MsgID_main.h` | 차이 있음 | BK-only CAN_ID 8; Origin-only CAN_ID 23; CAN_ID 값 변경 3; CAN_ID 설명 변경 26; enum entry 차이 5; preprocessor/define 차이 |
| `dbc_MsgID_peripheral.h` | 차이 있음 | Origin-only CAN_ID 5; CAN_ID 설명 변경 2; enum entry 차이 1; preprocessor/define 차이 |
| `dbc_MsgID_security.h` | 동일 | 차이 없음 |
| `ConversionHelper.h` | 차이 있음 | function 차이 2; preprocessor/define 차이 |

## 핵심 판단

- `Security_CAN.h`, `dbc_MsgID_security.h`는 현재 파일 기준 동일하다.
- `dbc_CAN.h`, `dbc_MsgID_main.h`, `dbc_CAN_peripheral.h`, `dbc_MsgID_peripheral.h`, `additionalDbcCan.h`, `ConversionHelper.h`는 차이가 있다.
- BK-only message/struct와 CAN_ID가 존재하며, 자동 통합 대상인지 사용자 판단이 필요하다.
- 공통 message 이름에서도 bit field, decoded field, comment/ID 설명 차이가 있어 충돌로 분류했다.
- BK의 header 내부 `static` 함수 구현과 Origin_36_merge의 prototype 중심 구조 차이는 별도 구현 정책 판단 대상으로 분리했다.
