#include <stdio.h>
#include "main.h"
#include "minunit.h"

int tests_run = 0;


static char * test_bang() {
char pFizzBuzz[6];
fizzbuzz( 15, pFizzBuzz );
mu_assert("error, pFizzBuzz != Bang",  pFizzBuzz == "Bang!");
return 0;
}

static char * test_fizz() {
char pFizzBuzz[6];
fizzbuzz( 3, pFizzBuzz );
mu_assert("error, pFizzBuzz != Fizz",  pFizzBuzz == "Fizz!");
return 0;
}

static char * all_tests() {
mu_run_test(test_bang);
mu_run_test(test_fizz);
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