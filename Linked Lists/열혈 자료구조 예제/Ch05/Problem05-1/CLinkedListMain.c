// 열혈 자료구조 p.162
// + data는 복수형
#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
    // Create and Initialize Circular Linked List
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    // Save 5 Data in List
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    // print data 3 times
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)*3 - 1; i++)
        {
            if(LNext(&list, &data))
            {
                printf("%d ", data);
            }
        }
    }
    printf("\n");

    // Remove even Numbers
    nodeNum = LCount(&list);

    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
        {
            LRemove(&list);
        }

        for(i=0; i<nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
            {
                LRemove(&list);
            }
        }
    }

    // Print all data once
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
            {
                printf("%d ", data);
            }
        }
    }

    return 0;
}