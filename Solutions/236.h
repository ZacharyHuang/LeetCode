#include "common.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode *l, *r;

	// if root is one of p or q, return itself
	if (root == p || root == q)
	{
		return root;
	}

	// get left child's result and right child's result
	l = root->left ? lowestCommonAncestor(root->left, p, q) : NULL;
	r = root->right ? lowestCommonAncestor(root->right, p, q) : NULL;

	// l and r are both not NULL, so this root is the LCA
	if (l && r)
	{
		return root;
	}

	// return the non NULL node of l and r, or NULL if both of them are NULL
	return l ? l : r;
}

void Test()
{
	struct TreeNode t[9];
	t[0].val = 3;
	t[1].val = 5;
	t[2].val = 1;
	t[3].val = 6;
	t[4].val = 2;
	t[5].val = 0;
	t[6].val = 8;
	t[7].val = 7;
	t[8].val = 4;
	int i;
	for (i = 0; i < 3; ++i)
	{
		t[i].left = &t[2 * i + 1];
		t[i].right = &t[2 * i + 2];
	}
	for (i = 3; i < 9; ++i)
	{
		t[i].left = t[i].right = NULL;
	}
	t[4].left = &t[7];
	t[4].right = &t[8];
	struct TreeNode* p = lowestCommonAncestor(&t[0], &t[1], &t[2]);
	printf("%d\n", p->val);
	p = lowestCommonAncestor(&t[0], &t[1], &t[8]);
	printf("%d\n", p->val);
}