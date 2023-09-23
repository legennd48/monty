#include "monty.h"

/**
 * swap -  swaps the top two elements of the stack.
 * @head: pointer to head node
 * @linum: current line number
 */

void swap(stack_t **head, unsigned int linum)
{
	stack_t *temp;
	int holder_1, holder_2;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linum);
		err_exit(head);
	}

	temp = (*head)->next;

	while (temp->next != NULL)
		temp = temp->next;

	holder_1 = temp->n;
	holder_2 = temp->prev->n;
	temp->n = holder_2;
	temp->prev->n = holder_1;
}


/**
 * add -  adds the top two elements of the stack..
 * @head: pointer to head node
 * @linum: current line number
 */

void add(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL, *secondToLast = NULL;
	int elementCount = 0, flag = 0, i;

	if (*head == NULL || head == NULL)
	{
		/* Error handling for empty stack */
		fprintf(stderr, "L%u: can't add, stack too short\n", linum);
		err_exit(head);
	}
	/* Calculate the number of elements in the stack */
	for (current = *head; current->next != NULL; current = current->next)
	{
		elementCount++;
		flag = 1;
	}
	secondToLast = *head;
	/* Traverse to the second-to-last element */
	for (i = 0; i < (elementCount - 1); i++)
	{
		secondToLast = secondToLast->next;
	}
	if (elementCount == 0 && flag == 0)
	{
		/* Handle error for an empty stack */
		fprintf(stderr, "L%u: can't add, stack too short\n", linum);
		err_exit(head);
	}
	else
	{
		/* Perform addition on the second-to-last element and cleanup */
		secondToLast->n += current->n;
		secondToLast->next = NULL;
		free(current);
		current = NULL;
		return;
	}
}


/**
 * nop - does absolutely nothing
 * @head: pointer to head node
 * @linum: current line number
 */

void nop(stack_t **head, unsigned int linum)
{
	(void)head;
	(void)linum;

	/* free(g_var.buff); */
	/* free_stack(*stack); */
}
