#include "common.h"

int lengthOfLongestSubstring(char* s)
{
	char* index[256] = { NULL };// record the appear index of each charater
	char *start = s;// start index of substring
	int maxl = 0;// max length of substring
	while (*s)
	{
		// get the index of last time this character appeared
		char* tmp = index[*s];

		// index is greater than start means this is the second time it appears
		if (tmp >= start)
		{
			// check max length
			maxl = s - start > maxl ? s - start : maxl;

			// update start
			start = tmp + 1;
		}

		// record this character's index
		index[*s] = s++;
	}

	// check current length, return the max length
	return s - start > maxl ? s - start : maxl;
}
void Test()
{
	printf("%d\n", lengthOfLongestSubstring("abcdabc"));
}