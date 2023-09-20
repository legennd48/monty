#include "monty.h"

/**
 * push - adds a new element node to stack
 * @stack: head of stack
 * @linum: line number
 */

void push(stack_t **stack, unsigned int linum)
{
	int value = 0;

	printf("control gets here push");

	if (arg != NULL && strcmp(arg, "") != 0 && strcmp(arg, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linum);
		exit(EXIT_FAILURE);
	}
	/* if (strlen(arg) > 1) */
	/* { */
	/* 	for (i = 0; arg[i]; i++) */
	/* 	{ */
	/* 		if (!isdigit(arg[i])) */
	/* 		{ */
	/* 			fprintf(stderr, "L%u: usage: push integer\n", linum); */
	/* 			exit(EXIT_FAILURE); */
	/* 		} */
	/* 	} */
	/* } */
	value = atoi(arg);
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

	printf("control gets here pall");

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
