#include "monty.h"

/**
 * add - adds the top two elements in the stack and sets the result on the
 * stack, after popping the top two elements
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number of monty f currently being processed
 * Return: void
 */

void add(stack_t **stack, unsigned int ln)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, sum);
}

/**
 * sub - subtracts the top two elements in the stack and sets the result on the
 * stack, after popping the top two elements
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number of monty f currently being processed
 * Return: void
 */
void sub(stack_t **stack, unsigned int ln)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n - (*stack)->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, sum);
}

/**
 * div_ - divides the top two elements in the stack and sets the result on the
 * stack, after popping the top two elements
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number of monty f currently being processed
 * Return: void
 */
void div_(stack_t **stack, unsigned int ln)
{
	int quotient;

	if (!*stack || !(*stack)->next || (*stack)->n == 0)
	{
		if (*stack && (*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", ln);
		else
			fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, quotient);
}

/**
 * mod - divides the top two elements in the stack and sets the remainder on
 * the stack, after popping the top two elements
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number of monty f currently being processed
 * Return: void
 */
void mod(stack_t **stack, unsigned int ln)
{
	int remainder;

	if (!*stack || !(*stack)->next || (*stack)->n == 0)
	{
		if (*stack && (*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", ln);
		else
			fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	remainder = (*stack)->next->n % (*stack)->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, remainder);
}

/**
 * mul - multiplies the top two elements in the stack and sets the result on
 * the stack, after popping the top two elements
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number of monty f currently being processed
 * Return: void
 */
void mul(stack_t **stack, unsigned int ln)
{
	int result;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->n * (*stack)->next->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, result);
}
