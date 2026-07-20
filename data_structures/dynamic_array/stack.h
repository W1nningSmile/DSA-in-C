#ifndef STACK_H
#define STACK_H

void append(int x, int *size, int **arr);
void pop(int *size, int **arr);
void insert(int value, int index, int *size, int **arr);
int get(int index, int *arr);

#endif