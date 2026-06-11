# 2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영 예정 작업계획

## 작업 목적

`Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합`의 병합 점검 필요사항 내용을 적용하여 2-4 병합 결과를 재생성한다.

이번 작업은 기존 2-4 결과를 덮어쓰지 않고, 별도 재진행 결과 폴더에 작성한다.

## 작업 구분

| 항목 | 내용 |
| --- | --- |
| 작업 분류 | `2. 파일 통합`의 세부 작업 `2-4` 재진행 |
| 작업명 | `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영` |
| 작업 폴더 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영/` |
| 결과 예정 위치 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영/canbus/` |

## 입력 기준

| 구분 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/` |
| 기존 2-4 결과 참고 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/` |
| 병합 점검 필요사항 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/*/*_병합_점검_필요사항.md` |
| 전체 점검 요약 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/2-4_Origin_36_merge_OhmioLibraries_BK_병합_점검_필요사항.md` |

## 병합 점검 필요사항 적용 기준

| Header | 적용 기준 |
| --- | --- |
| `additionalDbcCan.h` | 현재 상태 확인 확정. 기존 2-4의 `static` BK 함수 활성 반영 상태를 유지한다. |
| `ConversionHelper.h` | Origin `value <= 0` clamp 정책 유지. `<stdint.h>`를 추가한다. |
| `dbc_CAN.h` | 아래 `dbc_CAN.h` 세부 적용 기준에 따라 재병합한다. |
| `dbc_CAN_peripheral.h` | layout 충돌 function 활성 반영 상태를 유지한다. 주석 포함 기존 2-4 상태를 유지한다. |
| `dbc_MsgID_main.h` | `CAN_ID_ERROR_TRANS`, `CAN_ID_ERROR_MOTOR_ADAPTOR` 제외 확정. Origin version/hash 유지. `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT`는 Origin 값 유지. |
| `dbc_MsgID_peripheral.h` | Origin peripheral version/hash 유지. `CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` 설명은 Origin 구조 기준 유지. |
| `dbc_MsgID_security.h` | 점검 필요사항 없음. 기존 동일 결과 유지. |
| `Security_CAN.h` | 점검 필요사항 없음. 기존 동일 결과 유지. |

## `dbc_CAN.h` 세부 적용 기준

| 항목 | 적용 |
| --- | --- |
| `ErrorMotorAdaptor` | 활성 추가 제외. Origin `CAN_ID_ERROR_NETWORK` 정의 유지. |
| `ErrorTrans` | 활성 추가 제외. `CAN_ID_TRANS1_ERROR`와 사실상 같은 message로 판단하고 Origin 정의 유지. |
| `TransErrorCode` | 활성 추가 제외. |
| `PrintASCIIMsg` | 활성 추가 제외. Origin 정의 유지. |
| `IMUMag_ToCan()` `status` assert | 활성 추가 제외. Origin 우성 규칙에 따라 struct 내 `status` 제외. |
| `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` | `additionalDbcCan.h`에 정의된 상태를 유지하고 `dbc_CAN.h`에는 중복 추가하지 않는다. |
| `FusionLatitudeMsg` | 활성 추가 제외. `LatitudeMsg_t` 및 `LatitudeMsg_ToCan/FromCan` 대응으로 유지한다. |
| `SystemReqMsg` | bits0-7 `mode`, bits32-39 `brakePressure`, bits40-59 `reserved`, bits60-61 `driveDisalowed`로 반영한다. |
| Obsolete 계열 BK 정의 반영 | 사용자 의견에 명시된 BK message 정의를 반영하고, Origin `ObsoleteMsg` 기준 정의는 주석 표기한다. 대상: 0x120, 0x121, 0x160, 0x220, 0x221, 0x222, 0x223, 0x230, 0x231, 0x232, 0x233, 0x234, 0x250, 0x251, 0x252, 0x260, 0x321, 0x710 |
| `0x221`, `0x231` | BK의 `LongitudeMsg_t` mapping에 포함되도록 정리한다. 누락 사유는 작업내용에 기록한다. |
| `0x183`, `0x187`, `0x188` | BK mapping에 맞춰 `ManualDriveMsg_t`/`JoystickMsg_t` message ID comment/alias를 정리한다. |
| `0x670`, `0x671`, `0x672` | BK mapping에 맞춰 `TrackCtrlMsg_t`/`TrackAckMsg_t`/`TrackDataMsg_t` message ID comment/alias를 정리한다. |
| 공통 function 활성 반영 | 기존 2-4와 같이 BK function 활성 반영 상태를 유지한다. 필요한 경우 충돌 주석을 유지한다. |

## 생성 예정 산출물

| 산출물 | 내용 |
| --- | --- |
| `canbus/` | 병합 점검 필요사항을 반영한 2-4 재진행 header 결과물 8개 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_작업내용.md` | 재병합 적용 내용 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_점검_필요사항.md` | 재병합 후 남은 사용자 점검 필요사항 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_오류사항.md` | 오류 및 제한 사항 |
| `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_작업기록.md` | 작업 log |

## 검증 계획

1. 결과 `canbus/`에 8개 header가 생성되었는지 확인한다.
2. 기존 2-4 결과 폴더와 원본/BK 입력 폴더를 수정하지 않았는지 확인한다.
3. 병합 점검 필요사항의 확정 항목이 결과 header에 반영되었는지 확인한다.
4. 결과 header 8개 include 조합을 `g++ -fsyntax-only`로 문법 확인한다.
5. 남은 충돌 또는 사용자 판단 필요사항은 새 `점검_필요사항.md`에 기록한다.

## 진행 조건

이 문서는 예정 작업계획이다.

사용자가 이 계획을 확인하고 명시적으로 동의한 뒤에만 실제 2-4 병합 재진행을 수행한다.
