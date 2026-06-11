# 2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영 추가작업 SystemReq ObsoleteComment 예정 작업계획

## 작업 목적

`2-4_Origin_36_merge_OhmioLibraries_BK_병합_재진행_병합점검반영_점검_필요사항.md`에 추가된 사용자 의견을 현재 재진행 폴더 내 결과물에 반영한다.

이번 작업은 별도 수정 작업 폴더를 만들지 않고, 사용자의 지시에 따라 현재 재진행 작업 폴더 안에서 추가 작업으로 처리한다.

## 작업 범위

| 대상 | 작업 |
| --- | --- |
| `canbus/dbc_CAN.h` | `SystemReqMsg` bit 60/61 정의 수정 |
| `canbus/dbc_CAN.h` | Obsolete 계열 message ID comment 정리 |
| `canbus/dbc_CAN.h` | `ObsoleteMsg_t` placeholder struct 주석 처리 |
| `*_점검_필요사항.md` | 사용자 의견 반영 완료 상태로 정리 |
| `*_작업내용.md` | 추가 반영 내용 기록 |
| `*_작업기록.md` | 추가 작업 log 기록 |

## 적용 기준

| 항목 | 적용 |
| --- | --- |
| `SystemReqMsg` | bit 60 `driveDisalowed`, bit 61 `errorCheck`로 반영한다. |
| Obsolete comment 묶음 | `ObsoleteMsg_t` 앞의 ID comment 묶음은 삭제한다. |
| 활성 BK 정의 comment | 각 활성 정의 앞의 comment를 사용자 의견의 Obsolete message명으로 변경한다. |
| `ObsoleteMsg_t` | 삭제하지 않고 주석 처리한다. |

## 검증 계획

1. 변경 후 8개 header 동시 include를 `g++ -std=c++11 -fsyntax-only`로 확인한다.
2. `SystemReqMsg` bitfield 합계가 64bit인지 확인한다.
3. Obsolete 계열 comment가 사용자 의견과 맞는지 확인한다.

