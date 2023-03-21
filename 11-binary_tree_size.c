#include "binary_trees.h"

/**
* binary_tree_size -  measures the size of a binary tree
* @tree: tree to measure
* Return: size of tree, or 0
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 1;

	if (!tree)
		return (0);

	if (tree->left)
		size += binary_tree_size(tree->left);

	if (tree->right)
		size += binary_tree_size(tree->right);

	return (size);
}
