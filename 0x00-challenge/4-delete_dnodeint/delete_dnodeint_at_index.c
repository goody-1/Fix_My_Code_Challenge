#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 1;
	while (p < index && *head != NULL)
	{
		if (saved_head == NULL)
			return (0);
		saved_head = saved_head->next;
		p++;
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(saved_head);
		return (1);
	}


	tmp = saved_head->next->next;
	free(saved_head->next);

	saved_head->next = tmp;

	return (1);
}
