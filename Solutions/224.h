#include "common.h"

int helper(char** _s)
{
	int pre = 0, n = 0;
	char opt = '+';
	char* s = *_s;
	while (true)
	{
		if (*s >= '0' && *s <= '9')
		{
			n = n * 10 + *s - '0';
		}
		else if (*s == '+' || *s == '-')
		{
			pre = opt == '+' ? pre + n : pre - n;
			n = 0;
			opt = *s;
		}
		else if (*s == '(')
		{
			++s;
			n = helper(&s);
		}
		else if (*s == ')' || *s == 0)
		{
			*_s = *s == ')' ? s : s - 1;
			return opt == '+' ? pre + n : pre - n;
		}
		++s;
	}
}

int calculate(char* s) {
	return helper(&s);
}

void Test()
{
	printf("%d\n", calculate("1 + 1"));
	printf("%d\n", calculate(" 2-1 + 2"));
	printf("%d\n", calculate("(1+(4+5+2)-3_+(6+8)"));
}