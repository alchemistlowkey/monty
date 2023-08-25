#include "monty.h"

global_var global;

/**
 * global_init - initialises the global variables
 * @fd: file descriptor
 * Return: nothing
 */
void global_init(FILE *fd)
{
	global.fifo = 1;
	global.current = 1;
	global.args = NULL;
	global.buffer = NULL;
	global.head = NULL;
	global.fd = fd;
}

/**
 * free_global - frees the memory alloc for global variables
 * Return: Nothing
 */
void free_global(void)
{
	free_list(global.head);
	free(global.buffer);
	fclose(global.fd);
}
