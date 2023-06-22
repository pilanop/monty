#include "monty.h"

/**
* dup - duplicates the top element of the stack
* @stack: double pointer to the top of the stack
* @line_number: line number of the current opcode
*
* Return: void
*/
void dup(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't dup, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = (*stack)->n;
new_node->prev = NULL;
new_node->next = *stack;
(*stack)->prev = new_node;
*stack = new_node;
}

