#ifndef STACK_H
#define STACK_H

#include <stdio.h>

typedef struct array_stack {
    unsigned int *arr;
    size_t size;
    int index;
} array_stack;

#endif