#include "common.h"

int Helper(int n, char* s, char* word, int i, bool needSpace)
{
	static const char* table1[] =
	{ "", "One", "Two", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine" };
	static const char* table2[] =
	{ "", "", "Twenty", "Thirty", "Forty", "Fifty",
	"Sixty", "Seventy", "Eighty", "Ninety",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
	"Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	char* tmp;
	if (n >= 100)
	{
		if (needSpace)
		{
			s[i++] = ' ';
		}
		tmp = table1[n / 100];
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
		s[i++] = ' ';
		tmp = "Hundred";
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
		n %= 100;
		needSpace = true;
	}
	if (n >= 20)
	{
		if (needSpace)
		{
			s[i++] = ' ';
		}
		tmp = table2[n / 10];
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
		n %= 10;
		needSpace = true;
	}
	if (n >= 10)
	{
		if (needSpace)
		{
			s[i++] = ' ';
		}
		tmp = table2[n];
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
		n = 0;
	}
	if (n > 0)
	{
		if (needSpace)
		{
			s[i++] = ' ';
		}
		tmp = table1[n];
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
	}
	if (*word)
	{
		s[i++] = ' ';
		tmp = word;
		while (*tmp)
		{
			s[i++] = *tmp++;
		}
	}
	return i;
}

char* numberToWords(int num) {
	char* res = malloc(256);
	int i = 0;
	bool needSpace = false;
	if (num == 0)
	{
		res[0] = 'Z';
		res[1] = 'e';
		res[2] = 'r';
		res[3] = 'o';
		res[4] = 0;
		return res;
	}
	if (num >= 1000000000)
	{
		i = Helper(num / 1000000000,  res,"Billion", i, needSpace);
		num %= 1000000000;
		needSpace = true;
	}
	if (num >= 1000000)
	{
		i = Helper(num / 1000000, res, "Million", i, needSpace);
		num %= 1000000;
		needSpace = true;
	}
	if (num >= 1000)
	{
		i = Helper(num / 1000, res, "Thousand", i, needSpace);
		num %= 1000;
		needSpace = true;
	}
	if (num > 0)
	{
		i = Helper(num, res, "", i, needSpace);
	}
	res[i] = 0;
	return res;
}

void Test()
{
	char* res = numberToWords(2143410518);
	printf("%s\n", res);
	free(res);
}