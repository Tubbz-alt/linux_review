#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>

#define THRNUM 4

pthread_mutex_t mut[THRNUM];

int next(int n)
{
  if(n +1 == THRNUM)
    return 0;
  return n+1;
}


static void* thr_func(void* p)
{
    int c ='a' + (int )p;
    int n = (int) p;
    while(1)
    {
      pthread_mutex_lock(mut + n);
      write(1,&c,1);
      pthread_mutex_unlock(mut + next(n));
    }
    pthread_exit(NULL);
}


int main()
{
  int i = 0;
  pthread_t tid[THRNUM];
  int err;
  for(i = 0 ; i < THRNUM;++i)
  {
    pthread_mutex_init(mut+i,NULL);
    pthread_mutex_lock(mut+i);
    err = pthread_create(tid+i,NULL,thr_func,(void*)i);
    if(err)
    {
      fprintf(stderr,"error%s",strerror(err));
      exit(1);
    }
  }
  pthread_mutex_unlock(mut);

  alarm(5);

  for(i = 0 ; i < THRNUM;++i)
  {
    pthread_join(tid[i],NULL);
  }



  exit(0);
}
