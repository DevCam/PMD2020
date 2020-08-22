#include <stdio.h>

int main(void) {
  // Que es una variable?
  char letra = 'A';

  // Que attributos tiene una variable?
  // Tipo de dato: char
  // Identificador: letra
  // Valor: A

  int edad = 23;

  printf("%c\n", letra); // VALOR de letra
  printf("%d\n", edad); // VALOR de edad

  printf("%p\n", &letra); // DIRECCIÓN de letra
  printf("%p\n", &edad);  // DIRECCIÓN de edad

  // Operador '&' = Donde esta x?
  // Apuntador = Variable cuyo VALOR es una DIRECCION.

  char* apuntador_a_letra = &letra;

  // Obtener el VALOR de una DIRECCION
  // Operador '*' = Que HAY en x?
  printf("%p es la dirección\n", apuntador_a_letra);
  printf("%c es el VALOR\n", *apuntador_a_letra);

  // * les da control completo sobre el dato
  *apuntador_a_letra = 'B';
  printf("%c es el VALOR\n", letra);

  // recuerden que los apuntadores son variables :)
  char otraLetra = 'C';
  apuntador_a_letra = &otraLetra;

  printf("%c es el VALOR\n", *apuntador_a_letra);
}
