#include "common.h"

// unsafe double-ends queue
typedef struct
{
	int *_data;
	int _size;
	int _front;
	int _back;
} dqueue;

dqueue* dqueue_create(int size)
{
	dqueue* dq = malloc(sizeof(dqueue));
	dq->_data = malloc((size + 1) * sizeof(int));
	dq->_size = size;
	dq->_front = 0;
	dq->_back = -1;

	return dq;
}

#define dqueue_front(dq) ((dq)->_data[(dq)->_front])

#define dqueue_back(dq) ((dq)->_data[(dq)->_back])

#define dqueue_empty(dq) ((dq)->_front == (dq)->_back + 1 || ((dq)->_front == 0 && (dq)->_back == (dq)->_size))

#define dqueue_push_back(dq, value) (dq)->_data[((dq)->_back = (dq)->_back == (dq)->_size ? 0 : (dq)->_back + 1)] = (value)

#define dqueue_pop_back(dq) (dq)->_back = (dq)->_back ? (dq)->_back - 1 : (dq)->_size

#define dqueue_pop_front(dq) (dq)->_front = (dq)->_front == (dq)->_size ? 0 : (dq)->_front + 1

void dqueue_destroy(dqueue* dq)
{
	free(dq->_data);
	free(dq);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
	// window is greater then numsSize, return empty array
	if (k > numsSize || k == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	*returnSize = numsSize - k + 1;
	int* res = malloc(*returnSize * sizeof(int));
	dqueue* dq = dqueue_create(k);
	// first fulfill the window and get first max
	int i;
	for (i = 0; i < k; ++i)
	{
		// pop numbers which is less than current number from the back
		while (!dqueue_empty(dq) && dqueue_back(dq) < nums[i])
		{
			dqueue_pop_back(dq);
		}
		// push new number
		dqueue_push_back(dq, nums[i]);
	}
	res[0] = dqueue_front(dq);
	// for each number out of window, if it is the front, pop it, and then push new number into window like above
	for (i = k; i < numsSize; ++i)
	{
		// pop front if it is out of window
		if (nums[i - k] == dqueue_front(dq))
		{
			dqueue_pop_front(dq);
		}
		// pop numbers which is less than current number from the back
		while (!dqueue_empty(dq) && dqueue_back(dq) < nums[i])
		{
			dqueue_pop_back(dq);
		}
		// push new number
		dqueue_push_back(dq, nums[i]);
		// save the max
		res[i - k + 1] = dqueue_front(dq);
	}
	dqueue_destroy(dq);
	return res;
}

void Test()
{
	int a[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int returnSize = 0;
	int* res = maxSlidingWindow(a, sizeof(a) / sizeof(int), 3, &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%d ", res[i]);
	}
	printf("\n");
	free(res);
}