#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
    //char *malloc_ptr;
    char array[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    //char *cpy_array;
    //char cpy_array[10][10];
    //char *cpy_array_ptr = &cpy_array[10][10];
    
    char *cpy_array = malloc(10 * 10 * sizeof(char));
    for (int i = 0; i < 10; ++i) {
        //cpy_array[i] = array[i];
        
        strcpy(&cpy_array[i], array[i]);
        //free(cpy_array[i]);
        
        //malloc_ptr = malloc(10);
        //strcpy(malloc_ptr, array[i]);
        //strcpy(cpy_array[i], malloc_ptr);
    }
    for (int i= 0; i < 10; ++i)
        printf("%c\n", cpy_array[i]);
    
    free(cpy_array);

    return 0;
}
