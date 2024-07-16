// 열혈 자료구조 p.213
#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
    // Create and Initialize Stack
    Stack stack;
    StackInit(&stack);

    // Push Data
    SPush(&stack, 1); SPush(&stack, 2);
    SPush(&stack, 3); SPush(&stack, 4);
    SPush(&stack, 5);

    // Pop Data;
    while(!SIsEmpty(&stack))
    {
        printf("%d ", SPop(&stack));
    }

    return 0;
}