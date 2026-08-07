#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGTH 10

enum stack {EXIT = 0, PUSH, POP, PEEK, DISPLAY};

int stack_arr[MAX_LENGTH];
int top = -1, item = 0;

void push(int elememt);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int getChoice();

int main()
{
	int choice;

	while(1)
	{
		choice = getChoice();
		
		switch(choice)
		{
			case EXIT:
				exit(0);
				break;

			case PUSH:
				printf("Enter an item to be pushed inside stack\n");
				scanf("%d",&item);
				push(item);
				break;

			case POP:
				item = pop();
				printf("Item removed from stack is : %d\n",item);
				break;

			case PEEK:
				item = peek();
				printf("Item on top of stack : %d\n",item);
				break;

			case DISPLAY:
				display();
				break;

			default:
				printf("Please enter valid choice\n");
				break;
		}	
	}
	return 0;
}

int getChoice()
{
	int result;

	printf("0. Exit\n");
	printf("1. Push element in stack\n");
	printf("2. Pop element from stack\n");
	printf("3. Peek element from stack\n");
	printf("4. Display stack\n");

	printf("Enter your choice\n");
	scanf("%d",&result);

	return result;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if(top == (MAX_LENGTH - 1))
		return 1;
	else
		return 0;
}

void push(int element)
{
	if(isFull())
	{
		printf("Stack overflow\n");
		return;
	}

	top = top + 1;
	stack_arr[top] = element;
}

int pop()
{
	int item = 0;

	if(isEmpty())
	{
		printf("Stack underflow\n");
		return 0;
	}

	item = stack_arr[top];
	stack_arr[top] = 0;
	top = top - 1;
	return item;
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack underflow\n");
		return 0;
	}

	return stack_arr[top];
}

void display()
{
	int i = top;

	if(isEmpty())
	{
		printf("Stack underflow\n");
		return;
	}

	printf("Elements inside stack\n");
	for(i; i >= 0; i--)
		printf("%d\t",stack_arr[i]);
	printf("\n");
}
