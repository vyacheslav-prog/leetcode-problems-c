#include <stdio.h>
#include "../minunit.h"
#include "solution.c"

int tests_run = 0;

static char * test_sums_no_for_empty_numbers() {
	int *result = twoSum(0, 0, 0, 0);
	mu_assert("result must be null for empty numbers", 0 != result);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_sums_no_for_empty_numbers);
	return 0;
}

int main(void) {
	char *result = all_tests();
	if (0 != result) {
		printf("%s\n", result);
	} else {
		printf("done\n");
	}
	printf("tests run: %d\n", tests_run);
	return 0 != result;
}
