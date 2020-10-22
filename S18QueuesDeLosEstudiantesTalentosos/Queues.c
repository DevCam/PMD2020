//
// Creado por los estudiantes mas talentosos que el profe
// TODOS los estudiantes de PMD EXTREMADAMENTE TALENTOSOS
//

#include <stdlib.h>
#include "Queues.h"

Node_ref newNode(char c)
{
  Node_ref n = malloc(sizeof(struct Node_struct));

  n->dato = c;
  n->next = NULL;

  return n;
}

Queue* queue_create()
{
  Queue* foo = malloc(sizeof(Queue));

  foo->count = 0;
  foo->First = NULL;
  foo->Last = NULL;

  return foo;
}

void queue_offer(Queue* q, char c)
{
  Node_ref nodeToAdd = newNode(c);

  if(q->count == 0)
  {
    q->First = nodeToAdd;
    q->Last = nodeToAdd;
  } else {
    q->Last->next = nodeToAdd;
    q->Last = nodeToAdd;
  }
  q->count++;
}

char queue_poll(Queue* q)
{
  Node_ref toRemove = q->First;

  if(toRemove != NULL)
  {
    char dataToReturn = toRemove->dato;
    q->First = toRemove->next;
    free(toRemove);
    q->count--;
    return dataToReturn;
  }

  return 0;
}

void queue_destroy(Queue* q)
{
  while(q->count > 0)
    queue_poll(q);

  free(q);
}
