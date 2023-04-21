#include "binary_trees.h"


/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: double pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (root == NULL)
		return (NULL);
	node = bst_search(root, value);
	if (node == NULL)
		return (NULL);
	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent == NULL)
		{
			free(node);
			return (NULL);
		}
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		free(node);
		return (root);
	}
	if (node->left == NULL || node->right == NULL)
	{
		if (node->parent == NULL)
		{
			if (node->left != NULL)
				node->left->parent = NULL;
			else
				node->right->parent = NULL;
			free(node);
			return (node->left != NULL ? node->left : node->right);
		}
		if (node->parent->left == node)
		{
			if (node->left != NULL)
			{
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
			else
			{
				node->parent->left = node->right;
				node->right->parent = node->parent;
			}
		}
		else
		{
			if (node->left != NULL)
			{
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else
			{
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
		}
		free(node);
		return (root);
	}
	node->n = node->right->n;
	bst_remove(node->right, node->n);
	return (root);
}
