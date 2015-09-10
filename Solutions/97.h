#include "common.h"

bool isInterleave(char* s1, char* s2, char* s3) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int l3 = strlen(s3);
	// check length
	if (l1 + l2 != l3)
	{
		return false;
	}
	// check character
	int cnt[128] = { 0 };
	int i, j;
	for (i = 0; i < l1; ++i)
	{
		++cnt[s1[i]];
	}
	for (i = 0; i < l2; ++i)
	{
		++cnt[s2[i]];
	}
	for (i = 0; i < l3; ++i)
	{
		if (--cnt[s3[i]] < 0)
		{
			return false;
		}
	}
	// dp
	bool dp[l2 + 1];
	// init line 0
	dp[0] = true;
	for (j = 1; j <= l2 && s2[j - 1] == s3[j - 1]; ++j)
	{
		dp[j] = true;
	}
	// dp line 1 - l1
	for (i = 1; i <= l1; ++i)
	{
		dp[0] = s1[i - 1] == s3[i - 1] ? dp[0] : false;
		for (j = 1; j <= l2; ++j)
		{
			dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
	}
	return dp[l2];
}

void Test()
{
	printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbcbcac"));
	printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}