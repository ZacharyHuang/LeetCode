#include "common.h"

bool isAnagram(char* s, char* t) {
	int cnt[128] = { 0 };
	while (*s && *t)
	{
		++cnt[*s++];
		--cnt[*t++];
	}
	if (*s || *t)
	{
		return false;
	}
	int i;
	for (i = 'a'; i <= 'z'; ++i)
	{
		if (cnt[i] > 0)
		{
			return false;
		}
	}
	return true;
}

void Test()
{
	printf("%d\n", isAnagram("cat", "art"));
	printf("%d\n", isAnagram("cat", "act"));
}