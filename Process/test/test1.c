#include<stdio.h>
#include<unistd.h>

int main()   //判断一个数是否是质数
{
  int i = 20000;
  int j;
  pid_t pid;
  int flag = 1;
  for(i ;i < 20200;++i)
  {
    fflush(NULL);
   pid =  fork();
   if(pid < 0)
   {
      perror("fork失败\n");
      _exit(1);
   }
   if(pid == 0)
   {
    flag = 1;
    for(j = 2;j <= i / 2;++j)
    {
      if(i % j == 0)
      flag = 0;
    }
    if(flag == 1)
      printf("质数%d\n",i);
      _exit(0);
  }
  }
  _exit(0);
}
