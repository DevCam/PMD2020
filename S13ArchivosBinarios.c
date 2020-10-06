#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
  // diferencia entre un bin_file, y un archivo de texto?
  // sintaxis y tamaño
  // se parsea? sepamos lo que se guarda.

  FILE* txt = fopen("txt_file", "w+");
  FILE* bin = fopen("bin_file", "wb+");
  // para recordar endianess :
  // 0x00 0x00 0x00 0x41 -> bejarano ? 
  // 0x41 0x00 0x00 0x00 -> vania, benji, jaime?

  // **********************************************
  // para escribir un arreglo y leer un arreglo :
  // **********************************************

  /*
  int some_arry[10] = {2,3,4,5,6,7,8,9,10,11};
  fwrite(some_arry, sizeof(int), 10, bin);

  // leer los enteros en bin y escribirlos a consola
  int buffer_arry[10] = {};
  rewind(bin); // fseek, feof
  fread(buffer_arry, sizeof(int), 10, bin);

  for(int i=0; i<10; i++)
    printf("leimos: %d\n", buffer_arry[i]);
  */

  int some_num = 65;
  char* some_text = "hola";

  fprintf(txt, "%d", some_num);

  char buffer[sizeof(int)] = {};
  fwrite(&some_num, sizeof(int), 1, bin); // -> 0x41 0x00 0x00 0x00
  rewind(bin); 
  fread(buffer, sizeof(int), 1, bin);
  printf("Leimos: %x de bin\n", buffer[0]); // 0x41 -> 65

  // esta sentencia escribe bloques de tamaño 1, escribe 4 bloques de 1 byte
  fwrite(some_text, sizeof(char), strlen(some_text), bin); // es menos abstracta.

  // esta sentencia, bloques de tamaño 4, 1.
  fwrite(some_text, strlen(some_text), sizeof(char), bin); // es menos abstracta.

  fprintf(txt, "%s", some_text); // esta es mas abstracta.

  fclose(txt);
  fclose(bin);
}