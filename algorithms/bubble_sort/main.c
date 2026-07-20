#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main() {
    int arr[] = {
    42, 7, 19, 88, 3,
    55, 21, 1, 73, 14,
    67, 29, 90, 8, 34,
    2, 76, 50, 11, 61
    };
    int size = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", (arr)[i]);
    }

    return 0; 
}

//output: 1 2 3 7 8 11 14 19 21 29 34 42 50 55 61 67 73 76 88 90 