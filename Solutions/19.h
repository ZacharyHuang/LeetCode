#include "common.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	struct ListNode h;
	h.next = head;
	struct ListNode *front = &h, *back = &h;
	// move back n times
	int i;
	for (i = 0; i < n && back; ++i, back = back->next);
	// move front and back together
	while (back = back->next)
	{
		front = front->next;
	}
	// delete front->next
	back = front->next;
	front->next = back->next;
	free(back);
	return head;
}

void Test()
{
	struct ListNode* n[5];
	int i;
	for (i = 0; i < sizeof(n) / sizeof(struct ListNode *); ++i)
	{
		n[i] = malloc(sizeof(struct ListNode));
		n[i]->val = i + 1;
		if (i > 0)
		{
			n[i - 1]->next = n[i];
		}
	}
	n[sizeof(n) / sizeof(struct ListNode *) - 1]->next = NULL;
	struct ListNode* res = removeNthFromEnd(n[0], 2);
	while (res)
	{
		printf("%d->", res->val);
		struct ListNode *tmp = res;
		res = res->next;
		free(tmp);
	}
}