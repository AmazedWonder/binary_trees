#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal
 * on a binary tree
 * @tree: Pointer to the root of the binary tree
 * @func: Pointer to the function to be applied to each node
 *
 * Description: This function traverses the binary tree in pre-order,
 *				applying the specified function to each node's value.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);/*Apply the function to the current node*/
		/*Traverse the left subtree recursively*/
		binary_tree_preorder(tree->left, func);
		/*Traverse the right subtree recursively*/
		binary_tree_preorder(tree->right, func);
	}
}
