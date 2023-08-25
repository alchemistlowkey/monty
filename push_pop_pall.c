#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int count, i;

	if (!global.args)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_global();
		exit(EXIT_FAILURE);
	}
	for (i = 0; global.args[i] != '\0'; i++)
	{
		if (!isdigit(global.args[i]) && global.args[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_global();
			exit(EXIT_FAILURE);
		}
	}

	count = atoi(global.args);

	if (global.fifo == 1)
	{
		add_front(stack, count);
	}
	else
	{
		add_rear(stack, count);
	}
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pop an empty stack\n");
		free_global();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}

/**
 * pall - Prints all values
 * @stack: Double pointer
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	for (; current != NULL;)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
