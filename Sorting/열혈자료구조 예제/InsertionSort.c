// 열혈 자료구조 p.383
#include <stdio.h>

void InserSort(int arr[], int n)
{
    int i, j;
    int insData;

    for(i=1; i<n; i++)
    {
        insData = arr[i];   // Save target to insData

        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > insData)
            {
                arr[j+1] = arr[j];  // For comparison, push back one space
            }
            else
            {
                break;              // Escape
            }
        }

        arr[j+1] = insData;         // Insert sorting target in found location
    }
}

int main(void)
{
    int arr[5] = {5, 3, 2, 4, 1};
    int i;

    InserSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}