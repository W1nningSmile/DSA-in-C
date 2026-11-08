# Selection Sort in C

A C program that reads unsigned integers from a text file, sorts them with selection sort, and prints the sorted result along with the number of comparisons made during the sorting process.

## Project Structure

| File | Purpose |
|------|---------|
| `main2.c` | Reads `unsorted.txt` into a dynamic array, sorts it, and prints it. |
| `stack.c` | Implementations of the helper functions (file check, resize, print, sort). |
| `stack.h` | Declarations and the `array_stack` struct. |
| `unsorted.txt` | Input file (one integer per line). |

## How It Works

1. Opens `unsorted.txt` for reading. If the file doesn't exist, the program prints an error, creates an empty `unsorted.txt`, and exits with error code 1 so you can fill it in.
2. Reads the file line by line and stores each number in a dynamically allocated array (`array_stack`), growing the array with `realloc` when it gets close to full.
3. Sorts the array in ascending order with selection sort.
4. Prints the number of comparisons, then each sorted value on its own line.

### Data Structure

```c
typedef struct array_stack {
    unsigned int *arr;  // dynamic array of values
    int size;           // allocated capacity
    int index;          // number of elements stored
} array_stack;
```

### Functions

| Function | Description |
|----------|-------------|
| `check_file_status(FILE *fileptr)` | Exits with an error if the file failed to open (and creates an empty `unsorted.txt`). |
| `resize_array(unsigned int **arr, int *size)` | Doubles the array capacity using `realloc`. |
| `loop_through_arr(unsigned int *arr, int size)` | Prints every element, one per line. |
| `selection_sort(unsigned int *arr, int size)` | Sorts in place and prints the comparison count. |


## Example

`unsorted.txt`:

```
42
7
19
3
25
```

Output:

```
Number of comparisons: 15
3
7
19
25
42
```

## Input Format

- One non-negative integer per line.
- Each line is read with a 10-character buffer, so keep numbers to 8 digits or fewer.

## Complexity

Selection sort runs in **O(n²)** time and **O(1)** extra space. In this implementation the inner loop starts at `i`, so the comparison count is always `n(n + 1) / 2` regardless of input order (15 for the 5-element example above).

## Known Limitations

- Fixed 10-character line buffer limits the size of each number.
- `malloc` and `realloc` results are not checked for `NULL`.
- Negative numbers are not supported because values are stored as `unsigned int`.
