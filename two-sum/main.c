#include <stdio.h>
#include "../minunit.h"
#include "solution.c"

int tests_run = 0;

static char * test_sums_no_for_empty_numbers() {
	int resultSize = 0;
	int *result = twoSum(0, 0, 0, &resultSize);
	mu_assert("result must be null for empty numbers", NULL == result);
	return 0;
}

static char * test_sums_no_for_single_unsuitable_target() {
	int numbers[1] = {5};
	int resultSize = 0;
	int *result = twoSum(numbers, 1, 4, &resultSize);
	mu_assert("result must be null for numbers [{5}] and unsuitable target [4]", NULL == result);
	return 0;
}

static char * test_sums_two_numbers() {
	int numbers[2] = {1, 1};
	int resultSize = 0;
	int *result = twoSum(numbers, 2, 2, &resultSize);
	mu_assert("result must be [{0, 1}] for numbers [{1, 1}] and target [2]", 2 == resultSize && 0 == *result && 1 == *(result+1));
	return 0;
}

static char * test_sums_only_two_numbers_for_target() {
	int numbers[3] = {2, 2, 2};
	int resultSize = 0;
	int *result = twoSum(numbers, 3, 6, &resultSize);
	mu_assert("result must be null for numbers [{2, 2, 2}] and target [6]", NULL == result && 0 == resultSize);
	return 0;
}

static char * test_sums_two_numbers_when_first_is_skipped() {
	int numbers[3] = {3, 2, 4};
	int resultSize = 0;
	int *result = twoSum(numbers, 3, 6, &resultSize);
	mu_assert("result must be [{1, 2}] for numbers [{3, 2, 4}] and target [6]", 0 != resultSize && 1 == *result && 2 == *(result+1));
	return 0;
}

static char * all_tests() {
	mu_run_test(test_sums_no_for_empty_numbers);
	mu_run_test(test_sums_no_for_single_unsuitable_target);
	mu_run_test(test_sums_two_numbers);
	mu_run_test(test_sums_only_two_numbers_for_target);
	mu_run_test(test_sums_two_numbers_when_first_is_skipped);
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
