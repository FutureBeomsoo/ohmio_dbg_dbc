# 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교 예정 작업계획

## 작업 목적

`Origin_36_merge`와 `OhmioLibraries_BK`를 상호 비교한다.

`Origin_36_merge`는 `2-1_Origin_36_병합` 결과물이며, 이번 작업에서는 command 파일 지시에 따라 원본 폴더처럼 읽기 전용 기준으로 취급한다.

## 작업 구분

이 작업은 `2. 파일 통합`의 세부 작업 `2-3`이다.

- 작업 폴더: `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교/`
- 좌측 비교 기준: `Codex/파일_통합/2-1_Origin_36_병합/canbus/`
- 좌측 정의명: `Origin_36_merge`
- 우측 비교 기준: `OhmioLibraries_BK/include/canbus/`
- `Origin_36_merge` 결과물과 `OhmioLibraries_BK` 원본은 모두 수정하지 않는다.
- 이번 작업은 상호 비교 분석만 수행하며, 통합본 수정은 포함하지 않는다.

## 분석 파일 목록

아래 8개 header를 비교한다.

| 분류 | 파일 |
| --- | --- |
| CAN Message & Signal 정의 | `additionalDbcCan.h` |
| CAN Message & Signal 정의 | `dbc_CAN_peripheral.h` |
| CAN Message & Signal 정의 | `dbc_CAN.h` |
| CAN Message & Signal 정의 | `Security_CAN.h` |
| Signal Enum 정의 | `dbc_MsgID_main.h` |
| Signal Enum 정의 | `dbc_MsgID_peripheral.h` |
| Signal Enum 정의 | `dbc_MsgID_security.h` |
| 값 범위 계산 | `ConversionHelper.h` |

## 생성 예정 산출물

사용자 동의 후 아래 파일을 생성한다.

| 파일/폴더 | 내용 |
| --- | --- |
| `Origin_36_merge_OhmioLibraries_BK_상호비교_분석/` | header별 상호 비교 분석 결과 |
| `Origin_36_merge_OhmioLibraries_BK_상호비교_분석/<Header file>_분석내용.md` | 파일별 상세 비교 분석 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_작업내용.md` | 수행 내용 요약 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_점검_필요사항.md` | 사용자 판단이 필요한 충돌/누락/정책 사항 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_오류사항.md` | 오류 및 제한 사항 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_작업기록.md` | 작업 로그 |

## 분석 기준

`1. file 비교 분석` 지시내용을 포함 적용한다.

- 단순 텍스트 diff만 기록하지 않고, header 의미 단위로 분석한다.
- 한쪽 파일에만 있는 message, signal, enum, helper 함수, define을 구분한다.
- 같은 message 또는 enum 이름이 있으나 bit 범위, entry 값, 설명, 구조가 다른 경우 충돌로 기록한다.
- `Reserved` signal은 dummy field로 보되, 같은 bit 위치에 실제 signal이 있으면 실제 signal 반영 여부와 충돌 여부를 기록한다.
- 함수 선언/정의 차이는 구현 위치 정책 확인 대상으로 분리한다.
- version/hash 차이는 별도 항목으로 기록한다.
- `2-2`에서 작성한 BK 재비교 결과는 참고할 수 있으나, `2-3` 산출물은 별도 작업 결과로 독립 작성한다.

## 비교 관점

| 관점 | 기록 내용 |
| --- | --- |
| `Origin_36_merge`에만 있음 | Origin+36 병합 결과에는 있으나 BK에는 없는 항목 |
| `OhmioLibraries_BK`에만 있음 | BK에는 있으나 `Origin_36_merge`에는 없는 항목 |
| 동일 이름/ID의 값 변경 | 같은 entry/message 이름의 값 또는 ID 차이 |
| 동일 message의 bit 구조 변경 | bit field 범위, reserved 위치, signal 이름 차이 |
| 함수 구현 방식 차이 | header 내부 `static` 구현 vs 함수 선언만 존재하는 차이 |
| 사용자 판단 필요 | 통합/제외/대체 기준이 필요한 항목 |

## 점검 필요사항 작성 기준

아래 항목은 `점검_필요사항.md`에 기록한다.

- BK에만 있고 통합 여부가 불명확한 message, signal, enum
- 동일 message ID 또는 enum entry 이름의 의미/값/bit 구조 충돌
- version/hash 정책 판단이 필요한 항목
- 변환 함수 구현 위치 또는 동작 정책이 다른 항목
- `Reserved` 위치에 실제 signal이 존재하지만 자동 대체 여부가 불명확한 항목

## 검증 계획

사용자 동의 후 상호 비교 수행 뒤 아래를 확인한다.

1. 대상 header 8개에 대한 `*_분석내용.md` 문서가 생성되었는지 확인한다.
2. `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_작업내용.md`가 생성되었는지 확인한다.
3. 신규 사용자 점검 필요사항이 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_점검_필요사항.md`에 정리되었는지 확인한다.
4. 오류 및 제한 사항을 `오류사항.md`에 기록한다.
5. 작업 로그를 `작업기록.md`에 기록한다.
6. 원본 폴더와 `Origin_36_merge` header 코드가 수정되지 않았는지 확인한다.

## 진행 조건

이 문서는 작업계획이다. 사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 `2-3` 상호 비교 작업을 진행한다.
