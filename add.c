#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: double pointer to the top of the stack
 * @line: line number of the current opcode
 *
 * Return: void
 */
void _add(stack_t **head, unsigned int line)
{
	stack_t *head_ptr;
	int len = 0, aux;

	head_ptr = *head;
	while (head_ptr)
	{
		head_ptr = head_ptr->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	head_ptr = *head;
	aux = head_ptr->n + head_ptr->next->n;
	head_ptr->next->n = aux;
	*head = head_ptr->next;
	free(head_ptr);
}