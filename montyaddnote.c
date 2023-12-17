#include "monty.h"

/**
 * addnode - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be stored in the new node.
 *
 *	This function creates a new node with the given value and adds it
 *	to the head of the stack. If the stack is not empty, it updates the
 *	previous pointer of the existing head.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *auxiliary;

	auxiliary = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	/* If stack is not empty, update the previous pointer of the existing head */
	if (auxiliary)
		auxiliary->prev = new_node;

	/* Set the value, pointers, and update the head to the new node */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
