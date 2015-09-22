#include "common.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode h;
	h.next = NULL;
	struct ListNode *p = head, *q;
	while (q = p)
	{
		p = p->next;
		q->next = h.next;
		h.next = q;
	}
	return h.next;
}

bool isPalindrome(struct ListNode* head) {
	// get mid point of list
	struct ListNode *fast = head, *slow = head;
	while (fast && (fast = fast->next))
	{
		slow = slow->next;
		fast = fast->next;
	}
	// check if slow is head
	if (slow == head)
	{
		return true;
	}
	// reverse the second half
	fast = reverseList(slow);
	// check
	while (fast)
	{
		if (head->val != fast->val)
		{
			return false;
		}
		head = head->next;
		fast = fast->next;
	}
	// recover list(if needed)
	//reverseList(slow);
	return true;
}

void Test()
{
	struct ListNode a[5];
	a[0].val = 1;
	a[1].val = 2;
	a[2].val = 3;
	a[3].val = 2;
	a[4].val = 1;
	a[0].next = &a[1];
	a[1].next = &a[2];
	a[2].next = &a[3];
	a[3].next = &a[4];
	a[4].next = NULL;
	printf("%d\n", isPalindrome(&a[0]));
	a[1].val = 1;
	a[0].next = &a[1];
	a[1].next = &a[2];
	a[2].next = &a[3];
	a[3].next = &a[4];
	a[4].next = NULL;
	printf("%d\n", isPalindrome(&a[0]));
	
}