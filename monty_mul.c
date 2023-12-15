#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Stack head.
 * @counter: Line number.
 *
 * Return: No return.
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	for (h = *head; h; h = h->next, len++)
		;

	/* Check if the stack has less than two elements */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Perform the multiplication of the top two elements */
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
