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
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {NULL, NULL}
	};


	op = strtok(line, " \t\n");
	if (op == NULL || stack == NULL)
		return (0);

	if (op && op[0] == '#')
		return (0);
	g_var.arg = strtok(NULL, " \t\n");

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
		exit(EXIT_FAILURE);
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
