# Header_비교 작업내용

## 전체 비교 요약
| 비교 쌍                                | 파일                     | 동일  | 삭제 line | 추가 line | 충돌  | Reserved 대체 | 한쪽 전용 항목 |
| ----------------------------------- | ---------------------- | --- | ------- | ------- | --- | ----------- | -------- |
| OhmioLibraries_OhmioLibraries_36    | additionalDbcCan.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN_peripheral.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_36    | dbc_CAN.h              | 다름  | 43      | 10      | 4   | 4           | 18       |
| OhmioLibraries_OhmioLibraries_36    | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_36    | dbc_MsgID_main.h       | 다름  | 24      | 8       | 0   | 0           | 2        |
| OhmioLibraries_OhmioLibraries_36    | dbc_MsgID_peripheral.h | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_36    | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_36    | ConversionHelper.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | additionalDbcCan.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN_peripheral.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | dbc_CAN.h              | 다름  | 43      | 10      | 4   | 4           | 18       |
| OhmioLibraries_Ohmio_lib_include    | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | dbc_MsgID_main.h       | 다름  | 24      | 8       | 0   | 0           | 2        |
| OhmioLibraries_Ohmio_lib_include    | dbc_MsgID_peripheral.h | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_Ohmio_lib_include    | ConversionHelper.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_BK    | additionalDbcCan.h     | 다름  | 118     | 60      | 0   | 0           | 15       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN_peripheral.h   | 다름  | 187     | 688     | 6   | 0           | 12       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_CAN.h              | 다름  | 1559    | 2685    | 74  | 24          | 166      |
| OhmioLibraries_OhmioLibraries_BK    | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_main.h       | 다름  | 118     | 65      | 9   | 0           | 33       |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_peripheral.h | 다름  | 47      | 5       | 0   | 0           | 7        |
| OhmioLibraries_OhmioLibraries_BK    | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_OhmioLibraries_BK    | ConversionHelper.h     | 다름  | 6       | 5       | 2   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | additionalDbcCan.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | dbc_CAN_peripheral.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | dbc_CAN.h              | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | dbc_MsgID_main.h       | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | dbc_MsgID_peripheral.h | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_Ohmio_lib_include | ConversionHelper.h     | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_OhmioLibraries_BK | additionalDbcCan.h     | 다름  | 118     | 60      | 0   | 0           | 15       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN_peripheral.h   | 다름  | 187     | 688     | 6   | 0           | 12       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_CAN.h              | 다름  | 1527    | 2686    | 74  | 20          | 154      |
| OhmioLibraries_36_OhmioLibraries_BK | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_main.h       | 다름  | 102     | 65      | 9   | 0           | 31       |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_peripheral.h | 다름  | 47      | 5       | 0   | 0           | 7        |
| OhmioLibraries_36_OhmioLibraries_BK | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| OhmioLibraries_36_OhmioLibraries_BK | ConversionHelper.h     | 다름  | 6       | 5       | 2   | 0           | 0        |
| Ohmio_lib_include_OhmioLibraries_BK | additionalDbcCan.h     | 다름  | 118     | 60      | 0   | 0           | 15       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN_peripheral.h   | 다름  | 187     | 688     | 6   | 0           | 12       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_CAN.h              | 다름  | 1527    | 2686    | 74  | 20          | 154      |
| Ohmio_lib_include_OhmioLibraries_BK | Security_CAN.h         | 동일  | 0       | 0       | 0   | 0           | 0        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_main.h       | 다름  | 102     | 65      | 9   | 0           | 31       |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_peripheral.h | 다름  | 47      | 5       | 0   | 0           | 7        |
| Ohmio_lib_include_OhmioLibraries_BK | dbc_MsgID_security.h   | 동일  | 0       | 0       | 0   | 0           | 0        |
| Ohmio_lib_include_OhmioLibraries_BK | ConversionHelper.h     | 다름  | 6       | 5       | 2   | 0           | 0        |


## 주요 관찰
- `OhmioLibraries_36`와 `Ohmio_lib_include`의 대상 8개 헤더는 8/8개가 byte 단위로 동일하다.
- `OhmioLibraries_BK`가 포함된 비교에서 차이가 있는 파일은 18건이다.
- `OhmioLibraries`와 `OhmioLibraries_36` 간 차이가 있는 파일은 2건이다.
