#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>

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
/* func_func.c */
void func_call(op_func func, char *op, char *val, int ln, int format);
void func_find(char *opcode, char *value, int ln, int format);
/* file_func.c */
int line_parse(char *buffer, int line_number, int format);
void file_read(FILE *f);
void file_open(char *file);
void stack_print(stack_t **stack, unsigned int line_number);
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);

#endif /* _MONTY_H_ */
