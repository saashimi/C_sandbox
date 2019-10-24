#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *raw1; 
	char *raw2;
	char *concat;

	raw1 = malloc(64);
	raw2 = malloc(64);
	
	printf( "Enter a string: >> ");
	scanf("%s", raw1);

	printf("Enter a second string: >> ");
	scanf("%s", raw2);

	printf("\nSize of raw1: %ld", sizeof(raw1) * (strlen(raw1) + 1));
	printf("\nSize of raw2: %ld", sizeof(raw2) * (strlen(raw1) + 1));

	int raw1sz = strlen(raw1);
	raw1 = realloc(raw1, raw1sz + 1);
	printf("\nSize of realloc raw1: %ld", sizeof(raw1) * strlen(raw1) + 1);

	int raw2sz = strlen(raw2);
	raw2 = realloc(raw2, raw2sz + 1);	
	printf("\nSize of realloc raw2: %ld", sizeof(raw2));
	
	concat = malloc(raw1sz + raw2sz + 1);
	printf("\nSize of concat: %ld", sizeof(concat) * strlen(concat) + 1);

	strcpy( concat, raw1 );
	strcat( concat, raw2 );	
	printf("\n%s\n", concat);
	
	free(raw1);
	free(raw2);
	free(concat);
	printf("\nSize of concat when freed: %ld\n", sizeof(concat) * strlen(concat) + 1);
	
	return 0;
	
}


