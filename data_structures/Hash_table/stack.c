#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


LinkedList linked_list(char *key, char *value) {
    Node *Head = malloc(sizeof(Node));

    Head->key = key;
    Head->value = value;
    Head->next = NULL;

    LinkedList list = {
        .head = Head,
        .length = 1
    };

    return list;
}

Node *create_node(char *key, char *value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void loop(LinkedList *ptr_array, int x) {
    int count = 0;

    for (Node *ptr = ptr_array[x].head; ptr != NULL; ptr = ptr->next) {
        printf("Node %d: Key: %s, Value: %s\n", count, ptr->key, ptr->value);
        count++;
    }

    printf("\n\n");
}

void enumerate_linked_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}


long long int hash_function(char *key, int table_size) {
    unsigned long long int hash = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        hash = key[i] * 31 + hash;
        printf("Hash after processing character '%c': %llu\n", key[i], hash);
    }

    hash = hash % table_size;
    return hash;
}