// imports
#include <stdio.h>
#include <stdlib.h>

// structs
struct stack
{
    char pos[20];
};

// functions
int isBalanced(char *e)
{
    struct stack s;
    initialize(&s);
    for (int i = 0; e[i] != '\0'; i++)
    {
        if (e[i] == '(' ||
            e[i] == '{')
            push(&s, e[i]);
        else if (e[i] == ')')
            if (pop(&s) == '(')
                return 0;
            else if (e[i] == '}')
                if (pop(&s) == '{')
                    return 0;
    }
    return isEmpty(&s);
}

// main
int main(void)
{
}