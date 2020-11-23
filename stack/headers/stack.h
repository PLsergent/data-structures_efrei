#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __STACK__H__
#define __STACK__H__

#define __DYN__STACK__ 1 

#ifdef __STATIC__STACK__

#define MAX 100

typedef struct stack {  
    int tab[MAX];
    int top;
} stack_t;

#elif __DYN__STACK__

typedef struct node {
    int val;
    struct node * next;
} node_t;

typedef struct stack {
    node_t * top;
} stack_t;

#elif __FILE__STACK__

#define MAX_FLNM 100 

typedef struct {
    char filename[MAX_FLNM];
    int fd; // file descriptor of the open file
    int top_off; // final offset
} stack_t;

void set_file(stack_t *stack, char *file_name); // special function to determine the file to be used

#endif

void init_stack(stack_t *stack); // initalize the data structure
int push_stack(stack_t *stack, int val); // push value into stack
int pop_stack(stack_t *stack, int *val); // pops top value from stack
int top_stack(stack_t *stack); // returns top value of stack
void display_stack(stack_t *stack); // displays the contents of the stack

#endif 
