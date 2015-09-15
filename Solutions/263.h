#include "common.h"

bool isUgly(int num) {
	if (num <= 0)
	{
		return false;
	}
	while (!(num & 1))
	{
		num >>= 1;
	}
	while (num % 3 == 0)
	{
		num /= 3;
	}
	while (num % 5 == 0)
	{
		num /= 5;
	}
	return num == 1;
}

void Test()
{
	printf("%d\n", isUgly(10));
	printf("%d\n", isUgly(-1));
}