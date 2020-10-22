//
// Created by Josean Camarena on 22/10/20.
//

#ifndef LION_SANDBOX_QUEUES_H
#define LION_SANDBOX_QUEUES_H

struct Node_struct {
    char dato;
    struct Node_struct* next;
};
typedef struct Node_struct* Node_ref;

typedef struct {
    Node_ref First;
    Node_ref Last;
    int count;
} Queue;

Queue* queue_create();
void queue_offer(Queue* q, char c);
char queue_poll(Queue* q);
void queue_destroy(Queue* q);


#endif //LION_SANDBOX_QUEUES_H
