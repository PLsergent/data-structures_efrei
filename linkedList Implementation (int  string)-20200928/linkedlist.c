#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

node_t *add_first(node_t *plist, int val) {
  // create & intialize node
  node_t *pnd = (node_t *) malloc(sizeof(node_t));
  pnd->info = val;

  // link node to the previous first node
  pnd->next = plist;

  // new list starts with this node
  plist = pnd;

  // return the new list
  return plist;
}


node_t *add_end(node_t *plist, int val) {
  // create & intialize node
  node_t *pnd = (node_t *) malloc(sizeof(node_t));
  pnd->info = val;
  pnd->next = NULL;

  // special case : if list is empty, return the new list
  if (!plist)
    return pnd;

  // general case
  // link new node to the last node
  // go through the nodes till the end; p points to the actual node and q to its precedding node
  node_t *p, *q;
  p = q = plist;

  while (p) { // still not the end
    q = p;
    p = p->next;
  }

  // q points to the last node
  q->next = pnd;

  // return the new list
  return plist;
}


node_t *remove_first(node_t *plist, int *pval) {
  *pval = plist->info;
  node_t *newList = plist->next;

  free(plist);
  
  return newList;
}


node_t *remove_last(node_t *plist, int *pval) {
  // go through the list till the last node and remove it
  node_t *p, *q;
  p = q = plist;

  while(p->next) { // p is not the last node
    q = p;
    p = p->next;
  }

  // p points to the last node, q to its preceding node
  *pval = p->info;
  free(p);

  if (q == p) // list with only one node 
    return NULL;
  else {
    q->next = NULL; // modify new last node
    return plist;
  }
  
}


node_t *search(node_t *plist, int val) {
  node_t *p = plist;
  while(p && p->info != val) // go through the list
    p = p->next;

  if (!p) // not found
    return NULL;

  return p;
}


void display(node_t *plist) {
  while (plist != NULL) {
    printf("%d\n", plist->info);
    plist = plist->next;
  }
    
}



int main() {
  node_t *plist = NULL; // empty list

  plist = add_first(plist, 5);
  plist = add_first(plist, 10);
  plist = add_end(plist, 15);
  plist = add_end(plist, 20);

  display(plist);


  node_t *p = search(plist, 15);
  printf("searching for 15 : node %p info %d\n", p, p->info);
  
  int x;
  plist = remove_first(plist, &x);
  printf("removed first = %d\n", x);
  display(plist);

  
  plist = remove_last(plist, &x);
  printf("removed last = %d\n", x);
  display(plist);

  plist = remove_last(plist, &x);
  plist = remove_first(plist, &x);
  display(plist);

}
