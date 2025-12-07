#include <stdio.h>
#include <stdlib.h>
#define CHAR2INT(c) ((c) - '0')

int main(void)
{
    int left = getchar();
    int op = getchar();
    int right = getchar();

    switch (op)
    {
        case '+':
            putchar(CHAR2INT(left) + CHAR2INT(right) + '0');
            break;
        case '-':
            putchar(CHAR2INT(left) - CHAR2INT(right) + '0');
            break;
        case '*':
            putchar(CHAR2INT(left) * CHAR2INT(right) + '0');
            break;
        case '/':
            if (right == '0')
            {
                fprintf(stderr, "Error: Division by zero\n");
                return EXIT_FAILURE;
            }
            putchar(CHAR2INT(left) / CHAR2INT(right) + '0');
            break;
        default:
            fprintf(stderr, "Error: Unknown operator '%c'\n", op);
            return EXIT_FAILURE;
    }
}