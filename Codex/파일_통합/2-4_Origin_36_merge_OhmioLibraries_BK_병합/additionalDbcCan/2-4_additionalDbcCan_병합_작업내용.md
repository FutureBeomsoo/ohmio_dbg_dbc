# 2-4_additionalDbcCan_병합 작업내용

## 작업 범위

- 대상 header: `additionalDbcCan.h`
- Origin_36_merge: `Codex/파일_통합/2-1_Origin_36_병합/canbus/additionalDbcCan.h`
- OhmioLibraries_BK: `OhmioLibraries_BK/include/canbus/additionalDbcCan.h`
- 결과 파일: `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/additionalDbcCan.h`
- 원본 파일은 수정하지 않았다.

## 적용 내용

- BK `Motor3*` 함수 정의가 참조하는 `RPM2RadSec` define을 추가했다.
- BK `Motor3Status1_*`, `Motor3ReqMsg_*` 함수 정의를 활성 반영했다: `Motor3Status1_ToCan`, `Motor3Status1_FromCan`, `Motor3ReqMsg_ToCan`, `Motor3ReqMsg_FromCan`
- 사용자 의견에 따라 `DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg` 함수 정의를 `additionalDbcCan.h` 위치에 활성 반영했다.

## 파일 정보

| 항목 | Origin_36_merge | 2-4 결과 |
| --- | ---: | ---: |
| line | 208 | 303 |
| SHA256 | `b1552b9269e3` | `63d3dc66705b` |
