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
static void * thr_add(void *p)
{
  FILE *fp;
  fp = fopen(FNAME,"r+");  
  if(fp ==NULL)
  {
    perror("Fopen Error");
    exit(1);
  }
  fseek(fp,0,SEEK_SET);
  fgets(linebuf,LINESIZE,fp);
  fprintf(fp,"%d\n",atoi(linebuf)+1);
  
  fclose(fp);

  pthread_exit(NULL);
}



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
