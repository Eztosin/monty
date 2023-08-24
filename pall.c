#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top.
* @stack: double pointer to the head of the stack.
* @line_number: Line number being executed.
*/

void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
(void) line_number;
temp = *stack;
if (*stack == NULL)
return;

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
