#include "common.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize)
{
	if (pricesSize <= 1)
	{
		return 0;
	}
	int i, price;
	int front[pricesSize];// front[i] is max profit of prices[0 ~ i]
	int back[pricesSize];// back[i] is max profit of prices[i ~ pricesSize - 1]
	// set front
	for (i = 1, price = prices[0], front[0] = 0; i < pricesSize; ++i)
	{
		if (prices[i] < price)
		{
			price = prices[i];
			front[i] = front[i - 1];
		}
		else
		{
			front[i] = MAX(front[i - 1], prices[i] - price);
		}
	}
	// set back
	for (i = pricesSize - 2, price = prices[pricesSize - 1], back[pricesSize - 1] = 0; i >= 0; --i)
	{
		if (prices[i] > price)
		{
			price = prices[i];
			back[i] = back[i + 1];
		}
		else
		{
			back[i] = MAX(back[i + 1], price - prices[i]);
		}
	}
	// profit is max of front[i - 1] + back[i] where i = 1 ~ pricesSize - 1
	int max = back[0];// incase one transaction is enough
	for (i = 1; i < pricesSize; ++i)
	{
		int profit = front[i - 1] + back[i];
		max = MAX(max, profit);
	}
	return max;
}