#include "monty.h"

/**
 * push - adds a new element node to stack
 * @stack: head of stack
 * @linum: line number
 */

void push(stack_t **stack, unsigned int linum)
{
	int value = 0, i = 0;

	if (g_var.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linum);
		exit(EXIT_FAILURE);
	}

	if (g_var.arg[0] == '-' || g_var.arg[0] == '+')
		i++;
	while (g_var.arg[i])
	{

		if (isdigit(g_var.arg[i]) == 0)
			continue;
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", linum);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	value = atoi(g_var.arg);
	if (*stack == NULL)
		make_front(stack, value);
	else
		make_end(stack, value);
}


/**
 * pall - Print the elements of the stack
 * @stack: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void pall(stack_t **stack, unsigned int linum)
{
	stack_t *current = NULL;

	if (*stack == NULL)
	{
		return;
	}

	if (*stack == NULL && linum != 1)
	{
		/* possible need to free */
		exit(EXIT_SUCCESS);
	}

	current = *stack;
	while (current->next != NULL)
		current = current->next;

	while (current->prev != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}

	printf("%d\n", current->n);
}
