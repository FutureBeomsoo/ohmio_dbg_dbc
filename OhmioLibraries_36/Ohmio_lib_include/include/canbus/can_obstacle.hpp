#pragma once


#include "dbc_MsgID_main.h"
extern "C"
{
	#include "dbc_CAN.h"
}

#include <bitset>

#include "RosMessages.hpp"

can_msgs::Frame constructObsEmerMsg(bool StopFlag, uint8_t minDist, uint8_t maxDist, bool overtake, bool movingAway, bool obsErrorStop, double dist)
{
	ObstacleEmergency_t data;
    data.raw.signals.stop = (StopFlag) ? 0xFF : 0;
    data.raw.signals.minDistance = minDist;
	data.raw.signals.maxDistance = maxDist;
    data.raw.signals.overtake = overtake;
	data.raw.signals.movingAway = movingAway;
	data.raw.signals.obsErrorStop = obsErrorStop;
	data.envelopDistance = dist;
	ObstacleEmergency_ToCan(&data);

    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_EMERGENCY;
    
    can_msg.dlc = 8;
    memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

    return can_msg;
}


ObstacleEmergency_t interpretObsEmerMsg(can_msgs::Frame can_msg)
{
    assert(can_msg.id == CAN_ID_EMERGENCY);
    
	ObstacleEmergency_t data;
    memcpy(data.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	ObstacleEmergency_FromCan(&data);
    return data;
}

//! Create a dynamic validation message 
//
//! @param[in] wp - WP of the validation location
//! @param[in] x - location of the WP in the track (meters)
//! @param[in] y - location of the WP in the track (meters)
can_msgs::Frame constructDynamicValidationMsg(int wp, double x, double y)
{
	DynamicTrackValidationMsg_t data;
	// convert to mm before sending
	data.waypoint = wp;
	data.x = x;
	data.y = y;

	DynamicTrackValidationMsg_ToCan(&data);

	can_msgs::Frame can_msg;
	can_msg.id = CAN_ID_DYNAMIC_TRACK_VALIDATION;
	can_msg.dlc = 8;
	memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

	return can_msg;
}


DynamicTrackValidationMsg_t interpretDynamicValidationMsg(can_msgs::Frame can_msg)
{
	assert(can_msg.id == CAN_ID_DYNAMIC_TRACK_VALIDATION);
	DynamicTrackValidationMsg_t data;
	memcpy(data.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	DynamicTrackValidationMsg_FromCan(&data);

	return data;
}