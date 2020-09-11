#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void thread_primer(int p)
{
  int i = p;
  int j =2;
  int flag = 1;
  for(j = 2; j < i/2;j++)
  {
    if(i % j == 0)
    {
      flag = 0;
      break;
    }

  }
  if(flag)
  {
    printf("%d 是质数",i);
  }

}

int main()
{
  int i= 20011;
  thread_primer(i);


  return 0;
}
