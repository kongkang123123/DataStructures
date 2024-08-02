#include "SimpleHeap.h"

void HeapInit(Heap * ph)    // Initialize heap
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)     // Check if heap is empty
{
    if(ph->numOfData == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int GetParentIDX(int idx)   // Return parent node index
{
    return (idx/2);
}

int GetLChildIDX(int idx)   // Return left child index
{
    return (idx*2);
}

int GetRChildIDX(int idx)   // Return right child inde
{
    return (GetLChildIDX(idx) + 1);
}

// Return the child node index of the higher priority of two child nodes
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)
    {
        return 0;
    }
    else if (GetLChildIDX(idx) == ph->numOfData)
    {
        return GetLChildIDX(idx);
    }
    else
    {
        if(ph->heapArr[GetLChildIDX(idx)].pr
            > ph->heapArr[GetRChildIDX(idx)].pr)
        {
            return GetRChildIDX(idx);    
        }
        else
        {
            return GetLChildIDX(idx);
        }
    }
}

// Save data to Heap
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;    // 새 노드가 저장될 인덱스 값을 idx에 저장
    HeapElem nelem = {pr, data};    // 새 노드의 생성 및 초기화

    // 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
    while(idx != 1)
    {
        // 새 노드와 부모 노드의 우선순위 비교
        if(pr < (ph->heapArr[GetParentIDX(idx)]).pr)    // 새 노드의 우선순위 높다면
        {
            // 부모 노드를 한 레벨 내림, 실제로 내림
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            // 새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스 값만 갱신
            idx = GetParentIDX(idx);
        }
        else        // 새 노드의 우선순위가 높지 않다면
        {
            break;
        }
    }

    ph->heapArr[idx] = nelem;   // 새 노드를 배열에 저장
    ph->numOfData += 1;
}

// Delete data from Heap
HData HDelete(Heap * ph)
{
    HData retData = (ph->heapArr[1]).data;              // 반환을 위해서 삭제할 데이터 저장
    HeapElem lastElem = ph->heapArr[ph->numOfData];     // 힙의 마지막 노드 저장

    // 아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다.
    int parentIdx = 1;  // 루트 노드가 위치해야 할 인덱스 값 저장
    int childIdx;   

    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while(childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
        {                                           // 마지막 노드의 우선순위가 높으면 반복문 탈출
            break;
        }
        // 마지막 노드보다 우선순위 높으니, 비교대상 노드의 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;       // 마지막 노드가 저장될 위치정보를 한 레벨 내림
    }   // 반복문 탈출하면 parentIDX에는 마지막 노드의 위치정보가 저장됨 

    ph->heapArr[parentIdx] = lastElem;  // 마지막 노드 최종 저장
    ph->numOfData -= 1;
    return retData;
}