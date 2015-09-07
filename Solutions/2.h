#include "common.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int add = 0;
	struct ListNode head;
	struct ListNode* cur = &head;
	head.next = l1;
	while (l1 && l2)
	{
		int val = l1->val + l2->val + add;
		if (val > 9)
		{
			l1->val = val - 10;
			add = 1;
		}
		else
		{
			l1->val = val;
			add = 0;
		}
		cur = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l2) cur->next = l2;
	while (add)
	{
		if (cur->next) cur = cur->next;
		else cur = cur->next = calloc(1, sizeof(struct ListNode));
		int val = cur->val + add;
		if (val > 9)
		{
			cur->val = val - 10;
			add = 1;
		}
		else
		{
			cur->val = val;
			add = 0;
		}
	}
	return head.next;
}



void Test()
{
	struct ListNode l1[3], l2[3];
	l1[0].val = 2;
	l1[1].val = 4;
	l1[2].val = 3;
	l1[0].next = &l1[1];
	l1[1].next = &l1[2];
	l1[2].next = NULL;
	l2[0].val = 5;
	l2[1].val = 6;
	l2[2].val = 4;
	l2[0].next = &l2[1];
	l2[1].next = &l2[2];
	l2[2].next = NULL;
	struct ListNode* l = addTwoNumbers(l1, l2);
	while (l)
	{
		printf("%d->", l->val);
		l = l->next;
	}
}