#include "binary_trees.h"

/**
 * binary_tree_nodes - count # of nodes in a binary tree
 * @tree: tree 2 count
 * Return: # of nodes, or 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t c = 0;

	if (!tree)
		return (0);
	if (tree->left)
		c += 1 + binary_tree_nodes(tree->left);
	if (tree->right)
	{
		if (!tree->left)
			c++;
		c += binary_tree_nodes(tree->right);
	}
	return (c);
}
