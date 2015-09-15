#include "common.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int MyItoa(int i, char* a, int ai)
{
	if (i == 0)
	{
		a[ai++] = '0';
		a[ai] = 0;
		return ai;
	}
	if (i < 0)
	{
		a[ai++] = '-';
		i = -i;
	}
	int j = ai - 1;
	while (i > 0)
	{
		a[ai++] = (i % 10) + '0';
		i /= 10;
	}
	i = ai;
	while (++j < --i)
	{
		char tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	a[ai] = 0;
	return ai;
}

void dfs(struct TreeNode* root, char* path, int pathIndex, char** res, int* returnSize, int* resSize)
{
	path[pathIndex++] = '-';
	path[pathIndex++] = '>';
	pathIndex = MyItoa(root->val, path, pathIndex);
	if (root->left == NULL && root->right == NULL)
	{
		if (*returnSize == *resSize)
		{
			*resSize <<= 1;
			res = realloc(res, *resSize * sizeof(char*));
		}
		res[*returnSize] = malloc(pathIndex + 1);
		memcpy(res[*returnSize], path, pathIndex + 1);
		++(*returnSize);
		return;
	}
	if (root->left)
	{
		dfs(root->left, path, pathIndex, res, returnSize, resSize);
	}
	if (root->right)
	{
		dfs(root->right, path, pathIndex, res, returnSize, resSize);
	}
}
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	*returnSize = 0;
	if (root == NULL)
	{
		return NULL;
	}
	int resSize = 1024;
	char** res = malloc(resSize * sizeof(char*));
	char* path = malloc(3 * 2000);
	int pathIndex = MyItoa(root->val, path, 0);
	if (root->left == NULL && root->right == NULL)
	{
		res[*returnSize] = malloc(pathIndex + 1);
		memcpy(res[*returnSize], path, pathIndex + 1);
		++(*returnSize);
	}
	if (root->left)
	{
		dfs(root->left, path, pathIndex, res, returnSize, &resSize);
	}
	if (root->right)
	{
		dfs(root->right, path, pathIndex, res, returnSize, &resSize);
	}
	free(path);
	return res;
}

void Test()
{
	struct TreeNode t[4];
	t[0].val = 1;
	t[0].left = &t[1];
	t[0].right = &t[2];
	t[1].val = 2;
	t[1].left = NULL;
	t[1].right = &t[3];
	t[2].val = 30;
	t[2].left = NULL;
	t[2].right = NULL;
	t[3].val = -556;
	t[3].left = NULL;
	t[3].right = NULL;
	int returnSize = 0;
	char** res = binaryTreePaths(&t[0], &returnSize);
	int i;
	for (i = 0; i < returnSize; ++i)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
}