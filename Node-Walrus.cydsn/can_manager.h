#ifndef CAN_MANAGER_H
#define CAN_MANAGER_H


#include <project.h>
#include <stdio.h>
#include "data.h"



void can_init();

uint8_t can_test_send(uint16_t ID,uint8_t msg[8]);

//void can_get(DataPacket* data_queue, uint16_t* data_head, uint16_t* data_tail);
/*
void wrap_data_queue(uint16_t* data_head, uint16_t* data_tail);

inline void process_default(DataPacket* data_queue, uint16_t* data_head,
	uint16_t* data_tail);

inline void process_throttle(DataPacket* data_queue, uint16_t* data_head,
	uint16_t* data_tail);
*/
#endif
