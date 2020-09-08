// POSIX - unix-like
// Portable operating system interface
// estandar API

#include <stdio.h>
#include <pthread.h>

#define POOL_SIZE 5

void* ThreadHandler(void* args)
{
  int* a = args;
  printf("Hello from thread! %d \n", *a);
  return NULL;
}

int main(void)
{
  pthread_t thread[POOL_SIZE];
  int args[POOL_SIZE];

  for(int i=0; i < POOL_SIZE; i++)
  { 
    args[i] = i;
    int res = pthread_create(&thread[i], NULL, ThreadHandler, args+i);
    // scheduler 

    if(res != 0)
      return res;
   }

    // Proceso App
    // -> hilo main
          // -> thread[0]
                // -> otherThread[0]
                // -> otherThread[1]
          // -> thread[1]
          // -> thread[2]
          // -> thread[3]
          // -> thread[4]
  

  for(int i = 0; i < POOL_SIZE; i++)
  {
    pthread_join(thread[i], NULL);
    printf("from main, %d thread finished! \n", i);
  }

  printf("hello from main!\n");

  return 0;
}

