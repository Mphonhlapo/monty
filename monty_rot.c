#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	/* Check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/* Find the last element in the stack */
	for (; tmp->next != NULL; tmp = tmp->next)
		; /* Empty loop body; just iterating to the end of the stack */

	/* Set the second element as the new head */
	aux = (*head)->next;
	aux->prev = NULL;

	/* Connect the last element to the current head */
	tmp->next = *head;

	/* Update the head pointers */
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
