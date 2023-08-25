#include "monty.h"

global_var glob;

/**
 * global_init - initialises the global variables
 * @fd: file descriptor
 * Return: nothing
 */
void global_init(FILE *fd)
{
	glob.fifo = 1;
	glob.current = 1;
	glob.args = NULL;
	glob.buffer = NULL;
	glob.head = NULL;
	glob.fd = fd;
}

/**
 * free_global - frees the memory alloc for global variables
 * Return: Nothing
 */
void free_global(void)
{
	free_list(glob.head);
	free(glob.buffer);
	fclose(glob.fd);
}
