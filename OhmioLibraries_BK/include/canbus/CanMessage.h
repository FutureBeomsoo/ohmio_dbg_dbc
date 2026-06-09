#pragma once

//! a cam massage
typedef struct
{
	uint16_t id;			//!< The message ID (should be one of COMMON_CAN)
	uint32_t timeStamp;		//!< when was this message recieved
	uint8_t length;			//!< how many bytes in the data of the message
	uint8_t data[8];		//!< the data
}CAN_MSG;

