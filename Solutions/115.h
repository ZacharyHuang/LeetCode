#include "common.h"

int numDistinct(char* s, char* t) {
	int l1 = strlen(s);
	int l2 = strlen(t);
	int dp[l2 + 1];
	int i, j;
	// init line 0
	for (j = 0; j <= l2; ++j)
	{
		dp[j] = j ? 0 : 1;
	}
	// dp line 1 - l1
	for (i = 1; i <= l1; ++i)
	{
		int m = dp[0] = 1;
		for (j = 1; j <= l2; ++j)
		{
			int n = dp[j];
			if (s[i - 1] == t[j - 1])
			{
				dp[j] += m;
			}
			m = n;// record dp[i-1][j-1]
		}
	}
	return dp[l2];
}

void Test()
{
	printf("%d\n", numDistinct("rabbbit", "rabbit"));
}