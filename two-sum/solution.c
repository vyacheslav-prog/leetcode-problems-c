#include <stdlib.h>

const int EXPECTED_SIZE = 2;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *result = (int*) malloc(EXPECTED_SIZE * sizeof(int));
	int firstIndex, secondIndex;
	if (NULL == result) {
		return result;
	}
	for (firstIndex = 0; firstIndex < numsSize && EXPECTED_SIZE != *returnSize; firstIndex++) {
		for (secondIndex = firstIndex+1; secondIndex < numsSize; secondIndex++) {
			if (target == *(nums+firstIndex) + *(nums+secondIndex)) {
				*(result+0) = firstIndex;
				*(result+1) = secondIndex;
				*returnSize = EXPECTED_SIZE;
			}
		}
	}
	if (EXPECTED_SIZE != *returnSize) {
		free(result);
		result = NULL;
	}
	return result;
}
