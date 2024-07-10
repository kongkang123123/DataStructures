// 윤성우의 열혈 자료구조 p.127
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;
    int readData;

    head = (Node*)malloc(sizeof(Node)); // 추가 된 문장, 더미 노드 추가
    tail = head;

    // 데이터를 입력 받는 과정
    while(1)
    {
        printf("Input Number: ");
        scanf("%d", &readData);
        
        if(readData < 1)
        {
            break;
        }

        // 노드의 추가과정
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }
    printf("\n");

    // 입력받은 데이터의 출력과정
    printf("Print datas\n");

    if(head == NULL)
    {
        printf("No saved data");
    }
    else
    {
        cur = head;
        while(cur->next!=NULL)          // 두 번째 이후의 데이터 출력
        {
            cur=cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");

    // 메모리의 해제 과정
    if(head == NULL)
    {
        return 0;           // 해제할 노드가 존재하지 않음.
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        while(delNextNode != NULL)  // 두 번째 이후 노드 삭제
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("Remove %d\n", delNode->data);
            free(delNode);
        }
    }

    return 0;
}