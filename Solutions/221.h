#include "common.h"

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
	int i, j;
	int left[matrixColSize];
	int right[matrixColSize];
	int height[matrixColSize];
	int maxLength = 0;
	// init
	for (j = 0; j <= matrixColSize; ++j)
	{
		left[j] = height[j] = 0;
		right[j] = matrixColSize;
	}

	for (i = 0; i < matrixRowSize; ++i)
	{
		int cur = 0;
		// set left and height
		for (j = 0; j < matrixColSize; ++j)
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
		cur = matrixColSize;
		for (j = matrixColSize - 1; j >= 0; --j)
		{
			if (matrix[i][j] == '1')
			{
				right[j] = MIN(right[j], cur);
				int length = MIN(right[j] - left[j], height[j]);
				maxLength = maxLength > length ? maxLength : length;
			}
			else
			{
				right[j] = matrixColSize;
				cur = j;
			}
		}
	}

	return maxLength * maxLength;
}

void Test()
{
	char r1[] = "1101";
	char r2[] = "1101";
	char r3[] = "1111";
	char *m[] = { r1, r2, r3 };
	printf("%d\n", maximalSquare(m, 3, 4));
}