#include "common.h"

/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
void hm(int* a, int length, int p)
{
	int l, r, m = p, tmp;
	l = p * 2 + 1;
	r = l + 1;
	if (l < length && a[m] < a[l])
	{
		m = l;
	}
	if (r < length && a[m] < a[r])
	{
		m = r;
	}
	if (m != p)
	{
		tmp = a[p];
		a[p] = a[m];
		a[m] = tmp;
		hm(a, length, m);
	}
}
void hs(int* a, int length)
{
	int i, tmp;
	for (i = length / 2 - 1; i >= 0; --i)
	{
		hm(a, length, i);
	}
	for (i = length - 1; i > 0; --i)
	{
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		hm(a, i, 0);
	}
}
int** threeSum(int* nums, int numsSize, int* returnSize)
{
	int **res;
	int resSize = 128;
	*returnSize = 0;
	res = malloc(resSize * sizeof(int*));
	hs(nums, numsSize);
	int i = 0;
	while (i < numsSize)
	{
		int front = i + 1, back = numsSize - 1, tmp;
		while (front < back)
		{
			tmp = nums[i] + nums[front] + nums[back];
			if (tmp == 0)
			{
				if (resSize == *returnSize)
				{
					resSize <<= 1;
					res = realloc(res, resSize * sizeof(int*));
				}
				res[*returnSize] = malloc(3 * sizeof(int));
				res[*returnSize][0] = nums[i];
				res[*returnSize][1] = nums[front];
				res[*returnSize][2] = nums[back];
				++*returnSize;
				tmp = nums[front++];
				while (front < back && nums[front] == tmp)
				{
					++front;
				}
				tmp = nums[back--];
				while (front < back && nums[back] == tmp)
				{
					--back;
				}
			}
			else if (tmp < 0)
			{
				tmp = nums[front++];
				while (front < back && nums[front] == tmp)
				{
					++front;
				}
			}
			else
			{
				tmp = nums[back--];
				while (front < back && nums[back] == tmp)
				{
					--back;
				}
			}
		}
		tmp = nums[i];
		while (i < numsSize && nums[i] == tmp)
		{
			++i;
		}
	}
	return res;
}

void Test()
{
	int a[] = {-1, 0, 1, 2, -1, -4};
	int returnSize = 0;
	int** res = threeSum(a, sizeof(a) / sizeof(int), &returnSize);
	while (--returnSize >= 0)
	{
		printf("%d %d %d\n", res[returnSize][0], res[returnSize][1], res[returnSize][2]);
		free(res[returnSize]);
	}
	free(res);
}