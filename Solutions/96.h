int numTrees(int n)
{
	static int dp[100] = {1, 1, 2, 5, 0};
	if (dp[n] == 0)
	{
		int i, sum = 0;
		for (i = 0; i < n; ++i)
		{
			sum += numTrees(i) * numTrees(n - i - 1);
		}
		return dp[n] = sum;
	}
	else
	{
		return dp[n];
	}
}

void Test()
{
	printf("%d\n", numTrees(10));
}