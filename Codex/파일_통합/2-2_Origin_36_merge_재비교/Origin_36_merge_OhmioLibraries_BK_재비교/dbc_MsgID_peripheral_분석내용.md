# dbc_MsgID_peripheral.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_MsgID_peripheral.h`
- 우측: `OhmioLibraries_BK/include/canbus/dbc_MsgID_peripheral.h`
- 비교 목적: BK 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - peripheral DBC 갱신 차이

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| version/hash | 통합본 유지 | BK `MAJOR 1`, `MINOR 12`, `BUILD 0x0E350456` 대비 통합본은 `MAJOR 2`, `MINOR 3`, `BUILD 0xD1134632`다. |
| CAN_ID_BMS_STATUS8 | 레이아웃 변경 | 통합본은 6개의 8-bit temperature field 설명으로 변경되어 있다. |
| CAN_ID_AIR_CON_REQ | 통합본 확장 | 통합본은 `roofLight`, `JJK161Level` 설명을 포함한다. |
| AirCon 추가 ID | 통합본 추가 | `CAN_ID_AIR_CON_VERSION`, `CAN_ID_AIR_CON_JJ_K161STATUS`가 통합본에만 있다. |
| BMS charging current ID | 통합본 추가 | `CAN_ID_BMS_CHARGING_CURRENT`, `CAN_ID_BMS_CHARGING_CURRENT_REPLY`가 통합본에만 있다. |
| CAN_ID_RECOVERY | 통합본 추가 | 통합본에만 있다. |
| AIRCON_ERROR / BMS_CHARGE_CURRENT enum | 통합본 추가 | 통합본에만 해당 enum이 있다. |

## 재비교 판단

- BK 대비 차이는 기존 `2-1` 사용자 확인 완료 항목과 별개로 검토해야 한다.
- 이번 `2-2` 작업에서는 분석만 수행하며 통합본 코드는 수정하지 않는다.
