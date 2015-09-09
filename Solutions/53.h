#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
	int i, j;
	int dp[gridColSize];
	// row 1
	dp[0] = grid[0][0];
	for (j = 1; j < gridColSize; ++j)
	{
		dp[j] = dp[j - 1] + grid[0][j];
	}
	// row 2 - gridRowSize
	for (i = 1; i < gridRowSize; ++i)
	{
		dp[0] += grid[i][0];
		for (j = 1; j < gridColSize; ++j)
		{
			dp[j] = MIN(dp[j], dp[j - 1]) + grid[i][j];
		}
	}
	return dp[gridColSize - 1];
}

void Test()
{
	int r1[] = { 1, 2, 3 };
	int r2[] = { 2, 3, 4 };
	int r3[] = { 3, 4, 5 };
	int *g[] = { r1, r2, r3 };
	printf("%d\n", minPathSum(g, 3, 3));
}