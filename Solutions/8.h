#include "common.h"

int myAtoi(char* str) {
	long int x = 0;
	int flag = 1;
	int num = 0;
	while (*str == ' ') ++str;
	if (*str == '-')
	{
		flag = -1;
		++str;
	}
	else if (*str == '+')
	{
		++str;
	}
	while (*str <= '9' && '0' <= *str)
	{
		num = 1;
		x = x * 10 + *str - '0';
		if (x > INT_MAX) return (flag > 0) ? INT_MAX : INT_MIN;
		++str;
	}
	if (num == 0) return 0;
	return (flag > 0) ? (int)x : (int)-x;
}

void Test()
{
	printf("%d\n", myAtoi(" -123456 "));
}