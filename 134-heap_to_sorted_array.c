#include "binary_trees.h"

/**
 * tree_size - Calculates the size (number of nodes) of
 * a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The size of the binary tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - converts a binary heap to a sorted array
 * @heap: Pointer to the root node of the binary heap
 * @size: Pointer to a variable to store the size of
 * the sorted array
 *
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
