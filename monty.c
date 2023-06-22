#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
* read_file - reads the input file line by line and executes instructions
* @fp: file pointer to the input file
* @opcodes: array of instruction_t structs
* @stack: pointer to the top of the stack
*
* Return: void
*/
void read_file(FILE *fp, instruction_t opcodes[], stack_t **stack)
{
char line[MAX_LINE_LENGTH];
unsigned int line_number = 0;
int i;
char *opcode;

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
opcodes[i].f(stack, line_number);
break;
}
}
if (opcodes[i].f == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
fclose(fp);
free_stack(*stack);
exit(EXIT_FAILURE);
}
}
}

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
stack_t *stack = NULL;
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{NULL, NULL}
};

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

read_file(fp, opcodes, &stack);

fclose(fp);
free_stack(stack);

return (EXIT_SUCCESS);
}
