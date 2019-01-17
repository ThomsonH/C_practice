#include "Queue.h"

int main(int argc, char **argv)
{
    printf("In this part, will show you how to use queue....\r\n");

    struct Queue *Qptr = newQueue(10);

    push(Qptr, 1);
    push(Qptr, 2);
    push(Qptr, 3);
    push(Qptr, 4);

    displayQueue(Qptr);
    printf("fetch %d from Queue\r\n", pop(Qptr));
    printf("fetch %d from Queue\r\n", pop(Qptr));
    displayQueue(Qptr);
    printf("fetch %d from Queue\r\n", pop(Qptr));
    printf("fetch %d from Queue\r\n", pop(Qptr));
    displayQueue(Qptr);

    return 0;
}

int push(struct Queue *p, int val)
{
    if (p->size == p->maxsize)
        return -3;

    p->rear = (p->rear + 1) % p->maxsize; //enqueue and point out the data insert index.
    p->data[p->rear] = val;
    p->size++;
    return 0;
}

int pop(struct Queue *p)
{
    int ret;
    if (isEmpty(p))
        return -4;

    ret = p->data[p->front];
    p->front = (p->front + 1) % p->maxsize;
    p->size--;

    return ret;
}

/*---------------------------------------------------------
    return the result
    if the Queue is empty return 1, or return 0.    
---------------------------------------------------------*/
int isEmpty(struct Queue *p)
{
    return (p->size == 0);
}
int front(struct Queue *p)
{
    if (isEmpty(p))
    {
        return -1;
    }
    else
    {
        return p->data[p->front];
    }
}
int rear(struct Queue *p)
{
    if (isEmpty(p))
    {
        return -2;
    }
    else
    {
        return p->data[p->rear];
    }
}

void displayQueue(struct Queue *p)
{
    printf("------------Display Queue Start------------\r\n");
    if (isEmpty(p))
    {
        printf("Queue is Empty\r\n");
        return;
    }

    if (p->rear >= p->front)
    {
        for (int i = p->front; i <= p->rear; i++)
            printf("Element %d in position %d \r\n", p->data[i], i);
    }
    else
    {
        for (int i = p->front; i <= p->maxsize; i++)
            printf("Element %d in position %d \r\n", p->data[i], i);
        for (int i = 0; i <= p->rear; i++)
            printf("Element %d in position %d \r\n", p->data[i], i);
    }
    printf("------------Display Queue End------------\r\n");
}