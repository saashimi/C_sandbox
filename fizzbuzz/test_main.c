#include <stdio.h>
#include <string.h>
#include "main.h"
#include "minunit.h"

int tests_run = 0;


static char * test_bang() {
    int res;
    char pFizzBuzz[6];
    
    fizzbuzz( 15, pFizzBuzz );
    res = strcmp(pFizzBuzz, "Bang!");
    mu_assert("error, pFizzBuzz != Bang!",  res == 0);
    return 0;
}

static char * test_fizz() {
    int res;
    char pFizzBuzz[6];
    
    fizzbuzz( 3, pFizzBuzz );
    res = strcmp(pFizzBuzz, "Fizz!");
    mu_assert("error, pFizzBuzz != Fizz!",  res == 0);
    return 0;
}

static char * test_buzz() {
    int res;
    char pFizzBuzz[6];
    
    fizzbuzz( 5, pFizzBuzz );
    res = strcmp(pFizzBuzz, "Buzz!");
    mu_assert("error, pFizzBuzz != Buzz!",  res == 0);
    return 0;
}

static char * test_int() {
    int res;
    char pFizzBuzz[6];
    
    fizzbuzz( 2, pFizzBuzz );
    res = strcmp(pFizzBuzz, "2");
    mu_assert("error, pFizzBuzz != 2!",  res == 0);
    return 0;
}


static char * all_tests() {
    mu_run_test(test_bang);
    mu_run_test(test_fizz);
    mu_run_test(test_buzz);
    mu_run_test(test_int);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}