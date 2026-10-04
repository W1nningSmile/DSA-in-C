#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main() {
    LinkedList list = linked_list(12,45);
    
    Node *new_tail1 = create_node(19);
    add_tail(&(list.tail), new_tail1, &(list.length));

    Node *new_tail2 = create_node(1);
    add_tail(&(list.tail), new_tail2, &(list.length));

    Node *new_tail3 = create_node(29495);
    add_tail(&(list.tail), new_tail3, &(list.length));

    Node *node4 = create_node(234);
    add_head(&(list.head), node4, &(list.length));

    Node *node5 = create_node(567);
    insert_node(&(list.head), node5, &(list.length), 4);

    remove_node(&(list.head), &(list.length), 7);

    int x = get(&(list.head), 3);

    int y = find(&(list.head), 19);

    printf("Value at index 3: %d\n", x);
    printf("Index of value 19: %d\n", y);

    loop(&(list.head));
    return 0;
}