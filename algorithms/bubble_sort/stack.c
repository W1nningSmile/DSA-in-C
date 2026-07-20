#include "stack.h"

void bubble_sort(int *arr, int size) {

    for (int j = 0; j < size-1; j++){ //size-1 for both in order to ignore the last index --> last index not needed to check
       for (int i = 0; i < size-1-j; i++) { // "-j" bc j is the index of the last biggest number
            if (arr[i] > arr[i+1]) {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }

}