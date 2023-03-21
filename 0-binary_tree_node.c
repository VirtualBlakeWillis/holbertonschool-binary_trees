#include "binary_trees.h"

/**
* binary_tree_node - create a binary tree node
*
* @parent: the parent of the new node
* @value: the value stored in the new node
* Return: pointer to new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node;

    node = malloc(sizeof(binary_tree_t));
    if (!node)
        return (NULL);
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
