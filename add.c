#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: double pointer to the top of the stack.
* @line_number: Line number from byte code file.
*/

void add(stack_t **stack, unsigned int line_number)
{

stack_t *add_element;

if ((*stack) == NULL || (*stack)->prev == NULL)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

add_element = (*stack)->prev;
add_element->n = add_element->n + (*stack)->n;
(*stack) = add_element;

free((*stack)->next);

(*stack)->prev = NULL;
}
