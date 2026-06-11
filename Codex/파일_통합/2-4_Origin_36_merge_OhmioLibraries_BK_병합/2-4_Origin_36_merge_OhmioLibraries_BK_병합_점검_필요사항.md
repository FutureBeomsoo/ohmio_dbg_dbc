# 2-4_Origin_36_merge_OhmioLibraries_BK_병합 점검 필요사항

| Header | 주요 점검 필요사항 |
| --- | --- |
| `additionalDbcCan.h` | 현재 상태 확인 확정. BK 함수 정의는 `static` 형태로 활성 반영된 상태를 유지한다. |
| `ConversionHelper.h` | Origin `value <= 0` clamp 정책 유지 확정.<br>`<stdint.h>` 추가 확정. 후속 header 산출물 수정 작업에서 `ConversionHelper.h`에 반영 필요. |
| `dbc_CAN.h` | 확정 제외/유지: `ErrorMotorAdaptor`, `ErrorTrans`, `TransErrorCode`, `PrintASCIIMsg`, `IMUMag_ToCan()` `status` assert.<br>`DeviationReqMsg`, `DynamicTrackValidationMsg`, `FusionFrontLongitude`, `StopReqMsg`는 `additionalDbcCan.h` 처리로 `dbc_CAN.h` 중복 추가 제외 확정.<br>`FusionLatitudeMsg`는 `LatitudeMsg_t`/`LatitudeMsg_ToCan`/`LatitudeMsg_FromCan` 대응으로 활성 추가 제외 확정.<br>후속 header 수정 필요: `SystemReqMsg` 확정 layout, Obsolete 계열 BK 정의 반영, `0x221`/`0x231` Longitude mapping 정리.<br>설명/정리 필요: `0x183`, `0x187`, `0x188`, `0x670`, `0x671`, `0x672` message ID comment/alias mapping. |
| `dbc_CAN_peripheral.h` | layout 충돌 function 활성 반영 확정. `AirConReqMsg`, `BMSStatusMsg8` 등은 주석 포함 현재 상태를 유지한다. |
| `dbc_MsgID_main.h` | `CAN_ID_ERROR_TRANS`(0x26), `CAN_ID_ERROR_MOTOR_ADAPTOR`(0x2D) 제외 확정.<br>Origin version/hash 유지 확정.<br>`CAN_ID_IMU_ACC`, `CAN_ID_IMU_GYR`, `CAN_ID_IMU_ROT` 값은 Origin 값 유지 확정. |
| `dbc_MsgID_peripheral.h` | Origin peripheral version/hash 유지 확정.<br>`CAN_ID_AIR_CON_REQ`, `CAN_ID_BMS_STATUS8` 설명은 Origin 구조 기준 유지 확정. |
| `dbc_MsgID_security.h` | 없음 |
| `Security_CAN.h` | 없음 |
