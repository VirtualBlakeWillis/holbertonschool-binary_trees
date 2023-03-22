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
		balance -= 1 + binary_tree_balance_directional(tree->right, 1);

	return (balance);
}

/**
 * binary_tree_balance_directional - get height of one side of a binary tree
 * @tree: tree to balance
 * @direction: always 1, artifact of earlier testing
 * Return: height of that side of the tree
 */
int binary_tree_balance_directional(const binary_tree_t *tree, int direction)
{
	int balance = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
	{
		balance += direction;

		return (balance += MAX(binary_tree_balance_directional(tree->left, 1),
							binary_tree_balance_directional(tree->right, direction)));
	}
	return (0);
}
