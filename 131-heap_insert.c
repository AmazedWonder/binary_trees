#include "binary_trees.h"

/**
 * heap_insert - inserts a new node with a given
 * value into a binary heap
 * @root: Double pointer to the root node of the binary heap
 * @value: The value to be inserted
 *
 * Return: A pointer to the newly inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/*
	 * calculates the level and remaining leaves in the binary heap.
	 * Subtracts the total number of leaves from the tree size to get
	 * the remaining leaves on the last level.
	 */
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverses the tree to the first empty slot based on the binary
	 * representation of the number of leaves.Beginning from the root
	 */
	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);
	/*
	 * Inserts the new node into the first empty slot found in the tree.
	 * If the number of leaves is odd, insert the new node as the right
	 * child of the current node. Otherwise, insert it as the left child.
	 */
	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;/*Performs a "flip" to maintain the heap property*/
		flip->n = flip->parent->n;/* If value of curr node is >than parent's*/
		flip->parent->n = tmp;/*value, swap the values and*/
		/* continue flipping with the parent*/
	}
	return (new);
}

/**
 * binary_tree_size - Calculate the size (number of nodes)
 * of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
