#include "monty.h"

/**
 * sub -  subtracts the top element of the stack from the
 * second top element of the stack.
 * @head: pointer to head node
 * @linum: lin number
 */

void sub(stack_t **head, unsigned int linum)
{

	stack_t *current = NULL, *secondToLast = NULL;
	int elementCount = 0, flag = 0, i;

	if (*head == NULL || head == NULL)
	{
		/* Error handling for empty stack */
		fprintf(stderr, "L%u: can't sub, stack too short\n", linum);
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", linum);
		err_exit(head);
	}
	else
	{
		/* Perform sub on the second-to-last element and cleanup */
		secondToLast->n -= current->n;
		secondToLast->next = NULL;
		free(current);
		current = NULL;
		return;
	}
}



/**
 * _div - divides the second top element of the stack by the top element.
 * @head: pointer to head node
 * @linum: line number
 */
void _div(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL, *secondToLast = NULL;
	int elementCount = 0, flag = 0, i;

	if (*head == NULL || head == NULL)
	{
		/* Error handling for empty stack */
		fprintf(stderr, "L%u: can't div, stack too short\n", linum);
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
		secondToLast = secondToLast->next;
	if (elementCount < 2 && flag == 0)
	{
		/* Handle error for insufficient elements in the stack */
		fprintf(stderr, "L%u: can't div, stack too short\n", linum);
		err_exit(head);
	}
	if (current->n == 0)
	{
		/* Handle division by zero error */
		fprintf(stderr, "L%u: division by zero\n", linum);
		err_exit(head);
	}
	/* Perform division on the second-to-last element and cleanup */
	secondToLast->n /= current->n;
	secondToLast->next = NULL;
	free(current);
	current = NULL;
}
