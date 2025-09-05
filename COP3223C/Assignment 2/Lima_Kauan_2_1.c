/* 
COP3223 Fall 2024 Assignment 2_1 
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//random function
int random_number_gen(int max)
{
    //generate seed for rand()
    srand(time(NULL));

    //generate random number based on time
    int random = rand() % max + 1;
    return random;
}

//guess function
void guess_number(int guess, int value)
{
    //prompt for initial guess
    int guessCount = 1;
    printf("I have my number. What's your guess? ");
    scanf("%d", &guess);

    //if initial guess in incorrect, start giving hints and additional prompts up to 8 times
    while (guessCount < 8 && guess != value)
    {
        if (guess < value)
            printf("Too low. Guess again: ");
        else if (guess > value)
            printf("Too high. Guess again: ");
        scanf("%d", &guess);
        guessCount++;
    }

    //judge whether user guessed correctly or not.
    if (guess == value)
        printf("You got it in %d guesses!\n", guessCount);
    else
        puts("Better luck next time");
}

//main function
int main(void)
{
    //variable to play again
    int token;

    //loop program again if user wants
    do
    {
        //prompt for valid difficulty level
        int difficultyLevel;
        puts("Let's play Guess the Number");
        do
        {
            printf("Pick a difficulty level (1, 2, 3): ");
            scanf("%d", &difficultyLevel);
        } while (difficultyLevel < 0 || difficultyLevel > 3);

        //switch case for different difficulty levels to determine upper limit
        int output;
        switch (difficultyLevel)
        {
            case 1:
                output = random_number_gen(10);
                break;
            case 2:
                output = random_number_gen(100);
                break;
            case 3:
                output = random_number_gen(1000);
                break;
        }

        //call guess_number function
        int guess;
        guess_number(guess, output);

        //prompt to play again
        printf("Play again? ");
        scanf("%d", &token);
    } while (token == 1);
}