// 윤성우의 열혈 자료구조 p.82
#include <stdio.h>
#include "ArrayList.h"

int main(void) {
    // 문제 03-1. 1번: ArrayList의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsert(&list, 9);

    // 문제 03-01. 2번: 저장된 값의 합 계산하여 출력
    int sum = 0;
    if(LFirst(&list, &data))
    {
        sum += data;
        while(LNext(&list, &data))
        {
            sum += data;
        }
    }
    printf("Total: %d\n", sum);

    // 문제 03-01. 3번: 2또는 3의 배수의 데이터 삭제
    if(LFirst(&list, &data)) 
    {
       if(data % 2 == 0 || data % 3 == 0) 
       {
            LRemove(&list);
       }

       while(LNext(&list, &data)) {
            if(data % 2 == 0 || data % 3 == 0) 
            {
                LRemove(&list);
            }
        }
    }

    // 문제 03-01. 4번: 리스트에 저장된 데이터 순서대로 출력
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    
    return 0;
}