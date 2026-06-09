
#ifndef CAN_BUFFER_H
#define CAN_BUFFER_H
#pragma once
#include <stdint.h>
#include <string.h>

#ifndef CAN_BUFFER_SIZE
    #define CAN_BUFFER_SIZE 128		// the buffer must be big enough to hold all messages before it reads out 
#endif

typedef struct
{
	int id;
    int32_t eid;
	unsigned char data[8];
	uint8_t length;
} CAN_MSG_t;

typedef struct
{
	CAN_MSG_t mem[CAN_BUFFER_SIZE];
    unsigned char rIndex, wIndex;
} CAN_BUFFER_t;


extern CAN_BUFFER_t inputCanBuffer;
extern CAN_BUFFER_t outputCanBuffer;
extern CAN_BUFFER_t inputExtIDCanBuffer;
extern CAN_BUFFER_t outputExtIDCanBuffer;

void can_buffer_init(CAN_BUFFER_t *buf);
void can_buffer_write(CAN_BUFFER_t *buf, int id, unsigned char *bytes, uint8_t n);
uint8_t can_buffer_read(CAN_BUFFER_t *buf, CAN_MSG_t *rdBuf);
void can_buffer_write_extID(CAN_BUFFER_t *buf, int32_t id, unsigned char *bytes, uint8_t n);
uint8_t can_buffer_read_extID(CAN_BUFFER_t *buf, CAN_MSG_t *rdBuf);
void can_buffer_clear(CAN_BUFFER_t *buf);

#endif
