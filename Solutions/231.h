#include "common.h"

bool isPowerOfTwo(int n) {
	return n > 0 ? (n & (n - 1)) == 0 : false;
}

void Test()
{
	printf("%d\n", isPowerOfTwo(1<<10));
	printf("%d\n", isPowerOfTwo(0));
	printf("%d\n", isPowerOfTwo(INT_MIN));
}