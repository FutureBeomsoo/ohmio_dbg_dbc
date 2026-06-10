# CAN Header 통합 Codex 작업 인계

## 문서 목적

이 문서는 Git 명령 사용법을 설명하는 문서가 아니다.

사용자가 현재 프로젝트를 Git으로 다른 PC에 옮긴 뒤, 새 PC의 VSCode Codex가 현재 CAN header 통합 작업의 대화 맥락과 작업 상태를 이어받기 위한 인계 문서이다.

전제:

- 사용자가 현재 PC에서 필요한 변경사항을 commit/push 했다.
- 다른 PC에서 repository를 pull 했다.
- 다른 PC에서 `dev_header_merge` 브랜치로 이동했다.
- 그 다음 VSCode Codex에게 이 문서를 확인시켜 작업 상태를 복원한다.

## 새 PC의 Codex에게 줄 요청문

다른 PC에서 VSCode Codex에게 아래 내용을 그대로 요청한다.

```text
Codex/CAN_Header_통합_Codex_작업_인계.md 확인.

이 문서는 Git 명령 설명이 아니라 현재 CAN header 통합 작업을 이어받기 위한 인계 문서다.
이 문서 기준으로 현재 대화 맥락과 작업 상태를 복원해.

먼저 Codex/can_headerfile_commnad.txt를 확인해서 작업 규칙을 읽고,
그 다음 이 문서에 적힌 핵심 작업 문서를 순서대로 확인해.

새 작업이나 수정 작업은 즉시 진행하지 말고,
command 규칙대로 별도 작업 폴더와 <작업명>_예정_작업계획.md를 먼저 작성한 뒤
내 동의를 받고 진행해.
```

## Codex가 반드시 기억해야 할 사용자 요구

- 작업은 반드시 구분한다.
- 추가 작업과 세부 작업도 엄밀히 다른 작업으로 취급한다.
- 작업별로 별도 폴더를 만든다.
- 작업 시작 전 `<작업명>_예정_작업계획.md`를 작성한다.
- 사용자의 명시적 동의 전에는 실제 작업을 진행하지 않는다.
- 작업 내용은 `<작업명>_작업내용.md`에 정리한다.
- 오류 사항은 `<작업명>_오류사항.md`에 정리한다.
- 사용자 판단이 필요한 내용은 `<작업명>_점검_필요사항.md`에 정리한다.
- 모든 작업은 `<작업명>_작업기록.md`에 log로 남긴다.
- 기존 작업 기록을 덮어쓰지 않는다.
- 원본 폴더는 읽기 전용으로 취급하고, 산출물은 `Codex` 아래에 둔다.

## 현재 작업 상태

| 항목 | 상태 |
| --- | --- |
| 작업 브랜치 | `dev_header_merge` |
| 현재 통합본 이름 | `Origin_36_merge` |
| 현재 통합본 위치 | `Codex/파일_통합/2-1_Origin_36_병합/canbus` |
| 2-1 | `OhmioLibraries` + `OhmioLibraries_36` 병합 완료 |
| 2-1 수정 1 | `Obs_Keyframe_Saver` 확정 반영 완료 |
| 2-1 수정 2 | 잔여 점검 항목 확정 반영 완료 |
| 2-2 | `Origin_36_merge` 재비교 완료 |
| 2-3 | `Origin_36_merge` vs `OhmioLibraries_BK` 상호비교 완료 |
| 다음 핵심 상태 | BK 항목 통합/제외 판단 대기 |

## 이어받을 때 먼저 읽을 문서

Codex는 아래 순서로 파일을 확인한다.

| 순서 | 문서 | 목적 |
| --- | --- | --- |
| 1 | `Codex/can_headerfile_commnad.txt` | 전체 작업 규칙과 현재 작업 지시 확인 |
| 2 | `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_작업내용.md` | 현재 통합본 생성 기준 확인 |
| 3 | `Codex/파일_통합/2-1_Origin_36_병합/2-1_Origin_36_병합_점검_필요사항.md` | 2-1 사용자 확인 반영 상태 확인 |
| 4 | `Codex/파일_통합/2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영/2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영_작업내용.md` | `Obs_Keyframe_Saver` 확정 반영 내용 확인 |
| 5 | `Codex/파일_통합/2-1_Origin_36_병합_수정_잔여점검항목_확정반영/2-1_Origin_36_병합_수정_잔여점검항목_확정반영_작업내용.md` | 잔여 점검 항목 확정 반영 내용 확인 |
| 6 | `Codex/파일_통합/2-2_Origin_36_merge_재비교/2-2_Origin_36_merge_재비교_작업내용.md` | 2-2 재비교 결과 확인 |
| 7 | `Codex/파일_통합/2-2_Origin_36_merge_재비교/2-2_Origin_36_merge_재비교_점검_필요사항.md` | 2-2 이후 점검 항목 확인 |
| 8 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_작업내용.md` | BK 상호비교 결과 확인 |
| 9 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_점검_필요사항.md` | 다음 사용자 판단 필요사항 확인 |

