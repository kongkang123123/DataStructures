// 열혈 자료구조 p.406
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];  // Position of pivot is leftmost
    int low = left+1;
    int high = right;

    while(low <= high)  // Repeat until it does not corss
    {
        // Finding larger value than pivot
        while(arr[low] < pivot)
        {
            low++;  // Move low to the right
        }

        // Finding smaller value than pivot
        while(pivot < arr[high])
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
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
  //int arr[3] = {3, 3, 3};

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