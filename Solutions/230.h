#include "common.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int kthSmallest(struct TreeNode* root, int k) {
	struct TreeNode* stack[1024];
	int sl = -1;
	while (root)
	{
		stack[++sl] = root;
		root = root->left;
	}
	while (true)
	{
		root = stack[sl--];
		if (--k == 0)
		{
			return root->val;
		}
		if (root->right)
		{
			root = root->right;
			while (root)
			{
				stack[++sl] = root;
				root = root->left;
			}
		}
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
	printf("%d\n", kthSmallest(&t[0], 5));
}