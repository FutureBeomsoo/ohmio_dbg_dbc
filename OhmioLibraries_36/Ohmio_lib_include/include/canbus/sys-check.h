#pragma once

#include <stdbool.h>
#include "dbc_MsgID_main.h"

//! is_vehicle_in_moving_mode
//
//! Check the current mode and return true if the vehicle is in moving mode
//! @param[in] currentMode - current system mode
//! 
//! return true if the system is in moving mode
bool is_vehicle_in_moving_mode(SYS_STATES currentMode);
