#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define BUFFER_SIZE 1024

int table_size = 10;


int main() {
    LinkedList ptr_array[table_size]; 

    for (int i = 0; i < table_size; i++) {
        ptr_array[i] = (LinkedList){0}; // Initialize each linked list
    }

    while (1) {
        //key
        printf("Enter a key: ");
        char *buffer_key = malloc(BUFFER_SIZE);

        if (!fgets(buffer_key, BUFFER_SIZE, stdin)) {
            free(buffer_key);
            break;
        }
        buffer_key[strcspn(buffer_key, "\n")] = 0; // Remove newline character
        printf("You entered: %s\n", buffer_key);

        //value
        printf("Enter a value to hash: ");
        char *value_buffer = malloc(BUFFER_SIZE);

        if (!fgets(value_buffer, BUFFER_SIZE, stdin)) {
            free(value_buffer);
            break;
        }
        value_buffer[strcspn(value_buffer, "\n")] = 0; // Remove newline character
        printf("You entered: %s\n", value_buffer);



        long long int x = hash_function(buffer_key, 10);
        printf("Hash value: %lld\n", x);

        Node *new_tail1 = create_node(buffer_key, value_buffer);
        if (new_tail1 == NULL) {
            fprintf(stderr, "Memory allocation failed for new_tail1\n");
            free(buffer_key);
            free(value_buffer);
            continue;
        }
        printf("%p\n", new_tail1);

        if (ptr_array[x].head == NULL) {
            ptr_array[x] = linked_list(buffer_key, value_buffer);
            printf("Created new linked list at index %lld with key %s and value %s\n", x, ptr_array[x].head->key, ptr_array[x].head->value);
        } else {
            Node *current = ptr_array[x].head;
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = new_tail1;
            ptr_array[x].length++;

        }

        for (int i = 0; i < table_size; i++) {
            printf("\n\nLinked List at index %d:\n", i);
            loop(ptr_array, i);
        }



    }
}

