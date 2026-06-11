# 2-4_dbc_CAN_병합 작업내용

## 작업 범위

- 대상 header: `dbc_CAN.h`
- Origin_36_merge: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- OhmioLibraries_BK: `OhmioLibraries_BK/include/canbus/dbc_CAN.h`
- 결과 파일: `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/dbc_CAN.h`
- 원본 파일은 수정하지 않았다.

## 적용 내용

- Origin_36_merge를 base로 유지했다.
- 충돌 없는 BK-only struct는 없어서 활성 추가하지 않았다.
- 공통 BK function 정의를 사용자 의견에 따라 활성 반영했다: 116개
- `IMUMag_ToCan()`의 BK `status` assert는 Origin `z` bit field와 overlap되어 주석 처리하고 사용자 점검 항목으로 분리했다.
- 사용자 지시에 따라 `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg`는 `dbc_CAN.h`에 중복 추가하지 않았다.

## 파일 정보

| 항목 | Origin_36_merge | 2-4 결과 |
| --- | ---: | ---: |
| line | 3662 | 4342 |
| SHA256 | `acde60291555` | `b8104264fded` |
