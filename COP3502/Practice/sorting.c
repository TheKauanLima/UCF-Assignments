#include <stdio.h>
#include <stdlib.h>

void copy(int* src, int* dst, int n)
{
    for (int i = 0; i < n; i++)
    {
        dst[i] = src[i];
    }
}

void swap(int* a1, int* a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

void printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minVal = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minVal])
                minVal = j;
        }
        swap(&arr[i], &arr[minVal]);
    }
}

void insertionSort(int* arr, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        int hand = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > hand)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = hand;
    }
}

void bubbleSort(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
                swap(&arr[j + 1], &arr[j]);
        }
    }
}

void merge(int* arr, int l, int m, int r)
{
    int sizeL = m - l + 1;
    int sizeR = r - m;

    int* L = (int*)malloc(sizeof(int) * sizeL);
    int* R = (int*)malloc(sizeof(int) * sizeR);

    for (int i = 0; i < sizeL; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < sizeR; i++)
        R[i] = arr[m + i + 1];

    int i = 0;
    int j = 0;
    int k = l;
    while(i < sizeL && j < sizeR)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < sizeL)
        arr[k++] = L[i++];

    while(i < sizeL)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(void)
{
    int size = 7;
    int unsorted[7] = { 5, 8, 10, 9 , 11, 3, 25 };
    int sorted[7];

    copy(unsorted, sorted, size);

    printf("unsorted: ");
    printArray(sorted, size);

    printf("insertion: ");
    insertionSort(sorted, size);
    printArray(sorted, size);

    printf("selection: ");
    copy(unsorted, sorted, size);
    selectionSort(sorted, size);
    printArray(sorted, size);

    printf("bubble: ");
    copy(unsorted, sorted, size);
    bubbleSort(sorted, size);
    printArray(sorted, size);

    printf("merge: ");
    copy(unsorted, sorted, size);
    mergeSort(sorted, 0, size - 1);
    printArray(sorted, size);
}