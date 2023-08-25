#include "monty.h"

/**
 * pint - Prints top values of the stack
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swap the top two elements
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *up, *down;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't swap, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	up = *stack;
	down = up->next;
	up->next = down->next;
	if (down->next != NULL)
	{
		down->next->prev = up;
	}
	down->prev = NULL;
	down->next = up;
	up->prev = down;
	*stack = down;
}
