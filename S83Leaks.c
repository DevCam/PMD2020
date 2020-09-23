#include <stdio.h>
#include <stdlib.h>

void LeakPointer()
{
  void* memory = malloc(123); // heap - Garbage collector
}

void doubleFree()
{
  void* memory = malloc(123); // [ 0xA, 0xZZZ]
  free(memory); // aqui estamos gucci [] // [ 0xA, 0xZZZ]
  free(memory); // aqui tenemos comportamiento indeterminado [ 0x1239, 1231239;]
}

void danglingReference()
{
  void* memory = malloc(123);
  void* aux_pointer = memory;

  // NUNCA HAGAN ESTO
  aux_pointer++;
  aux_pointer++;
  aux_pointer++;
  free(memory); // es comportamiento indeterminado.
}

int main()
{
  // LeakPointer();
  // doubleFree();
  danglingReference();
  return 0;
}