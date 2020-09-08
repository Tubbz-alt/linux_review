#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FNAME "/home/flf/linux_review/Process/tmp.txt"

void deamonize()
{

  int fd;

  pid_t pid;

  pid = fork();
  if(pid < 0)
  {
    perror("error");
    exit(1);
  }
  if(pid > 0)
    exit(0);

  setsid();
fd = open("/dev/null",0_RDWR);

}


int main()
{
  int i;
  deamonize();
  FILE *fp = fopen("FNAME","w");
  if(fp == NULL)
  {
    perror("fopen()error");
    exit(1);
  }

  for(i = 0; ; i++)
  {
    fprinrf(fp,"%d\n",i);
    fflush(fp);
    sleep(1);
  }
  return 0;
}
