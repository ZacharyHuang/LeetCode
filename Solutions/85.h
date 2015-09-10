#include "common.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
	int left[matrixColSize];
	int right[matrixColSize];
	int height[matrixColSize];
	int maxArea = 0;
	int i, j;
	// init dp array
	for (j = 0; j < matrixColSize; ++j)
	{
		left[j] = height[j] = 0;
		right[j] = matrixColSize;
	}

	// start dp
	for (i = 0; i < matrixRowSize; ++i)
	{
		int cur;
		// set left and height
		for (cur = j = 0; j < matrixColSize; ++j)
		{
			if (matrix[i][j] == '1')
			{
				left[j] = MAX(left[j], cur);
				++height[j];
			}
			else
			{
				left[j] = 0;
				height[j] = 0;
				cur = j + 1;
			}
		}
		// set right and calculate area
		for (cur = matrixColSize, j = cur - 1; j >= 0; --j)
		{
			if (matrix[i][j] == '1')
			{
				right[j] = MIN(right[j], cur);
				int area = (right[j] - left[j]) * height[j];
				maxArea = MAX(maxArea, area);
			}
			else
			{
				right[j] = matrixColSize;
				cur = j;
			}
		}
	}

	return maxArea;
}

void Test()
{
	char r1[] = "0001000";
	char r2[] = "0011100";
	char r3[] = "0111110";
	char* m[] = { r1, r2, r3 };
	printf("%d\n", maximalRectangle(m, 3, 7));
}