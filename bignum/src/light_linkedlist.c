#include "../headers/bignum.h"


struct Node* newNode(int data) { 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 

void add_start(struct Node** head_ref, int new_data) { 
    struct Node* new_node = newNode(new_data); 
  
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}


void print_list(struct Node* node) {
    printf("\033[1;37m");
    while (node != NULL) { 
        printf("%d", node->data); 
        node = node->next; 
    } 
    printf("\033[0m\n"); 
}

// Use to display the number in the right order
void reverse(struct Node** head_ref) { 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 