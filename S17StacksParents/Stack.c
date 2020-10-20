//
// Created by Josean Camarena on 19/10/20.
//

#include "Stack.h"
#include "string.h"

Stack_ref new_stack()
{
  Stack_ref s = malloc(STACK_SIZE);
  s->head = NULL;
  s->count = 0;
  return s;
}

Node_ref new_node(char c)
{
  Node_ref n = malloc(NODE_SIZE);
  n->value = c;
  n->next = NULL;
  return n;
}

void destroy_stack(Stack_ref s)
{
  Node_ref limit = NULL;
  while(limit != s->head) {
    Node_ref focusNode = s->head;
    while(focusNode->next != limit)
      focusNode = focusNode->next;
    limit = focusNode;
    free(focusNode);
  }
  free(s);
}

char pop(Stack_ref stack)
{
  char val = 0;
  if(stack->head)
  {
    val = stack->head->value;
    Node_ref nodeToDelete = stack->head;
    stack->head = stack->head->next;
    free(nodeToDelete);
    stack->count--;
  }
  return val;
}

char peek(Stack_ref stack)
{
  char val = 0;
  if(stack->head)
    val = stack->head->value;
  return val;
}

void push(Stack_ref stack, char value)
{
  if(!stack->head)
    stack->head = new_node(value);
  else
  {
    Node_ref newHead = new_node(value);
    newHead->next = stack->head;
    stack->head = newHead;
  }
  stack->count++;
}
