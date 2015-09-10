#include "common.h"

int numDecodings(char* s) {
	if (*s == 0 || *s == '0')
	{
		return 0;
	}
	int n[2] = { 1, 1 };
	int tmp;
	char last = *s;
	while (*(++s))
	{
		tmp = n[1];
		if (*s == '0')
		{
			if (last == '2' || last == '1')
			{
				n[1] = n[0];
			}
			else
			{
				n[1] = 0;
			}
		}
		else if (last == '1' || (last == '2' && *s > '0' && *s <= '6'))
		{
			n[1] += n[0];
		}
		n[0] = tmp;
		last = *s;
	}
	return n[1];
}

void Test()
{
	printf("%d\n", numDecodings("110"));
}