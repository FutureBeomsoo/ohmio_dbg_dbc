# 2_Message_Signal_정의 작업기록

## 2026-06-12 11:51:55 KST

- `Codex/dbc_convert_Command.txt`의 작업 2 지시사항을 확인했다.
- 작업 1 결과물의 Chassis `BO_` 262개, Body `BO_` 85개를 확인했다.
- Chassis 사용자 점검 반영사항과 Body 확장 ID Vector DBC 표기 반영사항을 확인했다.
- 지시 파일의 절차 규칙에 따라 실제 Signal 추출 전 예정 작업계획 문서를 먼저 작성했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 12:49:58 KST

- 사용자 의견 2건을 확인했다.
- Big Endian 확인 Signal은 DBC에 `@0`으로 표기하고 점검 필요사항에도 기록하도록 예정 작업계획을 수정했다.
- `CM_ BO_` comment는 DBC 하단 Comment 정의 부분에 모아서 작성하도록 예정 작업계획을 수정했다.
- 실제 Signal 추출 작업은 진행하지 않았다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 13:02:42 KST

- 사용자 승인에 따라 작업 2 Signal 정의 생성을 진행했다.
- Chassis CAN: Message 262개, Signal 1295개, 예약 제외 104개, Big Endian 0개.
- Body CAN: Message 85개, Signal 444개, 예약 제외 41개, Big Endian 29개.
- `CM_ BO_` comment는 각 DBC 하단에 모아 배치했다.
- Body CAN DBC ID는 작업 1의 Vector DBC 확장 ID 표기를 유지했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 13:04:04 KST

- DBC 하단 `CM_ BO_` comment의 문자열 구분자를 DBC 문법에 맞게 큰따옴표로 복원했다.
- 점검 필요사항의 추가 점검 메모가 Chassis/Body 대상 Struct 기준으로만 남도록 정리했다.
- byte-swap 기반 Big Endian 항목은 Big Endian 표기 Signal 표에 기록되어 있어 중복 decode 미파싱 메모를 제거했다.

## 2026-06-12 14:02:47 KST

- 사용자 의견에 따라 Body CAN `Recovery`를 Task 2 산출물에서만 수동 보정했다.
- 원본 헤더 파일은 수정하지 않았다.
- `Recovery`는 DLC 8, `byte0`~`byte7` Signal 8개로 반영했다.
- Body CAN Signal 수는 452개, 예약 제외 수는 40개로 갱신했다.
