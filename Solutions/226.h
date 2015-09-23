#include "common.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
	struct TreeNode* tmp;
	if (root != NULL)
	{
		tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
	}
	return root;
}