## 현재 통합본의 주요 확정 사항

현재 통합본은 아래 경로의 header 파일 집합이다.

```text
Codex/파일_통합/2-1_Origin_36_병합/canbus
```

포함 header:

| 파일 |
| --- |
| `additionalDbcCan.h` |
| `ConversionHelper.h` |
| `dbc_CAN.h` |
| `dbc_CAN_peripheral.h` |
| `dbc_MsgID_main.h` |
| `dbc_MsgID_peripheral.h` |
| `dbc_MsgID_security.h` |
| `Security_CAN.h` |

확정 반영된 주요 판단:

| 항목 | 확정 내용 |
| --- | --- |
| `FusError` bit22 | `fus_conflicting_inputs` 반영 |
| `FusionFlagsMsg_t` bit22 | `conflicting_inputs` 반영 |
| `ObstaclePcWarningErrorCode` | `Obs_Keyframe_Saver` 확정, `Obs_Keyframe_Database` alias 제거 |
| `ObstaclePcWarning_t` bit14 | `ObsKeyframeSaverError` 확정 |
| `ObsKeyframeLoaderDatabaseError` | 제거 대상 아님, 유지 |
| `FusionFlagsMsg_t` bit34 | `w_no_engine_state` 확정, 36의 `no_engine_state`는 주석 참조 |
| `dbc_MsgID_main.h` version/hash | Origin 기준 `MAJOR 4`, `MINOR 15`, `BUILD 0xBEC99F67` 유지 |

## 현재 다음 단계

현재 바로 이어갈 내용은 `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_점검_필요사항.md`의 사용자 판단 항목이다.

Codex는 새 PC에서 상태 복원 후 바로 병합을 진행하면 안 된다. 먼저 사용자가 어떤 BK 항목을 통합할지, 제외할지 판단해야 한다.

주요 판단 대상:

| 구분 | 내용 |
| --- | --- |
| BK-only message/struct | BK에만 있는 message/struct를 `Origin_36_merge`에 통합할지 판단 |
| BK-only CAN ID | BK에만 있는 CAN ID를 통합할지 판단 |
| 공통 message layout 충돌 | 같은 message 이름에서 signal/bit layout이 다른 항목 판단 |
| enum entry 충돌 | 같은 enum 이름에서 entry/value가 다른 항목 판단 |
| version/hash 정책 | `Origin_36_merge` 값을 유지할지, BK 값을 반영할지 판단 |
| function 구현 정책 | prototype 중심 유지 또는 BK의 header 내부 `static` 구현 반영 여부 판단 |
| `ConversionHelper.h` 정책 | unsigned 변환에서 음수 입력 처리 방식을 판단 |

## 2-3 상호비교 결과 요약

| 파일 | 상태 |
| --- | --- |
| `Security_CAN.h` | 동일 |
| `dbc_MsgID_security.h` | 동일 |
| `additionalDbcCan.h` | 차이 있음 |
| `ConversionHelper.h` | 차이 있음 |
| `dbc_CAN.h` | 차이 있음 |
| `dbc_CAN_peripheral.h` | 차이 있음 |
| `dbc_MsgID_main.h` | 차이 있음 |
| `dbc_MsgID_peripheral.h` | 차이 있음 |

주요 차이:

| 항목 | 내용 |
| --- | --- |
| `dbc_CAN.h` | BK-only struct/message 다수, 공통 message layout 충돌 다수 |
| `dbc_MsgID_main.h` | BK-only CAN ID와 공통 CAN ID 설명/enum 충돌 |
| `dbc_CAN_peripheral.h` | peripheral message layout 차이 |
| `dbc_MsgID_peripheral.h` | peripheral version/hash 및 일부 CAN ID 차이 |
| `ConversionHelper.h` | unsigned 변환에서 음수 입력 처리 정책 차이 |
| `additionalDbcCan.h` | BK와 Origin_36_merge의 struct/function 구성 차이 |

## Codex가 이어받은 직후 해야 할 응답

새 PC의 Codex는 이 문서와 핵심 문서를 확인한 뒤, 사용자에게 아래처럼 짧게 보고한다.

```text
현재 상태를 복원했습니다.

Origin_36_merge 통합본은 2-1에서 생성되었고,
2-2 재비교와 2-3 BK 상호비교까지 완료된 상태입니다.

다음은 2-3 점검 필요사항 기준으로 BK-only 항목과 충돌 항목을 통합할지 제외할지 판단하는 단계입니다.
새 작업을 시작하려면 command 규칙에 따라 별도 작업 폴더와 예정 작업계획 문서를 먼저 작성하겠습니다.
```
