# Hash Table in C

A C program that implements an elementary hash table using separate chaining. It repeatedly prompts for a key and a value, hashes the key to pick one of 10 buckets, stores the pair in that bucket's linked list, and prints the whole table after every insertion.

## Project Structure

| File | Purpose |
|------|---------|
| `main.c` | Contains the input loop and the bucket array. |
| `stack.c` | Implementations of the helper functions (hash, node creation, printing). |
| `stack.h` | Declarations and the `Node` and `LinkedList` structs. |

## How It Works

1. Creates an array of 10 `LinkedList` buckets, all zero-initialized (empty).
2. Prompts for a key and a value with `fgets`, stripping the trailing newline from each.
3. Hashes the key: each character's value is multiplied by 31 and added to a running total, then the total is taken modulo 10 to select a bucket. The running total is printed after every character.
4. If the bucket is empty, a new linked list is started with the pair as its head. Otherwise the program walks to the end of the chain and appends a new node (separate chaining handles collisions).
5. Prints every bucket and its nodes after each insertion.
6. Repeats until input ends (EOF).

### Data Structures

```c
typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

typedef struct {
    Node *tail;   // declared but not currently used
    Node *head;
    int length;
} LinkedList;
```

### Functions

| Function | Description |
|----------|-------------|
| `hash_function(char *key, int table_size)` | Returns the bucket index for a key and prints the hash after each character. |
| `create_node(char *key, char *value)` | Allocates a node with `next` set to `NULL`. |
| `linked_list(char *key, char *value)` | Builds a `LinkedList` with a single head node and length 1. |
| `loop(LinkedList *ptr_array, int x)` | Prints every node in bucket `x`. |
| `enumerate_linked_list(Node *head)` | Prints every node starting from `head`. Defined in `stack.c` but currently unused and not declared in `stack.h`. |
| `add_tail(Node **tail, Node *new_tail, int *length)` | Declared in `stack.h` but not implemented. |


## Example

Inputs (key, then value):

```
cat   → meow
dog   → woof
act   → tac
```

How the keys hash:

| Key | Calculation | Bucket |
|-----|-------------|--------|
| `cat` | (99 + 97 + 116) × 31 = 9672, 9672 % 10 | 2 |
| `dog` | (100 + 111 + 103) × 31 = 9734, 9734 % 10 | 4 |
| `act` | (97 + 99 + 116) × 31 = 9672, 9672 % 10 | 2 |

`act` lands in the same bucket as `cat`, so it is chained after it. Output after the third entry (empty buckets and the per-character hash lines are trimmed):

```
Linked List at index 2:
Node 0: Key: cat, Value: meow
Node 1: Key: act, Value: tac

Linked List at index 4:
Node 0: Key: dog, Value: woof
```

## Input Format

- Keys and values are typed at the prompts, one per line.
- Each is read into a 1024-byte buffer, so keep both to 1023 characters or fewer.

## Complexity

Hashing a key takes **O(k)** time for a key of length `k`. Inserting walks to the end of the chain, so it costs **O(chain length)**. Because the table has a fixed 10 buckets, chains grow in proportion to the number of entries `n`, making insertion **O(n)** in the long run. Space is **O(n)**.

## Known Limitations

- Only insertion is supported: there is no lookup, update, or delete, and duplicate keys are stored as separate nodes. (for now, will probably be added later)
- The hash equals 31 × (sum of the characters), so anagrams always collide (`cat` and `act` both map to bucket 2).
- The table size is fixed at 10, and `hash_function` is called with a hardcoded `10` rather than the `table_size` variable. (will change next patch)
- Memory is never freed. When a bucket is empty, the extra node created by `create_node` is also leaked. (will change next patch)
- `malloc` results in `create_node` and `linked_list` are not checked for `NULL`, so the `NULL` check in `main.c` can never trigger.
- Input longer than 1023 characters spills into the next prompt. 
- `add_tail` is declared but never defined.
