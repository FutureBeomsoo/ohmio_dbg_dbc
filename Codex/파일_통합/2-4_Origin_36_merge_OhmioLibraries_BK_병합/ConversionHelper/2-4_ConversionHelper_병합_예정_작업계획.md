# 2-4_ConversionHelper_병합 예정 작업계획

## 대상

| 항목 | 경로 |
| --- | --- |
| Origin_36_merge | `Codex/파일_통합/2-1_Origin_36_병합/canbus/ConversionHelper.h` |
| OhmioLibraries_BK | `OhmioLibraries_BK/include/canbus/ConversionHelper.h` |
| 2-3 재수행 분석 | `Codex/파일_통합/2-3_Origin_36_merge_OhmioLibraries_BK_상호비교_재수행/Origin_36_merge_OhmioLibraries_BK_상호비교_재수행_분석/ConversionHelper_분석내용.md` |
| 결과 예정 | `Codex/파일_통합/2-4_Origin_36_merge_OhmioLibraries_BK_병합/canbus/ConversionHelper.h` |

## 2-3 재수행 결과 요약

| 항목 | 내용 |
| --- | --- |
| include 차이 | BK에만 `<assert.h>` 있음 |
| function 차이 | `RoundUnsigned`, `RoundLimitUnsigned` |
| 정책 차이 | Origin은 음수 입력을 0으로 clamp, BK는 `assert(value >= 0)` |

## 병합 계획

1. `Origin_36_merge` 파일을 base로 사용한다.
2. `RoundUnsigned`, `RoundLimitUnsigned`는 일반 helper function 충돌이므로 기본적으로 Origin 정의를 유지한다.
3. BK의 `<assert.h>` include와 assert 정책은 활성 반영하지 않고 점검 필요사항에 기록한다.
4. 필요 시 주석으로 BK 정책 차이를 남긴다.

## 생성 예정 문서

| 문서 | 내용 |
| --- | --- |
| `2-4_ConversionHelper_병합_작업내용.md` | helper 함수 정책 처리 내용 |
| `2-4_ConversionHelper_병합_점검_필요사항.md` | unsigned 음수 입력 처리 정책 확인 |
| `2-4_ConversionHelper_병합_오류사항.md` | 오류 및 제한 사항 |
| `2-4_ConversionHelper_병합_작업기록.md` | 작업 log |

## 진행 조건

사용자 동의 후 실제 병합을 진행한다.
