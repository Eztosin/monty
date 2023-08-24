#include "monty.h"

/**
* check_args_and_file - Checks program arguments and file.
* @ac: Expected argument count in main.
* @argv: Expected argument vector in main.
* @op_file: monty bytecode file to be checked.
*/

void check_args_and_file(int ac, char *argv, FILE **op_file)
{

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

*op_file = fopen(argv, "r");

if (*op_file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv);
exit(EXIT_FAILURE);
}
}
