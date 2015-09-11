#include "common.h"

#define MIN(a,b) ((a)<(b)?(a):(b))

int nthUglyNumber(int n) {
	static int uglyNumber[10000] = { 0, 1 };
	static int i1 = 1, i2 = 1, i3 = 1, i = 1;

	while (i < n)
	{
		int a1 = uglyNumber[i1] * 2;
		int a2 = uglyNumber[i2] * 3;
		int a3 = uglyNumber[i3] * 5;
		uglyNumber[++i] = MIN(a1, MIN(a2, a3));
		if (a1 == uglyNumber[i])
		{
			++i1;
		}
		if (a2 == uglyNumber[i])
		{
			++i2;
		}
		if (a3 == uglyNumber[i])
		{
			++i3;
		}
	}

	return uglyNumber[n];
}

void Test()
{
	printf("%d\n", nthUglyNumber(10));
}