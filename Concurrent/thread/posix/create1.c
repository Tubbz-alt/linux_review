#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<string.h>

void* func(void)
{
  puts("Thread is Working!");
  pthread_exit(NULL);
 //return NULL;
}


int main()
{
  puts("Begin!");
  pthread_t tid;
  int err;
  err = pthread_create(&tid,NULL,(void*)&func,NULL);
  if(err)
  {
    fprintf(stderr,"pthread_create_error %s",strerror(err));
    exit(1);
  }
 // pthread_join(tid,NULL); //只收尸不关心地址
   pthread_join(tid,NULL);
  puts("End!");
  return 0;
}

