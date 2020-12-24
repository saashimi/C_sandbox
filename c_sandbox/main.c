#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    char array[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    char cpy_array[10][10];
    
    for (int i = 0; i < 10; ++i) {
        strcpy(cpy_array[i], array[i]);
    }
    for (int i= 0; i < 10; ++i)
        printf("%s\n", cpy_array[i]);
    
    return 0;
}
