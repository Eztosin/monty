#include "monty.h"

/**
* check_args - checks if args is a valid integer.
* @args: argument to check.
* Return: 1 or 0 if it is not valid.
*/

int check_args(const char *args)
{
int j, is_valid, args_len;

if (args == NULL)
{
return (0);
}

args_len = strlen(args);
is_valid = 1;

for (j = 0; j < args_len; j++)
{
if (!isdigit(args[j]) && args[j] != '-')
{
is_valid = 0;
break;
}
}

return (is_valid);
}
