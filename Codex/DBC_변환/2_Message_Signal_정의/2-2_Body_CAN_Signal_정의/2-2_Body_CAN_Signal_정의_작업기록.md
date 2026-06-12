# 2-2_Body_CAN_Signal_정의 작업기록

## 2026-06-12 13:02:42 KST

- 작업 1 BO 초안 기준 Message 85개를 입력으로 사용했다.
- Signal 444개를 생성했다.
- 예약 필드 41개는 DBC Signal에서 제외하고 점검 필요사항에 기록했다.
- Big Endian Signal 29개를 DBC `@0`으로 표기하고 점검 필요사항에 기록했다.
- `CM_ BO_` comment 85개를 DBC 하단에 모아 배치했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 14:02:47 KST

- 사용자 의견에 따라 `Recovery`를 Body Task 2 산출물에서만 수동 보정했다.
- 원본 헤더의 `Recovery_t`는 수정하지 않았다.
- `Recovery` DBC DLC를 1에서 8로 변경했다.
- `Recovery`에 `byte0`~`byte7` 8개 Signal을 추가했다.
- Body CAN Signal 수는 444개에서 452개로 변경되었다.
- 예약 제외 항목에서 `Recovery.reserved`를 제거해 예약 제외 수는 41개에서 40개로 변경되었다.
