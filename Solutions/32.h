#include "common.h"

int longestValidParentheses(char* s) {
	int i = 0, stack = 0, max = 0;
	int dp[100000];
	for (i = 0; s[i]; ++i)
	{
		if (s[i] == '(')
		{
			++stack;
			dp[i] = 0;
		}
		else
		{
			if (--stack < 0)
			{
				dp[i] = stack = 0;
			}
			else
			{
				dp[i] = dp[i - 1] + 2;
				if (i - dp[i] > 0)
				{
					dp[i] += dp[i - dp[i]];
				}
				max = max > dp[i] ? max : dp[i];
			}
		}
	}
	return max;
}

void Test()
{
	printf("%d\n", longestValidParentheses(")(()())())("));
}