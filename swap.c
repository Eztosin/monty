#include "monty.h"

/**
* swap - swaps the top two elements of the stack.
* @stack: double pointer to the top of the list.
* @line_number: Line number from byte code file.
*/

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

if ((*stack) == NULL || (*stack)->prev == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

new_node = (*stack)->next;
(*stack)->next = new_node->next;

if (new_node->next != NULL)
new_node->next->prev = *stack;
new_node->prev = NULL;
new_node->next = *stack;
(*stack)->prev = new_node;
(*stack) = new_node;
}
