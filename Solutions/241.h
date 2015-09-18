#include "common.h"


int* Helper(int* nums, char* opts, int optsSize, int* returnSize)
{
	int* res;
	// just a number
	if (optsSize == 0)
	{
		*returnSize = 1;
		res = malloc(sizeof(int));
		res[0] = nums[0];
		return res;
	}
	// just two number with a operation
	if (optsSize == 1)
	{
		*returnSize = 1;
		res = malloc(sizeof(int));
		if (opts[0] == '+')
		{
			res[0] = nums[0] + nums[1];
		}
		else if (opts[0] == '-')
		{
			res[0] = nums[0] - nums[1];
		}
		else
		{
			res[0] = nums[0] * nums[1];
		}
		return res;
	}
	// select a operation and get all possible results of both sides
	*returnSize = 0;
	int leftSize[optsSize], rightSize[optsSize];
	int *left[optsSize], *right[optsSize];
	int i;
	for (i = 0; i < optsSize; ++i)
	{
		left[i] = Helper(nums, opts, i, &leftSize[i]);
		right[i] = Helper(nums + i + 1, opts + i + 1, optsSize - i - 1, &rightSize[i]);
		*returnSize += leftSize[i] * rightSize[i];
	}
	// generate results
	res = malloc((*returnSize) * sizeof(int));
	int j, k, l = 0;
	for (i = 0; i < optsSize; ++i)
	{
		for (j = 0; j < leftSize[i]; ++j)
		{
			for (k = 0; k < rightSize[i]; ++k)
			{
				if (opts[i] == '+')
				{
					res[l++] = left[i][j] + right[i][k];
				}
				else if (opts[i] == '-')
				{
					res[l++] = left[i][j] - right[i][k];
				}
				else
				{
					res[l++] = left[i][j] * right[i][k];
				}
			}
		}
		free(left[i]);
		free(right[i]);
	}
	return res;
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* diffWaysToCompute(char* input, int* returnSize) 
{
	int len = strlen(input);
	// save numbers and operations in two arrays
	int nums[len];
	char opts[len];
	int n = 0;
	int numsSize = 0, optsSize = 0;
	while (*input)
	{
		if ('0' <= *input && *input <= '9')
		{
			n = n * 10 + *input - '0';
		}
		else
		{
			nums[numsSize++] = n;
			n = 0;
			opts[optsSize++] = *input;
		}
		++input;
	}
	nums[numsSize++] = n;
	*returnSize = 0;
	return Helper(nums, opts, optsSize, returnSize);
}

void Test()
{
	int returnSize = 0;
	int* res = diffWaysToCompute("2*3-4*5", &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%d\n", res[i]);
	}
	free(res);
}