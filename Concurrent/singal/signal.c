#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
int main()
{
  int i;
  for(i = 0;i < 10;++i)
  {
    write(1,"*",1);
    sleep(1);
  }

  return 0;
}
