#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Helper function to check if a binary
 * tree is a valid BST
 * @tree: A pointer to the binary tree node
 * @lo: lower limit of the valid range
 * @hi: upper limit of the valid range
 *
 * Return: 1 if the tree is a valid BST,
 * 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		/* Check if current node's value is outside valid range */
		if (tree->n < lo || tree->n > hi)
			return (0); /* Not a valid BST */

		/* Recursively check the left and right subtrees */
		/* Update the range limits accordingly */
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, hi));
	}

	/* Base case: An empty tree is considered a valid BST */
	return (1);
}


/**
 * binary_tree_is_bst - Checks if a binary tree is a
 * valid binary search tree (BST)
 * @tree: A pointer to the binary tree node
 *
 * Return: 1 if the tree is a valid BST,
 * 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Call the helper function with the initial range limits */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
