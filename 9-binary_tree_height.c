#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure
 * Return: Height of tree, or NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0, rightHeight = 0;

	if (!tree)
		return (0);
	if (tree->left)
		leftHeight = 1 + binary_tree_height(tree->left);
	if (tree->right)
	rightHeight = 1 + binary_tree_height(tree->right);

	return (MAX(leftHeight, rightHeight));
}
