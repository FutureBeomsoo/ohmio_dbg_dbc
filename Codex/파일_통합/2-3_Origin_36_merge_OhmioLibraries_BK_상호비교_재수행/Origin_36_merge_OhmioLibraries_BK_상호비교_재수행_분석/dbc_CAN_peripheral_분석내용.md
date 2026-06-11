# dbc_CAN_peripheral.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN_peripheral.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 1211 | 1712 |
| SHA256 | 2a0e3537d5ff | 1d5a6995f92b |
| Include | 2 | 5 |
| Define | 1 | 1 |
| Struct/Message | 52 | 47 |
| Enum | 0 | 0 |
| CAN_ID | 0 | 0 |
| Function | 60 | 58 |
| Unified diff | -187 | +688 |

## 전처리/Define 비교

| Include | 구분 |
| --- | --- |
| `"ConversionHelper.h"` | OhmioLibraries_BK에만 있음 |
| `<assert.h>` | OhmioLibraries_BK에만 있음 |
| `<math.h>` | OhmioLibraries_BK에만 있음 |

- define 차이 없음.

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 5 | `AirConJJK161StatusMsg`, `AirConVersionMsg`, `BMSChargingCurrent`, `BMSChargingCurrentReply`, `Recovery` |
| OhmioLibraries_BK에만 있는 struct | 0 | - |
| 공통 struct 중 layout/comment 차이 | 2 | `AirConReqMsg`, `BMSStatusMsg8` |

### Origin_36_merge에만 있는 struct

| Struct | Line | Message ID comment | Total bits |
| --- | ---: | --- | ---: |
| `AirConJJK161StatusMsg` | 775 | 0x18FFC13C AirConJJK161StatusMsg | 64 |
| `AirConVersionMsg` | 760 | 0x18FFC13B AirConVersionMsg | 32 |
| `BMSChargingCurrent` | 1184 | 0x1CF303F4 BMSChargingCurrent | 40 |
| `BMSChargingCurrentReply` | 1200 | 0x1CF304F4 BMSChargingCurrentReply | 8 |
| `Recovery` | 1172 | 0x1F000000 Recovery | 8 |

### 공통 struct layout/comment 차이

| Struct | 차이 요약 | bit overlap 충돌 예시 |
| --- | --- | --- |
| `AirConReqMsg` | Origin_36_merge signal only: `JJK161Level`, `roofLight`<br>total bits 19 != 8 | - |
| `BMSStatusMsg8` | Origin_36_merge signal only: `cellSamplingTemp4`, `cellSamplingTemp5`, `cellSamplingTemp6`<br>same signal bit/type change: `cellSamplingTemp` width: 8 != 16; msb: 23 != 31; `cellSamplingTemp2` width: 8 != 16; lsb: 24 != 32; msb: 31 != 47; `cellSamplingTemp3` width: 8 != 16; lsb: 32 != 48; msb: 39 != 63<br>Origin_36_merge decoded field only: `cellSamplingTemp4`, `cellSamplingTemp5`, `cellSamplingTemp6` | 16-23: Origin `cellSamplingTemp`[16-23] vs BK `cellSamplingTemp`[16-31]<br>24-31: Origin `cellSamplingTemp2`[24-31] vs BK `cellSamplingTemp`[16-31]<br>32-39: Origin `cellSamplingTemp3`[32-39] vs BK `cellSamplingTemp2`[32-47]<br>40-47: Origin `cellSamplingTemp4`[40-47] vs BK `cellSamplingTemp2`[32-47]<br>48-55: Origin `cellSamplingTemp5`[48-55] vs BK `cellSamplingTemp3`[48-63] |

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 enum | 0 | - |
| OhmioLibraries_BK에만 있는 enum | 0 | - |
| 공통 enum entry 차이 | 0 | - |

