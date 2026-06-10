# 2-1_Origin_36_병합 예정 작업계획

## 작업 목적
- `Codex/can_headerfile_commnad.txt`의 `2-1. OhmioLibraries와 OhmioLibraries_36 병합`을 수행한다.
- `1. file 비교 분석` 결과를 기준으로 두 폴더의 CAN header 파일을 통합한다.
- 사용자 지시에 따라 `OhmioLibraries`를 Origin으로 보고, 이번 통합본 명칭은 `Origin_36_병합`으로 한다.

## 작업 범위
- 비교/병합 대상 원본:
  - Origin: `OhmioLibraries/include/canbus`
  - 36 병합 대상: `OhmioLibraries_36/include/canbus`
- 통합 결과 위치:
  - `Codex/파일_통합/2-1_Origin_36_병합/canbus`
- 작업 문서 위치:
  - `Codex/파일_통합/2-1_Origin_36_병합/`

## 대상 파일
- `additionalDbcCan.h`
- `ConversionHelper.h`
- `dbc_CAN.h`
- `dbc_CAN_peripheral.h`
- `dbc_MsgID_main.h`
- `dbc_MsgID_peripheral.h`
- `dbc_MsgID_security.h`
- `Security_CAN.h`

## 제외 범위
- `2-2. 2-1 통합결과 재비교`는 이번 작업에서 수행하지 않는다.
- `OhmioLibraries_BK` 병합은 수행하지 않는다.
- `OhmioLibraries_36/Ohmio_lib_include` 병합은 수행하지 않는다.
- 원본 폴더 및 원본 파일은 수정하지 않는다.


## 사용자 지시 반영 기준
- `OhmioLibraries`는 Origin으로 정의한다.
- `OhmioLibraries_36`은 Origin에 병합할 36 기준본으로 정의한다.
- `OhmioLibraries_36/Ohmio_lib_include`는 `OhmioLibraries_36`과 동일한 것으로 확인된 중복본으로 보고, 이번 비교 및 통합에서 제외한다.
- 이번 통합본의 명칭은 `Origin_36_병합`으로 한다.
- 작업 폴더, 산출물 문서명, 통합 header 결과 위치는 사용자 동의 후 실제 진행 단계에서 `2-1_Origin_36_병합` 기준으로 생성한다.

## 작업 방식
- Origin인 `OhmioLibraries`를 기준 파일로 복사하여 `Origin_36_병합` 통합본을 생성한다.
- `OhmioLibraries_36`과 동일한 파일은 그대로 반영한다.
- 충돌 없이 한쪽에만 있는 정의는 통합본에 유지한다.
- `Reserved`/`reserved`/`unused` Signal 위치에 상대 파일의 실제 Signal 정의가 있으면 실제 Signal 정의로 대체한다.
- 같은 bit 위치에 non-reserved Signal끼리 이름 또는 의미가 다르면 임의 확정하지 않고 `OHMIO_INTEGRATION_CHECK` 주석을 추가한 뒤 점검 필요사항에 기록한다.
- 함수 정의는 Signal 충돌이 없고 확인 가능한 경우에만 반영한다.

## 예정 산출물
- `2-1_Origin_36_병합_작업내용.md`
- `2-1_Origin_36_병합_오류사항.md`
- `2-1_Origin_36_병합_점검_필요사항.md`
- `2-1_Origin_36_병합_작업기록.md`
- `canbus/` 통합 header 파일 8개


## 동의 전 중단
- 이 문서는 작업 시작 전 계획 문서이다.
- 사용자의 명시적 동의 전에는 `canbus/` 생성, header 복사, 병합 편집, 결과 비교를 수행하지 않는다.
- 사용자의 최초 "진행" 요청은 이 계획에 대한 동의로 간주하지 않는다.
