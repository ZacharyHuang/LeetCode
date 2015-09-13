#include "common.h"

int romanToInt(char* s)
{
	int n = 0;
	while (*s == 'M')
	{
		n += 1000;
		++s;
	}
	if (*s == 'D')
	{
		n += 500;
		++s;
	}
	if (*s == 'C')
	{
		n += 100;
		++s;
		if (*s == 'M')
		{
			n += 800;
			++s;
		}
		else if (*s == 'D')
		{
			n += 300;
			++s;
		}
	}
	else if (*s == 'D')
	{
		n += 500;
		++s;
	}
	while (*s == 'C')
	{
		n += 100;
		++s;
	}
	if (*s == 'X')
	{
		n += 10;
		++s;
		if (*s == 'C')
		{
			n += 80;
			++s;
		}
		else if (*s == 'L')
		{
			n += 30;
			++s;
		}
	}
	else if (*s == 'L')
	{
		n += 50;
		++s;
	}
	while (*s == 'X')
	{
		n += 10;
		++s;
	}
	if (*s == 'I')
	{
		n += 1;
		++s;
		if (*s == 'X')
		{
			n += 8;
			++s;
		}
		else if (*s == 'V')
		{
			n += 3;
			++s;
		}
	}
	else if (*s == 'V')
	{
		n += 5;
		++s;
	}
	while (*s == 'I')
	{
		n += 1;
		++s;
	}
	return n;
}

void Test()
{
	printf("%d\n", romanToInt("MDCCCLXXXIV"));
}