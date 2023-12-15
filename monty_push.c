#include "monty.h"

/**
 * is_valid_argument - Checks if the argument is a valid integer.
 * @arg: Argument to be validated.
 * @counter: Line number in the Monty file.
 *
 * Return: The validated integer.
 */
static int is_valid_argument(unsigned int counter)
{
	int n, j = 0;

	/* Handle negative sign and check for non-numeric characters */
	if (bus.arg[0] == '-')
	{
		j++;
	}

	while (bus.arg[j] != '\0')
	{
		if (bus.arg[j] > '9' || bus.arg[j] < '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			exit(EXIT_FAILURE);
		}
		j++;
	}

	/* Convert argument to an integer */
	n = atoi(bus.arg);

	return (n);
}

/**
 * handle_invalid_argument - Handles the case of an invalid argument.
 * @counter: Line number in the Monty file.
 */
static void handle_invalid_argument(unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(bus.file);
	free(bus.content);
	exit(EXIT_FAILURE);
}

/**
 * f_push - Adds a node to the stack or queue.
 * @head: Pointer to the head of the stack or queue.
 * @counter: Line number in the Monty file.
 *
 * Description:
 * - Parses the argument to extract an integer value.
 * - Handles error cases for invalid arguments.
 * - Adds a new node to the stack or queue with the parsed integer.
 *
 * Return: No explicit return value.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;

	/* Check if argument is provided */
	if (bus.arg)
	{
		n = is_valid_argument(counter);
	}
	else
	{
		handle_invalid_argument(counter);
	}

	/* Add the new node to the stack or queue based on the lifi flag */
	if (bus.lifi == 0)
	{
		addnode(head, n); /* Stack mode */
	}
	else
	{
		addqueue(head, n); /* Queue mode */
	}
}
