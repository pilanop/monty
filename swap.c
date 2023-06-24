#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: double pointer to the top of the stack
* @line: line number of the current opcode
*
* Return: void
*/
void swap(stack_t **stack, unsigned int line) {
	int temporary;

	if (*stack == NULL || (*stack)->next == NULL) {
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temporary = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temporary;
}

