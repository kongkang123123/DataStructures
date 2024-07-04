#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
    List list;
    NameCard * pcard;
    ListInit(&list);    // 처음에 List Initialize해주기.

    pcard = MakeNameCard("Minseong", "010-1111-1111");
    LInsert(&list, pcard);

    pcard = MakeNameCard("Wonsik", "010-2222-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("Eunseop", "010-3333-3333");
    LInsert(&list, pcard);

    // Minseong의 정보를 조회하여 출력
    if(LFirst(&list, &pcard)) 
    {
        if(!NameCompare(pcard, "Minseong"))
        {
            ShowNameCardInfo(pcard);
        }
        
        else
        {
            while(LNext(&list, &pcard))
            {
                if(!NameCompare(pcard, "Minseong"))
                {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    // Eunseop의 정보를 변경
    if(LFirst(&list, &pcard))
    {
        if(!NameCompare(pcard, "Eunseop"))
        {
            ChangePhoneNum(pcard, "010-1234-1234");
        }
        
        else
        {
            while(LNext(&list, &pcard))
            {
                if(!NameCompare(pcard, "Eunseop"))
                {
                    ChangePhoneNum(pcard, "010-1234-1234");
                    break;
                }
            }
        }
    }

    // Wonsik의 정보를 삭제
    if(LFirst(&list, &pcard))
    {
        if(!NameCompare(pcard, "Wonsik"))
        {
            pcard = LRemove(&list);
            free(pcard);
        }

        else
        {
            while(LNext(&list, &pcard))
            {
                if(!NameCompare(pcard, "Wonsik"))
                {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    // 모든 사람의 정보 출력
    printf("The number of data: %d\n", LCount(&list));

    if(LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while(LNext(&list, &pcard))
        {
            ShowNameCardInfo(pcard);
        }
    }

    return 0;
}