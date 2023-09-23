/**
 * pint - prints the top item in the list
 * @stack: points to a pointer to a doubly linked list
 * @linum: keeps track of the line number
 *
 * Return: nothing
 */

#include "monty.h"

void pint(stack_t **stack, unsigned int linum)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linum);
		err_exit(stack);
	}

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	printf("%d\n", tmp->n);
}


/**
 * pop - removes the top item in the list
 * @stack: points to a pointer to a doubly linked list
 * @linum: keeps track of the line number in the file
 *
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int linum)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linum);
		err_exit(stack);
	}

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->prev == NULL)
		*stack = NULL;
	else
		tmp->prev->next = NULL;
	free(tmp);
}
