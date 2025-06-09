#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *result = malloc(2 * sizeof(int));
	if (0 == target) {
		return NULL;
	}
	*(result + 1) = target;
	return result;
}
