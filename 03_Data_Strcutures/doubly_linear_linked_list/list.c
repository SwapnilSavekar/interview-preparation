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
	temp->prev = NULL;

	return temp;
}

node_t* add_at_first(node_t* head, int data)
{
	node_t *newnode = create_node(data);

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}

	head->count = head->count + 1;

	return head;
}

node_t* add_at_last(node_t *head, int data)
{
	node_t* newnode = create_node(data);

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		node_t *trav = head;
		while(trav->next != NULL)
			trav = trav->next;

		newnode->prev = trav;
		trav->next = newnode;
	}

	head->count = head->count + 1;

	return head;
}

node_t* add_at_pos(node_t *head, int data, int pos)
{
	int i = 1;

	node_t *newnode = create_node(data);

	if(head == NULL)
		head = newnode;
	else
	{
		node_t *trav = head;
		while(i < pos - 1)
		{
			trav = trav->next;
			i++;
		}

		newnode->prev = trav;
		newnode->next = trav->next;
		trav->next = newnode;
	}

	head->count = head->count + 1;

	return head;
}

node_t* delete_first(node_t *head)
{
	if(head == NULL)
		printf("There is no element present in list\n");
	else if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		node_t *temp = head;
		head = head->next;
		if(head != NULL)
			head->prev = NULL;
		free(temp);
		temp = NULL;
		head->count = head->count - 1;
	}

	return head;
}

node_t* delete_last(node_t *head)
{
	if(head == NULL)
		printf("The list is empty\n");
	else if(head->next == NULL)
		head = delete_first(head);
	else
	{
		node_t *temp = NULL;
		node_t *trav = head;

		while(trav->next->next != NULL)
			trav = trav->next;

		temp = trav->next;
		trav->next = NULL;
		free(temp);
		temp = NULL;
	}

	return head;
}

node_t* delete_from_pos(node_t *head, int pos)
{
	if(head == NULL)
		printf("The list is empty\n");
	else if(pos == 1)
		head = delete_first(head);
	else
	{
		int i = 1;
		node_t *trav = head;
		node_t *temp = NULL;
		while(i < pos -1)
		{
			trav = trav->next;
			i = i + 1;
		}

		temp = trav->next;
		trav->next = temp->next;
		temp->next->prev = trav;
		free(temp);
		temp = NULL;
	}

	return head;
}

node_t* reverse(node_t *head)
{
	node_t *p1, *p2;

	p1 = head;
	p2 = p1->next;

	p1->next = NULL;
	p1->prev = p2;

	while(p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}

	head = p1;

	return head;
}

void display(node_t *head)
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		node_t *trav = head;
		printf("Elements in the list are : \n");
		while(trav != NULL)
		{
			printf("%d\t",trav->data);
			trav = trav->next;
		}
		printf("\n");
	}
}
