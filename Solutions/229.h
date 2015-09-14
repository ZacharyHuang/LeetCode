#include "common.h"

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* majorityElement(int* nums, int numsSize, int* returnSize)
{
	int*res = malloc(2 * sizeof(int));
	*returnSize = 0;
	int i, n1 = 0, n2 = 1, cnt1 = 0, cnt2 = 0;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] == n1)
		{
			++cnt1;
		}
		else if (nums[i] == n2)
		{
			++cnt2;
		}
		else if (cnt1 == 0)
		{
			n1 = nums[i];
			cnt1 = 1;
		}
		else if (cnt2 == 0)
		{
			n2 = nums[i];
			cnt2 = 1;
		}
		else
		{
			--cnt1;
			--cnt2;
		}
	}
	cnt1 = cnt2 = 0;
	for (i = 0; i < numsSize; ++i)
	{
		if (nums[i] == n1)
		{
			++cnt1;
		}
		else if (nums[i] == n2)
		{
			++cnt2;
		}
	}
	if (cnt1 > numsSize / 3)
	{
		res[*returnSize] = n1;
		++(*returnSize);
	}
	if (cnt2 > numsSize / 3)
	{
		res[*returnSize] = n2;
		++(*returnSize);
	}
	return res;
}

void Test()
{
	int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	int returnSize = 0;
	int *res = majorityElement(a, sizeof(a) / sizeof(int), &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
	free(res);
}