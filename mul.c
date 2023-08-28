#include "monty.h"

/**
* mul - multiplies the top two elements of the stack
* @stack: double pointer to the top of the stack.
* @line_number: Line number from byte code file.
*/

void mul(stack_t **stack, unsigned int line_number)
{

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n *= (*stack)->n;
pop(stack, line_number);
}
