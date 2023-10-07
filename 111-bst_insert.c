#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a binary search tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to be inserted
 *
 * Return: A pointer to the newly inserted node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			/* Create and insert the new node as the root */
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < curr->n) /* Insert in the left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			/* Create and insert the new node to the left */
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		else if (value > curr->n) /* Insert in the right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			/* Create and insert the new node to the right */
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	/* Return NULL if tree is NULL or value already exists in the tree */
	return (NULL);
}
