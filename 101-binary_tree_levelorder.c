#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: pointer to a constant binary_tree_t object
 * const binary tree node
 * @next: a pointer to another node_s structure
 */
/*typedef struct node_s*/
/*{*/
	/*const binary_tree_t *node;*/
	/*struct node_s *next;*/
/*} node_t;*/

node_t *append(node_t *head, const binary_tree_t *btnode);
void free_list(node_t *head);
node_t *get_children(node_t *head, const binary_tree_t *parent);
void levels_rec(node_t *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	node_t *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Recursively processes the nodes in a linked
 * list, applying a function to each node
 * @head: Pointer to the head of the linked list
 * @func: Pointer to the function to be applied
 * to each node's value
 */
void levels_rec(node_t *head, void (*func)(int))
{
	node_t *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Retrieves the children nodes of a
 * given parent node
 * @head: Pointer to the head of the linked list
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the head of the updated linked
 * list containing the children nodes
 */
node_t *get_children(node_t *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a new node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */
node_t *append(node_t *head, const binary_tree_t *btnode)
{
	node_t *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */
void free_list(node_t *head)
{
	node_t *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
