# 1-1_Chassis_CAN_Message_Name_정의 점검 필요사항

## 사용자 확인 필요 요약

- 점검 필요 항목 수: 17

## Transmit Node

- 원본 헤더에서 송신 Node를 확인할 수 없어 모든 `BO_` 정의의 Transmit Node를 지침에 따라 `Vector__XXX`로 작성했다.
- 실제 송신 Node 명칭이 필요한 경우 사용자 확인이 필요하다.

## message ID 주석 미연결 항목

| 원본 헤더 | line | CAN ID | Message Name | 사유 |
| --- | --- | --- | --- | --- |
| additionalDbcCan.h | 137 | 0x12 | ErrorFrontSteering | 다음 typedef struct 확인 전 다른 코드가 나타남 |
| additionalDbcCan.h | 138 | 0x13 | ErrorRearSteering | 다음 typedef struct 확인 전 다른 코드가 나타남 |

## CAN_ID enum에는 있으나 Struct/DLC가 확인되지 않은 항목

| MsgID 헤더 | line | CAN ID | DBC CAN ID | 상수 | 추정 Message Name | comment |
| --- | --- | --- | --- | --- | --- | --- |
| dbc_MsgID_main.h | 259 | 0x708 | 1800 | CAN_ID_VEHICLE_VIN | VehicleVIN | VehicleVIN: |
| dbc_MsgID_main.h | 261 | 0x711 | 1809 | CAN_ID_DRIVE_DEBUG_Ex | DriveDebugMsg | DriveDebugMsg: |
| dbc_MsgID_main.h | 264 | 0x718 | 1816 | CAN_ID_FOOT1_DEBUG | Foot1DebugMsg | Foot1DebugMsg: |
| dbc_MsgID_main.h | 265 | 0x719 | 1817 | CAN_ID_FOOT2_DEBUG | Foot2DebugMsg | Foot2DebugMsg: |
| dbc_MsgID_main.h | 266 | 0x71C | 1820 | CAN_ID_EPB_DEBUG | EPBDebugMsg | EPBDebugMsg: |
| dbc_MsgID_main.h | 272 | 0x728 | 1832 | CAN_ID_FUSION_PERSISTENT_PARAMS | FusionPersistentParams | FusionPersistentParams: |
| dbc_MsgID_main.h | 273 | 0x73D | 1853 | CAN_ID_NET_COMMS | NetCommsMsg | NetCommsMsg: |
| dbc_MsgID_main.h | 277 | 0x7A0 | 1952 | CAN_ID_LOC_ASSERT | LocAssertMsg | LocAssertMsg: |
| dbc_MsgID_main.h | 278 | 0x7A1 | 1953 | CAN_ID_DRV_ASSERT | DrvAssertMsg | DrvAssertMsg: |
| dbc_MsgID_main.h | 279 | 0x7A4 | 1956 | CAN_ID_MANUAL_ASSERT | ManualAssertMsg | ManualAssertMsg: |
| dbc_MsgID_main.h | 280 | 0x7A5 | 1957 | CAN_ID_FUS_ASSERT | FusAssertMsg | FusAssertMsg: |
| dbc_MsgID_main.h | 281 | 0x7AC | 1964 | CAN_ID_EPB1_ASSERT | Epb1AssertMsg | Epb1AssertMsg: |
| dbc_MsgID_main.h | 282 | 0x7AD | 1965 | CAN_ID_EPB2_ASSERT | Epb2AssertMsg | Epb2AssertMsg: |
| dbc_MsgID_main.h | 283 | 0x7B3 | 1971 | CAN_ID_STARTUP_ASSERT | StartupAssertMsg | StartupAssertMsg: |
| dbc_MsgID_main.h | 284 | 0x7BA | 1978 | CAN_ID_SECURITY_ASSERT | SecurityAssertMsg | SecurityAssertMsg: |

## Struct에는 있으나 CAN_ID enum에는 없는 항목

- 없음

## Struct Message Name과 CAN_ID enum comment 불일치

- 없음

## 사용자 의견
    
ErrorFrontSteering : dbc_CAN.h 에 정의 된 ErrorSteering_t typedef struct로 연결 확정.
ErrorRearSteering : dbc_CAN.h 에 정의 된 ErrorSteering_t typedef struct로 연결 확정.

CAN_ID enum에는 있으나 Struct/DLC가 확인되지 않은 항목
적용 제외 확정.

Codex/ 위치에 사용자_참고_사항.md 을 생성하고 다음과 같이 기록

```
##미추적 Message 목록
(0x708) VehicleVIN 
(0x711) DriveDebugMsg 
(0x718) Foot1DebugMsg 
(0x719) Foot2DebugMsg 
(0x71C) EPBDebugMsg 
(0x728) FusionPersistentParams 
(0x73D) NetCommsMsg 
(0x7A0) LocAssertMsg 
(0x7A1) DrvAssertMsg 
(0x7A4) ManualAssertMsg 
(0x7A5) FusAssertMsg 
(0x7AC) Epb1AssertMsg 
(0x7AD) Epb2AssertMsg 
(0x7B3) StartupAssertMsg 
(0x7BA) SecurityAssertMsg
```