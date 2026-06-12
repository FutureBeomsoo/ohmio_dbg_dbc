# 1-2_Body_CAN_Message_Name_정의 작업기록

## 2026-06-12 10:56:38 KST

- `Body` CAN 대상 작업 폴더를 생성했다.
- Struct 대상 헤더 2개에서 `// message ID`와 연결 struct/DLC를 추출했다.
- MsgID 대상 헤더 2개의 `CAN_ID_*` enum과 추출 결과를 대조했다.
- DBC `BO_` 초안 85개를 작성했다.
- Transmit Node는 확인 불가로 모두 `Vector__XXX`를 적용했다.
- CAN 2.0B 확장 ID의 DBC 표기 방식 확인 필요사항을 기록했다.
- DBC 파일 내부 `VERSION` 문자열은 DBC 도구 호환성을 위해 ASCII로 정리했다.
- 원본 헤더 파일은 수정하지 않았다.

## 2026-06-12 11:51:55 KST

- 사용자 점검 필요사항의 사용자 의견을 확인했다.
- CAN 2.0B 확장 ID에 `0x80000000` 플래그를 더한 Vector DBC 표기 적용을 확정했다.
- `1-2_Body_CAN_Message_Name_정의_BO_초안.dbc`의 `BO_` 및 `CM_ BO_` CAN ID 85개를 원본 CAN ID + `0x80000000` 값으로 갱신했다.
- `1-2_Body_CAN_Message_Name_정의_작업내용.md`의 `DBC CAN ID` 컬럼도 Vector DBC 표기 값으로 갱신했다.
- 원본 헤더 파일은 수정하지 않았다.
