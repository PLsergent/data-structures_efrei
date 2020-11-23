#include "./headers/stack.h"

int main() {
    stack_t p;

    /* #ifdef __FILE__STACK__
        set_file(&p, "persistentStack");
    #endif */

    init_stack(&p);
    push_stack(&p, 5);
    push_stack(&p, 6);
    push_stack(&p, 7);
    display_stack(&p);
    printf("(Press any key)\n");
    scanf("%*c");

    int val;
    pop_stack(&p, &val);
    printf("popped value = %d\n", val);
    display_stack(&p);
    
    pop_stack(&p, &val);
    printf("\npopped value = %d\n", val);
    display_stack(&p);

    pop_stack(&p, &val);
    printf("\npopped value = %d\n", val);
    display_stack(&p);

    pop_stack(&p, &val); // fails
    printf("\npopped value = %d\n", val); // prints out the old value
    display_stack(&p);
}