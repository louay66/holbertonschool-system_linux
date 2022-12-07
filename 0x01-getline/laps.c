#include "laps.h"
#include <string.h>
/**
 *race_state-count how many laps in racing for echa car
 *@id:list of id of cars
 *@size:size of list
 * Return: void
 */

void race_state(int *id, size_t size)
{
	static car_race *head;
	car_race *node;

	node = head;
	if (size)
	{
		check_list(&head, id, size);
		print(&head);
	}
	else if (size == 0)
	{
		while (node)
		{
			node = node->next;
			free(head);
			head = node;
		}
	}
}
/**
 *check_list-check if id in list else insert it
 *@head:linkedlist nodes
 *@id:id of cars
 *@size:size of list
 * Return: void
 */
void check_list(car_race **head, int *id, size_t size)
{
	car_race *node = *head;
	size_t i;

	for (i = 0; i < size; i++)
	{
		while (node)
		{
			if (id[i] == node->id)
			{
				++node->laps;
				break;
			}
			node = node->next;
		}
		if (!node)
		{
			printf("Car %i joined the race\n", id[i]);
			insert(head, addnode(id[i]));
		}
	}
}
/**
 *insert-insert into linked list acording
 *@head:linkedlist nodes
 *@newnode:new node to insert into linked list
 * Return: void
 */

void insert(car_race **head, car_race *newnode)
{
	if (*head == NULL || (*head)->id >= newnode->id)
	{
		newnode->next = *head;
		*head = newnode;
		return;
	}

	car_race *current = *head;

	while (current->next != NULL && current->next->id < newnode->id)
		current = current->next;

	newnode->next = current->next;
	current->next = newnode;
}

/**
 *addnode-creat new node
 *@id:value of node
 * Return: newnode
 */

car_race *addnode(int id)
{
	car_race *new;

	new = malloc(sizeof(car_race));
	if (!new)
	{
		return (NULL);
	}
	new->id = id;
	new->laps = 0;
	new->next = NULL;
	return (new);
}

/**
 *print-print nodes
 *@head:linkedlist nodes
 * Return: void
 */

void print(car_race **head)
{
	car_race *list = *head;

	printf("Race state:\n");
	while (list)
	{
		printf("Car %i [%lu laps]\n", list->id, list->laps);
		list = list->next;
	}
}
