#include "stack.h"

#include <stdio.h>
#include <stdlib.h>



LinkedList linked_list(int value1, int value2) {
    Node *Head = malloc(sizeof(Node));
    Node *Tail = malloc(sizeof(Node));

    Head->value = value1;
    Head->next = Tail;

    Tail->value = value2;
    Tail->next = NULL;

    LinkedList list = {
        .head = Head,
        .tail = Tail,
        .length = 2
    };

    return list;
}

Node *create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_tail(Node **tail, Node *new_tail, int *length) {
    //take tail and new node

    (*tail)->next = new_tail;
    *tail = new_tail;
    (*length)++;
}

void loop(Node **head) { 
    int count = 0;
    for (Node *ptr = *head; ptr != NULL; ptr = ptr->next) { //sets first ptr to head and loops 1 by 1 by using .next to go to the next ptr
                                                           // until it reaches an empty ptr
        
        printf("Node %d: %d\n", count, ptr->value);
        count++;
    }
}

void add_head(Node **head, Node *new_head, int *length) {
    new_head->next = *head;
    *head = new_head;
    (*length)++;
}

void insert_node(Node **front, Node *new_node, int *length, int position) {
    if (position > *length) {
        printf("Position is out of bounds\n");
        return;
    }

    for (Node *ptr = *front; ptr != NULL; ptr = ptr->next) { //goated loop icl
        if (position == 0) {
            new_node->next = (ptr)->next;
            (ptr)->next = new_node;
            (*length)++;
            break;
        }
        position--;
    }
}

void remove_node(Node **front, int *length, int position) {
    if (position == 0) {
        Node *temp = (*front)->next;
        free(*front);
        *front = temp;
        (*length)--;
        return;
    }

    if (position >= *length) {
        printf("Position is out of bounds\n");
        return;
    }

    for (Node *ptr = *front; ptr != NULL; ptr = ptr->next) { 
        if (position == 1) {
            Node *next = ((ptr)->next)->next;
            free((ptr)->next);
            (ptr)->next = next;
            (*length)--;
            break;
        }
        position--;
    }
}

int get(Node **front, int position) {
    for (Node *ptr = *front; ptr != NULL; ptr = ptr->next) { 
        position--;
        if (position == 0) {
            return ptr->value;
        }
    }
}

int find(Node **front, int value) {
    int position = 0;
    for (Node *ptr = *front; ptr != NULL; ptr = ptr->next) {
        position++;
        if (ptr->value == value) {
            return position;
        }
    }
    return -1; // Return -1 if the value is not found
}