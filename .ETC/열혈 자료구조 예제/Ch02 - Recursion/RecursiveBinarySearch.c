// 열혈 자료구조 p.63
#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target) {

    if(first > last) {  // 보통 예외처리는 함수 위에 선언
        return -1;  // 탐색 실패
    }

    int mid = (first + last) / 2;     // 탐색 대상의 중앙을 찾는다.

    if(arr[mid] == target) {
        return mid;                 // 탐색된 타켓의 인덱스 값 반환
    }

    else if(arr[mid] < target) {
        first = mid + 1;
        return BSearchRecur(arr, first, last, target);
    }

    else /* arr[mid] > target */ {
        last = mid - 1;
        return BSearchRecur(arr, first, last, target);
    }
}

int main(void) {

    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 7);

    if(idx == -1) {
        printf("Failed to Search\n");
    }

    else {
        printf("Index of Target: %d\n", idx);
    }

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 4);

    if(idx == -1) {
        printf("Failed to Search\n");
    }

    else {
        printf("Index of Target: %d\n", idx);
    }

    return 0;
}