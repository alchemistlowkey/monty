#include "monty.h"

/**
 * opcode_new - opcode compare checker
 * @op_code: points to the input opcode
 * Return: opcode function
 */
void (*opcode_new(char *op_code))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, op_code) == 0)
		{
			break;
		}
	}
	return (instructions[i].f);
}
