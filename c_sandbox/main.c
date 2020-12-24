#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    char array[10][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    
    char **strings = malloc(10 * 10); //pointer to pointer; max size specified
    for (int i = 0; i < 10; ++i) {
        strings[i] = malloc(6); // length of indiv. string
        strcpy(strings[i], array[i]);
    }
    
    for (int i= 0; i < 10; ++i)
        printf("%s\n", strings[i]);
    
    for (int i = 0; i < 10; ++i)
        free(strings[i]);
    free(strings);

    return 0;
}
