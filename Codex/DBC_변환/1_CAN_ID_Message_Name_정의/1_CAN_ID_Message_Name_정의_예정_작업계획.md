# 1_CAN_ID_Message_Name_정의 예정 작업계획

## 작업 목적

`include_Ohmio_Future/include/canbus`의 CAN 헤더 파일을 참조하여 Chassis CAN 및 Body CAN용 DBC 파일에 들어갈 `BO_ <CAN ID> <Message Name>: <DLC> <Transmit Node>` 메시지 정의 초안을 작성한다.

작업 1에서는 Signal 상세 정의를 생성하지 않고, 각 Message가 후속 Signal 정의 작업에서 참조할 Struct 정보를 comment와 표 항목으로 함께 남긴다.

## 사용자 의견 반영사항

1. Chassis CAN 대상 작업과 Body CAN 대상 작업을 별개 하위 작업 폴더로 분리한다.
2. 다음 작업을 위해 각 Message별 Signal 참고 대상 Struct comment를 추가한다.

## 작업 범위

### 원본 참조 폴더

- `include_Ohmio_Future/include/canbus`

### 1-1_Chassis_CAN_Message_Name_정의

대상 헤더:

- `additionalDbcCan.h`
- `dbc_CAN.h`
- `dbc_MsgID_main.h`

작성 위치:

- `Codex/DBC_변환/1_CAN_ID_Message_Name_정의/1-1_Chassis_CAN_Message_Name_정의/`

### 1-2_Body_CAN_Message_Name_정의

대상 헤더:

- `dbc_CAN_peripheral.h`
- `dbc_MsgID_peripheral.h`
- `Security_CAN.h`
- `dbc_MsgID_security.h`

작성 위치:

- `Codex/DBC_변환/1_CAN_ID_Message_Name_정의/1-2_Body_CAN_Message_Name_정의/`

### 참고 헤더

- `ConversionHelper.h`

## 수행 내용

1. Chassis CAN과 Body CAN을 별도 하위 작업으로 나누어 진행한다.
2. 대상 헤더 파일에서 `// message ID <CAN ID> <Message Name>` 주석을 수집한다.
3. 각 `message ID` 주석이 연결되는 `typedef struct` 블록과 type alias를 확인한다.
4. 해당 struct 내부의 `uint8_t buf[<DLC>]` 값을 확인하여 Message Length(DLC)를 추출한다.
5. DBC 형식에 맞춰 CAN ID를 10진수로 변환한다.
6. 송신 노드는 원본 헤더에서 확인되지 않는 경우 지침에 따라 `Vector__XXX`로 정의한다.
7. 각 Message 정의에 후속 Signal 정의 작업용 참고 Struct comment를 추가한다.
8. 누락, 중복 CAN ID, Message Name 충돌, DLC 확인 불가 항목은 사용자 점검 필요사항에 기록한다.

## 결과 작성 형식

각 Message는 아래 정보를 반드시 기록한다.

- CAN 구분: `Chassis` 또는 `Body`
- 원본 헤더 파일
- 원본 CAN ID: 16진수
- DBC CAN ID: 10진수
- Message Name
- DLC
- Transmit Node
- Signal 참고 Struct/type alias
- Struct 확인 상태

DBC 초안에는 다음 형식으로 `BO_` 정의와 Struct 참고 comment를 함께 작성한다.

```dbc
BO_ 257 Example_Message1: 8 Vector__XXX
CM_ BO_ 257 "Signal reference struct: ExampleMsg_t; source header: dbc_CAN.h";
```

## 산출물 구조

본 작업은 아래 구조로 `Codex/DBC_변환/1_CAN_ID_Message_Name_정의/` 내부에 생성 또는 갱신한다.

```text
Codex/DBC_변환/1_CAN_ID_Message_Name_정의/
├── 1_CAN_ID_Message_Name_정의_예정_작업계획.md
├── 1_CAN_ID_Message_Name_정의_작업기록.md
├── 1-1_Chassis_CAN_Message_Name_정의/
│   ├── 1-1_Chassis_CAN_Message_Name_정의_작업내용.md
│   ├── 1-1_Chassis_CAN_Message_Name_정의_오류사항.md
│   ├── 1-1_Chassis_CAN_Message_Name_정의_점검_필요사항.md
│   ├── 1-1_Chassis_CAN_Message_Name_정의_작업기록.md
│   └── 1-1_Chassis_CAN_Message_Name_정의_BO_초안.dbc
└── 1-2_Body_CAN_Message_Name_정의/
    ├── 1-2_Body_CAN_Message_Name_정의_작업내용.md
    ├── 1-2_Body_CAN_Message_Name_정의_오류사항.md
    ├── 1-2_Body_CAN_Message_Name_정의_점검_필요사항.md
    ├── 1-2_Body_CAN_Message_Name_정의_작업기록.md
    └── 1-2_Body_CAN_Message_Name_정의_BO_초안.dbc
```

## 작업 제한

- 원본 폴더 및 원본 헤더 파일은 수정하지 않는다.
- 모든 결과물은 `Codex` 폴더 하위에만 작성한다.
- 본 계획 파일에 대한 사용자 승인 후 실제 추출 및 결과물 작성을 진행한다.
- 작업 1은 Message 정의 단계이므로 Signal의 start bit, signed type, factor, offset, min, max는 생성하지 않는다.
- Big Endian, Multiplexer, 송수신 Node 등 작업 1 범위를 넘어서는 정보가 발견되면 즉시 기록만 하고 상세 정의는 후속 작업 범위로 분리한다.

## 검증 방법

1. 추출된 각 메시지에 대해 CAN ID, Message Name, DLC, 원본 헤더, 참고 Struct/type alias를 대조한다.
2. 동일 CAN ID의 중복 정의 여부를 확인한다.
3. 동일 Message Name의 복수 CAN ID 사용 여부를 확인하고 의도된 공유 Struct인지 기록한다.
4. 생성된 `BO_` 정의가 DBC 기본 형식과 일치하는지 확인한다.
5. `CM_ BO_` Struct 참고 comment의 CAN ID가 대응되는 `BO_` CAN ID와 일치하는지 확인한다.

## 승인 요청

위 계획대로 `작업 1. *.dbc 파일 별 CAN ID 에 대한 Message Name 정의`를 진행해도 되는지 확인이 필요하다.
