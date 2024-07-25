// 열혈 자료구조 p.177
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee * WhoNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
    int i;
    Employee * pemp;

    // Create and Initialize List
    List list;
    ListInit(&list);

    // Save Information of 4 people
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empNum = 1111;
    strcpy(pemp->name, "Terry");
    LInsert(&list, pemp);

    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empNum = 2222;
    strcpy(pemp->name, "Jery");
    LInsert(&list, pemp);

    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empNum = 3333;
    strcpy(pemp->name, "Hary");
    LInsert(&list, pemp);

    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empNum = 4444;
    strcpy(pemp->name, "Sunny");
    LInsert(&list, pemp);

    // Who is Worker on duty after 3 day from Terry's Duty day
    // => Who is on duty three days after Terry's shift?
    pemp = WhoNightDuty(&list, "Terry", 3);
    ShowEmployeeInfo(pemp);

    // => Who is on duty fifteen days after Sunny's shift?
    pemp = WhoNightDuty(&list, "Sunny", 15);
    ShowEmployeeInfo(pemp);

    // Free Memory
    if(LFirst(&list, &pemp))
    {
        free(pemp);

        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &pemp))
            {
                free(pemp);
            }   
        }
    }
   
    return 0;
}

Employee * WhoNightDuty(List * plist, char * name, int day)
{
    int i, num;
    Employee * ret;

    num = LCount(plist);

    // Finding Name;
    LFirst(plist, &ret);

    if(strcmp(ret->name, name))
    {
        for(i=0; i<num-1; i++)
        {
            LNext(plist, &ret);

            if(!strcmp(ret->name, name)==0)
            {
                break;
            }
        }
        if(i>=num-1)    // No Key Name
        {
            return NULL;
        }
    }

    // After The Day //////
    for(i=0; i<day; i++)
    {
        LNext(plist, &ret);
    }

    return ret;
}

void ShowEmployeeInfo(Employee * emp)
{
    printf("Employee Name: %s \n", emp->name);
    printf("Employee Id: %d \n\n", emp->empNum);
}