#pragma once

#include "error_action.h"

typedef struct
{
	SystemErrorType data;		// this is the received error packet
	uint8_t timer;				// set this timer to 64 when error packet received; countdown every 10ms and clears the error data if no error packet received after the timer reaches 0
}ERRORS_t;

//! This function is going to check individual error bit and returns the highest error action 
//
//! @param[in] id - Device unit ID is defined in the dbc_MsgID_main.h
//! @param[in] sysMode - current system mode; SYS_STATES is defined in the dbc_MsgID_main.h 
//! @param[in] erCheck - error check flag is normally getting from the management request CAN packet (0x320). 
//! @param[in] lidar - use lidar flag is normally getting from the management request CAN packet (0x320). 
//! @param[in] errorCode - error value in uint32_t format. 
//! @param[in] currentTime - current system tick timer in ms.
//! @param[in] startup - startup status (default NUMBER_OF_STARTUP_STATUS for non startup unit).
//! 
//! @return the highest error action defined in error_action.h
ERROR_ACTION error_action_check_Unit(UNIT_ID id, SYS_STATES sysMode, bool erCheck,
	bool lidar, uint32_t errorCode, uint64_t currentTime, STARTUP_STATUS startup);

//! This function is going through each unit and returns the highest error action 
//
//! @param[in] sysMode - current system mode; SYS_STATES is defined in the dbc_MsgID_main.h 
//! @param[in] erCheck - error check flag is normally getting from the management request CAN packet (0x320). 
//! @param[in] lidar - use lidar flag is normally getting from the management request CAN packet (0x320). 
//! @param[in] errorCode - pointer to the error value asddress. 
//! @param[in] currentTime - current system tick timer in ms.
//! @param[in] startup - startup status (default NUMBER_OF_STARTUP_STATUS for non startup unit).
//! 
//! @return the highest error action defined in error_action.h
ERROR_ACTION error_action_check(SYS_STATES sysMode, bool erCheck, bool lidar, ERRORS_t *errorCode, uint64_t currentTime, STARTUP_STATUS startup);
