#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of the current opcode
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
