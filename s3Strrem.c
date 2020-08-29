#include <stdio.h>

void strrem(char* input, char target)
{

  // Parte 1 - Haciendo "trampa" con corchetes
  // y memoria adicional (un arreglo extra 'temp')
  char temp[500]={};

  int posEnTemp = 0;

  for(int i=0; input[i] != '\0'; i++)
  {
    if(input[i] != target)
    {
      temp[posEnTemp] = input[i];
      posEnTemp++;
    }
  }
  char* posEnInput = input;
  int index = 0;
    // pEI
        // inp
        //  v
  // [H][o][l][a][ ][m][u][n][d][o][\0]
  // [H][l][l][a][ ][\0][u][n][d][o][\0]

  // parte 2 - usando corchetes pero SIN memoria adicional.
  for(int i=0; input[i] != '\0'; i++)
  {
    if(input[i] != target)
    {
      // este SI lo queremos
      posEnInput[index] = input[i];
      index++;
    } else {
      // este no lo queremos
    }
  }

  posEnInput[index] = '\0';
  //printf("%s\n", temp);

  // pEI
  // inp
  //  v
  // [H][o][l][a][ ][m][u][n][d][o][\0]
  // [H][l][l][a][ ][\0][u][n][d][o][\0]
  
  // Solucion final - sin corchetes NI memoria adicional
  // usando solamente aritmetica de apuntadores.
  char* cpiadora;
  for(cpiadora = input; *input != '\0'; input++)
  {
    if(*input != target)
    {
      *cpiadora = *input;
      cpiadora++;
    }
  }
  *cpiadora = '\0';
}
