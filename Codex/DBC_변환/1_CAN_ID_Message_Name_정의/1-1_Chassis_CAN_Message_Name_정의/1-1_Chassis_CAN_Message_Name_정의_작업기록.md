# 1-1_Chassis_CAN_Message_Name_정의 작업기록

## 2026-06-12 10:56:38 KST

- `Chassis` CAN 대상 작업 폴더를 생성했다.
- Struct 대상 헤더 2개에서 `// message ID`와 연결 struct/DLC를 추출했다.
- MsgID 대상 헤더 1개의 `CAN_ID_*` enum과 추출 결과를 대조했다.
- DBC `BO_` 초안 262개를 작성했다.
- Transmit Node는 확인 불가로 모두 `Vector__XXX`를 적용했다.
- 미연결 message ID 주석 2개를 점검 필요사항에 기록했다.
- Struct/DLC가 확인되지 않은 CAN_ID enum 항목 15개를 점검 필요사항에 기록했다.
- DBC 파일 내부 `VERSION` 문자열은 DBC 도구 호환성을 위해 ASCII로 정리했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:18:22 KST

- `ErrorFrontSteering`, `ErrorRearSteering`의 `additionalDbcCan.h`/`dbc_CAN.h` 중복 주석 및 enum/struct 분리 선언 내용을 별도 기록 파일로 작성했다.
- 작성 파일: `1-1_Chassis_CAN_Message_Name_정의_ErrorSteering_중복주석_기록.md`
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:48:16 KST

- 사용자 점검 필요사항의 사용자 의견을 확인했다.
- `ErrorFrontSteering`, `ErrorRearSteering`은 `dbc_CAN.h`의 `ErrorSteering_t` typedef struct 연결로 확정되었음을 확인했다.
- Struct/DLC가 확인되지 않은 CAN_ID enum 항목 15개는 적용 제외 확정으로 확인했다.
- `Codex/사용자_참고_사항.md`에 미추적 Message 목록을 작성했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:51:55 KST

- Chassis CAN 점검 필요사항 문서에 사용자 의견 반영 결과를 명시했다.
- `ErrorFrontSteering`, `ErrorRearSteering`은 기존 BO 초안의 `ErrorSteering_t` 연결이 확정된 상태이므로 DBC 초안 추가 변경 없음으로 정리했다.
- Struct/DLC 미확인 CAN_ID enum 15개는 적용 제외 확정 및 `Codex/사용자_참고_사항.md` 기록 완료로 정리했다.
- 원본 헤더 파일은 수정하지 않았다.
