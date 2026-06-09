#pragma once


#include "dbc_MsgID_main.h"
extern "C"
{
	#include "dbc_CAN.h"
}

#include <bitset>

#include "RosMessages.hpp"

can_msgs::Frame constructObsEmerMsg(bool StopFlag, uint8_t minDist, uint8_t maxDist, bool movingAway, double dist)
{
	ObstacleEmergency_t data;
    data.raw.signals.stop = (StopFlag) ? 0xFF : 0;
    data.raw.signals.minDistance = minDist;
	data.raw.signals.maxDistance = maxDist;
	data.raw.signals.movingAway = movingAway;
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
    

// the CPP interface assumes distance in m but the C interface uses mm
static const float distanceConverter = 1000.0f; // convert to mm 


//! Create an obstacle message 
//
//! @param[in] distance - distance to the nearest obstacle on track (meters)
//! @param[in] distanceBesideA - distance to the nearest obstacle near the track in small safety margin (meters)
//! @param[in] distanceBesideB - distance to the nearest obstacle near the track in large safety margin (meters)
//! @param[in] timestamp - event time stamp
can_msgs::Frame constructObsDistMsg(float distance, float distanceBesideA, float distanceBesideB, uint32_t timestamp)
{
	ObstacleDetectionLiDARMsg_t data;
	// convert to mm before sending
    data.obstacleDistanceLiDAR = std::max(0.0f, std::min(1000.0f, distance));
	data.obstacleDistanceLiDAR *= distanceConverter;
	data.obstacleDistanceLiDARRegionA = std::max(0.0f, distanceBesideA) * distanceConverter;
	data.obstacleDistanceLiDARRegionB = std::max(0.0f, distanceBesideB) * distanceConverter;


    data.raw.signals.obstacleDistanceLiDARvalid = true;
    data.raw.signals.obstacleDistanceLiDARtimestamp = timestamp;
	ObstacleDetectionLiDARMsg_ToCan(&data);

    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_OBSTACLE;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;
    memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

    return can_msg;
}


ObstacleDetectionLiDARMsg_t interpretObsDistMsg(can_msgs::Frame can_msg)
{
    assert(can_msg.id == CAN_ID_OBSTACLE);
	ObstacleDetectionLiDARMsg_t data;
    memcpy(data.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	ObstacleDetectionLiDARMsg_FromCan(&data);
	// convert to m after we got from CAN
	data.obstacleDistanceLiDAR /= distanceConverter;
	data.obstacleDistanceLiDARRegionA /= distanceConverter;
	data.obstacleDistanceLiDARRegionB /= distanceConverter;

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
	data.raw.signals.waypoint = wp;
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