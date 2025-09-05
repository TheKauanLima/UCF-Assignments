/* 
COP3223 Fall 2024 Week 3 Lab B
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
int main(void)
{
    int loopSize = 9;
    for (int i = 1; i <= loopSize; i++)
    {
        for (int j = 1; j <= loopSize; j++)
        {
            if (i % 2 == 0 || j % 2 == 0 ||
                ((i < loopSize && i > 1) && (j < loopSize && j > 1)))
            {
                printf("%s", "  ");
            }
            else
            {
                printf("%s", "* ");
            }
        }
        puts("");
    }
}