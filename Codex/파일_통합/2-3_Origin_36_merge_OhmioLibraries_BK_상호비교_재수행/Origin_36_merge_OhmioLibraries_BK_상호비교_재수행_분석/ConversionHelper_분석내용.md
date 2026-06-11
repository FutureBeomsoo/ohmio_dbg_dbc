# ConversionHelper.h 상호 비교 재수행 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/ConversionHelper.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/ConversionHelper.h`
- 파일 동일 여부: 다름

## 요약

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 92 | 91 |
| SHA256 | 7340b1a5939b | 4e5d4dab8e6c |
| Include | 0 | 1 |
| Define | 0 | 0 |
| Struct/Message | 0 | 0 |
| Enum | 0 | 0 |
| CAN_ID | 0 | 0 |
| Function | 6 | 6 |
| Unified diff | -6 | +5 |

## 전처리/Define 비교

| Include | 구분 |
| --- | --- |
| `<assert.h>` | OhmioLibraries_BK에만 있음 |

- define 차이 없음.

## Message/Struct 비교

| 구분 | 개수 | 항목 |
| --- | ---: | --- |
| Origin_36_merge에만 있는 struct | 0 | - |
| OhmioLibraries_BK에만 있는 struct | 0 | - |
| 공통 struct 중 layout/comment 차이 | 0 | - |

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
| Origin_36_merge에만 있는 function | 0 | - |
| OhmioLibraries_BK에만 있는 function | 0 | - |
| 공통 function 형태/구현 차이 | 2 | `RoundLimitUnsigned`, `RoundUnsigned` |

### 공통 function 차이 상세

| Function | Origin_36_merge | OhmioLibraries_BK | 차이 |
| --- | --- | --- | --- |
| `RoundLimitUnsigned` | static inline defined; `uint64_t RoundLimitUnsigned(double value, double quantization, int numBits)` | static inline defined; `uint64_t RoundLimitUnsigned(double value, double quantization, int numBits)` | body |
| `RoundUnsigned` | static inline defined; `uint64_t RoundUnsigned(double value, double quantization)` | static inline defined; `uint64_t RoundUnsigned(double value, double quantization)` | body |

