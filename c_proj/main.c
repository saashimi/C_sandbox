#include <stdio.h>
#include <stdlib.h>

/* function declaration */
int max(int num1, int num2);

int main() {
    /* local variable definition */
    int a;
    int b;
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("Enter another integer: ");
    scanf("%d", &b);
    int ret;

    /* calling a function to get max value */
    ret = max(a, b);

    printf("Max value is : %d\n", ret);

    return 0;
}

/* function returning the max between two numbers */
int max(int num1, int num2) {

    /* local variable declaration */
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}
