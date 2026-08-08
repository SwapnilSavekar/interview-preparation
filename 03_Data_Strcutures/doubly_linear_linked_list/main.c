#include<stdio.h>
#include<stdlib.h>

#include "list.h"

enum list {EXIT = 0, ADD_FIRST, ADD_LAST, ADD_POS, DELETE_FIRST, DELETE_LAST, DELETE_POS, REVERSE, DISPLAY};

int getchoice()
{
	int choice;

	printf("0. Exit\n");
	printf("1. Add at first\n");
	printf("2. Add at last\n");
	printf("3. Add at position\n");
	printf("4. Delete first\n");
	printf("5. Delete Last\n");
	printf("6. Delete from position\n");
	printf("7. Reverse list\n");
	printf("8. Display list\n");

	printf("Enter your choice\n");
	scanf("%d",&choice);

	return choice;
}

int main()
{
	node_t *head = NULL;

	int choice = 0, pos = 0, data = 0;

	while(1)
	{
		choice = getchoice();

		switch(choice)
		{
			case EXIT:
				exit(0);
				break;

			case ADD_FIRST:
				printf("Enter data for newnode\n");
				scanf("%d",&data);
				head = add_at_first(head, data);
				break;

			case ADD_LAST:
				printf("Enter data for newnode\n");
				scanf("%d",&data);
				head = add_at_last(head,data);
				break;

			case ADD_POS:
				printf("Enter data for newnode\n");
				scanf("%d",&data);
				printf("Enter a position you want to insert a node\n");
				scanf("%d",&pos);
				add_at_pos(head,data,pos);
				break;

			case DELETE_FIRST:
				head = delete_first(head);
				break;

			case DELETE_LAST:
				head = delete_last(head);
				break;

			case DELETE_POS:
				printf("Enter the position of node which you want to delete\n");
				scanf("%d",&pos);
				head = delete_from_pos(head,pos);
				break;

			case REVERSE:
				head = reverse(head);
				break;

			case DISPLAY:
				display(head);
				break;

			default:
				printf("Please enter a valid choice\n");
				break;
		}
	}
	return 0;
}
