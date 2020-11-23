#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __BIGNUM__H__
#define __BIGNUM__H__

// Linked list node
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Create a new node with given data
struct Node* newNode(int data);

void add_start(struct Node** head_ref, int new_data);
void print_list(struct Node* node);
void reverse(struct Node** head_ref);
struct Node* addTwoLists(struct Node* first, struct Node* second);

#endif