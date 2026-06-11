# 2-4_Origin_36_merge_OhmioLibraries_BK_병합 예정 작업계획

## 작업 목적

`Origin_36_merge`와 `OhmioLibraries_BK`를 병합하여 다음 단계 통합본을 작성한다.

이번 작업은 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행` 결과물을 근거로 수행한다.

## 작업 구분

| 항목 | 내용 |
| --- | --- |
| 작업 분류 | `2. 파일 통합`의 세부 작업 `2-4` |
| 작업명 | `2-4_Origin_36_merge_OhmioLibraries_BK_병합` |
| 작업 폴더 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/` |
| 기준 A | `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/` |
| 기준 B | `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/` |
| 참고 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/` |
| 결과물 예정 위치 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/` |

## 적용 규칙

`Codex/can_headerfile_commnad.txt`의 2-4 지시를 적용한다.

| 규칙 | 적용 방식 |
| --- | --- |
| header file별 계획 | 8개 header별 하위 폴더와 `*_예정_작업계획.md`를 작성한다. |
| header file별 점검 | 실제 병합 후 각 header별 `*_점검_필요사항.md`를 작성한다. |
| header file별 작업내용 | 실제 병합 후 각 header별 `*_작업내용.md`를 작성한다. |
| 결과 위치 | 원본은 수정하지 않고 `Codex/파일_통합/2-4.../canbus/`에 결과를 작성한다. |
| 기본 병합 기준 | `Origin_36_merge`를 base로 사용한다. |
| 한쪽에만 있는 정의 | 충돌이 없으면 그대로 추가한다. |
| 일반 정의 충돌 | 기본적으로 `Origin_36_merge`를 우성, `OhmioLibraries_BK`를 열성으로 판단한다. |
| Reserved vs named | 같은 bit field에서 `Reserved`와 named signal이 충돌하면 named signal을 우성으로 판단한다. |
| function 정의 | `ToCAN`/`FromCAN`은 확인 가능한 정의 내용을 따른다. |
| signal 충돌 function | BK 함수 정의를 활성 반영하되, 충돌 내용을 주석으로 표시하고 사용자 점검 필요사항에 남긴다. |

## 함수 반영 해석 기준

2-4 지시에는 struct/signal 정의 우선순위와 function 구현 반영 방식이 함께 있다. 실제 병합에서는 아래처럼 분리 적용한다.

| 대상 | 처리 |
| --- | --- |
| struct/member 정의 | `Origin_36_merge` 우성, 단 `Reserved` vs named이면 named 우성 |
| 충돌 없는 BK-only struct/member | 활성 정의로 추가 |
| 충돌 있는 BK struct/member | 활성 정의는 우성 규칙 적용, BK 정의는 주석/점검으로 기록 |
| struct/member와 일치하는 BK `ToCAN`/`FromCAN` 정의 | 활성 함수 정의로 반영 |
| struct/member와 충돌하는 BK `ToCAN`/`FromCAN` 정의 | 사용자 의견에 따라 활성 반영하되, 충돌 내용을 주석으로 표시하고 점검사항에 기록 |
| 일반 helper function 충돌 | 2-4 규칙에 명확하지 않은 경우 `Origin_36_merge` 우성으로 두고 점검사항에 기록 |

## 대상 header별 세부 계획 문서

| Header | 계획 문서 |
| --- | --- |
| `additionalDbcCan.h` | `additionalDbcCan/2-4_additionalDbcCan_병합_예정_작업계획.md` |
| `ConversionHelper.h` | `ConversionHelper/2-4_ConversionHelper_병합_예정_작업계획.md` |
| `dbc_CAN.h` | `dbc_CAN/2-4_dbc_CAN_병합_예정_작업계획.md` |
| `dbc_CAN_peripheral.h` | `dbc_CAN_peripheral/2-4_dbc_CAN_peripheral_병합_예정_작업계획.md` |
| `dbc_MsgID_main.h` | `dbc_MsgID_main/2-4_dbc_MsgID_main_병합_예정_작업계획.md` |
| `dbc_MsgID_peripheral.h` | `dbc_MsgID_peripheral/2-4_dbc_MsgID_peripheral_병합_예정_작업계획.md` |
| `dbc_MsgID_security.h` | `dbc_MsgID_security/2-4_dbc_MsgID_security_병합_예정_작업계획.md` |
| `Security_CAN.h` | `Security_CAN/2-4_Security_CAN_병합_예정_작업계획.md` |

## 생성 예정 산출물

사용자 동의 후 아래 산출물을 생성한다.

| 산출물 | 내용 |
| --- | --- |
| `canbus/` | 2-4 병합 header 결과물 8개 |
| `*/<header>_작업내용.md` | header별 병합 작업 내용 |
| `*/<header>_점검_필요사항.md` | header별 사용자 판단 필요사항 |
| `*/<header>_오류사항.md` | header별 오류 및 제한 사항 |
| `*/<header>_작업기록.md` | header별 작업 log |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_작업내용.md` | 전체 병합 요약 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_점검_필요사항.md` | 전체 점검 필요사항 요약 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_오류사항.md` | 전체 오류사항 요약 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_작업기록.md` | 전체 작업 log |

## 검증 계획

1. 결과 `canbus/`에 대상 header 8개가 생성되었는지 확인한다.
2. 원본 `Origin_36_merge`와 `OhmioLibraries_BK`가 수정되지 않았는지 확인한다.
3. header별 작업내용, 점검 필요사항, 오류사항, 작업기록이 생성되었는지 확인한다.
4. 2-3 재수행 결과 대비 병합 반영/제외/주석 처리 항목이 누락되지 않았는지 확인한다.
5. compile/build 검증은 별도 요청이 없으면 수행하지 않고, 이번 작업에서는 문법 위험 항목을 점검사항에 기록한다.

## 진행 조건

이 문서는 예정 작업계획이다.

사용자가 이 계획과 header별 계획을 확인하고 명시적으로 동의한 뒤에만 실제 2-4 병합을 진행한다.

## 사용자 의견

signal 충돌 function : 활성으로 반영 하되, 충돌 내용 주석 표시 및 사용자 점검 필요사항 기록.

위 사용자 의견은 본문 `signal 충돌 function` 및 `struct/member와 충돌하는 BK ToCAN/FromCAN 정의` 처리 기준에 반영 완료.
