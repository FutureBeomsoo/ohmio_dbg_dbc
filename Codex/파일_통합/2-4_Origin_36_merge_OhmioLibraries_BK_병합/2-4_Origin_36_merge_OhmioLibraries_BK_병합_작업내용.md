# 2-4_Origin_36_merge_OhmioLibraries_BK_병합 작업내용

## 작업 범위

- `2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행` 결과를 참고하여 2-4 병합 산출물을 생성했다.
- 생성 시각: 2026-06-11T17:09:55+09:00
- 원본 `Origin_36_merge`와 `OhmioLibraries_BK`는 수정하지 않았다.

## 결과 파일 요약

| Header | Origin line | Result line | Origin SHA | Result SHA | 처리 |
| --- | ---: | ---: | --- | --- | --- |
| `additionalDbcCan.h` | 208 | 303 | `b1552b9269e3` | `63d3dc66705b` | 변경 |
| `ConversionHelper.h` | 92 | 92 | `7340b1a5939b` | `7340b1a5939b` | 동일 복사 |
| `dbc_CAN.h` | 3662 | 4342 | `acde60291555` | `b8104264fded` | 변경 |
| `dbc_CAN_peripheral.h` | 1211 | 1693 | `2a0e3537d5ff` | `ae550b32d614` | 변경 |
| `dbc_MsgID_main.h` | 917 | 923 | `4223f406ef5b` | `7ca4351bf740` | 변경 |
| `dbc_MsgID_peripheral.h` | 372 | 372 | `5377c208879f` | `5377c208879f` | 동일 복사 |
| `dbc_MsgID_security.h` | 8 | 8 | `d8897bab1dbd` | `d8897bab1dbd` | 동일 복사 |
| `Security_CAN.h` | 56 | 56 | `2c9c4e643024` | `2c9c4e643024` | 동일 복사 |

## 주요 처리

- `additionalDbcCan.h`: BK `Motor3*` 함수 및 사용자 지정 cross-file message 함수 정의를 활성 반영했다.
- `dbc_CAN.h`: CAN ID 충돌 없는 BK-only struct는 없어서 추가하지 않았고, 공통 BK function 정의를 활성 반영했다. `IMUMag_ToCan()`의 BK `status` assert는 Origin layout과 overlap되어 주석 처리했다.
- `dbc_CAN_peripheral.h`: BK function 정의를 활성 반영했다.
- `dbc_MsgID_main.h`: numeric ID 충돌 없는 BK-only CAN_ID를 추가했다.
- `ConversionHelper.h`, `dbc_MsgID_peripheral.h`는 Origin 정책을 유지했다.
- `Security_CAN.h`, `dbc_MsgID_security.h`는 동일 파일로 복사했다.
