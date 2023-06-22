#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number of the current opcode
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

(void)line_number;

tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

