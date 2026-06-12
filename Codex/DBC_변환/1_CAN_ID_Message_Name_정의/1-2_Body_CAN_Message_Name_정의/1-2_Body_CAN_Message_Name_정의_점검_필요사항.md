# 1-2_Body_CAN_Message_Name_정의 점검 필요사항

## 사용자 확인 필요 요약

- 최초 점검 필요 항목 수: 1
- 사용자 의견 반영 후 남은 점검 필요 항목 수: 0
- CAN 2.0B 확장 ID는 `0x80000000` 플래그를 더한 Vector DBC 표기로 적용 완료.

## Transmit Node

- 원본 헤더에서 송신 Node를 확인할 수 없어 모든 `BO_` 정의의 Transmit Node를 지침에 따라 `Vector__XXX`로 작성했다.
- 실제 송신 Node 명칭이 필요한 경우 사용자 확인이 필요하다.

## CAN 2.0B 확장 ID DBC 표기

- Body CAN은 CAN 2.0B이고 11-bit 범위를 초과하는 ID를 포함한다.
- 사용자 의견에 따라 사용하는 DBC 도구가 확장 ID에 `0x80000000` 플래그를 더한 Vector DBC 표기를 사용하는 것으로 확정했다.
- Body CAN `BO_` 초안의 `BO_` 및 `CM_ BO_` CAN ID는 원본 CAN ID에 `0x80000000`을 더한 10진수 값으로 갱신했다.
- 원본 CAN ID는 `CM_ BO_` comment의 `original CAN ID`와 작업내용 문서의 `원본 CAN ID` 컬럼에 유지했다.

## message ID 주석 미연결 항목

- 없음

## CAN_ID enum에는 있으나 Struct/DLC가 확인되지 않은 항목

- 없음

## Struct에는 있으나 CAN_ID enum에는 없는 항목

- 없음

## Struct Message Name과 CAN_ID enum comment 불일치

- 없음

## 사용자 의견
    사용하는 DBC 도구가 확장 ID에 `0x80000000` 플래그를 더한 Vector DBC 표기 적용 확정.

## 적용 결과

- Body CAN 확장 ID Vector DBC 표기 적용 완료.
- 원본 헤더 파일은 수정하지 않음.
