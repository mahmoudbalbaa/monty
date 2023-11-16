#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t globva;

/* opcode_instructuions*/
void push_node(stack_t **stack, unsigned int line_number);
void print_all(stack_t **stack, unsigned int line_number);
void print_data(stack_t **doubly, unsigned int cline);
void pop_node(stack_t **doubly, unsigned int cline);
void swap_top(stack_t **doubly, unsigned int cline);
void set_queue(stack_t **doubly, unsigned int cline);
void set_stack(stack_t **doubly, unsigned int cline);
void add_op(stack_t **doubly, unsigned int cline);
void _nop_(stack_t **doubly, unsigned int cline);
void sub_op(stack_t **doubly, unsigned int cline);
void div_op(stack_t **doubly, unsigned int cline);
void multi_op(stack_t **doubly, unsigned int cline);
void mod_op(stack_t **doubly, unsigned int cline);
void print_char(stack_t **doubly, unsigned int cline);
void print_str(stack_t **doubly, unsigned int cline);
void rotat_first(stack_t **doubly, unsigned int cline);
void revset_stack(stack_t **doubly, unsigned int cline);

/*get function*/
void (*get_instructs(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _search(char *s, char c);
char *_str_tok(char *s, char *d);
void *_realloc_(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc_(unsigned int nmemb, unsigned int size);
int strcmp_(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_node_last(stack_t **head, const int n);
stack_t *add_node_first(stack_t **head, const int n);
void free_listnodeint(stack_t *head);

/* main */
void free_globva(void);

#endif
