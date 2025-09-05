#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void selectionSort(int* arr)
{
    int i, j;
    int lowest = arr[0];
    for(i = 0; i < SIZE - 1; i++)
    {
        for(j = i; j < SIZE - 1; j++)
        {
            if (arr[j] < lowest)
            {
                lowest = arr[j];
            }
        }
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;

        for (int k = 0; k < SIZE - 1; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[j] < arr[j-1])
            {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
        }
    }
}

int main(void)
{
    int n = 6;
    int arr[SIZE] = { 5, 8, 2, 7, 3, 1 };
    // selectionSort(arr);
    bubbleSort(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}