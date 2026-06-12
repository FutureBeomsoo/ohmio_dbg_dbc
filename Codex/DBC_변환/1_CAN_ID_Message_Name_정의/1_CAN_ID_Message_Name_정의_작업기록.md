# 1_CAN_ID_Message_Name_정의 작업기록

## 2026-06-12 10:42:07 KST

- `Codex/dbc_convert_Command.txt`의 작업 지시 및 절차 규칙을 확인했다.
- `작업 1`의 범위가 `*.dbc 파일 별 CAN ID 에 대한 Message Name 정의`임을 확인했다.
- 지시 파일의 절대 규칙에 따라 실제 작업 전 예정 작업계획 문서를 먼저 작성했다.
- 원본 헤더는 수정하지 않았다.

## 2026-06-12 10:50:44 KST

- 사용자 의견 2건을 확인했다.
- Chassis CAN과 Body CAN을 별개 하위 작업 폴더로 분리하도록 예정 작업계획을 재구성했다.
- 각 Message별 Signal 참고 대상 Struct comment를 산출물 형식에 추가했다.
- 실제 CAN ID 추출 작업은 진행하지 않았다.

## 2026-06-12 10:56:38 KST

- 사용자 승인 후 작업 1 실제 추출을 진행했다.
- Chassis CAN과 Body CAN을 별도 하위 작업 폴더로 분리하여 산출물을 작성했다.
- Chassis CAN `BO_` 초안 262개를 작성했다.
- Body CAN `BO_` 초안 85개를 작성했다.
- 각 `BO_` 정의에 Signal 참고 Struct `CM_ BO_` comment를 추가했다.
- DBC 파일 내부 `VERSION` 문자열은 DBC 도구 호환성을 위해 ASCII로 정리했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:18:22 KST

- Chassis CAN의 `ErrorFrontSteering`, `ErrorRearSteering` 중복 주석 및 enum/struct 분리 선언 내용을 별도 문서로 기록했다.
- 작성 파일: `1-1_Chassis_CAN_Message_Name_정의/1-1_Chassis_CAN_Message_Name_정의_ErrorSteering_중복주석_기록.md`
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:48:16 KST

- Chassis CAN 사용자 점검 필요사항의 사용자 의견을 확인했다.
- Struct/DLC 미확인 CAN_ID enum 15개를 적용 제외 확정으로 확인하고 `Codex/사용자_참고_사항.md`에 미추적 Message 목록을 작성했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:51:55 KST

- Chassis CAN 및 Body CAN 사용자 점검 필요사항의 사용자 의견을 확인하고 적용했다.
- Chassis CAN은 `ErrorSteering_t` 연결 확정 및 Struct/DLC 미확인 CAN_ID enum 15개 적용 제외 확정으로 점검사항을 정리했다.
- Body CAN은 확장 ID에 `0x80000000` 플래그를 더한 Vector DBC 표기로 `BO_` 초안과 작업내용의 `DBC CAN ID` 값을 갱신했다.
- 원본 헤더 파일은 수정하지 않았다.
