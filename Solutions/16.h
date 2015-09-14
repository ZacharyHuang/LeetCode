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
int threeSumClosest(int* nums, int numsSize, int target)
{
	int i = 0, front, back, closest = INT_MAX, delta1 = INT_MIN, delta2 = INT_MAX;
	hs(nums, numsSize);
	while (i < numsSize)
	{
		front = i + 1;
		back = numsSize - 1;
		int tmp;
		while (front < back)
		{
			tmp = nums[i] + nums[front] + nums[back];
			if (tmp == target)
			{
				return tmp;
			}
			else if (tmp < target)
			{
				if (delta1 < tmp)
				{
					closest = delta1 = tmp;
					delta2 = target - tmp + target;
				}
				tmp = nums[front++];
				while (front < back && nums[front] == tmp)
				{
					++front;
				}
			}
			else
			{
				if (tmp < delta2)
				{
					closest = delta2 = tmp;
					delta1 = target - tmp + target;
				}
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
	return closest;
}

void Test()
{
	int a[] = {0, 0, 0};
	printf("%d\n", threeSumClosest(a, sizeof(a) / sizeof(int), 1));
}