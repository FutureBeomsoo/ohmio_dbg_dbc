# 2_Message_Signal_정의 예정 작업계획

## 작업 목적

`Codex/dbc_convert_Command.txt`의 수행 작업 2에 따라 각 Message에 대한 Signal의 `Name`, `Signed type`, `start bit`, `length`, `factor`, `offset`, `min`, `max`를 정의한다.

작업 1의 결과물인 Chassis/Body `BO_` 초안을 기준으로 각 Message에 `SG_` 정의를 추가할 수 있는 Signal 초안을 작성한다.

## 작업 1 결과물 참조 기준

### Chassis CAN

- Message 기준 파일: `Codex/DBC_변환/1_CAN_ID_Message_Name_정의/1-1_Chassis_CAN_Message_Name_정의/1-1_Chassis_CAN_Message_Name_정의_BO_초안.dbc`
- Message 수: 262개
- CAN ID 표기: CAN 2.0A 원본 ID의 10진수 표기
- 확정 반영:
  - `ErrorFrontSteering`, `ErrorRearSteering`은 `dbc_CAN.h`의 `ErrorSteering_t`로 연결 확정
  - Struct/DLC 미확인 CAN_ID enum 15개는 적용 제외
  - 적용 제외 목록은 `Codex/사용자_참고_사항.md`의 `미추적 Message 목록`을 참조

### Body CAN

- Message 기준 파일: `Codex/DBC_변환/1_CAN_ID_Message_Name_정의/1-2_Body_CAN_Message_Name_정의/1-2_Body_CAN_Message_Name_정의_BO_초안.dbc`
- Message 수: 85개
- CAN ID 표기: 원본 CAN ID에 `0x80000000` 플래그를 더한 Vector DBC 10진수 표기
- 원본 CAN ID는 `CM_ BO_` comment의 `original CAN ID` 값을 참조

## 원본 참조 폴더

- `include_Ohmio_Future/include/canbus`

## 대상 헤더

### 2-1_Chassis_CAN_Signal_정의

대상 헤더:

- `additionalDbcCan.h`
- `dbc_CAN.h`
- `dbc_MsgID_main.h`

참고 입력:

- `1-1_Chassis_CAN_Message_Name_정의_BO_초안.dbc`
- `1-1_Chassis_CAN_Message_Name_정의_작업내용.md`
- `1-1_Chassis_CAN_Message_Name_정의_점검_필요사항.md`

작성 위치:

- `Codex/DBC_변환/2_Message_Signal_정의/2-1_Chassis_CAN_Signal_정의/`

### 2-2_Body_CAN_Signal_정의

대상 헤더:

- `dbc_CAN_peripheral.h`
- `dbc_MsgID_peripheral.h`
- `Security_CAN.h`
- `dbc_MsgID_security.h`

참고 입력:

- `1-2_Body_CAN_Message_Name_정의_BO_초안.dbc`
- `1-2_Body_CAN_Message_Name_정의_작업내용.md`
- `1-2_Body_CAN_Message_Name_정의_점검_필요사항.md`

작성 위치:

- `Codex/DBC_변환/2_Message_Signal_정의/2-2_Body_CAN_Signal_정의/`

### 공통 참고 헤더

- `ConversionHelper.h`

## 수행 내용

1. 작업 1의 `BO_` 초안에서 Message ID, Message Name, DLC, Signal 참고 Struct를 수집한다.
2. 원본 헤더의 해당 `typedef struct` 안 `raw.signals` bit-field를 분석한다.
3. 각 bit-field의 선언 순서를 기준으로 Little Endian start bit를 누적 계산한다.
4. `uint64_t` 계열 bit-field는 unsigned, `int64_t` 계열 bit-field는 signed로 정의한다.
5. `reserved`, `reserved1` 등 예약 필드는 기본적으로 DBC Signal 생성 대상에서 제외하되, 제외 내역은 작업내용 또는 점검사항에 기록한다.
6. 동일 Struct를 공유하는 여러 Message에는 동일 Signal 구조를 반복 적용한다.
7. `<Type alias>_ToCan`, `<Type alias>_ToCAN`, `<Type alias>_FromCan`, `<Type alias>_FromCAN` 함수가 있으면 factor, offset, min, max를 추출한다.
8. 변환 함수에서 factor/offset/min/max를 명확히 확정할 수 없는 Signal은 기본값으로 정의한다.
   - factor: `1`
   - offset: `0`
   - unsigned min/max: bit length 기준 표현 가능 범위
   - signed min/max: two's complement bit length 기준 표현 가능 범위
9. Big Endian 변환 패턴이 확인되면 해당 Signal은 DBC에 Big Endian(`@0`)으로 표기하고 점검 필요사항에도 기록한다.
10. Unit과 Receive Node는 원본에서 확인되지 않으면 지침에 따라 `" "`와 `Vector__XXX`로 정의한다.
11. Body CAN은 작업 1에서 확정한 Vector DBC 확장 ID 표기를 유지한다.
12. `CM_ BO_` comment는 각 `BO_` 바로 아래에 두지 않고 DBC 하단의 Comment 정의 부분에 모아서 작성한다.

## 결과 작성 형식

DBC 초안은 작업 1의 `BO_` 정의 아래에 `SG_`를 추가하는 형태로 작성한다.
`CM_ BO_` comment는 Message 정의 부분이 끝난 뒤 DBC 하단의 Comment 정의 부분에 별도로 모아 작성한다.

