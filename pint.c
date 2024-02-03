#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void pint(node_t **stack, unsigned int line)
{
	if (!stack || !(*stack))
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line);
		exit_op();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
