#ifndef __LIST_H
#define __LIST_H

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
	int count;
}node_t;

node_t* create_node(int data);
node_t* add_at_first(node_t *head, int data);
node_t* add_at_last(node_t *head, int data);
node_t* add_at_pos(node_t *head, int data, int pos);
node_t* delete_first(node_t *head);
node_t* delete_last(node_t *head);
node_t* delete_from_pos(node_t *head, int pos);
node_t* reverse(node_t *head);
void display(node_t *head);

#endif
