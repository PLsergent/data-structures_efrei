#include "./headers/history.h"


int main() {
    // History double linkedlist
    node* head = NULL;
    node* current_node;

    head = add_start(head, 3);
    head = add_start(head, 2);
    head = add_start(head, 1);

    print_list(head);
    
    current_node = head;
    current_node = go_to_next(current_node);
    current_node = remove_node(current_node);

    print_list(head);
}