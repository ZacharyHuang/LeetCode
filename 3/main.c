#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int lengthOfLongestSubstring(char* s)
{
	char* index[256] = {NULL};
	char *t = s, *tmp;
	int maxl = 0;
	while (*s)
	{
		tmp = index[*s];
		if (tmp >= t)
		{
			maxl = s - t > maxl ? s - t : maxl;
			t = tmp + 1;
		}
		index[*s] = s++;
	}
	return s - t > maxl ? s - t : maxl;
}
int main()
{
	printf("%d\n", lengthOfLongestSubstring("abcdabc"));
	return 0;
}