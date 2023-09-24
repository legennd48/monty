#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void pchar(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL;
	char character;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", linum);
		err_exit(head);
	}

	current = *head;

	if (current->n >= 0 && current->n < 128)
	{
		character = current->n;
		putchar(character);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", linum);
		err_exit(head);
	}
	putchar('\n');
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void pstr(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL;
	char character;

	(void)linum;

	if (*head == NULL)
	{
		putchar('\n');
		return;
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	while (current != NULL && current->n != 0)
	{
		if (current->n >= 0 && current->n <= 127)
		{
			character = current->n;
			putchar(character);
			current = current->prev;
		}
		else
			break;
	}
	putchar('\n');
}
