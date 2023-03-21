#include "binary_trees.h"

/**
 *
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
