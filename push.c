/**
 * _push - Pushes an integer onto the stack or queue.
 * @stack: Pointer to the head of the stack (or queue).
 * @line: Current line number in the Monty bytecode file.
 *
 * This function checks if the argument is an integer and then
 * pushes it onto the stack (or queue) depending on the mode.
 * In stack mode (mode 0), the element is added to the beginning
 * of the stack; in queue mode (mode 1), the element is added to
 * the end of the queue.
 *
 * Return: No return value.
 */
void push(stack_t **stack, unsigned int line)
{
    if (!is_number(global.arg))
    {
        dprintf(2, "L%d: usage: push integer\n", line);
        exit_error();
        exit(EXIT_FAILURE);
    }

    int n = atoi(global.arg);
    global.mode == 0 ? insert_node_begin(&global.stack, n) : insert_node_end(&global.stack, n);
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line: Current line number in the Monty bytecode file.
 *
 * Return: No return value.
 */
void pall(stack_t **stack, unsigned int line)
{
    stack_t *tmp = *stack;

    // Suppress unused parameter warning
    (void)line;

    // Iterate through the stack and print values
    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

