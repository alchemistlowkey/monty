#include "monty.h"

/**
 * rotr - Rotates from top to bottom
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int tmp;

	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
	{
		current = current->next;
	}

	tmp = current->n;

	while (current->prev != NULL)
	{
		current->n = current->prev->n;
		current = current->prev;
	}
	current->n = tmp;
}

/**
 * rotl - Rotates from bottom to top
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int tmp;

	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	tmp = current->n;

	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}

	current->n = tmp;
}
