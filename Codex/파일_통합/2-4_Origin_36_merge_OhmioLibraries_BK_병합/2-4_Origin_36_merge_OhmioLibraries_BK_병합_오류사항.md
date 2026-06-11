# 2-4_Origin_36_merge_OhmioLibraries_BK_병합 오류사항

## 오류 사항

- 최종 병합 산출물 기준 미해결 실행 오류는 없다.
- 중간 검증에서 BK-only `ErrorMotorAdaptor`, `ErrorTrans`가 numeric CAN ID 충돌 항목인데 `dbc_CAN.h`에 활성 추가된 상태를 확인했다.
- 해당 2개 struct는 최종 산출물에서 제거했고, `dbc_CAN` 및 전체 점검 필요사항에 사용자 확인 항목으로 분리했다.
- 중간 검증에서 BK-only `CAN_ID_OBSTACLE_TRACK`이 numeric 충돌 없는 항목인데 `dbc_MsgID_main.h`에 누락된 것을 확인했다.
- 해당 CAN_ID는 최종 `dbc_MsgID_main.h`에 활성 추가했다.
- 헤더 단독 문법 확인 중 `IMUMag_ToCan()`의 BK `status` 참조가 최종 struct에 없는 것을 확인했다.
- `status`는 Origin `z` bit field와 overlap되는 BK-only signal이라, struct는 Origin 우성 규칙대로 유지하고 해당 assert 줄을 주석 처리했다.

## 제한 사항

- 전체 프로젝트 build는 수행하지 않았다.
- 생성 header 문법 확인은 수행했다. 8개 header 전체 include 조합과 `dbc_CAN.h` 단독 확인은 위 보정 후 통과했다.
- `ConversionHelper.h` 단독 확인은 `<stdint.h>` 선행 include 없이 실패하지만, 이를 include하는 생성 header들은 `<stdint.h>`를 먼저 include한다.
- 사용자 의견에 따라 signal 충돌 function도 활성 반영했으므로 일부 function은 최종 struct layout과의 동작 확인이 필요할 수 있다.
- CAN ID numeric 충돌이 있는 BK-only 항목은 활성 추가하지 않고 점검 필요사항으로 분리했다.
