#include "./headers/linked_list_int.h"
#include "./headers/linked_list_string.h"


int main() {
    // Int linkedlist
    node_int* head = NULL;

    head = add_start(head, 5);
    head = add_start(head, 6);
    head = remove_first(head);

    print_list(head);

    // String linkedlist
    node_str* head_str = NULL;

    head_str = add_start_str(head_str, "oui");
    head_str = add_start_str(head_str, "non");

    print_list_str(head_str);
}