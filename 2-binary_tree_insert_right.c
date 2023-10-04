#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right
 * child of a parent node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		/*If the parent already has a right child,*/
		/*make it the right child of the new node*/
		new_node->right = parent->right; /*Set the right child of the new node*/
		/*Update the parent pointer of the existing right child*/
		parent->right->parent = new_node;
	}
	/*Set the new node as the right child of the parent*/
	parent->right = new_node;

	return (new_node);
}
