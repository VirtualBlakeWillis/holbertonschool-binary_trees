#include "binary_trees.h"

/**
 * binary_tree_depth - measures the height of a node in a binary tree
 * @tree: tree to measure
 * Return: depth of tree, or NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	if (tree->parent != NULL)
		depth = 1 + binary_tree_depth(tree->parent);
	return (depth);
}
