#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<string.h>

#define THRNUM 20 
#define LINESIZE 1024
char linebuf[LINESIZE];
#define FNAME "/home/flf/linux_review/Thread/temp"

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;




static void * thr_add(void *p)
{
  FILE *fp;
  fp = fopen(FNAME,"r+");  
  if(fp ==NULL)
  {
    perror("Fopen Error");
    exit(1);
  }
  pthread_mutex_lock(&mut);
  fgets(linebuf,LINESIZE,fp);
  fseek(fp,0,SEEK_SET);
  sleep(1);
  fprintf(fp,"%d",atoi(linebuf)+1);
  
  fclose(fp);
  pthread_mutex_unlock(&mut);
  pthread_exit(NULL);
}

//竞争看不出来问题可以将竞争放大   sleep

int main()
{
  int i;
  pthread_t tid[THRNUM];
  int err;
  for(i = 0; i < THRNUM;i++)
  {
    err = pthread_create(tid+i,NULL,thr_add,NULL);
      if(err)
      {
          fprintf(stderr,"pthread_create():%s\n",strerror(err));
            exit(1);
      }
  }

  for(i = 0; i < THRNUM;i++ )
  {
    pthread_join(tid[i],NULL);
  }

  exit(0);
}
