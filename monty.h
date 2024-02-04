#ifndef MONTY_H
#define MONTY_H

/** Libraries **/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** Structs **/

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

/**
 * struct global_s - contains global variables
 * @mode: 0 stack, 1 queue (default stack)
 * @buffer: getline buffer;
 * @node: argument of opcode (value of stack)
 * @head: head of stack
 * @line: keeps track of current line #
 * @file: pointer to file descriptor
 *
 * Description: Struct for keeping global vars
 *
 */

typedef struct global_s
{
    int mode; // 0 for stack, 1 for queue (default is stack)
    char *buffer; // Buffer for getline
    char *arg; // Argument of opcode (value for stack)
    node_t *stack; // Pointer to stack
    unsigned int line; // Current line number
    FILE *file; // Pointer to file descriptor
} global_t;

// Declare global variable
extern global_t global;

// Opcode functions
void push(node_t **stack, unsigned int line);
void pall(node_t **stack, unsigned int line);
void pint(node_t **stack, unsigned int line);
void pop(node_t **stack, unsigned int line);
void swap(node_t **stack, unsigned int line);
void add(node_t **stack, unsigned int line);
void nop(node_t **stack, unsigned int line);
void sub(node_t **stack, unsigned int line);
void div(node_t **stack, unsigned int line);
void mul(node_t **stack, unsigned int line);
void mod(node_t **stack, unsigned int line);
void pchar(node_t **stack, unsigned int line);
void pstr(node_t **stack, unsigned int line);
void rotl(node_t **stack, unsigned int line);
void rotr(node_t **stack, unsigned int line);
void stack(node_t **stack, unsigned int line);
void queue(node_t **stack, unsigned int line);
void set_global(void);

// Auxiliary functions
int find_opcode(char *name);
void exit_error(void);

node_t *insert_node_begin(node_t **stack, int data);
node_t *insert_node_end(node_t **stack, int data);
int delete_node_at_index(node_t **stack, unsigned int index);
void free_stack(node_t *stack);

int is_number(char *s);

#endif /* MONTY_H */
