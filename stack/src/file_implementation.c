#include "../headers/stack.h"

#ifdef __FILE__STACK__


void init_stack(stack_t *stack) {
    strcpy(stack->filename, "data.txt");
    fopen("data.txt", "w");
    stack->top_off = -1;
    printf("Stack file implementation initialized.\n");
}

int isEmpty(stack_t *stack) {
    return stack->top_off == -1;
}

int push_stack(stack_t *stack, int val) {
    FILE *file = fopen(stack->filename, "a"); // append

    // Convert val to string
    char val_str[100];
    sprintf(val_str, "%d", val);
    
    fputs(val_str, file);
    fputs("\n", file);
    fclose(file);
    stack->top_off ++;

    printf("%d pushed to stack\n", val);
    return val;
}

int pop_stack(stack_t *stack, int *val) {
    if (isEmpty(stack)) {
        return -1;
    }
    
    FILE *file = fopen(stack->filename, "r"); // read
    FILE *tmp_file = fopen("tmp-data.txt", "w"); // temporary file

    int count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // While there is a line in the file
    while ((read = getline(&line, &len, file)) != -1) {
        // If current line is not the top
        if (stack->top_off != count) {
            fputs(line, tmp_file); // Put it in the temporary file
        } else {
            *val = *line - '0'; // converted to int
        }
        count++;
    }
    fclose(file);
    fclose(tmp_file);

    // Remove old data.txt and rename temporary file to "data.txt"
    remove(stack->filename);
    rename("tmp-data.txt", stack->filename);
    stack->top_off --;
    return *val;
}

int top_stack(stack_t *stack) {
    FILE *file = fopen(stack->filename, "r"); // read

    int count = 0;
    char *line = NULL;
    char *top;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        if (stack->top_off == count) {
            top = line;
        }
        count++;
    }
    fclose(file);
    printf("Top : %s\n", top);
    return (long)top;
}

void display_stack(stack_t *stack) {
    if (!isEmpty(stack)) {
        FILE *file = fopen(stack->filename, "r"); // read

        int count = 0;
        char *line = NULL;
        char *top;
        size_t len = 0;
        ssize_t read;
        printf("Stack : (top value is the last one)\n");
        while ((read = getline(&line, &len, file)) != -1) {
            printf("%s", line);
            count++;
        }
        fclose(file);
    } else {
        printf("The Stack is empty\n");
    }
    
}

#endif