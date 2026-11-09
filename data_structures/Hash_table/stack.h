#ifndef STACK_H
#define STACK_H

typedef struct Node{
    char *key;
    char *value;
    struct Node *next;
} Node;

typedef struct {
    Node *tail;
    Node *head;

    int length;
} LinkedList;

Node *create_node(char *key, char *value);
LinkedList linked_list(char *key, char *value);
long long int hash_function(char *key, int table_size);
void loop(LinkedList *ptr_array, int x);

#endif
