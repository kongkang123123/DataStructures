// 열혈 자료구조 p.411
// 사실 pivot을 배열의 중간에 해당하는 값으로 결정할 때, 좋은 성능 보임
// 피벗이 중간값에 해당하는 값일 경우, 정렬 대상이 균등하게 나뉘기 때문
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int MedianOfThree(int arr[], int left, int right)
{
    int samples[3] = {left, (left+right)/2, right}; // Organize array as index value

    if(arr[samples[1]]<arr[samples[0]])
    {
        Swap(samples, 0, 1);    
    }

    if(arr[samples[2]] < arr[samples[1]])
    {
        Swap(samples, 1, 2);
    }
    if(arr[samples[1]] < arr[samples[0]])
    {
        Swap(samples, 0, 1);
    }

    return samples[1];
}

int Partition(int arr[], int left, int right)
{
    int pIdx = MedianOfThree(arr, left, right);
    int pivot = arr[pIdx];  // Position of pivot is leftmost

    int low = left+1;
    int high = right;

    printf("Pivot: %d \n", pivot);

    Swap(arr, left, pIdx);  // Move pivot to the left

    while(low <= high)  // Repeat until it does not corss
    {
        // Finding larger value than pivot
        while(arr[low] <= pivot && low <= right)
        {
            low++;  // Move low to the right
        }

        // Finding smaller value than pivot
        while(pivot <= arr[high] && (left+1) <= high)
        {
            high--; // Move high to the left
        }

        // If it does not cross, execute Swap()
        if(low <= high)
        {
            Swap(arr, low, high);
        }
    }

    Swap(arr, left, high);      // Interchange pivot and the target that high point to
    return high;                // Return position for the moved pivot
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);    // in two parts
        QuickSort(arr, left, pivot-1);              // Arrange left part
        QuickSort(arr, pivot+1, right);             // Arrange right part
    }
}

int main(void)
{
    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    int len = sizeof(arr)/sizeof(int);
    int i;

    QuickSort(arr, 0, len - 1);

    for(i=0; i<len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}