#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<string.h>

void* func(void)
{
  puts("Thread is Working!");
  return NULL;
}


int main()
{
  puts("Begin!");
  pthread_t tid;
  int err;
  err = pthread_create(&tid,NULL,(void*)&func,NULL);
  func();
  if(err)
  {
    fprintf(stderr,"pthread_create_error %s",strerror(err));
    exit(1);
  }
  puts("End!");
  return 0;
}
