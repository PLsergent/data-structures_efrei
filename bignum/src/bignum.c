#include "../headers/bignum.h"


struct Node* addTwoLists(struct Node* first, struct Node* second) { 
  
    // res is head node of the resultant list 
    struct Node* res = NULL; 
    struct Node* temp_node, * prev = NULL; 
    int carry = 0, sum; 
  
    // while both lists exist 
    while (first != NULL || second != NULL) { 
        // Calculate value of next digit in resultant list. 
        // The next digit is sum of following : 
        // Carry 
        // Next digit of first list (if there is a next digit) 
        // Next digit of second list (if there is a next digit) 
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0); 
  
        // Update carry for next calulation 
        carry = (sum >= 10) ? 1 : 0; 
        sum = sum % 10; 
  
        temp_node = newNode(sum); 

        if (res == NULL) {
            res = temp_node; 
        } else {
            prev->next = temp_node; 
        }
  
        prev = temp_node; 

        if (first) {
            first = first->next; 
        }

        if (second) {
            second = second->next; 
        }
    } 
    
    // Add a node with the carry at the end of the loop
    if (carry > 0) {
        temp_node->next = newNode(carry); 
    }
  
    return res; 
}