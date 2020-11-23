#include "../headers/history.h"


void print_list(node *head) {
    node* current = head;

    while (current != NULL) {
        printf("%d\n", current->element);
        current = current->next;
    }
}

node* add_start(node *head, int val) {
    node* new_node;
    new_node = (node *) malloc(sizeof(node));

    new_node->element = val;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;

    return new_node;
}

node* add_end(node *head, int val) {
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node*) malloc(sizeof(node));
    current->next->element = val;
    current->next->next = NULL;
    current->next->prev = current;

    return current->next;
}

node* insert_after(node *current_node, int val) {
    if (current_node->next == NULL) {
        node* last_node = add_end(current_node, val);
        return last_node;
    }

    node* new_node = (node*) malloc(sizeof(node));
    new_node->element = val;
    new_node->next = current_node->next;
    new_node->prev = current_node;

    current_node->next = new_node;

    return new_node;
}

node* remove_node(node *current_node) {
    node* return_node;

	if(current_node->prev == NULL) {
		return_node = current_node->next; //the next node will be front of list
		return_node->prev = NULL;
        printf("oui");
	} else if(current_node->next == NULL) {
		return_node = current_node->prev;   // the previous node will be last of list
		return_node->next = NULL;
        printf("non");
	} else {
		current_node->prev->next = current_node->next;
		current_node->next->prev = current_node->prev;
        return_node = current_node->prev;
	}
    printf("Node %d has been removed, new current node : %d\n", current_node->element, return_node->element);
	free(current_node);
    return return_node;
}

node* go_to_next(node *current_node) {
    if (current_node->next == NULL) {
        printf("Last item\n");
        return current_node;
    }
    
    printf("Item found: %d\n", current_node->next->element);
    return current_node->next;
}

node* go_to_prev(node *current_node) {
    if (current_node->prev == NULL) {
        printf("First item\n");
        return current_node;
    }
    
    printf("Item found: %d", current_node->prev->element);
    return current_node->prev;
}