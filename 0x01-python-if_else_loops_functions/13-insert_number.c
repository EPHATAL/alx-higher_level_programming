#include <stdlib.h>
#include "lists.h"

/**
*insert_node - inserts node in sorted
*@head: address of head pointer
*@number: number
*Return: inserted mode
*/
listint_t *insert_node(listint_t **head, int number)
{
listint_t *node = *head, *new = malloc(sizeof(listint_t));

if (!new)
return (NULL);

new->n = number;
new->next = NULL;

if (!node || new->n < node->n)
{
new->next = node;
return (*head = new);
}

while (node)
{
if (!node->next || new->n < node->next->n)
{
new->next = noce->next;
node->next = new;
return (node);
}
node = node->next;
}
return (NULL)
}
