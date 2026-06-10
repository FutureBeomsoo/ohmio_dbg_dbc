# dbc_CAN_peripheral.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 1212 | 1713 |
| SHA256 | 2a0e3537d5ff | 1d5a6995f92b |
| Include | 2 | 5 |
| Define | 0 | 0 |
| Struct/Message | 52 | 47 |
| Enum | 0 | 0 |
| CAN_ID | 0 | 0 |
| Function | 60 | 58 |
| Unified diff | +187 | -688 |

## 전처리/Define 비교

| Include | 구분 | 비고 |
| --- | --- | --- |
| "ConversionHelper.h" | OhmioLibraries_BK에만 있음 |  |
| <assert.h> | OhmioLibraries_BK에만 있음 |  |
| <math.h> | OhmioLibraries_BK에만 있음 |  |

- define 차이 없음.

## Message/Struct 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 struct | `AirConJJK161StatusMsg`, `AirConVersionMsg`, `BMSChargingCurrent`, `BMSChargingCurrentReply`, `Recovery` | 5 |
| 공통 struct의 signal layout 차이 | `AirConReqMsg`, `BMSStatusMsg8` | 2 |

### 공통 struct signal layout 차이

| Struct | 차이 내용 |
| --- | --- |
| AirConReqMsg | Origin_36_merge only: `JJK161Level`, `roofLight`<br>total bits 19 vs 8 |
| BMSStatusMsg8 | Origin_36_merge only: `cellSamplingTemp4`, `cellSamplingTemp5`, `cellSamplingTemp6`<br>bit width changed: `cellSamplingTemp`, `cellSamplingTemp2`, `cellSamplingTemp3` |

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

- enum 차이 없음.

## 함수 선언/정의 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 함수 | `AirConJJK161StatusMsg_FromCan`, `AirConJJK161StatusMsg_ToCan` | 2 |
| 동일 함수의 선언/정의 형태 변경 | `AVASReqMsg_FromCan`, `AVASReqMsg_ToCan`, `AVASStatusMsg_FromCan`, `AVASStatusMsg_ToCan`, `AirConReqMsg_FromCan`, `AirConReqMsg_ToCan`, `AirConStatusMsg_FromCan`, `AirConStatusMsg_ToCan`, `BMS2ChargerReqMsg_FromCan`, `BMS2ChargerReqMsg_ToCan`, `BMSStatusMsg12_FromCan`, `BMSStatusMsg12_ToCan`, `BMSStatusMsg2_FromCan`, `BMSStatusMsg2_ToCan`, `BMSStatusMsg3_FromCan`, `BMSStatusMsg3_ToCan`, `BMSStatusMsg4_FromCan`, `BMSStatusMsg4_ToCan`, `BMSStatusMsg5_FromCan`, `BMSStatusMsg5_ToCan`, `BMSStatusMsg6_FromCan`, `BMSStatusMsg6_ToCan`, `BMSStatusMsg7_FromCan`, `BMSStatusMsg7_ToCan`, `BMSStatusMsg8_FromCan`, `BMSStatusMsg8_ToCan`, `BmsLotteChargeVehicle_FromCan`, `BmsLotteChargeVehicle_ToCan`, `BmsLotteChargerInfo_FromCan`, `BmsLotteChargerInfo_ToCan`, `BmsLotteDrive1_FromCan`, `BmsLotteDrive1_ToCan`, `BmsLotteDrive2_FromCan`, `BmsLotteDrive2_ToCan`, `BmsLotteDrive3_FromCan`, `BmsLotteDrive3_ToCan`, `BmsLotteLandmark6_FromCan`, `BmsLotteLandmark6_ToCan`, `BmsLotteLandmark7_FromCan`, `BmsLotteLandmark7_ToCan`, `BmsLotteLandmark8_FromCan`, `BmsLotteLandmark8_ToCan`, `BmsLotteTotalChangeValue_FromCan`, `BmsLotteTotalChangeValue_ToCan`, `ChargerStatusMsg_FromCan`, `ChargerStatusMsg_ToCan`, `DTGSpeedRpmMsg_FromCan`, `DTGSpeedRpmMsg_ToCan`, `DoorStatusMsg_FromCan`, `DoorStatusMsg_ToCan`, ... (8개 추가) | 58 |

