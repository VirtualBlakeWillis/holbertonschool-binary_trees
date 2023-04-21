#include "binary_trees.h"
int check_tree(const binary_tree_t *node, int value, int smallerOrLarger);
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree to check
	* Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_tree(tree->left, tree->n, 0) &&
			check_tree(tree->right, tree->n, 1));
}

/**
 * check_tree - checks if a binary tree is a valid Binary Search Tree
 *
 * @node: pointer to the root node of the tree to check
 * @value: value of the node
 * @smallerOrLarger: 0 if the node is smaller than the value, 1 if larger
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int check_tree(const binary_tree_t *node, int value, int smallerOrLarger)
	{

	if (node == NULL)
		return (1);
	if (smallerOrLarger == 0)
	{
		if (node->n >= value)
			return (0);
	}
	else
	{
		if (node->n <= value)
			return (0);
	}

	return (check_tree(node->left, value, smallerOrLarger) &&
			check_tree(node->right, value, smallerOrLarger));
}
