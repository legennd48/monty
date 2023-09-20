#include "monty.h"

/**
 * getfunc - calls the appropriate function to execute the op commands from main.
 * @command: command to be interpreted
 * @linum: line number
 * Return: 0 always
 */

int getfunc(char *cmd, char *arg, stack_t **stack, unsigned int linum)
{
	int i = 0, flag = 0;
	instruction_t funcs[] = {
		{"push", push}, {"pall", pall}
	};

	(void)arg;
	printf("control gets here getfunc");
	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(cmd, funcs[i].opcode) == 0)
		{
			flag = 1;
			funcs[i].f(stack, linum);
			break;
		}
	}
	if (flag == 0)
		fprintf(stderr, "%d: unknown instruction %s", linum, cmd);
	return (0);
}
