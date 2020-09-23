#include <stdio.h>
#include <stdlib.h>

int array_size = 5;
int globArray[] = {1,1,1,1,1};

int* retStackArray()
{
  int arrayToReturn[] = {0,0,0,0,0}; // ESTA EN STACK!
  int* calleseCompilador = &arrayToReturn[0];
  return calleseCompilador;
}

int* retDynamicArray()
{
  int* arrayToReturn = calloc(5, sizeof(int));
  return arrayToReturn;
}

void printArray(int* target, int element_count)
{
  for(int i=0; i < element_count; i++)
    printf("%d ", target[i]);
  printf("\n");
}

struct Alumno {
  int id;
  float calificacion;
  int courses[6];
};

void printInt(void* int_ref)
{
  double* caster = int_ref;
  printf("%lf es un int\n", *caster);
}

void printAlumno(void* al_ref)
{
  struct Alumno* caster = al_ref;
  printf("Alumno [%d] con cali [%f] \n", caster->id, caster->calificacion);
  printf("curso 0: %d \n", caster->courses[0]);
}

int main()
{
  // Memory-stack-use after return
  int* stackArry = retStackArray();
  printf("[StackArry] ");
  printArray(stackArry, 5);
  int* dynamicArry = retDynamicArray();
  printf("[DynamicArry] ");
  printArray(dynamicArry, 5);

  free(dynamicArry);

  struct Alumno al = {
    .id = 1,
    .calificacion = 10,
    .courses = {1,2,3}
  };

  //printAlumno(&al);
  //int alumnolol = 12; // 4 bytes
  //printf("%ul", sizeof(struct Alumno)); // 32 bytes

  //printAlumno(&alumnolol);
  printInt(&al);
  return 0;
}