#include "common.h"

char* convert(char* s, int numRows) {
	if (numRows == 1)
	{
		return s;
	}
	int sLength = strlen(s);
	char* tmp = malloc(sLength);
	int l = 0;
	int k2 = (--numRows) << 1;
	int i = 0, j = 0;
	i = j;
	// line 1:  0  2k  4k  6k ...
	while (i < sLength)
	{
		tmp[l++] = s[i];
		i += k2;
	}
	// line 2~k-1: i  2k-i  2k+i  4k - i ...
	for (j = 1; j < numRows; ++j)
	{
		i = j;
		int m = k2 - i;
		while (i < sLength)
		{
			tmp[l++] = s[i];
			if (m < sLength)
			{
				tmp[l++] = s[m];
			}
			i += k2;
			m += k2;
		}
	}
	i = j;
	// line k: k  3k  5k ...
	while (i < sLength)
	{
		tmp[l++] = s[i];
		i += k2;
	}
	memcpy(s, tmp, sLength);
	free(tmp);
	return s;
}

void Test()
{
	char str[] = "PAYPALISHIRING";
	printf("%s", convert(str, 3));
}