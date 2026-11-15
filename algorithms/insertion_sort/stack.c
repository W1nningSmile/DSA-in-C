#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void check_file_status(FILE *fileptr) {
    if (fileptr == NULL) {
        perror("error opening file.\n"); //prints error message (very neat icl)
        fileptr = fopen("unsorted.txt", "w");
        fclose(fileptr);
        exit(1);
    }
}

array_stack *read_file_line(FILE *fileptr, char *file_list) {
    array_stack *stack = malloc(sizeof(array_stack));
    stack->size = 0;
    stack->index = 0;

    if (stack == NULL) {
        perror("Error allocating memory for stack.\n");
        fclose(fileptr);
        return NULL;
    }

    char *buffer = malloc(MAX_LINE_LENGTH * sizeof(char));

    if (buffer == NULL) {
        perror("Error allocating memory for buffer.\n");
        fclose(fileptr);
        free_safe(stack);
        return NULL;
    }

    while(fgets(buffer , MAX_LINE_LENGTH, fileptr) != NULL) { //counts amount of lines
        stack->size++;
    }

    free_safe(buffer);

    stack->arr = malloc(stack->size * sizeof(long int));

    if (stack->arr == NULL) {
        perror("Error allocating memory for stack array.\n");
        fclose(fileptr);
        free_safe(stack);
        return NULL;
    }

    rewind(fileptr);
    
    while (fgets(file_list, MAX_LINE_LENGTH, fileptr) != NULL) { //reads each line and converts to long int
        stack->arr[stack->index++] = (unsigned long int) strtol(file_list, NULL, 10);
    }

    return stack;
}

void echo_list(array_stack * stack) {
    for (size_t i = 0; i < stack->size; i++) {
        printf("%lu\n", stack->arr[i]);
    }
}

void insertion_sort(array_stack *stack) {
    for (size_t i =1; i < stack->size; i++) { //sets up an index range where we know that the elements are sorted
        unsigned long int current = stack->arr[i];
        for (size_t j = i; j > 0 && stack->arr[j-1] > current; j--) { //checks if previous element is greater than current, if so, swaps them
            stack->arr[j] = stack->arr[j-1];
            stack->arr[j-1] = current;
        }
    }
}