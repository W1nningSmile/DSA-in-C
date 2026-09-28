#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;


Node create_tail(int value);
void add(Node **tail, Node *new_tail, int *length);
void loop(Node *head);

int main() {
    int length = 2;

    Node temp = {12, NULL};
    Node *tail = &temp;
    Node head = {13, &temp};

    Node new_tail1 = create_tail(19);
    add(&tail, &new_tail1, &length);

    Node new_tail2 = create_tail(23455);
    add(&tail, &new_tail2, &length);

    loop(&head);
    return 0;
}

Node create_tail(int value) {
    return (Node){value, NULL};
} 

void add(Node **tail, Node *new_tail, int *length) {
    //take tail and new node

    (*tail)->next = new_tail;
    *tail = new_tail;
    (*length)++;
}

void loop(Node *head) { 
    for (Node *ptr = head; ptr != NULL; ptr = ptr->next) { //sets first ptr to head and loops 1 by 1 by using .next to go to the next ptr
                                                           // until it reaches an empty ptr
        printf("%d\n", ptr->value);
    }
}