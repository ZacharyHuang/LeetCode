#include "common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define METHOD 1
#if METHOD == 1
#define MINANDMAX(a,b,c,min,max) \
{\
	if (a < b)\
	{\
		if (a < c)\
		{\
			min = a; \
			max = MAX(b, c); \
		}\
		else\
		{\
			min = c; \
			max = b; \
		}\
	}\
	else\
	{\
		if (b < c)\
		{\
			min = b; \
			max = MAX(a, c); \
		}\
		else\
		{\
			min = c; \
			max = a; \
		}\
	}\
}

int maxProduct(int* nums, int numsSize) {
	int i, p = nums[0], n = nums[0], max = nums[0];
	for (i = 1; i < numsSize; ++i)
	{
		int a = n * nums[i];
		int b = p * nums[i];
		MINANDMAX(a, b, nums[i], n, p);
		max = MAX(max, p);
	}
	return max;
}
#else
int maxProduct(int* nums, int numsSize) {
	int i, front = 0, back = 0, res = -2147483648, n = numsSize - 1;

	for (i = 0; i < numsSize; ++i)
	{
		front = front ? front * nums[i] : nums[i];
		back = back ? back * nums[n - i] : nums[n - i];
		res = MAX(res, MAX(front, back));
	}
	return res;
}
#endif
void Test()
{
	int a[] = { -2, -3, -4 };
	printf("%d\n", maxProduct(a, sizeof(a) / sizeof(int)));
}