#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - global structure
 * @fifo: stack or queue
 * @current: current line
 * @args: pointer to the second parameter in the current line
 * @buffer: points to the inputed text
 * @head: points to head of the doubly linked list
 * @fd: file descriptor
 * Description: doubly linked list node structure
 */
typedef struct global_variable
{
	int fifo;
	unsigned int current;
	char *args;
	char *buffer;
	stack_t *head;
	FILE *fd;
} global_var;

extern global_var global;

void (*opcode_new(char *op_code))(stack_t **stack, unsigned int line_number);

void stack(stack_t **stack, unsigned int line_number);

void queue(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

stack_t *add_front(stack_t **head, const int n);
stack_t *add_rear(stack_t **head, const int n);
void free_list(stack_t *head);

void free_global(void);
void global_init(FILE *fd);

FILE *checker(int argc, char *argv[]);

#endif
