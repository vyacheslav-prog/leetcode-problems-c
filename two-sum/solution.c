#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *result = NULL;
	int numsCounter;
	if (0 == numsSize) {
		return result;
	}
	result = malloc(2 * sizeof(int));
	if (NULL == result) {
		return result;
	}
	for (numsCounter = 0; numsCounter < numsSize && target == *nums; numsCounter++) {
		*result = target;
		*returnSize += 1;
	}
	if (0 != *returnSize) {
		return result;
	}
	return NULL;
}
