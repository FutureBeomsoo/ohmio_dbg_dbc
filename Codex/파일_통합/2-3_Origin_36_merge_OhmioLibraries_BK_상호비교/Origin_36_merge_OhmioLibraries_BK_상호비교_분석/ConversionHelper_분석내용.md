# ConversionHelper.h 상호 비교 분석

## 비교 대상

- 비교 A: `Origin_36_merge` - `Codex/파일_통합/2-1_Origin_36_병합/canbus/ConversionHelper.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/ConversionHelper.h`
- 파일 동일 여부: 다름

## 요약
| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 93 | 92 |
| SHA256 | 7340b1a5939b | 4e5d4dab8e6c |
| Include | 0 | 1 |
| Define | 0 | 0 |
| Struct/Message | 0 | 0 |
| Enum | 0 | 0 |
| CAN_ID | 0 | 0 |
| Function | 0 | 0 |
| Unified diff | +6 | -5 |

## 전처리/Define 비교

| Include | 구분 | 비고 |
| --- | --- | --- |
| <assert.h> | OhmioLibraries_BK에만 있음 |  |

- define 차이 없음.

## Message/Struct 비교

- struct/message 차이 없음.

## CAN_ID 비교

- CAN_ID 차이 없음.

## Enum 비교

- enum 차이 없음.

## 함수 선언/정의 비교

- 함수 선언/정의 차이 없음.

## 변환 동작 차이

| 항목 | Origin_36_merge | OhmioLibraries_BK |
| --- | --- | --- |
| `<assert.h>` include | 없음 | 있음 |
| `RoundUnsigned` 음수/0 처리 | `value <= 0`이면 `0` 반환 | `assert(value >= 0)` |
| `RoundLimitUnsigned` 음수 처리 | `RoundUnsigned`의 0 clamp 동작을 따름 | 함수 내부에서 `assert(value >= 0)` 수행 |

## 점검 필요 판단

| 판단 | 내용 |
| --- | --- |
| 변환 정책 확인 필요 | BK는 음수 입력을 assert로 막고, Origin_36_merge는 0으로 clamp한다. 변환 정책을 어느 쪽으로 유지할지 확인 필요 |
