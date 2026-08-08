#include<stdio.h>
#include<stdlib.h>

#include "list.h"

enum list {EXIT = 0, ADD_FIRST, ADD_LAST, ADD_POS, DELETE_FIRST, DELETE_LAST, DELETE_POS, REVERSE, DISPLAY};

int getchoice()
{
	int ret;

	printf("0. Exit\n");
	printf("1. Add at first\n");
	printf("2. Add at last\n");
	printf("3. Add at position\n");
	printf("4. Delete first\n");
	printf("5. Delete last\n");
	printf("6. Delete from position\n");
	printf("7. Reverse link list\n");
	printf("8. Display list\n");

	printf("Enter your choice \n");
	scanf("%d",&ret);

	return ret;
}

int main()
{
	node_t *head = NULL;
	int choice = 0, data = 0, pos = 0;

	while(1)
	{
		choice = getchoice();

		switch(choice)
		{
			case EXIT:
				exit(0);
				break;

			case ADD_FIRST:
				printf("Enter a data for newnode\n");
				scanf("%d",&data);
				head = add_at_first(head,data);
				break;

			case ADD_LAST:
				printf("Enter a data for newnode\n");
				scanf("%d",&data);
				head = add_at_last(head,data);
				break;

			case ADD_POS:
				printf("Enter a data for newnode\n");
				scanf("%d",&data);
				printf("Enter a pos\n");
				scanf("%d",&pos);
				if(pos > (head->count))
					printf("Enter a valid position there are only %d element in list\n",head->count);
				else
					head = add_at_pos(head,data,pos);
				break;

			case DELETE_FIRST:
				 head = delete_at_first(head);
				break;

			case DELETE_LAST:
				head = delete_from_last(head);
				break;

			case DELETE_POS:
				printf("Enter a position to delete a node\n");
				scanf("%d",&pos);

				if(pos > head->count)
					printf("Enter a valid position\n");
				else
					head = delete_from_pos(head,pos);
				break;

			case REVERSE:
				head = reverse(head);
				break;

			case DISPLAY:
				display(head);
				break;

			default:
				printf("This is not valid choice please enter correct choice\n");
				break;
		}
	}
	return 0;
}
