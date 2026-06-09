#pragma once

#include <stdint.h>
#include <stdbool.h>
#ifdef __PC_SIM
#include "sim.h"
#else 
#ifndef _NOT_FOR_MPLAB
#include "system_config.h"		// we should use the SYS_CLK_FREQ value defined in the system_config.h file for MPLAB projects
#endif // !_NOT_FOR_MPLAB
#endif

#ifndef SYS_CLK_FREQ
#define SYS_CLK_FREQ		252000000ul		// this is for test code
#endif // !SYS_CLK_FREQ



#define MILLIS2TICKS (SYS_CLK_FREQ / 2000)		// CP0 rolls over every 34s if SYS_CLK_FREQ is 252MHz

/* Communication error structure */
typedef struct
{
	uint32_t newMsgTime;            // newly received message ticktime (CP0 tick value)
	uint32_t lastUpdateTime;		// last received ticktime (CP0 tick value)
	uint16_t maxAllowedMissTime;	// max. allowed time for missing packet (ms)	
	uint16_t maxAllowedDelayTime;	// max. allowed time for packet delay (ms)
	uint8_t delayPacketCount;		// count the number of delay packet 
}COMMS_ERROR_t;

/* Counter error structure */
typedef struct
{
    uint16_t packetCount;		// count the number of error packet 
    uint16_t allowedCount;		// max. allowed count number of error packet 
}COUNTER_ERROR_t;

//! This function is called every time when a new message received in the CAN interrupt.
//! this is going to check the current tick time with the last updated time 
//! and keep the delay count in the item structure.
//
//! @param[in, out] item - unit that needs to check the delay time period
//! @param[in] currentTickTime - current CP0 tick value
//! 
//! @return void
void communication_delay_check(COMMS_ERROR_t *item, uint32_t currentTickTime);

//! This function is called every 10ms to check any missing packet and delay packet count.
//
//! @param[in] item - unit that needs to check for the miss time
//! @param[in] currentTickTime - current CP0 tick value
//! 
//! @return true if the last updated time is over the max. allowed miss time or delay packet count is over MAX_DELAY_COUNT
bool communication_error_check(COMMS_ERROR_t *item, uint32_t currentTickTime);

//! This function is called every 10ms to check any error flag has raised.
//
//! @param[in] flag - current error flag status
//! @param[in] item - unit that needs to check for the error counter
//! 
//! @return true if the last updated time is over the max. allowed miss time or delay packet count is over MAX_DELAY_COUNT
bool counter_error_check(bool flag, COUNTER_ERROR_t *item);

//! This function is to initialise the communication error check unit
//
//! @param[in, out] unit - unit that needs to check for communication errors
//! @param[in] messagePeriod - expected time period in ms
//! @param[in] currentTickTime - current CP0 tick value
//! 
//! @return n/a
void InitUnit(COMMS_ERROR_t* unit, uint32_t messagePeriod, uint32_t currentTime);

//! This function is to initialise the counter error check flag
//
//! @param[in, out] flag - flag that needs to check for counter errors
//! @param[in] allowedCount - max. allowed error counter value
//! 
//! @return n/a
void InitCountFlag(COUNTER_ERROR_t* flag, uint16_t allowedCount);