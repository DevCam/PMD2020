//
// Created by Josean Camarena on 02/11/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "Sets.h"

ArraySet* array_set_new(int max_elements)
{
  ArraySet* a = malloc(sizeof(struct array_set));
  a->count = 0;
  a->size = max_elements;
  a->elements = calloc(a->size, sizeof(int));
  return a;
}
void array_set_destroy(ArraySet* s)
{
  free(s->elements);
  free(s);
}

int array_set_add(ArraySet* s, int n)
{
  if(s->count < s->size && !array_set_contains(s, n))
  {
    for(int i =0; i < s->size; i++)
      if(s->elements[i] == 0)
      {
        s->elements[i] = n;
        s->count++;
        return 1;
      }
  }
  return 0;
}

int array_set_remove(ArraySet* s, int n)
{
  for(int i = 0; i < s->size; i++)
  {
    if(s->elements[i] == n)
    {
      s->elements[i] = 0; //delete element
      s->count--;
      return 1;
    }
  }
  return 0;
}

// O (n)
int array_set_contains(ArraySet* s, int n)
{
  for(int i=0; i < s->size; i++)
    if(s->elements[i] == n)
      return 1;
  return 0;
}

void array_set_pretty_print(ArraySet* s)
{
  printf("{ ");
  for (int i = 0; i < s->size; i++)
    if (s->elements[i] != 0)
      printf("%c ", s->elements[i]);
  printf("}\n");
}

// O(k)
// o(n)
// O(n^2) -> o(ab)
ArraySet* Intersect(ArraySet* a, ArraySet* b)
{
  // { a, b, c}
  // { b, c, d}
  // { b , c }
  ArraySet* newSet = array_set_new(1000);
  for(int i=0; i<a->size; i++)
  {
    int elementToCompare = a->elements[i];
    for(int j=0; j<b->size; j++)
    {
      if(b->elements[j] == elementToCompare)
        array_set_add(newSet, elementToCompare);
    }
  }
}

BST* BST_new()
{
  BST* T = malloc(sizeof(struct binary_search_tree));
  T->count = 0;
  T->root = NULL;
  return T;
}

void destroyBinaryNode(BinaryNode* node)
{
  if(node->left)
    destroyBinaryNode(node->left);
  if(node->right)
    destroyBinaryNode(node->right);
  free(node);
}
void BST_destroy(BST* t)
{
  if(t->root)
    destroyBinaryNode(t->root);
  free(t);
}

BinaryNode* binary_node_new(int val)
{
  BinaryNode* newNode = malloc(sizeof(struct binary_node));
  newNode->value = val;
  newNode->right = NULL;
  newNode->left = NULL;

  return newNode;
}

int BST_add_to_tree(BinaryNode* focusNode, int val)
{
  if(focusNode->value < val)
  {
    if(focusNode->right == NULL)
    {
      BinaryNode* newNode = binary_node_new(val);
      focusNode->right = newNode;
      return 1;
    } else {
      return BST_add_to_tree(focusNode->right, val);
    }
  }
  if(focusNode->value > val)
  {
    if(focusNode->left == NULL)
    {
      BinaryNode* newNode = binary_node_new(val);
      focusNode->left = newNode;
      return 1;
    } else {
      return BST_add_to_tree(focusNode->left, val);
    }
  }
  else {
    return 0;
  }
}

int BST_add(BST* t, int val)
{
  if(t->root == NULL)
  {
    BinaryNode* newNode = binary_node_new(val);
    t->root = newNode;
    t->count++;
  } else {
    if(BST_add_to_tree(t->root, val))
    {
      t->count++;
      return 1;
    } else {
      return 0;
    }
  }
  return 1;
}

int BST_contains(BST* t, int val)
{

}