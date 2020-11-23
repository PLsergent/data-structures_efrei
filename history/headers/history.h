#include <stdio.h>
#include <stdlib.h>
#ifndef __HISTORY__H__
#define __HISTORY__H__

    typedef struct node {
        int element;
        struct node* next;
        struct node* prev;
    } node;

    node* add_start(node *head, int val); // return the new head
    node* add_end(node *head, int val); // return the head
    node* insert_after(node *current_node, int val); // return inserted node
    node* remove_node(node *current_node); // return the prev node
    node* go_to_next(node *current_node); // return new current node
    node* go_to_prev(node *current_node); // return new current node
    void print_list(node *head);

#endif