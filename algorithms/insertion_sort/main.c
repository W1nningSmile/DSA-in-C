#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



int main() {
    char *buffer;
    FILE *file = fopen("unsorted.txt", "r");
    check_file_status(file);

    buffer = malloc(MAX_LINE_LENGTH * sizeof(char));

    if (buffer == NULL) {
        perror("Error allocating memory for buffer.\n");
        fclose(file);
        return(1);
    }

    array_stack *sorted_list = read_file_line(file, buffer);
    free_safe(buffer);

    insertion_sort(sorted_list);

    printf("Sorted list:\n");
    echo_list(sorted_list);

    fclose(file);
    free_safe(sorted_list->arr);
    free_safe(sorted_list);

    return 0;
}
