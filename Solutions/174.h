#include "common.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize)
{
	int dp[dungeonColSize];
	int i, j;
	// init line dungeonRowSize
	dp[dungeonColSize - 1] = 1 - MIN(dungeon[dungeonRowSize - 1][dungeonColSize - 1], 0);
	for (j = dungeonColSize - 2; j >= 0; --j)
	{
		dp[j] = MAX(1, dp[j + 1] - dungeon[dungeonRowSize - 1][j]);
	}
	// dp line dungeonRowSize - 1 ~ 1
	for (i = dungeonRowSize - 2; i >= 0; --i)
	{
		dp[dungeonColSize - 1] = MAX(1, dp[dungeonColSize - 1] - dungeon[i][dungeonColSize - 1]);
		for (j = dungeonColSize - 2; j >= 0; --j)
		{
			dp[j] = MAX(1, MIN(dp[j], dp[j + 1]) - dungeon[i][j]);
		}
	}

	return dp[0];
}

void Test()
{
	int r1[] = { -2, -3, 3 };
	int r2[] = { -5, -10, 1 };
	int r3[] = { 10, 30, -5 };
	int *d[] = { r1, r2, r3 };
	printf("%d\n", calculateMinimumHP(d, 3, 3));
}