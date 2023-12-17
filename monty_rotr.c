#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	/* Check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	copy = *head;

	/* Find the last element in the stack */
	for (; copy->next != NULL; copy = copy->next)
		; /* Empty loop body; just iterating to the end of the stack */

	/* Connect the last element to the current head */
	copy->next = *head;
	copy->prev->next = NULL;

	/* Update the head pointers */
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
