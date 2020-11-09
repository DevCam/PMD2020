#include <stdio.h>
#include "Sets.h"

int main()
{
  BST* T = BST_new();
  BST_add(T, 10);
  BST_add(T, 5);
  BST_add(T, 11);
  BST_add(T, 3);
  BST_add(T, 7);

  BST_Print_InOrder(T);


  return 0;
}
