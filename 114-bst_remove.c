#include "binary_trees.h"
bst_t *bst_remove_leaf(bst_t *root);
void *bst_remove_right(bst_t *root);
void *bst_remove_left(bst_t *root);


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
			bst_remove_leaf(node);
		}
		if (node->parent->left == node)
			bst_remove_left(node);
		else
			bst_remove_right(node);
		free(node);
		return (root);
	}
	node->n = node->right->n;
	bst_remove(node->right, node->n);
	return (root);
}

/**
 * bst_remove_left - removes a node from a Binary Search Tree
 * @node: double pointer to the root node of the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
void *bst_remove_left(bst_t *node)
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
	return (node);
}

/**
 * bst_remove_right - removes a node from a Binary Search Tree
 * @node: double pointer to the root node of the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
void *bst_remove_right(bst_t *node)
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
	return (node);
}

/**
 * bst_remove_leaf - removes a node from a Binary Search Tree
 * @node: double pointer to the root node of the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value, or NULL on failure
 */
bst_t *bst_remove_leaf(bst_t *node)
{
	if (node->left != NULL)
		node->left->parent = NULL;
	else
		node->right->parent = NULL;
	free(node);
	return (node->left != NULL ? node->left : node->right);
}


/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the tree
 * @value: value to search for
 * Return: pointer to the node containing a value equals to value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else
		return ((bst_t *)tree);
}
