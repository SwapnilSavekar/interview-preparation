Singly Linked List
Overview

This project implements a Singly Linear Linked List in C++.

A singly linked list consists of nodes where each node contains:

Data
A pointer to the next node

The last node points to NULL, indicating the end of the list.

Node Structure
+--------+---------+      +--------+---------+      +--------+---------+
|  data  |  next   | ---> |  data  |  next   | ---> |  data  |  NULL   |
+--------+---------+      +--------+---------+      +--------+---------+
   Node 1                   Node 2                   Node 3

Functions Implemented
1. Create Node
node_t* create_node(int data);

Creates a new node dynamically, initializes it with the given data, and sets its next pointer to NULL.

Time Complexity: O(1)

2. Add at First
node_t* add_at_first(node_t *head, int data);

Adds a new node at the beginning of the linked list.


3. Add at Last
node_t* add_at_last(node_t *head, int data);

Adds a new node at the end of the linked list.

4. Add at Position
node_t* add_at_pos(node_t *head, int data, int pos);

Adds a new node at the specified position.

This implementation uses 1-based indexing:

Position:
  1     2     3     4
  ↓     ↓     ↓     ↓
 10 →  20 →  30 →  40 → NULL

5. Delete at First
node_t* delete_at_first(node_t *head);

Removes the first node from the linked list and returns the updated head.

6. Delete from Last
node_t* delete_from_last(node_t* head);

Removes the last node from the linked list.

7. Delete from Position
node_t* delete_from_pos(node_t *head, int pos);

Deletes the node at the specified position.

8. Display
void display(node_t *head);

Traverses the linked list from the head and displays all elements.

9. Reverse
node_t* reverse(node_t *head);

Reverses the linked list and returns the new head.
