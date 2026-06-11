# 2-4_dbc_CAN_병합 오류사항

## 오류 사항

- 최종 병합 산출물 기준 미해결 실행 오류는 없다.
- 중간 검증에서 BK-only `ErrorMotorAdaptor`, `ErrorTrans`가 numeric CAN ID 충돌 항목인데 활성 추가된 상태를 확인했다.
- 해당 2개 struct는 최종 `dbc_CAN.h`에서 제거했고, 점검 필요사항에 사용자 확인 항목으로 분리했다.
- 헤더 문법 확인 중 `IMUMag_ToCan()`의 BK `status` 참조가 최종 struct에 없는 것을 확인했다.
- `status`는 Origin `z` bit field와 overlap되는 BK-only signal이라, struct는 Origin 우성 규칙대로 유지하고 해당 assert 줄을 주석 처리했다.

## 제한 사항

- 이번 작업은 header 병합 산출물 생성이며 별도 build/compile 검증은 수행하지 않았다.
- 전체 프로젝트 build는 수행하지 않았다.
- 생성 header 단독 문법 확인 결과 `dbc_CAN.h`는 위 보정 후 통과했다.
- 사용자 의견에 따라 signal 충돌 function도 활성 반영한 항목은 동작 확인이 필요할 수 있다.
