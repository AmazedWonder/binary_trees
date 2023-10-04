#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a binary tree
 * @parent: Pointer to the parent node of the new node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Assign the value and parent pointer to the new node */
	new_node->n = value;
	new_node->parent = parent;

	/* Initialize left and right children pointers to NULL */
	new_node->left = NULL;
	new_node->right = NULL;

	/* Return the new node */
	return (new_node);
}
