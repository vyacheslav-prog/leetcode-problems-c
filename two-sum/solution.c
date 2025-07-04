#include <stdlib.h>

const int EXPECTED_SIZE = 2;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	unsigned int firstIndex = 0;
	unsigned int secondIndex = 1;
	int *result = (int*) malloc(EXPECTED_SIZE * sizeof(int));
	if (NULL == result) {
		return result;
	}
	while (secondIndex <= numsSize && target != *(nums+firstIndex) + *(nums+secondIndex)) {
		if (numsSize == secondIndex) {
			firstIndex = secondIndex = firstIndex + 1;
		}
		secondIndex++;
	}
	if (numsSize != firstIndex) {
		*(result+0) = firstIndex;
		*(result+1) = secondIndex;
		*returnSize = EXPECTED_SIZE;
	} else {
		free(result);
		result = NULL;
	}
	return result;
}
