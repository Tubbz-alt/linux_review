#include<stdio.h>
#include<unistd.h>

int main()   //判断一个数是否是质数
{
  int i = 20000;
  int j;
  int flag = 1;
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
  return 0;
}
