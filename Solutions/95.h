#include "common.h"

/**
 *Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* NewTreeNode(int value)
{
	struct TreeNode* node = calloc(1, sizeof(struct TreeNode));
	if (node == NULL)
	{
		return NULL;
	}
	node->val = value;
	return node;
}

struct TreeNode** helper(int startIndex, int endIndex, int* returnSize)
{
	struct TreeNode** res;
	// no number
	if (endIndex < startIndex)
	{
		*returnSize = 1;
		res = malloc(sizeof(struct TreeNode*));
		res[0] = NULL;
		return res;
	}
	// one number
	if (endIndex == startIndex)
	{
		*returnSize = 1;
		res = malloc(sizeof(struct TreeNode*));
		res[0] = NewTreeNode(startIndex);
		return res;
	}
	// 2 or more number
	struct TreeNode** left[20];
	int leftReturnSize[20];
	struct TreeNode** right[20];
	int rightReturnSize[20];
	int i, j, k, sum = 0;
	for (i = startIndex; i <= endIndex; ++i)
	{
		left[i] = helper(startIndex, i - 1, &leftReturnSize[i]);
		right[i] = helper(i + 1, endIndex, &rightReturnSize[i]);
		sum += leftReturnSize[i] * rightReturnSize[i];
	}
	res = malloc(sum * sizeof(struct TreeNode*));
	*returnSize = 0;
	for (i = startIndex; i <= endIndex; ++i)
	{
		for (j = 0; j < leftReturnSize[i]; ++j)
		{
			for (k = 0; k < rightReturnSize[i]; ++k)
			{
				res[*returnSize] = NewTreeNode(i);
				res[*returnSize]->left = left[i][j];
				res[*returnSize]->right = right[i][k];
				++(*returnSize);
			}
		}
	}
	return res;
}

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
struct TreeNode** generateTrees(int n, int* returnSize) {
	return helper(1, n, returnSize);
}

void PrintTreeAndFree(struct TreeNode* root, int level)
{
	int i;
	for (i = 0; i < level; ++i)
	{
		printf(" ");
	}
	printf("%d\n", root->val);
	if (root->left)
	{
		PrintTreeAndFree(root->left, level + 1);
	}
	if (root->right)
	{
		PrintTreeAndFree(root->right, level + 1);
	}
	free(root);
}

void Test()
{
	int i, size = 0;
	struct TreeNode** res = generateTrees(3, &size);
	for (i = 0; i < size; ++i)
	{
		PrintTreeAndFree(res[i], 0);
	}
}