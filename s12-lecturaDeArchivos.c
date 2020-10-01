#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// File descriptors & Streams.
// modos de apertura: r+, w+
// los modos de apertura cambian dos cosas: los permisos con los que se asoc. un stream 
// y la pos del cursor al momento de asoc.

// A recordar: TODOS los programas en c ya tienen 3 streams definidos 
// stdin -> standard input
// stdout -> standard output
// stderr -> standard error

void WriteNumbers(int start, int end, FILE* stream);
void WriteNumbersToConsole(int start, int end);
void ReadNumbersFromStream(FILE* stream);

int main(void)
{
  // MUCHO CUIDADO CON LOS PATHS
  // f = fopen("numbers.txt", "a");
  // tenemos que abrir un archivo

  FILE* f;
  // f = fopen("numbers.txt", "w");

  f = fopen("numbers.txt", "a+");
  WriteNumbers(1, 10, f);
  rewind(f);
  ReadNumbersFromStream(f);

  fclose(f);

  return 0;
}

void WriteNumbersToConsole(int start, int end)
{
  // fprintf -> (stream, lo que queremos escribir, los varargs)
  // printf -> stream implicito es stdout
  for(int i = start; i <= end; i++)
    fprintf(stdout, "%d\n", i);
}

void ReadNumbersFromStream(FILE* stream)
{
  // escribir a consola que num se leyó y el agregado de los numeros.
  // esta garantizado que stream se puede leer y el cursor esta al principio.

  // printf -> fprintf es mas general porque printf es implicito que escribe a stdout
  // scanf -> fscanf es mas general porque scanf es implicito a stdin

  int readNumber;
  int sum = 0;
  while(fscanf(stream, "%d\n", &readNumber) != EOF)
  {
    sum += readNumber;
    printf("leimos [%d ] y el agregado es [%d] \n", readNumber, sum);
  }

  // revisar si ocurrieron errores
  if(ferror(stream))
  {
    // aqui ocurrio un error :(
    printf("algo malo paso inge \n");
  }
}

void WriteNumbers(int start, int end, FILE* stream)
{
  // stream ya es un stream válido y puedes escribir.
  for(int i = start; i <= end; i++)
    fprintf(stream, "%d\n", i);
}
