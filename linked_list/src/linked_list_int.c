#include "../headers/linked_list_int.h"


void print_list(node_int* head) {
    node_int* current = head;

    while (current != NULL) {
        printf("%d\n", current->x);
        current = current->next;
    }
}

node_int* add_start(node_int* head, int val) {
    node_int* new_node;
    new_node = (node_int *) malloc(sizeof(node_int));

    new_node->x = val;
    new_node->next = head;
    head = new_node;

    return new_node;
}

node_int* add_end(node_int* head, int val) {
    node_int* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_int*) malloc(sizeof(node_int));
    current->next->x = val;
    current->next->next = NULL;

    return current->next;
}

node_int* remove_first(node_int* head) {
    node_int* next_node = NULL;

    if (head == NULL) {
        return NULL;
    }

    next_node = head->next;
    free(head);
    head = next_node;

    return head;
}

node_int* remove_last(node_int* head) {
    // If only one value
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_int* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return current;
}

void remove_val(node_int* head, int val) {
    node_int* current = head;

    if (head->x == val) {
        node_int * next_node = head->next;
        free(head);
        head = next_node;
    }

    while (current->next != NULL) {
        if (current->next->x == val) {
            node_int * del_node = current->next;
            current->next = current->next->next;
            free(del_node);
        }
        current = current->next;
    }
}

node_int* search_value(node_int* head, int val) {
    node_int* current = head;

    if (head->x == val) {
        return 0;
    }

    while (current->next != NULL) {
        if (current->next->x == val) {
            return 0;
        }
        current = current->next;
    }

    return NULL;
}

