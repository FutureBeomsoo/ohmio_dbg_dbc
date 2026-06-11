# additionalDbcCan.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/additionalDbcCan.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/additionalDbcCan.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 208 | 150 |
| SHA256 | b1552b9269e3 | d2f253f8da97 |
| Include | 3 | 0 |
| Define | 0 | 1 |
| Struct/Message | 6 | 2 |
| Enum | 1 | 1 |
| CAN_ID | 0 | 0 |
| Function | 15 | 4 |
| Unified diff | -118 | +60 |

## 전처리/Define 비교

| Include | 구분 |
| --- | --- |
| `"ConversionHelper.h"` | Origin_36_merge에만 있음 |
| `<math.h>` | Origin_36_merge에만 있음 |
| `<stdint.h>` | Origin_36_merge에만 있음 |

| Define | Origin_36_merge | OhmioLibraries_BK | 판정 |
| --- | --- | --- | --- |
| `RPM2RadSec` |  | `(3.14159265358979323846 / 30)` | OhmioLibraries_BK에만 있음 |

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 4 | `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` |
| OhmioLibraries_BK에만 있는 struct | 0 | - |
| 공통 struct 중 layout/comment 차이 | 0 | - |

### Origin_36_merge에만 있는 struct

| Struct | Line | Message ID comment | Total bits |
| --- | ---: | --- | ---: |
| `DeviationReqMsg` | 160 | 0x2C5 DeviationReqMsg | 41 |
| `DynamicTrackValidationMsg` | 110 | 0x300 DynamicTrackValidationMsg | 59 |
| `FusionFrontLongitude` | 188 | 0x21A FusionFrontLongitude | 64 |
| `StopReqMsg` | 135 | 0x326 StopReqMsg | 32 |

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
| Origin_36_merge에만 있는 function | 11 | `DeviationReqMsg_FromCan`, `DeviationReqMsg_ToCan`, `DynamicTrackValidationMsg_FromCan`, `DynamicTrackValidationMsg_ToCan`, `FusionFrontLongitude_FromCan`, `FusionFrontLongitude_ToCan`, `StopReqMsg_FromCan`, `StopReqMsg_ToCan`, `WayPointFromParts`, `WayPointToHigh`, `WayPointToLow` |
| OhmioLibraries_BK에만 있는 function | 0 | - |
| 공통 function 형태/구현 차이 | 4 | `Motor3ReqMsg_FromCan`, `Motor3ReqMsg_ToCan`, `Motor3Status1_FromCan`, `Motor3Status1_ToCan` |

### 공통 function 차이 상세

| Function | Origin_36_merge | OhmioLibraries_BK | 차이 |
| --- | --- | --- | --- |
| `Motor3ReqMsg_FromCan` | declared; `void Motor3ReqMsg_FromCan(Motor3ReqMsg_t * msg)` | static defined; `void Motor3ReqMsg_FromCan(Motor3ReqMsg_t * msg)` | static, defined |
| `Motor3ReqMsg_ToCan` | declared; `void Motor3ReqMsg_ToCan(Motor3ReqMsg_t * msg)` | static defined; `void Motor3ReqMsg_ToCan(Motor3ReqMsg_t * msg)` | static, defined |
| `Motor3Status1_FromCan` | declared; `void Motor3Status1_FromCan(Motor3Status1_t * msg)` | static defined; `void Motor3Status1_FromCan(Motor3Status1_t * msg)` | static, defined |
| `Motor3Status1_ToCan` | declared; `void Motor3Status1_ToCan(Motor3Status1_t * msg)` | static defined; `void Motor3Status1_ToCan(Motor3Status1_t * msg)` | static, defined |

