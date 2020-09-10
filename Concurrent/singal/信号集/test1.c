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
  sigset_t set;
  signal(SIGINT, Inturput_Handlle);
  sigemptyset(&set);
  sigaddset(&set,SIGINT);
  for(j = 0;j < 1000;j++)
  { 
    sigprocmask(SIG_BLOCK,&set,NULL);   //把这个阻塞住
    for(i = 0;i < 5;i++)
    {
      write(1,"*",1);
      sleep(1);
    }
    write(1,"\n",1);
    sigprocmask(SIG_UNBLOCK,&set,NULL); // 解除阻塞
  }
  exit(0);
}
