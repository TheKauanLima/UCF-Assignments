// Arup Guha
// 6/20/07
// Written in COP 3502 to illustrate an array implementation of a stack.
//modified by Tanvir Ahmed 6/1/2020

//Modified by Adam Betinsky on 2/3/2025 to save time while doing Lab #5
//Lab #5: Stack Implementation Skeleton Code

//UPDATED ON 2/4/2025 to allow for a character stack instead of an integer stack

//SUBMITTED 2/16/2025 by Kauan Lima after finishing Lab 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //needed for isdigit

// The array will store the items in the stack, first in
// index 0, then 1, etc. top will represent the index
// to the top element in the stack. If the stack is
// empty top will be -1.

#define SIZE 100
#define EMPTY -1

struct stack {

    char items[SIZE];

    int top;

};

//Provided functions
void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
int push(struct stack* stackPtr, char value);
int empty(struct stack* stackPtr);
char pop(struct stack* stackPtr);
char peek(struct stack* stackPtr);
void print_stack(struct stack* stackPtr);

//---------------------------------------------
//Functions you need to complete (in addition to main)
int checkBalance(char exp[]);
int priority(char ch);
int isOperator(char ch);
char *infixToPostfix(char infix[]);
int isParentheses(char ch1);

int main()
{
    struct stack exp;
    initialize(&exp);

    printf("Enter expression: ");
    scanf("%[^\n]s", exp.items);
    printf("Your input expression: %s\n\n", exp.items);

    printf("Checking balance...\n");
    if (checkBalance(exp.items))
        printf("VALID\n");
    else
        return 0;

    char* postfix = infixToPostfix(exp.items);
    printf("The postfix is: %s", postfix);
    free(postfix);

    return 0;
}

void initialize(struct stack* stackPtr) {
    stackPtr->top = -1;
}

// If the push occurs, 1 is returned. If the
// stack is full and the push can't be done, 0 is
// returned.
int push(struct stack* stackPtr, char value) {

    // Check if the stack is full.
    if (full(stackPtr))
        return 0;

    // Add value to the top of the stack and adjust the value of the top.
    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
    return 1;
}

// Returns true iff the stack pointed to by stackPtr is full.
int full(struct stack* stackPtr) {
    return (stackPtr->top == SIZE - 1);
}

// Returns true iff the stack pointed to by stackPtr is empty.
int empty(struct stack* stackPtr) {
    return (stackPtr->top == -1);
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is popped and returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char pop(struct stack* stackPtr) {

    char retval;

    // Check the case that the stack is empty.
    if (empty(stackPtr))
        return EMPTY;

    // Retrieve the item from the top of the stack, adjust the top and return
    // the item.
    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}

// Pre-condition: The stack pointed to by stackPtr is NOT empty.
// Post-condition: The value on the top of the stack is returned.
// Note: If the stack pointed to by stackPtr is empty, -1 is returned.
char peek(struct stack* stackPtr) {

    // Take care of the empty case.
    if (empty(stackPtr))
        return EMPTY;

    // Return the desired item.
    return stackPtr->items[stackPtr->top];
}

void print_stack(struct stack* stackPtr) {
    printf("\nPrinting the Current stack...");
    for(int i=0; i<=stackPtr->top; i++)
        printf("%d ", stackPtr->items[i]);
}

/*
 * -------------------------------------------------------------------
 *
 * This marks the start of the functions you must complete
 */
int checkBalance(char exp[])
{
    struct stack s;
    initialize(&s);

    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' && peek(&s) == '(')
        {
            pop(&s);
        }
        else if (exp[i] == ']' && peek(&s) == '[')
        {
            pop(&s);
        }
        else if (exp[i] == '}' && peek(&s) == '{')
        {
            pop(&s);
        }
        i++;
    }

    if (!empty(&s))
    {
        printf("INVALID\n");
        return 0;
    }
    return 1;
}

int priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    return (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

char *infixToPostfix(char exp[])
{
    struct stack s;
    initialize(&s);
    char* postfix = (char*)malloc(strlen(exp + 1) * 2);
    int postfixIndex = 0;

    int i = 0;
    while (exp[i] != '\0')
    {
        if (isOperator(exp[i]))
        {
            postfix[postfixIndex++] = ' ';

            if (s.top == -1)
            {
                push(&s, exp[i]);
            }
            else if (priority(exp[i]) >= priority(peek(&s)))
            {
                push(&s, exp[i]);
            }
            else if (priority(exp[i]) < priority(peek(&s)))
            {
                char c = pop(&s);
                postfix[postfixIndex] = c;
                postfix[postfixIndex+1] = ' ';
                i--;
            }
        }
        else if (isdigit(exp[i]))
        {
            postfix[postfixIndex] = exp[i];
        }
        else if (isParentheses(exp[i]))
        {
            postfix[postfixIndex++] = ' ';
            
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            {
                push(&s, exp[i]);
            }
            else if (exp[i] == ')')
            {
                if (s.top != '(')
                {
                    char c = pop(&s);
                    postfix[postfixIndex] = c;
                    i--;
                }
            }
            else if (exp[i] == ']')
            {
                postfix[postfixIndex++] = ' ';
                
                if (s.top != '[')
                {
                    char c = pop(&s);
                    postfix[postfixIndex] = c;
                    i--;
                }
            }
            else if (exp[i] == '}')
            {
                if (s.top != '{')
                {
                    char c = pop(&s);
                    postfix[postfixIndex] = c;
                    i--;
                }
            }
        }

        i++;
        postfixIndex++;
    }

    while (!empty(&s))
    {
        char c = pop(&s);
        postfix[postfixIndex] = c;
        postfix[postfixIndex+1] = ' ';
    }

    return postfix;
}

int isParentheses(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{' || ch == ')' || ch == ']' || ch == '}');
}