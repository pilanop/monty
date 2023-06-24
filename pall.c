#include "monty.h"

/**
* pall - prints all the values on the stack, starting from the top of the stack
* @stack: double pointer to the top of the stack
* @line: line number of the current opcode
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line) {
	stack_t *temporary;

	(void) line;

	temporary = *stack;
	while (temporary != NULL) {
		printf("%d\n", temporary->n);
		temporary = temporary->next;
	}
}

