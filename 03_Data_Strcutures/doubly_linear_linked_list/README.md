Doubly Linear Linked List

Implementation of a Doubly Linear Linked List in C++.

Each node contains three parts:

+--------+--------+--------+
|  prev  |  data  |  next  |
+--------+--------+--------+

The prev pointer points to the previous node and the next pointer points to the next node. The prev pointer of the first node and the next pointer of the last node are NULL.

Operations
node_t* create_node(int data);

node_t* add_at_first(node_t *head, int data);

node_t* add_at_last(node_t *head, int data);

node_t* add_at_pos(node_t *head, int data, int pos);

node_t* delete_first(node_t *head);

node_t* delete_last(node_t *head);

node_t* delete_from_pos(node_t *head, int pos);

void display(node_t *head);

node_t* reverse(node_t *head);
