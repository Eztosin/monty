#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top.
* @stack: double pointer to the head of the stack.
* @line_number: Line number being executed.
*/

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
(void) line_number;
new_node = *stack;

if (*stack == NULL)
return;

while (new_node != NULL)
{
printf("%d\n", new_node->n);
new_node = new_node->next;
}
}
