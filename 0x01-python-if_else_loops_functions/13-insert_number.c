#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @number: The number to be inserted.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new_node, *current, *prev = NULL;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
{
return NULL;
}
new_node->n = number;
if (*head == NULL || (*head)->n >= number)
{
new_node->next = *head;
*head = new_node;
return new_node;
}
current = *head;
while (current != NULL && current->n < number)
{
prev = current;
current = current->next;
}
new_node->next = current;
prev->next = new_node;
return new_node;
}
