# 2-2_Origin_36_merge_재비교 작업내용

## 작업 범위

- `Origin_36_merge` 결과에 대해 `1. file 비교 분석`을 재수행했다.
- 비교 기준 통합본: `Codex/파일_통합/2-1_Origin_36_병합/canbus`
- 비교 대상: `OhmioLibraries`, `OhmioLibraries_36`, `OhmioLibraries_BK`
- `OhmioLibraries_36/Ohmio_lib_include`는 중복본으로 제외했다.
- 원본 폴더와 통합본 header 코드는 수정하지 않았다.

## 생성 위치

- 작업 폴더: `Codex/파일_통합/2-2_Origin_36_merge_재비교`

## 생성 파일

| 파일/폴더 | 상태 | 내용 |
| --- | --- | --- |
| Origin_36_merge_OhmioLibraries_재비교/ | 생성 | 통합본과 Origin 비교 분석 8개 파일 |
| Origin_36_merge_OhmioLibraries_36_재비교/ | 생성 | 통합본과 36 비교 분석 8개 파일 |
| Origin_36_merge_OhmioLibraries_BK_재비교/ | 생성 | 통합본과 BK 비교 분석 8개 파일 |
| 2-2_Origin_36_merge_재비교_점검_필요사항.md | 생성 | 재비교 후 사용자 확인 필요사항 |
| 2-2_Origin_36_merge_재비교_오류사항.md | 생성 | 오류 및 제한 사항 |
| 2-2_Origin_36_merge_재비교_작업기록.md | 생성 | 작업 로그 |

## 비교 결과 요약

| 비교 | 결과 | 설명 |
| --- | --- | --- |
| Origin_36_merge vs OhmioLibraries | 2개 파일 차이 | `dbc_CAN.h`, `dbc_MsgID_main.h`만 다르며, 차이는 36 반영 또는 사용자 확인 완료 항목이다. |
| Origin_36_merge vs OhmioLibraries_36 | 2개 파일 차이 | `dbc_CAN.h`, `dbc_MsgID_main.h`만 다르며, 차이는 Origin 유지 또는 사용자 확인 완료 항목이다. |
| Origin_36_merge vs OhmioLibraries_BK | 6개 파일 차이 | `additionalDbcCan.h`, `dbc_CAN_peripheral.h`, `dbc_CAN.h`, `dbc_MsgID_main.h`, `dbc_MsgID_peripheral.h`, `ConversionHelper.h`에서 대규모 차이가 있다. |
| 공통 동일 파일 | 확인 | `Security_CAN.h`, `dbc_MsgID_security.h`는 세 비교 대상 모두와 동일하다. |

## 사용자 확인 완료 항목 처리

- `ObstaclePcWarningErrorCode`, `ObstaclePcWarning_t` bit14, `CAN_ID_OBSTACLE_PC_WARNING`은 확정 반영 항목으로 처리했다.
- `FusionFlagsMsg_t` bit34, version/hash, `CAN_ID_FUSION_FLAGS`는 확정 반영 항목으로 처리했다.
- 위 항목들은 `2-2` 재비교에서 점검 필요사항으로 재분류하지 않았다.