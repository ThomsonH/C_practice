#include "Queue_Embedded.h"

uint8_t Rxbuffer[RXBUFFER_LENGTH];


int main(int argc, char *argv[])
{
	Queue *RxQueue = CreateQueue(Rxbuffer, sizeof(Rxbuffer));

	for(int i = 0; i <25; i++)
		enQueue(RxQueue, 30+i);

	for(int i = 0; i < 15; i++)
		printf("deQueue is %d\r\n", deQueue(RxQueue));

	printf("front is %d \r\n", isFront(RxQueue));
	printf("rear is %d \r\n", isRear(RxQueue));
	for(int i = 0; i < sizeof(Rxbuffer); i++)
		printf("Rxbuffer[%d] = %d\r\n", i, Rxbuffer[i]);
	return 0;
}


Queue* CreateQueue(uint8_t* ptr, unsigned capacity)
{
	
	Queue* queue = (Queue*) malloc(sizeof(Queue)); 
	queue->size = capacity;
	queue->front = -1;
	queue->rear = -1;
	queue->ptr = ptr;
	return queue;
}

QueueState enQueue( Queue *queue, uint8_t item)
{
	if(((queue->front == 0) && (queue->rear == queue->size - 1))|| (queue->rear == (queue->front - 1) % (queue->size - 1))) 
	{
		printf("Queue is full\r\n");
		return STATE_FULL;
	}
	else if(queue->front == -1)
	{
		queue->front = queue->rear = 0;
		queue->ptr[queue->rear] = item;
	}
	else if((queue->rear == queue->size - 1) && (queue->front != 0))
	{
		queue->front = queue->rear = 0;
		queue->ptr[queue->rear] = item;
	}
	else
	{
		queue->rear = queue->rear + 1;
		queue->ptr[queue->rear] = item;
	}

}
uint8_t deQueue( Queue *queue)
{
	if(queue->front == -1)
	{
		printf("Queue is Empty\r\n");
		return STATE_EMPTY;
	}
	uint8_t data = queue->ptr[queue->front];
	queue->ptr[queue->front] = -1;
	if(queue->front == queue->rear)
	{
		queue->front = -1;
		queue->rear = -1;
	}
	else if(queue->front == queue->size - 1)
		queue->front = 0;
	else
	{
		queue->front = queue->front + 1;
	}
	return data;
	
}
uint32_t isFull(Queue *que)
{
	return que->size  == que->capacity;
}
uint32_t isEmpty(Queue *que)
{
	return que->size == 0;
}
uint32_t isFront(Queue *que)
{
	if(isEmpty(que))
		return 0;
	return que->ptr[que->front];
}
uint32_t isRear(Queue *que)
{
	if(isEmpty(que))
		return 0;
	return que->ptr[que->rear];
}

/************************ (C) COPYLEFT *****END OF FILE****/
