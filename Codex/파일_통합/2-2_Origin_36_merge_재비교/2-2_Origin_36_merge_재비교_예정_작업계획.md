# 2-2_Origin_36_merge_재비교 예정 작업계획

## 작업 목적

`2-1. OhmioLibraries와 OhmioLibraries_36 병합` 결과물인 `Origin_36_merge`에 대해 `1. file 비교 분석`을 재수행한다.

재비교 목적은 아래와 같다.

- `Origin_36_merge`가 `OhmioLibraries`, `OhmioLibraries_36`, `OhmioLibraries_BK`의 통합 결과를 의도대로 포함하는지 확인한다.
- 병합 과정에서 누락된 entry, signal, enum, message ID 설명이 있는지 확인한다.
- 사용자 확인을 통해 확정 반영된 항목이 더 이상 충돌/점검 필요 항목으로 남아 있지 않은지 확인한다.

## 작업 구분

이 작업은 `2. 파일 통합`의 세부 작업 `2-2`이다.

- 작업 폴더: `Codex/파일_통합/2-2_Origin_36_merge_재비교/`
- 비교 기준 통합본: `Codex/파일_통합/2-1_Origin_36_병합/canbus/`
- 통합본 정의명: `Origin_36_merge`
- 원본 폴더 `OhmioLibraries`, `OhmioLibraries_36`, `OhmioLibraries_BK`는 읽기 전용으로만 사용한다.
- `OhmioLibraries_36/Ohmio_lib_include`는 `OhmioLibraries_36`과 동일한 중복본으로 보고 이번 비교에서 제외한다.

## 비교 대상

| 비교명 | 좌측 | 우측 | 목적 |
| --- | --- | --- | --- |
| `Origin_36_merge_OhmioLibraries_재비교` | `Codex/파일_통합/2-1_Origin_36_병합/canbus` | `OhmioLibraries/include/canbus` | Origin 대비 통합본의 변경/추가 반영 확인 |
| `Origin_36_merge_OhmioLibraries_36_재비교` | `Codex/파일_통합/2-1_Origin_36_병합/canbus` | `OhmioLibraries_36/include/canbus` | 36 대비 통합본의 반영/유지/제외 항목 확인 |
| `Origin_36_merge_OhmioLibraries_BK_재비교` | `Codex/파일_통합/2-1_Origin_36_병합/canbus` | `OhmioLibraries_BK/include/canbus` | BK 대비 통합본의 반영/유지/제외 항목 확인 |

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
| `Origin_36_merge_OhmioLibraries_재비교/` | 통합본과 Origin 비교 분석 결과 |
| `Origin_36_merge_OhmioLibraries_36_재비교/` | 통합본과 36 비교 분석 결과 |
| `Origin_36_merge_OhmioLibraries_BK_재비교/` | 통합본과 BK 비교 분석 결과 |
| 각 비교 폴더의 `<Header file>_분석내용.md` | 파일별 비교 분석 내용 |
| `2-2_Origin_36_merge_재비교_작업내용.md` | 수행 내용 요약 |
| `2-2_Origin_36_merge_재비교_점검_필요사항.md` | 재비교 후 사용자 확인이 필요한 항목 |
| `2-2_Origin_36_merge_재비교_오류사항.md` | 오류 및 제한 사항 |
| `2-2_Origin_36_merge_재비교_작업기록.md` | 작업 로그 |

## 분석 기준

- 단순 텍스트 diff만 기록하지 않고, header 의미 단위로 확인한다.
- enum entry, struct bitfield, message ID 설명, version/hash, 변환 helper 차이를 구분한다.
- `Reserved` bit는 dummy field로 보고, 같은 위치에 실제 signal이 있으면 실제 signal 반영 여부를 확인한다.
- `2-1` 이후 사용자 확인 완료 항목은 충돌이 아니라 확정 반영 항목으로 분류한다.
- 통합본에만 있는 항목은 병합 반영 결과인지 확인한다.
- 원본에만 남아 있는 항목은 통합 누락인지, 사용자 확인에 따른 제외인지 구분한다.

## 사용자 확인 완료로 취급할 항목

아래 항목은 기존 `2-1` 및 수정 작업에서 사용자 확인이 완료된 것으로 보고, `2-2` 재비교에서는 점검 필요가 아니라 확정 반영 항목으로 기록한다.

| 대상 | 확정 내용 |
| --- | --- |
| `ObstaclePcWarningErrorCode` | `Obs_Keyframe_Saver` 유지, `Obs_Keyframe_Database` 제외 |
| `ObstaclePcWarning_t` bit14 | `ObsKeyframeSaverError` 유지, `ObsKeyframeDatabaseError` 제외 |
| `CAN_ID_OBSTACLE_PC_WARNING` | Origin 기준 설명 유지 |
| `FusionFlagsMsg_t` bit34 | `w_no_engine_state` 유지, 36 기준 `no_engine_state`는 주석 표기 |
| `dbc_MsgID_main.h` version/hash | 현재 통합본 값 유지 |
| `CAN_ID_FUSION_FLAGS` | `FusionFlagsMsg_t` 기준 설명 유지 |

## 검증 계획

사용자 동의 후 재비교 수행 뒤 아래를 확인한다.

1. 대상 header 8개에 대한 비교 분석 문서가 세 비교 폴더에 모두 생성되었는지 확인한다.
2. `2-1` 사용자 확인 완료 항목이 점검 필요 항목으로 다시 분류되지 않았는지 확인한다.
3. 통합본 `canbus` 코드에 `OHMIO_INTEGRATION_CHECK`가 남아 있지 않은지 확인한다.
4. 재비교 결과에서 새 사용자 점검 필요 항목이 있으면 `2-2_Origin_36_merge_재비교_점검_필요사항.md`에 별도 기록한다.
5. 작업 로그와 오류사항 문서를 append/생성한다.

## 진행 조건

이 문서는 작업계획이다. 사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 `2-2` 재비교 작업을 진행한다.

## 사용자 의견 반영

- `OhmioLibraries_BK`까지 통합 대상이므로 비교 대상에 추가했다.