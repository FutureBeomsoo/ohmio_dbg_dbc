# ErrorSteering 중복 주석 기록

## 기록 일시

- 2026-06-12 11:18:22 KST

## 대상 Message

| CAN ID | DBC CAN ID | Message Name | BO 반영 Struct |
| --- | --- | --- | --- |
| `0x12` | `18` | `ErrorFrontSteering` | `ErrorSteering_t` |
| `0x13` | `19` | `ErrorRearSteering` | `ErrorSteering_t` |

## 확인 내용

`ErrorFrontSteering`, `ErrorRearSteering`는 Chassis CAN 대상 헤더 안에서 `// message ID` 설명 주석이 중복 확인된다.

### additionalDbcCan.h

- 위치: `include_Ohmio_Future/include/canbus/additionalDbcCan.h:137`
- 내용:

```cpp
// message ID 0x12 ErrorFrontSteering
// message ID 0x13 ErrorRearSteering
enum SteerErrorCode
```

이 위치의 `message ID` 주석은 바로 다음 선언이 `typedef struct`가 아니라 `enum SteerErrorCode`이다. 따라서 이 위치만으로는 DBC `BO_` 정의에 필요한 DLC와 Signal 참고 Struct를 확정할 수 없다.

### dbc_CAN.h

- 위치: `include_Ohmio_Future/include/canbus/dbc_CAN.h:3765`
- 내용:

```cpp
// message ID 0x12 ErrorFrontSteering
// message ID 0x13 ErrorRearSteering
typedef struct{
    union
    {
        uint8_t buf[8];
        struct
        {
            ...
        } signals;
    } raw;
    ...
} ErrorSteering_t;
```

이 위치의 `message ID` 주석은 실제 CAN payload Struct인 `ErrorSteering_t`와 연결되어 있으며, `uint8_t buf[8]`로 DLC 8을 확인할 수 있다.

## BO 초안 반영 기준

DBC `BO_` 초안에는 Struct/DLC를 확인할 수 있는 `dbc_CAN.h` 기준으로만 반영했다.

```dbc
BO_ 18 ErrorFrontSteering: 8 Vector__XXX
CM_ BO_ 18 "Signal reference struct: ErrorSteering_t; source header: dbc_CAN.h; source line: 3765; original CAN ID: 0x12";

BO_ 19 ErrorRearSteering: 8 Vector__XXX
CM_ BO_ 19 "Signal reference struct: ErrorSteering_t; source header: dbc_CAN.h; source line: 3766; original CAN ID: 0x13";
```

## 집계 영향

- Chassis 대상 헤더의 원시 `// message ID` 주석 수 기준으로는 `264`개로 집계된다.
- Struct/DLC와 연결되어 실제 DBC `BO_`로 생성 가능한 Message 기준으로는 `262`개로 집계된다.
- 차이 `2`개는 `additionalDbcCan.h`의 `0x12 ErrorFrontSteering`, `0x13 ErrorRearSteering` 주석이다.
- 해당 2개 Message 자체는 `dbc_CAN.h`의 `ErrorSteering_t` 기준으로 이미 BO 초안에 반영되어 있으므로 누락은 아니다.

## 처리 상태

- `additionalDbcCan.h`의 중복 주석 2건은 Chassis 점검 필요사항의 `message ID 주석 미연결 항목`에 기록했다.
- 원본 헤더 파일은 수정하지 않았다.
