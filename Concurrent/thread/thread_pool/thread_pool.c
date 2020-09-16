#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

#define LIST_ADD(item,list) do 
{
  item->pre = NULL;
  item->next = list;
  if(list != NULL)
  {
    list->prev = item;
  }
  list = item;
}while(0);


#define LIST_erase(item,list) do 
{
  item->pre = NULL;
  item->next = list;
  if(list != NULL)
  {
    list->prev = item;
  }
  list = item;
}while(0);

struct NWORKER
{
  pthread_t thread;
  struct NWORKER* pre;
  struct NWORKER* next;
};

struct NJOB
{
  void(*fun)(struct NJOB* job);
  void *user_data;
  struct NJOB* pre;
  struct NJOB *next;
};

struct NMANAGER
{
  struct NWORKER *workers;
  struct NJOB *jobs;

  pthread_cond_t jobs_cond;//等待条件
  pthread_mutex_t job_mutex; //线程加锁
};

typedef struct NMANAGER nThreadPool;

int nThreadPoolCreate(nThreadPool *pool,int numWorkers)
{
  if(numWorkers < 1)
  {
    numWorkers = 1;
  }
  if(pool == NULL)
  {
    return -1;
  }
  memset(pool,0,sizeof(nThreadPool));

  pthread_cond_t blank_cond = PTHREAD_COND_INITIALIZER;
  memcpy(&pool->jobs_cond,&blank_cond,sizeof(pthread_cond_t));
  
  pthread_mutex_t blank_mutex = PTHREAD_MUTEX_INITIALIZER;
  memcpy(&pool->job_mutex,&blank_mutex,sizeof(pthread_mutex_t));
}






















int main()
{



  return 0;
}
