#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node        // Structure for expressing Linked List
{
    Data data;
    struct _node * next;
} Node;

typedef struct _listStack   // Structure for expressing Stack based Linked List
{
    Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);         // Initialize Stack
int SIsEmpty(Stack * pstack);           // Check Stack is Empty or Not

void SPush(Stack * pstack, Data data);  // Push operation of Stack
Data SPop(Stack * pstack);              // Pop operation of Stack
Data SPeek(Stack * pstack);             // Peek operation of Stack

#endif