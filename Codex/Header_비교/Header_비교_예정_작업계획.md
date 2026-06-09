# Header_비교 예정 작업계획

## 작업 범위
- 원본 폴더: `OhmioLibraries`, `OhmioLibraries_36`, `OhmioLibraries_36/Ohmio_lib_include`, `OhmioLibraries_BK`
- 대상 파일: `additionalDbcCan.h`, `dbc_CAN_peripheral.h`, `dbc_CAN.h`, `Security_CAN.h`, `dbc_MsgID_main.h`, `dbc_MsgID_peripheral.h`, `dbc_MsgID_security.h`, `ConversionHelper.h`
- 산출물 위치: `Codex/Header_비교`

## 분석 방법
- 원본 헤더는 읽기 전용으로 유지한다.
- 4개 소스 루트의 6개 조합을 상호 비교한다.
- 파일 동일성, include/macro, CAN ID enum, 일반 enum, typedef struct Signal bit field, 함수 선언/정의를 비교한다.
- Reserved/unused 필드는 dummy bit field로 분류하고, 상대 파일의 non-reserved Signal과 겹치면 대체 후보로 별도 기록한다.

## 진행 근거
- 사용자가 `1. file 비교 분석 수행`을 명시하여 본 계획에 따라 분석을 진행했다.
