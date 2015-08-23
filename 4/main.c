#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char** MapCreate(int n)
{
	int i;
	char** map = malloc(n*sizeof(char*));
	for (i = 0; i < n; ++i)
	{
		map[i] = malloc((n + 1)*sizeof(char*));
	}
	return map;
}
void MapDraw(char** map, int n, int *y)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (j == y[i]) map[i][j] = 'Q';
			else map[i][j] = '.';
		}
		map[i][n] = 0;
	}
}
void MapDestroy(char** map, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		free(map[i]);
	}
	free(map);
}
bool canPut(int x, int y, int s, int t)
{
	if (x == s || y == t) return false;
	if (t - y == s - x || t - y == x - s) return false;
	return true;
}
void backTracking(char **** res, int *returnSize, int *y, int n, int x)
{
	int i, j;
	bool put;
	if (x == n)
	{
		++(*returnSize);
		*res = realloc(*res, *returnSize*sizeof(char***));
		char ** map = (*res)[(*returnSize) - 1] = MapCreate(n);
		MapDraw(map, n, y);
	}
	else
	{
		for (i = 0; i < n; ++i)
		{
			put = true;
			for (j = 0; j < x && put; ++j)
			{
				put = canPut(j, y[j], x, i);
			}
			if (put)
			{
				y[x] = i;
				backTracking(res, returnSize, y, n, x + 1);
			}
		}
	}
}
char*** solveNQueens(int n, int* returnSize)
{
	char ***res = NULL;
	*returnSize = 0;
	int *y = malloc(n*sizeof(int));
	backTracking(&res, returnSize, y, n, 0);
	return res;
}
int main()
{
	int n = 1;
	int rs = 0;
	char*** res = solveNQueens(n, &rs);
	while (--rs >= 0)
	{
		int i, j;
		for (i = 0; i < n; ++i)
		{
			printf("%s\n", res[rs][i]);
			free(res[rs][i]);
		}
		free(res[rs]);
	}
	free(res);
	return 0;
}