#include "stack.h"

int main(int argc, char **argv)
{
    struct Stack *p = newStack(100);

    push(p, 11);
    push(p, 12);
    push(p, 13);
    push(p, 14);
    push(p, 15);

    int popout = 0;
    printf("input pop times :");
    scanf("%d", &popout);
    while (popout--)
    {
        int ret = pop(p);
        if (ret < 0)
            printf("Stack is empty\r\n");
        if(ret >= 0)
            printf("%d popped from stack \r\n", ret);
    }

    return 0;
}

int isFull(struct Stack *p)
{
    return p->top == p->capacity - 1;
}
int isEmpty(struct Stack *p)
{
    return p->top == -1;
}
int push(struct Stack *p, int val)
{
    if (isFull(p))
        return -1;
    p->array[++p->top] = val;
    return 0;
}
int pop(struct Stack *p)
{
    if (isEmpty(p))
        return -2;
    return p->array[p->top--];
}
