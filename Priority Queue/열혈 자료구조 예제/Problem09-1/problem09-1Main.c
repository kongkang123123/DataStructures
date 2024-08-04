// 열혈 자료구조 p.370
#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2)
{
    return (strlen(str2) - strlen(str1));
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "A");
    PEnqueue(&pq, "BCD");
    PEnqueue(&pq, "EF");

    while(!PQIsEmpty(&pq))
    {
        printf("%s \n", PDequeue(&pq));
    }

    return 0;
}