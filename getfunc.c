#include "monty.h"

/**
 * getfunc - calls the appropriate function to execute
 * the op commands from main.
 * @cmd: command to be interpreted
 * @linum: line number
 * @stack: pointer to head
 * @fd: file descriptor of opened file
 * Return: 0 always
 */

int getfunc(char *cmd, stack_t **stack, unsigned int linum)
{
	int i, flag = 0;
	char *op = NULL;
	instruction_t funcs[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};

	if (cmd == NULL || stack == NULL)
		return (0);
	op = cmd;
	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if(strcmp(op, funcs[i].opcode) == 0)
		{
			flag = 1;
			funcs[i].f(stack, linum);
			break;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", linum, cmd);
		exit(EXIT_FAILURE);/*potential free g_var */
	}
	return (0);
}
