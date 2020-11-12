#include <stdio.h>
#include "priorityQueue.h"

int compareInts(void*a, void* b)
{
  return *((int*)a) - *((int*)b);
}

void draw_int_heap(PriorityQueue* q)
{
  for(int i = 0; i < q->count; i++)
    printf("%d ", *(int*)q->heap[i]);
  printf("\n");
}

int main() {
  int data[] = {6, 3, 7, 2, 5, 1, 8, 0, 4, -1, 9, -2, 10, -3, 11, -4, 0, 5, 1, -2, 7, 2};
  int N = sizeof(data) / sizeof(int);

  PriorityQueue* pq1 =priorityQueue_new(30, compareInts);
  int i, *min;
  int *ptr = data;
  for(i = 0; i < N; i ++, ptr ++) {
    priorityQueue_offer(pq1, ptr);
    printf("agregar: %d ", *ptr);
    min = (int*) priorityQueue_peek(pq1);
    printf("Peek: %3d\n", *min);
  }

  while(pq1->count > 0) {
    min = (int*) priorityQueue_poll(pq1);
    printf("Poll: %3d\n", *min);
  }
  return 0;
}
