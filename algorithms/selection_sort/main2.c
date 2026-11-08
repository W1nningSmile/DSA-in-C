#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
    char buffer[10];

    array_stack A1;
    A1.arr = malloc(16 * sizeof( unsigned int));
    A1.size = 16;
    A1.index = 0;

    FILE *fileptr = fopen("unsorted.txt", "r");

    check_file_status(fileptr);

    while (fgets(buffer, 10, fileptr)){
        A1.arr[A1.index] = strtol(buffer, NULL, 10);
        A1.index++;

        if (A1.size - 8 == A1.index) {
            resize_array(&A1.arr, &A1.size);
        }
    }

    selection_sort(A1.arr, A1.index);

    loop_through_arr(A1.arr, A1.index);

    fclose(fileptr);
}

