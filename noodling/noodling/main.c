#include <stdio.h>
#include <string.h>

void myFunction( char* pStr );

/* This is a working example of
https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function */

int main( void )
{
    char pStr[17];
    myFunction( pStr );
    printf( "%s", pStr );
}

void myFunction( char* pStr )
{
    const char str[20] = "This is a string";
    strcpy( pStr, str );
}
