#include "monty.h"

/**
* sub - substracts the top two elements of the stack
* @stack: double pointer to the top of the stack.
* @line_number: Line number from byte code file.
*/

void sub(stack_t **stack, unsigned int line_number)
{

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n -= (*stack)->n;
pop(stack, line_number);
}
