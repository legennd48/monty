#include "monty.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 always
 */

int main(int ac, char *av[])
{
	printf("control gets here main-1");
	unsigned int linum = 0;
	int fd = 0;
	char buff[1024], *cmd = NULL, *lines = NULL, *temp = NULL;
	ssize_t bytes_read = 0;
	stack_t *stack = NULL;
	char *arg = NULL;

	printf("control gets here main-1");
	if (ac != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	printf("control gets here main0");
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	printf("control gets here main1");
	bytes_read = read(fd, buff, sizeof(buff));
	if (bytes_read > 0)
	{
		buff[bytes_read - 1] = '\0';
		lines = strtok(buff, "\n");
		while (lines != NULL)
		{
			printf("control gets here main");
			linum++;
			temp = lines;
			cmd = strtok(temp, DELIM);
			arg = strtok(NULL, DELIM);
			printf("%s", arg);
			getfunc(cmd, arg, &stack, linum);
		}
	}
	close(fd);
	return (0);
}
