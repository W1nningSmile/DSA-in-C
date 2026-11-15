#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_LINE_LENGTH 64
#define free_safe(ptr) do { free(ptr); ptr=NULL; } while(0) //preprocessor macro to free memory and set pointer to NULL
                                                            //uses do {...} while (0) to make a multistatement behave as a single statement

typedef struct array_stack {
    unsigned long int *arr;
    size_t size;
    int index;
} array_stack;

void check_file_status(FILE *fileptr);
array_stack *read_file_line(FILE *fileptr, char *file_list);
void echo_list(array_stack *stack);
void insertion_sort(array_stack *stack);

#endif