## Function 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 function | 2 | `AirConJJK161StatusMsg_FromCan`, `AirConJJK161StatusMsg_ToCan` |
| OhmioLibraries_BK에만 있는 function | 0 | - |
| 공통 function 형태/구현 차이 | 58 | `AVASReqMsg_FromCan`, `AVASReqMsg_ToCan`, `AVASStatusMsg_FromCan`, `AVASStatusMsg_ToCan`, `AirConReqMsg_FromCan`, `AirConReqMsg_ToCan`, `AirConStatusMsg_FromCan`, `AirConStatusMsg_ToCan`, `BMS2ChargerReqMsg_FromCan`, `BMS2ChargerReqMsg_ToCan`, `BMSStatusMsg12_FromCan`, `BMSStatusMsg12_ToCan`, `BMSStatusMsg2_FromCan`, `BMSStatusMsg2_ToCan`, `BMSStatusMsg3_FromCan`, `BMSStatusMsg3_ToCan`, `BMSStatusMsg4_FromCan`, `BMSStatusMsg4_ToCan`, `BMSStatusMsg5_FromCan`, `BMSStatusMsg5_ToCan`, `BMSStatusMsg6_FromCan`, `BMSStatusMsg6_ToCan`, `BMSStatusMsg7_FromCan`, `BMSStatusMsg7_ToCan`, `BMSStatusMsg8_FromCan`, `BMSStatusMsg8_ToCan`, `BmsLotteChargeVehicle_FromCan`, `BmsLotteChargeVehicle_ToCan`, `BmsLotteChargerInfo_FromCan`, `BmsLotteChargerInfo_ToCan`, `BmsLotteDrive1_FromCan`, `BmsLotteDrive1_ToCan`, `BmsLotteDrive2_FromCan`, `BmsLotteDrive2_ToCan`, `BmsLotteDrive3_FromCan`, `BmsLotteDrive3_ToCan`, `BmsLotteLandmark6_FromCan`, `BmsLotteLandmark6_ToCan`, `BmsLotteLandmark7_FromCan`, `BmsLotteLandmark7_ToCan`, `BmsLotteLandmark8_FromCan`, `BmsLotteLandmark8_ToCan`, `BmsLotteTotalChangeValue_FromCan`, `BmsLotteTotalChangeValue_ToCan`, `ChargerStatusMsg_FromCan`, `ChargerStatusMsg_ToCan`, `DTGSpeedRpmMsg_FromCan`, `DTGSpeedRpmMsg_ToCan`, `DoorStatusMsg_FromCan`, `DoorStatusMsg_ToCan`, `Foot1Status_FromCan`, `Foot1Status_ToCan`, `Foot2Status_FromCan`, `Foot2Status_ToCan`, `StepStatusMsg_FromCan`, `StepStatusMsg_ToCan`, `WiperMsg_FromCan`, `WiperMsg_ToCan` |

### 공통 function 차이 상세

