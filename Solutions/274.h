#include "common.h"

int hIndex(int* citations, int citationsSize) {
	int* cnt = calloc(citationsSize + 1, sizeof(int));
	int i;
	for (i = 0; i < citationsSize; ++i)
	{
		if (citations[i] > citationsSize)
		{
			++cnt[citationsSize];
		}
		else
		{
			++cnt[citations[i]];
		}
	}

	for (i = citationsSize; i >= 0; --i)
	{
		if (i < citationsSize)
		{
			cnt[i] += cnt[i + 1];
		}
		if (cnt[i] >= i)
		{
			free(cnt);
			return i;
		}
	}
}

void Test()
{
	int c[] = { 3, 0, 6, 1, 5 };
	printf("%d\n", hIndex(c, sizeof(c) / sizeof(int)));
}