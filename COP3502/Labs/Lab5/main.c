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
    struct stack checkerStack;
    initialize(&checkerStack);

    // read string char by char left to right
    for (int i = 0; exp[i] != '\0'; ++i)
    {
        // if (, [, or {, push onto stack
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(&checkerStack, exp[i]);

        // if ), ], }, pop and check for corresponding opening character
        if (exp[i] == ')')
        {
            char c = pop(&checkerStack);
            if (c != '(')
            {
                printf("INVALID for )!!!\n");
                return 0;
            }
        }
        else if (exp[i] == ']')
        {
            char c = pop(&checkerStack);
            if (c != '[')
            {
                printf("INVALID for ]!!!\n");
                return 0;
            }
        }
        else if (exp[i] == '}')
        {
            char c = pop(&checkerStack);
            if (c != '{')
            {
                printf("INVALID for }!!!\n");
                return 0;
            }
        }
    }

    if (!empty(&checkerStack))
    {
        printf("INVALID\n");
        return 0;
    }

    return 1;
}

int priority(char ch)
{
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return 0;
}

int isOperator(char ch)
{
    return (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

char *infixToPostfix(char infix[])
{
    struct stack operators;
    initialize(&operators);

    // allocate double length to account for spaces in final postfix
    char* postfix = malloc((strlen(infix) + 1) * 2);
    int postfixIndex = 0; // curr index in postfix expression

    // read left to right
    for (int i = 0; i < strlen(infix); ++i)
    {
        // if an operand
        if (isdigit(infix[i]))
        {
            // handle multiple digits
            while (isdigit(infix[i]))
            {
                // add to postfix
                postfix[postfixIndex] = infix[i];
                postfixIndex++;
                i++;
            }
            i--; // correct index for next iter

            postfix[postfixIndex] = ' ';
            postfixIndex++;
        }

        // if left parenthesis, push onto stack
        else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
            push(&operators, infix[i]);
        // if right parenthesis, pop until left parenthesis
        else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}')
        {
            char popUntil;

            if (infix[i] == ')') popUntil = '(';
            else if (infix[i] == ']') popUntil = '[';
            else if (infix[i] == '}') popUntil = '{';

            while (!empty(&operators) && peek(&operators) != popUntil)
            {
                postfix[postfixIndex++] = pop(&operators);
                postfix[postfixIndex++] = ' ';
            }
            pop(&operators);
        }

        // if an operator
        else if (isOperator(infix[i]))
        {
            // compare to the operator at the top of the stack
            char c = peek(&operators);

            // if priority of curr is higher than at the top
            if (priority(c) < priority(infix[i]))
            {
                // push curr to the stack
                push(&operators, infix[i]);
            }
            // otherwise priority is <= top of stack
            else
            {
                // keep popping until priority of curr is greater than the top
                // check that stack if not empty, and infix[i] is not parentheses
                while (!empty(&operators) && priority(infix[i]) <= priority(c) && !isParentheses(infix[i]))
                {
                    // add popped operators to postfix
                    postfix[postfixIndex] = pop(&operators);
                    postfix[postfixIndex + 1] = ' ';
                    postfixIndex += 2;
                    c = peek(&operators);
                }

                // push curr operator to the stack
                push(&operators, infix[i]);
            }
        }
    }

    while (!empty(&operators))
    {
        postfix[postfixIndex++] = pop(&operators);
        postfix[postfixIndex++] = ' ';
    }

    postfix[postfixIndex] = '\0';

    return postfix;
}

int isParentheses(char ch1)
{
    return (ch1 == '(' || ch1 == ')' || ch1 == '[' || ch1 == ']' || ch1 == '{' || ch1 == '}');
}