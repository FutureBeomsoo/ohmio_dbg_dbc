# 2-4_dbc_MsgID_main_병합 점검 필요사항

| 대상 | 내용 |
| --- | --- |
| CAN_ID numeric 충돌 제외 | 제외 확정. `CAN_ID_ERROR_TRANS`(0x26), `CAN_ID_ERROR_MOTOR_ADAPTOR`(0x2D)는 Origin 기존 ID와 충돌하므로 활성 추가하지 않는다. |
| version/hash | Origin version/hash 유지 확정. BK `MAJOR 2`, `MINOR 110`, `BUILD 0x47AB1E0D`는 반영하지 않는다. |
| CAN_ID 값 변경 | `CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` 값은 Origin 값 유지 확정. |


## 사용자 의견

CAN_ID numeric 충돌 제외 : `CAN_ID_ERROR_TRANS`(0x26), `CAN_ID_ERROR_MOTOR_ADAPTOR`(0x2D) 제외 확정.
version/hash :  Origin version/hash를 유지 확정. - 주석 유지.
`CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` 값은 Origin 값을 유지 확정.
