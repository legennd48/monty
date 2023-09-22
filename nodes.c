#include "monty.h"

/**
 * make_front - makes first node of the stack.
 * @stack: pointer to first element of.
 * @val: value
 * Return: new node
 */
stack_t *make_front(stack_t **stack, int val)
{
	stack_t *new, *tmp = NULL;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}


	new->n = val;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}
	tmp = *stack;
	new->next = tmp;
	tmp->prev = new;
	*stack = new;

	return (new);
}

/**
 * make_end - makes last node.
 * @stack: pointer to the top of the stack.
 * @val: value
 * Return: new node
 */
stack_t *make_end(stack_t **stack, int val)
{
	stack_t *new, *temp = NULL;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new->n = val;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		return (new);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
	new->next = NULL;

	return (new);
}