| Function | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| AVASReqMsg_FromCan | prototype | static definition |
| AVASReqMsg_ToCan | prototype | static definition |
| AVASStatusMsg_FromCan | prototype | static definition |
| AVASStatusMsg_ToCan | prototype | static definition |
| AirConReqMsg_FromCan | prototype | static definition |
| AirConReqMsg_ToCan | prototype | static definition |
| AirConStatusMsg_FromCan | prototype | static definition |
| AirConStatusMsg_ToCan | prototype | static definition |
| BMS2ChargerReqMsg_FromCan | prototype | static definition |
| BMS2ChargerReqMsg_ToCan | prototype | static definition |
| BMSStatusMsg12_FromCan | prototype | static definition |
| BMSStatusMsg12_ToCan | prototype | static definition |
| BMSStatusMsg2_FromCan | prototype | static definition |
| BMSStatusMsg2_ToCan | prototype | static definition |
| BMSStatusMsg3_FromCan | prototype | static definition |
| BMSStatusMsg3_ToCan | prototype | static definition |
| BMSStatusMsg4_FromCan | prototype | static definition |
| BMSStatusMsg4_ToCan | prototype | static definition |
| BMSStatusMsg5_FromCan | prototype | static definition |
| BMSStatusMsg5_ToCan | prototype | static definition |
| BMSStatusMsg6_FromCan | prototype | static definition |
| BMSStatusMsg6_ToCan | prototype | static definition |
| BMSStatusMsg7_FromCan | prototype | static definition |
| BMSStatusMsg7_ToCan | prototype | static definition |
| BMSStatusMsg8_FromCan | prototype | static definition |
| BMSStatusMsg8_ToCan | prototype | static definition |
| BmsLotteChargeVehicle_FromCan | prototype | static definition |
| BmsLotteChargeVehicle_ToCan | prototype | static definition |
| BmsLotteChargerInfo_FromCan | prototype | static definition |
| BmsLotteChargerInfo_ToCan | prototype | static definition |
| BmsLotteDrive1_FromCan | prototype | static definition |
| BmsLotteDrive1_ToCan | prototype | static definition |
| BmsLotteDrive2_FromCan | prototype | static definition |
| BmsLotteDrive2_ToCan | prototype | static definition |
| BmsLotteDrive3_FromCan | prototype | static definition |
| BmsLotteDrive3_ToCan | prototype | static definition |
| BmsLotteLandmark6_FromCan | prototype | static definition |
| BmsLotteLandmark6_ToCan | prototype | static definition |
| BmsLotteLandmark7_FromCan | prototype | static definition |
| BmsLotteLandmark7_ToCan | prototype | static definition |
| BmsLotteLandmark8_FromCan | prototype | static definition |
| BmsLotteLandmark8_ToCan | prototype | static definition |
| BmsLotteTotalChangeValue_FromCan | prototype | static definition |
| BmsLotteTotalChangeValue_ToCan | prototype | static definition |
| ChargerStatusMsg_FromCan | prototype | static definition |
| ChargerStatusMsg_ToCan | prototype | static definition |
| DTGSpeedRpmMsg_FromCan | prototype | static definition |
| DTGSpeedRpmMsg_ToCan | prototype | static definition |
| DoorStatusMsg_FromCan | prototype | static definition |
| DoorStatusMsg_ToCan | prototype | static definition |
| Foot1Status_FromCan | prototype | static definition |
| Foot1Status_ToCan | prototype | static definition |
| Foot2Status_FromCan | prototype | static definition |
| Foot2Status_ToCan | prototype | static definition |
| StepStatusMsg_FromCan | prototype | static definition |
| StepStatusMsg_ToCan | prototype | static definition |
| WiperMsg_FromCan | prototype | static definition |
| WiperMsg_ToCan | prototype | static definition |

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| 충돌/변경 판단 필요 | 동일 이름/ID에서 bit 구조, 설명, enum 값 차이가 있음 |
| 함수 구현 위치 정책 필요 | header 내부 static 구현과 prototype 중심 구조가 혼재함 |
