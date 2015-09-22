#include "common.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
	// we copy next node to this node and delete next node
	// point to node->next
	struct ListNode* p = node->next;
	// copy data field from p to node
	node->val = p->val;
	// set p->next to node->next
	node->next = p->next;
	// free p
	free(p);
}

void Test()
{
	struct ListNode* a[4];
	a[0] = malloc(sizeof(struct ListNode));
	a[1] = malloc(sizeof(struct ListNode));
	a[2] = malloc(sizeof(struct ListNode));
	a[3] = malloc(sizeof(struct ListNode));
	a[0]->val = 1;
	a[0]->next = a[1];
	a[1]->val = 2;
	a[1]->next = a[2];
	a[2]->val = 3;
	a[2]->next = a[3];
	a[3]->val = 4;
	a[3]->next = NULL;
	deleteNode(a[2]);
	struct ListNode* n = a[0];
	while (n)
	{
		printf("%d->", n->val);
		struct ListNode* p = n;
		n = n->next;
		free(p);
	}
}