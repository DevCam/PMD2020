//
// Created by Josean Camarena on 02/11/20.
//

#ifndef LION_SANDBOX_SETS_H
#define LION_SANDBOX_SETS_H

// USING ARRAYS
typedef struct array_set {
  int* elements;
  int count;
  int size;
}ArraySet;

ArraySet* array_set_new(int);
void array_set_destroy(ArraySet*);
int array_set_add(ArraySet*, int);
int array_set_remove(ArraySet*, int);
int array_set_contains(ArraySet*, int);

void array_set_pretty_print(ArraySet*);

// USING BST

typedef struct binary_node {
  int value;
  struct binary_node* left;
  struct binary_node* right;
}BinaryNode;

typedef struct binary_search_tree {
  BinaryNode* root;
  int count;
}BST;

BinaryNode* binary_node_new(int);
BST* BST_new();
void BST_destroy(BST*);
int BST_add(BST*, int);
int BST_contains(BST*, int);
void BST_Print_InOrder(BST* t);
void BST_print_nodes_InOrder(BinaryNode* focusNode);


#endif //LION_SANDBOX_SETS_H
