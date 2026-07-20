#include <stdio.h>
#include <stdlib.h>

#include "stack.c"

int main() {
    //setup
    int *arr = NULL; //malloc(0) can fail?
    int size = 0;

    append(6, &size, &arr); //need to pass int ** ptr bc the address might change during realloc and just passing int * will only send a copy of the address of the array, not the pointer to the array 
                         //so if the address changes during realloc, we wouldnt get the update
    printf("worked\n");

    printf("size: %d\n", size);

    for (int i = 0; i < size; i++) {
        printf("The index #%d is: %d\n", i, (arr)[i]);
    }


    printf("\n\n\n");


    //pop(&size, &arr);
    //printf("%d\n", size);

    //for (int i = 0; i < size; i++) {
    //    printf("The index #%d is: %d\n", i, (arr)[i]);
    //}//i in larr[sizeof(&arr)/sizeof(int)]

    insert(0, 0, &size, &arr);

    printf("%d\n", size);

    for (int i = 0; i < size; i++) {
        printf("The insert #%d is: %d\n", i, (arr)[i]);
    }//i in larr[sizeof(&arr)/sizeof(int)]

    printf("%d", get(1, arr));

    return 0;
}

//note: think of ptrs as the units of k in reaction orders of chem. you need to match the units to make it work.
// * removes one and & adds one
// want to have int ** == int **, not int * == int **