# dbc_CAN.h 비교 분석

- 비교 A: `OhmioLibraries` - `OhmioLibraries/include/canbus/dbc_CAN.h`
- 비교 B: `OhmioLibraries_36` - `OhmioLibraries_36/include/canbus/dbc_CAN.h`
- 파일 동일 여부: 다름
- 공백 정규화 후 동일 여부: 다름

## 요약
| 항목           | OhmioLibraries | OhmioLibraries_36 |
| ------------ | -------------- | ----------------- |
| Line         | 3661           | 3628              |
| SHA256       | 1f61bb3507a1   | 2251ffadbd73      |
| Struct       | 146            | 145               |
| Enum         | 28             | 28                |
| CAN_ID       | 0              | 0                 |
| Function     | 130            | 130               |
| Unified diff | -43            | +10               |


Diff hunk 위치:
- `@@ -583,24 +583,6 @@`
- `@@ -1314,8 +1296,6 @@`
- `@@ -1333,8 +1313,6 @@`
- `@@ -1558,14 +1536,11 @@`
- `@@ -1993,7 +1968,7 @@`
- `@@ -2031,7 +2006,7 @@`
- `@@ -2172,12 +2147,10 @@`
- `@@ -2214,7 +2187,7 @@`
- `@@ -2226,23 +2199,21 @@`
- `@@ -2489,10 +2460,8 @@`
- `@@ -2518,10 +2487,8 @@`

### 전처리/Include 비교
include/macro 차이는 없습니다.

### CAN ID enum 비교
CAN_ID enum 항목이 없습니다.

### 일반 enum 비교
#### DrvExtErrorCode
OhmioLibraries에만 있는 entry:
| Entry             | Value |
| ----------------- | ----- |
| Drvext_EPB1_Comms | 6     |
| Drvext_EPB2_Comms | 7     |

동일 entry 이름의 값 변경:
| Entry                | OhmioLibraries | OhmioLibraries_36 |
| -------------------- | -------------- | ----------------- |
| Drvext_NumErrorCodes | 8              | 6                 |

#### FusErrorCode
OhmioLibraries에만 있는 entry:
| Entry        | Value |
| ------------ | ----- |
| fus_Reserved | 0x16  |

OhmioLibraries_36에만 있는 entry:
| Entry                  | Value |
| ---------------------- | ----- |
| fus_conflicting_inputs | 0x16  |

#### ObstaclePcWarningErrorCode
OhmioLibraries에만 있는 entry:
| Entry                        | Value |
| ---------------------------- | ----- |
| Obs_Keyframe_Loader_Database | 0x10  |
| Obs_Keyframe_Loader_Version  | 0x11  |
| Obs_Keyframe_Saver           | 0xE   |

OhmioLibraries_36에만 있는 entry:
| Entry                 | Value |
| --------------------- | ----- |
| Obs_Keyframe_Database | 0xE   |

동일 entry 이름의 값 변경:
| Entry               | OhmioLibraries | OhmioLibraries_36 |
| ------------------- | -------------- | ----------------- |
| Obs_NumWarningCodes | 0x12           | 0x10              |


### Struct/Message 비교
OhmioLibraries에만 있는 struct:
| Struct      | message ID      | bit 수 |
| ----------- | --------------- | ----- |
| ConnectWp_t | 0x630 ConnectWp | 49    |

변경된 공통 struct: 6개
#### ErrorDriveExt_t
- Signal 총 bit 수 변경: OhmioLibraries=8, OhmioLibraries_36=6
OhmioLibraries에만 있는 Signal:
| Signal               | 정의                                   | OhmioLibraries_36 겹침 영역 |
| -------------------- | ------------------------------------ | ----------------------- |
| DrvextEPB1CommsError | bit6 uint64_t DrvextEPB1CommsError:1 | -                       |
| DrvextEPB2CommsError | bit7 uint64_t DrvextEPB2CommsError:1 | -                       |

#### FusError_t
OhmioLibraries에만 있는 Signal:
| Signal   | 정의                        | OhmioLibraries_36 겹침 영역                 |
| -------- | ------------------------- | --------------------------------------- |
| reserved | bit22 uint64_t reserved:1 | bit22 uint64_t fus_conflicting_inputs:1 |

OhmioLibraries_36에만 있는 Signal:
| Signal                 | 정의                                      | OhmioLibraries 겹침 영역      |
| ---------------------- | --------------------------------------- | ------------------------- |
| fus_conflicting_inputs | bit22 uint64_t fus_conflicting_inputs:1 | bit22 uint64_t reserved:1 |

Reserved 대체 후보:
| 범위    | OhmioLibraries            | OhmioLibraries_36                       | 판정                                      |
| ----- | ------------------------- | --------------------------------------- | --------------------------------------- |
| bit22 | bit22 uint64_t reserved:1 | bit22 uint64_t fus_conflicting_inputs:1 | Reserved 대체 후보: OhmioLibraries reserved |

#### FusionFlagsMsg_t
동일 Signal 이름의 정의 변경:
| Signal    | OhmioLibraries                 | OhmioLibraries_36              | 판정               |
| --------- | ------------------------------ | ------------------------------ | ---------------- |
| reserved  | bit22 uint64_t reserved:1      | bits35-39 uint64_t reserved:5  | bit/type/unit 변경 |
| reserved1 | bits37-39 uint64_t reserved1:3 | bits44-45 uint64_t reserved1:2 | bit/type/unit 변경 |
| reserved2 | bits44-45 uint64_t reserved2:2 | bit51 uint64_t reserved2:1     | bit/type/unit 변경 |
| reserved3 | bit51 uint64_t reserved3:1     | bits53-54 uint64_t reserved3:2 | bit/type/unit 변경 |

