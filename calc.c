#include "monty.h"

/**
 * add - Add the top two elements
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	total = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * sub - Subtracts the top two elements from each other
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't sub, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * divi - Divides the two top elements from each other
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void divi(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't div, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * mul - Multiplies the two top elements of the stack
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mul, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * mod - Modulus of the top two elements
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mod, stack too short\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_global();
		exit(EXIT_FAILURE);
	}

	total = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = total;
}
