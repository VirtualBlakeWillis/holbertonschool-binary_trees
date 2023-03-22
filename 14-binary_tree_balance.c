#include "binary_trees.h"
int binary_tree_balance_directional(const binary_tree_t *tree, int direction);
/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 * @tree: tree to measure
 * Return: balance factor, or 0
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (!tree)
		return (0);
	if (tree->left)
		balance += 1 + binary_tree_balance_directional(tree->left, 1);
	if (tree->right)
		balance += -1 + binary_tree_balance_directional(tree->right, -1);

	return (balance);
}

int binary_tree_balance_directional(const binary_tree_t *tree, int direction)
{

	if (!tree)
		return (0);
	if (direction > 0)
	{
		return (1 + binary_tree_balance_directional(tree->left, direction));
	}
	if (direction < 0)
		return (-1 + binary_tree_balance_directional(tree->right, direction));
	return (0);
}