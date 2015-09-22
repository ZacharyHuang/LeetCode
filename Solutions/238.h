#include "common.h"

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int* res = malloc(numsSize*sizeof(int));
	// save second half in the res
	int i;
	res[numsSize - 1] = 1;
	for (i = numsSize - 1; i > 0; --i)
	{
		res[i - 1] = res[i] * nums[i];
	}
	// save first half in the nums and merge with res
	for (i = 1; i < numsSize; ++i)
	{
		nums[i] *= nums[i - 1];
		res[i] *= nums[i - 1];
	}
	*returnSize = numsSize;
	return res;
}

void Test()
{
	int a[] = { 1, 2, 3, 4 };
	int returnSize = 0;
	int* res = productExceptSelf(a, sizeof(a) / sizeof(int), &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
	free(res);
}