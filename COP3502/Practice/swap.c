#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b)
{
    char t;
    t = *a;
    *a = *b;
    *b = t;
}

void permuteSwap(char* s, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", s);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(&s[l], &s[i]);
            permuteSwap(s, l+1, r);
            swap(&s[l], &s[i]);
        }
    }
}

void printArray(char* s, int* perm, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", s[perm[i]]);
    }
    printf("\n");
}

void permuteUsed(int* perm, int* used, char* s, int k, int n)
{
    if (k == n)
    {
        printArray(s, perm, n);
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        used[i] = 1;
        perm[k] = i;
        permuteUsed(perm, used, s, k+1, n);
        used[i] = 0;
    }
}

int sumArray(int* a, int s)
{
    if (s == 0)
        return 0;
    return a[s - 1] + sumArray(a, s-1);
}

int main(void)
{
    char s[] = "ABCD";
    int length = strlen(s);

    printf("\n-- SWAP --\n");

    permuteSwap(s, 0, length - 1);

    printf("\n-- USED --\n");

    int* perm = calloc(length, sizeof(int));
    int* used = calloc(length, sizeof(int));
    permuteUsed(perm, used, s, 0, length);
    free(perm);
    free(used);

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d", sumArray(arr, 8));
}