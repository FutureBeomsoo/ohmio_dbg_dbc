# dbc_CAN_peripheral.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN_peripheral.h`
- 우측: `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h`
- 비교 목적: BK 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - BK 대비 구조 차이 큼

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| 변환 함수 구현 방식 | 구현 방식 차이 | BK는 다수 `_ToCan`/`_FromCan`을 `static` 본문으로 포함하지만, 통합본은 선언만 둔다. |
| AirConReqMsg | 통합본 확장 | 통합본에는 `roofLight`, `JJK161Level` bitfield가 추가되어 있다. |
| BMSStatusMsg8 | 레이아웃 변경 | BK는 3개의 16-bit temperature field, 통합본은 6개의 8-bit temperature field 구조다. |
| AirConVersionMsg / AirConJJK161StatusMsg | 통합본 추가 | 통합본에만 AirCon version/JJK161 status message가 있다. |
| Recovery / BMSChargingCurrent / BMSChargingCurrentReply | 통합본 추가 | 통합본에만 해당 message 구조체가 있다. |
| include/assert 정책 | 구현 방식 차이 | BK는 `<math.h>`, `<assert.h>`, `ConversionHelper.h`를 include하지만 통합본은 해당 include를 제거하고 선언 중심 header로 구성되어 있다. |

## 재비교 판단

- BK 대비 차이는 기존 `2-1` 사용자 확인 완료 항목과 별개로 검토해야 한다.
- 이번 `2-2` 작업에서는 분석만 수행하며 통합본 코드는 수정하지 않는다.
