#include "binary_trees.h"

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
		balance += 1 + binary_tree_balance(tree->left);
	if (tree->right)
		balance -= 1 + binary_tree_balance(tree->right);

	return (balance);
}
