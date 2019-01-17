#ifndef STACK__H
#define STACK__H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *newStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
};

int isFull(struct Stack *p);
int isEmpty(struct Stack *p);
int push(struct Stack *p, int val);
int pop(struct Stack *p);

#endif