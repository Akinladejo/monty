#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "monty.h"


op_env_t op_env = {NULL, NULL, NULL, 0, 1, LIFO};
void op_add(stack_t **sp);

void op_pint(stack_t **sp)
{
    int sum;

    if (!sp || !*sp)
    {
        fprintf(stderr, "L%lu: can't pint, stack empty\n", (unsigned long)op_env.lineno);
        exit(EXIT_FAILURE);
    }

    sum = (*sp)->n;
    printf("%d\n", sum);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Upon success, return EXIT_SUCCESS.
 */
int main(int argc, char **argv)
{
	ssize_t n_read = 0;

	if (argc != 2)
		pfailure("USAGE: monty file\n");

	if (!freopen(argv[1], "r", stdin))
		pfailure("Error: Can't open file %s\n", argv[1]);

	atexit(free_op_env);

	while ((n_read = getline(&op_env.line, &op_env.linesz, stdin)) > 0)
	{
		op_env.argv = tokenize(op_env.line);

		if (op_env.argv && **op_env.argv != '#')
			get_instruction_fn(*op_env.argv)(&op_env.sp);

		free(op_env.argv);
		op_env.argv = NULL;
		op_env.lineno += 1;
	}
	return (EXIT_SUCCESS);
}
