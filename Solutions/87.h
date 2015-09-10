#include "common.h"

bool helper(char* s1, char* s2, int length)
{
	if (length == 1)
	{
		return s1[0] == s2[0];
	}
	if (length == 2)
	{
		return (s1[0] == s2[0] && s1[1] == s2[1]) || (s1[0] == s2[1] && s1[1] == s2[0]);
	}

	int i;
	if (length > 3)
	{
		int cnt[128] = { 0 };
		for (i = 0; i < length; ++i)
		{
			++cnt[s1[i]];
			--cnt[s2[i]];
		}
		for (i = 'A'; i <= 'z'; ++i)
		{
			if (cnt[i] != 0)
			{
				return false;
			}
		}
	}

	for (i = 1; i < length; ++i)
	{
		if (
			(helper(s1, s2, i) && helper(s1 + i, s2 + i, length - i))
			|| (helper(s1, s2 + length - i, i) && helper(s1 + i, s2, length - i))
			)
		{
			return true;
		}
	}
	return false;
}

bool isScramble(char* s1, char* s2) {
	int l = strlen(s1);
	return helper(s1, s2, l);
}

void Test()
{
	printf("%d\n", isScramble("great", "rgate"));
}