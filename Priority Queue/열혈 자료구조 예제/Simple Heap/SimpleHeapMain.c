// 열혈 자료구조 p.351
#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
    Heap heap;
    HeapInit(&heap);        // Initialize heap

    HInsert(&heap, 'A', 1);     // Save character 'A' as highest priority
    HInsert(&heap, 'B', 2);     // Save character 'B' as 2nd priority
    HInsert(&heap, 'C', 3);     // Save character 'C' as 3rd priority
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A', 1);     // One more time!
    HInsert(&heap, 'B', 2);     // One more time!
    HInsert(&heap, 'C', 3);     // One more time!
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
    {
        printf("%c \n", HDelete(&heap));
    }

    return 0;
}