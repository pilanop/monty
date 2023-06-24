#include "monty.h"

/**
 * dup - duplicates the top element of the stack and pushes it onto the stack.
 * @stack: double pointer to the top of the stack
 * @line: line number of the current opcode
 *
 * Return: void
 */
void dup(stack_t **stack, unsigned int line)
{
	stack_t *new;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't dup, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = (*stack)->n;
	new->prev = NULL;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

