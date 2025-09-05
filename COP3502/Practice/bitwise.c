#include <stdio.h>
#include <stdlib.h>

// int lowestOneBit(int n)
// {
//     if (n == 0)
//         return 0;
//     int i = 0;
//     int b = n;
//     while (1)
//     {
//         if ((b & 1) == 1)
//             return 1 << i;
//         b = n >> i;
//         i++;
//     }
// }

int lowestOneBit(int n)
{
    int r = 1;
    while ((r & n) == 0)
        r = r << 1;
    return r;
}

int highestOneBit(int n)
{
    int r = 1 << 30;
    while ((r & n) == 0)
        r = r >> 1;
    return r;
}

int main(void)
{
    printf("Lowest One Bit: %d\n", lowestOneBit(6));
    printf("Highest One Bit: %d", highestOneBit(6));
}