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

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: tree to check
* Return: 1 if perfect, 0 if not
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int balance = 0, full = 0;

	if (!tree)
		return (0);

	full = binary_tree_is_full(tree);
	balance = binary_tree_balance(tree);

	if (balance == 0 && full == 1)
		return (1);
	return (0);
}
