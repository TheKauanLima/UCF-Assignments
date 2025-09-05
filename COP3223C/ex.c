//array of pointer
#include <stdio.h>
int main(void) {
    int num0 = 10;
    int num1 = 15;
    int num2 = 20;
    int* numPtr[3] = { &num0, &num1, &num2 };
    printf("value of numPtr[1] is %p, address of num1 is %p\n", numPtr[1],
    &num1);
    printf("valud of num1 is %d\n", *numPtr[1]);
    //hello, cat, weekend
    char str[3][8] = { "hello", "cat", "weekend" };
    for (int i = 0; i < 3; i++) {
        printf("%s\n", str[i]);
    }
    puts("");
    char* cPtr[3] = { "hello", "cat", "weekend" };
    for (int i = 0; i < 3; i++) {
        printf("value of i is %p\n", cPtr[i]);
        printf("%s\n", cPtr[i]);
    }
    printf("char is %c\n", cPtr[1][1]);
    char a[6] = "hello";
    char* aPtr = a;
    printf("%s\n", a);
    printf("%s\n", aPtr);
}