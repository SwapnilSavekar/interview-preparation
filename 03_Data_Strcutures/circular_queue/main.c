#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

enum operations {EXIT = 0, INSERT, DELETE, PEEK, DISPLAY};

int queue[MAX_SIZE];

int front = -1, rear = -1;

int getChoice();
void insert(int element);
int delete();
int peek();
void display();
int isEmpty();
int isFull();

int main()
{
	int choice = 0, element = 0;

	while(1)
	{
		choice = getChoice();

		switch(choice)
		{
			case EXIT:
				exit(0);
				break;

			case INSERT:
				printf("Enter an element which you want to insert in queue\n");
				scanf("%d",&element);
				insert(element);
				break;

			case DELETE:
				element = delete();
				printf("Element deleted from queue is : %d\n",element);
				break;

			case PEEK:
				element = peek();
				printf("Element at front of queue is : %d\n",element);
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
	int choice = 0;

	printf("0. Exit\n");
	printf("1. Insert element in queue\n");
	printf("2. Delete element from queue\n");
	printf("3. Get top element from queue\n");
	printf("4. Display queue\n");

	printf("Enter your choice\n");
	scanf("%d",&choice);

	return choice;
}

int isEmpty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
		return 1;
	else
		return 0;
}

void insert(int element)
{
	if(isFull())
	{
		printf("Queue Overflow\n");
		return;
	}

	if(front == -1)
		front = front + 1;
	
	if(rear == MAX_SIZE - 1)
		rear = 0;
	else
		rear = rear + 1;
	queue[rear] = element;
}

int delete()
{
	int element = 0;

	if(isEmpty())
	{
		printf("Queue Underflow\n");
		return 0;
	}

	element = queue[front];
	queue[front] = 0;

	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX_SIZE - 1)
		front = 0;
	else
		front = front + 1;

	return element;
}

int peek()
{
	if(isEmpty())
	{
		printf("Queue Underflow\n");
		return 0;
	}

	return queue[front];
}

void display()
{
	int i = 0;

	if(isEmpty())
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Element present inside queue are : \n");
	for(i = 0; i < MAX_SIZE; i++)
		printf("%d\t",queue[i]);

	printf("\n");
}

