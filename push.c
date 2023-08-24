#include "monty.h"

int push_data;

/**
* push - Adds a new node to the top of the stack.
* @stack: Double pointer to the head of the stack.
* @line_number: Line number from byte code file.
* @data: string representation of integer data.
*/

void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

if (*stack == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = push_data;

new_node->next = *stack;
new_node->prev = NULL;

push_data = 0;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}
