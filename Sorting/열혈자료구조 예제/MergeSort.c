// 열혈 자료구조 p.393
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1;
    int i;

    // 병합 한 결과를 담을 배열 sortArr의 동적 할당
    int * sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left;

    while(fIdx <= mid && rIdx <= right)
    {
        // 병합 할 두 영역의 데이터들을 비교하여,
        // 정렬순서대로 sortArr에 하나씩 옮겨 담는다.
        if(arr[fIdx] <= arr[rIdx])
        {
            sortArr[sIdx] = arr[fIdx++];
        }
        else
        {
            sortArr[sIdx] = arr[rIdx++];
        }

        sIdx++;
    }

    // 이후엔 비교가 무의미해짐. 반으로 나눴을때, part1과 part2 모두 정렬이 되어있는 상태이기 때문
    if(mid < fIdx)  // 배열의 앞부분이 모두 sortArr에 옮겨졌다면,
    {
        for(i=rIdx; i<=right; i++, sIdx++)  // 배열의 뒷부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
        {
            sortArr[sIdx] = arr[i];
        }
    }
    else            // 배열의 뒷부분이 모두 sortArr에 옮겨졌다면,
    {
        for(i=fIdx; i<=mid; i++, sIdx++)    // 배열의 앞부분에 남은 데이터들을 sortArr에 그대로 옮긴다.
        {
            sortArr[sIdx] = arr[i];
        }
    }

    for(i=left; i<=right; i++)
    {
        arr[i] = sortArr[i];
    }

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left+right)/2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void)
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    int i;

    MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(i=0; i<7; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}