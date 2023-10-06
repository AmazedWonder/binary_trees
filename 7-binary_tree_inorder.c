#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal
 * on a binary tree
 * @tree: Pointer to the root of the binary tree
 * @func: Pointer to the function to be applied to each node
 *
 * Description: This function traverses the binary tree in in-order,
 *				applying the specified function to each node's value.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		/*Traverse the left subtree recursively*/
		binary_tree_inorder(tree->left, func);
		func(tree->n);/*Apply the function to the current node*/
		/*Traverse the right subtree recursively*/
		binary_tree_inorder(tree->right, func);
	}
}
