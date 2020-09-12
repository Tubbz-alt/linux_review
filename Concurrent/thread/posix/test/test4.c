#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
//用200个线程判断区间内是否为质数

struct thread_arg_st
{
  int n;
};

struct thread_arg_st *p;

static void* thread_primer(void *p)
{
  int i = ((struct thread_arg_st *)p)->n;
  //free(p);
  int j =2;
  int flag = 1;
  for(j = 2; j < i/2;j++)
  {
    if(i % j == 0)
    {
      flag = 0;
      break;
    }
  }
  if(flag)
  {
    printf("%d 是质数",i);
  }
  pthread_exit(NULL);
}

int main()   //判断一个数是否是质数
{
  pthread_t err;
  pthread_t tid[200];
  int i = 20000;
  void *ptr;
  for(i ;i <= 20200;++i)
  {
    p =(struct thread_arg_st*)malloc(sizeof(*p));
    if(p ==NULL)
    {
      perror("malloc_error");
      exit(1);
    }
    p->n = i;
    err = pthread_create(&tid[i-20000],NULL,thread_primer,p);
    if(err)
    {
      fprintf(stderr,"pthread_create():%s\n",strerror(err));
      exit(1);
    }
  }
  for(i = 0;i <= 200;++i)
  {
    pthread_join(tid[i],&ptr);
    free(ptr);
  }
  exit(0);
}

//程序不正常会发生竞争

