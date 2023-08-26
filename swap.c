#include "monty.h"

/**
* swap - swaps the top two elements of the stack.
* @stack: double pointer to the top of the list.
* @line_number: Line number from byte code file.
*/

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *new_node, *second_node;

if ((*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

new_node = *stack;
second_node = (*stack)->next;

new_node->next = second_node->next;
new_node->prev = second_node;
second_node->next = new_node;
second_node->prev = NULL;

*stack = second_node;
}
