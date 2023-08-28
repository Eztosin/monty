#include "monty.h"

/**
* free_dlistint - frees the list represented by the stack.
* @stack: pointer to the top of the stack.
*/

void free_dlistint(stack_t *stack)
{
stack_t *current_node, *next_node;

current_node = stack;

while (current_node != NULL)
{
next_node = current_node->next;
free(current_node);
current_node = next_node;
}

}
