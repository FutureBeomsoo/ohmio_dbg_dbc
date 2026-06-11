# 2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영 작업내용

## 작업 기준

| 항목 | 경로 |
| --- | --- |
| 기준 계획 | `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_예정_작업계획.md` |
| 기존 2-4 결과 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/` |
| 병합 점검 필요사항 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/` 하위 `*_병합_점검_필요사항.md` |
| 재진행 결과 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영/canbus/` |

## 생성 결과

기존 2-4 결과 header 8개를 새 재진행 폴더로 복사한 뒤, 병합 점검 필요사항의 사용자 확정 의견을 반영했다.

| Header | 처리 내용 |
| --- | --- |
| `additionalDbcCan.h` | 기존 2-4 결과 유지. BK 함수 `static` 활성 반영 상태 유지. |
| `ConversionHelper.h` | `<stdint.h>` 추가. Origin `value <= 0` clamp 정책 유지. |
| `dbc_CAN.h` | 사용자 확정 의견에 따른 layout/comment/function/struct 반영. |
| `dbc_CAN_peripheral.h` | 기존 2-4 결과 유지. layout 충돌 function 활성 반영 상태 유지. |
| `dbc_MsgID_main.h` | 기존 2-4 결과 유지. `CAN_ID_ERROR_TRANS`, `CAN_ID_ERROR_MOTOR_ADAPTOR` 제외 상태 유지. |
| `dbc_MsgID_peripheral.h` | 기존 2-4 결과 유지. Origin version/hash 및 comment 기준 유지. |
| `dbc_MsgID_security.h` | 기존 동일 결과 유지. |
| `Security_CAN.h` | 기존 동일 결과 유지. |

## `dbc_CAN.h` 반영 상세

| 항목 | 반영 내용 |
| --- | --- |
| `SystemReqMsg` | bits0-7 `mode`, bits32-39 `brakePressure`, bits40-59 `reserved`, bits60-61 `driveDisalowed`로 반영. |
| `TrackCtrlMsg_t` | `0x670 TrackCtrlObsMsg` comment mapping 추가. |
| `TrackAckMsg_t` | `0x671 TrackAckObsMsg` comment mapping 추가. |
| `TrackDataMsg_t` | `0x672 TrackDataObsMsg` comment mapping 추가. |
| `ManualDriveMsg_t` | `0x187 TransDriveMsg` comment mapping 추가. |
| `JoystickMsg_t` | `0x183 TeleOpMsg`, `0x188 TransJoystickMsg` comment mapping 추가. |
| `LongitudeMsg_t` | `0x221 longitudeFrontMsg`, `0x231 longitudeBackMsg` comment mapping 추가. |
| `LatitudeMsg_t` | BK `FusionLatitudeMsg_ToCan/FromCan` 로직을 `LatitudeMsg_ToCan/FromCan`으로 반영. |
| `IMUMag_ToCan()` | `status` assert 제외 확정 상태로 주석 정리. |
| Obsolete 계열 | Origin `ObsoleteMsg_t` 기준 주석을 유지하고, 사용자 확정에 따라 BK message 정의를 활성 추가. |

## Obsolete 계열 BK 정의 활성 추가

| Message ID | BK 정의 |
| --- | --- |
| `0x120` | `ObstacleDetectionLiDARMsg_t` |
| `0x121` | `UltraSoundMsg_t` |
| `0x160` | `BrakeReqMsg_t` |
| `0x220`, `0x230` | `GPSLatitudeMsg_t` |
| `0x222`, `0x232` | `HeightMsg_t` |
| `0x223`, `0x234` | `CombinedHeightMsg_t` |
| `0x233` | `HeadingMsg_t` |
| `0x250` | `UWBDistanceMsg_t` |
| `0x251` | `UWBLatitudeMsg_t` |
| `0x252` | `UWBLongitudeMsg_t` |
| `0x260` | `CompassMsg_t` |
| `0x321` | `DriveInfoMsg_t` |
| `0x710` | `LogIndMsg_t` |

`0x221`, `0x231`은 별도 struct를 만들지 않고 기존 `LongitudeMsg_t`에 mapping comment를 추가했다. BK에서도 `LongitudeMsg_t`가 `FusionLongitudeFront/Rear`와 `longitudeFront/back`을 함께 처리하는 동일 layout 구조이기 때문이다.

## 제외 확정 유지

| 항목 | 처리 |
| --- | --- |
| `ErrorMotorAdaptor` | 활성 추가 제외. Origin `CAN_ID_ERROR_NETWORK` 유지. |
| `ErrorTrans` | 활성 추가 제외. Origin `CAN_ID_TRANS1_ERROR` 유지. |
| `TransErrorCode` | 활성 추가 제외. |
| `PrintASCIIMsg` | 활성 추가 제외. Origin 정의 유지. |
| `FusionLatitudeMsg` | 별도 type 활성 추가 제외. `LatitudeMsg_t` 함수에 로직 반영. |
| `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` | `additionalDbcCan.h` 정의 유지. `dbc_CAN.h` 중복 추가 제외. |

## 검증

| 항목 | 결과 |
| --- | --- |
| 결과 header 개수 | 8개 확인 |
| 변경 파일 | `ConversionHelper.h`, `dbc_CAN.h` |
| 기존 2-4와 동일 유지 파일 | `additionalDbcCan.h`, `dbc_CAN_peripheral.h`, `dbc_MsgID_main.h`, `dbc_MsgID_peripheral.h`, `dbc_MsgID_security.h`, `Security_CAN.h` |
| 문법 검증 | `g++ -std=c++11 -fsyntax-only` 통과 |

## 추가 작업 반영

사용자 의견에 따라 현재 재진행 폴더 내에서 추가 작업을 수행했다.

| 항목 | 반영 내용 |
| --- | --- |
| 추가 작업계획 | `2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_추가작업_SystemReq_ObsoleteComment_예정_작업계획.md` 작성 |
| `SystemReqMsg` | `driveDisalowed :2`를 `driveDisalowed :1`, `errorCheck :1`로 수정 |
| Obsolete 계열 comment | 기존 Obsolete ID 묶음 comment 삭제 |
| 활성 BK 정의 comment | 활성 정의 앞 message ID comment를 `Obsolete_*` 기준으로 변경 |
| `ObsoleteMsg_t` | placeholder struct를 주석 처리 |
| 추가 검증 | 8개 header 동시 include 문법 검증 통과 |
