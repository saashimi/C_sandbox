#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct CharAlloc {
    int charlen;
    char *strsz; 
};	

int main() {

	struct CharAlloc raw1;
        struct CharAlloc raw2;
        struct CharAlloc concat;

	//char *raw1; 
	//char *raw2;
	//char *concat;

	raw1.strsz = malloc(64);
	raw2.strsz = malloc(64);
	
	printf( "Enter a string: >> ");
	scanf("%s", raw1.strsz);

	printf("Enter a second string: >> ");
	scanf("%s", raw2.strsz);

	printf("\nSize of raw1: %ld", (strlen(raw1.strsz) + 1));
	printf("\nSize of raw2: %ld", (strlen(raw1.strsz) + 1));

	raw1.charlen = strlen(raw1.strsz);
	raw1.strsz = realloc(raw1.strsz, raw1.charlen + 1);
	printf("\nSize of realloc raw1: %d", raw1.charlen + 1);

	raw2.charlen = strlen(raw2.strsz);
	raw2.strsz = realloc(raw2.strsz, raw2.charlen + 1);	
	printf("\nSize of realloc raw2: %d", raw2.charlen + 1);
	
	concat.strsz = malloc(raw1.charlen + raw2.charlen + 1);
	strcpy( concat.strsz, raw1.strsz );
	strcat( concat.strsz, raw2.strsz );	
	concat.charlen = strlen(concat.strsz);
	
        printf("\n%s\n", concat.strsz);
	printf("\nSize of concat: %d", concat.charlen + 1);
	
	free(raw1.strsz);
	free(raw2.strsz);
	free(concat.strsz);
	printf("\nSize of concat when freed: %ld\n", strlen(concat.strsz) + 1);
	
	return 0;
	
}
