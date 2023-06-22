#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number of the current opcode
*
* Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
int tmp;

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

tmp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = tmp;
}

