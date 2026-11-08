#ifndef STACK_H
#define STACK_H

#include <stdio.h>

typedef struct array_stack {
    unsigned int *arr;
    int size;
    int index;
} array_stack;


void check_file_status(FILE *fileptr);
void resize_array( unsigned int **arr, int *size);
void loop_through_arr( unsigned int *arr, int size);
void selection_sort(unsigned int *arr, int size);


#endif