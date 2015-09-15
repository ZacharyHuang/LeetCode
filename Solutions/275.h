#include "common.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int hIndex(int* citations, int citationsSize) {
	int index = 0;
	int startIndex = 0, endIndex = citationsSize - 1;
	while (startIndex <= endIndex)
	{
		int midIndex = (startIndex + endIndex) >> 1;
		int len = citationsSize - midIndex;
		index = MAX(index, MIN(len, citations[midIndex]));
		if (citations[midIndex] <= len)
		{
			startIndex = midIndex + 1;
		}
		else
		{
			endIndex = midIndex - 1;
		}
	}
	return index;
}

void Test()
{
	int c[] = { 0, 1 };
	printf("%d\n", hIndex(c, sizeof(c) / sizeof(int)));
}