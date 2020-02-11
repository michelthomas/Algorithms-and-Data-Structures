#include <stdio.h>
#include "doubly_linked_list.h"

node* initList(node *linked_list);

int main() {
    node *linked_list = create_linked_list();

    linked_list = initList(linked_list);

    print_linked_list(linked_list);
    printf("\n");

    linked_list =  remove_node_by_key(linked_list, 6);
    print_linked_list(linked_list);

    linked_list = remove_node(linked_list, get_tail(linked_list));
    linked_list = remove_node(linked_list, get_tail(linked_list));
    linked_list = remove_node(linked_list, get_tail(linked_list));
    linked_list = remove_node(linked_list, linked_list);
    linked_list = remove_node(linked_list, linked_list);
    printf("\n");
    print_linked_list(linked_list);

    linked_list = add_begin(linked_list, 51);
    linked_list = add_begin(linked_list, 52);

    linked_list = add_end(linked_list, 71);
    linked_list = add_end(linked_list, 72);

    for (int i = 0; i < 9; ++i) {
        linked_list = remove_node_by_key(linked_list, i);
        printf("\n");
        print_linked_list(linked_list);
    }


    return 0;
}

node* initList(node *linked_list) {
    for (int i = 0; i < 10; ++i) {
        linked_list = add_begin(linked_list, i);
    }

    return linked_list;
}