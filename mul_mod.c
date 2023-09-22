#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack..
 * @head: pointer to head node
 * @linum: line number
 */
void mul(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL, *secondToLast = NULL;
	int elementCount = 0, flag = 0, i;

	if (*head == NULL || head == NULL)
	{
		/* Error handling for empty stack */
		fprintf(stderr, "L%u: can't mul, stack too short\n", linum);
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

	if (elementCount < 2 && flag == 0)
	{
		/* Handle error for insufficient elements in the stack */
		fprintf(stderr, "L%u: can't mul, stack too short\n", linum);
		err_exit(head);
	}


	/* Perform multiplication on the second-to-last element and cleanup */
	secondToLast->n *= current->n;
	secondToLast->next = NULL;
	free(current);
	current = NULL;
}


#include "monty.h"

/**
 * mod -  computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * the top element of the stack..
 * @head: pointer to head node
 * @linum: line number
 */
void mod(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL, *secondToLast = NULL;
	int elementCount = 0, flag = 0, i;

	if (*head == NULL || head == NULL)
	{
		/* Error handling for empty stack */
		fprintf(stderr, "L%u: can't mod, stack too short\n", linum);
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
	if (elementCount < 2 && flag == 0)
	{
		/* Handle error for insufficient elements in the stack */
		fprintf(stderr, "L%u: can't mod, stack too short\n", linum);
		err_exit(head);
	}
	if (current->n == 0)
	{
		/* Handle division by zero error */
		fprintf(stderr, "L%u: division by zero\n", linum);
		err_exit(head);
	}
	/* Perform multiplication on the second-to-last element and cleanup */
	secondToLast->n %= current->n;
	secondToLast->next = NULL;
	free(current);
	current = NULL;
}
