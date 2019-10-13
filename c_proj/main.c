#include <stdio.h>
#include <string.h>

void fizzbuzz( int x, char* pFizzBuzz );
void intprint( int x, char* pFizzBuzz );

int main( void ) {
    int i;

    for ( i = 1; i < 101; i ++ ) {
        char pFizzBuzz[6];
        fizzbuzz( i, pFizzBuzz );
        printf( "%s\n" , pFizzBuzz );
    }

    return 0;
}

void fizzbuzz( int x, char* pFizzBuzz )
{
    const char BANG[6] = "Bang!";
    const char FIZZ[6] = "Fizz!";
    const char BUZZ[6] = "Buzz!";

    if ( x % 15 == 0 )
        strcpy( pFizzBuzz, BANG );
    else if ( x % 3 == 0 )
        strcpy( pFizzBuzz, FIZZ );
    else if ( x % 5 == 0 )
        strcpy( pFizzBuzz, BUZZ );
    else
        intprint( x, pFizzBuzz);
}

void intprint( int x, char* pFizzBuzz )
{
    char c[6];
    sprintf( c, "%d", x );
    strcpy(pFizzBuzz, c);
}
