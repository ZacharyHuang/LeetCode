#include "common.h"

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
	*returnSize = 0;
	char** res = malloc(numsSize*sizeof(char*));
	if (numsSize == 0)
	{
		return NULL;
	}
	int i;
	int front, back;
	front = back = nums[0];
	for (i = 1; i < numsSize; ++i)
	{
		if (nums[i] == back + 1)
		{
			back = nums[i];
		}
		else
		{
			if (front == back)
			{
				res[*returnSize] = malloc(12);
				sprintf(res[*returnSize], "%d", front);
			}
			else
			{
				res[*returnSize] = malloc(24);
				sprintf(res[*returnSize], "%d->%d", front, back);
			}
			++(*returnSize);
			front = back = nums[i];
		}
	}
	if (front == back)
	{
		res[*returnSize] = malloc(12);
		sprintf(res[*returnSize], "%d", front);
	}
	else
	{
		res[*returnSize] = malloc(24);
		sprintf(res[*returnSize], "%d->%d", front, back);
	}
	++(*returnSize);
	return res;
}

void Test()
{
	int a[] = {0, 1, 2, 4, 5, 7};
	int i, returnSize = 0;
	char** res = summaryRanges(a, sizeof(a) / sizeof(int), &returnSize);
	for (i = 0; i < returnSize; ++i)
	{
		printf("%s", res[i]);
		free(res[i]);
	}
	free(res);
}