# 2-4_dbc_CAN_peripheral_병합 작업내용

## 작업 범위

- 대상 header: `dbc_CAN_peripheral.h`
- Origin_36_merge: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN_peripheral.h`
- OhmioLibraries_BK: `OhmioLibraries_BK/include/canbus/dbc_CAN_peripheral.h`
- 결과 파일: `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_CAN_peripheral.h`
- 원본 파일은 수정하지 않았다.

## 적용 내용

- Origin_36_merge를 base로 유지했다.
- BK의 공통 `ToCan`/`FromCan` 함수 정의를 활성 반영했다: 58개

## 파일 정보

| 항목 | Origin_36_merge | 2-4 결과 |
| --- | ---: | ---: |
| line | 1211 | 1693 |
| SHA256 | `2a0e3537d5ff` | `ae550b32d614` |
