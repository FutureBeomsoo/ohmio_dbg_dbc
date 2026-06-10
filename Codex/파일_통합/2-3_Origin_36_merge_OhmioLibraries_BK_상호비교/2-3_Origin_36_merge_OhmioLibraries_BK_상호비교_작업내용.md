# 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교 작업내용

## 작업 범위

- `Origin_36_merge`와 `OhmioLibraries_BK`의 대상 header 8개를 상호 비교했다.
- `Origin_36_merge` 기준 경로: `Codex/파일_통합/2-1_Origin_36_병합/canbus`
- `OhmioLibraries_BK` 기준 경로: `OhmioLibraries_BK/include/canbus`
- `Origin_36_merge`와 `OhmioLibraries_BK` 원본 파일은 수정하지 않았다.
- 이번 작업은 비교 분석만 수행했으며 통합 적용은 수행하지 않았다.

## 생성 산출물

| 산출물 | 상태 | 내용 |
| --- | --- | --- |
| Origin_36_merge_OhmioLibraries_BK_상호비교_분석/ | 생성 | header별 8개 분석 문서 |
| 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_점검_필요사항.md | 생성 | 사용자 판단 필요사항 |
| 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_오류사항.md | 생성 | 오류 및 제한 사항 |
| 2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_작업기록.md | 생성 | 작업 로그 |

## 파일별 결과 요약

| 파일 | 상태 | 주요 차이 |
| --- | --- | --- |
| additionalDbcCan.h | 차이 있음 | Origin_36_merge-only struct 4; Origin_36_merge-only 함수 11; 함수 형태 변경 4 |
| dbc_CAN_peripheral.h | 차이 있음 | struct layout 차이 2; 함수 형태 변경 58 |
| dbc_CAN.h | 차이 있음 | BK-only struct 21; BK-only enum 1; struct layout 차이 39; enum entry 차이 15; 함수 형태 변경 116 |
| Security_CAN.h | 동일 | 차이 없음 |
| dbc_MsgID_main.h | 차이 있음 | version/hash 차이; BK-only CAN_ID 8; CAN_ID 변경 29; enum entry 차이 5 |
| dbc_MsgID_peripheral.h | 차이 있음 | peripheral version/hash 차이; CAN_ID 변경 2; enum entry 차이 1 |
| dbc_MsgID_security.h | 동일 | 차이 없음 |
| ConversionHelper.h | 차이 있음 | `<assert.h>` include 차이; unsigned 변환 음수 처리 정책 차이 |

## 핵심 판단

- `Security_CAN.h`, `dbc_MsgID_security.h`는 동일하다.
- `additionalDbcCan.h`, `dbc_CAN_peripheral.h`, `dbc_CAN.h`, `dbc_MsgID_main.h`, `dbc_MsgID_peripheral.h`, `ConversionHelper.h`는 차이가 있다.
- 차이 중 상당수는 BK-only message/CAN_ID/enum 또는 동일 message의 bit layout 변경이다.
- 특히 BK 대비 main CAN schema와 peripheral schema는 별도 통합 판단이 필요하다.
