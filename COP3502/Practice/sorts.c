#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void copy(int a[], int new[])
{
    for (int i = 0; i < SIZE; i++)
        new[i] = a[i];
}

void printArr(int a[])
{
    for (int i = 0; i < SIZE - 1; i++)
        printf("%d, ", a[i]);
    printf("%d", a[SIZE - 1]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[])
{
    int i, j;
    for (i = 0; i < SIZE - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        swap(&a[min], &a[i]);
    }
}
void bubbleSort(int a[])
{
    for (int i = 0; i < SIZE - 1; i++)
        for (int j = 0; j < SIZE - 1 - i; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

void insertionSort(int a[])
{
    int i, j, item;
    for (i = 1; i < SIZE; i++)
    {
        item = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (item < a[j])
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = item;
    }
}

void merge(int a[], int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    int *L = malloc(sizeof(int) * sizeL);
    int *R = malloc(sizeof(int) * sizeR);

    for (int i = 0; i < sizeL; i++)
        L[i] = a[left + i];
    for (int i = 0; i < sizeR; i++)
        R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < sizeL && j < sizeR)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < sizeL)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeR)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int partition(int a[], int left, int right)
{
    int par = left + rand() % (right - left + 1);
    swap(&a[left], &a[par]);
    par = left;
    left++;

    while (left <= right)
    {
        while (left <= right && a[left] <= a[par])
            left++;
        while (left <= right && a[right] > a[par])
            right--;
        if (left < right)
            swap(&a[left], &a[right]);
    }
    swap(&a[par], &a[right]);
    return right;
}

void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int par = partition(a, left, right);
        quickSort(a, left, par - 1);
        quickSort(a, par + 1, right);
    }
}

int main(void)
{
    srand(time(NULL));

    int unsorted[SIZE];
    for (int i = 0; i < SIZE; i++)
        unsorted[i] = rand() % (10000 - 1 + 1) + 1;

    int sorted[SIZE];
    copy(unsorted, sorted);

    // sorting
    printf("Unsorted: ");
    printArr(unsorted);

    // selection sort
    printf("Selection: ");
    selectionSort(sorted);
    printArr(sorted);
    copy(unsorted, sorted);

    // bubble sort
    printf("Bubble: ");
    bubbleSort(sorted);
    printArr(sorted);
    copy(unsorted, sorted);

    // insertion sort
    printf("Insertion: ");
    insertionSort(sorted);
    printArr(sorted);
    copy(unsorted, sorted);

    // merge sort
    printf("Merge: ");
    mergeSort(sorted, 0, SIZE - 1);
    printArr(sorted);
    copy(unsorted, sorted);

    // quick sort
    printf("Quick: ");
    quickSort(sorted, 0, SIZE - 1);
    printArr(sorted);
    copy(unsorted, sorted);
}