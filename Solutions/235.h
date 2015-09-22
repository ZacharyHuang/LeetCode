#include "common.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lca_helper(struct TreeNode* root, struct TreeNode* low, struct TreeNode* high) {
	// if root is one of low and high, return root
	if (root == low || root == high)
	{
		return root;
	}

	// if low belongs to the left sub-tree and high belongs to the right sub-tree, return root
	if (low->val < root->val && root->val < high->val)
	{
		return root;
	}

	// low and high belongs to a same sub-tree
	return high->val < root->val ? lca_helper(root->left, low, high) : lca_helper(root->right, low, high);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode* tmp;
	// make p is the small one and q is the big one
	if (p->val > q->val)
	{
		tmp = p;
		p = q;
		q = tmp;
	}
	while (true)
	{
		// if root is one of p and q, or if p belongs to the left sub-tree and q belongs to the right sub-tree, return root
		if ((p->val < root->val && root->val < q->val) || root == p || root == q)
		{
			return root;
		}

		// low and high belongs to a same sub-tree, move to that
		root = q->val < root->val ? root->left : root->right;
	}
}

void Test()
{
	struct TreeNode t[9];
	t[0].val = 6;
	t[1].val = 2;
	t[2].val = 8;
	t[3].val = 0;
	t[4].val = 4;
	t[5].val = 7;
	t[6].val = 9;
	t[7].val = 3;
	t[8].val = 5;
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
	p = lowestCommonAncestor(&t[0], &t[1], &t[4]);
	printf("%d\n", p->val);
}