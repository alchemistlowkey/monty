#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * main - Monty bytecode interpreter
 * @argc: Arguments count
 * @argv: Arguments vector
 * Return: integer
 */
int main(int argc, char *argv[])
{
	size_t i;
	void (*f)(stack_t **stack __attribute__((unused)), 
		unsigned int line_number __attribute__((unused)));
	ssize_t cmd = 0;
	FILE *fd;
	char *toks[2] = {NULL, NULL};

	i = 500;
	fd = checker(argc, argv);
	global_init(fd);
	cmd = getline(&global.buffer, &i, fd);
	while (cmd != -1)
	{
		toks[0] = strtok(global.buffer, " \t\n");
		if (toks[0] && toks[0][0] != '#')
		{
			f = opcode_new(toks[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%u: ", global.current);
				fprintf(stderr, "unknown instruction %s\n", toks[0]);
				free_global();
				exit(EXIT_FAILURE);
			}
			global.args = strtok(NULL, " \t\n");
			f(&global.head, global.current);
		}
		cmd = getline(&global.buffer, &i, fd);
		global.current++;
	}
	free_global();
	return (0);
}
