#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root of the binary tree
 *
 * Description: This function deletes the entire binary
 * tree rooted at `tree`.
 *              It recursively deletes the left and right
 *			subtrees before freeing the current node.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		/*Delete the left subtree recursively*/
		binary_tree_delete(tree->left);
		/*Delete the right subtree recursively*/
		binary_tree_delete(tree->right);
		free(tree); /*Free the current node*/
	}
}
