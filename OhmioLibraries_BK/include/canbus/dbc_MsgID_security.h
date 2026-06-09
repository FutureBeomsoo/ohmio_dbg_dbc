#pragma once


typedef enum
{
    CAN_ID_COLLISION_EVENT_INFO    =    0x480019B,    //    CollisionEventInfo:  bits0-7: counter; bits8-15: remoteID; bits16-23: distance; bits24-27: direction; bits28-31: status; bits32-63: timestamp; 
    CAN_ID_COLLISION_EVENT_CONFIG1    =    0x484019B,    //    CollisionEventConfig1:  bits0-7: maxSpeedW; bits8-15: maxSpeedInfo; 
} COMMON_CAN_S;
