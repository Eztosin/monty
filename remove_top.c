#include "monty.h"

/**
* pop - removes the top element of the stack.
* @stack: double pointer to the top of the stack.
* @line_number: Line number from byte code file.
*/

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

if ((*stack) == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
new_node = *stack;
*stack = (*stack)->next;

if ((*stack) != NULL)
(*stack)->prev = NULL;

free(new_node);
}
