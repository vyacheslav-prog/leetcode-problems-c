#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *result;
	int numsCounter;
	if (0 == numsSize) {
		return NULL;
	}
	result = malloc(2 * sizeof(int));
	if (NULL == result) {
		return NULL;
	}
	for (numsCounter = 0; numsCounter < numsSize; numsCounter++) {
		*(result + 0) = target;
	}
	return result;
}
