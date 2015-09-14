#include "common.h"

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

void Helper(char* digits, char* ans, int ansLength, char** res, int* returnSize)
{
	static char map[10][2] = {
		{1, ' '},
		{0, 0},
		{3, 'a'},
		{3, 'd'},
		{3, 'g'},
		{3, 'j'},
		{3, 'm'},
		{4, 'p'},
		{3, 't'},
		{4, 'w'}
	};
	if (*digits == 0)
	{
		res[*returnSize] = calloc(ansLength + 1, sizeof(char));
		memcpy(res[*returnSize], ans, ansLength);
		++(*returnSize);
		return;
	}
	int n = *digits - '0';
	int i = map[n][0];
	while (--i >= 0)
	{
		ans[ansLength] = map[n][1] + i;
		Helper(digits + 1, ans, ansLength + 1, res, returnSize);
	}
}
char** letterCombinations(char* digits, int* returnSize)
{
	int l = strlen(digits);
	*returnSize = 0;
	if (l == 0)
	{
		return NULL;
	}
	char ans[l];
	int size = 1 << (l << 1);
	char** res = malloc(size*sizeof(char*));
	Helper(digits, ans, 0, res, returnSize);
	return res;
}


void Test()
{
	int returnSize = 0;
	char** res = letterCombinations("273", &returnSize);
	while (--returnSize >= 0)
	{
		printf("%s\n", res[returnSize]);
		free(res[returnSize]);
	}
	free(res);
}