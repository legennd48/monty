#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @head: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void rotl(stack_t **head, unsigned int linum)
{
	stack_t *current, *new_head;

	(void)linum; (void)new_head;

	if (*head == NULL || (*head)->next == NULL)
		return;

	current = *head;

	while (current->next != NULL)
		current = current->next;

	current->next = *head;
	current->prev->next = NULL;
	*head = current;

	current->next->prev = current;
	current->prev = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 * @head: Pointer to the head of the stack
 * @linum: Line number of the instruction
 */

void rotr(stack_t **head, unsigned int linum)
{
	stack_t *current = *head, *new_head;

	(void)linum;

	if (*head == NULL || (*head)->next == NULL)
		return;

	/* Traverse to the last element */
	while (current->next != NULL)
		current = current->next;

	/* Update the pointers to rotate the stack */
	current->next = *head;
	new_head = (*head)->next;
	(*head)->next = NULL;
	*head = new_head;
	(*head)->prev = NULL;
	current->next->prev = current;

/*	(*head) = current->next;*/
/*	(*head)->prev = NULL;*/

	/* Adjust the links to complete the rotation */
/*	while (current->next != NULL)*/
/*		current = current->next;*/

/*	current->next = NULL;*/
}
