#include "common.h"

int reverse(int x) {
	long y = 0;
	while (x)
	{
		y = y * 10 + (x % 10);
		x /= 10;
	}
	return (y > INT_MAX || y < INT_MIN) ? 0 : y;
}

void Test()
{
	printf("%d\n", reverse(123456));
}