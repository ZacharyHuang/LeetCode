#include "common.h"

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize == 0)
	{
		return 0;
	}
	int i, buyPrice = INT_MAX, max = 0;
	for (i = 0; i < pricesSize; ++i)
	{
		if (prices[i] < buyPrice)
		{
			buyPrice = prices[i];
		}
		else
		{
			int profit = prices[i] - buyPrice;
			max = max > profit ? max : profit;
		}
	}
	return max;
}

void Test()
{
	int p[] = { 3, 5, 2, 7, 1, 4, 2, 6, 4, 9, 1, 3 };
	printf("%d\n", maxProfit(p, sizeof(p) / sizeof(int)));
}