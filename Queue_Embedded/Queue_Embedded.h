#ifndef __QUEUE_H
#define __QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>

#define uint8_t   unsigned char
#define uint16_t  unsigned short
#define uint32_t  unsigned int
#define int32_t   int

#define RXBUFFER_LENGTH	64

extern uint8_t Rxbuffer[RXBUFFER_LENGTH];


typedef enum{
	STATE_OK,
	STATE_ERR,
	STATE_FULL,
	STATE_EMPTY
}QueueState;

typedef struct
{
	int32_t front, rear, size;
	uint32_t capacity;
	uint8_t *ptr;
}Queue;


Queue* CreateQueue(uint8_t* ptr, unsigned capacity);
QueueState enQueue( Queue *queue, uint8_t item);
uint8_t deQueue( Queue *queue);

uint32_t isFull(Queue *que);
uint32_t isEmpty(Queue *que);
uint32_t isFront(Queue *que);
uint32_t isRear(Queue *que);

void Queue_task(Queue *queue);


#ifdef __cplusplus
}
#endif

#endif /* __QUEUE_H */
