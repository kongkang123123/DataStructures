#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE        1
#define FALSE       0
#define STACK_LEN   100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);         // Initialize Stack
int SIsEmpty(Stack * pstack);           // Check Stack is Empty

void SPush(Stack * pstack, Data data);  // Push operation of Stack
Data SPop(Stack * pstack);              // Pop operation of Stack
Data SPeek(Stack * pstack);             // Peek operation of Stack

#endif