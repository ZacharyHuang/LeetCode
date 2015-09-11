#include "common.h"

int rob(int* nums, int numsSize) {
	int sum1 = 0;
	int sum2 = 0;
	int tmp;
	int i;
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
	return sum2;
}

void Test()
{
	int h[] = { 1, 2, 3, 4, 4, 5, 6, 7, 8 };
	printf("%d\n", rob(h, sizeof(h) / sizeof(int)));
}