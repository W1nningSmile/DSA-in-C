#ifndef STACK_H
#define STACK_H

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *tail;
    Node *head;

    int length;
} LinkedList;


Node *create_node(int value);
LinkedList linked_list(int value1, int value2);
void add_tail(Node **tail, Node *new_tail, int *length);
void loop(Node **head);
void add_head(Node **head, Node *new_head, int *length);
void insert_node(Node **front, Node *new_node, int *length, int position);
void remove_node(Node **front, int *length, int position);
int get(Node **front, int position);
int find(Node **front, int value);

#endif
