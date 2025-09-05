#include <stdio.h>

#define SIZE 3

int decToOct(int n, int i)
{
    int s = (n % 8) * i;
    if (n < 8)
        return s;
    return decToOct(n/8, i * 10) + s;
}

int zeros(int n)
{
    if (n == 0)
        return 0;
    return zeros(n/5) + n/5;
}

int productDigits (int n)
{
    if (n == 0)
        return 1;
    return productDigits(n / 10) * n % 10;
}

int weightedSum(int numbers[], int n)
{
    if (n == 0)
        return 0;
    return numbers[n-1]*n + weightedSum(numbers, n-1);
}

int f (int n)
{
    return n;
}

int fcomp(int n, int k)
{
    if (k == 1)
        return f(n);
    return fcomp(n, k-1);
}

int binary(int n, int i)
{
    int s = (n % 2) * i;
    if (n < 2)
        return s;
    return decToOct(n/2, i * 10) + s;
}

int main(void)
{
    // int n = 0;
    // printf("Decimal: ");
    // scanf("%d", &n);
    // printf("Octal: %d", decToOct(n, 1));

    // int x = 0;
    // printf("x: ");
    // scanf("%d", &x);
    // printf("Zeros: %d", zeros(x));

    // int m = 0;
    // printf("m: ");
    // scanf("%d", &m);
    // printf("Product: %d", productDigits(m));

    // int y[SIZE] = { 5, 4, 6 };
    // printf("WeightedSum: %d", weightedSum(y, SIZE));

    // int f = 0;
    // printf("f: ");
    // scanf("%d", &f);
    // int k = 0;
    // printf("k: ");
    // scanf("%d", &k);
    // printf("fcomp: %d", fcomp(f, k));

    int n = 0;
    printf("Decimal: ");
    scanf("%d", &n);
    printf("Binary: %d", binary(n, 1));
}