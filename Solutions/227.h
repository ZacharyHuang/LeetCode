#include "common.h"

int calculate(char* s) {
	int pre = 0, cur = 1, n = 0;
	char opt = '+';
	while (true)
	{
		if (*s <= '9' && *s >= '0')
		{
			n = n * 10 + *s - '0';
		}
		else if (*s == '*' || *s == '/')
		{
			if (opt == '+')
			{
				cur = n;
			}
			else if (opt == '-')
			{
				cur = -n;
			}
			else if (opt == '*')
			{
				cur *= n;
			}
			else
			{
				cur /= n;
			}
			opt = *s;
			n = 0;
		}
		else if (*s == '+' || *s == '-')
		{
			if (opt == '+')
			{
				pre += n;
			}
			else if (opt == '-')
			{
				pre -= n;
			}
			else if (opt == '*')
			{
				pre += cur * n;
			}
			else
			{
				pre += cur / n;
			}
			opt = *s;
			n = 0;
		}
		else if (*s == 0)
		{
			if (opt == '+')
			{
				return pre + n;
			}
			else if (opt == '-')
			{
				return pre - n;
			}
			else if (opt == '*')
			{
				return pre + cur * n;
			}
			else
			{
				return pre + cur / n;
			}
		}
		++s;
	}
}

void Test()
{
	printf("%d\n", calculate("1+2*3-4+5*6/7"));
	printf("%d\n", calculate("3+2*2"));
	printf("%d\n", calculate("3+5/2"));
}