#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *c = *head;
	unsigned int i;

	if (c == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(c);
		return (1);
	}

	for (i = 0; i < (index - 1); i++)
	{
		if (c->next == NULL)
			return (-1);

		c = c->next;
	}

	tmp = c->next;
	c->next = tmp->next;
	free(tmp);
	return (1);
}
