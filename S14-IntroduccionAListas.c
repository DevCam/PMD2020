#include <stdio.h>
#include <stdlib.h>


struct Node {
  int value;
  struct Node* next;
};

void AddNode(struct Node* first, int valueToAdd)
{
}

void PrintList(struct Node* first)
{
  // [a] -> b, ->c
  // [0] [123] [9]
  while(first != NULL)
  {
    printf("[%d]", first->value);
    first = first->next;
  }
}

int GetElementCount(struct Node* first)
{
  int laVariableQueMeAyuda = 0;
  while(first != NULL)
  {
    laVariableQueMeAyuda++;
    first = first->next; 
  }

  return laVariableQueMeAyuda;
}

int main()
{
  // a
  struct Node first;
  first.value = 0;
  first.next = NULL;

  // a -> b -> NULL
  struct Node b;
  b.value = 123;
  b.next = NULL;
  first.next = &b; 

  // a -> b -> c -> NULL
  struct Node c;
  c.value = 9;
  c.next = NULL;
  b.next = &c;

  struct Node d;
  d.value = 17;
  d.next = NULL;
  c.next = &d;

  PrintList(first.next);

  printf("el elemento 2 de la lista tiene valor: %d \n", first.next->next->value);

  //printf("el valor es: %d\n", ((a.next)->next)->value);

  // esto es la manera ineficiente.
  /*
  int* arry = calloc(10, sizeof(int));

  for(int i =0; i < 10; i++)
  {
    arry[i] = i;
    printf("%d ", arry[i]);
  }
  // queremos duplicar nuestro arreglo, arry 0 .. 9 . 0 ... 9
  int* temp = arry;
  // arry [0 , 1,2,3 ... 9]
  // temp [0 , 1,2,3 ... 9]
  int* arry = calloc(20, sizeof(int));
  // arry { 0 , 0, 0}

  for(int i =0; i < 10; i++)
  {
    arry[i] = temp[i];
    arry[i+10] = temp[i];
  }
  // {0..9, 0... 9}
  free(arry);
  */

}