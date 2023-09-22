#include "monty.h"

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
	FILE *file;
	char *read;
	stack_t *stack = NULL;
	int bytes = 1024;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	g_var.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	g_var.buff = malloc(bytes);
	if (g_var.buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
Here:
	read = fgets(g_var.buff, bytes, file);
	while (read != NULL)
	{
		linum++;
/*		printf("L%u: %s", linum, read);*/
		getfunc(read, &stack, linum);
		goto Here;
	}
	free_stack(stack);
	free(g_var.buff);
	g_var.buff = NULL;
	fclose(file);
	return (0);
}
