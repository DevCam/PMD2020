// Sesión 2
// Artimética de apuntadores & apuntadores a structs.
// Devcam

#include <stdio.h>

struct Coord2d {float x; float y;};

int main(void) {
  struct Coord2d foo = {
    0.5,
    0.9
  };

  printf("Foo is @ [%f, %f]\n", foo.x, foo.y);

  struct Coord2d* bar = &foo;

  printf("Bar is @ [%f, %f]\n", (*bar).x, (*bar).y);

  // Una manera mas elegante:
  printf("Bar is @ [%f, %f]\n", bar->x, bar->y);

  // Para considerar la memoria
  printf("foo   @ %p\n", &foo);
  printf("foo.x @ %p\n", &foo.x);
  printf("foo.y @ %p\n", &foo.y);

  printf("Bar apunta a: %p\n", bar);

  // Apuntadores a miembros de estructura
  float* baz = &foo.x;
  printf("baz @ %p\n", baz);
  baz = &bar->x;
  printf("baz @ %p\n", baz);

}
