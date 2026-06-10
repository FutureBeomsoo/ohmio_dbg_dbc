# dbc_CAN_peripheral.h 비교 분석

- 비교 A: `Ohmio_lib_include` - `OhmioLibraries_36/Ohmio_lib_include/include/canbus/dbc_CAN_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목           | Ohmio_lib_include | OhmioLibraries_BK |
| ------------ | ----------------- | ----------------- |
| Line         | 1211              | 1712              |
| SHA256       | 2a0e3537d5ff      | 1d5a6995f92b      |
| Struct       | 52                | 47                |
| Enum         | 0                 | 0                 |
| CAN_ID       | 0                 | 0                 |
| Function     | 60                | 58                |
| Unified diff | -187              | +688              |


Diff hunk 위치:
- `@@ -1,7 +1,9 @@`
- `@@ -175,17 +177,25 @@`
- `@@ -205,9 +215,22 @@`
- `@@ -224,9 +247,18 @@`
- `@@ -289,9 +321,38 @@`
- `@@ -310,9 +371,22 @@`
- `@@ -334,9 +408,24 @@`
- `@@ -378,9 +467,29 @@`
- `@@ -402,9 +511,18 @@`
- `@@ -479,9 +597,38 @@`
- `@@ -503,9 +650,39 @@`
- `@@ -536,9 +713,44 @@`
- `@@ -563,9 +775,36 @@`
- `@@ -587,9 +826,35 @@`
- `@@ -611,9 +876,35 @@`
- `@@ -624,26 +915,46 @@`
- `@@ -679,9 +990,35 @@`
- `@@ -702,9 +1039,27 @@`
- `@@ -731,9 +1086,35 @@`
- `@@ -752,57 +1133,23 @@`
- `@@ -824,9 +1171,23 @@`
- `@@ -942,9 +1303,25 @@`
- `@@ -966,9 +1343,27 @@`
- `@@ -992,9 +1387,27 @@`
- `@@ -1020,9 +1433,29 @@`
- `@@ -1046,9 +1479,26 @@`
- `@@ -1078,9 +1528,39 @@`
- `@@ -1109,9 +1589,37 @@`
- `@@ -1129,9 +1637,27 @@`
- `@@ -1151,9 +1677,24 @@`
- `@@ -1168,44 +1709,4 @@`

### 전처리/Include 비교
Include 차이:
| Include              | Ohmio_lib_include | OhmioLibraries_BK |
| -------------------- | ----------------- | ----------------- |
| "ConversionHelper.h" |                   | OhmioLibraries_BK |
| <assert.h>           |                   | OhmioLibraries_BK |
| <math.h>             |                   | OhmioLibraries_BK |


### CAN ID enum 비교
CAN_ID enum 항목이 없습니다.

### 일반 enum 비교
일반 enum 차이는 없습니다.

### Struct/Message 비교
Ohmio_lib_include에만 있는 struct:
| Struct                    | message ID                         | bit 수 |
| ------------------------- | ---------------------------------- | ----- |
| AirConJJK161StatusMsg_t   | 0x18FFC13C AirConJJK161StatusMsg   | 64    |
| AirConVersionMsg_t        | 0x18FFC13B AirConVersionMsg        | 32    |
| BMSChargingCurrentReply_t | 0x1CF304F4 BMSChargingCurrentReply | 8     |
| BMSChargingCurrent_t      | 0x1CF303F4 BMSChargingCurrent      | 40    |
| Recovery_t                | 0x1F000000 Recovery                | 8     |

변경된 공통 struct: 2개
#### AirConReqMsg_t
- Signal 총 bit 수 변경: Ohmio_lib_include=19, OhmioLibraries_BK=8
Ohmio_lib_include에만 있는 Signal:
| Signal      | 정의                               | OhmioLibraries_BK 겹침 영역 |
| ----------- | -------------------------------- | ----------------------- |
| JJK161Level | bits16-18 uint64_t JJK161Level:3 | -                       |
| roofLight   | bits8-15 uint64_t roofLight:8    | -                       |

#### BMSStatusMsg8_t
동일 Signal 이름의 정의 변경:
| Signal            | Ohmio_lib_include                                  | OhmioLibraries_BK                                   | 판정               |
| ----------------- | -------------------------------------------------- | --------------------------------------------------- | ---------------- |
| cellSamplingTemp  | bits16-23 uint64_t cellSamplingTemp:8, // degrees  | bits16-31 uint64_t cellSamplingTemp:16, // degrees  | bit/type/unit 변경 |
| cellSamplingTemp2 | bits24-31 uint64_t cellSamplingTemp2:8, // degrees | bits32-47 uint64_t cellSamplingTemp2:16, // degrees | bit/type/unit 변경 |
| cellSamplingTemp3 | bits32-39 uint64_t cellSamplingTemp3:8, // degrees | bits48-63 uint64_t cellSamplingTemp3:16, // degrees | bit/type/unit 변경 |

Ohmio_lib_include에만 있는 Signal:
| Signal            | 정의                                                 | OhmioLibraries_BK 겹침 영역                             |
| ----------------- | -------------------------------------------------- | --------------------------------------------------- |
| cellSamplingTemp4 | bits40-47 uint64_t cellSamplingTemp4:8, // degrees | bits32-47 uint64_t cellSamplingTemp2:16, // degrees |
| cellSamplingTemp5 | bits48-55 uint64_t cellSamplingTemp5:8, // degrees | bits48-63 uint64_t cellSamplingTemp3:16, // degrees |
| cellSamplingTemp6 | bits56-63 uint64_t cellSamplingTemp6:8, // degrees | bits48-63 uint64_t cellSamplingTemp3:16, // degrees |

비트 범위 충돌:
| 겹침        | Ohmio_lib_include                                  | OhmioLibraries_BK                                   | 판정                             |
| --------- | -------------------------------------------------- | --------------------------------------------------- | ------------------------------ |
| bits16-23 | bits16-23 uint64_t cellSamplingTemp:8, // degrees  | bits16-31 uint64_t cellSamplingTemp:16, // degrees  | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits24-31 | bits24-31 uint64_t cellSamplingTemp2:8, // degrees | bits16-31 uint64_t cellSamplingTemp:16, // degrees  | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits32-39 | bits32-39 uint64_t cellSamplingTemp3:8, // degrees | bits32-47 uint64_t cellSamplingTemp2:16, // degrees | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits40-47 | bits40-47 uint64_t cellSamplingTemp4:8, // degrees | bits32-47 uint64_t cellSamplingTemp2:16, // degrees | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits48-55 | bits48-55 uint64_t cellSamplingTemp5:8, // degrees | bits48-63 uint64_t cellSamplingTemp3:16, // degrees | 동일 bit 영역의 non-reserved 정의 불일치 |
| bits56-63 | bits56-63 uint64_t cellSamplingTemp6:8, // degrees | bits48-63 uint64_t cellSamplingTemp3:16, // degrees | 동일 bit 영역의 non-reserved 정의 불일치 |

물리/편의 member 차이:
| member            | Ohmio_lib_include        | OhmioLibraries_BK |
| ----------------- | ------------------------ | ----------------- |
| cellSamplingTemp4 | double cellSamplingTemp4 | -                 |
| cellSamplingTemp5 | double cellSamplingTemp5 | -                 |
| cellSamplingTemp6 | double cellSamplingTemp6 | -                 |


### 함수 선언/정의 비교
Ohmio_lib_include에만 있는 함수:
| Function                      | Kind      | Signature                                                         |
| ----------------------------- | --------- | ----------------------------------------------------------------- |
| AirConJJK161StatusMsg_FromCan | prototype | void AirConJJK161StatusMsg_FromCan(AirConJJK161StatusMsg_t * msg) |
| AirConJJK161StatusMsg_ToCan   | prototype | void AirConJJK161StatusMsg_ToCan(AirConJJK161StatusMsg_t * msg)   |

함수 선언/정의 형태 변경:
| Function                         | Ohmio_lib_include | OhmioLibraries_BK |
| -------------------------------- | ----------------- | ----------------- |
| AVASReqMsg_FromCan               | prototype         | static definition |
| AVASReqMsg_ToCan                 | prototype         | static definition |
| AVASStatusMsg_FromCan            | prototype         | static definition |
| AVASStatusMsg_ToCan              | prototype         | static definition |
| AirConReqMsg_FromCan             | prototype         | static definition |
| AirConReqMsg_ToCan               | prototype         | static definition |
| AirConStatusMsg_FromCan          | prototype         | static definition |
| AirConStatusMsg_ToCan            | prototype         | static definition |
| BMS2ChargerReqMsg_FromCan        | prototype         | static definition |
| BMS2ChargerReqMsg_ToCan          | prototype         | static definition |
| BMSStatusMsg12_FromCan           | prototype         | static definition |
| BMSStatusMsg12_ToCan             | prototype         | static definition |
| BMSStatusMsg2_FromCan            | prototype         | static definition |
| BMSStatusMsg2_ToCan              | prototype         | static definition |
| BMSStatusMsg3_FromCan            | prototype         | static definition |
| BMSStatusMsg3_ToCan              | prototype         | static definition |
| BMSStatusMsg4_FromCan            | prototype         | static definition |
| BMSStatusMsg4_ToCan              | prototype         | static definition |
| BMSStatusMsg5_FromCan            | prototype         | static definition |
| BMSStatusMsg5_ToCan              | prototype         | static definition |
| BMSStatusMsg6_FromCan            | prototype         | static definition |
| BMSStatusMsg6_ToCan              | prototype         | static definition |
| BMSStatusMsg7_FromCan            | prototype         | static definition |
| BMSStatusMsg7_ToCan              | prototype         | static definition |
| BMSStatusMsg8_FromCan            | prototype         | static definition |
| BMSStatusMsg8_ToCan              | prototype         | static definition |
| BmsLotteChargeVehicle_FromCan    | prototype         | static definition |
| BmsLotteChargeVehicle_ToCan      | prototype         | static definition |
| BmsLotteChargerInfo_FromCan      | prototype         | static definition |
| BmsLotteChargerInfo_ToCan        | prototype         | static definition |
| BmsLotteDrive1_FromCan           | prototype         | static definition |
| BmsLotteDrive1_ToCan             | prototype         | static definition |
| BmsLotteDrive2_FromCan           | prototype         | static definition |
| BmsLotteDrive2_ToCan             | prototype         | static definition |
| BmsLotteDrive3_FromCan           | prototype         | static definition |
| BmsLotteDrive3_ToCan             | prototype         | static definition |
| BmsLotteLandmark6_FromCan        | prototype         | static definition |
| BmsLotteLandmark6_ToCan          | prototype         | static definition |
| BmsLotteLandmark7_FromCan        | prototype         | static definition |
| BmsLotteLandmark7_ToCan          | prototype         | static definition |
| BmsLotteLandmark8_FromCan        | prototype         | static definition |
| BmsLotteLandmark8_ToCan          | prototype         | static definition |
| BmsLotteTotalChangeValue_FromCan | prototype         | static definition |
| BmsLotteTotalChangeValue_ToCan   | prototype         | static definition |
| ChargerStatusMsg_FromCan         | prototype         | static definition |
| ChargerStatusMsg_ToCan           | prototype         | static definition |
| DTGSpeedRpmMsg_FromCan           | prototype         | static definition |
| DTGSpeedRpmMsg_ToCan             | prototype         | static definition |
| DoorStatusMsg_FromCan            | prototype         | static definition |
| DoorStatusMsg_ToCan              | prototype         | static definition |
| Foot1Status_FromCan              | prototype         | static definition |
| Foot1Status_ToCan                | prototype         | static definition |
| Foot2Status_FromCan              | prototype         | static definition |
| Foot2Status_ToCan                | prototype         | static definition |
| StepStatusMsg_FromCan            | prototype         | static definition |
| StepStatusMsg_ToCan              | prototype         | static definition |
| WiperMsg_FromCan                 | prototype         | static definition |
| WiperMsg_ToCan                   | prototype         | static definition |


## 사용자 점검 후보
- BMSStatusMsg8_t: non-reserved bit 범위 충돌 6건
