#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line: Current line number
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

#include "monty.h"

/**
 * swap - Exchange the positions of the top two elements in the stack.
 * @stack: Pointer to the head of the stack (or queue).
 * @line: Current line number in the Monty bytecode file.
 *
 * Return: No return value.
 */
void swap(stack_t **stack, unsigned int line)
{
    stack_t *current = *stack, *nextElement;
    int elementCount = 0;

   
    while (current && ++elementCount < 2)
        current = current->next;

   
    if (elementCount < 2)
    {
        dprintf(2, "L%d: unable to swap, insufficient elements in the stack\n", line);
        exit_op();
        exit(EXIT_FAILURE);
    }

   
    nextElement = current->next;
    current->next = nextElement->next;
    current->prev = nextElement;
    nextElement->next = current;
    nextElement->prev = current->prev;

    *stack = nextElement;
}
