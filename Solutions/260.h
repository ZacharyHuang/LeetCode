#include "common.h"

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int *res = malloc(2 * sizeof(int));
	*returnSize = 2;
	int ab = 0, i;
	// get a ^ b
	for (i = 0; i < numsSize; ++i)
	{
		ab ^= nums[i];
	}
	// get a bit 1 from a ^ b, which means that a's bit is different from b's
	int bit = 1;
	while (!(ab & bit))
	{
		bit <<= 1;
	}
	// get a or b from nums that nums & bit != 0
	res[0] = 0;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] & bit)
		{
			res[0] ^= nums[i];
		}
	}
	// then the other is a ^ b ^ a
	res[1] = ab ^ res[0];
	return res;
}

void Test()
{
	int n[] = { 1, 2, 1, 3, 2, 5 };
	int returnSize = 0;
	int* res = singleNumber(n, sizeof(n) / sizeof(int), &returnSize);
	printf("%d %d\n", res[0], res[1]);
	free(res);
}