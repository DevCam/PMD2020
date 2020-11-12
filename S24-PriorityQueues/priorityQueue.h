//
// Created by Josean Camarena on 11/11/20.
//

#ifndef HEAPS_PRIORITYQUEUE_H
#define HEAPS_PRIORITYQUEUE_H

#include "stdlib.h"

typedef struct {
  void** heap;
  int (*Compare)(void*, void*);
  int capacity;
  int count;
}PriorityQueue;

PriorityQueue* priorityQueue_new(int initialCapacity, int(*Compare)(void*, void*));
void priorityQueue_offer(PriorityQueue* queue, void* newElement);
void* priorityQueue_peek(PriorityQueue* queue);
void* priorityQueue_poll(PriorityQueue* queue);

#endif //HEAPS_PRIORITYQUEUE_H
