#include<stdio.h>
#include<stdlib.h>

#include "list.h"

node_t* create_node(int data)
{
	node_t *temp = (node_t*)malloc(sizeof(node_t));

	if(temp == NULL)
	{
		perror("Malloc failed to allocate memory\n");
		exit(0);
	}

	temp->data = data;
	temp->next = NULL;

	return temp;
}

node_t* add_at_first(node_t *head , int data)
{
	node_t *newnode = create_node(data);

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}

	head->count = head->count + 1;

	return head;
}

node_t* add_at_last(node_t *head, int data)
{
	node_t *newnode = create_node(data);

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		node_t *trav = head;
		while(trav->next != NULL)
			trav = trav->next;
		
		trav->next = newnode;
	}

	head->count = head->count + 1;

	return head;
}

node_t* add_at_pos(node_t *head, int data, int pos)
{
	int i = 1;
	node_t *trav = head;
	node_t *newnode = create_node(data);

	for(i; i < pos - 1; i++)
		trav = trav->next;

	newnode->next = trav->next;
	trav->next = newnode;
	
	head->count = head->count + 1;
	return head;
}

node_t* delete_at_first(node_t *head)
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		exit(0);
	}

	node_t *temp = NULL;
	temp = head;

	head = temp->next;
	free(temp);

	head->count = head->count - 1;

	return head;
}

node_t* delete_from_last(node_t *head)
{
	if(head == NULL)
	{
		printf("There is no element to delete in list\n");
		exit(0);
	}
	else if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		node_t *trav = head;

		while(trav->next->next != NULL)
			trav = trav->next;

		free(trav->next);
		trav->next = NULL;
	}

	head->count = head->count - 1;

	return head;
}

node_t* delete_from_pos(node_t *head, int pos)
{
	if(head == NULL)
	{
		printf("There is no element in list for deletion\n");
		exit(0);
	}
	else if(pos == 1)
	{
		free(head);
		head = NULL;
	}
	else
	{
		int i = 1;
		node_t *trav = head;
		node_t *temp = NULL;
		while(i < pos - 1)
		{
			trav = trav->next;
			i = i + 1;
		}

		temp = trav->next;
		trav->next = temp->next;
		free(temp);
		temp = NULL;
	}
	head->count = head->count - 1;

	return head;
}

node_t* reverse(node_t *head)
{
	node_t *next, *prev, *trav;

	prev = NULL;
	trav = head;

	while(trav != NULL)
	{
		next = trav->next;
		trav->next = prev;
		prev = trav;
		trav = next;
	}
	head = prev;

	return head;
}

void display(node_t *head)
{
	if(head == NULL)
	{
		printf("List is empty\n");
		exit(0);
	}

	node_t *trav = head;
	printf("The element in the list are \n");

	while(trav != NULL)
	{
		printf("%d\t",trav->data);
		trav = trav->next;
	}

	printf("\n");
}
