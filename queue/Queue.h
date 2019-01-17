#ifndef QUEUE__H
#define QUEUE__H

#include <stdio.h>
#include <stdlib.h>

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int

struct Queue
{
    int *data;
    int front;
    int rear;
    int size;
    int maxsize;
};

/*
    Use this struct to new a stack structure.
    first, we need to know the depth of the structure which is determined by user.

    then initialize the structure, and return a pointer.
    User can use the pointer to operate the structure.
*/
struct Queue *newQueue(uint32_t Capcitor)
{
    struct Queue *ptr = NULL;

    ptr = (struct Queue *)malloc(sizeof(struct Queue));

    ptr->data = (int *)malloc(sizeof(int) * Capcitor);
    ptr->maxsize = Capcitor;
    ptr->front = 0;
    ptr->rear = -1;
    ptr->size = 0;

    return ptr;
}

/*
    the most important function
    push() : insert data into the structure.
    pop()  : fetch data from the structure.
*/
int push(struct Queue *p, int val);
int pop(struct Queue *p);

/*
    some tools we can simplify the code
*/
int isEmpty(struct Queue *p);
int front(struct Queue *p);
int rear(struct Queue *p);

// Just display the queue
void displayQueue(struct Queue *p);

#endif