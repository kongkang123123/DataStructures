// 필요한 함수만 호출하면 됨.
// 그래서 밑 헤더파일만 include해줌.
#include "DequeBaseQueue.h"

void QueueInit(Queue * pq)
{
    DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
    return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
    DQAddLast(pq, data);    // 큐는 뒤로 들어가서 앞으로 나오는 구조
}

Data Dequeue(Queue * pq)
{
    return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq)
{
    return DQGetFirst(pq);
}