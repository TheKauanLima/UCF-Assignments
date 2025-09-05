/* 
COP3223 Fall 2024 Assignment 1_2
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt for five digit integer
    const int prompt;
    printf("Please enter a five digit integer: ");
    scanf("%d", &prompt);

    //declare variables to divide prompt, store each digit, and final result
    int dividePrompt = prompt;
    int storeDigit;
    int finalNumber = 0;

    //obtain final digit in dividePrompt
    //add to final number by multiplying the digit * 10^i
    //remove final digit of dividePrompt
    for (int i = 4; i >= 0; i--)
    {
        storeDigit = dividePrompt % 10;
        finalNumber = finalNumber + storeDigit * pow(10, i);
        dividePrompt = dividePrompt / 10;
    }

    //check for rounding errors
    if (finalNumber == prompt - 1) finalNumber = prompt;

    //print the final result
    if (finalNumber == prompt)
        printf("%d is a palindrome number", prompt);
    else if (finalNumber != prompt)
        printf("%d is not a palindrome number", prompt);
}