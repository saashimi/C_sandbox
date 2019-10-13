#include <stdio.h>

char * fizzbuzz( int x );

int main() {
    char *pRes;
    int i;

    for ( i = 1; i < 101; i ++ ) {
        pRes = fizzbuzz( i );
        printf("%s\n" , pRes);
    }

    return 0;
}

char * fizzbuzz( int x )
{
    static char bangv[] = "Bang!";
    static char fizzv[] = "Fizz!";
    static char buzzv[] = "Buzz!";
    static char c[10];

    if ( x % 15 == 0 )
        return bangv;
    else if ( x % 3 == 0 )
        return fizzv;
    else if ( x % 5 == 0 )
        return buzzv;
    else
        sprintf( c, "%d", x );
        return c;
}
