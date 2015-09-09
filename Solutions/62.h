#include "common.h"

int uniquePaths(int m, int n)
{
	int i;
	long res = 1;
	if (m < n)
	{
		n += --m - 1;
	}
	else
	{
		i = --m;
		m = --n;
		n += i;
	}

	for (i = 0; i < m; ++i)
	{
		res = res * (n - i) / (1 + i);
	}
	return res;
}

void Test()
{
	printf("%d\n", uniquePaths(7, 3));
}