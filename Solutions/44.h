#include "common.h"

bool isMatch(char* s, char* p) {
	char* afterStar = NULL;
	char* record = s;
	while (*s)
	{
		if (*p == '*')
		{
			while (*(++p) == '*');
			afterStar = p;
			record = s;
		}
		else if (*s == *p || *p == '?')
		{
			++s;
			++p;
		}
		else if (afterStar)
		{
			p = afterStar;
			s = ++record;
		}
		else
		{
			return false;
		}
	}
	while (*p == '*')
	{
		++p;
	}
	return *p == 0;
}

void Test()
{
	printf("%d\n", isMatch("aa", "*"));
	printf("%d\n", isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
}