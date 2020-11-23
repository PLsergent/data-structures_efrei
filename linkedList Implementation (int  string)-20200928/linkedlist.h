#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

typedef struct _node {
  int info;

  struct _node *next;

} node_t;

// adds a node with val at the beginning of plist, returns the new ist
node_t * add_first(node_t*plist, int val);

// adds a node with val at the end of plist, returns the new list
node_t * add_last(node_t *plist, int val);

// searches for the first node containing val in plist, returns the node if successful otherwise NULL
node_t * search(node_t *plist, int val);

// removes the first node from a non-empty plist, puts info in pval, returns the new list
node_t * remove_first(node_t *plist, int *pval);

// removes the last node from a non-empty plist, puts info in pval, returns the new list
node_t * remove_last(node_t *plist, int *pval);

// removes the first node in plist containing val, returns the new list
node_t * remove_val(node_t *plist, int val);

// displays the content of plist
void display(node_t *plist);

#endif
