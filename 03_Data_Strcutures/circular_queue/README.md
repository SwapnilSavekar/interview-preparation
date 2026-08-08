# circular queue Implementation Using Array

Implementation of a **circular Queue using an array** in C.

A queue follows the **FIFO (First In First Out)** principle. The element inserted first is removed first.

The implementation maintains two indexes:

* `front` – points to the first element
* `rear` – points to the last element

## Operations

```cpp
int enqueue(int data);

int dequeue();

int peek();

bool is_empty();

bool is_full();

void display();
```

## Example

```text
Enqueue: 10, 20, 30

Front                       Rear
  ↓                           ↓
+----+----+----+
| 10 | 20 | 30 |
+----+----+----+

Dequeue()

10 is removed first.

