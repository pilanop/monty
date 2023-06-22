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
	stack_t *template;

	if (stack == NULL || *stack == NULL)
		_more_err(7, line_number);

	template = *stack;
	*stack = template->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(template);
}
