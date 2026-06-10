# 2-1_Origin_36_병합 작업내용

## 작업 범위
- `Codex/can_headerfile_commnad.txt`의 `2-1. OhmioLibraries와 OhmioLibraries_36 병합`을 수행했다.
- `OhmioLibraries`를 Origin으로 보고 `OhmioLibraries_36` 내용을 병합했다.
- `OhmioLibraries_36/Ohmio_lib_include`는 `OhmioLibraries_36`과 동일한 중복본으로 보고 제외했다.
- `OhmioLibraries_BK`와 `2-2. 2-1 통합결과 재비교`는 수행하지 않았다.

## 생성 위치
- 통합 header: `Codex/파일_통합/2-1_Origin_36_병합/canbus`
- 작업 문서: `Codex/파일_통합/2-1_Origin_36_병합`

## 생성 파일
| 파일 | 처리 내용 |
| --- | --- |
| `additionalDbcCan.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |
| `ConversionHelper.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |
| `dbc_CAN.h` | Origin 기준 + 36의 reserved 대체 Signal 반영 + 충돌 주석 기록 |
| `dbc_CAN_peripheral.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |
| `dbc_MsgID_main.h` | Origin 기준 + 36의 reserved 대체 설명 반영 + 충돌 주석 기록 |
| `dbc_MsgID_peripheral.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |
| `dbc_MsgID_security.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |
| `Security_CAN.h` | Origin과 36이 동일하여 Origin 파일 그대로 반영 |

## 주요 병합 내용
- `dbc_CAN.h`
  - `FusError_t` bit22를 36의 실제 Signal인 `fus_conflicting_inputs`로 대체했다.
  - `FusionFlagsMsg_t` bit22를 36의 실제 Signal인 `conflicting_inputs`로 대체했다.
  - `FusionFlagsMsg_t` bit34는 사용자 확인에 따라 `w_no_engine_state`로 확정하고, 36의 `no_engine_state` 명칭은 참고 주석으로 표시했다.
  - `ObstaclePcWarningErrorCode`는 사용자 확인에 따라 Origin 기준 `Obs_Keyframe_Saver`를 유지했다.
  - `ObstaclePcWarning_t` bit14는 사용자 확인에 따라 Origin 기준 `ObsKeyframeSaverError`를 유지하고, 36의 `ObsKeyframeDatabaseError` 명칭은 병합 기준에서 제외했다.
- `dbc_MsgID_main.h`
  - Origin의 `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67`을 유지했다.
  - 36의 version/hash 차이는 참고 주석으로 표시했다.
  - `CAN_ID_FUS_ERROR`와 `CAN_ID_FUSION_FLAGS`의 bit22 설명을 `conflicting_inputs` 계열로 갱신했다.
  - `CAN_ID_OBSTACLE_PC_WARNING`은 사용자 확인에 따라 Origin 기준 설명을 유지했다.
  - `CAN_ID_FUSION_FLAGS`는 사용자 확인에 따라 `FusionFlagsMsg_t` 기준 설명을 유지했다.

## 추가 수정 반영
- `2-1_Origin_36_병합_수정_Obs_Keyframe_Saver_확정반영` 작업으로 `ObstaclePcWarning_t` bit14 사용자 확인 내용을 반영했다.
- `dbc_CAN.h`에서 36의 bit14 명칭 alias인 `Obs_Keyframe_Database = Obs_Keyframe_Saver`를 제거했다.
- `dbc_CAN.h`, `dbc_MsgID_main.h`에서 `ObsKeyframeDatabaseError` 관련 점검 주석을 제거했다.
- `Obs_Keyframe_Loader_Database`, `ObsKeyframeLoaderDatabaseError`는 Origin 기준 항목으로 유지했다.

## 추가 수정 반영 - 잔여 점검 항목 확정
- `2-1_Origin_36_병합_수정_잔여점검항목_확정반영` 작업으로 남은 점검 필요 항목 3개를 사용자 확인 완료 기준으로 반영했다.
- `FusionFlagsMsg_t` bit34는 `w_no_engine_state`로 확정하고, `OhmioLibraries_36` 기준 명칭 `no_engine_state`는 주석으로 표기했다.
- `dbc_MsgID_main.h` version/hash는 현재 통합본 값 `MAIN_CANBUS_VERSION_MINOR 15`, `MAIN_CANBUS_VERSION_BUILD 0xBEC99F67`을 유지했다.
- `CAN_ID_FUSION_FLAGS`는 `FusionFlagsMsg_t` 기준 설명을 유지했다.
- 통합 코드에서 `OHMIO_INTEGRATION_CHECK` 점검 주석을 제거했다.

## 확인 사항
- 대상 header 8개가 모두 생성되었음을 확인했다.
- `dbc_CAN.h`, `dbc_CAN_peripheral.h`, `dbc_MsgID_main.h`는 `gcc -fsyntax-only` 조건에서 통과했다.
- `ConversionHelper.h`는 `<stdint.h>` 선행 include 조건(`gcc -include stdint.h`)에서 통과했다.
