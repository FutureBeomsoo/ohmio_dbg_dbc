#pragma once


#include "dbc_MsgID_main.h"
extern "C"
{
	#include "dbc_CAN.h"
}
#include "RosMessages.hpp"



can_msgs::Frame constructSteerObservedMsg(uint32_t can_id,
    float steer_angle, 
    uint8_t status, 
	uint8_t calibrationSet,
	bool sensorFailed,
	uint8_t factorSet,
    uint8_t heart_beat, 
    int8_t temperature, 
    uint32_t timestamp)
{
    can_msgs::Frame can_msg;
    can_msg.id = can_id;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;

	SteeringStatusMsg_t frame;
    frame.angle = steer_angle;
    frame.raw.signals.status = status;
	frame.raw.signals.calibrationSet = calibrationSet;
	frame.raw.signals.sensorFailed = sensorFailed;
	frame.raw.signals.factorSet = factorSet;
    frame.raw.signals.heartbeat = heart_beat;
    frame.temperature = temperature;
    frame.raw.signals.time = timestamp;
	SteeringStatusMsg_ToCan(&frame);

    memcpy(&(can_msg.data[0]), frame.raw.buf, can_msg.dlc);

    return can_msg;
}


SteeringStatusMsg_t interpretSteerObservedMsg(const can_msgs::Frame & can_msg)
{
    assert(can_msg.id == CAN_ID_STEERING || can_msg.id == CAN_ID_STEERING2);
	SteeringStatusMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	SteeringStatusMsg_FromCan(&frame);

    return frame;
}









can_msgs::Frame constructSteerRequestedMsg(uint32_t can_id,
                                                                                                    float steer_angle, 
                                                                                                    uint8_t steer_speed, 
                                                                                                    uint8_t heart_beat, 
                                                                                                    uint32_t timestamp)
{
    can_msgs::Frame can_msg;
    can_msg.id = can_id;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;

	SteeringReqMsg_t frame;
    frame.angle = steer_angle;
    frame.raw.signals.speed = steer_speed;
    frame.raw.signals.counter = heart_beat;
    frame.raw.signals.time = timestamp;
	SteeringReqMsg_ToCan(&frame);

    memcpy(&(can_msg.data[0]), frame.raw.buf, can_msg.dlc);

    return can_msg;
}


SteeringReqMsg_t interpretSteerRequestedMsg(const can_msgs::Frame & can_msg)
{
    assert(can_msg.id == CAN_ID_F_STEER_REQ || can_msg.id == CAN_ID_R_STEER_REQ);
	SteeringReqMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	SteeringReqMsg_FromCan(&frame);

    return frame;
}

















can_msgs::Frame constructWheelSpeedRequestedMsg(float left_speed, 
                                                                                                                   float right_speed, 
                                                                                                                   SYS_STATES drive_mode, 
                                                                                                                   bool braking_flag, 
                                                                                                                   bool reverse_flag, 
                                                                                                                   uint32_t timestamp)
{
    can_msgs::Frame can_msg;
    can_msg.id = CAN_ID_SPEED_REQ;
    //can_msg.header.stamp = ros::Time::now();
    can_msg.dlc = 8;

	MotorReqMsg_t frame;
    frame.leftSpeed = left_speed;
    frame.rightSpeed = right_speed;
    frame.raw.signals.mode = drive_mode;
    frame.raw.signals.brake = braking_flag;
    frame.raw.signals.reverse = reverse_flag;
    frame.raw.signals.time = timestamp;
	MotorReqMsg_ToCan(&frame);

    memcpy(&(can_msg.data[0]), frame.raw.buf, can_msg.dlc);

    return can_msg;
}


MotorReqMsg_t interpretWheelSpeedRequestedMsg(const can_msgs::Frame & can_msg)
{
    assert(can_msg.id == CAN_ID_SPEED_REQ);
	MotorReqMsg_t frame;
    memcpy(frame.raw.buf, &(can_msg.data[0]), can_msg.dlc);
	MotorReqMsg_FromCan(&frame);

    return frame;
}