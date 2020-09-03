
#include <stdio.h>


void OrderIntArray(int*, int );
void GenericBubbleSort(void**,int, int (*)(void*, void*));
int CompareIntegers(void*, void*);

int main()
{
  int arry[] = {2,12,45,1,0, -12, 312};

  void* direcciones[] = {
    arry+0,
    arry+1,
    arry+2,
    arry+3,
    arry+4,
    arry+5,
    arry+6,
  };

  //OrderIntArray(arry, 7);
  GenericBubbleSort(direcciones, 7, CompareIntegers);

  for(int i=0; i<7; i++)
  {
    int* unNombre = direcciones[i];
    printf("%d ", *unNombre);
  }
}

int CompareIntegers(void* a_ref, void* b_ref)
{
  int* intPtrA = a_ref;
  int* intPtrB = b_ref;
  int a = *intPtrA;
  int b = *intPtrB;

  // si a > b, regresa 1
  // si a == b regresa 0
  // si a < b regresa -1
  return a-b; // equivalente al IF de abajo
  if(a>b)
    return 1;
  else if(a == b)
    return 0;
  else
    return -1;
}

void GenericBubbleSort(void* target[],int elementCount, int (*Comp)(void*, void*))
{
  for(int i = 0; i<elementCount-1; i++)
    for(int j = i +1 ; j < elementCount; j++)
      if(Comp(target[i], target[j]) > 0)
      {
        // target i es mayot a target j
        void* temp = target[i];
        target[i] = target[j];
        target[j] = temp;
      }
 
}

void OrderIntArray(int* target, int elementCount)
{
  for(int i = 0; i<elementCount-1; i++)
    for(int j = i +1 ; j < elementCount; j++)
      if(target[i] > target[j])
      {
        int temp = target[i];
        target[i] = target[j];
        target[j] = temp;
      }

}