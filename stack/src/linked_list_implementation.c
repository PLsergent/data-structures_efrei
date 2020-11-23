#include "../headers/stack.h"

#ifdef __DYN__STACK__


void init_stack(stack_t* stack) {
    stack->top = NULL;
    printf("Stack linked list implementation initialized.\n");
}

int isEmpty(stack_t *stack) {
    return stack->top == NULL;
}

int push_stack(stack_t *stack, int val) {
    node_t* new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = stack->top;
    stack->top = new_node;

    printf("%d pushed to stack\n", val);
    return new_node->val;
}

int pop_stack(stack_t *stack, int *val) {
    node_t* tmp = stack->top;

    if (isEmpty(stack)) {
        return -1;
    }
    *val = stack->top->val;

    if (stack->top->next != NULL) {
        stack->top = stack->top->next;
        free(tmp);
        return stack->top->val;
    } else {
        stack->top = NULL;
        return -1;
    }
}

int top_stack(stack_t *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    printf("Top value : %d\n", stack->top->val);
    return stack->top->val;
}

void display_stack(stack_t *stack) {
    node_t* current;

    if (!isEmpty(stack)) {
        current = stack->top;
        printf("(Top on the left)\n");
        printf("Stack: ");
        do {
            printf("%d ", current->val);
            current = current->next;
        } while (current != NULL);
        printf("\n");
    } else {
        printf("The Stack is empty\n");
    }
}

#endif