#include "../headers/linked_list_string.h"


void print_list_str(node_str* head) {
    node_str* current = head;

    while (current != NULL) {
        printf("%s\n", current->text);
        current = current->next;
    }
}

node_str* add_end_str(node_str * head, char* text) {
    node_str* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node_str*) malloc(sizeof(node_str));
    current->next->text = text;
    current->next->next = NULL;

    return current->next;
}

node_str* add_start_str(node_str * head, char* text) {
    node_str * new_node = (node_str *) malloc(sizeof(node_str));
    new_node->text = (char *) malloc(strlen(text)+1);
    strcpy(new_node->text, text);

    new_node->next = head;
    head = new_node;

    return new_node;
}

node_str* remove_first_str(node_str * head) {
    node_str * next_node = NULL;

    if (head == NULL) {
        return NULL;
    }

    next_node = head->next;
    free(head);
    head = next_node;

    return head;
}

node_str* remove_last_str(node_str * head) {
    // If only one value
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_str * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return current;
}

node_str* remove_text(node_str * head, char* text) {
    node_str * current = head;

    if (head->text == text) {
        node_str * next_node = head->next;
        free(head);
        head = next_node;
    }

    while (current->next != NULL) {
        if (current->next->text == text) {
            node_str * del_node = current->next;
            current->next = current->next->next;
            free(del_node);
        }
        current = current->next;
    }
}

node_str* search_text(node_str * head, char* text) {
    node_str * current = head;

    if (strcmp(head->text, text)) {
        return 0;
    }

    while (current->next != NULL) {
        if (strcmp(current->next->text, text)) {
            return 0;
        }
        current = current->next;
    }

    return NULL;
}

