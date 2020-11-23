#include "./headers/bignum.h"


int main() {
    char first_number[1000], second_number[1000];

    struct Node* res = NULL; 
    struct Node* first = NULL; 
    struct Node* second = NULL;

    printf("Enter the first number : ");
    scanf("%s", first_number);

    size_t length_first = strlen(first_number);
    size_t i = 0; 
    for (; i < length_first; i++) {
        add_start(&first, first_number[i] -'0');
    }
    
    printf("Enter the second number : ");
    scanf("%s", second_number);

    size_t length_second = strlen(first_number);
    size_t j = 0; 
    for (; j < length_second; j++) {
        add_start(&second, second_number[j] -'0');
    }

    printf("First List is : ");
    reverse(&first); // Flip number for reading comprehension
    print_list(first);
    reverse(&first);

    printf("Second List is : ");
    reverse(&second); // Flip number for reading comprehension
    print_list(second);
    reverse(&second);
  
    // Add the two lists and see result 
    res = addTwoLists(first, second); 
    printf("Resultant list is : ");
    reverse(&res);
    print_list(res); 
  
    return 0; 
} 