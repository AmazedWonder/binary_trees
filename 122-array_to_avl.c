#include "binary_trees.h"

/**
 * array_to_avl - Converts an array into an AVL tree
 * @array: Pointer to the array of integers
 * @size: The size of the array
 *
 * Return: A pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/* Check if the current element already exists in the tree */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If the current element is unique, insert it into the AVL tree */
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
