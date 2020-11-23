#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __LINKEDLIST_STRING__H__
#define __LINKEDLIST_STRING__H__

    typedef struct node_str {
        char* text;
        struct node_str* next;
    } node_str;

    node_str* add_start_str(node_str *head, char* text);
    node_str* add_end_str(node_str *head, char* text);
    node_str* search_str(node_str *head, char* text);
    node_str* remove_first_str(node_str *head);
    node_str* remove_last_str(node_str *head);
    node_str* remove_text(node_str *head, char* text);
    void print_list_str(node_str *head);

#endif