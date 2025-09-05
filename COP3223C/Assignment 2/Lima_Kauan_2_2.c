/* 
COP3223 Fall 2024 Assignment 2_2
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <stdlib.h>

//gcd function
int gcd(int first, int second)
{
    //if a number is 0, return the other number
    if (first == 0) return second;
    else if (second == 0) return first;

    //continue recursively until second == 0, at which point answer is first.
    return gcd(second, first % second);
}

//main function
int main(void)
{
    //prompt for first number
    int firstNum;
    printf("Please input the first number: ");
    scanf("%d", &firstNum);

    //prompt for second number
    int secondNum;
    printf("Please input the first number: ");
    scanf("%d", &secondNum);

    //call function
    int greatestCommonDenominator = gcd(firstNum, secondNum);

    //print result
    printf("the common divisor for %d and %d is %d", firstNum, secondNum, greatestCommonDenominator);
}