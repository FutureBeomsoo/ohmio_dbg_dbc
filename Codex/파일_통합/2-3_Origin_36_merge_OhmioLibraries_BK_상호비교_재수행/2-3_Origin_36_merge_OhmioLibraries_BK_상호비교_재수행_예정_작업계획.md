# 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행 예정 작업계획

## 작업 목적

`Codex/can_headerfile_commnad.txt`를 다시 확인한 기준으로 `2-3. Origin_36_merge 와 OhmioLibraries_BK 상호 비교`를 재수행한다.

이번 작업은 기존 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교` 결과를 덮어쓰지 않고, 별도 재수행 작업으로 구분한다.

## 작업 구분

| 항목 | 내용 |
| --- | --- |
| 작업 분류 | `2. 파일 통합`의 세부 작업 `2-3` 재수행 |
| 작업명 | `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행` |
| 작업 폴더 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/` |
| 좌측 비교 기준 | `Codex/파일_통합/2-1_Origin_36_병합/canbus/` |
| 좌측 정의명 | `Origin_36_merge` |
| 우측 비교 기준 | `OhmioLibraries_BK/include/canbus/` |
| 우측 정의명 | `OhmioLibraries_BK` |
| 기존 2-3 결과 | 참고 가능하나 수정/덮어쓰기 금지 |

## command 파일 재확인 결과

이번 재수행에 적용할 핵심 규칙은 아래와 같다.

| 규칙 | 적용 방식 |
| --- | --- |
| 작업 시작 전 계획 문서 작성 후 동의 필요 | 이 문서를 작성한 뒤 실제 작업은 중단한다. |
| 세부 작업마다 별도 폴더 생성 | 기존 2-3과 분리하여 `..._재수행` 폴더를 사용한다. |
| 모든 결과물은 `Codex` 폴더 내 생성 | 재수행 산출물은 모두 이번 작업 폴더 아래에 둔다. |
| 원본 폴더 및 파일 수정 금지 | `Origin_36_merge`, `OhmioLibraries_BK` 모두 읽기 전용으로 취급한다. |
| 기존 작업 기록 덮어쓰기 금지 | 기존 2-3 산출물을 수정하지 않는다. |
| 충돌/판단 필요사항 기록 | 사용자 확인 필요 내용은 별도 `점검_필요사항.md`에 기록한다. |

## 비교 대상 파일

아래 8개 header를 현재 파일 기준으로 다시 비교한다.

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

## 재수행 분석 기준

단순 텍스트 diff가 아니라 header 의미 단위로 분석한다.

| 관점 | 기록 내용 |
| --- | --- |
| 한쪽에만 있는 항목 | `Message(Struct)`, `Signal(Member)`, `Enum`, `function`, `macro`, `preprocessor` 등 |
| 같은 CAN ID의 정의 충돌 | 같은 CAN ID에 서로 다른 message 정의가 있는 경우 |
| 같은 message의 ID 충돌 | 같은 CAN message가 서로 다른 CAN ID로 정의된 경우 |
| 같은 message의 bit 충돌 | 같은 struct에서 같은 bit field에 다른 signal/member가 정의된 경우 |
| enum entry 충돌 | 같은 enum 이름 내부의 entry 존재 여부 또는 value 차이 |
| function 차이 | 선언/정의 존재 여부, header 내부 `static` 구현 여부, parameter 차이 |
| macro/preprocessor 차이 | version/hash, include, define 차이 |
| Reserved 처리 | `Reserved`는 dummy field로 보고, 같은 위치에 실제 signal이 있으면 충돌/대체 후보로 기록 |

## 생성 예정 산출물

사용자 동의 후 아래 산출물을 생성한다.

| 산출물 | 내용 |
| --- | --- |
| `Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/` | header별 재비교 분석 결과 폴더 |
| `Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/<Header file>_분석내용.md` | 파일별 상세 비교 분석 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_작업내용.md` | 재수행 내용 요약 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_점검_필요사항.md` | 사용자 판단 필요사항 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_오류사항.md` | 오류, 제한 사항, 재수행 중 확인된 문제 |
| `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_작업기록.md` | 작업 log |

## 검증 계획

재수행 완료 후 아래를 확인한다.

1. 분석 대상 header 8개에 대해 `*_분석내용.md`가 생성되었는지 확인한다.
2. 기존 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교/` 산출물이 수정되지 않았는지 확인한다.
3. `Origin_36_merge` 통합본 header가 수정되지 않았는지 확인한다.
4. `OhmioLibraries_BK` 원본 header가 수정되지 않았는지 확인한다.
5. 사용자 판단이 필요한 항목을 `점검_필요사항.md`에 분리했는지 확인한다.
6. 오류 및 제한 사항을 `오류사항.md`에 기록한다.
7. 작업 로그를 `작업기록.md`에 기록한다.

## 진행 조건

이 문서는 예정 작업계획이다.

command 파일의 절대 규칙에 따라, 사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 `2-3` 상호 비교 재수행을 진행한다.
