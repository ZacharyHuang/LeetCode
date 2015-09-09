#include "common.h"

bool isPalindrome(int x) {
	if (x < 0 || (x > 1000000000 && (x % 10) > 2))
	{
		return false;
	}
	int y = x;
	long z = 0;
	do
	{
		z = z * 10 + (x % 10);
	} while (x /= 10);
	if (z > INT_MAX)
	{
		return false;
	}
	return z == y;
}

void Test()
{
	printf("%d %d\n", isPalindrome(12321), isPalindrome(1234567899));
}