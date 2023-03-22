#include "binary_trees.h"
#include "14-binary_tree_balance.c"
/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: tree to check
* Return: 1 if full, 0 if not
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int balance = 0;

	if (!tree)
		return (0);

	balance = ((1 * binary_tree_is_full(tree->left)) +
				(-1 * binary_tree_is_full(tree->right)));

	return (!balance);
}
