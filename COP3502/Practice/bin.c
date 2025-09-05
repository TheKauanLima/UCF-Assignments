#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 12

int binarySearch(int* arr, int key, int size)
{
    int l = 0, r = size - 1, m;

    while (l <= r)
    {
        m = (l + r) / 2;

        if (key == arr[m])
            return m;
        else if (key > arr[m])
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int binarySearchRec(int* arr, int l, int r, int key)
{
    if (l > r)
        return -1;

    int m = (l + r) / 2;

    if (key == arr[m])
        return m;
    else if (key > arr[m])
        return binarySearchRec(arr, m + 1, r, key);
    else
        return binarySearchRec(arr, l, m - 1, key);
}

void SLMP1(int* arr1, int* arr2, int arr1s, int arr2s)
{
    printf("slmp1: ");
    for (int i = 0; i < arr1s; i++)
        for (int j = 0; j < arr2s; j++)
            if (arr1[i] == arr2[j])
            {
                printf("%d ", arr1[i]);
                break;
            }
    printf("\n");
}

void SLMP2(int* arr1, int* arr2, int arr1s, int arr2s)
{
    printf("slmp2: ");
    for (int i = 0; i < arr1s; i++)
        if (binarySearchRec(arr2, 0, arr2s - 1, arr1[i]) != -1)
            printf("%d ", arr1[i]);
    printf("\n");
}

void SLMP3(int* arr1, int* arr2, int arr1s, int arr2s)
{
    printf("slmp3: ");
    int i = 0, j = 0;

    while (i < arr1s && j < arr2s)
    {
        if (arr1[i] == arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
            j++;
        else if (arr1[i] < arr2[j])
            i++;
    }
}

int main(void)
{
    int arr1[SIZE] = { 1, 3, 5, 7, 18, 19, 23, 27, 29, 30, 36, 50 };
    int arr2[SIZE - 1] = { 1, 4, 5, 9, 18, 19, 24, 25, 31, 32, 36 };
    printf("bin iter: %d\n", binarySearch(arr1, 36, SIZE));
    printf("bin rec: %d\n\n", binarySearchRec(arr1, 0, SIZE - 1, 50));

    SLMP1(arr1, arr2, SIZE, SIZE);
    SLMP2(arr1, arr2, SIZE, SIZE - 1);
    SLMP3(arr1, arr2, SIZE, SIZE - 1);
}