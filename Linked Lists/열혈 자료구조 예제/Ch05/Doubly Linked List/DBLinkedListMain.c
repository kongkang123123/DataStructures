// 열혈 자료구조 p.182
#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
    // Create and Initialize Doubly Linked List
    List list;
    int data;
    ListInit(&list);

    // Save 8 Data
    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);

    // Check Saved Data
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        // Check Data Moving Right
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }

        // Check Data Moving Left
        while(LPrevious(&list, &data))
        {
            printf("%d ", data);
        }

        printf("\n\n");
    }

    return 0;
}