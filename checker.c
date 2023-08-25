#include "monty.h"

/**
 * checker -  checker for files
 * @argc: argument counts
 * @argv: argument vector
 * Return: file
 */
FILE *checker(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
