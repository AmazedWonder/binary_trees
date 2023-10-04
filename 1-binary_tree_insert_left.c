#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left
 * child of a parent node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		/*If the parent already has a left child,*/
		/*make it the left child of the new node*/
		new_node->left = parent->left; /*Set the left child of the new node*/
		/*Update the parent pointer of the existing left child*/
		parent->left->parent = new_node;
	}
	parent->left = new_node; /*Set the new node as the left child of the parent*/

	return (new_node);
}
