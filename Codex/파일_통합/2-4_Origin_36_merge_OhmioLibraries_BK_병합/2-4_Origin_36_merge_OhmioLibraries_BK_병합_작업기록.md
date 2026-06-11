# 2-4_Origin_36_merge_OhmioLibraries_BK_병합 작업기록

| 순서 | 작업 | 결과 |
| ---: | --- | --- |
| 1 | command/계획 확인 | 사용자 동의 후 진행 |
| 2 | 입력 파싱 | Origin/BK header 8개 분석 |
| 3 | 병합 산출물 생성 | `canbus/` header 8개 생성 |
| 4 | header별 문서 작성 | 작업내용/점검/오류/기록 작성 |
| 5 | 전체 문서 작성 | 전체 작업내용/점검/오류/기록 작성 |
| 6 | 최종 검증 | 결과 header 8개 및 문서 세트 생성 확인, 원본/BK 입력 폴더 미수정 확인 |
| 7 | 최종 보정 | `CAN_ID_OBSTACLE_TRACK` 누락 확인 후 `dbc_MsgID_main.h`에 추가 |
| 8 | 문법 확인 보정 | `IMUMag_ToCan()`의 BK `status` assert overlap을 주석 처리하고 `dbc_CAN.h` 단독 문법 확인 통과 |
| 9 | 전체 include 문법 확인 | 2-4 결과 header 8개 include 조합 `g++ -fsyntax-only` 통과 |