OhmioLibraries에만 있는 Signal:
| Signal              | 정의                                   | OhmioLibraries_36 겹침 영역          |
| ------------------- | ------------------------------------ | -------------------------------- |
| reserved4           | bits53-54 uint64_t reserved4:2       | bits53-54 uint64_t reserved3:2   |
| w_large_gnss_delay  | bit35 uint64_t w_large_gnss_delay:1  | bits35-39 uint64_t reserved:5    |
| w_large_lidar_delay | bit36 uint64_t w_large_lidar_delay:1 | bits35-39 uint64_t reserved:5    |
| w_no_engine_state   | bit34 uint64_t w_no_engine_state:1   | bit34 uint64_t no_engine_state:1 |

OhmioLibraries_36에만 있는 Signal:
| Signal             | 정의                                  | OhmioLibraries 겹침 영역               |
| ------------------ | ----------------------------------- | ---------------------------------- |
| conflicting_inputs | bit22 uint64_t conflicting_inputs:1 | bit22 uint64_t reserved:1          |
| no_engine_state    | bit34 uint64_t no_engine_state:1    | bit34 uint64_t w_no_engine_state:1 |

Reserved 대체 후보:
| 범위    | OhmioLibraries                       | OhmioLibraries_36                   | 판정                                         |
| ----- | ------------------------------------ | ----------------------------------- | ------------------------------------------ |
| bit22 | bit22 uint64_t reserved:1            | bit22 uint64_t conflicting_inputs:1 | Reserved 대체 후보: OhmioLibraries reserved    |
| bit35 | bit35 uint64_t w_large_gnss_delay:1  | bits35-39 uint64_t reserved:5       | Reserved 대체 후보: OhmioLibraries_36 reserved |
| bit36 | bit36 uint64_t w_large_lidar_delay:1 | bits35-39 uint64_t reserved:5       | Reserved 대체 후보: OhmioLibraries_36 reserved |

비트 범위 충돌:
| 겹침    | OhmioLibraries                     | OhmioLibraries_36                | 판정                             |
| ----- | ---------------------------------- | -------------------------------- | ------------------------------ |
| bit34 | bit34 uint64_t w_no_engine_state:1 | bit34 uint64_t no_engine_state:1 | 동일 bit 영역의 non-reserved 정의 불일치 |

#### FusionHeight_t
- Signal 총 bit 수 변경: OhmioLibraries=64, OhmioLibraries_36=57
OhmioLibraries에만 있는 Signal:
| Signal       | 정의                                | OhmioLibraries_36 겹침 영역 |
| ------------ | --------------------------------- | ----------------------- |
| compute_time | bits57-63 uint64_t compute_time:7 | -                       |

물리/편의 member 차이:
| member       | OhmioLibraries      | OhmioLibraries_36 |
| ------------ | ------------------- | ----------------- |
| compute_time | double compute_time | -                 |

#### ObstaclePcWarning_t
- Signal 총 bit 수 변경: OhmioLibraries=18, OhmioLibraries_36=16
OhmioLibraries에만 있는 Signal:
| Signal                         | 정의                                              | OhmioLibraries_36 겹침 영역                   |
| ------------------------------ | ----------------------------------------------- | ----------------------------------------- |
| ObsKeyframeLoaderDatabaseError | bit16 uint64_t ObsKeyframeLoaderDatabaseError:1 | -                                         |
| ObsKeyframeLoaderVersionError  | bit17 uint64_t ObsKeyframeLoaderVersionError:1  | -                                         |
| ObsKeyframeSaverError          | bit14 uint64_t ObsKeyframeSaverError:1          | bit14 uint64_t ObsKeyframeDatabaseError:1 |

OhmioLibraries_36에만 있는 Signal:
| Signal                   | 정의                                        | OhmioLibraries 겹침 영역                   |
| ------------------------ | ----------------------------------------- | -------------------------------------- |
| ObsKeyframeDatabaseError | bit14 uint64_t ObsKeyframeDatabaseError:1 | bit14 uint64_t ObsKeyframeSaverError:1 |

비트 범위 충돌:
| 겹침    | OhmioLibraries                         | OhmioLibraries_36                         | 판정                             |
| ----- | -------------------------------------- | ----------------------------------------- | ------------------------------ |
| bit14 | bit14 uint64_t ObsKeyframeSaverError:1 | bit14 uint64_t ObsKeyframeDatabaseError:1 | 동일 bit 영역의 non-reserved 정의 불일치 |

#### ObstacleTrackDistanceMsg_t
- Signal 총 bit 수 변경: OhmioLibraries=64, OhmioLibraries_36=44
OhmioLibraries에만 있는 Signal:
| Signal       | 정의                                       | OhmioLibraries_36 겹침 영역 |
| ------------ | ---------------------------------------- | ----------------------- |
| BackDistance | bits59-63 uint64_t BackDistance:5, // mm | -                       |
| reserved     | bits44-58 uint64_t reserved:15           | -                       |

물리/편의 member 차이:
| member       | OhmioLibraries      | OhmioLibraries_36 |
| ------------ | ------------------- | ----------------- |
| BackDistance | double BackDistance | -                 |


### 함수 선언/정의 비교
함수 선언/정의 차이는 없습니다.

## 사용자 점검 후보
- DrvExtErrorCode.Drvext_NumErrorCodes 값 변경: 8 -> 6
- ObstaclePcWarningErrorCode.Obs_NumWarningCodes 값 변경: 0x12 -> 0x10
- FusError_t: Reserved 대체 후보 1건
- FusionFlagsMsg_t: non-reserved bit 범위 충돌 1건
- FusionFlagsMsg_t: Reserved 대체 후보 3건
- ObstaclePcWarning_t: non-reserved bit 범위 충돌 1건
