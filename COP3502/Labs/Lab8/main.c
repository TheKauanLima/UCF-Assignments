/* Lab 8 written by Kauan Lima 2/24/2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXVAL 1000000

// Get difference from two times
long timediff(clock_t t1, clock_t t2)
{
    return (double)(t2 - t1) / CLOCKS_PER_SEC * 1000;
}

// Copy
void copy(int* src, int* dst, int size)
{
    for (int i = 0; i < size; i++)
        dst[i] = src[i];
}

// Swapping function
void swap(int* v1, int* v2)
{
    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Bubble Sort
void bubbleSort(int* arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion
void insertionSort(int* arr, int l, int r)
{
    int i, j;

    for (i = l + 1; i <= r; i++)
    {
        int item = arr[i];

        int j;
        for (j = i - 1; j >= l; j--)
        {
            if (arr[j] > item)
                arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = item;
    }
}

// Merge Sort

void merge(int* arr, int l, int m, int r)
{
    // set all necessary variables and arrays
    int sizeL = m - l + 1;
    int sizeR = r - m;

    int* L = (int*)malloc(sizeof(int) * sizeL);
    int* R = (int*)malloc(sizeof(int) * sizeR);

    for (int i = 0; i < sizeL; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < sizeR; i++)
        R[i] = arr[(m + 1) + i];

    int i = 0, j = 0, k = l;

    while (i < sizeL && j < sizeR)
    {
        if (L[i] <= R[i])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < sizeL)
        arr[k++] = L[i++];

    while (j < sizeR)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void mergeInsertionSort(int* arr, int l, int r, int t)
{
    if (r - l + 1 <= t)
    {
        insertionSort(arr, l, r);
        return;
    }

    if (l < r)
    {
        int m = (l + r) / 2;

        mergeInsertionSort(arr, l, m, t);
        mergeInsertionSort(arr, m+1, r, t);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int* arr, int low, int high)
{
    int temp;
    int i, lowpos;
    i = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[i]);
    lowpos = low;
    low++;
    while (low <= high)
    {
        while (low <= high && arr[low] <= arr[lowpos]) low++;

        while (high >= low && arr[high] > arr[lowpos]) high--;

        if (low < high)
            swap(&arr[low], &arr[high]);
    }

    swap(&arr[lowpos], &arr[high]);
    return high;
}

void quickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int split = partition(arr, low, high);
        quickSort(arr, low, split - 1);
        quickSort(arr, split + 1, high);
    }
}

int main()
{
    int arraySizes[6] = {10000, 20000, 30000, 40000, 50000, 60000};

    // loop through arraysizes
    for (int i = 0; i < 6; i++)
    {
        int* unsortedArray = (int*)malloc(arraySizes[i] * sizeof(int));

        // populate unsortedArray
        for (int j = 0; j < arraySizes[i]; j++)
            unsortedArray[j] = rand() % MAXVAL + 1;

        int* sortedArray = (int*)malloc(arraySizes[i] * sizeof(int));
        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Selection Sort
        clock_t start, end;
        start = clock();
        selectionSort(sortedArray, arraySizes[i]);
        end = clock();
        long elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Selection sort\n", arraySizes[i], elapsed);

        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Bubble Sort
        start, end;
        start = clock();
        bubbleSort(sortedArray, arraySizes[i]);
        end = clock();
        elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Bubble sort\n", arraySizes[i], elapsed);

        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Insertion Sort
        start = clock();
        insertionSort(sortedArray, 0, arraySizes[i] - 1);
        end = clock();
        elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Insertion sort\n", arraySizes[i], elapsed);

        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Merge Sort
        start = clock();
        mergeSort(sortedArray, 0, arraySizes[i] - 1);
        end = clock();
        elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Merge sort\n", arraySizes[i], elapsed);

        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Merge Insertion Sort
        start = clock();
        mergeInsertionSort(sortedArray, 0, arraySizes[i] - 1, 25);
        end = clock();
        elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Merge Insertion sort\n", arraySizes[i], elapsed);

        copy(unsortedArray, sortedArray, arraySizes[i]);

        // Quick Sort
        start = clock();
        quickSort(sortedArray, 0, arraySizes[i] - 1);
        end = clock();
        elapsed = timediff(start, end);
        printf("\nsorting %d values takes %ld milliseconds for Quick sort\n", arraySizes[i], elapsed);
    }

    return 0;
}