#include "monty.h"

/**
 * f_sub - Subtraction operation.
 * @head: Stack head.
 * @counter: Line number.
 *
 * Return: No return.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;

	/* Count the number of nodes in the stack using a while loop */
	nodes = 0;
	while (aux != NULL)
	{
		aux = aux->next;
		nodes++;
	}

	/* Check if the stack has less than two elements */
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Perform the subtraction of the top two elements */
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
