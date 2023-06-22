#include "monty.h"
#define MAX_LINE_LENGTH 1024

/**
* main - entry point for Monty interpreter
* @argc: number of arguments
* @argv: array of arguments
*
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char **argv)
{
FILE *fp;
char line[MAX_LINE_LENGTH];
unsigned int line_number = 0;
stack_t *stack = NULL;
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};
int i;
char *opcode;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fp = fopen(argv[1], "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
{
line_number++;
opcode = strtok(line, DELIMS);
if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
continue;
for (i = 0; opcodes[i].opcode; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
opcodes[i].f(&stack, line_number);
break;
}
}
if (opcodes[i].f == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
fclose(fp);
exit(EXIT_FAILURE);
}
}

fclose(fp);
return (EXIT_SUCCESS);
}
