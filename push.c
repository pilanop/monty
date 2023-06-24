#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line: line number of the current opcode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line)
{
	char *arg = strtok(NULL, DELIMS);
	int n;

	if (arg == NULL || check_digit(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	add_node(stack, n);
}

/**
 * check_digit - checks if a string contains only digits
 * @str: string to check
 *
 * Return: 1 if true, 0 if false
 */
int check_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * add_node - adds a new node at the beginning of a stack_t list
 * @head: double pointer to the top of the stack
 * @n: value of the new node
 *
 * Return: void
 */
void add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
