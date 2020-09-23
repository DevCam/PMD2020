#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void toUpper(char*);

// Code, text, program -> ROM NO SE PUEDE ALTERAR DESPUES DE COMPILAR
// BIS, Variables GLOBALES (init o init) -> menos nos interesa

// HEAP -> memoria dinamica, calculablle en tiempo de ejecución. -> si mod
// STACK -> Constante, o calculable en tiempo de compil. -> si mod

int main(void)
{
  char* inROM = "holamundo"; // string literal
  char inAutoMemory[] = {'h', 'o', 'l', 'i', 'm', 'u', 'n', 'd', 'i', '\0'};
  int otherArry[12];
  // inManegedMemory ocupa 8 bytes
  // char* ref = strcpy(void*, char*)
  char* inManagedMemory = strcpy(malloc(inAutoMemory[0] * sizeof(char)), "holemunde");

  printf("[inRom] %s \n", inROM);
  printf("[inManagedMemory] %s \n", inManagedMemory);
  printf("[inAutoMemory] %s \n", inAutoMemory);

  // toUpper(inROM);
  toUpper(inManagedMemory);
  toUpper(inAutoMemory);

  printf("[inManagedMemory] %s \n", inManagedMemory);
  printf("[inAutoMemory] %s \n", inAutoMemory);

  return 0;
}

void toUpper(char* target)
{
  while(*target != '\0')
    if(*target >= 'a' && *target <= 'z')
      *target++ -= 32;
}