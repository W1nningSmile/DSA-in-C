#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void check_file_status(FILE *fileptr) {
    if (fileptr == NULL) {
        printf("Error opening file.\n");
        FILE *fileptr = fopen("unsorted.txt", "w");
        fclose(fileptr);
        exit(1);
    }
}

void resize_array( unsigned int **arr, int *size) {
    *size *= 2;
    *arr = realloc(*arr, *size * sizeof( unsigned int));
}

void loop_through_arr( unsigned int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%u\n", arr[i]);
    }
}

void selection_sort(unsigned int *arr, int size) {
    int current_min_index;
    int rep = 0;
    int buffer ;

    for (int i = 0; i < size ; i++) {
        current_min_index = i;
        for (int j = i; j < size; j++) {
            rep++;
            if (arr[j] < arr[current_min_index]) {
                current_min_index = j;
            }
        }
        buffer = arr[current_min_index];
        arr[current_min_index] = arr[i];
        arr[i] = buffer;
    }
    printf("Number of comparisons: %d\n", rep);
}