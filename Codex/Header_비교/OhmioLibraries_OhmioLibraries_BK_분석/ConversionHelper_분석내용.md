# ConversionHelper.h 비교 분석

- 비교 A: `OhmioLibraries` - `OhmioLibraries/include/canbus/ConversionHelper.h`
- 비교 B: `OhmioLibraries_BK` - `OhmioLibraries_BK/include/canbus/ConversionHelper.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목 | OhmioLibraries | OhmioLibraries_BK |
| --- | --- | --- |
| Line | 92 | 91 |
| SHA256 | 7340b1a5939b | 4e5d4dab8e6c |
| Struct | 0 | 0 |
| Enum | 0 | 0 |
| CAN_ID | 0 | 0 |
| Function | 6 | 6 |
| Unified diff | -6 | +5 |

Diff hunk 위치:
- `@@ -1,11 +1,13 @@`
- `@@ -47,11 +49,7 @@`
- `@@ -64,6 +62,7 @@`

### 전처리/Include 비교
Include 차이:
| Include | OhmioLibraries | OhmioLibraries_BK |
| --- | --- | --- |
| <assert.h> |  | OhmioLibraries_BK |

### CAN ID enum 비교
CAN_ID enum 항목이 없습니다.

### 일반 enum 비교
일반 enum 차이는 없습니다.

### Struct/Message 비교
양쪽 struct 목록은 동일합니다.
공통 struct의 Signal layout 차이는 없습니다.

### 함수 선언/정의 비교
동일 inline/static 함수 body 변경:
| Function | OhmioLibraries | OhmioLibraries_BK |
| --- | --- | --- |
| RoundLimitUnsigned | definition body hash 변경 | definition body hash 변경 |
| RoundUnsigned | definition body hash 변경 | definition body hash 변경 |

## 사용자 점검 후보
- RoundLimitUnsigned 함수 body 변경
- RoundUnsigned 함수 body 변경
