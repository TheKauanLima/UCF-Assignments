// Heap Lab 12: COP3502C
// isHeap_recursive && isHeap_iter completed by Kauan Lima
#include "main.h"

int main()
{

    int n;//integer for the number of values the user will enter

    int *arr;//integer pointer that will point to our dynamically allocated array of integers

    printf("How many entries? ");

    scanf("%d", &n);//take in the number of values the user wants to enter

    printf("Enter %d entries: ", n);

    arr = malloc(sizeof(int) * n);//allocate memory for the integer array!

    for(int i = 0; i < n; i++){//loop that cycles through the number of values the user wants to enter and gets the value for each element from the user

        scanf("%d", &arr[i]);

    }

    int x = isHeap_recursive(arr, 0, n);//check to see if the array is a heap based on recursion and store the returned value. Afterward, used the stored value to determine if the array is a min heap and tell the user

    if(x == 1){

        printf("Recursive says Yes!\n");

    } else{

        printf("Recursive says No!\n");

    }

    int y = isHeap_iter(arr, n);//check to see if the array is a heap based on iteration and store the returned value. Afterward, used the stored value to determine if the array is a min heap and tell the user

    if(y == 1){

        printf("Iterative says Yes!\n");

    } else{

        printf("Iterative says No!\n");

    }

    free(arr);//free the memory for the integer array since we are done with it!

    return 0;//return an integer since this is an integer function

}

int isHeap_recursive(int arr[], int i, int n)
{
    if (i >= n || n <= 0)
        return 1;

    if (2 * i + 1 < n) // checking if left child is within n
        if (arr[2 * i + 1] < arr[i])
            return 0;

    if (2 * i + 2 < n) // checking if right child is within n
        if (arr[2 * i + 2] < arr[i])
            return 0;
    
    return isHeap_recursive(arr, 2 * i + 1, n) && isHeap_recursive(arr, 2 * i + 2, n);
}

int isHeap_iter(int arr[], int n)
{
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        if (arr[2 * i + 1] < arr[i]) // check if left child is smaller than current element
            return 0;

        if (2 * i + 2 < n) // first check if the right child is within the bounds (size of array) && then check if the right child fulfills the heap property
            if (arr[2 * i + 2] < arr[i])
                return 0;
    }
    return 1;
}



