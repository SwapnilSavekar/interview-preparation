# Queue Implementation Using Array

Implementation of a **Queue using an array** in C++.

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
```

## Complexity

| Operation | Complexity |
| --------- | ---------- |
| Enqueue   | O(1)       |
| Dequeue   | O(1)       |
| Peek      | O(1)       |
| Is Empty  | O(1)       |
| Is Full   | O(1)       |
| Display   | O(n)       |

## Notes

This implementation uses a fixed-size array. When the queue is full, an enqueue operation results in **queue overflow**. When the queue is empty, a dequeue operation results in **queue underflow**.

A circular queue can be used to utilize the unused spaces created after dequeue operation.
