#include "monty.h"

/**
 * make_front - makes first node of the stack.
 * @stack: pointer to first element of.
 * @val: value
 * Return: new node
 */
stack_t *make_front(stack_t **stack, int val)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}


	new->n = val;
	new->next = *stack;
	new->prev = NULL;

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
	stack_t *new;
	stack_t *temp;

	if (stack == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;
	new->n = val;
	new->prev = temp;
	new->next = NULL;

	return (new);
}
