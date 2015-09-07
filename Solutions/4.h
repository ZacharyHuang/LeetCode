#include "common.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int totalSize = nums1Size + nums2Size;
	int index1 = 0, index2 = 0;
	int deleteLength = (totalSize >> 1) - ((totalSize & 1) ? 0 : 1);

	// delete half of deleteLength each time
	while (deleteLength > 0)
	{
		int half = deleteLength == 1 ? 1 : (deleteLength >> 1);
		int i1 = index1 + half, i2 = index2 + half;
		// nums1 is running out
		if (i1 > nums1Size)
		{
			i1 = nums1Size;
		}
		// nums2 is running out
		if (i2 > nums2Size)
		{
			i2 = nums2Size;
		}
		//compare two number
		if (nums1[i1 - 1] < nums2[i2 - 1])
		{
			// delete nums1
			deleteLength -= i1 - index1;
			index1 = i1;
			// check is nums1 running out
			if (i1 >= nums1Size)
			{
				break;
			}
		}
		else
		{
			// delete nums2
			deleteLength -= i2 - index2;
			index2 = i2;
			// check is nums2 running out
			if (i2 >= nums2Size)
			{
				break;
			}
		}
	}
	double res;
	// check is nums1 running out
	if (index1 >= nums1Size)
	{
		// get median from nums2
		index2 += deleteLength;
		res = nums2[index2];
		if (!(totalSize & 1))
		{
			res = (res + nums2[index2 + 1]) / 2;
		}
		return res;
	}
	// check is nums2 running out
	else if (index2 >= nums2Size)
	{
		// get median from nums1
		index1 += deleteLength;
		res = nums1[index1];
		if (!(totalSize & 1))
		{
			res = (res + nums1[index1 + 1]) / 2;
		}
		return res;
	}
	// nums1 and nums2 are not running out
	if (nums1[index1] < nums2[index2])
	{
		res = nums1[index1++];
	}
	else
	{
		res = nums2[index2++];
	}
	if (!(totalSize & 1))
	{
		// check is nums1 running out
		if (index1 >= nums1Size)
		{
			res = (res + nums2[index2]) / 2;
		}
		// check is nums2 running out
		else if (index2 >= nums2Size)
		{
			res = (res + nums1[index1]) / 2;
		}
		// nums1 and nums2 are not running out
		else
		{
			res = (res + (nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2])) / 2;
		}
	}
	return res;
}

void Test()
{
	int nums1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int nums2[5] = { 1, 2, 3, 4, 5 };
	printf("%lf\n", findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int)));
}