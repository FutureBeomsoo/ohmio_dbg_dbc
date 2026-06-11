# 2-4_additionalDbcCan_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/additionalDbcCan.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/additionalDbcCan.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/additionalDbcCan_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/additionalDbcCan.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| Origin-only struct | `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` |
| BK-only struct | 없음 |
| Origin-only function | `DeviationReqMsg_*`, `DynamicTrackValidationMsg_*`, `FusionFrontLongitude_*`, `StopReqMsg_*`, `WayPoint*` |
| 공통 function 차이 | `Motor3ReqMsg_*`, `Motor3Status1_*` |
| BK-only define | `RPM2RadSec` |
| include 차이 | Origin에 `<stdint.h>`, `<math.h>`, `"ConversionHelper.h"` 있음 |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. Origin-only struct/function은 유지한다.
3. BK의 `RPM2RadSec`는 BK의 `Motor3*` 함수 정의가 참조하므로 반영 후보로 검토한다.
4. `Motor3ReqMsg_*`, `Motor3Status1_*`는 struct 충돌이 없으면 BK의 함수 정의를 활성 반영한다.
5. include는 함수 구현에 필요한 `<math.h>`, `"ConversionHelper.h"`를 유지한다.
6. BK 함수 반영 시 `static` 여부가 header 사용 방식에 영향을 줄 수 있으므로 작업내용과 점검사항에 기록한다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_additionalDbcCan_병합_작업내용.md` | `additionalDbcCan.h` 병합 내용 |
| `2-4_additionalDbcCan_병합_점검_필요사항.md` | `RPM2RadSec`, `static` 함수 정책 등 사용자 확인 항목 |
| `2-4_additionalDbcCan_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_additionalDbcCan_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.
