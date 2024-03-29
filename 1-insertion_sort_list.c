#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 * the Insertion Sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *prev, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
temp = current->next;
prev = current->prev;

while (prev != NULL && prev->n > current->n)
{
if (prev->prev != NULL)
prev->prev->next = current;
else
*list = current;

if (current->next != NULL)
current->next->prev = prev;

prev->next = current->next;
current->prev = prev->prev;

current->next = prev;
prev->prev = current;

print_list(*list);

prev = current->prev;
}

current = temp;
}
}
