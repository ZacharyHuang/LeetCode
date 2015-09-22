#include "common.h"
#ifdef BiNARY_SEARCH
// two-dimension binary search
//      left      mid2     right
//  top   __________________
//        |        |        |
//        |   A    |    B   |
//  mid1  |________|________|
//	      |        |        |
//        |   C    |    D   |
// bottom |________|________|
// we find a[mid1][mid2] which mid1 = (top + bottom) / 2 and mid2 = (left + right) / 2, and compare it with target
// if a[mid1][mid2] > target, so target must be in area A, B and C if it exists.
// if a[mid1][mid2] < target, so target must be in area B, C and D if it exists.
// if a[mid1][mid2] == target, return true
bool bs(int** a, int top, int bottom, int left, int right, int target)
{
	// return false if area is empty
	if (right < left || bottom < top)
	{
		return false;
	}
	// if there is only one column, we use a one-dimension binary search
	if (left == right)
	{
		int startIndex = top, endIndex = bottom;
		while (startIndex <= endIndex)
		{
			int midIndex = (startIndex + endIndex) >> 1;
			if (a[midIndex][left] < target)
			{
				startIndex = midIndex + 1;
			}
			else if (a[midIndex][left] > target)
			{
				endIndex = midIndex - 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	// if there is only one row, we use a one-dimension binary search
	if (top == bottom)
	{
		int startIndex = left, endIndex = right;
		while (startIndex <= endIndex)
		{
			int midIndex = (startIndex + endIndex) >> 1;
			if (a[top][midIndex] < target)
			{
				startIndex = midIndex + 1;
			}
			else if (a[top][midIndex] > target)
			{
				endIndex = midIndex - 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	// find two-dimension's midIndex
	int mid1 = (top + bottom) >> 1;
	int mid2 = (left + right) >> 1;
	// search area A, B, C if a[mid1][mid2] > target
	if (a[mid1][mid2] > target)
	{
		return bs(a, top, mid1 - 1, left, mid2 - 1, target)
			|| bs(a, mid1, bottom, left, mid2 - 1, target)
			|| bs(a, top, mid1 - 1, mid2, right, target);
	}
	// search area B, C, D if a[mid1][mid2] < target
	else if (a[mid1][mid2] < target)
	{
		return bs(a, top, mid1, mid2 + 1, right, target)
			|| bs(a, mid1 + 1, bottom, left, mid2, target)
			|| bs(a, mid1 + 1, bottom, mid2 + 1, right, target);
	}
	// return true if a[mid1][mid2] == target
	else
	{
		return true;
	}
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	// if the max num is less than target, just return false
	if (matrix[matrixRowSize - 1][matrixColSize - 1] < target)
	{
		return false;
	}
	// start two-dimension search if max num != target
	return matrix[matrixRowSize - 1][matrixColSize - 1] == target
		? true
		: bs(matrix, 0, matrixRowSize - 1, 0, matrixColSize - 1, target);
}
#endif
#define LINEAR
#ifdef LINEAR
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	int i = 0, j = matrixColSize - 1;
	while (i < matrixRowSize && j >= 0)
	{
		if (matrix[i][j] == target)
		{
			return true;
		}
		else if (matrix[i][j] < target)
		{
			++i;
		}
		else
		{
			--j;
		}
	}
	return false;
}
#endif

void Test()
{
	/*int r1[] = { 1, 6, 10, 13, 14, 16, 21 };
	int r2[] = { 3, 10, 12, 18, 22, 27, 29 };
	int r3[] = { 3, 15, 19, 20, 23, 29, 34 };
	int r4[] = { 8, 15, 19, 25, 27, 29, 39 };
	int r5[] = { 12, 17, 24, 25, 28, 29, 41 };
	int r6[] = { 16, 22, 27, 31, 31, 33, 44 };
	int r7[] = { 20, 26, 28, 35, 39, 41, 45 };
	int r8[] = { 25, 31, 34, 39, 44, 45, 47 };
	int *m[] = { r1, r2, r3, r4, r5, r6, r7, r8 };*/
	int r1[] = { 1, 2, 3, 4, 5 };
	int r2[] = { 6, 7, 8, 9, 10 };
	int r3[] = { 11, 12, 13, 14, 15 };
	int r4[] = { 16, 17, 18, 19, 20 };
	int r5[] = { 21, 22, 23, 24, 25 };
	int *m[] = { r1, r2, r3, r4, r5 };
	printf("%d\n", searchMatrix(m, 5, 5, 15));
}