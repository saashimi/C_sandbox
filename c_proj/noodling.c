#include <stdio.h>
#include <stdlib.h>

char func();

int main()
{
    char ret;
    ret = func();
    sprintf("%s", ret);
    return 0;
}

char func()
{
    char[16] = "This is a string";
    return char;
}
