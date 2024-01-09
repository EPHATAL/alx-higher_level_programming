#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
*check_cycle - checks singly-linked list
*@list: pointer to list
*
*Return: If there is no cycle - 0.
*if there is a cycle -1
*/
int check_cycle(listint_t *list)
{
listint_t *slow = list, *fast = list;

while (fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
	return (1)
}
return (0);
}
