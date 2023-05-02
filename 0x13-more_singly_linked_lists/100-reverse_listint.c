#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: A pointer to the address of
 *        the head of the list_t list.
 * Return: pointer to the first node in the new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *ahead, *prv;

	if (head == NULL || *head == NULL)
		return (NULL);

	prv = NULL;

	while ((*head)->next != NULL)
	{
		ahead = (*head)->next;
		(*head)->next = prv;
		prv = *head;
		*head = ahead;
	}

	(*head)->next = prv;

	return (*head);
}

