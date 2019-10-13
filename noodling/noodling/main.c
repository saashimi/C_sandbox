#include <stdio.h>
#include <string.h>

void myFunction( char* pStr );

/* This is a working example of
https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function */

int main( void )
{
    char pStr[17]; /* pStr is a char pointer */
    myFunction( pStr );
    printf( "%s", pStr );
}

void myFunction( char* pStr ) /* Input var is a char pointer */
{
    const char str[20] = "This is a string"; /* Constant char array*/
    strcpy( pStr, str );
}
