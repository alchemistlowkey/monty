#include "monty.h"

/**
 * nop - Do nothing
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pstr - Prints string
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL && current->n != 0 &&
		current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * pchar - Prints character
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pchar, value out of range\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
