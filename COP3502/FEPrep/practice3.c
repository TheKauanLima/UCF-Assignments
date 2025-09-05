// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// definitions

// structs
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// functions
int **triangularSum(int *base, int n)
{
    int **ta = malloc(sizeof(int *) * n);

    ta[0] = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        ta[0][i] = base[i];

    for (int i = 1; i < n; i++)
    {
        ta[i] = malloc(sizeof(int) * (n - i));
        for (int j = 0; j < n - i; j++)
        {
            ta[i][j] = ta[i - 1][j] + ta[i - 1][j + 1];
        }
    }
    return ta;
}

int sumSingleParents(node *root)
{
    if (!root)
        return 0;

    int leftsum = sumSingleParents(root->left);
    int rightsum = sumSingleParents(root->right);

    int sum = 0;
    if ((root->left && !root->right) || (!root->left && root->right))
        sum += root->data;
    return sum + leftsum + rightsum;
}

void swap(int *ptrA, int *ptrB);
int heaparray[100];

void percolateUp(int idx)
{
    if (idx > 1)
    {
        if (heaparray[idx] < heaparray[idx / 2])
        {
            swap(&heaparray[idx], &heaparray[idx / 2]);
            percolateUp(idx / 2);
        }
    }
}

int kClosePerm(int *perm, int *used, int n, int maxgap, int k)
{
    if (n == k)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        if (k > 0 && abs(perm[k - 1] - i) > maxgap)
            continue;
        used[i] = 1;
        perm[k] = i;
        res += kClosePerm(perm, used, n, maxgap, k + 1);
        used[i] = 0;
    }
    return res;
}

// int kClosePerm(int *perm, int *used, int n, int maxgap, int k)
// {
//     if (n == k)
//         return 1;
//     int res = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (used[i])
//             continue;
//         used[i] = 1;
//         perm[k] = i;
//         kClosePerm(perm, used, n, maxgap, k + 1);
//         for (int j = 0; j < n - 1; j++)
//         {
//             if (!(perm[j] - perm[j + 1] > abs(maxgap)))
//                 break;
//         }
//         res++;
//         used[i] = 0;
//     }
//     return res;
// }

// 13, 11, 9, 16, 12, 15, 10, 5
// 13, 11, 9, 5, 12, 15, 10, 16
// 13, 11, 9, 5, 12, 10, 15, 16
// 10, 11, 9, 5, 12, 13, 15, 16
// 10, 11, 9, 5, 12, 13, 15, 16
// 10, 5, 9, 11, 12, 13, 15, 16
// 9, 5, 10, 11, 12, 13, 15, 16
// 5, 9, 10, 11, 12, 13, 15, 16

int leastBitsOn(int x)
{
    int numOn = 0;
    int cur = 0;
    int longest = 0;
    for (int i = 0; i < 8 * sizeof(int); i++)
    {
        if ((x & (1 << i)) != 0)
        {
            cur++;
            numOn++;
        }
        else
            cur = 0;

        if (longest < cur)
            longest = cur;
    }
    return numOn + 1 - longest;
}

// main
int main(void)
{
}