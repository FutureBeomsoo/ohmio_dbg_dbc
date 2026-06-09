/**
 * @file can_general.h
 *  @brief \mainpage The can_obstacle library is a low level library solely converting from raw can frames into c structures representing the data they store.
 */
 
#pragma once
#include "dbc_MsgID_main.h"
#include "dbc_CAN.h"

#define LIVE_UPDATE_SWITCHER_ID		0xC000
#define CAN_O_ID_RESERVED           0x7FF
#define CAN_P_ID_RESERVED           0x1FFFFFFF
	
static const unsigned resetIDlookupTable[LAST_UNIT_ID] = 
{
    (unsigned)CAN_ID_LOC_RESET_CAUSE,
    (unsigned)CAN_ID_DRIVE_RESET_CAUSE,
    (unsigned)CAN_ID_F_STEER_RESET_CAUSE,
    (unsigned)CAN_ID_R_STEER_RESET_CAUSE,
    (unsigned)CAN_ID_MANUAL_RESET_CAUSE,
    (unsigned)CAN_ID_FUSION_RESET_CAUSE,
    (unsigned)CAN_ID_BLACK_BOX_RESET_CAUSE,
    (unsigned)CAN_ID_OBSTACLE_PC_RESET_CAUSE,
    (unsigned)CAN_ID_L_MOTOR_RESET_CAUSE,
    (unsigned)CAN_ID_R_MOTOR_RESET_CAUSE,
    (unsigned)CAN_ID_EHB_RESET_CAUSE,
    (unsigned)CAN_O_ID_RESERVED,       // not used; EHB2
    (unsigned)CAN_ID_EPB1_RESET_CAUSE,
    (unsigned)CAN_ID_EPB2_RESET_CAUSE,
    (unsigned)CAN_ID_F_SIGNAL_RESET_CAUSE,
    (unsigned)CAN_ID_R_SIGNAL_RESET_CAUSE,
    (unsigned)CAN_P_ID_RESERVED,
    (unsigned)CAN_P_ID_RESERVED,
    (unsigned)CAN_ID_ATMEL_RESET_SAFETY,
    (unsigned)CAN_ID_RESET_STARTUP,
    (unsigned)CAN_ID_ATMEL_RESET_LOC,
    (unsigned)CAN_ID_ATMEL_RESET_DRIVE,
    (unsigned)CAN_ID_ATMEL_RESET_MANUAL,
    (unsigned)CAN_ID_ATMEL_RESET_FUSION,
	(unsigned)CAN_ID_FOOT1_RESET_CAUSE,
	(unsigned)CAN_ID_FOOT2_RESET_CAUSE,
	(unsigned)CAN_ID_RESET_SECURITY,
	(unsigned)CAN_O_ID_RESERVED,	// not used; management pc
	(unsigned)CAN_ID_ATMEL_RESET_SECURITY,
	(unsigned)CAN_ID_RESET_NETWORK_COMM,
	(unsigned)CAN_ID_RESET_ACCESSORY1,
	(unsigned)CAN_ID_RESET_ACCESSORY2,
	(unsigned)CAN_ID_RESET_WHEEL_SPEED1, 
    (unsigned)CAN_ID_RESET_WHEEL_SPEED2,
    (unsigned)CAN_O_ID_RESERVED,
    (unsigned)CAN_O_ID_RESERVED,
	(unsigned)CAN_O_ID_RESERVED,
	(unsigned)CAN_ID_FUSION_RESET_CAUSE,
	(unsigned)CAN_ID_RESET_TRANSLATOR,
	(unsigned)CAN_ID_RESET_TRANSLATOR2,
	(unsigned)CAN_ID_RESET_TELE_OP,
	(unsigned)CAN_ID_ATMEL_RESET_TELEOP,
	(unsigned)CAN_ID_RESET_JOYSTICK,
};
