#include <stdio.h>
#include <stdlib.h>
#ifndef __LINKEDLIST_INT__H__
#define __LINKEDLIST_INT__H__

    typedef struct node_int {
        int x;
        struct node_int* next;
    } node_int;

    node_int* add_start(node_int *head, int val); // return new head
    node_int* add_end(node_int *head, int val); // return inserted node
    node_int* search_value(node_int *head, int val); // return 0 if found
    node_int* remove_first(node_int *head); // return new head
    node_int* remove_last(node_int *head); // return new last node
    void remove_val(node_int *head, int val);
    void print_list(node_int *head);

#endif