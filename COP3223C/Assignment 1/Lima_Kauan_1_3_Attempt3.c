/* 
COP3223 Fall 2024 Assignment 1_3 
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for number of rows
    const int rows;
    printf("Please enter a number of rows (odd number): ");
    scanf("%d", &rows);

    //check if input is even or negative
    while (rows % 2 == 0 || rows < 0 || rows > 19)
    {
        printf("Invalid input.\nPlease re-enter number of rows (odd number): ");
        scanf("%d", &rows);
    }

    //declare variables for number of spaces and stars to print
    int spaceLimit;
    int printLimit;

    //print the diamond
    for (int i = 1; i <= rows; i++)
    {
        //determine the number of spaces to print
        //increase space limit until i matches the half the rows
        if (i <= (rows/2) + 1)
        {
            spaceLimit = (rows / 2) - (i - 1);
            printLimit = (2 * i) - 1;
        }
        //decrease space limit when i exceeds half row count
        else
        {
            spaceLimit = i - (rows / 2) - 1;
            printLimit = (2 * (rows - i)) + 1;
        }

        //print the diamond given the spaceLimit and printLimit
        for (int j = 0; j < spaceLimit; j++)
            printf(" ");
        for (int k = 0; k < printLimit; k++)
            printf("*");

        printf("\n");
    }
}