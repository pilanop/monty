#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line: line number of the current opcode
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *temporary;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temporary = *stack;
	*stack = (*stack)->next;
	free(temporary);
}