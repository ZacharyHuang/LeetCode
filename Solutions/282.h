#include "common.h"

void bt(char* num, int target, long pre, long mid, long cur, char* a, int ai, char*** res, int* returnSize, int* resSize)
{
	// all numbers are used
	if (*num == 0)
	{
		// save answer if reuslt equals to target
		if (pre + cur * mid == target)
		{
			if (*returnSize >= *resSize)
			{
				(*resSize) <<= 1;
				*res = realloc(*res, (*resSize) * sizeof(char*));
			}
			(*res)[*returnSize] = malloc(ai + 1);
			memcpy((*res)[*returnSize], a, ai);
			(*res)[*returnSize][ai] = 0;
			++(*returnSize);
		}
		return;
	}

	int n = *num - '0';
	// try merge numbers
	if (cur != 0)
	{
		a[ai] = *num;
		bt(num + 1, target, pre, mid, cur * 10 + n, a, ai + 1, res, returnSize, resSize);
	}

	// try times
	a[ai] = '*';
	a[ai + 1] = *num;
	bt(num + 1, target, pre, mid * cur, n, a, ai + 2, res, returnSize, resSize);

	// try plus
	a[ai] = '+';
	a[ai + 1] = *num;
	bt(num + 1, target, pre + mid * cur, 1, n, a, ai + 2, res, returnSize, resSize);

	// try minus
	a[ai] = '-';
	a[ai + 1] = *num;
	bt(num + 1, target, pre + mid * cur, -1, n, a, ai + 2, res, returnSize, resSize);

}

char** addOperators(char* num, int target, int* returnSize) {
	*returnSize = 0;
	if (*num == 0)
	{
		return NULL;
	}
	int resSize = 128;
	char** res = malloc(resSize * sizeof(char*));
	char a[2 * strlen(num)];
	a[0] = *num;
	bt(num + 1, target, 0, 1, *num - '0', a, 1, &res, returnSize, &resSize);
	return res;
}

void Test()
{
	int returnSize = 0;
	char** res = addOperators("123456789", 45, &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
}