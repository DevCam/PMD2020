// Sesión 2
// Aritmética de apuntadores & apuntadores a estructuras.
// devcam

#include <stdio.h>

int main(void) {
  int foo[3] = {10, 11, 12};

  for(int i=0; i<3;i++)
    printf("foo[%d] tiene dirección [%p] y valor [%d]\n", i, &foo[i], foo[i]);
  
  printf("la dirección de foo es: %p\n", foo);
  printf("la direc. de foo[0] es: %p\n", &foo[0]);

  int* bar = foo;
  printf("la dirección de bar es: %p\n", bar);
  printf("bar tiene el valor: %d\n", *bar);

  // Como podemos imprimir todos los valores de foo
  // usando bar ?
  // Usando aritmética de apuntadores!

  // bar + 1 se refiere a la siguiente dirección (la que esta "a un lado")
  // bar + 2 se refiere a la que esta a 2 "bloques" de distancia
  // es decir bar+i = foo[i]

  for(int i=0; i<3;i++)
    printf("bar+%d tiene dirección [%p] y valor [%d]\n", i, bar+i, *(bar+i));

  // siguiente dirección y "bloques de distancia"
  // sizeof(int) -> 4
  // sizeof(char) -> 1

  printf("bar apunta a %p\n", bar);
  bar++; // bar = bar + 1
  printf("bar apunta a %p\n", bar);

  // ahora con chars
  char letras[3] = {'A', 'B', 'C'};
  char* baz = letras;

  printf("baz apunta a %p\n", baz);
  baz++;
  printf("baz apunta a %p\n", baz);

  // apuntadores variables vs apuntadores constantes
  char otraLetra = 'Z';

  baz++;
  baz--;
  baz+=5;
  baz-=5;
  baz = &otraLetra;

  // nada de esto es legal
  letras++;
  letras--;
  letras+=5;
  letras-=5;
  letras=&otraLetra;
}
