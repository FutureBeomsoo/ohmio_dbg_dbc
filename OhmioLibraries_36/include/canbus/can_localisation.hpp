#pragma once


#include "dbc_MsgID_main.h"
extern "C"
{
	#include "dbc_CAN.h"
}


#include "RosMessages.hpp"

//! Cretae a CAN message from longitude information 
//
//! @param[in] can_id - the can bus message ID to send.
//! @param[in] lat_or_long - the value to send.
//! @param[in] timestamp - current timed.
//! @param[in] quality - signal quality (0-7).
//! @return a CAN frame that can be sent
can_msgs::Frame constructLongMsg(uint32_t can_id, double lat_or_long, uint64_t timestamp, uint8_t quality)
{
	can_msgs::Frame can_msg;
	can_msg.id = can_id;
	//can_msg.header.stamp = ros::Time::now();
	can_msg.dlc = 8;

	LongitudeMsg_t frame;
	memset(frame.raw.buf, 0, sizeof(frame.raw.buf));
	frame.longitude = lat_or_long;
	frame.raw.signals.time = timestamp;
	frame.raw.signals.quality = quality;
	LongitudeMsg_ToCan(&frame);

	memcpy(&(can_msg.data[0]), frame.raw.buf, can_msg.dlc);

	return can_msg;
}

//! Extract latitueds or longitude from a CAN message
//
//! @param[in] can_msg - the message.
//! @return a LocLatLongType structure with the data in the correct fields
LongitudeMsg_t interpretLatLongMsg(const can_msgs::Frame & can_msg)
{
	LongitudeMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	LongitudeMsg_FromCan(&frame);

    return frame;
}



//! Cretae a CAN message from heading and confidence information 
//
//! @param[in] heading - ??
//! @param[in] easting_confidence - ??.
//! @param[in] northing_confidence - ??.
//! @param[in] heading_confidence - ??.
//! @return a CAN frame that can be sent
can_msgs::Frame constructLocFusionOtherMsg(double heading, double easting_confidence, double northing_confidence, double heading_confidence)
{
    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_FUSION_OTHER;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;

	FusionInfoMsg_t frame;
    frame.heading = heading;
    frame.forwardConfidence = easting_confidence;
    frame.lateralConfidence = northing_confidence;
    frame.headConfidence = heading_confidence;
	FusionInfoMsg_ToCan(&frame);

    memcpy(&(can_msg.data[0]), frame.raw.buf, can_msg.dlc);

    return can_msg;
}


//! Extract heading and confidence from a CAN message
//
//! @param[in] can_msg - the message.
//! @return a LocFusionOtherType structure with the data in the correct fields
FusionInfoMsg_t interpretLocFusionOtherMsg(const can_msgs::Frame &can_msg)
{
    assert(can_msg.id == CAN_ID_FUSION_OTHER);

	FusionInfoMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	FusionInfoMsg_FromCan(&frame);
    
    return frame;
}

