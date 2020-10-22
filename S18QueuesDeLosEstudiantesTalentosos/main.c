#include <stdio.h>
#include "Queues.h"

/*
   struct Node_struct {
      char dato;
      struct Node_struct* next;
      struct Node_struct* prev;
  };
  typedef struct Node_struct* Node_ref;

  Node_ref queue_create();
  void queue_offer(Node_ref* q, char c);
  char queue_poll(Node_ref* q);
  void queue_destroy(Node_ref* q);
 */

int main() {
  // 'A', 'B', 'C'
  // Node_ref laQueueDePaco = queue_create();

  // queue_offer(laQueueDePaco, 'A');
  Queue* laQueueDePaco = queue_create();

  queue_offer(laQueueDePaco, 'A');
  printf("Tenemos %c\n", queue_poll(laQueueDePaco));

  queue_offer(laQueueDePaco, 'B');
  printf("Tenemos %c\n", queue_poll(laQueueDePaco));

  queue_offer(laQueueDePaco, 'C');
  queue_offer(laQueueDePaco, 'D');
  queue_offer(laQueueDePaco, 'E');

  printf("Tenemos %c\n", queue_poll(laQueueDePaco));
  printf("Tenemos %c\n", queue_poll(laQueueDePaco));

  return 0;
}