```dbc
BO_ 257 Example_Message1: 8 Vector__XXX
 SG_ ExampleSig0 : 0|12@1+ (0.01,-20.47) [-20.47|20.48] " " Vector__XXX
 SG_ ExampleSig1 : 16|11@1- (0.1,0) [-102.4|102.3] " " Vector__XXX

CM_ BO_ 257 "Signal reference struct: ExampleMsg_t; source header: dbc_CAN.h; source line: 100; original CAN ID: 0x101";
```

Big Endian으로 확정된 Signal은 아래와 같이 `@0`으로 작성한다.

```dbc
 SG_ ExampleBigEndianSig : 24|16@0+ (1,0) [0|65535] " " Vector__XXX
```

각 Signal은 아래 정보를 작업내용 문서에 기록한다.

- CAN 구분
- Message Name
- DBC CAN ID
- 원본 CAN ID
- 원본 헤더
- Signal 참고 Struct
- Signal Name
- bit-field type
- start bit
- length
- endian
- signed 여부
- factor
- offset
- min
- max
- unit
- receive node
- 변환 함수 근거
- 확인 상태

DBC 파일 구성 순서는 아래를 따른다.

```text
VERSION/NS_/BS_/BU_

<Message 정의 부분>
BO_ ...
 SG_ ...

<Comment 정의 부분>
CM_ BO_ ...
```

## 산출물 구조

```text
Codex/DBC_변환/2_Message_Signal_정의/
├── 2_Message_Signal_정의_예정_작업계획.md
├── 2_Message_Signal_정의_작업기록.md
├── 2-1_Chassis_CAN_Signal_정의/
│   ├── 2-1_Chassis_CAN_Signal_정의_작업내용.md
│   ├── 2-1_Chassis_CAN_Signal_정의_오류사항.md
│   ├── 2-1_Chassis_CAN_Signal_정의_점검_필요사항.md
│   ├── 2-1_Chassis_CAN_Signal_정의_작업기록.md
│   └── 2-1_Chassis_CAN_Signal_정의_SG_초안.dbc
└── 2-2_Body_CAN_Signal_정의/
    ├── 2-2_Body_CAN_Signal_정의_작업내용.md
    ├── 2-2_Body_CAN_Signal_정의_오류사항.md
    ├── 2-2_Body_CAN_Signal_정의_점검_필요사항.md
    ├── 2-2_Body_CAN_Signal_정의_작업기록.md
    └── 2-2_Body_CAN_Signal_정의_SG_초안.dbc
```

## 작업 제한

- 원본 폴더 및 원본 헤더 파일은 수정하지 않는다.
- 모든 결과물은 `Codex` 폴더 하위에만 작성한다.
- 본 계획 파일에 대한 사용자 승인 후 실제 Signal 추출 및 결과물 작성을 진행한다.
- 작업 2는 Signal 정의 단계이므로 Enum 값 매핑(`VAL_`, `VAL_TABLE_`)은 작업 3, 4로 분리한다.
- 변환 함수 해석이 불명확한 항목은 임의로 확정하지 않고 점검 필요사항에 기록한다.

## 검증 방법

1. 작업 1의 `BO_` Message 수와 작업 2 출력 DBC의 `BO_` Message 수가 일치하는지 확인한다.
2. 각 Message의 Signal bit length 합이 DLC bit 수를 초과하지 않는지 확인한다.
3. Signal start bit가 bit-field 선언 순서 기준으로 누락 또는 중복되지 않는지 확인한다.
4. `reserved` 제외 후 실제 Signal 수와 제외 Signal 수를 기록한다.
5. `BO_`와 DBC 하단 `CM_ BO_`의 CAN ID 매칭이 유지되는지 확인한다.
6. Body CAN 확장 ID가 Vector DBC 표기로 유지되는지 확인한다.
7. Big Endian으로 확인된 Signal이 `@0`으로 작성되고 점검 필요사항에 기록되었는지 확인한다.
8. DBC 파일 내부에 비ASCII 라인이 없는지 확인한다.

## 승인 요청

위 계획대로 `작업 2. 각 Message에 대한 Signal의 Name, Signed type, start bit, length, factor, offset, min, max 정의`를 진행해도 되는지 확인이 필요하다.

## 사용자 의견

  9. Big Endian 변환 패턴이 확인되면 해당 Signal은 오류사항 및 점검 필요사항에 기록한다.:
    해당 Signal이 Big Endiand으로 확인 되면, Big Endian으로 표기 하되, 점검 필요사항에 기록.

  ```dbc
  BO_ 257 Example_Message1: 8 Vector__XXX
  CM_ BO_ 257 "Signal reference struct: ExampleMsg_t; source header: dbc_CAN.h; source line: 100; original CAN ID: 0x101";
  SG_ ExampleSig0 : 0|12@1+ (0.01,-20.47) [-20.47|20.48] " " Vector__XXX
  SG_ ExampleSig1 : 16|11@1- (0.1,0) [-102.4|102.3] " " Vector__XXX
  ```
  에서 
  CM_ BO_ <Comment> 는 dbc 하단 에 정의

  ````
  ...
  <메세지 정의 부분>
  ...

  <Comment 정의 부분>
  ```

## 사용자 의견 반영사항

1. Big Endian 변환 패턴이 확인된 Signal은 DBC에 Big Endian(`@0`)으로 표기하고, 동시에 점검 필요사항에 기록한다.
2. `CM_ BO_` comment는 각 Message 정의 바로 아래가 아니라 DBC 하단의 Comment 정의 부분에 모아서 작성한다.
