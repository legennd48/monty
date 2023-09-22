#include "monty.h"

/**
 * getfunc - calls the appropriate function to execute
 * the op commands from main.
 * @line: line to be interpreted
 * @linum: line number
 * @stack: pointer to head
 * Return: 0 always.
 */

int getfunc(char *line, stack_t **stack, unsigned int linum)
{
	int i;
	char *op = NULL;
	instruction_t funcs[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};


	op = strtok(line, " \t\n");
	if (op == NULL || stack == NULL)
		return (0);
/*	printf("%s\n", op);*/

	if (op && op[0] == '#')
		return (0);
	g_var.arg = strtok(NULL, " \t\n");
/*	if (g_var.arg != NULL)*/
/*		printf("%s\n", g_var.arg);*/
/*	else*/
/*		printf("(null)\n");*/

	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (strcmp(op, funcs[i].opcode) == 0)
		{
			funcs[i].f(stack, linum);
			return (0);
		}
	}
	if (op && funcs[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", linum, op);
		fclose(g_var.file);
		free(g_var.buff);
		free_stack(*stack);
		exit(EXIT_FAILURE);/*potential free g_var */
	}
	return (0);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: points to the head of the list
 *
 * Return: nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *curr, *next;

	if (stack == NULL)
		return;
	curr = stack;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
}
