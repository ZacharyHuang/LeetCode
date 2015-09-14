#include "common.h"

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
/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
	int **res;
	int resSize = 128;
	*returnSize = 0;
	res = malloc(resSize * sizeof(int*));
	hs(nums, numsSize);
	int i = 0;
	while (i < numsSize)
	{
		int j = i + 1, tmp;
		while (j < numsSize)
		{
			int front = j + 1, back = numsSize - 1;
			while (front < back)
			{
				tmp = nums[i] + nums[j] + nums[front] + nums[back] - target;
				if (tmp == 0)
				{
					if (resSize == *returnSize)
					{
						resSize <<= 1;
						res = realloc(res, resSize * sizeof(int*));
					}
					res[*returnSize] = malloc(4 * sizeof(int));
					res[*returnSize][0] = nums[i];
					res[*returnSize][1] = nums[j];
					res[*returnSize][2] = nums[front];
					res[*returnSize][3] = nums[back];
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
			tmp = nums[j];
			while (j < numsSize && nums[j] == tmp)
			{
				++j;
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
	int a[] = {1, 0, -1, 0, -2, 2};
	int returnSize = 0;
	int** res = fourSum(a, sizeof(a) / sizeof(int), 0, &returnSize);
	while (--returnSize >= 0)
	{
		printf("%d %d %d %d\n", res[returnSize][0], res[returnSize][1], res[returnSize][2], res[returnSize][3]);
		free(res[returnSize]);
	}
	free(res);
}