#include "binary_trees.h"

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
