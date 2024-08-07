// 열혈 자료구조 p.386
#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
    return (n2 - n1);   // Sorting for ascending order
 // return (n1 - n2);   //       ""    descending order
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    // Organize Heap with sorting target
    for (i = 0; i < n; i++)
    {
        HInsert(&heap, arr[i]);
    }
    
    for(i=0; i<n; i++)
    {
        arr[i] = HDelete(&heap);
    }
}

int main(void)
{
    int arr[4] = {3, 4, 2, 1};
    int i;

    HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);

    for(i=0; i<4; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}