#include "common.h"

int countDigitOne(int n) {
	int cnt = 0;
	long k;
	for (k = 1; k <= n; k *= 10)
	{
		int m = n / k;
		cnt += (m + 8) / 10 * k + ((m % 10) == 1 ? (n % k) + 1 : 0);
	}
	return cnt;
}

void Test()
{
	printf("%d\n", countDigitOne(1410065408));
}