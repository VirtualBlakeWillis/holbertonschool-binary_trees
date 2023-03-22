#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: node 2 find uncle of
 * Return: pinter to uncle, or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: node to find sibling of
 * Return: sibling if found, or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling, *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	if (parent->left == node)
		sibling = parent->right;
	else
		sibling = parent->left;

	return (sibling);
}