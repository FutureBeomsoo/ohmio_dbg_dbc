#pragma once


#include "dbc_MsgID_main.h"
extern "C"
{
	#include "dbc_CAN.h"
}

#include "RosMessages.hpp"


can_msgs::Frame constructVersionNumberMsg(uint16_t UnitID, unsigned int Major, unsigned int Minor, unsigned int Build)
{
    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_VERSION_RESP;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;
	VersionRespMsg_t data;
    data.raw.signals.id = UnitID;
    data.raw.signals.major = Major;
    data.raw.signals.minor = Minor;
    data.raw.signals.build = Build;
    memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

    return can_msg;
}


VersionRespMsg_t interpretVersionNumberMsg(can_msgs::Frame can_msg)
{
	VersionRespMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
    
    return frame;
}


can_msgs::Frame constructResetRequestMsg(uint16_t reset_unit_id, uint16_t shutdown_unit_id)
{
    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_RESET_REQ;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 4;
	ResetReqMsg_t data;
    data.raw.signals.reset = reset_unit_id;
    data.raw.signals.shutdown = shutdown_unit_id;
    memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

    return can_msg;
}


ResetReqMsg_t interpretResetRequestMsg(can_msgs::Frame can_msg)
{
    assert(can_msg.id == CAN_ID_RESET_REQ);
	ResetReqMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);

    return frame;
}


can_msgs::Frame constructResetCauseMsg(uint32_t CAN_ID, uint16_t ResetReason)
{
    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 2;
	ResetCauseMsg_t data;
    data.raw.signals.cause = ResetReason;
    memcpy(&(can_msg.data[0]), data.raw.buf, can_msg.dlc);

    return can_msg;
}


uint16_t interpretResetCauseMsg(can_msgs::Frame can_msg)
{
	ResetCauseMsg_t data;
    memcpy(data.raw.buf, &(can_msg.data[0]), can_msg.dlc);

    return data.raw.signals.cause;
}


DriveInfo500kWpMsg_t interpretDriveInfo10KMsg(can_msgs::Frame can_msg)
{
    assert(can_msg.id == CAN_ID_DRIVE_INFO);
	DriveInfo500kWpMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	DriveInfo500kWpMsg_FromCan(&frame);
    
    return frame;
}


DriveInfoLongWpMsg_t interpretDriveInfoLongWpMsg(can_msgs::Frame can_msg)
{
    assert(can_msg.id == CAN_ID_DRIVE_INFO_LONG_WP);
	DriveInfoLongWpMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	DriveInfoLongWpMsg_FromCan(&frame);
    
    return frame;
}


StartupStatusMsg_t interpretStartUpStatusMsg(can_msgs::Frame can_msg)
{
	StartupStatusMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
    
    return frame;
}


