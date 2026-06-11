# 2-4_dbc_MsgID_main_병합 작업내용

## 작업 범위

- 대상 header: `dbc_MsgID_main.h`
- Origin_36_merge: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_main.h`
- OhmioLibraries_BK: `OhmioLibraries_BK/include/canbus/dbc_MsgID_main.h`
- 결과 파일: `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_MsgID_main.h`
- 원본 파일은 수정하지 않았다.

## 적용 내용

- Origin_36_merge를 base로 유지했다.
- numeric ID 충돌 없는 BK-only CAN_ID를 추가했다: `CAN_ID_TELE_OP`, `CAN_ID_TRANS_DRIVE`, `CAN_ID_TRANS_JOYSTICK`, `CAN_ID_OBSTACLE_CTRL`, `CAN_ID_OBSTACLE_ACK`, `CAN_ID_OBSTACLE_TRACK`

## 파일 정보

| 항목 | Origin_36_merge | 2-4 결과 |
| --- | ---: | ---: |
| line | 917 | 923 |
| SHA256 | `4223f406ef5b` | `7ca4351bf740` |
