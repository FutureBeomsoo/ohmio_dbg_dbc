#pragma once
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include "ConversionHelper.h"


// message ID 0x480019B CollisionEventInfo
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t counter :8;
			uint64_t remoteID :8;
			uint64_t distance :8;    //m
			uint64_t direction :4;
			uint64_t status :4;
			uint64_t timestamp :32;
		} signals;
	} raw;
} CollisionEventInfo_t;

// message ID 0x484019B CollisionEventConfig1
typedef struct{ 
	union
	{ 
		uint8_t buf[8];
		struct
		{
			uint64_t maxSpeedW :8;    //mm/s
			uint64_t maxSpeedInfo :8;    //mm/s
		} signals;
	} raw;
    double maxSpeedW;
    double maxSpeedInfo;
} CollisionEventConfig1_t;


static void CollisionEventConfig1_ToCan(CollisionEventConfig1_t * msg) 
{ 
    assert(msg->maxSpeedW >= 0);
    msg->raw.signals.maxSpeedW = RoundLimitUnsigned(msg->maxSpeedW, 30, 8);
    assert(msg->maxSpeedInfo >= 0);
    msg->raw.signals.maxSpeedInfo = RoundLimitUnsigned(msg->maxSpeedInfo, 30, 8);
}

static void CollisionEventConfig1_FromCan(CollisionEventConfig1_t * msg) 
{ 
    msg->maxSpeedW = msg->raw.signals.maxSpeedW * 30 * 1.0;
    msg->maxSpeedInfo = msg->raw.signals.maxSpeedInfo * 30 * 1.0;
}



