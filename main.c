#include "monty.h"

int push_data;

/**
* main - runs monty byte code files
* @argc: argument count.
* @argv: argument vector.
*/

int main(int argc, char *argv[])
{
FILE *bytecode_file;
ssize_t get_dline;
char *opcode, *args, *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
stack_t *stack = NULL;
int i, opcode_found;
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{NULL, NULL}
};

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

bytecode_file = fopen(argv[1], "r");
if (bytecode_file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while ((get_dline = getline(&line, &len, bytecode_file)) != -1)
{
line_number++;

opcode = strtok(line, " \t\n");
args = strtok(NULL, " \t\n");

if (opcode != NULL && opcode[0] != '#')
{
opcode_found = 0;
for (i = 0; opcodes[i].opcode != NULL; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
if (strcmp(opcode, "push") == 0)
{
if (args != NULL)
{
push_data = atoi(args);
opcodes[i].f(&stack, line_number);
}
else
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
free(line);
fclose(bytecode_file);
free_dlistint(stack);
exit(EXIT_FAILURE);
}
}
else
{
opcodes[i].f(&stack, line_number);
}
opcode_found = 1;
break;
}
}

if (!opcode_found)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
free(line);
fclose(bytecode_file);
free_dlistint(stack);
exit(EXIT_FAILURE);
}
}
}

free(line);
fclose(bytecode_file);
free_dlistint(stack);
exit(EXIT_SUCCESS);
}
