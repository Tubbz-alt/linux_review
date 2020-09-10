/*
 *我们需要更改程序，阻塞-》保存之前的状态 -》阻塞
 *
 * */



#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>

static void Inturput_Handlle(int s)
{
    write(1,"!",1);
}
int main()
{
  int i;
  int j;
  sigset_t set,oset;
  signal(SIGINT, Inturput_Handlle);
  sigemptyset(&set);
  sigaddset(&set,SIGINT);
  for(j = 0;j < 1000;j++)
  { 
    sigprocmask(SIG_BLOCK,&set,&oset);   //把这个阻塞住
    for(i = 0;i < 5;i++)
    {
      write(1,"*",1);
      sleep(1);
    }
    write(1,"\n",1);
    sigprocmask(SIG_UNBLOCK,&oset,NULL); // 解除阻塞
  }
  exit(0);
}
