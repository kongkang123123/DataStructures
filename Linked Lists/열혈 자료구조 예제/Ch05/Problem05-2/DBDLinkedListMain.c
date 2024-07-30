// 열혈 자료구조 p.191
#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
    List list;
    int data;
    ListInit(&list);

    // Save 8 data
    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);

    // Inquire about the data
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }

        printf("\n");
    }

    // Remove even numbers from the list
    if(LFirst(&list, &data))
    {
        if(data % 2 == 0)
        {
            LRemove(&list);
        }

        while(LNext(&list, &data))
        {
            if(data % 2 == 0)
            {
                LRemove(&list);
            }
        }
    }

    // Re-inquire about the data
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }

        printf("\n\n");
    }

    return 0;
}