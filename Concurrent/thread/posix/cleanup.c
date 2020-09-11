#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>
#include<string.h>


static void cleanup_func(void*p)
{
  puts(p);
}

void* func(void)
{
  puts("Thread is Working!");
  //栈的清理
  pthread_cleanup_push(cleanup_func,"cleanup1");     
  pthread_cleanup_push(cleanup_func,"cleanup2");
  pthread_cleanup_push(cleanup_func,"cleanup3");
  pthread_cleanup_push(cleanup_func,"cleanup4");
  puts("push over");
  pthread_cleanup_pop(1);
  pthread_cleanup_pop(1);
  pthread_cleanup_pop(1);
  pthread_cleanup_pop(1);
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

