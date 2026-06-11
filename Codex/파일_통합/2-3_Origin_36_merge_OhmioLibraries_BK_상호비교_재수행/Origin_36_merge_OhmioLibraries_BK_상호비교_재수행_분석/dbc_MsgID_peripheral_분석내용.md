# dbc_MsgID_peripheral.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_peripheral.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 372 | 330 |
| SHA256 | 5377c208879f | 10c7b65e1e0e |
| Include | 0 | 0 |
| Define | 3 | 3 |
| Struct/Message | 0 | 0 |
| Enum | 18 | 16 |
| CAN_ID | 83 | 78 |
| Function | 0 | 0 |
| Unified diff | -47 | +5 |

## 전처리/Define 비교

- include 차이 없음.

| Define | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `PERIPHERAL_CANBUS_VERSION_MAJOR` | `2` | `1` | 값 변경 |
| `PERIPHERAL_CANBUS_VERSION_BUILD` | `0xD1134632` | `0x0E350456` | 값/주석 변경 |
| `PERIPHERAL_CANBUS_VERSION_MINOR` | `3` | `12` | 값/주석 변경 |

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 0 | - |
| OhmioLibraries_BK에만 있는 struct | 0 | - |
| 공통 struct 중 layout/comment 차이 | 0 | - |

## CAN_ID 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 CAN_ID | 5 | `CAN_ID_AIR_CON_JJ_K161STATUS`, `CAN_ID_AIR_CON_VERSION`, `CAN_ID_BMS_CHARGING_CURRENT`, `CAN_ID_BMS_CHARGING_CURRENT_REPLY`, `CAN_ID_RECOVERY` |
| OhmioLibraries_BK에만 있는 CAN_ID | 0 | - |
| 같은 CAN_ID 이름의 값 변경 | 0 | - |
| 같은 CAN_ID 이름의 설명 변경 | 2 | `CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` |
| 같은 numeric ID의 이름 차이 | 0 | - |

### CAN_ID 상세

| CAN_ID | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `CAN_ID_AIR_CON_JJ_K161STATUS` | `0x18ffc13c` AirConJJK161StatusMsg:  bits0-1: mode; bits2-3: reserved; bits4-7: reqTemp; bits8-10: level; bits11-15: reserved1; bits16-23: airConTemp1; bits24-31: airConTemp2; bits32-39: roomTemp; bits40-47: outdoorTemp; bits48-55: reserved2; bits56-61: errorCode; bits62-63: errorLevel; |  | Origin_36_merge에만 있음 |
| `CAN_ID_AIR_CON_VERSION` | `0x18ffc13b` AirConVersionMsg:  bits0-7: reserved; bits8-15: ManufactCode; bits16-23: HWMajorVer; bits24-31: HWMinorVer; |  | Origin_36_merge에만 있음 |
| `CAN_ID_BMS_CHARGING_CURRENT` | `0x1cf303f4` BMSChargingCurrent:  bits0-7: byte0; bits8-15: byte1; bits16-23: byte2; bits24-31: ChargeCurrent; bits32-39: byte4; |  | Origin_36_merge에만 있음 |
| `CAN_ID_BMS_CHARGING_CURRENT_REPLY` | `0x1cf304f4` BMSChargingCurrentReply:  bits0-7: ChargingCurrent; |  | Origin_36_merge에만 있음 |
| `CAN_ID_RECOVERY` | `0x1f000000` Recovery:  bits0-7: reserved; |  | Origin_36_merge에만 있음 |

### CAN_ID 설명/comment 차이

| CAN_ID | Value | Origin_36_merge 설명 | OhmioLibraries_BK 설명 |
| --- | --- | --- | --- |
| `CAN_ID_AIR_CON_REQ` | `0x18ff45f4` | AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; bits8-15: roofLight; bits16-18: JJK161Level; | AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; |
| `CAN_ID_BMS_STATUS8` | `0x1089f5f4` | BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-23: cellSamplingTemp; bits24-31: cellSamplingTemp2; bits32-39: cellSamplingTemp3; bits40-47: cellSamplingTemp4; bits48-55: cellSamplingTemp5; bits56-63: cellSamplingTemp6; | BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-31: cellSamplingTemp; bits32-47: cellSamplingTemp2; bits48-63: cellSamplingTemp3; |

## Enum 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 enum | 2 | `AIRCON_ERROR`, `BMS_CHARGE_CURRENT` |
| OhmioLibraries_BK에만 있는 enum | 0 | - |
| 공통 enum entry 차이 | 1 | `COMMON_CAN_P` |

### COMMON_CAN_P

| Entry | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `CAN_ID_AIR_CON_JJ_K161STATUS` | `0x18ffc13c` |  | Origin_36_merge에만 있음 |
| `CAN_ID_AIR_CON_VERSION` | `0x18ffc13b` |  | Origin_36_merge에만 있음 |
| `CAN_ID_BMS_CHARGING_CURRENT` | `0x1cf303f4` |  | Origin_36_merge에만 있음 |
| `CAN_ID_BMS_CHARGING_CURRENT_REPLY` | `0x1cf304f4` |  | Origin_36_merge에만 있음 |
| `CAN_ID_RECOVERY` | `0x1f000000` |  | Origin_36_merge에만 있음 |
| `CAN_ID_AIR_CON_REQ` | `0x18ff45f4` | `0x18ff45f4` | 주석 변경 |
| `CAN_ID_BMS_STATUS8` | `0x1089f5f4` | `0x1089f5f4` | 주석 변경 |

## Function 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 function | 0 | - |
| OhmioLibraries_BK에만 있는 function | 0 | - |
| 공통 function 형태/구현 차이 | 0 | - |
