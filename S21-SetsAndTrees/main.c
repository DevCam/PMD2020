#include <stdio.h>
#include "Sets.h"

int main()
{
  ArraySet* S = array_set_new(6);

  array_set_add(S, 'a');
  array_set_add(S, 'b');
  array_set_add(S, 'c');

  array_set_pretty_print(S);

  array_set_remove(S, 'a');

  if(array_set_contains(S, 'c'));


  array_set_pretty_print(S);


  return 0;
}
