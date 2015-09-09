#include "common.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int maxArea(int* height, int heightSize) {
	// can not contain any water
	if (heightSize < 2)
	{
		return 0;
	}
	int left = 0, right = heightSize - 1;
	int max = 0;
	// calculate area and move indices
	do
	{
		// get lower height and higher height of left and right
		int low, high;
		if (height[left] < height[right])
		{
			low = height[left];
			high = height[right];
		}
		else
		{
			low = height[right];
			high = height[left];
		}

		// update max area
		int width = right - left;
		max = MAX(max, low * width);

		// move indices
		// 1. the high height * width can not reach the max area, we need to move both two indices until they are higher than high height
		if (high * width < max)
		{
			bool moveLeft = height[left] <= high;
			bool moveRight = height[right] <= high;
			while (left < right && (moveLeft || moveRight))
			{
				if (moveLeft)
				{
					++left;
				}
				if (moveRight)
				{
					--right;
				}
			}
		}
		// 2. the high height * width can not reach the max area, we just need move the lower index until it is higher than low
		else
		{
			// 2.1 left is lower
			if (height[left] < height[right])
			{
				while (height[left] <= low)
				{
					++left;
				}
			}
			// 2.2 right is lower
			else if (height[right] < height[left])
			{
				while (height[right] <= low)
				{
					--right;
				}
			}
			// 2.3 left and right are the same height, we need to move the index which get a higher height first
			else
			{
				int le = left, ri = right;
				while (left < right && height[left] <= low && height[right] <= low)
				{
					++left;
					--right;
				}
				// recover the other index if a higher index found
				if (left < right)
				{
					if (height[left] > height[right])
					{
						right = ri;
					}
					else
					{
						left = le;
					}
				}
			}
		}
	} while (left < right);
	return max;
}

void Test()
{
	int h[] = {1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1};
	printf("%d\n", maxArea(h, sizeof(h) / sizeof(int)));
}