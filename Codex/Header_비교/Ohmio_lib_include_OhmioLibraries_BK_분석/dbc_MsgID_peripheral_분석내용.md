# dbc_MsgID_peripheral.h 비교 분석

- 비교 A: `Ohmio_lib_include` - `OhmioLibraries_36/Ohmio_lib_include/include/canbus/dbc_MsgID_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_MsgID_peripheral.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목           | Ohmio_lib_include | OhmioLibraries_BK |
| ------------ | ----------------- | ----------------- |
| Line         | 372               | 330               |
| SHA256       | 5377c208879f      | 10c7b65e1e0e      |
| Struct       | 0                 | 0                 |
| Enum         | 18                | 16                |
| CAN_ID       | 83                | 78                |
| Function     | 0                 | 0                 |
| Unified diff | -47               | +5                |


Diff hunk 위치:
- `@@ -1,9 +1,9 @@`
- `@@ -59,7 +59,7 @@`
- `@@ -69,25 +69,20 @@`
- `@@ -95,25 +90,6 @@`
- `@@ -128,24 +104,6 @@`

### 전처리/Include 비교
Macro 값 변경:
| Macro                           | Ohmio_lib_include | OhmioLibraries_BK |
| ------------------------------- | ----------------- | ----------------- |
| PERIPHERAL_CANBUS_VERSION_BUILD | 0xD1134632        | 0x0E350456        |
| PERIPHERAL_CANBUS_VERSION_MAJOR | 2                 | 1                 |
| PERIPHERAL_CANBUS_VERSION_MINOR | 3                 | 12                |


### CAN ID enum 비교
Ohmio_lib_include에만 있는 CAN_ID:
| Name                              | Value      | Comment                                                                                                                                                                                                                                                                            |
| --------------------------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| CAN_ID_AIR_CON_JJ_K161STATUS      | 0x18FFC13C | AirConJJK161StatusMsg:  bits0-1: mode; bits2-3: reserved; bits4-7: reqTemp; bits8-10: level; bits11-15: reserved1; bits16-23: airConTemp1; bits24-31: airConTemp2; bits32-39: roomTemp; bits40-47: outdoorTemp; bits48-55: reserved2; bits56-61: errorCode; bits62-63: errorLevel; |
| CAN_ID_AIR_CON_VERSION            | 0x18FFC13B | AirConVersionMsg:  bits0-7: reserved; bits8-15: ManufactCode; bits16-23: HWMajorVer; bits24-31: HWMinorVer;                                                                                                                                                                        |
| CAN_ID_BMS_CHARGING_CURRENT       | 0x1CF303F4 | BMSChargingCurrent:  bits0-7: byte0; bits8-15: byte1; bits16-23: byte2; bits24-31: ChargeCurrent; bits32-39: byte4;                                                                                                                                                                |
| CAN_ID_BMS_CHARGING_CURRENT_REPLY | 0x1CF304F4 | BMSChargingCurrentReply:  bits0-7: ChargingCurrent;                                                                                                                                                                                                                                |
| CAN_ID_RECOVERY                   | 0x1F000000 | Recovery:  bits0-7: reserved;                                                                                                                                                                                                                                                      |

동일 CAN_ID 이름/값의 주석 정의 변경:
#### CAN_ID_AIR_CON_REQ (0x18FF45F4)
  - Ohmio_lib_include: AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature; bits8-15: roofLight;
                       bits16-18: JJK161Level;
  - OhmioLibraries_BK: AirConReqMsg:  bits0-1: mode; bits2-3: level; bits4-7: temperature;
#### CAN_ID_BMS_STATUS8 (0x1089F5F4)
  - Ohmio_lib_include: BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-23: cellSamplingTemp;
                       bits24-31: cellSamplingTemp2; bits32-39: cellSamplingTemp3; bits40-47: cellSamplingTemp4;
                       bits48-55: cellSamplingTemp5; bits56-63: cellSamplingTemp6;
  - OhmioLibraries_BK: BMSStatusMsg8:  bits0-7: totalPacketFrames; bits8-15: packetSeqNum; bits16-31: cellSamplingTemp;
                       bits32-47: cellSamplingTemp2; bits48-63: cellSamplingTemp3;

### 일반 enum 비교
Ohmio_lib_include에만 있는 enum:
| Enum               | entry 수 |
| ------------------ | ------- |
| AIRCON_ERROR       | 8       |
| BMS_CHARGE_CURRENT | 7       |


### Struct/Message 비교
양쪽 struct 목록은 동일합니다.
공통 struct의 Signal layout 차이는 없습니다.

### 함수 선언/정의 비교
함수 선언/정의 차이는 없습니다.

## 사용자 점검 후보
- PERIPHERAL_CANBUS_VERSION_BUILD 버전 값 변경: 0xD1134632 -> 0x0E350456
- PERIPHERAL_CANBUS_VERSION_MAJOR 버전 값 변경: 2 -> 1
- PERIPHERAL_CANBUS_VERSION_MINOR 버전 값 변경: 3 -> 12
