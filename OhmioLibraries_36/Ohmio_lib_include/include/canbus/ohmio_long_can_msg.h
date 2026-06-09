#pragma once

// This file is to handle long message uses the same CAN ID
// can_tx_long_msg() function receives a long_can_msg_t structure with 3 pieces of information: the entire buffer to be transmitted (up to 448 bytes), 
// the length of the buffer and the can identifier. 
// This function will automatically split the long message and send the parts to the canbus.

#include <stdint.h>
#include <stdbool.h>


typedef union
{
   struct
   {
      uint8_t msg_idx :2;
      uint8_t frame_idx :6;
   };
   uint8_t b;
} byte0_t;

typedef struct
{
    uint8_t * buf;
    uint32_t length;
    uint16_t can_id;
    byte0_t b0;
} long_can_msg_t;

typedef struct
{
    union
    {
        uint8_t buf[21];
        struct
        {
            uint8_t ASCII[17];
			uint32_t dummy;
        };
    };
} vehicle_VIN_t;


//! Crate a single frame of a multi frame message
//
//! It is the caller responsibility to make sure that the dataLength is correct 
//! @param[in] data - pointer to the start of the data to send
//! @param[in] dataLength - size of the data
//! @param[in,out] start - where to start this message. Returns the start of the next message
//! @param[in,out] sync - counter of loops over the data
//! @param[out] messageOutput - 8 byte data to send over CAM
void FillMultiFrameMessage(uint8_t* data, int dataLength, int* start, int* sync, uint8_t messageOutput[8]);



//! Read a single frame of a multi frame message
//
//! It is the caller responsibility to make sure that the dataLength is correct 
//! @param[in] messageOutput - 8 byte data to send over CAM
//! @param[in] dataLength - size of the data
//! @param[out] data - pointer to the start of the data to send
//! @param[out] sync - sync from this message. 
//! @return true if we got full data
bool ReadMultiFrameMessage(uint8_t messageInput[8], int dataLength, uint8_t* data, int* sync);
