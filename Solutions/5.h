#include "common.h"

char* longestPalindrome(char* s)
{
	int mid = 0, max = 0, maxIndex = 0;
	while (s[mid])
	{
		int left = mid, right = mid;
		while (s[right + 1] == s[mid])
		{
			++right;
		}
		mid = right + 1;
		while (left > 0 && s[right + 1] == s[left - 1])
		{
			--left;
			++right;
		}
		int length = right - left + 1;
		if (length > max)
		{
			max = length;
			maxIndex = left;
		}
	}
	char* res = calloc(max + 1, sizeof(char));
	memcpy(res, s + maxIndex, max);
	return res;
}

void Test()
{
	char* res = longestPalindrome("abbaabb");
	printf("%s\n", res);
	free(res);
}