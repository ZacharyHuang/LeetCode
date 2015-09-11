#include "common.h"

int rob(int* nums, int numsSize) {
	int sum1 = 0, sum2 = 0, max = 0, tmp;
	int i;
	// in case there is only one house
	if (numsSize == 1)
	{
		return nums[0];
	}
	--numsSize;
	// rob first and skip last
	for (i = 0; i < numsSize; ++i)
	{
		// the previous house is skipped, than rob this house
		if (sum1 == sum2)
		{
			sum2 += nums[i];
		}
		// the previous house is not skipped
		else
		{
			tmp = sum1 + nums[i];
			sum1 = sum2;
			// rob this house could get more money than robbing the previous one, then rob it, otherwise just skip it
			if (tmp > sum2)
			{
				sum2 = tmp;
			}
		}
	}
	max = sum2;
	sum1 = sum2 = 0;
	// rob last and skip first
	for (i = 1; i <= numsSize; ++i)
	{
		// the previous house is skipped, than rob this house
		if (sum1 == sum2)
		{
			sum2 += nums[i];
		}
		// the previous house is not skipped
		else
		{
			tmp = sum1 + nums[i];
			sum1 = sum2;
			// rob this house could get more money than robbing the previous one, then rob it, otherwise just skip it
			if (tmp > sum2)
			{
				sum2 = tmp;
			}
		}
	}
	return max > sum2 ? max : sum2;
}

void Test()
{
	int h[] = { 1, 2, 3, 4, 4, 5, 6, 7, 8 };
	printf("%d\n", rob(h, sizeof(h) / sizeof(int)));
}