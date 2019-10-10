#include <stdio.h>
#include <stdlib.h>

/* function declaration */
char fizzbuzz(int x);

int main() {
    /* local variable definition */
    int x = 15;
    char ret;

    /* calling FizzBuzz */
    ret = fizzbuzz(x);
    printf("%s", ret);

    return 0;
}

/* function returning the max between two numbers */
char fizzbuzz(int x) {

    /* local variable declaration */
    char buffer[50];
    char bang[] = "Bang!";
    char fizz[] = "Fizz!";
    char buzz[] = "Buzz!";

    if ( x % 15 == 0)
        return *bang;
    else if ( x % 3 == 0)
        return *fizz;
    else if ( x % 5 == 0)
        return *buzz;
    else
        sprintf(buffer, "%d", x);
        return *buffer;
}
