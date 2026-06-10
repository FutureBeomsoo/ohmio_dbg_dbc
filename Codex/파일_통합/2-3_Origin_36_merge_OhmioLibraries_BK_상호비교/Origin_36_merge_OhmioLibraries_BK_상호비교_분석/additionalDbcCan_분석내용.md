# additionalDbcCan.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/additionalDbcCan.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/additionalDbcCan.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 209 | 151 |
| SHA256 | b1552b9269e3 | d2f253f8da97 |
| Include | 3 | 0 |
| Define | 0 | 1 |
| Struct/Message | 6 | 2 |
| Enum | 1 | 1 |
| CAN_ID | 0 | 0 |
| Function | 15 | 4 |
| Unified diff | +118 | -60 |

## 전처리/Define 비교

| Include | 구분 | 비고 |
| --- | --- | --- |
| "ConversionHelper.h" | Origin_36_merge에만 있음 |  |
| <math.h> | Origin_36_merge에만 있음 |  |
| <stdint.h> | Origin_36_merge에만 있음 |  |

| Define | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| RPM2RadSec |  | (3.14159265358979323846 / 30) // rad per sec = RMP * 2pi / 60 |

## Message/Struct 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 struct | `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` | 4 |

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

- enum 차이 없음.

## 함수 선언/정의 비교

| 구분 | 항목 | 개수 |
| --- | --- | --- |
| Origin_36_merge에만 있는 함수 | `DeviationReqMsg_FromCan`, `DeviationReqMsg_ToCan`, `DynamicTrackValidationMsg_FromCan`, `DynamicTrackValidationMsg_ToCan`, `FusionFrontLongitude_FromCan`, `FusionFrontLongitude_ToCan`, `StopReqMsg_FromCan`, `StopReqMsg_ToCan`, `WayPointFromParts`, `WayPointToHigh`, `WayPointToLow` | 11 |
| 동일 함수의 선언/정의 형태 변경 | `Motor3ReqMsg_FromCan`, `Motor3ReqMsg_ToCan`, `Motor3Status1_FromCan`, `Motor3Status1_ToCan` | 4 |

| Function | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Motor3ReqMsg_FromCan | prototype | static definition |
| Motor3ReqMsg_ToCan | prototype | static definition |
| Motor3Status1_FromCan | prototype | static definition |
| Motor3Status1_ToCan | prototype | static definition |

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| 함수 구현 위치 정책 필요 | header 내부 static 구현과 prototype 중심 구조가 혼재함 |
