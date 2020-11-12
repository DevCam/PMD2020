//
// Created by Josean Camarena on 11/11/20.
//

#include "priorityQueue.h"

PriorityQueue* priorityQueue_new(int initialCapacity, int(*Compare)(void*, void*))
{
  PriorityQueue* q = malloc(sizeof(PriorityQueue));

  q->count = 0;
  q->Compare = Compare;
  q->heap = calloc(initialCapacity, sizeof(void*));
  q->capacity = initialCapacity;

  return q;
}

int parent(int currentNode) { return (currentNode-1) / 2;}
int left_child(int currentNode) { return 2 * currentNode + 1;}
int right_child(int currentNode) { return 2 * currentNode + 2;}

void swap(void** a, void** b)
{
  void* temp = *a;
  *a = *b;
  *b = temp;
}

// obtain root (if such element exists) NULL otherwise
void* priorityQueue_peek(PriorityQueue* queue)
{
  if(queue->count > 0)
    return queue->heap[0];
  return NULL;
}

void grow_heap_if_needed(PriorityQueue* queue)
{
  if(queue->count == queue->capacity)
  {
    // we need more space!
    int newCapacity = queue->capacity * 2;
    void* newHeap = realloc(queue->heap, newCapacity * sizeof(void*));
    if(newHeap == NULL)
      exit(0);
    queue->capacity = newCapacity;
    queue->heap = newHeap;
  }
}


// Add an element to the pQueue
void priorityQueue_offer(PriorityQueue* q, void* newElement)
{
  grow_heap_if_needed(q);

  int newElementIndex = q->count;
  int parentIndex = parent(newElementIndex);
  q->heap[newElementIndex] = newElement;

  while(
          newElementIndex > 0 && // no es el nodo raiz
          q->Compare(q->heap[newElementIndex], q->heap[parentIndex]) < 0) // no se cumple la condición de heap
  {
    swap(&q->heap[newElementIndex], &q->heap[parentIndex]);
    newElementIndex = parentIndex;
    parentIndex =  parent(newElementIndex);
  }
  q->count++;
}

void* priorityQueue_poll(PriorityQueue* q)
{
  if(q->count == 0) return NULL;
  void* toRemove = q->heap[0];
  q->count--;
  if(q->count == 0) return toRemove; // we removed the last element

  q->heap[0] = q->heap[q->count];
  int candidateIndex = 0;
  int isHeapValid = 0;

  while (!isHeapValid)
  {
    int newIndex = candidateIndex;
    int left = left_child(candidateIndex);
    int right = right_child(candidateIndex);

    if(left < q->count && q->Compare(q->heap[left], q->heap[candidateIndex]) < 0)
      newIndex = left;

    if(right < q->count && q->Compare(q->heap[right], q->heap[newIndex]) < 0)
      newIndex = right;

    if(newIndex != candidateIndex)
    {
      swap(&q->heap[newIndex], &q->heap[candidateIndex]);
      candidateIndex = newIndex;
    } else {
      isHeapValid = 1;
    }
  }
  return toRemove;
}
