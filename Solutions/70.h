#include "common.h"

int climbStairs(int n)
{
	static int steps[1000] = {1, 1, 2, 0};
	static int stepIndex = 2;
	if (steps[n] == 0)
	{
		while (stepIndex < n)
		{
			steps[++stepIndex] = steps[stepIndex - 1] + steps[stepIndex - 2];
		}
	}
	return steps[n];
}

void Test()
{
	printf("%d\n", climbStairs(4));
}