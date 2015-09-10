#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int **triangle, int numRows) {
	int i, j;
	for (i = numRows - 2; i >= 0; --i)
	{
		for (j = 0; j <= i; ++j)
		{
			triangle[i][j] += MIN(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}

void Test()
{
	int r1[] = { -1 };
	int r2[] = { 2, 3 };
	int r3[] = { 1, -1, -1 };
	int *t[] = { r1, r2, r3 };
	printf("%d\n", minimumTotal(t, 3));
}