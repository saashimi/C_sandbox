#include <stdio.h>


char * func( void );

int main() {
    char *res;
    res = func();
    printf("%s" , res);

    return 0;
}

char * func( void )
{
    static char str[] = "blah";
    return str;
}
