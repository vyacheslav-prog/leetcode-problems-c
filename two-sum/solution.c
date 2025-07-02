#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *result = NULL;
	int firstIndex, secondIndex;
	result = malloc(2 * sizeof(int));
	if (NULL == result) {
		return result;
	}
	for (firstIndex = 0; firstIndex < numsSize && 0 == *returnSize; firstIndex++) {
		for (secondIndex = firstIndex+1; secondIndex < numsSize; secondIndex++) {
			if (target == *(nums+firstIndex) + *(nums+secondIndex)) {
				*(result+0) = firstIndex;
				*(result+1) = secondIndex;
				*returnSize = 2;
			}
		}
		if (0 == *returnSize && 1 == numsSize && target == *nums) {
			*result = firstIndex;
			*returnSize = 1;
		}
	}
	if (0 != *returnSize) {
		return result;
	}
	free(result);
	return NULL;
}
