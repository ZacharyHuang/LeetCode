#include "common.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
	int l1 = strlen(word1);
	int l2 = strlen(word2);
	int dp[l2 + 1];
	int i, j, k;
	// empty string
	if (l1 == 0 || l2 == 0)
	{
		return l1 ? l1 : l2;
	}

	// init line 0
	for (j = 0; j <= l2; ++j)
	{
		dp[j] = j;
	}

	// dp line 1 - l1
	for (i = 1; i <= l1; ++i)
	{
		// col 0
		k = dp[0];
		dp[0] = i;
		// col 1 - l2
		for (j = 1; j <= l2; ++j)
		{
			int ins = dp[j] + 1;
			int del = dp[j - 1] + 1;
			int rpl = k + (word1[i - 1] != word2[j - 1]);
			k = dp[j];
			dp[j] = MIN(ins, MIN(del, rpl));
		}
	}
	return dp[l2];
}

void Test()
{
	printf("%d\n", minDistance("appche", "apple"));
}