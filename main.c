#include "monty.h"

global_t globva;

/**
 * free_globva - frees the global variables
 *
 * Return: no return
 */
void free_globva(void)
{
	free_listnodeint(globva.head);
	free(globva.buffer);
	fclose(globva.fd);
}

/**
 * start_globva - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_globva(FILE *fd)
{
	globva.lifo = 1;
	globva.cont = 1;
	globva.arg = NULL;
	globva.head = NULL;
	globva.fd = fd;
	globva.buffer = NULL;
}

/**
 * check_arg - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_arg(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_arg(argc, argv);
	start_globva(fd);
	nlines = getline(&globva.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _str_tok(globva.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_instructs(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globva.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_globva();
				exit(EXIT_FAILURE);
			}
			globva.arg = _str_tok(NULL, " \t\n");
			f(&globva.head, globva.cont);
		}
		nlines = getline(&globva.buffer, &size, fd);
		globva.cont++;
	}

	free_globva();

	return (0);
}
