#pragma once

// the set of MOTOR CONF 
// Anywhere in your code using this enum put 
// static_assert(0x09 == NUMBER_OF_MOTOR_CONF, "MOTOR CONF changed"); // for C++
// _static_assert(0x09 == NUMBER_OF_MOTOR_CONF, "MOTOR CONF changed"); // for C
// this will trigger an error if this enum changes so that you can verify that your code is still valid with this change.
typedef enum
{
	MOTOR_CURTIS_DUAL = 0x01,
	MOTOR_CURTIS_SINGLE_CONF0 = 0x02,
	MOTOR_CURTIS_SINGLE_CONF1 = 0x04,
	MOTOR_MOTOR3 = 0x08,

	/* number of mode in total */
	NUMBER_OF_MOTOR_CONF,
} MOTOR_CONF;
