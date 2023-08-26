#include "monty.h"

/**
* check_opcode - check for opcode.
* @opcode_found: opcode to check
* @line_number: line number from byte code file.
* @opcode: opcode name.
* Return: opcode found or error if not found.
*/

int check_opcode(int opcode_found, unsigned int line_number,
const char *opcode)
{

if (!opcode_found)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
exit(EXIT_FAILURE);
}
return (opcode_found);
}
