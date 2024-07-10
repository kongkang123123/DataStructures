// 윤성우의 열혈 자료구조 p.129
// 더미 노드 기반의 정렬 삽입 + 정렬 사입 기준 변경 가능한 연결 리스트
// + p.143 문제 04-3 수행하기
#ifndef __D_LINKED_LIST_H__
#define __D_LINEKD_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
} Node;

typedef struct _linkeedList
{
    Node * head;                        // 더미 노드를 가리키는 멤버
    Node * cur;                         // 참조 및 삭제를 돕는 멤버
    Node * before;                      // 삭제를 돕는 멤버
    int numOfData;                      // 저장된 데이터의 수를 기록하기 위한 멤버
    int (*comp)(LData d1, LData d2);    // 정렬의 기준을 등록하기 위한 멤버
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);    // 첫번째 노드: 더미 노드 다음에 연결된 노드
void SInsert(List * plist, LData data);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif