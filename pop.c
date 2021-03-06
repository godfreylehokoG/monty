#include "monty.h"

/**
 * pop - deletes the number on the top of the stack
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number currently being operated on @file
 */

void pop(stack_t **stack, unsigned int ln)
{
	stack_t *new_head;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	new_head = (*stack)->next;
	delete_dnodeint_at_index(stack, 0);
	*stack = new_head;
}
