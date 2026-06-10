# additionalDbcCan.h 비교 분석

- 비교 A: `OhmioLibraries_36` - `OhmioLibraries_36/include/canbus/additionalDbcCan.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/additionalDbcCan.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목           | OhmioLibraries_36 | OhmioLibraries_BK |
| ------------ | ----------------- | ----------------- |
| Line         | 208               | 150               |
| SHA256       | b1552b9269e3      | d2f253f8da97      |
| Struct       | 6                 | 2                 |
| Enum         | 1                 | 1                 |
| CAN_ID       | 0                 | 0                 |
| Function     | 15                | 4                 |
| Unified diff | -118              | +60               |


Diff hunk 위치:
- `@@ -1,7 +1,4 @@`
- `@@ -34,14 +31,48 @@`
- `@@ -72,12 +103,34 @@`
- `@@ -95,114 +148,3 @@`

### 전처리/Include 비교
Include 차이:
| Include              | OhmioLibraries_36 | OhmioLibraries_BK |
| -------------------- | ----------------- | ----------------- |
| "ConversionHelper.h" | OhmioLibraries_36 |                   |
| <math.h>             | OhmioLibraries_36 |                   |
| <stdint.h>           | OhmioLibraries_36 |                   |

OhmioLibraries_BK에만 있는 macro:
| Macro      | Value                         |
| ---------- | ----------------------------- |
| RPM2RadSec | (3.14159265358979323846 / 30) |


### CAN ID enum 비교
CAN_ID enum 항목이 없습니다.

### 일반 enum 비교
일반 enum 차이는 없습니다.

### Struct/Message 비교
OhmioLibraries_36에만 있는 struct:
| Struct                      | message ID                      | bit 수 |
| --------------------------- | ------------------------------- | ----- |
| DeviationReqMsg_t           | 0x2C5 DeviationReqMsg           | 41    |
| DynamicTrackValidationMsg_t | 0x300 DynamicTrackValidationMsg | 59    |
| FusionFrontLongitude_t      | 0x21A FusionFrontLongitude      | 64    |
| StopReqMsg_t                | 0x326 StopReqMsg                | 32    |

공통 struct의 Signal layout 차이는 없습니다.

### 함수 선언/정의 비교
OhmioLibraries_36에만 있는 함수:
| Function                          | Kind      | Signature                                                                 |
| --------------------------------- | --------- | ------------------------------------------------------------------------- |
| DeviationReqMsg_FromCan           | prototype | void DeviationReqMsg_FromCan(DeviationReqMsg_t * msg)                     |
| DeviationReqMsg_ToCan             | prototype | void DeviationReqMsg_ToCan(DeviationReqMsg_t * msg)                       |
| DynamicTrackValidationMsg_FromCan | prototype | void DynamicTrackValidationMsg_FromCan(DynamicTrackValidationMsg_t * msg) |
| DynamicTrackValidationMsg_ToCan   | prototype | void DynamicTrackValidationMsg_ToCan(DynamicTrackValidationMsg_t * msg)   |
| FusionFrontLongitude_FromCan      | prototype | void FusionFrontLongitude_FromCan(FusionFrontLongitude_t * msg)           |
| FusionFrontLongitude_ToCan        | prototype | void FusionFrontLongitude_ToCan(FusionFrontLongitude_t * msg)             |
| StopReqMsg_FromCan                | prototype | void StopReqMsg_FromCan(StopReqMsg_t * msg)                               |
| StopReqMsg_ToCan                  | prototype | void StopReqMsg_ToCan(StopReqMsg_t * msg)                                 |
| WayPointFromParts                 | prototype | uint32_t WayPointFromParts(uint64_t low, uint64_t high)                   |
| WayPointToHigh                    | prototype | uint64_t WayPointToHigh(uint32_t wp)                                      |
| WayPointToLow                     | prototype | uint64_t WayPointToLow(uint32_t wp)                                       |

함수 선언/정의 형태 변경:
| Function              | OhmioLibraries_36 | OhmioLibraries_BK |
| --------------------- | ----------------- | ----------------- |
| Motor3ReqMsg_FromCan  | prototype         | static definition |
| Motor3ReqMsg_ToCan    | prototype         | static definition |
| Motor3Status1_FromCan | prototype         | static definition |
| Motor3Status1_ToCan   | prototype         | static definition |
