#include "common.h"

int maxSubArray(int* nums, int numsSize)
{
	int sum = 0, max = nums[0];
	int i;
	for (i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
		max = max > sum ? max : sum;
		if (sum < 0)
		{
			sum = 0;
		}
	}
	return max;
}

void Test()
{
	int n[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	printf("%d\n", maxSubArray(n, sizeof(n) / sizeof(int)));
}