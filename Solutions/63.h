#include "common.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
	int dp[obstacleGridColSize];
	int i = 0, j = 0;
	// line 1
	dp[0] = obstacleGrid[i][0] == 0 ? 1 : 0;
	for (j = 1; j < obstacleGridColSize; ++j)
	{
		dp[j] = obstacleGrid[i][j] == 0 ? dp[j - 1] : 0;
	}
	// line 2-obstacleGridRowSize
	for (i = 1; i < obstacleGridRowSize; ++i)
	{
		dp[0] = obstacleGrid[i][0] == 0 ? dp[0] : 0;
		for (j = 1; j < obstacleGridColSize; ++j)
		{
			dp[j] = obstacleGrid[i][j] == 0 ? (dp[j - 1] + dp[j]) : 0;
		}
	}
	return dp[obstacleGridColSize - 1];
}

void Test()
{
	int r1[] = {0, 0, 0};
	int r2[] = {0, 1, 0};
	int r3[] = {0, 0, 0};
	int *g[] = {r1, r2, r3};
	printf("%d\n", uniquePathsWithObstacles(g, 3, 3));
}