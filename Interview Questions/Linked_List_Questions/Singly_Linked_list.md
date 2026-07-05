# Representation of a Singly Linked List

To represent a node of a singly linked list in C, we use a structure with two data members:

1. **data** – Stores the value contained in the node.
2. **next** – A pointer that stores the address of the next node in the sequence.

```c
struct Node {
    int data;
    struct Node* next;
};
```

---

# Time Complexity

**Time Complexity** measures how much time (or the number of operations) an algorithm takes relative to the size of the input.

## O(1) — Constant Time

The operation takes the same amount of work regardless of the size of the linked list.

**Examples:**
- Insert at the head
- Delete from the head

---

## O(N) — Linear Time

The amount of work grows proportionally to the number of nodes in the linked list.

**Examples:**
- Insert at the end
- Insert at a given position
- Delete from the end
- Delete from a given position
- Print the linked list (traverses every node)

### Example

- 10 nodes → ~10 operations
- 1000 nodes → ~1000 operations

---

# Space Complexity

**Space Complexity** measures how much **extra memory** an algorithm uses while performing an operation.

## O(1) — Constant Extra Space

The algorithm uses only a fixed amount of additional memory, regardless of the size of the linked list.

For linked list insertion and deletion, only a few pointer variables are required.

---

# Interview Question

### **Should space complexity decrease when deleting nodes?**

### Answer

**No.**

Space complexity is **not** about whether the data structure becomes smaller after the operation.

Instead, it measures **the extra memory used by the algorithm while performing the operation**, not the size of the final data structure.

### Example

Before deletion:

```text
10 -> 20 -> 30 -> 40
```

Delete `30`:

```text
10 -> 20 -> 40
```

The total memory occupied by the linked list decreases by one node.

However, during the deletion algorithm, only one temporary pointer is used:

```c
Node* temp = current->next;
current->next = temp->next;
free(temp);
```

Extra memory used:

- One pointer variable (`temp`)
- Constant amount of additional memory

Therefore:

- **Space Complexity = O(1)**
- Even though the linked list itself becomes smaller.

---

# Key Takeaway

- **Time Complexity** depends on **how many nodes are traversed**.
- **Space Complexity** depends on **how much extra memory is used by the algorithm**, **not** on how much memory the data structure occupies after the operation.
