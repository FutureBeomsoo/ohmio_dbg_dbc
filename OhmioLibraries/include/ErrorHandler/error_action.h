/**
 * @file error_action.h
 *  @brief \mainpage The error_action library is a low level library solely converting from error bit into corresponding error action.
 */
#ifndef _ERROR_ACTION_H    /* Guard against multiple inclusion */
#define _ERROR_ACTION_H


#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "canbus/dbc_CAN.h"
#include "canbus/dbc_MsgID_main.h"
#include "can_error.h"

typedef enum
{
    SYS_ERROR_IDLE = 0,
    SYS_ERROR_MANUAL,
	SYS_ERROR_REMOTE,
    SYS_ERROR_AUTO_INIT,
	SYS_ERROR_AUTO_TIMEOUT,

    // alway add modes above this
    NO_OF_SYS_ERROR_ACTION_MODE,
}SYS_ERROR_ACTION_MODE;


typedef enum
{
    NO_ACTION = 0,
    EMRG_L1,		// graceful stop and change to idle after fully stopped
    EMRG_L2,
    EMRG_L3,		// graceful stop and change to emergency mode after timeout
	EMRG_L4,
    EMRG_L5,
    EMRG_L6,
    HARD_STOP,		// hard stop and change to emergency mode immediately

    // alway add error modes above this
    NO_OF_ERROR_ACTION,
}ERROR_ACTION;

extern const uint8_t error2action_LOC[Loc_NumErrorCodes+1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_DRV[Drv_NumErrorCodes+1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_STEER[Steer_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_MANUAL[Man_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_FUSION[Fusion_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_FUS[fus_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_OBS[Obstacle_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_MOT[motor3status_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_EHB[EHB_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_T060[T060_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_EPB[EPB_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_SIGNAL[signal_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_SAFETY[Safety_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_STARTUP[startup_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_MANAGEMENT[mgt_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_NETWORK[network_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_ATLOC[Atloc_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_ATDRV[Atdrive_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_ATMAN[Atmanual_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_ATFUS[Atfusion_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_MGTPC[mgt_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_WHEEL[wheel_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];
extern const uint8_t error2action_ACCESSORY[Accessory_NumErrorCodes + 1][NO_OF_SYS_ERROR_ACTION_MODE];

ERROR_ACTION ErrorToAction(COMMON_CAN errorMessageId, int errorBit, SYS_ERROR_ACTION_MODE mode);
SYS_ERROR_ACTION_MODE getErrorActionMode(SYS_STATES mode, bool timeout);

#endif