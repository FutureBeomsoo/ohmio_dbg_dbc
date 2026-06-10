# dbc_CAN.h 분석내용

## 비교 대상

- 좌측: `Codex/파일_통합/2-1_Origin_36_병합/canbus/dbc_CAN.h`
- 우측: `OhmioLibraries_BK/include/canbus/dbc_CAN.h`
- 비교 목적: BK 대비 통합본의 반영/유지/제외 항목 확인

## 결과 요약

- 상태: 차이 있음 - BK 대비 미통합/대체 후보 다수

## 상세 내용

| 항목 | 판정 | 내용 |
| --- | --- | --- |
| 통합본에만 있는 대표 struct | 통합본 추가 | `GpsPpsMsg`, `UBXPart1Msg`, `UBXPart2Msg`, `UBXPart3Msg`, `ConnectWp`, `DriveInfo500kWpMsg`, `ObstacleDangerZoneStopMsg`, `ObstaclePcWarning`, `IMUStatus`, `ExtObsLocMsg`, `ExtObsSpeedMsg`, `EmulatorHeadingMsg`, `ErrorNetwork`, `ErrorTeleOp` 등이 통합본에만 있다. |
| BK에만 있는 대표 struct | BK 미반영 후보 | `BrakeReqMsg`, `CombinedHeightMsg`, `CompassMsg`, `DriveInfoMsg`, `DynamicTrackValidationMsg`, `DeviationReqMsg`, `StopReqMsg`, `FusionFrontLongitude`, `GPSLatitudeMsg`, `UWBLatitudeMsg`, `UWBLongitudeMsg`, `UltraSoundMsg`, `ErrorMotorAdaptor`, `ErrorTrans`, `LogIndMsg`, `PrintASCIIMsg` 등이 BK에만 있다. |
| 변환 함수 구현 방식 | 구현 방식 차이 | BK는 다수 `_ToCan`/`_FromCan` 구현을 header에 포함하고, 통합본은 선언만 둔다. |
| WheelCountMsg | 레이아웃 변경 | BK는 right/left count 32-bit 구조, 통합본은 16-bit right/left count + 32-bit clock 구조다. |
| SystemReqMsg | 레이아웃 변경 | 통합본은 `mode:6`, `driveDisalowed`, `reserved1` 구조를 사용한다. BK는 `mode:8`, `brakePressure`, `reserved` 구조다. |
| ManagementError | 통합본 확장 | 통합본은 `mgtDrvInfoCommsError`, `sharedDriveError`, `ignoreDZ`, `mcuVersionsOk`, `recording`, `limpMode`를 포함한다. |
| Fusion/Obstacle 계열 | 대규모 차이 | FusionHeight, FusionFlags, obstacle warning/danger-zone, IMU, emulator, external obstacle 계열에서 BK와 통합본 구조가 다르다. |
| error enum 계열 | 대규모 차이 | Manual/EPB/Signal/Startup/WheelSpeed/TeleOp/Atmel/Network/Accessory 등 error enum과 bitfield가 BK 대비 많이 변경되어 있다. |

## 재비교 판단

- BK 대비 차이는 기존 `2-1` 사용자 확인 완료 항목과 별개로 검토해야 한다.
- 이번 `2-2` 작업에서는 분석만 수행하며 통합본 코드는 수정하지 않는다.
