#include "stack.h"

void append(int x, int *size, int **arr) {

    int *temp = realloc(*arr, (*size+1) * sizeof(int));

    if (temp != NULL) { //realloc can fail so give it to a temp
        *arr = temp;
        (*arr)[*size] = x;
        (*size)++;
    }

}

void pop(int *size, int **arr) {
    if (*size > 0){
        (*size)--;

        int *temp = realloc(*arr, *size * sizeof(int));

        if (temp != NULL) {
            *arr = temp;
        }

    } else if (*size == 0) { //you shouldnt do realloc(_, 0) apparently 
        *arr = NULL;
    }

}

void insert(int value, int index, int *size, int **arr) { 
    if (index < 0 || index > *size) return;


    int *temp = realloc(*arr, (*size+1) * sizeof(int));

    (*size)++; //if realloc fails, size wont change

    if (temp != NULL) { //if realloc changes address, temp[i+1] = (*arr)[i]; will point to freed memeory

        for (int i = *size-1; i > index; i--) {
            temp[i] = temp[i-1];
        }

        temp[index] = value;

        *arr = temp;
    }

}

int get(int index, int *arr) {
    return arr[index];
}
