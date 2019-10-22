#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[6] = "herpa";
	char b[6] = "derpa";
	char *c;

	c = malloc(11);	
	strcpy( c, a );
	strcat( c, b );	
	
	printf("%s\n", c);
	printf("\nSize of a: %ld", sizeof(a));
	printf("\nSize of b: %ld", sizeof(a));
	printf("\nSize of c: %ld", sizeof(a));
	free(c);
	printf("\nSize of c when freed: %ld\n", sizeof(c));
	printf("\nherpaderpa %ld\n", sizeof("herpaderpa"));
	return 0;
	
}


