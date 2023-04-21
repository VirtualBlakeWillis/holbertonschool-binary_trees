#include "binary_trees.h"

/**
 * bst_insert - insets a value in a Binary Search Tree
 * @tree: double pointer to the root node of the tree
 * @value: value to store at node inserted
 * Return: pointer to created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node = *tree;
	while (node != NULL)
	{
		if (value < node->n)
		{
			if (node->left == NULL)
			{
				node->left = binary_tree_node(node, value);
				return (node->left);
			}
			node = node->left;
		}
		else if (value > node->n)
		{
			if (node->right == NULL)
			{
				node->right = binary_tree_node(node, value);
				return (node->right);
			}
			node = node->right;
		}
		else if (value == node->n)
			return (NULL);
	}
	return (NULL);
}
