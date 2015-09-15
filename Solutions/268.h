#include "common.h"

int missingNumber(int* nums, int numsSize) {
	int i;
	long sum = numsSize*(numsSize + 1) / 2;
	for (i = 0; i < numsSize; ++i)
	{
		sum -= nums[i];
	}
	return (int)sum;
}

void Test()
{
	int a[] = { 0, 1, 3, 5, 4 };
	printf("%d\n", missingNumber(a, sizeof(a) / sizeof(int)));
}