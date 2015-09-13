#include "common.h"

char* Helper(int count, char* s, char* c)
{
	if (count <= 3)
	{
		while (count > 0)
		{
			*s++ = c[0];
			--count;
		}
	}
	else if (count == 4)
	{
		*s++ = c[0];
		*s++ = c[1];
	}
	else if (count == 5)
	{
		*s++ = c[1];
	}
	else if (count <= 8)
	{
		*s++ = c[1];
		while (count > 5)
		{
			*s++ = c[0];
			--count;
		}
	}
	else if (count == 9)
	{
		*s++ = c[0];
		*s++ = c[2];
	}
	return s;
}

char* intToRoman(int num)
{
	char* table = "IVXLCDM";
	char* res = calloc(20, sizeof(char));
	char* s = res;
	int count;
	if (num >= 1000)
	{
		s = Helper(num / 1000, s, table + 6);
		num %= 1000;
	}
	if (num >= 100)
	{
		s = Helper(num / 100, s, table + 4);
		num %= 100;
	}
	if (num >= 10)
	{
		s = Helper(num / 10, s, table + 2);
		num %= 10;
	}
	if (num >= 1)
	{
		s = Helper(num, s, table);
	}
	return res;
}

void Test()
{
	char* s = intToRoman(1849);
	printf("%s\n", s);
	free(s);
}