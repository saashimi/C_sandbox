#include <stdio.h>
#include <stdlib.h>

/*
int* func() {
	int* mem = malloc(1024);
	return mem;
}*/

int main() {
	int i, n;

	for (i = 1; i <= 10; i++) {
		n = rand() % 100 + 1;
		printf("%d\n", n);
	}
	return 0;
	
}
