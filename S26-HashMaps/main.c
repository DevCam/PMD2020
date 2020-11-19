#include <stdio.h>
#include "Map.h"

int hash_string(char* string)
{
  int len = strlen(string);
  int hashKey = 0;

  for(int i = 0; i<len; i++)
    hashKey += string[i] - 'a';

  return hashKey;
}

// omg -> Oh My god
// afk -> away from keyboard
// afaik -> as far as I know

int main() {
  Map* m = map_create(1000000, hash_string);

  map_put(m, "omg", "oh my god");
  map_put(m, "mog", "este valor puede ser distinto, no importa");
  // map_put(m, "mog", "my oh god");

  printf("%s\n", map_get(m, "omg"));

  return 0;
}
