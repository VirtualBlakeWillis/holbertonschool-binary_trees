#include "binary_trees.h"

/**
* binary_tree_leaves - counts the leaves of a binary tree
* @tree: tree 2 count
* Return: # of leaves, or 0
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->right && !tree->left)
		return (1);

	return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
