//
// Created by Josean Camarena on 19/10/20.
//

#include <stdlib.h>

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#define STACK_SIZE sizeof(struct stack_struct)
#define NODE_SIZE sizeof(struct node_struct)

struct node_struct {
    char value;
    struct node_struct* next;
};
typedef struct node_struct* Node_ref;

struct stack_struct{
    Node_ref head;
    int count;
};

typedef struct stack_struct* Stack_ref;

Stack_ref new_stack();
void destroy_stack(Stack_ref);
Node_ref new_node(char);

char pop(Stack_ref);
char peek(Stack_ref);
void push(Stack_ref, char);

#endif //DATASTRUCTURES_STACK_H
