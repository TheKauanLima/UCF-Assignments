/* 
COP3223 Fall 2024 Week 3 Lab B
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>

int main(void)
{
    int x, y, z;
    printf("Enter three numbers.\nPlease enter the first number: ");
    scanf("%d", &x);

    printf("Please enter the second number: ");
    scanf("%d", &y);

    printf("Please enter the third number: ");
    scanf("%d", &z);

    int least, mid, high;
    if(x<y)
    {
        if(x<z)
        {
            least = x;
            if (z<y)
            {
                mid = z;
                high = y;
            }
            else
            {
                mid = y;
                high = z;
            }
        }
        else
        {
            least = z;
            mid = x;
            high = y;
        }
    }
    else if (y<x)
    {
        if (y<z)
        {
            least = y;
            if (x<z)
            {
                mid = x;
                high = z;
            }
            else
            {
                mid = z;
                high = x;
            }
        }
        else
        {
            least = z;
            mid = y;
            high = x;
        }
    }

    printf("%d %d %d", least, mid, high);
}