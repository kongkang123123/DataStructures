// 윤성우의 열혈 자료구조 p.28
// 이진 탐색 알고리즘을 순차 탐색 알고리즘과 비교하는 예제
// 순차 탐색 알고리즘의 비교연산의 횟수: n    O(n)

#include <stdio.h>

int BSearch(int arr[], int len, int target) {
    
    int first = 0;
    int last = len - 1;
    int mid;
    int opCount = 0;        // 비교연산의 횟수를 기록

    while(first <= last) {
        mid = (first+last)/2;

        if(target == arr[mid]) {
            return mid;
        }

        else {
            if(target < arr[mid]){
                last = mid - 1;
            }
            else /* target > arr[mid] */ {
                first = mid + 1;
            }
        }
        opCount += 1;       // 비교연산의 횟수 1 증가
    }

    printf("The Number of Counting: %d\n", opCount);    // 탐색 실패 시 연산횟수 출력
    return -1;
}

int main(void) {

    int arr1[500] = {0,};       // 모든 요소 0으로 초기화
    int arr2[5000] = {0,};      // 모든 요소 0으로 초기화
    int arr3[50000] = {0,};     // 모든 요소 0으로 초기화
    int idx;

    // 배열 arr1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    idx = BSearch(arr1, sizeof(arr1)/sizeof(arr1[0]), 1);
    
    if(idx == -1) {
        printf("Faile to Search\n\n");
    }
    else {
        printf("Index of Target: %d\n", idx);
    }

    // 배열 arr2을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    idx = BSearch(arr2, sizeof(arr2)/sizeof(arr2[0]), 1);
    
    if(idx == -1) {
        printf("Faile to Search\n\n");
    }
    else {
        printf("Index of Target: %d\n", idx);
    }

    // 배열 arr3을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    idx = BSearch(arr3, sizeof(arr3)/sizeof(arr3[0]), 1);
    
    if(idx == -1) {
        printf("Faile to Search\n\n");
    }
    else {
        printf("Index of Target: %d\n", idx);
    }

    return 0;
}