#include "monty.h"

/**
 * push - adds a new element node to stack
 * @stack: head of stack
 * @linum: line number
 */

void push(stack_t **stack, unsigned int linum)
{
	int value = 0, i = 0, flag = 0, neg = 0, j = 0;
	char str[256];

	if (g_var.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", linum);
		err_exit(stack);
	}
	if (g_var.arg[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (g_var.arg[i])
	{
		if (g_var.arg[i] >= 48 && g_var.arg[i] <= 57)
		{
			flag = 1;
			str[j] = g_var.arg[i];
			str[j + 1] = '\0';
			value = atoi(str);
			if (neg == 1)
				value *= -1;
		}
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", linum);
			err_exit(stack);
		}
		i++;
		j++;
	}
	if (flag)
	{
		make_end(stack, value);
		return;
	}
	fprintf(stderr, "L%u: usage: push integer\n", linum);
	err_exit(stack);
}


/**
 * pall - Print the elements of the stack
 * @head: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void pall(stack_t **head, unsigned int linum)
{
	stack_t *current = NULL;

	if (*head == NULL)
		return;

	if (*head == NULL && linum != 1)
		succ_exit();

	current = *head;
	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * err_exit - frees the global variable and exit
 * @stack: points to pointer to doubly linked list
 *
 * Return: nothing
 */

void err_exit(stack_t **stack)
{
	free(g_var.buff);
	free_stack(*stack);
	fclose(g_var.file);
	exit(EXIT_FAILURE);
}

/**
 * succ_exit - frees the global variable and exit
 *
 * Return: nothing
 */

void succ_exit(void)
{
	free(g_var.buff);
	fclose(g_var.file);
	exit(EXIT_SUCCESS);
}
