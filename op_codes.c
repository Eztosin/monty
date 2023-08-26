#include "monty.h"

/**
* exec_opcode - checks and execute the given bytecode.
* @opcodes: array of opcode instructions
* @stack: double pointer to top of the stack
* @line_number: Line number from byte code file.
* @opcode: Opcode name.
* @args: Arguments for the opcode.
*/

void exec_opcode(instruction_t *opcodes, stack_t **stack,
unsigned int line_number, const char *opcode, const char *args)
{
int i, opcode_found = 0;

for (i = 0; opcodes[i].opcode != NULL; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
if (strcmp(opcode, "push") == 0)
{
if (args != NULL)
{
if (check_args(args))
{
push_data = atoi(args);
opcodes[i].f(stack, line_number);
}
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
else
{
opcodes[i].f(stack, line_number);
}
opcode_found = 1;
break;
}
}

check_opcode(opcode_found, line_number, opcode);
}
