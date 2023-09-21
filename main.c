#include "monty.h"
#include <stdio.h>

global_var_t g_var = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 always
 */

int main(int ac, char *av[])
{
	unsigned int linum = 0;
	ssize_t lines_read = 1;
	stack_t *stack = NULL;
	size_t bytes = 0;
	int flag = 0, flag2 = 0;
	char *cmd = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	g_var.fd = fopen(av[1], O_RDONLY);
	if (g_var.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	lines_read = getline(&g_var.buff, &bytes, fileno(g_var.fd));
	while (lines_read >= 0)
	{
		flag = 0;
		linum++;
		cmd = strtok(g_var.buff, DELIM);
		if (!cmd)
			flag2 = 1;
		if (flag2 == 0)
		{
			if (cmd[0] == '#')
			{
				lines_read = getline(&g_var.buff, &bytes, fileno(g_var.fd));
				flag = 1;
			}
		}
		if (flag == 0)
		{
			getfunc(cmd, &stack, linum);
			lines_read = getline(&g_var.buff, &bytes, fileno(g_var.fd));
		}
	}
	/*free stack */
	free(g_var.buff);
	g_var.buff = NULL;
	fclose(g_var.fd);
	return (0);
}
