#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t pid;

  printf("[%d]Begin!\n",getpid());
  pid = fork();
  if(pid < 0)   //如果 =  子进程  >0 父进程 <0失败
  {
    perror("fork()");
    _exit(1);
  }
  if(pid == 0)  // child
  {
    printf("[%d]Child is working\n",getpid());
  }
  else   //parent 
  {
    sleep(1);
    printf("[%d]Parent is working \n",getpid());
  }
    printf("[%d]End!\n",getpid());
   // getchar();
    _exit(0);
}
