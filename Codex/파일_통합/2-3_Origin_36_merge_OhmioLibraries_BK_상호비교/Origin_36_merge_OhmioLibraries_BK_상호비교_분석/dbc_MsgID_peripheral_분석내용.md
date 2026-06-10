# dbc_MsgID_peripheral.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_peripheral.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 373 | 331 |
| SHA256 | 5377c208879f | 10c7b65e1e0e |
| Include | 0 | 0 |
| Define | 3 | 3 |
| Struct/Message | 0 | 0 |
| Enum | 18 | 16 |
| CAN_ID | 83 | 78 |
| Function | 0 | 0 |
| Unified diff | +47 | -5 |

## 전처리/Define 비교

- include 차이 없음.

| Define | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| PERIPHERAL_CANBUS_VERSION_BUILD | 0xD1134632         // 32 bit hash code for the dbc file | 0x0E350456         // 32 bit hash code for the dbc file |
| PERIPHERAL_CANBUS_VERSION_MAJOR | 2 | 1 |
| PERIPHERAL_CANBUS_VERSION_MINOR | 3 | 12 |

## Message/Struct 비교

- struct/message 차이 없음.

## CAN_ID 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 CAN_ID | `CAN_ID_AIR_CON_JJ_K161STATUS`, `CAN_ID_AIR_CON_VERSION`, `CAN_ID_BMS_CHARGING_CURRENT`, `CAN_ID_BMS_CHARGING_CURRENT_REPLY`, `CAN_ID_RECOVERY` | 5 |
| 동일 CAN_ID 이름의 값/설명 변경 | `CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` | 2 |

### CAN_ID 값/설명 변경 상세

| CAN_ID | Origin 값 | BK 값 | Origin 설명 | BK 설명 |
| --- | --- | --- | --- | --- |
| CAN_ID_AIR_CON_REQ | 0x18FF45F4 | 0x18FF45F4 | AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; bits8-15: roofLight; bits16-18: JJK161Level; | AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; |
| CAN_ID_BMS_STATUS8 | 0x1089F5F4 | 0x1089F5F4 | BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-23: cellSamplingTemp; bits24-31: cellSamplingTemp2; bits32-39: cellSamplingTemp3; bits40-47: cellSamplingTemp4; bits48-55: cellSamplingTemp5; bits56-63: cellSamplingTemp6; | BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-31: cellSamplingTemp; bits32-47: cellSamplingTemp2; bits48-63: cellSamplingTemp3; |

## Enum 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 enum | `AIRCON_ERROR`, `BMS_CHARGE_CURRENT` | 2 |
| 공통 enum entry 차이 | `COMMON_CAN_P` | 1 |

### 공통 enum entry 차이 상세

#### COMMON_CAN_P
| Entry | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| CAN_ID_AIR_CON_JJ_K161STATUS | 419414332 |  |
| CAN_ID_AIR_CON_VERSION | 419414331 |  |
| CAN_ID_BMS_CHARGING_CURRENT | 485688308 |  |
| CAN_ID_BMS_CHARGING_CURRENT_REPLY | 485688564 |  |
| CAN_ID_RECOVERY | 520093696 |  |


## 함수 선언/정의 비교

- 함수 선언/정의 차이 없음.

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| 충돌/변경 판단 필요 | 동일 이름/ID에서 bit 구조, 설명, enum 값 차이가 있음 |
| version/hash 또는 변환 정책 필요 | define 또는 helper 동작 차이 확인 필요 |
