#include "monty.h"

int push_data;

/**
* main - runs monty byte code files
* @argc: argument count.
* @argv: argument vector.
* Return: Always 0.
*/
int main(int argc, char *argv[])
{
FILE *bytecode_file;
ssize_t get_dline;
char *opcode, *args, *line = NULL;
size_t len = 0;
unsigned int line_number = 0;
stack_t *stack = NULL;
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{"swap", swap},
{"add", add},
{"nop", nop},
{"mod", mod},
{"div_monty", div_monty},
{"mul", mul},
{"sub", sub},
{NULL, NULL}
};

check_args_and_file(argc, argv[1], &bytecode_file);

while ((get_dline = getline(&line, &len, bytecode_file)) != -1)
{
line_number++;
opcode = strtok(line, " \t\n");
args = strtok(NULL, " \t\n");

if (opcode != NULL && opcode[0] != '#')
{
exec_opcode(opcodes, &stack, line_number, opcode, args);
}
}
free(line);
free_dlistint(stack);
fclose(bytecode_file);
return (EXIT_SUCCESS);
}