| Function | Origin_36_merge | OhmioLibraries_BK | 차이 |
| --- | --- | --- | --- |
| `AVASReqMsg_FromCan` | declared; `void AVASReqMsg_FromCan(AVASReqMsg_t * msg)` | static defined; `void AVASReqMsg_FromCan(AVASReqMsg_t * msg)` | static, defined |
| `AVASReqMsg_ToCan` | declared; `void AVASReqMsg_ToCan(AVASReqMsg_t * msg)` | static defined; `void AVASReqMsg_ToCan(AVASReqMsg_t * msg)` | static, defined |
| `AVASStatusMsg_FromCan` | declared; `void AVASStatusMsg_FromCan(AVASStatusMsg_t * msg)` | static defined; `void AVASStatusMsg_FromCan(AVASStatusMsg_t * msg)` | static, defined |
| `AVASStatusMsg_ToCan` | declared; `void AVASStatusMsg_ToCan(AVASStatusMsg_t * msg)` | static defined; `void AVASStatusMsg_ToCan(AVASStatusMsg_t * msg)` | static, defined |
| `AirConReqMsg_FromCan` | declared; `void AirConReqMsg_FromCan(AirConReqMsg_t * msg)` | static defined; `void AirConReqMsg_FromCan(AirConReqMsg_t * msg)` | static, defined |
| `AirConReqMsg_ToCan` | declared; `void AirConReqMsg_ToCan(AirConReqMsg_t * msg)` | static defined; `void AirConReqMsg_ToCan(AirConReqMsg_t * msg)` | static, defined |
| `AirConStatusMsg_FromCan` | declared; `void AirConStatusMsg_FromCan(AirConStatusMsg_t * msg)` | static defined; `void AirConStatusMsg_FromCan(AirConStatusMsg_t * msg)` | static, defined |
| `AirConStatusMsg_ToCan` | declared; `void AirConStatusMsg_ToCan(AirConStatusMsg_t * msg)` | static defined; `void AirConStatusMsg_ToCan(AirConStatusMsg_t * msg)` | static, defined |
| `BMS2ChargerReqMsg_FromCan` | declared; `void BMS2ChargerReqMsg_FromCan(BMS2ChargerReqMsg_t * msg)` | static defined; `void BMS2ChargerReqMsg_FromCan(BMS2ChargerReqMsg_t * msg)` | static, defined |
| `BMS2ChargerReqMsg_ToCan` | declared; `void BMS2ChargerReqMsg_ToCan(BMS2ChargerReqMsg_t * msg)` | static defined; `void BMS2ChargerReqMsg_ToCan(BMS2ChargerReqMsg_t * msg)` | static, defined |
| `BMSStatusMsg12_FromCan` | declared; `void BMSStatusMsg12_FromCan(BMSStatusMsg12_t * msg)` | static defined; `void BMSStatusMsg12_FromCan(BMSStatusMsg12_t * msg)` | static, defined |
| `BMSStatusMsg12_ToCan` | declared; `void BMSStatusMsg12_ToCan(BMSStatusMsg12_t * msg)` | static defined; `void BMSStatusMsg12_ToCan(BMSStatusMsg12_t * msg)` | static, defined |
| `BMSStatusMsg2_FromCan` | declared; `void BMSStatusMsg2_FromCan(BMSStatusMsg2_t * msg)` | static defined; `void BMSStatusMsg2_FromCan(BMSStatusMsg2_t * msg)` | static, defined |
| `BMSStatusMsg2_ToCan` | declared; `void BMSStatusMsg2_ToCan(BMSStatusMsg2_t * msg)` | static defined; `void BMSStatusMsg2_ToCan(BMSStatusMsg2_t * msg)` | static, defined |
| `BMSStatusMsg3_FromCan` | declared; `void BMSStatusMsg3_FromCan(BMSStatusMsg3_t * msg)` | static defined; `void BMSStatusMsg3_FromCan(BMSStatusMsg3_t * msg)` | static, defined |
| `BMSStatusMsg3_ToCan` | declared; `void BMSStatusMsg3_ToCan(BMSStatusMsg3_t * msg)` | static defined; `void BMSStatusMsg3_ToCan(BMSStatusMsg3_t * msg)` | static, defined |
| `BMSStatusMsg4_FromCan` | declared; `void BMSStatusMsg4_FromCan(BMSStatusMsg4_t * msg)` | static defined; `void BMSStatusMsg4_FromCan(BMSStatusMsg4_t * msg)` | static, defined |
| `BMSStatusMsg4_ToCan` | declared; `void BMSStatusMsg4_ToCan(BMSStatusMsg4_t * msg)` | static defined; `void BMSStatusMsg4_ToCan(BMSStatusMsg4_t * msg)` | static, defined |
| `BMSStatusMsg5_FromCan` | declared; `void BMSStatusMsg5_FromCan(BMSStatusMsg5_t * msg)` | static defined; `void BMSStatusMsg5_FromCan(BMSStatusMsg5_t * msg)` | static, defined |
| `BMSStatusMsg5_ToCan` | declared; `void BMSStatusMsg5_ToCan(BMSStatusMsg5_t * msg)` | static defined; `void BMSStatusMsg5_ToCan(BMSStatusMsg5_t * msg)` | static, defined |
| `BMSStatusMsg6_FromCan` | declared; `void BMSStatusMsg6_FromCan(BMSStatusMsg6_t * msg)` | static defined; `void BMSStatusMsg6_FromCan(BMSStatusMsg6_t * msg)` | static, defined |
| `BMSStatusMsg6_ToCan` | declared; `void BMSStatusMsg6_ToCan(BMSStatusMsg6_t * msg)` | static defined; `void BMSStatusMsg6_ToCan(BMSStatusMsg6_t * msg)` | static, defined |
| `BMSStatusMsg7_FromCan` | declared; `void BMSStatusMsg7_FromCan(BMSStatusMsg7_t * msg)` | static defined; `void BMSStatusMsg7_FromCan(BMSStatusMsg7_t * msg)` | static, defined |
| `BMSStatusMsg7_ToCan` | declared; `void BMSStatusMsg7_ToCan(BMSStatusMsg7_t * msg)` | static defined; `void BMSStatusMsg7_ToCan(BMSStatusMsg7_t * msg)` | static, defined |
| `BMSStatusMsg8_FromCan` | declared; `void BMSStatusMsg8_FromCan(BMSStatusMsg8_t * msg)` | static defined; `void BMSStatusMsg8_FromCan(BMSStatusMsg8_t * msg)` | static, defined |
| `BMSStatusMsg8_ToCan` | declared; `void BMSStatusMsg8_ToCan(BMSStatusMsg8_t * msg)` | static defined; `void BMSStatusMsg8_ToCan(BMSStatusMsg8_t * msg)` | static, defined |
| `BmsLotteChargeVehicle_FromCan` | declared; `void BmsLotteChargeVehicle_FromCan(BmsLotteChargeVehicle_t * msg)` | static defined; `void BmsLotteChargeVehicle_FromCan(BmsLotteChargeVehicle_t * msg)` | static, defined |
| `BmsLotteChargeVehicle_ToCan` | declared; `void BmsLotteChargeVehicle_ToCan(BmsLotteChargeVehicle_t * msg)` | static defined; `void BmsLotteChargeVehicle_ToCan(BmsLotteChargeVehicle_t * msg)` | static, defined |
| `BmsLotteChargerInfo_FromCan` | declared; `void BmsLotteChargerInfo_FromCan(BmsLotteChargerInfo_t * msg)` | static defined; `void BmsLotteChargerInfo_FromCan(BmsLotteChargerInfo_t * msg)` | static, defined |
| `BmsLotteChargerInfo_ToCan` | declared; `void BmsLotteChargerInfo_ToCan(BmsLotteChargerInfo_t * msg)` | static defined; `void BmsLotteChargerInfo_ToCan(BmsLotteChargerInfo_t * msg)` | static, defined |
| `BmsLotteDrive1_FromCan` | declared; `void BmsLotteDrive1_FromCan(BmsLotteDrive1_t * msg)` | static defined; `void BmsLotteDrive1_FromCan(BmsLotteDrive1_t * msg)` | static, defined |
| `BmsLotteDrive1_ToCan` | declared; `void BmsLotteDrive1_ToCan(BmsLotteDrive1_t * msg)` | static defined; `void BmsLotteDrive1_ToCan(BmsLotteDrive1_t * msg)` | static, defined |
| `BmsLotteDrive2_FromCan` | declared; `void BmsLotteDrive2_FromCan(BmsLotteDrive2_t * msg)` | static defined; `void BmsLotteDrive2_FromCan(BmsLotteDrive2_t * msg)` | static, defined |
| `BmsLotteDrive2_ToCan` | declared; `void BmsLotteDrive2_ToCan(BmsLotteDrive2_t * msg)` | static defined; `void BmsLotteDrive2_ToCan(BmsLotteDrive2_t * msg)` | static, defined |
| `BmsLotteDrive3_FromCan` | declared; `void BmsLotteDrive3_FromCan(BmsLotteDrive3_t * msg)` | static defined; `void BmsLotteDrive3_FromCan(BmsLotteDrive3_t * msg)` | static, defined |
| `BmsLotteDrive3_ToCan` | declared; `void BmsLotteDrive3_ToCan(BmsLotteDrive3_t * msg)` | static defined; `void BmsLotteDrive3_ToCan(BmsLotteDrive3_t * msg)` | static, defined |
| `BmsLotteLandmark6_FromCan` | declared; `void BmsLotteLandmark6_FromCan(BmsLotteLandmark6_t * msg)` | static defined; `void BmsLotteLandmark6_FromCan(BmsLotteLandmark6_t * msg)` | static, defined |
| `BmsLotteLandmark6_ToCan` | declared; `void BmsLotteLandmark6_ToCan(BmsLotteLandmark6_t * msg)` | static defined; `void BmsLotteLandmark6_ToCan(BmsLotteLandmark6_t * msg)` | static, defined |
| `BmsLotteLandmark7_FromCan` | declared; `void BmsLotteLandmark7_FromCan(BmsLotteLandmark7_t * msg)` | static defined; `void BmsLotteLandmark7_FromCan(BmsLotteLandmark7_t * msg)` | static, defined |
| `BmsLotteLandmark7_ToCan` | declared; `void BmsLotteLandmark7_ToCan(BmsLotteLandmark7_t * msg)` | static defined; `void BmsLotteLandmark7_ToCan(BmsLotteLandmark7_t * msg)` | static, defined |
| `BmsLotteLandmark8_FromCan` | declared; `void BmsLotteLandmark8_FromCan(BmsLotteLandmark8_t * msg)` | static defined; `void BmsLotteLandmark8_FromCan(BmsLotteLandmark8_t * msg)` | static, defined |
| `BmsLotteLandmark8_ToCan` | declared; `void BmsLotteLandmark8_ToCan(BmsLotteLandmark8_t * msg)` | static defined; `void BmsLotteLandmark8_ToCan(BmsLotteLandmark8_t * msg)` | static, defined |
| `BmsLotteTotalChangeValue_FromCan` | declared; `void BmsLotteTotalChangeValue_FromCan(BmsLotteTotalChangeValue_t * msg)` | static defined; `void BmsLotteTotalChangeValue_FromCan(BmsLotteTotalChangeValue_t * msg)` | static, defined |
| `BmsLotteTotalChangeValue_ToCan` | declared; `void BmsLotteTotalChangeValue_ToCan(BmsLotteTotalChangeValue_t * msg)` | static defined; `void BmsLotteTotalChangeValue_ToCan(BmsLotteTotalChangeValue_t * msg)` | static, defined |
| `ChargerStatusMsg_FromCan` | declared; `void ChargerStatusMsg_FromCan(ChargerStatusMsg_t * msg)` | static defined; `void ChargerStatusMsg_FromCan(ChargerStatusMsg_t * msg)` | static, defined |
| `ChargerStatusMsg_ToCan` | declared; `void ChargerStatusMsg_ToCan(ChargerStatusMsg_t * msg)` | static defined; `void ChargerStatusMsg_ToCan(ChargerStatusMsg_t * msg)` | static, defined |
| `DTGSpeedRpmMsg_FromCan` | declared; `void DTGSpeedRpmMsg_FromCan(DTGSpeedRpmMsg_t * msg)` | static defined; `void DTGSpeedRpmMsg_FromCan(DTGSpeedRpmMsg_t * msg)` | static, defined |
| `DTGSpeedRpmMsg_ToCan` | declared; `void DTGSpeedRpmMsg_ToCan(DTGSpeedRpmMsg_t * msg)` | static defined; `void DTGSpeedRpmMsg_ToCan(DTGSpeedRpmMsg_t * msg)` | static, defined |
| `DoorStatusMsg_FromCan` | declared; `void DoorStatusMsg_FromCan(DoorStatusMsg_t * msg)` | static defined; `void DoorStatusMsg_FromCan(DoorStatusMsg_t * msg)` | static, defined |
| `DoorStatusMsg_ToCan` | declared; `void DoorStatusMsg_ToCan(DoorStatusMsg_t * msg)` | static defined; `void DoorStatusMsg_ToCan(DoorStatusMsg_t * msg)` | static, defined |
| `Foot1Status_FromCan` | declared; `void Foot1Status_FromCan(Foot1Status_t * msg)` | static defined; `void Foot1Status_FromCan(Foot1Status_t * msg)` | static, defined |
| `Foot1Status_ToCan` | declared; `void Foot1Status_ToCan(Foot1Status_t * msg)` | static defined; `void Foot1Status_ToCan(Foot1Status_t * msg)` | static, defined |
| `Foot2Status_FromCan` | declared; `void Foot2Status_FromCan(Foot2Status_t * msg)` | static defined; `void Foot2Status_FromCan(Foot2Status_t * msg)` | static, defined |
| `Foot2Status_ToCan` | declared; `void Foot2Status_ToCan(Foot2Status_t * msg)` | static defined; `void Foot2Status_ToCan(Foot2Status_t * msg)` | static, defined |
| `StepStatusMsg_FromCan` | declared; `void StepStatusMsg_FromCan(StepStatusMsg_t * msg)` | static defined; `void StepStatusMsg_FromCan(StepStatusMsg_t * msg)` | static, defined |
| `StepStatusMsg_ToCan` | declared; `void StepStatusMsg_ToCan(StepStatusMsg_t * msg)` | static defined; `void StepStatusMsg_ToCan(StepStatusMsg_t * msg)` | static, defined |
| `WiperMsg_FromCan` | declared; `void WiperMsg_FromCan(WiperMsg_t * msg)` | static defined; `void WiperMsg_FromCan(WiperMsg_t * msg)` | static, defined |
| `WiperMsg_ToCan` | declared; `void WiperMsg_ToCan(WiperMsg_t * msg)` | static defined; `void WiperMsg_ToCan(WiperMsg_t * msg)` | static, defined |

