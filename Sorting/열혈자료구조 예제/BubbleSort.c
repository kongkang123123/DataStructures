// 열혈 자료구조 p.376
#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<(n-i)-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // Change data
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[4] = {3,2,1,4};
    int i;

    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}