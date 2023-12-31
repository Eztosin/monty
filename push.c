#include "monty.h"

/**
* push - Adds a new node to the top of the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number from byte code file.
*/

void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
(void) line_number;

new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = push_data;

new_node->next = *stack;
new_node->prev = NULL;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}
