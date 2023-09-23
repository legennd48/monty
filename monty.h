#ifndef _MONTY_H_
#define _MONTY_H_

/* Headers */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

/* Constants */
#define DELIM " \n\t"
/* "\b;:\t\a\r " */


/* structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_var_s - global variable structure
 * @arg: argument integer
 * @fd: filr descriptor
 * @line_buf: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_var_s
{
	char *arg;
	FILE *file;
	char *buff;

} global_var_t;

extern  global_var_t g_var;


/* Functions */
int getfunc(char *line, stack_t **stack, unsigned int linum);
stack_t *make_front(stack_t **stack, int val);
void push(stack_t **stack, unsigned int linum);
void pall(stack_t **head, unsigned int linum);
void pint(stack_t **stack, unsigned int linum);
void pop(stack_t **stack, unsigned int linum);
stack_t *make_end(stack_t **stack, int val);
void free_stack(stack_t *stack);
void err_exit(stack_t **stack);
void succ_exit(void);
void swap(stack_t **head, unsigned int linum);
void add(stack_t **head, unsigned int linum);
void nop(stack_t **head, unsigned int linum);
void add(stack_t **head, unsigned int linum);
void sub(stack_t **head, unsigned int linum);
void _div(stack_t **head, unsigned int linum);
void mod(stack_t **head, unsigned int linum);
void mul(stack_t **head, unsigned int linum);
void pchar(stack_t **head, unsigned int linum);
void pstr(stack_t **head, unsigned int linum);
#endif /* _MONTY_H_ */
