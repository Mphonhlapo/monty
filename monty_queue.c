#include "monty.h"

/**
 * f_queue - sets the data structure to queue mode.
 * @head: Pointer to the head of the stack.
 * @counter: Line number (unused).
 * Return: No return value.
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)counter;

	switch (bus.lifi)
	{
	case 0:
		bus.lifi = 1; /* Set the queue mode flag */
		break;
	case 1:
		/* Already in queue mode, do nothing */
		break;
	default:
		fprintf(stderr, "L%d: Unknown stack/queue mode\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}

/**
 * addqueue - Adds a new node to the tail of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be stored in the new node.
 *
 * This function creates a new node with the given value and adds it
 * to the tail of the stack (queue). If the stack is empty, it becomes
 * the head of the stack.
 */
void addqueue(stack_t **head, int n)
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

	/* Set the value and pointers for the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the stack is not empty, traverse to the end to find the tail */
	if (auxiliary)
	{
		while (auxiliary->next)
			auxiliary = auxiliary->next;
	}

	/* If the stack is empty, set the new node as the head */
	if (!auxiliary)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Update pointers to add the new node to the tail */
		auxiliary->next = new_node;
		new_node->prev = auxiliary;
	}
}
