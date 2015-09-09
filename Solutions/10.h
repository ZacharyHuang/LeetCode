#include "common.h"

bool isMatch(char* s, char* p) {
	// match single characters
	while (*s && *p && *(p + 1) != '*')
	{
		if (*p == *s || *p == '.')
		{
			++p;
			++s;
		}
		else
		{
			return false;
		}
	}
	// p is empty
	if (*p == 0)
	{
		return *s == 0;
	}
	// s is empty but p is not '?*'
	if (*s == 0 && *(p + 1) != '*')
	{
		return false;
	}
	// p is not empty, so *(p+1) must be '*'
	// skip useless '?*'
	while (*(p + 2) != 0 && *(p + 3) == '*' && (*p == *(p + 2) || *(p + 2) == '.'))
	{
		p += 2;
	}
	// p is '?*'
	if (*(p + 2) == 0)
	{
		// p is '.*'
		if (*p == '.')
		{
			return true;
		}
		// p is 'a*'
		while (*s && *s == *p)
		{
			++s;
		}
		return *s == 0;
	}
	// p is '?*???'
	// try every possible case
	do
	{
		// go on match
		if (isMatch(s, p + 2))
		{
			return true;
		}
	} while (*s && (*s++ == *p || *p == '.')); // skip a character
	return false;
}

void Test()
{
	printf("%d\n", isMatch("ab", ".*c"));
}