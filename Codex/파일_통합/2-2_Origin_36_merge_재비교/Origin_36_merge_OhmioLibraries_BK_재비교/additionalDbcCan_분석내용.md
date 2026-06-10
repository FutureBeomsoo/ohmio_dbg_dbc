# additionalDbcCan.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/additionalDbcCan.h`
- 우측: `OhmioLibraries_BK/include/canbus/additionalDbcCan.h`
- 비교 목적: BK 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - BK 대비 구조 차이 큼

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| include | 통합본 추가 | 통합본은 `<stdint.h>`, `<math.h>`, `ConversionHelper.h` include를 가진다. |
| Motor3Status1 / Motor3ReqMsg 변환 함수 | 구현 방식 차이 | BK는 `static` 함수 본문을 header에 포함하지만, 통합본은 함수 선언만 둔다. |
| WayPoint split helper | 통합본 추가 | `WayPointFromParts`, `WayPointToLow`, `WayPointToHigh` 선언이 통합본에만 있다. |
| DynamicTrackValidationMsg / StopReqMsg / DeviationReqMsg | 통합본 추가 | 분할 waypoint 구조와 변환 함수 선언이 통합본에만 있다. |
| FusionFrontLongitude_t | 통합본 추가 | 통합본에만 구조체와 변환 함수 선언이 있다. |
| RPM2RadSec / inline 변환 본문 | BK에만 있음 | BK의 변환 구현 본문과 `RPM2RadSec` define은 통합본에 없다. 구현 위치 정책 확인이 필요하다. |

## 재비교 판단

- BK 대비 차이는 기존 `2-1` 사용자 확인 완료 항목과 별개로 검토해야 한다.
- 이번 `2-2` 작업에서는 분석만 수행하며 통합본 코드는 수정하지 않는다.
