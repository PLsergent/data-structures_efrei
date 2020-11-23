#include "../headers/stack.h"

#ifdef __STATIC__STACK__


void init_stack(stack_t* stack) {
    stack->top = -1; 
    printf("Stack array implementation initialized.\n");
}

int isFull(stack_t *stack) {
    // size of `array` in bytes
    size_t size = sizeof(stack->tab);

    // number of elements in `array`
    size_t length = sizeof(stack->tab) / sizeof(stack->tab[0]); 
    return stack->top == length; 
}

int isEmpty(stack_t *stack) {
    return stack->top == -1;
}
  
int push_stack(stack_t *stack, int val) {
    if (isFull(stack)) {
        return -1;
    }
    stack->top ++;
    stack->tab[stack->top] = val;

    printf("%d pushed to stack\n", val); 
    return val;
}

int pop_stack(stack_t *stack, int *val) {
    if(isEmpty(stack)) {
        return -1;
    }
    *val = stack->tab[stack->top];
    stack->top --;
    return stack->tab[stack->top]; 
}

int top_stack(stack_t *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->tab[stack->top];
}

void display_stack(stack_t *stack) {
    if (!isEmpty(stack)) {
        printf("(Top on the left)\n");
        printf("Stack: ");
        for (int i=stack->top; i >= 0; i--) {
            printf("%d ", stack->tab[i]);
        }
    printf("\n");
    } else {
        printf("The Stack is empty\n");
    }
}

#endif