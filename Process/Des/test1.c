#include<stdio.h>
#include<unistd.h>
//交叉分配

#define N 3
int main()   //判断一个数是否是质数
{
  int i = 20000;
  int n;
  int j;
  pid_t pid;
  int flag = 1;
  for(n = 0; n<N;n++)
  {
    fflush(NULL);
    pid = fork();
   if(pid < 0)
   {
      perror("fork失败\n");
      _exit(1);
   }
  if(pid == 0)
  {
  for(i ;i < 20200;++i)
  {
   
   
    flag = 1;
    for(j = 2;j <= i / 2;++j)
    {
      if(i % j == 0)
      flag = 0;
    }
    if(flag == 1)
      printf("质数%d\n",i);
  }
  }
  _exit(0);
  }
  _exit(0);
}




//到底是哪个进程先退出的你没有研究到，这个设计到调度问题



